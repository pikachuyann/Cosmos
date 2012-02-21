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
    if (fox_glynn(lambda * t, DBL_EPSILON , 1/DBL_EPSILON ,epsilon, &fg)){
        cerr << "fox_glyn:" << fg->left << "," << fg->right << " Total weigts:"<< fg->total_weight<< endl;
        /*for(int i = 0; i<= fg->right - fg->left; i++){
            cerr << "i:\t"<< fg->left+i<< "\tcoeff:\t" << fg->weights[i]/ fg->total_weight << endl;
        }*/
    }
    //fg->right = 10; 
    initVect(fg->right+1);
    
}

BatchR* SimulatorContinuousBounded::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
    int left = max(numSolv->getMinT(),fg->left);
    int Nmax = fg->right - left;
    cerr << "minT:\t" << numSolv->getMinT() << endl;
    cerr << "Nmax:\t" << Nmax << endl;
    cerr << "left:\t" << left << endl;
    
    vector<double> MeanN (Nmax+1,0.0);
    vector<double> M2N (Nmax+1,0.0);
	vector<int> IsuccN (Nmax+1,0);
    int n =-1;
    
	double Dif=0.0;
	//double Y = 0;
	BatchR* batchResult = new BatchR();
	
	list<simulationState> statevect((Nmax+1)*BatchSize);
	//delete EQ;
	
    int c =0;
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		EQ = new EventsQueue(N.tr);
		reset();
        it->maxStep = fg->right - (c/BatchSize);
		//cerr << "new path:\t" << it->maxStep << endl;
        
        c++;
		AutEdge AE;
		A.CurrentLocation = A.EnabledInitLocation(N.Marking);
		A.CurrentTime = 0;
		
		
		//Simulator::InitialEventsQueue();
		
		AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
		
		(*it).saveState(&N,&A,&AE,&EQ, &simTime);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
		//cerr << numSolv->getVect() << endl;
		n++;
        //cerr << "new round:"<< n << endl;
        
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
            if(it->maxStep >= fg->right -n){
                   
                //cerr << "vect:\t" << it->maxStep;
                AutEdge AE;
                
                it->loadState(&N,&A,&AE,&EQ, &simTime);
                
                
                //cerr << A.Likelihood << endl;	
                
                //cerr << "mu:\t" << mu() << " -> ";
                
                if (it->maxStep == fg->right -n) {
                    //We first need to initialise the trajectory
                    Simulator::InitialEventsQueue();
                    it->saveState(&N,&A,&AE,&EQ, &simTime);
                } else {
                    
                    bool continueb = SimulateOneStep(&AE);
                    //cerr << "\t" << mu() << endl;
                    
                    if((!EQ->isEmpty() || AE.Index > -1) && continueb) {
                        it->saveState(&N,&A,&AE,&EQ, &simTime);
                    } else {
                        if (Result.first) {
                            //cerr << "n:\t" << n <<" Result:" << Result.second << " maxStep:\t" << it->maxStep <<endl;
                            batchResult->Isucc++;
                            
                            //cerr << "finish(" << endl;
                            
                            if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;
                            
                            //for (int i= max(0,n-fg->left); i<fg->right - fg->left; i++) 
                            {
                                int i = it->maxStep - left;
                                //cerr << "i:\t" << i << endl;
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
			
		}
        
	}
	
	//cerr << "test" << endl;
	//exit(0);
    //int Isucc =0;
    
    double stdev = 0.0;
    int leftdec = left- fg->left;
    for(int i=0; i<= fg->right- left; i++){
       
        double var = M2N[i]- pow(MeanN[i],2);
        double stdevN = 0.0;
        if(var>0)stdevN = sqrt(var); 
        
        cerr << "i:\t" << i+ left<< "\tMean:\t"  << MeanN[i] << "\tstdev:\t" << stdevN << "\tcoeff:\t" << fg->weights[i+leftdec]/fg->total_weight << endl;
        
        batchResult->Mean += fg->weights[i+leftdec] * MeanN[i] ;
        stdev += fg->weights[i+leftdec] * stdevN;
        
        //batchResult->M2 += pow(fg->weights[i+leftdec]/fg->total_weight,2) * M2N[i];
        
        //Isucc += IsuccN[i];
        //Dif = (fg->weights[i] * MeanN[i])/fg->total_weight - batchResult->Mean;
        //batchResult->Mean += (IsuccN[i] * Dif / Isucc);       
        //Dif = M2N[i] - batchResult->M2; 
        //batchResult->M2 +=  (IsuccN[i] * fg->weights[i] * Dif / Isucc)/ fg->total_weight; 
    }
    batchResult->Mean /= fg->total_weight;
    stdev /= fg->total_weight;
    
    batchResult->M2 = pow(stdev, 2) + pow(batchResult->Mean,2);
    //batchResult->M2 /= pow(fg->total_weight,2);
    
    //batchResult->Isucc = IsuccN[0];
    cerr << endl;
    
    rusage ruse;
    getrusage(RUSAGE_SELF, &ruse);
    cerr << "\033[A\033[2K" << "\033[A\033[2K" << "Total Time: "<<  ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl << endl; 
    
    batchResult->print();
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
        //cerr << "active transition:" << *it << endl;
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
    if(Id== N.tr-2){
        origin_rate = lambda - N.Origine_Rate_Sum;
        //cerr << "lambda:\t" << lambda << "\tselfloop:\t" << origin_rate << endl; 
    }    
    P[0]= ComputeDistr( Id, origin_rate);
	P[1]= origin_rate;
	return P;
}

