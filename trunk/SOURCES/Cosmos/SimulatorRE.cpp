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

#include "SimulatorRE.hpp"

using namespace std;

SimulatorRE::SimulatorRE(bool b) {
	doubleIS_mode=b;
	N.gammaprob.Load();
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

void SimulatorRE::returnResultTrue(vector<int> marking, double D){
	A.UpdateLinForm(marking);
	A.UpdateLhaFunc(A.CurrentTime, D);
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = A.Likelihood * A.FormulaVal;
	return;
}

void SimulatorRE::returnResultFalse(){
	Result.first =true;
	Result.second =0.0;
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
	for(int i=0; i< (*EQ).getSize(); i++){ 
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
	if(doubleIS_mode){	
		A.Likelihood = A.Likelihood * 
		(N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) * 
		((N.Rate_Sum-N.Rate_Table[N.tr-1]) / N.Rate_Table[E1_transitionNum]);
	}else{
		A.Likelihood = A.Likelihood * 
		(N.Origine_Rate_Table[E1_transitionNum] / N.Origine_Rate_Sum) *
		(N.Rate_Sum / N.Rate_Table[E1_transitionNum]);
	}
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
        vector<double> Param = N.GetDistParameters(Id);
        t += GenerateTime(N.Transition[Id].DistType, Param);
		
		N.Rate_Table[Id] = Param[0];
		N.Origine_Rate_Table[Id] = Param[1];
		N.Rate_Sum = N.Rate_Sum + Param[0];
		N.Origine_Rate_Sum = N.Origine_Rate_Sum + Param[1];
		
    }
    double w;
    vector<double> wParam(1, N.GetWeight(Id));
    string dist = "EXPONENTIAL";
    w = GenerateTime(dist, wParam);
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = w;
	
}

