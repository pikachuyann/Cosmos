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
#include <sys/resource.h>


SimulatorContinuousBounded::SimulatorContinuousBounded(int m,double e):SimulatorBoundedRE(m){
    epsilon = e;
}

void SimulatorContinuousBounded::initVectCo(double t){
    
    lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    fg=NULL;
    if (fox_glynn(lambda * t, 1e-16, 1e+16,epsilon, &fg)){
        cerr << "fox_glyn:" << fg->left << "," << fg->right << "Total weigts:"<< fg->total_weight<< endl;
        /*for(int i = 0; i<= fg->right - fg->left; i++){
            cerr << "i:\t"<< fg->left+i<< "\tcoeff:\t" << fg->weights[i]<< endl;
        }*/
    }
    initVect(fg->right);
    
}

BatchR* SimulatorContinuousBounded::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
    int Nmax = fg->right -fg->left;
    
    vector<double> MeanN (Nmax,0.0);
    vector<double> M2N (Nmax,0.0);
	vector<int> IsuccN (Nmax,0);
    int n =0;
    
	double Dif=0.0;
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
		n++;
        
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
			AutEdge AE;
			
			(*it).loadState(&N,&A,&AE,&EQ, &simTime);
			//cerr << A.Likelihood << endl;		
			
			bool continueb = SimulateOneStep(&AE);
			
			if((!EQ->isEmpty() || AE.Index > -1) && continueb) {
				(*it).saveState(&N,&A,&AE,&EQ, &simTime);
			} else {
				if (Result.first && n >= fg->left) {
					//cerr << endl<<"Result:" << Result.second << endl;
					batchResult->Isucc++;
					
                    //cerr << "finish(" << endl;
                    
					if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
					
                    for (int i= 0; i<n-fg->left; i++) {
                        IsuccN[i]++;
                    
                        Dif = Result.second - MeanN[i];
                        MeanN[i] += Dif / IsuccN[i];
					
                        Dif = pow(Result.second, 2) - M2N[i];
                        M2N[i] += Dif / IsuccN[i];
					}
                    //cerr << ")finish" << endl;
                        
				}
				
				batchResult->I++;
				
                
                delete EQ;
				it = statevect.erase(it);
				
                it--;
			}
			
			
			
		}
        
	}
	
	cerr << "test" << endl;
	//exit(0);
    int Isucc =0;
    
    for(int i=0; i< fg->right- fg->left; i++){
        //cerr << "Mean:\t"  << MeanN[i] << endl<< "M2:\t" << M2N[i] <<
        //endl << "coeff:\t" << fg->weights[i] << endl;
        Isucc += IsuccN[i];
        Dif = MeanN[i] - batchResult->Mean;
        batchResult->Mean += (IsuccN[i] * fg->weights[i] * Dif / Isucc)/fg->total_weight;
        
        Dif = M2N[i] - batchResult->M2; 
        batchResult->M2 +=  (IsuccN[i] * fg->weights[i] * Dif / Isucc)/fg->total_weight ;
    }
    //batchResult->Isucc = IsuccN[0];
    
    rusage ruse;
    getrusage(RUSAGE_SELF, &ruse);
    cerr << "\033[A\033[2K"<< "\033[A\033[2K" << "\033[A\033[2K" << "Total Time: "<<  ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl << endl; 
    
    //batchResult->print();
    //exit(0);
	return (batchResult);
}

void SimulatorContinuousBounded::updateSPN(int E1_transitionNum){
	Event F;
	
	if( ! N.IsEnabled(E1_transitionNum)) (*EQ).remove(0);
	
	for (set<int>::iterator it = N.PossiblyEnabled[E1_transitionNum].begin(); it != N.PossiblyEnabled[E1_transitionNum].end(); it++) {
		if (N.IsEnabled(*it)) {
			if ((*EQ).TransTabValue(*it) < 0) {
				GenerateDummyEvent(F, (*it));
				(*EQ).insert(F);
			} 
		}
	}
	
	for (set<int>::iterator it = N.PossiblyDisabled[E1_transitionNum].begin(); it != N.PossiblyDisabled[E1_transitionNum].end(); it++) {
		if ((*EQ).TransTabValue(*it)>-1) {
			if (!N.IsEnabled(*it))
				(*EQ).remove((*EQ).TransTabValue(*it));
		}
	}
	
	
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	vector<int> Enabled_trans ((*EQ).getSize());
	for(int i=0; i< (*EQ).getSize(); i++){ 
		Enabled_trans[i] = (*EQ).InPosition(i).transition; 
	};
	
	for (vector<int>::iterator it = Enabled_trans.begin(); it != Enabled_trans.end(); it++) {
		if(*it != N.tr-1 && *it != N.tr-2){
			if(N.IsEnabled(*it)){
				GenerateEvent(F, (*it));
				(*EQ).replace(F, (*EQ).TransTabValue(*it));
			}else {
				(*EQ).remove((*EQ).TransTabValue(*it));
			}
		}; 
	};
	
    GenerateEvent(F, (N.tr-2));
	if(!doubleIS_mode){
		(*EQ).replace(F, (*EQ).TransTabValue(N.tr-2));
	}
    
	GenerateEvent(F, (N.tr-1));
	if(!doubleIS_mode){
		(*EQ).replace(F, (*EQ).TransTabValue(N.tr-1));
	}
	
};

vector<double> SimulatorContinuousBounded::getParams(int Id){
	
	vector<double> P(2);
	double origin_rate = (N.GetDistParameters(Id))[0];
    if(Id== N.tr-2)origin_rate = lambda - N.Origine_Rate_Sum;
    P[0]= ComputeDistr( Id, origin_rate);
	P[1]= origin_rate;
	return P;
}