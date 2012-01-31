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
#include "numSolverBB.hpp"
#include "numSolverSH.hpp"
#include <sys/resource.h>

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(int m){
    switch (m) {
        case 1:
            numSolv = new numericalSolver();
            break;
            
        case 2:
            numSolv = new numSolverBB();
            break;
            
        case 3:
            numSolv = new numSolverSH();
            break;
    }
    
    delete EQ;
	
	//numSolv->initVect(T);
}

void SimulatorBoundedRE::initVect(int T){
    numSolv->initVect(T);
}

BatchR* SimulatorBoundedRE::RunBatch(){
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


double SimulatorBoundedRE::mu(){
	
	vector<int> vect (N.Msimpletab.size());
	for(int i=0; i< N.Msimpletab.size();i++){
		vect[i] = N.Marking[N.Msimpletab[i]];
	};
	
	int stateN = numSolv->findHash(&vect);
	 
	if(stateN<0){
		cerr << numSolv->getVect()<< endl;
		cerr << "state not found" << endl;
	}
		
	return(numSolv->getMu(stateN));
}

double SimulatorBoundedRE::ComputeDistr(int t , double origin_rate){
	
	//cerr << endl<< "mux" << endl;
	double mux = mu();
	if( mux==0.0 || mux==1.0) return(origin_rate);
    
	if(t== N.tr-1){
		if(N.Origine_Rate_Sum >= N.Rate_Sum){
			//cerr << "strange !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
		}else{ 
			return 0.0 ;};
	}; 
	
	double distr;
	N.fire(t);
	numSolv->stepVect();
	distr = origin_rate *( mu() / mux);
	//cerr << " distr: "<< distr << " ";
	
	numSolv->previousVect();
	N.unfire(t);
	return(distr);
}
