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
	lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    numSolv->initVect(T);
}


BatchR SimulatorBoundedRE::RunBatch(){
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
	
	BatchR batchResult(1);
	
	list<simulationState> statevect(BatchSize);
	//delete EQ;
	
	if(verbose>=1){
		cerr << "Initial round:";
		numSolv->printState();
		cerr << "\tremaining trajectories: "<< statevect.size() << "\tInit Prob:";
		cerr << numSolv->getVect()[0] << endl;
	}
	for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
		N.Origine_Rate_Table = vector<double>(N.tr,0.0);
		N.Rate_Table = vector<double>(N.tr,0.0);
		EQ = new EventsQueue(N);
		reset();
		
		Simulator::InitialEventsQueue();
		
		//AE = A.GetEnabled_A_Edges( N.Marking);
        
		it->saveState(&N,&A,&EQ);
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
        if(verbose>=1){
            cerr << "new round:";
			numSolv->printState();
			cerr << "\tremaining trajectories: "<< statevect.size() << "\tInit Prob:";
            cerr << numSolv->getVect()[0] << endl;
        }
		
		for (list<simulationState>::iterator it= statevect.begin(); it != statevect.end() ; it++) {
            
			it->loadState(&N,&A,&EQ);
            
			//cerr << A.Likelihood << endl;
			//cerr << "mu:\t" << mu() << " ->\t";
			bool continueb = SimulateOneStep();
			//cerr << mu() << endl;
			if(numSolv->getVect().size() <= 1){
				continueb=false;
				Result.first=false;
			}
			
			if((!EQ->isEmpty()) && continueb) {
				it->saveState(&N,&A,&EQ);
			} else {
				batchResult.addSim(Result);
				delete EQ;
				it = statevect.erase(it);
				it--;
				
				//log the result
				if (Result.first && logResult){
					for(size_t i=0; i<Result.second.size();i++){
						if (i>0)logvalue << "\t";
						logvalue << Result.second[i];
					}
					logvalue << endl;
				}
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
	
	vector<int> vect (numSolv->S.begin()->first->size(),0);
	
    N.lumpingFun(N.Marking,vect);
	int stateN = numSolv->findHash(&vect);
	
	if(stateN<0){
		//cerr << numSolv->getVect()<< endl
		cerr << "statevect(";
        for(size_t i =0 ; i<vect.size() ; i++)cerr << vect[i]<< ",";
		cerr << ")" << endl<<"state not found" << endl;
		N.print_state(vect);
		return 0.0;
		//exit(EXIT_FAILURE);
	}
	
	return(numSolv->getMu(stateN));
}

void SimulatorBoundedRE::updateSPN(size_t,const abstractBinding&){
	Event F;
    //check if the current transition is still enabled
	
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	
	//Run over all transition
	for (size_t it = 0; it < N.tr-2; it++) {
		for(vector<abstractBinding>::const_iterator bindex = N.Transition[it].bindingList.begin() ;
			bindex != N.Transition[it].bindingList.end() ; ++bindex){
			if(N.IsEnabled(it, *bindex)){
				if (EQ->isScheduled(it, bindex->id())) {
					GenerateEvent(F, it ,*bindex );
					EQ->replace(F);
				} else {
					GenerateEvent(F, it ,*bindex );
					EQ->insert(F);
				}
			}else{
				if(EQ->isScheduled(it, bindex->id()))
					EQ->remove(it,bindex->id());
			}
		}
	}
	
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

void SimulatorBoundedRE::getParams(size_t Id,const abstractBinding& b){
	
	N.GetDistParameters(Id,b);
	double origin_rate = N.ParamDistr[0];
    if(Id== N.tr-2){
        origin_rate = lambda - N.Origine_Rate_Sum;
        //cerr << "lambda:\t" << lambda << "\tselfloop:\t" << origin_rate << endl;
    }
    N.ParamDistr[0]= ComputeDistr( Id, b,origin_rate);
	N.ParamDistr[1]= origin_rate;
}


double SimulatorBoundedRE::ComputeDistr(size_t t ,const abstractBinding& b, double origin_rate ){
	
	//cerr << endl<< "mux" << endl;
	double mux = mu();
    
	if(t== N.tr-1){
		if (mux==0.0)return 1E200;
		
		if(verbose>3){
			N.Marking.printHeader(cerr);cerr << endl;
			N.Marking.print(cerr);cerr << endl;
			vector<int> vect (numSolv->S.begin()->first->size(),0);
			N.lumpingFun(N.Marking,vect);
			N.print_state(vect);
		}
		
		if(N.Origine_Rate_Sum >= N.Rate_Sum){
			if(verbose>3 )cerr << "trans:sink distr: "<< N.Origine_Rate_Sum - N.Rate_Sum << " origine_rate:" << N.Origine_Rate_Sum <<" Rate: " << N.Rate_Sum << endl;
			//cerr << "strange !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
		}else{
			if(verbose>3 && (N.Origine_Rate_Sum < 0.99*N.Rate_Sum)){
				cerr << "Reduce model does not guarantee variance" << endl;
				cerr << "Initial sum of rate: " << N.Origine_Rate_Sum << " Reduce one: " << N.Rate_Sum << " difference: " << N.Origine_Rate_Sum - N.Rate_Sum << endl ;
				//exit(EXIT_FAILURE);
			}
			//cerr << "trans:sink distr: 0 " << endl;
			return 0.0 ;};
	};
	if( mux==0.0 || mux==1.0) return(origin_rate);
	
	double distr;
	N.fire(t,b);
	numSolv->stepVect();
	distr = origin_rate *( mu() / mux);
	if(verbose>3 )cerr << "trans: " << N.Transition[t].label << "\tdistr: "<< distr << "\torigin Rate: "<< origin_rate << "\tmu: " << mu()<< "\tmu prec: " << mux << endl;
	
	numSolv->previousVect();
	N.unfire(t,b);
	return(distr);
}
