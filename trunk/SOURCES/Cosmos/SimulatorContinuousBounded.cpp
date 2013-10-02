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
 * file SimulatorContinuousBounded.cpp created by Benoit Barbot on 31/01/12.   *
 *******************************************************************************
 */


#include <iostream>
#include "SimulatorContinuousBounded.hpp"
#include "float.h"
#include "math.h"
#include <sys/resource.h>
//#include <boost/math/distributions/normal.hpp>

SimulatorContinuousBounded::SimulatorContinuousBounded(int m,double e):SimulatorBoundedRE(m){
    epsilon = e;
    //boost::math::normal norm;
    //Normal_quantile = quantile(norm, 0.5 + 0.99 / 2.0);
}

void SimulatorContinuousBounded::initVectCo(double t){
    
    lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    fg=NULL;
    if (fox_glynn(lambda * t, DBL_EPSILON , 1/DBL_EPSILON ,epsilon, &fg)){
        cerr << "fox_glyn:" << fg->left << "," << fg->right << " Total weigts:"<< fg->total_weight<< endl;
        /*for(int i = 0; i<= fg->right - fg->left; i++){
            cerr << fg->left+i << " " << fg->weights[i]/ fg->total_weight << endl;
        }*/
    }
    //fg->right = 10;
	double lambda2= lambda;
    initVect(fg->right+1);
    lambda = lambda2;
}

