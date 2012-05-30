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

// convert a string to an integer
int StrToInt(string st) {
    std::istringstream iss(st);
    int x;
    iss >> x;
    return x;
}

// main function it read the options given as arguments and initialyse 
// the simulator.
// Then it start a while loop which compute a batch of trajectory
// and output the result.
// The loop stop only when the programme receive end_of_file on
// his standart input
int main(int argc, char** argv) {
		//cerr << "start client"<< endl;	
	pid_t pid =getpid();
	write(STDOUT_FILENO,reinterpret_cast<char*>(&pid),sizeof(pid));
	fflush(stdout);
	//cerr << "pid : "<< pid << endl;
    Simulator* mySim; 
	
	string str;
	
	if(argc > 3){

		str = argv[3];
		if(str== "-RE"){
			mySim= (new SimulatorRE(false));
			//mySim->RareEvent_mode=true;
		}
		if(str== "-RE2"){
			mySim= (new SimulatorRE(true));
			//mySim->RareEvent_mode=true;
			//mySim->doubleIS_mode=true;
		}
		if(str== "-BURE"){
            int m = atoi(argv[4]);
            int T = atoi(argv[5]);
            SimulatorBoundedRE* myBoundedSim = new SimulatorBoundedRE(m);
            myBoundedSim->initVect(T);
			mySim= myBoundedSim;
		}
        if(str== "-COBURE"){
            int m = atoi(argv[4]);
            double t = atof(argv[5]);
            double e = atof(argv[6]);
            SimulatorContinuousBounded* myBoundedSim = new SimulatorContinuousBounded(m,e);
            myBoundedSim->initVectCo(t);
			mySim= myBoundedSim;
		}
		if(str== "-STSPBU"){
			stateSpace states;
			states.exploreStateSpace();
			states.buildTransitionMatrix();
			states.outputMat();
            cout << "Finish Exporting" << endl;
			exit(EXIT_SUCCESS);
		}
        if(str== "-STSP"){
			stateSpace states;
			states.exploreStateSpace();
			states.buildTransitionMatrix();
            states.outputPrism();
            states.launchPrism(argv[4]);
            states.importPrism();
            states.outputVect();
            cout << "Finish Exporting" << endl;
			exit(EXIT_SUCCESS);
		}
    } else {
		mySim= (new Simulator);
	}
    
    //mySim->Load(); //initialize the simulator
	
    str = argv[1];
    mySim->SetBatchSize(StrToInt(str)); //set the batch size
    str = argv[2];
    mySim->verbose = StrToInt(str);
    //mySim->logValue();
    
    
    while( !cin.eof() ){
      BatchR* batchResult = mySim->RunBatch(); //simulate a batch of trajectory

      batchResult->outputR();// output the result on the standart output
      
      /*cout << batchR->I <<":"<< batchR->Isucc <<":"<< batchR->Mean 
	<< ":" << batchR->M2 << endl;*/

      delete batchResult;
      
    }

    return (EXIT_SUCCESS);


}
