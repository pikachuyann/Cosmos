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
	
	Initialized = true;
	
	
	set<int, less <int> > ent;
	ent = N.enabledTrans();
	set<int>::iterator it;
	Event E;
	N.Rate_Sum = 0;
	N.Origine_Rate_Sum = 0;
	for (it = ent.begin(); it != ent.end(); it++) {
		GenerateEvent(E, (*it));
		(*EQ).insert(E);
		
	}
}

void SimulatorRE::returnResultTrue(vector<int>& marking, double D){
	A.UpdateLinForm(marking);
	A.UpdateLhaFunc(A.CurrentTime, D);
	A.UpdateLhaFuncLast(A.CurrentTime, D);
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = vector<double>(A.FormulaVal);
    for(size_t i = 0; i< A.FormulaVal.size() ; i++){
        Result.second[i] *= A.Likelihood;
    }
}

void SimulatorRE::returnResultFalse(){
	Result.first = false;
	Result.second[0] =0.0;
}

void SimulatorRE::updateSPN(int E1_transitionNum){
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
	for(size_t i=0; i< (*EQ).getSize(); i++){
		Enabled_trans[i] = (*EQ).InPosition(i).transition; 
	};
	
	for (vector<int>::iterator it = Enabled_trans.begin(); it != Enabled_trans.end(); it++) {
		if(*it != N.tr-1){
			if(N.IsEnabled(*it)){
				GenerateEvent(F, (*it));
				(*EQ).replace(F, (*EQ).TransTabValue(*it));
			}else {
				(*EQ).remove((*EQ).TransTabValue(*it));
			}
		}; 
	};
	
	GenerateEvent(F, (N.tr-1));
	if(!doubleIS_mode){
		(*EQ).replace(F, (*EQ).TransTabValue(N.tr-1));
	}
	
};

void SimulatorRE::updateLikelihood(int E1_transitionNum){
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

bool SimulatorRE::transitionSink(int i){
    return (i==N.tr-1);
}

void SimulatorRE::GenerateDummyEvent(Event& E, int Id) {
    E.transition = Id;
    E.time = 0.0;
    E.priority = N.GetPriority(Id);
    E.weight = 0.0;
}
	
void SimulatorRE::GenerateEvent(Event& E, int Id) {
	
    double t = simTime;
    if (N.Transition[Id].transType == Timed) {
        getParams(Id);
        t += GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr);
		
		N.Rate_Table[Id] = N.ParamDistr[0];
		N.Origine_Rate_Table[Id] = N.ParamDistr[1];
		N.Rate_Sum = N.Rate_Sum + N.ParamDistr[0];
		N.Origine_Rate_Sum = N.Origine_Rate_Sum + N.ParamDistr[1];
		
    }
	double w=0.0;
	if (N.Transition[Id].DistTypeIndex > 2) {
		N.ParamDistr[0]= N.GetWeight(Id);
		w = GenerateTime(2, N.ParamDistr);
		//vector<double> wParam(1, N.GetWeight(Id));
		//w = GenerateTime(2, wParam);
    }
	
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = w;
	
}

void SimulatorRE::reset(){
	Simulator::reset();
	N.Origine_Rate_Sum=0;
	N.Rate_Sum=0;
}

void SimulatorRE::getParams(int Id){
	
	N.GetDistParameters(Id);
	N.ParamDistr[1]=N.ParamDistr[0];
	N.ParamDistr[0]= ComputeDistr( Id, N.ParamDistr[0]);
}


double SimulatorRE::mu(){
	
	vector<int> vect (N.Msimpletab.size());
	for(size_t i=0; i< N.Msimpletab.size();i++){
		vect[i] = N.Marking[N.Msimpletab[i]];
		//cout << i << " : " << N.Msimpletab[i] << " : " << N.Marking[N.Msimpletab[i]] << endl;
	};
	
    N.lumpingFun(&vect);
    //cerr << "test(";
    int i = muprob.findHash(&vect);
    if(i<0){
        cerr << "state:(";
        for (size_t j =0; j < vect.size(); j++) {
            cerr << vect[j] << ",";
        }
        cerr << ") ->" << i << endl;
       // exit(EXIT_FAILURE);
    }
    //cerr << ")" << endl;
	return((*muprob.muvect)[i]);
}

double SimulatorRE::ComputeDistr(int t , double origin_rate){
	
	double mux = mu();
	if( mux==0.0 || mux==1.0) return(origin_rate);
    
	if(t== N.tr-1){
		if(N.Origine_Rate_Sum >= N.Rate_Sum){
			return( (N.Origine_Rate_Sum - N.Rate_Sum)  );
		}else{ 
			return 0.0 ;};
	}; 
	
	double distr;
	N.fire(t);
	distr = origin_rate *( mu() / mux);
	N.unfire(t);
	return(distr);
}

