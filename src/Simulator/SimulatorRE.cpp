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

SPN_RE::SPN_RE(int& v,bool doubleIS):SPN_orig(v),doubleIS_mode(doubleIS){
    rareEventEnabled=false;
    Rate_Sum = 0;
    Origine_Rate_Sum = 0;
    Rate_Table = vector<double>(tr,0.0);
    Origine_Rate_Table = vector<double>(tr,0.0);
}

void SPN_RE::initialize( stateSpace *muprob){
    this->muprob=muprob;
}

SimulatorRE::SimulatorRE(SPN_orig& N,LHA_orig& A):Simulator(N,A) {
    //static_cast<SPN_RE&>(N).initialize(EQ, this, muprob);
}

void SimulatorRE::initVect(){
    muprob = new stateSpace();
	muprob->inputVect();
    static_cast<SPN_RE&>(N).initialize(muprob);
}

void SPN_RE::InitialEventsQueue(EventsQueue &EQ,timeGen &TG) {
	Rate_Sum = 0;
	Origine_Rate_Sum = 0;
	SPN_orig::InitialEventsQueue(EQ,TG);
}

void SimulatorRE::returnResultTrue(){
	A.getFinalValues(N.Marking,Result.quantR,Result.qualR);
	Result.accept = true;
    for(size_t i = 0; i< A.FormulaVal.size() ; i++)Result.quantR[i] *= A.Likelihood;
	if(verbose>3)cerr << "---------------\n TRUE: Likelyhood: "<< A.Likelihood <<" \n------\n";
}

