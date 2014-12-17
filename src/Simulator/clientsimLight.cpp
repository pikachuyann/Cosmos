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
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


// Handler for interuption of the server
void signalHandler(int);

void signalHandler( int )
{
    exit(EXIT_SUCCESS);
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

	signal(SIGINT, signalHandler);
	
	Simulator mySim;
    const int optioni=5;

	for(int i=1; i<argc ;i++){
		if(strcmp(argv[i],"-log")==0 && argc>i)
			mySim.logValue(argv[i+1]);
		if(strcmp(argv[i],"-trace")==0 && argc>i){
			mySim.logTrace(argv[i+1],stod(argv[i+2]));
		}
        if(strcmp(argv[i],"-dotFile")==0 && argc>i){
            mySim.dotFile = argv[i+1];
        }
	}
    
	
	if(argc>=optioni-1){
		mySim.SetBatchSize(atoi(argv[1])); //set the batch size
		mySim.verbose = atoi(argv[2]);
		mySim.initRandomGenerator(atoi(argv[4]));
        mySim.tmpPath=argv[3];
	}else{
		cerr << "Not enough argument";
		return (EXIT_FAILURE);
	}
	
    if(mySim.verbose>=4)mySim.RunBatch();
    else while( !cin.eof() ){
		BatchR batchResult = mySim.RunBatch(); //simulate a batch of trajectory
		
		batchResult.outputR();// output the result on the standart output
		
		//cerr << batchResult->I <<":"<< batchResult->Isucc <<":"<< batchResult->Mean[0]
		//<< ":" << batchResult->M2[0] << endl;
		
    }
	
    return (EXIT_SUCCESS);
	
	
}
