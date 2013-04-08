/*******************************************************************************
 *									                                           *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *			                                    						       *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 *******************************************************************************
 */

/**
 * \file server.cpp
 * This file contain the implementation of a server waiting for
 * The simulators to give him result and aggregate them.
 */


#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <errno.h>
#include <algorithm>

#include "../Cosmos/BatchR.hpp"
#include "result.hpp"
#include "server.hpp"

using namespace std;

//! A list of file descriptor for the select system call.
fd_set client_list;

//! A vector of FILE containing the stdout of each simulator.
vector<FILE*> clientstream;

//! A vector of PID of the simulators
vector<pid_t> clientPID;

//! The maximal index of file descriptor in client_list.
int max_client=0 ;

//! Boolean indicating if the simulation should continue.
bool continueSelect=false;

/**
 * Signal handler.
 * The signals this function is expecting are SIGCHLD which append if
 * child simulator terminate. In this case the return status of the child
 * must be retrive to know what make the simulator terminate.
 * If the termination is legit: The simulator terminate because it has finished 
 * its computation which append in -v 4 mode and when exporting state space,
 * or the server just killed the simulator with signal 2.
 * Then do nothing. Otherwise report the error.
 *
 * If the signal SIGINT is caught then the variable continueSelect is set to 
 * false, this is sufficient because the signal interrupt the select 
 * system call.
 *
 * @param signum the number of a signal
 */
void signalHandler( int signum )
{
	switch (signum){
		case SIGCHLD: {
			int status;
			pid_t child = wait(&status);
			
			if(child != -1){
				if(status!=0){
				if(WIFSIGNALED(status)){
					if(WTERMSIG(status) != 2){
						cout << "Simulator "<< child << "Terminated by signal :" << WTERMSIG(status) << endl;
						exit(EXIT_FAILURE);
					}
				} else if(WIFEXITED(status)){
					if(WEXITSTATUS(status) != 130)cout << "Simulator exit with code " << WEXITSTATUS(status) << endl;
				}else {
					cout << "Simulator "<< child << " Crash ! with unknown status "<< status  << endl;
				}
				}
			}
		}
			break;
		case SIGINT:
			continueSelect = false;
			break;
		default:
			cerr << " Unexpected signal: " << signum << endl;
	}
}

void popenClient(const char* bin, const char *argv[]){
	pid_t pid = 0;
	int pipefd[2];
	int pipeerr[2];
	FILE* output;
	
	pipe(pipefd); //create a pipe
	pipe(pipeerr);
	pid = fork(); //fork the process
	if (pid == 0){
		//Child.
		close(pipefd[0]);
		close(pipeerr[0]);
		if(dup2(pipefd[1], STDOUT_FILENO)<0)perror("Fail to redirect stdout");
		//if(dup2(pipeerr[1], STDERR_FILENO)<0)perror("Fail to redirect stderr");
		if(execvp(bin,(char *const *)argv)<0)perror("Fail to lauch the client");
	}else if(pid>0){
		
		//Only parent gets here. Listen to what the tail says
		close(pipefd[1]);
		close(pipeerr[1]);
		
		//open the output of the client.
		output= fdopen(pipefd[0], "r");
		//if(dup2(STDERR_FILENO,pipeerr[0])<0)perror("Fail to redirect stderr");
		
		clientstream.push_back(output);
		int streamfd = fileno(output);
		if(streamfd >max_client)max_client = streamfd;
		clientPID.push_back(pid);
		
	}else perror("Fail to fork");
}

inline void pushint(const char *argv[],size_t &argn,size_t v){
	char* s = (char *)malloc(255*sizeof(char));
	sprintf(s, "%li", v);
	argv[argn] = s;
	argn++;
}

inline void pushdouble(const char *argv[],size_t &argn,double v){
	char* s = (char *)malloc(255*sizeof(char));
	sprintf(s, "%f", v);
	argv[argn] = s;
	argn++;
}


inline void pushstr(const char *argv[],size_t &argn,const char* v){
	char* s = (char *)malloc(255*sizeof(char));
	sprintf(s, "%s", v);
	argv[argn] = s;
	argn++;
}

void freestr(const char *argv[],size_t t){
	for(size_t i =0; i<t;i++)
		free((void *)argv[i]);
}


/**
 * Launch the P.Njob copy of the simulator with the parameters define in P
 */
