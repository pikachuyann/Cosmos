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
#include <list>

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(){
	//numericalSolver numSolv;
	//numSolv.computeMatrix();
	//numSolv.initVect(20);
	
	//exit(0);
	
}


BatchR* SimulatorBoundedRE::RunBatch(){
	double Dif=0;
	//double Y = 0;
	BatchR* batchResult = new BatchR();
	
	list<simulationState> statevect(BatchSize);
	
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		reset();
		simTime = 0.0;
		AutEdge AE;
		A.CurrentLocation = A.EnabledInitLocation(N.Marking);
		A.CurrentTime = 0;
		simTime = 0;
		
		Simulator::InitialEventsQueue();
		AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
		
		(*it).saveState(&N,&A,&AE,EQ, &simTime);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		//cout << "new round" << endl;
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
			AutEdge AE;
			
			(*it).loadState(&N,&A,&AE,EQ, &simTime);
			
			bool continueb = SimulateOneStep(&AE);
			
			if((!EQ->isEmpty() || AE.Index > -1) && continueb ) {
				(*it).saveState(&N,&A,&AE,EQ, &simTime);
			} else {
				if (Result.first) {
					
					batchResult->Isucc++;
					
					if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
					
					
					Dif = Result.second - batchResult->Mean;
					batchResult->Mean += Dif / batchResult->Isucc;
					
					Dif = pow(Result.second, 2) - batchResult->M2;
					batchResult->M2 += Dif / batchResult->Isucc;
					
				}
				
				//reset();
				batchResult->I++;
				//cout << "erase sim" << endl;
				it = statevect.erase(it);
				it--;
			}
			
			
			
		}
	}
	
	//exit(0);
	return (batchResult);

}