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

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(){
	//numSolv = new numericalSolver();
	//numSolv = new numSolverBB();
	numSolv = new numSolverSH();
	
	delete EQ;
	int T =122;
	
	//numericalSolver numSolv;
	//numSolv.computeMatrix();
	numSolv->initVect(T);
	
	/*for(int i=0;i<T-1;i++){
		cerr << "itvect:"<<i<< "->" << numSolv.getVect() << endl;
		numSolv.stepVect();
	};*/
	
	//exit(0);
	
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
	return (batchResult);
}


double SimulatorBoundedRE::mu(){
	
	vector<int> vect (N.Msimpletab.size());
	for(int i=0; i< N.Msimpletab.size();i++){
		vect[i] = N.Marking[N.Msimpletab[i]];
		//cout << i << " : " << N.Msimpletab[i] << " : " << N.Marking[N.Msimpletab[i]] << endl;
	};
	//vect[vect.size()-1]=A.CurrentLocation;
	
	
	int stateN = numSolv->findHash(&vect);
	
	/*for (int i=0; i<vect.size(); i++) {
		cerr << vect[i];
	}*/
	//cerr << " state:"<< stateN << " prob:" << numSolv.getMu(stateN) << " -> ";
	
	 
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