void launch_clients(parameters& P){
    signal(SIGCHLD , signalHandler); 
	signal(SIGINT, signalHandler);
	//pid_t readpid;
	for(int i = 0;i<P.Njob;i++){
		string cmd = P.tmpPath + "/ClientSim";;
		const char *argv[10] = {0};
		size_t argn = 0;
		pushstr(argv, argn, cmd.c_str());
		
		pushint(argv,argn,P.Batch);
		pushint(argv,argn,P.verbose);
		
		//<< P.Batch << " " << P.verbose;

		// is seed is zero generate a pseudo random seed.
		if(P.seed==0){
			timeval t;
			gettimeofday(&t,(struct timezone*)0);
			//os << " " <<(t.tv_usec + t.tv_sec + getpid()+i);
			pushint(argv,argn,(t.tv_usec + t.tv_sec + getpid()+i));
		}else{
			//is seed is not null add i to the seed to guarantee independance
			// of simulation.
			//os << " " << (P.seed+i);
			pushint(argv,argn,P.seed+i);
		}
		
		//Argument to select the simulator to use.
		if(P.BoundedContinuous){
			//os << " " << "-COBURE" << " " << P.BoundedRE << " " << P.horizon << " " << P.epsilon;
			pushstr(argv,argn,"-COBURE");
			pushint(argv,argn,P.BoundedRE);
			pushdouble(argv,argn,P.horizon);
			pushdouble(argv,argn,P.epsilon);
		} else if(P.BoundedRE>0){
			//os << " " << "-BURE" << " " << P.BoundedRE << " " << P.horizon;
			pushstr(argv,argn,"-BURE");
			pushint(argv,argn,P.BoundedRE);
			pushint(argv,argn,P.horizon);
		} else if(P.DoubleIS){
			//os << " " << "-RE2";
			pushstr(argv,argn,"-RE2");
		} else if(P.RareEvent){
			//os << " " << "-RE";
			pushstr(argv,argn,"-RE");
		}
		
		//If logging the row data is require pass it as an option.
		if (P.dataraw.compare("")!=0){
			//os << " -log " << P.dataraw;
			pushstr(argv,argn,"-log");
			pushstr(argv,argn,P.dataraw.c_str());
		}
		
		/*//Lauch a new client with the parameters
        FILE* stream = popen((os.str()).c_str(), "r");
		//add the file descriptor to the list of file descriptor.
        clientstream.push_back(stream);
        int streamfd = fileno(stream);
        if(streamfd >max_client)max_client = streamfd;
        
		//Read the first bythes of the stream it should contain the
		//PID of the client.
        fread(reinterpret_cast<char*>( &readpid ), sizeof(readpid) ,1, stream);
        clientPID.push_back(readpid);
		 */
		popenClient(cmd.c_str(),argv);
		freestr(argv, argn);
    }
    
}

/**	
 * Kill all the copy of the simulators at the end of the computation.
 * This also allow to recover usage information of the simulators.
 */
void kill_client(){
	
    while (!clientPID.empty())
    {
        kill(clientPID.back(),2);
        clientstream.pop_back();
        clientPID.pop_back();
    }
	pid_t child= 1;
	while (child != -1) {
		int termstat;
		child = wait(&termstat);
	}
    
}

/**
 * Build a list of input files of all the simulators to collect results
 * This list is made to be used with the function <sys/select.h>/select
 */
void makeselectlist(void){
    FD_ZERO(&client_list);
    for(size_t it = 0;it < clientstream.size(); it++){
        int fl = fileno(clientstream[it]);
        FD_SET(fl,&client_list);
    }
}

void launchExport(parameters& P){    
    if(P.computeStateSpace==2){
		ostringstream setuppr;
		setuppr << "cd " << P.Path << "../prism ; ./install.sh";
		cout << "setup prism:" << setuppr.str() << endl;
		system(setuppr.str().c_str());
	}
		
    ostringstream os;
	os << P.tmpPath << "/ClientSim 1 " << P.verbose << " 0 ";
    if(P.computeStateSpace==1)os << " -STSP " << P.Path << "../" << P.prismPath;
	else os << " -STSPBU " << P.Path << "../" << P.prismPath;
    
    if(P.verbose >1)cout << os.str() << endl;
    
    if (system(os.str().c_str()) == 0){
        cout << "Export Finish" << endl;
    }else{
        cerr << "Export Fail" << endl;
    }    
}

// This function launch a set of simulators and stop them once
// The precision criterion is reach.
void launchServer(parameters& P){
    if(P.verbose>0)cout << "START SIMULATION ..." << endl;
    
    //Init result
    result Result(P);
    //Launch a set of simulators
    launch_clients(P);
    //Make a list of file system for polling
    
	continueSelect = true;
    do{
        makeselectlist();
		if(!continueSelect)break;
        //wait for a simulator to return some result
        if(select(max_client+1, &client_list, NULL, NULL, NULL) == -1){
			if(errno == EINTR)break;
            perror("Server-select() error!");
            exit(EXIT_FAILURE);
        }
		//Iterate over the simultor to check wich one has some results.
        for(size_t it = 0;it < clientstream.size() ;it++){
            if(FD_ISSET(fileno(clientstream[it]),  &client_list)){
                //aggregate the new result to the total result
                BatchR batchResult(P.nbAlgebraic);
                if(batchResult.inputR(clientstream[it])){
					//batchResult.print();
					Result.addBatch(&batchResult);
					//If neaded output the progress of the computation.
					if(P.verbose>0 || P.alligatorMode)Result.printProgress();
				} else {
					//The batch result was not complete.
					//If the simulator was kill by the server it is OK otherwise
					//It is a problem.
					if(P.verbose>2) cerr << "Warning uncomplete Batch Result"<<endl;
					if(feof( clientstream[it] )!=0){
						if(P.verbose>2)cerr << "Deconnection Simulator:" << clientPID[it] << endl;
						clientstream.erase(clientstream.begin() + it);
						clientPID.erase(clientPID.begin() + it);
					}
				}
			}
        }
		//Check if the simulation should continue.
    }while(Result.continueSim() && clientstream.size()>0 && continueSelect);
    
	//Output all the results
    if(P.verbose>0)cout << endl;
    Result.stopclock();
    
	if(P.dataPDFCDF.length()>0)
		Result.outputCDFPDF(P.dataPDFCDF);
	
	if(P.alligatorMode){
		Result.printAlligator();
		Result.printGnuplot();
	} else{
        if(P.verbose>1)Result.print(cout);
	}
	
	
	Result.close_gnuplot();
    //Kill all the simulator
    kill_client();
    
    string fn = "Result";
    fn.append(".res");
    Result.printResultFile(fn);
    
}
