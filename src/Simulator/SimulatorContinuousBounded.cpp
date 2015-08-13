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
#include <algorithm>
//#include <boost/math/distributions/normal.hpp>

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <limits>


SimulatorContinuousBounded::SimulatorContinuousBounded(LHA& a,int m,double e,int js):SimulatorBoundedRE(A,m){
    epsilon = e;
	if(js>0){
		jumpsize = js;
		singleIS =false;
	}else{
		jumpsize = -js;
		singleIS = true;
	}
    //boost::math::normal norm;
    //Normal_quantile = quantile(norm, 0.5 + 0.99 / 2.0);
}

void SimulatorContinuousBounded::initVectCo(double t){
    
    lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    fg = unique_ptr<FoxGlynn>(new FoxGlynn((lambda * t), DBL_EPSILON , 1/DBL_EPSILON ,epsilon));
	if (fg->isValid){
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

BatchR SimulatorContinuousBounded::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	
	//cerr << ")" << endl;
    int left = (int)max(numSolv->getMinT(),fg->left);
    int Nmax = (int)ceil(((double)fg->right - left)/jumpsize) ;
    //cerr << "minT:\t" << numSolv->getMinT() << endl;
    cerr << "Number of batch:\t" << Nmax+1 << "\tleft: " << left << "\tright: " << fg->right << "\tjumpsize:" << jumpsize <<  endl;
    //cerr << "left:\t" << left << endl;
    
    int n =-1;
    

    BatchR batchResult(2*(Nmax+1),0);

	
	//Copy and sum Poisson Weight
    for(int i =0; i<= Nmax; i++)
		batchResult.Min[2*i] = 0.0;
	for(int i=left; i<= fg->right; i++){
		int j = (int)ceil((double)( i - left)/jumpsize);
		batchResult.Min[2*j] += fg->weights[i - fg->left];
	}
	for(int i =0; i<= Nmax; i++)
		batchResult.Min[2*i] /= fg->total_weight;
		
	list<simulationState> statevect((Nmax+1)*BatchSize);
	
    int c =0;
	if(verbose>=1)cerr << "new round:"<< n << "\tremaining trajectories: "<< statevect.size() << endl;
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		N.Origine_Rate_Table = vector<double>(N.tr,0.0);
		N.Rate_Table = vector<double>(N.tr,0.0);
		
		bool continueb = false;
		//we try to find a trajectory reaching the precondition.
		while(!continueb){
			//we build a new trajectory from the initial state.
			continueb =true;
			EQ = new EventsQueue(N);
			reset();
			//We simulate until either the condition is satisfied or the trajectory reach a deadend.
			while(!N.precondition(N.Marking) && continueb){
				continueb = SimulateOneStep();
			}
		}
		
		if (singleIS) {
			it->maxStep = fg->right;
		}else{
			it->maxStep = (int)fmin(fg->right , left + (Nmax - (c/BatchSize))*jumpsize);
		}
        
		//cerr << "new path:\t" << it->maxStep << endl;
		
		c++;
		
		it->saveState(&N,&A,&EQ);
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
                it->loadState(&N,&A,&EQ);
                
                
                //cerr << A.Likelihood << endl;
                
                //cerr << "mu:\t" << mu() << " -> ";
                
                if (it->maxStep == fg->right -n) {
                    //We first need to initialise the trajectory
                    Simulator::InitialEventsQueue();
					if(verbose>=2)
						//cerr << "new Path: " << it->maxStep << "\tmuinit: " << mu() << endl;
                    it->saveState(&N,&A,&EQ);
                } else {
                    
                    bool continueb = SimulateOneStep();
                    //cerr << "\t" << mu() << endl;
                    
                    if((!EQ->isEmpty()) && continueb) {
                        it->saveState(&N,&A,&EQ);
                    } else {
						int i = (int)ceil((double)(it->maxStep- left)/jumpsize) ;
						int i2 =(int)fmax(0.0,ceil((double)(n - left)/jumpsize));
						//cerr << "Successfull trajectory: "<< it->maxStep << " -> " << i << endl;
                        if (Result.accept ) {
                            
                            if (Result.quantR[0] * (1 - Result.quantR[0]) != 0) batchResult.IsBernoulli[0] = false;
							
							batchResult.Isucc+=1;
							if(singleIS)for(int j = i2; j<= Nmax; j++){
								batchResult.Mean[2*j]+=1;
								batchResult.Mean[2*j+1] += Result.quantR[0];
								batchResult.M2[2*j+1] += pow(Result.quantR[0] , 2);
								batchResult.M3[2*j+1] += pow(Result.quantR[0] , 3);
								batchResult.M4[2*j+1] += pow(Result.quantR[0] , 4);
								batchResult.Min[2*j+1] = fmin(batchResult.Min[2*j+1],Result.quantR[0]);
								batchResult.Max[2*j+1] = fmax(batchResult.Max[2*j+1],Result.quantR[0]);
                            } else {
								batchResult.Mean[2*i]+=1;
								batchResult.Mean[2*i+1] += Result.quantR[0];
								batchResult.M2[2*i+1] += pow(Result.quantR[0] , 2);
								batchResult.M3[2*i+1] += pow(Result.quantR[0] , 3);
								batchResult.M4[2*i+1] += pow(Result.quantR[0] , 4);
								batchResult.Min[2*i+1] = fmin(batchResult.Min[2*i+1],Result.quantR[0]);
								batchResult.Max[2*i+1] = fmax(batchResult.Max[2*i+1],Result.quantR[0]);
							}
                            
                        }
						if(singleIS){for(int j = 0; j<= Nmax; j++)batchResult.M2[2*j]+=1;}
						else batchResult.M2[2*i]+=1;
                        batchResult.I++;
                        
                        
                        delete EQ;
                        it = statevect.erase(it);
                        
                        it--;
                    }
                }
                
			}
			
		}
        
	}

	return (batchResult);
}

