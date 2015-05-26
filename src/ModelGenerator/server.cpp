/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
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
 * Most of this file is C code.
 */


#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>
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
#include <err.h>
#include <assert.h>

#include "../Simulator/BatchR.hpp"
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


int selfPipe;

void init_self_pipe(){
    int pipefd[2];

    //create the self pipe
    if(pipe(pipefd) !=0  )err(1,"Fail to create a self pipe");

    FILE* output = fdopen(pipefd[0], "r");
    selfPipe=pipefd[1];

    clientstream.push_back(output);
    if(pipefd[0] >max_client)max_client = pipefd[0];
    clientPID.push_back(0);

}

//! Boolean indicating if the simulation should continue.
bool continueSelect=false;

void signalHandlerSP(int signum){
    char buff[1];
    buff[0] = (char)signum;
    assert(1==write(selfPipe, buff, 1));
}

void signalHandler( int signum )
{
    switch (signum){
        case SIGCHLD: {
            int status;
            pid_t child = wait(&status);

            if(child != -1){
                if(!WIFEXITED(status)){ //Something to report
                    if(count(clientPID.begin(),clientPID.end(),child)==0)
                        cerr << "The unknown child "<< child << "Terminated by signal :" << WTERMSIG(status) << endl;
                    else{
                        if(WIFSIGNALED(status)){
                            cerr << "Simulator "<< child << "Terminated by signal :" << WTERMSIG(status) << endl;
                            exit(EXIT_FAILURE);
                        } else if(WIFEXITED(status)){
                            if(WEXITSTATUS(status) != 130){
                                cout << "Simulator exit with code " << WEXITSTATUS(status) << endl;
                            }
                        }else {
                            cerr << "Simulator "<< child << " Crash ! with unknown status "<< status  << endl;
                        }
                    }
                }
            }
            break;
        }
        case SIGINT:
            continueSelect = false;
            break;
        case SIGPIPE:
            cerr << "receive a sigpipe" <<endl;
            break;


        default:
            cerr << " Unexpected signal: " << signum << endl;
    }
}

/*
 * Open a child processes retriving both PID and an a pipe
 * to the standart input of the child.
 * This function fork and execute the given binary
 * on the child.
 * @param bin the path to the binary to execute.
 * @param argv the list of argument.
 */
void popenClient(const char* bin, const char *argv[]){
	pid_t pid = 0;
	int pipefd[2];
	int pipeerr[2];
	FILE* output;
	
	//create a pipe
	if(pipe(pipefd) !=0  )err(1,"Fail to launch simulator");
	if(pipe(pipeerr) != 0)err(1,"Fail to launch simulator");
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
	sprintf(s, "%zu", v);
	argv[argn] = s;
	argn++;
}

