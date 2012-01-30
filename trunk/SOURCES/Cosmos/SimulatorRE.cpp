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
		//
		//(N.Origine_Rate_Table[E1_transitionNum] / 1.0) *
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
        vector<double> Param = getParams(Id);
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

void SimulatorRE::reset(){
	Simulator::reset();
	N.Origine_Rate_Sum=0;
	N.Rate_Sum=0;
}

vector<double> SimulatorRE::getParams(int Id){
	
	vector<double> P(2);
	double origin_rate = (N.GetDistParameters(Id))[0];
	P[0]= ComputeDistr( Id, origin_rate);
	P[1]= origin_rate;
	return P;
}


double SimulatorRE::mu(){
	
	vector<int> vect (N.Msimpletab.size());
	for(int i=0; i< N.Msimpletab.size();i++){
		vect[i] = N.Marking[N.Msimpletab[i]];
		//cout << i << " : " << N.Msimpletab[i] << " : " << N.Marking[N.Msimpletab[i]] << endl;
	};
	
	return((*muprob.muvect)[muprob.findHash(&vect)]);
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

