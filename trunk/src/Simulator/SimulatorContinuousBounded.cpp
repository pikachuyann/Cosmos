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

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <limits>


SimulatorContinuousBounded::SimulatorContinuousBounded(int m,double e):SimulatorBoundedRE(m){
    epsilon = e;
    //boost::math::normal norm;
    //Normal_quantile = quantile(norm, 0.5 + 0.99 / 2.0);
}

void SimulatorContinuousBounded::initVectCo(double t){
    
    lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    fg=NULL;
    if (fox_glynn((lambda * t), DBL_EPSILON , 1/DBL_EPSILON ,epsilon, &fg)){
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
    
    int n =-1;
    

    BatchR* batchResult = new BatchR(3*(Nmax+1));
    for(int i=0; i<= fg->right- left; i++)
      batchResult->Mean[3*i] = fg->weights[i+ left- fg->left] /fg->total_weight;

	list<simulationState> statevect((Nmax+1)*BatchSize);
	//delete EQ;
	
    int c =0;
	if(verbose>=1)cerr << "new round:"<< n << "\tremaining trajectories: "<< statevect.size() << endl;
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		N.Origine_Rate_Table = vector<double>(N.tr,0.0);
		N.Rate_Table = vector<double>(N.tr,0.0);
		
		EQ = new EventsQueue(N);
		reset();
        it->maxStep = fg->right - (c/BatchSize);
		//cerr << "new path:\t" << it->maxStep << endl;
        
        c++;
		AutEdge AE;
		
		//Simulator::InitialEventsQueue();
		
		AE = A.GetEnabled_A_Edges( N.Marking);
		
		it->saveState(&N,&A,&AE,&EQ);
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
                
                it->loadState(&N,&A,&AE,&EQ);
                
                
                //cerr << A.Likelihood << endl;
                
                //cerr << "mu:\t" << mu() << " -> ";
                
                if (it->maxStep == fg->right -n) {
                    //We first need to initialise the trajectory
                    Simulator::InitialEventsQueue();
                    it->saveState(&N,&A,&AE,&EQ);
                } else {
                    
                    bool continueb = SimulateOneStep();
                    //cerr << "\t" << mu() << endl;
                    
                    if((!EQ->isEmpty()) && continueb) {
                        it->saveState(&N,&A,&AE,&EQ);
                    } else {
						int i = it->maxStep - left;
                        if (Result.first ) {
                            
                            if (Result.second[0] * (1 - Result.second[0]) != 0) batchResult->IsBernoulli[0] = false;
							
                            {
							
							
							
							batchResult->Isucc+=1;
							batchResult->Mean[3*i+1]+=1;
							batchResult->Mean[3*i+2] += Result.second[0];
							batchResult->M2[3*i+2] += pow(Result.second[0] , 2);
							batchResult->M3[3*i+2] += pow(Result.second[0] , 3);
							batchResult->M4[3*i+2] += pow(Result.second[0] , 4);
							batchResult->Min[3*i+2] = fmin(batchResult->Min[3*i+2],Result.second[0]);
							batchResult->Max[3*i+2] = fmax(batchResult->Max[3*i+2],Result.second[0]);
							
                            }
                            
                        }
                        batchResult->M2[3*i+1]+=1;
                        batchResult->I++;
                        
                        
                        delete EQ;
                        it = statevect.erase(it);
                        
                        it--;
                    }
                }
                
			}
			
		}
        
	}
	
	//rusage ruse;
	//getrusage(RUSAGE_SELF, &ruse);
    //cerr << "\033[A\033[2K" << "\033[A\033[2K"
    //cerr << "Total Time: "<<  ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.
    //<< "\tTotal Memory: " << ruse.ru_maxrss << "ko" << endl << endl<< endl << endl; 
    
	
    //	cerr << "DIR Result Mean:\t" << (lowtotal +uptotal)/2.0 << endl;
    //cerr << "DIR Confidence interval:\t ["<< lowtotal <<";"<< uptotal << "]" << endl << endl << endl<< endl << endl<< endl;

    //batchResult->print();
    //exit(0);
	return (batchResult);
}