void SPN_RE::update(double ctime,size_t t, const abstractBinding& b,EventsQueue &EQ,timeGen &TG){
	//If rareevent not require yet call the parent function
	
	if(!rareEventEnabled){
		if(precondition(Marking)){
			rareEventEnabled = true;
			//A.Likelihood = 1.0;
		}else{
			update(ctime, t, b,EQ, TG);
		return;
		}
	}
	
	Event F;
    
	Rate_Sum = 0;
	Origine_Rate_Sum = 0;
	
	//Run over all transition
	for (const auto &tr : Transition) {
        if(tr.Id != SPN::tr - 1){
			for(const auto &bindex : tr.bindingList ){
				if(IsEnabled(tr.Id, bindex)){
					if (EQ.isScheduled(tr.Id, bindex.id())) {
						GenerateEvent(ctime,F, tr.Id ,bindex, TG );
						EQ.replace(F);
					} else {
						GenerateEvent(ctime,F, tr.Id ,bindex, TG );
						EQ.insert(F);
					}
				}else{
					if(EQ.isScheduled(tr.Id, bindex.id()))
						EQ.remove(tr.Id,bindex.id());
				}
			}
		}
	}
	
	abstractBinding bpuit;
	GenerateEvent(ctime,F, (tr-1), bpuit,TG);
	if(!doubleIS_mode){
		EQ.replace(F);
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
    let NRE = static_cast<SPN_RE&>(N);
    
    /*cerr << "initialised?:\t" << E1_transitionNum << "\t" << A.Likelihood << endl;
    cerr << NRE.Rate_Sum << "\t" << NRE.Origine_Rate_Sum << "\t[";
    for(let cv:NRE.Rate_Table)cerr << cv << ", ";
    cerr << "]\t[";
    for(let cv:NRE.Origine_Rate_Table)cerr << cv << ", ";
    cerr << "]" << endl;*/
    
	if(NRE.doubleIS_mode){
		A.Likelihood = A.Likelihood *
		(NRE.Origine_Rate_Table[E1_transitionNum] / NRE.Origine_Rate_Sum) *
		((NRE.Rate_Sum-NRE.Rate_Table[N.tr-1]) / NRE.Rate_Table[E1_transitionNum]);
	}else{
		A.Likelihood = A.Likelihood *
		//
		//(N.Origine_Rate_Table[E1_transitionNum] / 1.0) *
		(NRE.Origine_Rate_Table[E1_transitionNum] / NRE.Origine_Rate_Sum) *
		(NRE.Rate_Sum / NRE.Rate_Table[E1_transitionNum]);
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

void SPN_RE::GenerateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b, timeGen &TG){
	
    double t = ctime;
    if (Transition[Id].DistTypeIndex != IMMEDIATE) {
        getParams(Id, b);
        t += TG.GenerateTime(Transition[Id].DistTypeIndex, ParamDistr, customDistr);
		
		Rate_Table[Id] = ParamDistr[0];
		Origine_Rate_Table[Id] = ParamDistr[1];
		Rate_Sum = Rate_Sum + ParamDistr[0];
		Origine_Rate_Sum = Origine_Rate_Sum + ParamDistr[1];
		
    }
	double w=0.0;
	if (Transition[Id].DistTypeIndex > 2) {
		ParamDistr[0]= GetWeight(Id,b);
		w = TG.GenerateTime(EXPONENTIAL, ParamDistr, customDistr);
		//vector<double> wParam(1, N.GetWeight(Id));
		//w = GenerateTime(2, wParam);
    }
	
    E.transition = Id;
    E.time = t;
    E.priority = GetPriority(Id,b);
    E.weight = w;
	E.binding = b;
	
}

void SimulatorRE::reset(){
    A.Likelihood=1.0;
    N.reset();
    A.reset(N.Marking);
    EQ->reset();
}

/**
 * Simulate a whole trajectory in the system. Result is store in SimOutput
 */
void SimulatorRE::SimulateSinglePath() {
    auto &NRE = static_cast<SPN_RE&>(N);
	NRE.rareEventEnabled = NRE.precondition(N.Marking);
    reset();
    N.InitialEventsQueue(*EQ,*this);
	
	if(logtrace.is_open())logtrace << "New Path"<< endl;
    
	bool continueb = true;
	while ((!EQ->isEmpty()) && continueb ) {
        //cerr << "continue path"<< endl;
		if(logtrace.is_open()){
			logtrace << A.CurrentTime << "\t";
			N.Marking.print(logtrace,0.0);
			A.printState(logtrace);
			logtrace << endl;
		}
		if(verbose>3){
			//Print marking and location of the automata
			//Usefull to track a simulation
			N.Marking.printHeader(cerr);
			A.printHeader(cerr);
			cerr << endl;
			N.Marking.print(cerr,0.0);
			A.printState(cerr);
            cerr << "\t" << A.Likelihood;
			cerr << endl;
			if(verbose>4)EQ->view(N.Transition);
			if(verbose==6)interactiveSimulation();
		}
		
		continueb = SimulateOneStep();
		if(!NRE.rareEventEnabled)NRE.rareEventEnabled = NRE.precondition(N.Marking);
	}
    //cerr << "finish path"<< endl;
}


void SPN_RE::getParams(size_t Id,const abstractBinding& b){
	//If rareevent not require yet call the parent function
	if(!rareEventEnabled){
        GetDistParameters(Id,b);
		return;
	}
	GetDistParameters(Id,b);
	ParamDistr[1]= ParamDistr[0];
	ParamDistr[0]= ComputeDistr( Id, b, ParamDistr[0]);
    //N.ParamDistr[0]= N.ParamDistr[1]; /////////////////////////////////////////////////to remove
}

double SPN_RE::mu(){
	
	vector<int> vect (muprob->S.begin()->first->size(),0);
	
    lumpingFun(Marking,vect);
    //cerr << "test(";
    int i = muprob->findHash(&vect);
    if(i<0 || verbose>4){
        cerr << "state:(";
        for (size_t j =0; j < vect.size(); j++) {
            cerr << vect[j] << ",";
        }
        cerr << ") ->" << i << endl;
		Marking.printHeader(cerr);
		cerr << endl;
		Marking.print(cerr,0.0);
		cerr << endl;
		print_state(vect);
        if(i<0)exit(EXIT_FAILURE);
    }
	if(verbose>3)cerr << "muValue: " << muprob->getMu(i) << endl;
	return muprob->getMu(i);
}

double SPN_RE::ComputeDistr(size_t t , const abstractBinding& b, double origin_rate){
	if(verbose>4)cerr << "trans: " << Transition[t].label << " mu origine:";
	double mux = mu();
	if( mux==0.0 || mux==1.0) return(origin_rate);
    
	if(t== tr-1){
		if(Origine_Rate_Sum >= Rate_Sum){
			return( Origine_Rate_Sum - Rate_Sum  );
		}else{
			if(verbose>3 && (Origine_Rate_Sum < 0.99*Rate_Sum)){
				cerr << "Reduce model does not guarantee variance" << endl;
				cerr << "Initial sum of rate: " << Origine_Rate_Sum << " Reduce one: " << Rate_Sum << " difference: " << Origine_Rate_Sum - Rate_Sum << endl ;
				//exit(EXIT_FAILURE);
			}
			
			return 0.0 ;};
	};
	if(verbose>4)cerr << "mu target : ";
	double distr;
	fire(t,b,0.0);
	distr = origin_rate *( mu() / mux);
	unfire(t,b);
	if(verbose>4)cerr <<endl;
	return(distr);
}

