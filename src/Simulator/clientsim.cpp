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
 * file clientsim.cpp created by Benoit Barbot.                                *
 *******************************************************************************
 */

#include "BatchR.hpp"
#include "Simulator.hpp"
#include "SimulatorRE.hpp"
#include "SimulatorBoundedRE.hpp"
#include "SimulatorContinuousBounded.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


// Handler for interuption of the server
void signalHandler(int);

void signalHandler( int s)
{
    if(s == SIGHUP )exit(EXIT_SUCCESS);
}

/**
 * main function it read the options given as arguments and initialyse
 * the simulator.
 * Then it start a while loop which compute a batch of trajectory
 * and output the result.
 * The loop stop only when the programme receive end_of_file on
 * his standart input
 */
int main(int argc, char** argv) {
	//assert(cerr<< "Cosmos compile in DEBUG mode!"<< endl);
	//cerr << "start client"<< endl;
	//pid_t pid =getpid();
	//write(STDOUT_FILENO,reinterpret_cast<char*>(&pid),sizeof(pid));
	//fflush(stdout);
	//cerr << "pid : "<< pid << endl;

  //retrive_segment();

	signal(SIGINT, SIG_IGN);
    signal(SIGHUP, signalHandler);
	
	Simulator* mySim;
	
	string str;
    const int optioni=5;
	
	if(argc > optioni){
		
		str = argv[optioni];
		if(str== "-RE"){
			SimulatorRE* myRESim= new SimulatorRE(false);
			myRESim->initVect();
			mySim=myRESim;
		}else if(str== "-RE2"){
			SimulatorRE* myRESim= (new SimulatorRE(true));
			myRESim->initVect();
			mySim = myRESim;
		}else if(str== "-BURE"){
            int m = atoi(argv[optioni+1]);
            int T = atoi(argv[optioni+2]);
            SimulatorBoundedRE* myBoundedSim = new SimulatorBoundedRE(m);
            myBoundedSim->initVect(T);
			mySim= myBoundedSim;
		}else if(str== "-COBURE"){
            int m = atoi(argv[optioni+1]);
            double t = atof(argv[optioni+2]);
            double e = atof(argv[optioni+3]);
			int stepc = atoi(argv[optioni+4]);
            SimulatorContinuousBounded* myBoundedSim = new SimulatorContinuousBounded(m,e,stepc);
            myBoundedSim->initVectCo(t);
			mySim= myBoundedSim;
		}else if(str== "-STSPBU"){
			stateSpace states;
			states.exploreStateSpace();
			states.buildTransitionMatrix();
			//states.uniformizeMatrix();
			states.outputMat();
			states.outputTmpLumpingFun();
            BatchR dummR(0);
            dummR.outputR();
            cerr << "Finish Exporting" << endl;
			exit(EXIT_SUCCESS);
		}else if(str== "-STSP"){
			stateSpace states;
			states.exploreStateSpace();
			states.buildTransitionMatrix();
			states.outputPrism();
			states.launchPrism(argv[optioni+1]);
			states.importPrism();
			states.outputVect();
			states.outputTmpLumpingFun();
			//cout << "Finish Exporting" << endl;
			double prResult = states.returnPrismResult();
            BatchR dummR(1);
            dummR.addSim(make_pair<bool,vector<double> >(true,vector<double>(1,prResult)));
            dummR.outputR();
			/*cout << "Prism Result:\t"<< prResult << endl;
			ofstream ResultsFile("Result.res", ios::out | ios::trunc);
			ResultsFile << "Result Computed by Prism:" << endl;
			ResultsFile << "Estimated value:\t" << prResult << endl;
			ResultsFile << "Confidence interval:\t[" <<prResult*0.9999;
			ResultsFile << " , " << prResult*1.00001 << "]" << endl;
			ResultsFile.close();*/
			exit(EXIT_SUCCESS);
		} else mySim= (new Simulator);
		
    } else {
		mySim= (new Simulator);
	}
	
	for(int i=1; i<argc ;i++){
		if(strcmp(argv[i],"-log")==0 && argc>i)
			mySim->logValue(argv[i+1]);
		if(strcmp(argv[i],"-trace")==0 && argc>i){
			mySim->logTrace(argv[i+1],stod(argv[i+2]));
		}
        if(strcmp(argv[i],"-dotFile")==0 && argc>i){
            mySim->dotFile = argv[i+1];
        }
	}
    
	
	if(argc>=optioni-1){
		mySim->SetBatchSize(atoi(argv[1])); //set the batch size
		mySim->verbose = atoi(argv[2]);
		mySim->initRandomGenerator(atoi(argv[4]));
        mySim->tmpPath=argv[3];
	}else{
		cerr << "Not enough argument";
		return (EXIT_FAILURE);
	}
	
    if(mySim->verbose>=4)mySim->RunBatch();
    else while( !cin.eof() ){
		BatchR batchResult = mySim->RunBatch(); //simulate a batch of trajectory
		
		batchResult.outputR();// output the result on the standart output
		
		//cerr << batchResult->I <<":"<< batchResult->Isucc <<":"<< batchResult->Mean[0]
		//<< ":" << batchResult->M2[0] << endl;
		
    }
	
    return (EXIT_SUCCESS);
	
	
}
