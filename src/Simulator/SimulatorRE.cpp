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
#include <time.h>
#include "marking.hpp"
//#include "RareEvent.hpp"

#include "SimulatorRE.hpp"

using namespace std;

SimulatorRE::SimulatorRE(bool b) {
	rareEventEnabled = false;
	doubleIS_mode=b;
}

SimulatorRE::SimulatorRE(){
	SimulatorRE(false);
}

void SimulatorRE::initVect(){
	muprob.inputVect();
}

void SimulatorRE::InitialEventsQueue() {
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	Simulator::InitialEventsQueue();
	
}

void SimulatorRE::returnResultTrue(){
	A.getFinalValues(N.Marking,Result.second);
	Result.first = true;
    for(size_t i = 0; i< A.FormulaVal.size() ; i++)Result.second[i] *= A.Likelihood;
	if(verbose>3)cerr << "---------------\n TRUE \n------\n";
}

void SimulatorRE::updateSPN(size_t t, const abstractBinding& b){
	//If rareevent not require yet call the parent function
	
	if(!rareEventEnabled){
		if(N.precondition(N.Marking)){
			rareEventEnabled = true;
			A.Likelihood = 1.0;
		}else{
			Simulator::updateSPN(t, b);
		return;
		}
	}
	
	Event F;
    
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	
	//Run over all transition
	for (const auto &tr : N.Transition) {
		if(tr.Id != N.tr-1){
			for(const auto &bindex : tr.bindingList ){
				if(N.IsEnabled(tr.Id, bindex)){
					if (EQ->isScheduled(tr.Id, bindex.id())) {
						GenerateEvent(F, tr.Id ,bindex );
						EQ->replace(F);
					} else {
						GenerateEvent(F, tr.Id ,bindex );
						EQ->insert(F);
					}
				}else{
					if(EQ->isScheduled(tr.Id, bindex.id()))
						EQ->remove(tr.Id,bindex.id());
				}
			}
		}
	}
	
	abstractBinding bpuit;
	GenerateEvent(F, (N.tr-1), bpuit);
	if(!doubleIS_mode){
		EQ->replace(F);
	}
	
	/*
	 //In Debug mode check that transition are scheduled iff they are enabled
	for (const auto &tr : N.Transition) {
		for(const auto &bindex : tr.bindingList){
			if (N.IsEnabled(tr.Id, bindex) !=
				EQ->isScheduled(tr.Id, bindex.id())){
				cerr << "N.IsEnabled(" << tr.label << ",";
				bindex.print();
				cerr <<")" << endl;
				if(EQ->isScheduled(tr.Id, bindex.id())){
					cerr << "Scheduled and not enabled!"<< endl;
				}else{
					cerr << "Enabled and not scheduled!" << endl;
				}
				assert(N.IsEnabled(tr.Id, bindex) ==
					   EQ->isScheduled(tr.Id, bindex.id()));
			}
		}
	}
	 */
	 
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
		N.ParamDistr[0]= N.GetWeight(Id,b);
		w = GenerateTime(EXPONENTIAL, N.ParamDistr);
		//vector<double> wParam(1, N.GetWeight(Id));
		//w = GenerateTime(2, wParam);
    }
	
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id,b);
    E.weight = w;
	E.binding = b;
	
}

void SimulatorRE::reset(){
	Simulator::reset();
	N.Origine_Rate_Sum=0;
	N.Rate_Sum=0;
}

/**
 * Simulate a whole trajectory in the system. Result is store in SimOutput
 */
void SimulatorRE::SimulateSinglePath() {
	rareEventEnabled = N.precondition(N.Marking);
	InitialEventsQueue();
	
	if(logtrace.is_open())logtrace << "New Path"<< endl;
    
	bool continueb = true;
	while ((!(*EQ).isEmpty()) && continueb ) {
        //cerr << "continue path"<< endl;
		if(logtrace.is_open()){
			logtrace << A.CurrentTime << "\t";
			N.Marking.print(logtrace);
			A.printState(logtrace);
			logtrace << endl;
		}
		if(verbose>3){
			//Print marking and location of the automata
			//Usefull to track a simulation
			N.Marking.printHeader(cerr);
			A.printHeader(cerr);
			cerr << endl;
			N.Marking.print(cerr);
			A.printState(cerr);
			cerr << endl;
			if(verbose>4)EQ->view(N.Transition);
			if(verbose==6)interactiveSimulation();
		}
		
		continueb = SimulateOneStep();
		if(!rareEventEnabled)rareEventEnabled = N.precondition(N.Marking);
	}
    //cerr << "finish path"<< endl;
}


void SimulatorRE::getParams(size_t Id,const abstractBinding& b){
	//If rareevent not require yet call the parent function
	if(!rareEventEnabled){
		Simulator::getParams(Id, b);
		return;
	}
	N.GetDistParameters(Id,b);
	N.ParamDistr[1]= N.ParamDistr[0];
	N.ParamDistr[0]= ComputeDistr( Id, b, N.ParamDistr[0]);
    //N.ParamDistr[0]= N.ParamDistr[1]; /////////////////////////////////////////////////to remove
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
	if(verbose>3)cerr << "muValue: " << ((*muprob.muvect)[i]) << endl;
	return((*muprob.muvect)[i]);
}

double SimulatorRE::ComputeDistr(size_t t , const abstractBinding& b, double origin_rate){
	if(verbose>4)cerr << "trans: " << N.Transition[t].label << " mu origine:";
	double mux = mu();
	if( mux==0.0 || mux==1.0) return(origin_rate);
    
	if(t== N.tr-1){
		if(N.Origine_Rate_Sum >= N.Rate_Sum){
			return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
		}else{
			if(verbose>3 && (N.Origine_Rate_Sum < 0.99*N.Rate_Sum)){
				cerr << "Reduce model does not guarantee variance" << endl;
				cerr << "Initial sum of rate: " << N.Origine_Rate_Sum << " Reduce one: " << N.Rate_Sum << " difference: " << N.Origine_Rate_Sum - N.Rate_Sum << endl ;
				//exit(EXIT_FAILURE);
			}
			
			return 0.0 ;};
	};
	if(verbose>4)cerr << "mu target : ";
	double distr;
	N.fire(t,b,0.0);
	distr = origin_rate *( mu() / mux);
	N.unfire(t,b);
	if(verbose>4)cerr <<endl;
	return(distr);
}

