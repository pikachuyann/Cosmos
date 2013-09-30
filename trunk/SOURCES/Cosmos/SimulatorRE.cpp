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
 * file SimulatorRE.cpp created by Benoit Barbot on 09/11/11.                  *
 *******************************************************************************
 */

#include "EventsQueue.hpp"
#include <iostream>
#include <set>
#include <math.h>
#include <float.h>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>
#include "marking.hpp"
//#include "RareEvent.hpp"

#include "SimulatorRE.hpp"

using namespace std;

SimulatorRE::SimulatorRE(bool b) {
	doubleIS_mode=b;
	muprob.inputVect();
}

SimulatorRE::SimulatorRE(){
	SimulatorRE(false);
}

void SimulatorRE::InitialEventsQueue() {
	
	Event E;
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	
	for (vector<_trans>::const_iterator t = N.Transition.begin()
		 ; t != N.Transition.end() ; ++t) {
		for(vector<abstractBinding>::const_iterator bindex = t->bindingList.begin() ;
			bindex != t->bindingList.end() ; ++bindex){
			if (N.IsEnabled(t->Id,*bindex)) {
				GenerateEvent(E, t->Id ,*bindex);
				(*EQ).insert(E);
			}
		}
	}
}
	
void SimulatorRE::returnResultTrue(){
	
	A.UpdateLinForm(N.Marking);
	A.UpdateLhaFuncLast();
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = vector<double>(A.FormulaVal);
    for(size_t i = 0; i< A.FormulaVal.size() ; i++){
        Result.second[i] *= A.Likelihood;
    }
	if(verbose>3)cerr << "---------------\n TRUE \n------\n";
}

void SimulatorRE::returnResultFalse(){
	Result.first = false;
	Result.second =vector<double>(A.FormulaVal.size(),0.0);
	if(verbose>3)cerr << "---------------\n FALSE \n------\n";
}

void SimulatorRE::updateSPN(size_t,const abstractBinding&){
	Event F;
    //check if the current transition is still enabled
	
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	
	// Possibly removing Events corresponding to newly disabled-transitions
	for (size_t it = 0; it < N.tr-1; it++) {
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
	GenerateEvent(F, (N.tr-1), bpuit);
	if(!doubleIS_mode){
		EQ->replace(F);
	}
	
	//In Debug mode check that transition are scheduled iff they are enabled
	for (vector<_trans>::const_iterator t = N.Transition.begin()
		 ; t != N.Transition.end() ; ++t) {
		for(vector<abstractBinding>::const_iterator bindex = t->bindingList.begin() ;
			bindex != t->bindingList.end() ; ++bindex){
			if (N.IsEnabled(t->Id, *bindex) !=
				EQ->isScheduled(t->Id, bindex->id())){
				cerr << "N.IsEnabled(" << t->label << ",";
				bindex->print();
				cerr <<")" << endl;
				if(EQ->isScheduled(t->Id, bindex->id())){
					cerr << "Scheduled and not enabled!"<< endl;
				}else{
					cerr << "Enabled and not scheduled!" << endl;
				}
				assert(N.IsEnabled(t->Id, *bindex) ==
					   EQ->isScheduled(t->Id, bindex->id()));
			}
		}
	}
	
};

void SimulatorRE::updateLikelihood(size_t E1_transitionNum){
    //cerr << "initialised?:\t" << E1_transitionNum << endl;
	if(doubleIS_mode){	
		A.Likelihood = A.Likelihood * 
		(N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) * 
		((N.Rate_Sum-N.Rate_Table[N.tr-1]) / N.Rate_Table[E1_transitionNum]);
	}else{
		A.Likelihood = A.Likelihood * 
		//
		//(N.Origine_Rate_Table[E1_transitionNum] / 1.0) *
		(N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) *
		(N.Rate_Sum / N.Rate_Table[E1_transitionNum]);
	}
}

bool SimulatorRE::transitionSink(size_t i){
    return (i==N.tr-1);
}

/*
 Useless for the moment
void SimulatorRE::GenerateDummyEvent(Event& E, size_t Id) {
    E.transition = Id;
    E.time = 0.0;
    E.priority = N.GetPriority(Id);
    E.weight = 0.0;
}*/
	
void SimulatorRE::GenerateEvent(Event& E,size_t Id,const abstractBinding& b) {
	
    double t = A.CurrentTime;
    if (N.Transition[Id].transType == Timed) {
        getParams(Id, b);
        t += GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr);
		
		N.Rate_Table[Id] = N.ParamDistr[0];
		N.Origine_Rate_Table[Id] = N.ParamDistr[1];
		N.Rate_Sum = N.Rate_Sum + N.ParamDistr[0];
		N.Origine_Rate_Sum = N.Origine_Rate_Sum + N.ParamDistr[1];
		
    }
	double w=0.0;
	if (N.Transition[Id].DistTypeIndex > 2) {
		N.ParamDistr[0]= N.GetWeight(Id);
		w = GenerateTime(EXPONENTIAL, N.ParamDistr);
		//vector<double> wParam(1, N.GetWeight(Id));
		//w = GenerateTime(2, wParam);
    }
	
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = w;
	E.binding = b;
	
}

void SimulatorRE::reset(){
	Simulator::reset();
	N.Origine_Rate_Sum=0;
	N.Rate_Sum=0;
}

void SimulatorRE::getParams(size_t Id,const abstractBinding& b){
	
	N.GetDistParameters(Id,b);
	N.ParamDistr[1]=N.ParamDistr[0];
	N.ParamDistr[0]= ComputeDistr( Id, b, N.ParamDistr[0]);
}


double SimulatorRE::mu(){
	
	vector<int> vect (muprob.S.begin()->first->size(),0);
	
    N.lumpingFun(N.Marking,vect);
    //cerr << "test(";
    int i = muprob.findHash(&vect);
    if(i<0 || verbose>4){
        cerr << "state:(";
        for (size_t j =0; j < vect.size(); j++) {
            cerr << vect[j] << ",";
        }
        cerr << ") ->" << i << endl;
		N.Marking.printHeader(cerr);
		cerr << endl;
		N.Marking.print(cerr);
		cerr << endl;
		N.print_state(vect);
        if(i<0)exit(EXIT_FAILURE);
    }
	if(verbose>3) cerr << ((*muprob.muvect)[i]) << endl;
    //cerr << ")" << endl;
	return((*muprob.muvect)[i]);
}

double SimulatorRE::ComputeDistr(size_t t , const abstractBinding& b, double origin_rate){
	if(verbose>4)cerr << "trans: " << t << " mu origine:";
	double mux = mu();
	if( mux==0.0 || mux==1.0) return(origin_rate);
    
	if(t== N.tr-1){
		if(N.Origine_Rate_Sum >= N.Rate_Sum){
			cerr << "Reduce model does not guarantee variance" << endl;
			exit(EXIT_FAILURE);
			
			return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
		}else{ 
			return 0.0 ;};
	}; 
	if(verbose>4)cerr << "mu target : ";
	double distr;
	N.fire(t,b);
	distr = origin_rate *( mu() / mux);
	N.unfire(t,b);
	if(verbose>4)cerr <<endl;
	return(distr);
}

