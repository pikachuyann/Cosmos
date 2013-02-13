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

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fstream>
#include <boost/math/distributions/normal.hpp>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>

#include "../Cosmos/BatchR.hpp"
#include "result.hpp"
#include "server.hpp"

using namespace std;

fd_set client_list;
vector<FILE*> clientstream;
vector<pid_t> clientPID;
int max_client=0 ;

// Handler for crash of the simulator
void signalHandler( int signum )
{
	switch (signum){
		case SIGCHLD: {
			int status;
			pid_t child = wait(&status);
			
			if(child == -1)perror("wait error");
			else {
				if(status==0){cout << "Simulator terminate" << endl;}
				else if(WIFSIGNALED(status)){
					if(WTERMSIG(status) != 2){
						cout << "Simulator "<< child << "Terminated by signal :" << WTERMSIG(status) << endl;
						exit(EXIT_FAILURE);
					}
				} else {
					cout << "Simulator "<< child << "Crash !" << endl;
				}
			}
		}
			break;
		case SIGINT:
			break;
		default:
			cerr << " Unexpected signal" << endl;
	}
}

// Launch the P.Njob copy of the simulator with the parameters define in P
void launch_clients(parameters& P){
    signal(SIGCHLD , signalHandler); 
	signal(SIGINT, signalHandler);
	pid_t readpid;
	for(int i = 0;i<P.Njob;i++){
		ostringstream os;
		os << P.tmpPath<<"/ClientSim " << P.Batch << " " << P.verbose;

		if(P.seed==0){
			timeval t;
			gettimeofday(&t,(struct timezone*)0);
			os << " " <<(t.tv_usec + t.tv_sec + getpid()+i);
		}else{
			os << " " << (P.seed+i);
		}
		
		if(P.DoubleIS){
			os << " " << "-RE2";
		} else if(P.RareEvent){
			os << " " << "-RE";
		} else if(P.BoundedContinuous){
			os << " " << "-COBURE" << " " << P.BoundedRE << " " << P.horizon << " " << P.epsilon;
		} else if(P.BoundedRE>0){
			os << " " << "-BURE" << " " << P.BoundedRE << " " << P.horizon;
		}
		
		if (P.dataraw.compare("")!=0) os << " -log " << P.dataraw;
		
        FILE* stream = popen((os.str()).c_str(), "r");
        clientstream.push_back(stream);
        int streamfd = fileno(stream);
        if(streamfd >max_client)max_client = streamfd;
        
        fread(reinterpret_cast<char*>( &readpid ), sizeof(readpid) ,1, stream);
        clientPID.push_back(readpid);
    }
    
}

//Kill all the copy of the simulators at the end of the computation
void kill_client(){    
    /*rusage ruse;
     getrusage(RUSAGE_CHILDREN, &ruse);
     cout <<endl << "Total Time: "
     << ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
     << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl; */
    
    while (!clientPID.empty())
    {
        kill(clientPID.back(),2);
        clientstream.pop_back();
        clientPID.pop_back();
    }
    
}

// Build a list of input files of all the simulators to collect results
// This list is made to be used with the function <sys/select.h>/select
void makeselectlist(int Njob){
    FD_ZERO(&client_list);
    for(int it = 0;it<Njob;it++){
        int fl = fileno(clientstream[it]);
        FD_SET(fl,&client_list);
    }
}

void launchExport(parameters& P){
    
    ostringstream setuppr;
    setuppr << "cd " << P.Path << "../prism ; ./install.sh"; 
    cout << "setup prism:" << setuppr.str() << endl;
    system(setuppr.str().c_str());
    
    ostringstream os;
	os << P.tmpPath << "/ClientSim 1 " << P.verbose << " 0 ";
    os << " " << "-STSP " << P.Path << "../" << P.prismPath;
    
    if(P.verbose >1)cout << os.str() << endl;
    
    if (system(os.str().c_str()) == 0){
        cout << "Export Finish" << endl;
    }else{
        cout << "Export Fail" << endl;
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
    makeselectlist(P.Njob);
    
    do{
        fd_set cs_cp = client_list;
        //wait for a simulator to return some result
        if(select(max_client+1, &cs_cp, NULL, NULL, NULL) == -1){
			if(errno == EINTR){
				break;
			}
			
            perror("Server-select() error!");
            exit(EXIT_FAILURE);
        }
        for(int it = 0;it<P.Njob;it++){
            if(FD_ISSET(fileno(clientstream[it]), &cs_cp)){
                //aggregate the new result to the total result
                BatchR batchResult(P.nbAlgebraic);
                batchResult.inputR(clientstream[it]);
                //batchResult.print();
                Result.addBatch(&batchResult);
                if(P.verbose>0 || P.alligatorMode)Result.printProgress();
            }
        }
    }while(Result.continueSim());
    
    //Kill all the simulator
    kill_client();
    
    if(P.verbose>0)cout << endl;
    Result.stopclock();
    
	if(P.dataPDFCDF.length()>0)
		Result.outputCDFPDF(P.dataPDFCDF);
	
	if(P.alligatorMode){
		Result.printAlligator();
	} else{
        if(P.verbose>1)Result.print(cout);
	}
    
    string fn = "Result";
    fn.append(".res");
    Result.printResultFile(fn);
    
}
