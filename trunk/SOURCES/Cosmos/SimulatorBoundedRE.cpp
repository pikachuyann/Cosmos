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
 * file SimulatorBoundedRE.cpp created by Benoit Barbot on 06/12/11.           *
 *******************************************************************************
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
	
	BatchR* batchResult = new BatchR(1);
	
	list<simulationState> statevect(BatchSize);
	//delete EQ;
	
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		EQ = new EventsQueue(N);
		reset();
		
		AutEdge AE;
		A.CurrentLocation = A.EnabledInitLocation(N.Marking);
		A.CurrentTime = 0;
		
		
		Simulator::InitialEventsQueue();
		
		AE = A.GetEnabled_A_Edges( N.Marking);
        
		(*it).saveState(&N,&A,&AE,&EQ, &A.CurrentTime);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
        if(verbose==1){
            cerr << "new round" << endl;
            cerr << numSolv->getVect() << endl;
        }
		
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
			AutEdge AE;
			
            
			(*it).loadState(&N,&A,&AE,&EQ, &A.CurrentTime);
            
			//cerr << A.Likelihood << endl;		
			//cerr << "mu:\t" << mu() << " ->\t";
			bool continueb = SimulateOneStep();
			//cerr << mu() << endl;
            
			if((!EQ->isEmpty()) && continueb) {
				(*it).saveState(&N,&A,&AE,&EQ, &A.CurrentTime);
			} else {
				batchResult->addSim(&Result);
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
	for(size_t i=0; i< N.Msimpletab.size();i++){
		vect[i] = N.Marking.getNbOfTokens(N.Msimpletab[i]);
	};
	
    N.lumpingFun(&vect);
	int stateN = numSolv->findHash(&vect);
	 
	if(stateN<0){
		cerr << numSolv->getVect()<< endl<< "statevect(";
        for(size_t i =0 ; i<vect.size() ; i++)cerr << vect[i]<< ",";
		cerr << ")" << endl<<"state not found" << endl;
	}
		
	return(numSolv->getMu(stateN));
}

double SimulatorBoundedRE::ComputeDistr(const int t ,const abstractBinding& b, double origin_rate ){
	
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
	N.fire(t,b);
	numSolv->stepVect();
	distr = origin_rate *( mu() / mux);
	//cerr << " distr: "<< distr << " ";
	
	numSolv->previousVect();
	N.unfire(t,b);
	return(distr);
}