BatchR* SimulatorContinuousBounded::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
    int left = (int)max(numSolv->getMinT(),fg->left);
    int Nmax = fg->right - left;
    //cerr << "minT:\t" << numSolv->getMinT() << endl;
    cerr << "Nmax:\t" << Nmax << endl;
    //cerr << "left:\t" << left << endl;
    
    vector<double> MeanN (Nmax+1,0.0);
    vector<double> M2N (Nmax+1,0.0);
	vector<int> IsuccN (Nmax+1,0);
    int n =-1;
    
	double Dif=0.0;
	//double Y = 0;
	BatchR* batchResult = new BatchR(A.FormulaVal.size());
	
	list<simulationState> statevect((Nmax+1)*BatchSize);
	//delete EQ;
	
    int c =0;
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		EQ = new EventsQueue(N);
		reset();
        it->maxStep = fg->right - (c/BatchSize);
		//cerr << "new path:\t" << it->maxStep << endl;
        
        c++;
		AutEdge AE;
		A.setInitLocation(N.Marking);
		A.CurrentTime = 0;
		
		
		//Simulator::InitialEventsQueue();
		
		AE = A.GetEnabled_A_Edges( N.Marking);
		
		(*it).saveState(&N,&A,&AE,&EQ, &A.CurrentTime);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
		if(verbose>=3)cerr << numSolv->getVect() << endl;
		n++;
        if(verbose>=1)cerr << "new round:"<< n << "\tremaining trajectories: "<< statevect.size() << endl;
        
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
            if(it->maxStep >= fg->right -n){
                   
                //cerr << "vect:\t" << it->maxStep;
                AutEdge AE;
                
                it->loadState(&N,&A,&AE,&EQ, &A.CurrentTime);
                
                
                //cerr << A.Likelihood << endl;	
                
                //cerr << "mu:\t" << mu() << " -> ";
                
                if (it->maxStep == fg->right -n) {
                    //We first need to initialise the trajectory
                    Simulator::InitialEventsQueue();
                    it->saveState(&N,&A,&AE,&EQ, &A.CurrentTime);
                } else {
                    
                    bool continueb = SimulateOneStep();
                    //cerr << "\t" << mu() << endl;
                    
                    if((!EQ->isEmpty()) && continueb) {
                        it->saveState(&N,&A,&AE,&EQ, &A.CurrentTime);
                    } else {
                        if (Result.first) {
                            //cerr << "n:\t" << n <<" Result:" << Result.second << " maxStep:\t" << it->maxStep <<endl;
                            //batchResult->Isucc++;
                            
                            //cerr << "finish(" << endl;
                            
                            if (Result.second[0] * (1 - Result.second[0]) != 0) batchResult->IsBernoulli[0] = false;
							
                            //for (int i= max(0,n-fg->left); i<fg->right - fg->left; i++) 
                            {
                                int i = it->maxStep - left;
                                //cerr << "i:\t" << i << endl;
                                IsuccN[i]++;
                                
                                Dif = Result.second[0] - MeanN[i];
                                MeanN[i] += Dif / IsuccN[i];
                                
                                Dif = pow(Result.second[0] , 2) - M2N[i];
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
        
        if(verbose>=2)cerr << "i:\t" << i+ left<< "\tMean:\t"  << MeanN[i] << "\tstdev:\t" << stdevN << "\tcoeff:\t" << fg->weights[i+leftdec]/fg->total_weight << endl;
        
        batchResult->Mean[0] += fg->weights[i+leftdec] * MeanN[i]  * IsuccN[i];
        stdev += fg->weights[i+leftdec] * stdevN * IsuccN[i];
        batchResult->Isucc += IsuccN[i];
        //batchResult->I = IsuccN[0];
        
        //batchResult->M2 += pow(fg->weights[i+leftdec]/fg->total_weight,2) * M2N[i];
        
        //Isucc += IsuccN[i];
        //Dif = (fg->weights[i] * MeanN[i])/fg->total_weight - batchResult->Mean;
        //batchResult->Mean += (IsuccN[i] * Dif / Isucc);       
        //Dif = M2N[i] - batchResult->M2; 
        //batchResult->M2 +=  (IsuccN[i] * fg->weights[i] * Dif / Isucc)/ fg->total_weight; 
    }
    batchResult->Mean[0] /= fg->total_weight;
    stdev /= fg->total_weight;
    
    
    batchResult->M2[0] = pow(stdev, 2) + pow(batchResult->Mean[0],2);
    //batchResult->M2 /= pow(fg->total_weight,2);
    
    //batchResult->Isucc = IsuccN[0];
    cerr << endl;
	
    rusage ruse;
    getrusage(RUSAGE_SELF, &ruse);
    cerr << "\033[A\033[2K" << "\033[A\033[2K" << "Total Time: "<<  ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    << "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl << endl<< endl << endl; 
    
	
	cerr << "DIR Result Mean:\t" << batchResult->Mean[0]/ batchResult->I << endl;
	cerr << "DIR Result std:\t" << batchResult->M2[0] << endl << endl << endl<< endl << endl;

    //batchResult->print();
    //exit(0);
	return (batchResult);
}
/*
void SimulatorContinuousBounded::updateSPN(size_t E1_transitionNum,const abstractBinding& b){
	SimulatorRE::updateSPN(E1_transitionNum, b);
	
	Event F;
	abstractBinding bpuit;
    GenerateEvent(F, (N.tr-2),bpuit);
	if(!doubleIS_mode){
		EQ->replace(F);
	}
    
	GenerateEvent(F, (N.tr-1),bpuit);
	if(!doubleIS_mode){
		EQ->replace(F);
	}
	
};
*/
/*double SimulatorContinuousBounded::mu(){
	
	vector<int> vect (muprob.S.begin()->first->size(),0);
	
    N.lumpingFun(N.Marking, vect);
	int stateN = numSolv->findHash(&vect);
    
	if(stateN<0){
		cerr << numSolv->getVect()<< endl << "vect:";
        for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++) {
            cerr << *it<< " , ";
        }
        cerr << endl << "marking:";
        for(size_t i=0; i< N.Msimpletab.size();i++){
            cerr << N.Marking.getNbOfTokens(N.Msimpletab[i]) << " , ";
        };
		cerr << endl << "state not found" << endl;
	}
    
	return(numSolv->getMu(stateN));
}*/
/*
void SimulatorContinuousBounded::getParams(size_t Id,const abstractBinding& b){
	
	N.GetDistParameters(Id,b);
	double origin_rate = N.ParamDistr[0];
    if(Id== N.tr-2){
        origin_rate = lambda - N.Origine_Rate_Sum;
        //cerr << "lambda:\t" << lambda << "\tselfloop:\t" << origin_rate << endl; 
    }    
    N.ParamDistr[0]= ComputeDistr( Id, b,origin_rate);
	N.ParamDistr[1]= origin_rate;
}
*/