inline void pushdouble(const char *argv[],size_t &argn,double v){
	char* s = (char *)malloc(255*sizeof(char));
	sprintf(s, "%e", v);
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

void launch_clients(parameters& P){
    init_self_pipe();
    signal(SIGCHLD , signalHandlerSP);
    signal(SIGINT, signalHandlerSP);
    signal(SIGPIPE, signalHandlerSP);
	//pid_t readpid;

	for(int i = 0;i<P.Njob;i++){
		string cmd = P.tmpPath + "/ClientSim";;
		const char *argv[15] = {0};
		size_t argn = 0;
		pushstr(argv, argn, cmd.c_str());
		
		pushint(argv,argn,P.Batch);
        if (P.interactive) {
            pushint(argv,argn,6);
        } else pushint(argv,argn,P.verbose);
        pushstr(argv,argn,P.tmpPath.c_str());

		//<< P.Batch << " " << P.verbose;
		
		// if seed is zero generate a pseudo random seed.
		if(P.seed==0){
			timeval t;
			gettimeofday(&t,(struct timezone*)0);
			//os << " " <<(t.tv_usec + t.tv_sec + getpid()+i);
			pushint(argv,argn,(t.tv_usec + t.tv_sec + getpid()+i));
		}else{
			//if seed is not null add i to the seed to guarantee independance
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
			pushint(argv, argn, P.continuousStep);
		} else if(P.BoundedRE>0){
			//os << " " << "-BURE" << " " << P.BoundedRE << " " << P.horizon;
			pushstr(argv,argn,"-BURE");
			pushint(argv,argn,P.BoundedRE);
			pushint(argv,argn,(int)P.horizon);
		} else if(P.DoubleIS){
			//os << " " << "-RE2";
			pushstr(argv,argn,"-RE2");
		} else if(P.RareEvent){
			//os << " " << "-RE";
			pushstr(argv,argn,"-RE");
		} else if(P.computeStateSpace==1){
            pushstr(argv,argn,"-STSP");
            pushstr(argv,argn,P.prismPath.c_str());
        } else if(P.computeStateSpace>1){
            pushstr(argv,argn,"-STSPBU");
            pushstr(argv,argn,P.prismPath.c_str());
        }
		
		//If logging the row data is require pass it as an option.
		if (P.dataraw!=""){
			//os << " -log " << P.dataraw;
			pushstr(argv,argn,"-log");
			pushstr(argv,argn,P.dataraw.c_str());
		}

        if (P.dotfile!=""){
            //os << " -log " << P.dataraw;
            pushstr(argv,argn,"-dotFile");
            pushstr(argv,argn,P.dotfile.c_str());
        }

		if (P.datatrace!=""){
			//os << " -log " << P.dataraw;
			pushstr(argv,argn,"-trace");
			pushstr(argv,argn,P.datatrace.c_str());
			pushdouble(argv,argn,P.sampleResol);
		}
		
		if(P.verbose >2){
			for(size_t i=0; i<argn; i++ )cout << " " << argv[i];
			cout << endl;
        }

        popenClient(cmd.c_str(),argv);
        freestr(argv, argn);

    }

}

void kill_client(){
    while (!clientPID.empty()){
        if (clientPID.back()!=0)kill(clientPID.back(),SIGHUP);
        clientstream.pop_back();
        clientPID.pop_back();
    }
}

void wait_client(){
    pid_t child= 1;
    while (child != -1) {
		int termstat;
		child = wait(&termstat);
	}
	
}

void makeselectlist(void){
    FD_ZERO(&client_list);
    for(size_t it = 0;it < clientstream.size(); it++){
        int fl = fileno(clientstream[it]);
        FD_SET(fl,&client_list);
    }
}

/**
 * This function launch a set of simulators and stop them once
 * The precision criterion is reach.
 */
void launchServer(parameters& P){
    //Init result
    result Result;

    //Try to read previous batch
    {
        FILE* intraj = fopen((P.tmpPath+"/saveTraj").c_str(),"r");
        if(intraj != NULL){
            Result.MeanM2.inputR(intraj);
            cout << Result.MeanM2.I << " Previous Trajectories found and loaded" << endl;
        }
    }

    if(P.verbose>0)cout << "START SIMULATION ..." << endl<< endl << endl << endl;

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
                if (clientPID[it]==0) {
                    // Receive through self pipe
                    char buff[1];
                    read(fileno(clientstream[it]), buff, 1);
                    //cerr << "receive signal" << (int)buff[0] <<endl;
                    signalHandler((int)buff[0]);
                    continue;
                }
                //aggregate the new result to the total result
                BatchR batchResult(P.nbAlgebraic);

                if(batchResult.inputR(clientstream[it])){
					//batchResult.print();
					Result.addBatch(batchResult);
					//If neaded output the progress of the computation.
					if((P.verbose>0 || P.alligatorMode) && P.computeStateSpace==0 )
                        Result.printProgress();
				} else {
					//The batch result was not complete.
					//If the simulator was kill by the server it is OK otherwise
					//it is a problem.
					if(P.verbose>2) cerr << "Warning uncomplete or ill formed Batch Result"<<endl;
					if(feof( clientstream[it] )!=0){
						if(P.verbose>2)cerr << "Deconnection Simulator:" << clientPID[it] << endl;
						clientstream.erase(clientstream.begin() + it);
						clientPID.erase(clientPID.begin() + it);
					}
				}
			}
        }
		//Check if the simulation should continue.
    }while(Result.continueSim() && clientstream.size()>1 && continueSelect);
    signal(SIGCHLD, signalHandler);
    signal(SIGPIPE, signalHandler);

    //Kill all the simulator
    kill_client();
    //signal(SIGCHLD, SIG_IGN);
	
	//Output all the results
    Result.stopclock();
    if(P.verbose>0){
        Result.printCompactResult();
        cout<< endl;
    }

    if(P.tmpStatus != 0){
        ofstream savetraj(P.tmpPath+"/saveTraj");
        Result.MeanM2.outputR(savetraj);
    }

	//use gnuplot
	if(P.dataPDFCDF.length()>0)Result.outputCDFPDF(P.dataPDFCDF);
	//if(P.alligatorMode)
	Result.printGnuplot();
	
	Result.close_gnuplot();
	wait_client();
    
	if(P.alligatorMode){
		Result.printAlligator();
	} else{
        if(P.verbose>1)Result.print(cout);
	}
	
	size_t lastslash = P.PathLha.find_last_of("/");
	if(lastslash==string::npos)lastslash= -1;
	size_t lastdot = P.PathLha.find_last_of(".");
    string fn = "Result_" + P.PathLha.substr(lastslash+1,lastdot - lastslash-1 );
    fn.append(".res");
    Result.printResultFile(fn);
	Result.printResultFile("Result.res");
    
}
