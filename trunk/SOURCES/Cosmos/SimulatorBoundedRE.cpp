/*
 *  SimulatorBoudedRE.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorBoundedRE.hpp"
#include <list>

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(){
	delete EQ;
	int T =40;
	
	//numericalSolver numSolv;
	numSolv.computeMatrix();
	numSolv.initVect(T);
	
	for(int i=0;i<T-1;i++){
		numSolv.stepVect();
		cout << "itvect:"<<i<< "->" << numSolv.getVect() << endl;
	};
	
	exit(0);
	
}


BatchR* SimulatorBoundedRE::RunBatch(){
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
		cout << "new round" << endl;
		numSolv.stepVect();
		
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
			AutEdge AE;
			
			(*it).loadState(&N,&A,&AE,&EQ, &simTime);
					
			bool continueb = SimulateOneStep(&AE);
			
			if((!EQ->isEmpty() || AE.Index > -1) && continueb ) {
				(*it).saveState(&N,&A,&AE,&EQ, &simTime);
			} else {
				if (Result.first) {
					
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
	return (batchResult);

}