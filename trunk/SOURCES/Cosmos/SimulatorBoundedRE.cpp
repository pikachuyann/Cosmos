/*
 *  SimulatorBoudedRE.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorBoundedRE.hpp"
#include "numericalSolver.hpp"

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(){
	numericalSolver numSolv;
	numSolv.computeMatrix();
	numSolv.initVect(20);
	
	exit(0);
	
}


BatchR* SimulatorBoundedRE::RunBatch(){
	double Dif=0;
	//double Y = 0;
	BatchR* batchResult = new BatchR();
	
	while (batchResult->Isucc < BatchSize) {
		
		
		
		SimulateSinglePath();
		
		
		if (Result.first) {
			//------------------ Rare Event -----------------
			//logvalue << Result.second << endl ;
			//----------------- /Rare Event -----------------
			batchResult->Isucc++;
			
			if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
			
			
			Dif = Result.second - batchResult->Mean;
			batchResult->Mean += Dif / batchResult->Isucc;
			
			Dif = pow(Result.second, 2) - batchResult->M2;
			batchResult->M2 += Dif / batchResult->Isucc;
			
			/*if (Isucc > 1) {
			 Dif = pow(Result.second, 2) - Y;
			 Y = Y + Dif / (Isucc - 1);
			 } else x1sqr = pow(Result.second, 2);*/
		}
		
		reset();
		batchResult->I++;
		
	}
	
	return (batchResult);

}