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

template<class S,class DEDS>
SimulatorBoundedREBase<S,DEDS>::SimulatorBoundedREBase(DEDS& N,LHA_orig& A,int m):SimulatorREBase<S,DEDS>(N,A){
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
    this->muprob = numSolv;
    delete this->EQ;
	this->N.initialize( this->muprob);
	//numSolv->initVect(T);
}

template<class S,class DEDS>
void SimulatorBoundedREBase<S,DEDS>::initVect(int T){
	lambda = numSolv->uniformizeMatrix();
    cerr << "lambda:" << lambda<< endl;
    numSolv->initVect(T);
}

template<class S,class DEDS>
BatchR SimulatorBoundedREBase<S,DEDS>::RunBatch(){
   
	//cerr << "test(";
	numSolv->reset();
	//cerr << ")" << endl;
	
	BatchR batchResult(1,0);
	
	list<simulationState<EventsQueue> > statevect(this->BatchSize);
	//delete EQ;
	
	if(this->verbose>=1){
		cerr << "Initial round:";
		numSolv->printState();
		cerr << "\tremaining trajectories: "<< statevect.size() << "\tInit Prob:";
		cerr << numSolv->getVect()[0] << endl;
	}
	for (auto it= statevect.begin(); it != statevect.end() ; it++) {
		this->N.Origine_Rate_Table = vector<double>(this->N.tr,0.0);
		this->N.Rate_Table = vector<double>(this->N.tr,0.0);
		this->EQ = new EventsQueue(this->N);
		this->reset();
		
        this->N.SPN_orig::initialEventsQueue(*(this->EQ),*this);

		//AE = A.GetEnabled_A_Edges( N.Marking);
        
		it->saveState(&(this->N),&(this->A),&(this->EQ));
	}
	
	//cout << "new batch" << endl;
	while (!statevect.empty()) {
		numSolv->stepVect();
        if(this->verbose>=1){
            cerr << "new round:";
			numSolv->printState();
			cerr << "\tremaining trajectories: "<< statevect.size() << "\tInit Prob:";
            cerr << numSolv->getVect()[0] << endl;
        }
		
		for (auto it= statevect.begin(); it != statevect.end() ; it++) {
            
			it->loadState(&(this->N),&(this->A),&(this->EQ));
            
            
			//cerr << A.Likelihood << endl;
			//cerr << "mu:\t" << mu() << " ->\t";
			bool continueb = this->SimulateOneStep();
			//cerr << mu() << endl;
			if(numSolv->getVect().size() <= 1){
				continueb=false;
				this->Result.accept=false;
			}
			
			if((!this->EQ->isEmpty()) && continueb) {
                it->saveState(&(this->N),&(this->A),&(this->EQ));
			} else {
				batchResult.addSim(this->Result);
				delete this->EQ;
				it = statevect.erase(it);
				it--;
				
				//log the result
				if (this->Result.accept && this->logResult){
					for(size_t i=0; i<this->Result.quantR.size();i++){
						if (i>0)this->logvalue << "\t";
						this->logvalue << this->Result.quantR[i];
					}
					this->logvalue << endl;
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


SPN_BoundedRE::SPN_BoundedRE(int& v,bool doubleIS):SPN_RE(v,doubleIS){
    
}

double SPN_BoundedRE::mu(){
	
	vector<int> vect (muprob->S.begin()->first->size(),0);
	
    lumpingFun(Marking,vect);
	int stateN = muprob->findHash(&vect);
	
	if(stateN<0){
		//cerr << numSolv->getVect()<< endl
		cerr << "statevect(";
        for(size_t i =0 ; i<vect.size() ; i++)cerr << vect[i]<< ",";
		cerr << ")" << endl<<"state not found" << endl;
		print_state(vect);
		return 0.0;
		//exit(EXIT_FAILURE);
	}
	
	return(muprob->getMu(stateN));
}

void SPN_BoundedRE::update(double ctime,size_t,const abstractBinding&,EventsQueue &EQ, timeGen &TG){
	Event F;
    //check if the current transition is still enabled
	
	Rate_Sum = 0;
	Origine_Rate_Sum = 0;
	
	//Run over all transition
    for (size_t it = 0; it < SPN::tr-2; it++) {
		for(vector<abstractBinding>::const_iterator bindex = Transition[it].bindingList.begin() ;
			bindex != Transition[it].bindingList.end() ; ++bindex){
			if(IsEnabled(it, *bindex)){
				if (EQ.isScheduled(it, bindex->id())) {
					generateEvent(ctime,F, it ,*bindex, TG,static_cast<SPN_RE&>(*this) );
					EQ.replace(F);
				} else {
					generateEvent(ctime,F, it ,*bindex, TG,static_cast<SPN_RE&>(*this) );
					EQ.insert(F);
				}
			}else{
				if(EQ.isScheduled(it, bindex->id()))
					EQ.remove(it,bindex->id());
			}
		}
	}
	
	abstractBinding bpuit;
    generateEvent(ctime,F, (SPN::tr-2),bpuit, TG,static_cast<SPN_RE&>(*this));
	if(!doubleIS_mode){
		EQ.replace(F);
	}
	
    generateEvent(ctime,F, (SPN::tr-1),bpuit, TG,static_cast<SPN_RE&>(*this));
	if(!doubleIS_mode){
		EQ.replace(F);
	}
	
};

void SPN_BoundedRE::getParams(size_t Id,const abstractBinding& b){
	
	GetDistParameters(Id,b);
	double origin_rate = ParamDistr[0];
    if(Id== SPN::tr-2){
        origin_rate = muprob->maxRate - Origine_Rate_Sum;
        //cerr << "lambda:\t" << lambda << "\tselfloop:\t" << origin_rate << endl;
    }
    ParamDistr[0]= ComputeDistr( Id, b,origin_rate);
	ParamDistr[1]= origin_rate;
}


double SPN_BoundedRE::ComputeDistr(size_t t ,const abstractBinding& b, double origin_rate ){
	
	//cerr << endl<< "mux" << endl;
	double mux = mu();
    
    if(t== SPN::tr-1){
		if (mux==0.0)return 1E200;
		
		if(verbose>3){
			Marking.printHeader(cerr);cerr << endl;
			Marking.print(cerr,0.0);cerr << endl;
			vector<int> vect (muprob->S.begin()->first->size(),0);
			lumpingFun(Marking,vect);
			print_state(vect);
		}
		
		if(Origine_Rate_Sum >= Rate_Sum){
			if(verbose>3 )cerr << "trans:sink distr: "<< Origine_Rate_Sum - Rate_Sum << " origine_rate:" << Origine_Rate_Sum <<" Rate: " << Rate_Sum << endl;
			//cerr << "strange !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			return( (Origine_Rate_Sum - Rate_Sum)  );
		}else{
			if(verbose>3 && (Origine_Rate_Sum < 0.99*Rate_Sum)){
				cerr << "Reduce model does not guarantee variance" << endl;
				cerr << "Initial sum of rate: " << Origine_Rate_Sum << " Reduce one: " << Rate_Sum << " difference: " << Origine_Rate_Sum - Rate_Sum << endl ;
				//exit(EXIT_FAILURE);
			}
			//cerr << "trans:sink distr: 0 " << endl;
			return 0.0 ;};
	};
	if( mux==0.0 || mux==1.0) return(origin_rate);
	
	double distr;
	fire(t,b,0.0);
	static_cast<numericalSolver*>(muprob)->stepVect();
	distr = origin_rate *( mu() / mux);
	if(verbose>3 )cerr << "trans: " << Transition[t].label << "\tdistr: "<< distr << "\torigin Rate: "<< origin_rate << "\tmu: " << mu()<< "\tmu prec: " << mux << endl;
	
	static_cast<numericalSolver*>(muprob)->previousVect();
	unfire(t,b);
	return(distr);
}

template class SimulatorBoundedREBase<SimulatorBoundedRE<SPN_BoundedRE>,SPN_BoundedRE>;
template class SimulatorBoundedRE<SPN_BoundedRE>;

#include "SimulatorContinuousBounded.hpp"
template class SimulatorBoundedREBase<SimulatorContinuousBounded<SPN_BoundedRE>,SPN_BoundedRE>;



