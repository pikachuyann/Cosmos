//
//  SimulatorContinuousBounded.cpp
//  Cosmos
//
//  Created by Benoit Barbot on 31/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SimulatorContinuousBounded.hpp"
#include "float.h"
#include "math.h"


SimulatorContinuousBounded::SimulatorContinuousBounded(int m,double e):SimulatorBoundedRE(m){
    epsilon = e;
}

void SimulatorContinuousBounded::initVectCo(double t){
    double lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    if (fox_glynn(lambda * t, DBL_MIN, DBL_MAX,epsilon, &fg)){
        cerr << "fox_glyn:" << fg->left << "," << fg->right << endl;
    }
    initVect(fg->right);
    
}

BatchR* SimulatorContinuousBounded::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
	
	double Dif=0;
	//double Y = 0;
	BatchR* batchResult = new BatchR();
	
	list<simulationState> statevect(BatchSize);
	//delete EQ;
	
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		EQ = new EventsQueue(N.tr);
		reset();
		
		AutEdge AE;
		A.CurrentLocation = A.EnabledInitLocation(N.Marking);
		A.CurrentTime = 0;
		
		
		Simulator::InitialEventsQueue();
		
		AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
		
		(*it).saveState(&N,&A,&AE,&EQ, &simTime);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
		//cerr << "new round" << endl;
		//cerr << numSolv.getVect() << endl;
		
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
			AutEdge AE;
			
			(*it).loadState(&N,&A,&AE,&EQ, &simTime);
			//cerr << A.Likelihood << endl;		
			
			bool continueb = SimulateOneStep(&AE);
			
			if((!EQ->isEmpty() || AE.Index > -1) && continueb) {
				(*it).saveState(&N,&A,&AE,&EQ, &simTime);
			} else {
				if (Result.first) {
					//écerr << endl<<"Result:" << Result.second << endl;
					
					batchResult->Isucc++;
					
					if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
					
					
					Dif = Result.second - batchResult->Mean;
					batchResult->Mean += Dif / batchResult->Isucc;
					
					Dif = pow(Result.second, 2) - batchResult->M2;
					batchResult->M2 += Dif / batchResult->Isucc;
					
				}
				
				batchResult->I++;
				delete EQ;
				it = statevect.erase(it);
				it--;
			}
			
			
			
		}
	}
	
	//cerr << "test" << endl;
	//exit(0);
    
    rusage ruse;
    getrusage(RUSAGE_SELF, &ruse);
    cerr <<endl << endl << "Total Time: "<<  ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl << endl; 
    
	return (batchResult);
}
