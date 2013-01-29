/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
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
 *******************************************************************************
 */

#include "Simulator.hpp"
//#include "SimulatorRE.h"
#include <iostream>
#include <set>
#include <unistd.h>
#include <math.h>
#include <float.h>
#include <boost/random.hpp>
//#include <boost/random/random_device.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>
#include "marking.hpp"


using namespace std;

Simulator::Simulator():verbose(0) {
	size_t n = N.tr; //n his the number of transition
	EQ = new EventsQueue(n); //initialization of the event queue
	Initialized = false;
    logResult=false;
	
	//Initialize random generator
	
	/*timeval t;
	gettimeofday(&t,(struct timezone*)0);
	RandomNumber.seed(t.tv_usec + t.tv_sec + getpid());*/
	//srand(time(t.tv_usec));
	
	/*RandomNumber.seed(RandomNumber());
	RandomNumber.seed(rand());*/
//	boost::random::random_device rng;
//	RandomNumber.seed(rng);

	BatchSize = 1000;
}

Simulator::~Simulator() {
}

void Simulator::initRandomGenerator(const unsigned int seed){
	RandomNumber.seed(seed);
}

void Simulator::logValue(const char* path){
    logvalue.open(path,fstream::out);
    logvalue.precision(15);
    logResult=true;
}

void Simulator::SetBatchSize(const size_t RI) {
	BatchSize = RI;
}

double Simulator::max(double a, double b) {
	if (a >= b) return a;
	else return b;
}

void Simulator::InitialEventsQueue() {
    //Check each transition. If a transition is enabled then his fire
    //time is simulated and added to the structure.
	Initialized = true;
	
	Event E;
	for (size_t t = 0; t < N.tr; t++) {
		if (N.IsEnabled(t)) {
		GenerateEvent(E, (t));
		(*EQ).insert(E);
		}
	}
}

void Simulator::reset() {
	//Reset The Petri net, the automaton, the event Queue and the 
    //random generator
    	
	N.reset();
	A.reset(N.Marking);

	(*EQ).reset();
	
}

void Simulator::returnResultTrue(){
    //This function is called when an accepting state is reached in 
    //the automaton. It update the automaton variable before updating the
    //Hasl formula.
    
	A.UpdateLinForm(N.Marking);
	A.UpdateLhaFuncLast();
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = vector<double>(A.FormulaVal);
}
void Simulator::returnResultFalse(){
	Result.first = false;
}


void Simulator::updateLHA(double DeltaT){
    //This function update the automaton after a transition of the Petri net
	A.DoElapsedTimeUpdate(DeltaT, N.Marking);
	A.UpdateLinForm(N.Marking);
	A.UpdateLhaFunc(DeltaT);
	A.CurrentTime += DeltaT;
}

void Simulator::fireLHA(int EdgeIndex){
	A.DoEdgeUpdates(EdgeIndex, N.Marking);
	A.CurrentLocation = A.Edge[EdgeIndex].Target;
}

void Simulator::updateSPN(int E1_transitionNum){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.
    
	Event F;
    //check if the current transition is still enabled
	if (N.IsEnabled(E1_transitionNum)) {		
		GenerateEvent(F, E1_transitionNum);
		(*EQ).replace(F, 0); //replace the transition with the new generated time
	} else (*EQ).remove(0);
	
	// Possibly adding Events corresponding to newly enabled-transitions
	const set<int>* net = N.PossiblyEn();
	for (set<int>::iterator it = net->begin(); it != net->end(); it++) {
		if (N.IsEnabled(*it)) {
			if ((*EQ).TransTabValue(*it) < 0) {
                GenerateEvent(F, (*it));
                (*EQ).insert(F);
			} else {
                if (N.Transition[(*it)].MarkingDependent) {
					GenerateEvent(F, (*it));
					(*EQ).replace(F, (*EQ).TransTabValue(*it));
                }
			}
		}
	}
	
	// Possibly removing Events corresponding to newly disabled-transitions
	const set<int>* ndt = N.PossiblyDis();
	for (set<int>::iterator it = ndt->begin(); it != ndt->end(); it++) {
		if ((*EQ).TransTabValue(*it)>-1) {
			if (!N.IsEnabled(*it))
                (*EQ).remove((*EQ).TransTabValue(*it));
			else {
                if (N.Transition[(*it)].MarkingDependent) {
					GenerateEvent(F, (*it));
					(*EQ).replace(F, (*EQ).TransTabValue(*it));
                }
			}
		}
	}

    // Update transition which have no precondition on the Marking
	const set<int>* fmd = N.FreeMarkingDependant();
	for (set<int>::iterator it = fmd->begin(); it != fmd->end(); it++) {
		if (N.IsEnabled(*it)) {
			if ((*EQ).TransTabValue(*it) < 0) {
                GenerateEvent(F, (*it));
                (*EQ).insert(F);
				
			} else {
                GenerateEvent(F, (*it));
                (*EQ).replace(F, (*EQ).TransTabValue(*it));
			}
		}
		
	}
}

// Only used in the Rare Event context
void Simulator::updateLikelihood(int i){
	return;
}

//Only used in the Rare Event context
bool Simulator::transitionSink(int i){
    return false;
}

//Simulate one step of simulation
//the return value is true if the simulation did not reach
//An accepting are refusing state.
bool Simulator::SimulateOneStep(){
    if(verbose>3){
        //Print marking and location of the automata
        //Usefull to track a simulation
		N.Marking.print();
        A.printState();
		cerr << endl;
    }
	//AutEdge AE = *AEref;
    
	AutEdge AE = A.GetEnabled_A_Edges( N.Marking);
	
    //If there is no enabled transition in the Petri net
    //try to reach an accepting state by using autonomous edge of 
    //the automata refuse the simulation otherwise.
	if ((*EQ).isEmpty()) {
		while (AE.Index>-1) {
            if(verbose>3){
				cerr << "Autonomous transition with Empty Queue:";
				cerr << AE.Index << endl;
				A.printState();
				cerr << endl;
			}
			updateLHA( AE.FiringTime - A.CurrentTime );
			fireLHA(AE.Index);
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else AE = A.GetEnabled_A_Edges( N.Marking);
		}
		returnResultFalse();
		return false;
	} else {
        //Take the first event in the queue
		Event E1 = (*EQ).InPosition(0);
		        
		int E1_transitionNum = E1.transition;
        
        //If this transition is the sink transition refuse the simulation
        //Only usefull for Rare Event handling.
		if(transitionSink(E1_transitionNum)){
            returnResultFalse();
            return false;
        }
        
        updateLikelihood(E1_transitionNum);
		
        //Take all autonomous edge in the automata before the fire time
        //of the transition of the Petri net.
		while (E1.time >= AE.FiringTime) {
            //cerr << "looping on autonomous edge";
			
			updateLHA(AE.FiringTime - A.CurrentTime);
			fireLHA(AE.Index);
			if(verbose>3){
				cerr << "Autonomous transition:" << AE.Index << endl;
				A.printState();
				cerr << endl;
			}
			
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else AE = A.GetEnabled_A_Edges( N.Marking);
		}
		if(verbose>3)
			cerr << "transition:" << N.Transition[E1.transition].label << endl;
		//Make time elapse in the LHA
		updateLHA( E1.time - A.CurrentTime );
		
		//Fire the transition in the SPN
		N.fire(E1_transitionNum);
		
        //Check if there exist a valid transition in the automata.
		int SE = A.GetEnabled_S_Edges(E1_transitionNum, N.Marking);
		
		//If no synchronisation is possible the trajectory is rejected
		if (SE < 0) {
			returnResultFalse();
			return false;
		} else {
			//If synchronisation is possible fire it and check if the
			// reached state is final. Then update the SPN.
			fireLHA(SE);
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else {
				updateSPN(E1_transitionNum);
			}
		}
	}
	return true;
}

//Simlulate a whole trajectory in the system. Result is store in SimOutput
void Simulator::SimulateSinglePath() {
	
	Simulator::InitialEventsQueue();
	A.CurrentLocation = A.EnabledInitLocation(N.Marking);
	A.CurrentTime = 0;
	
    //cerr << "start path"<< endl;
    
	bool continueb = true;
	while ((!(*EQ).isEmpty()) && continueb ) {
        //cerr << "continue path"<< endl;
		continueb = SimulateOneStep();
	}
    //cerr << "finish path"<< endl;
}


//Generate an event based on the type of his distribution
void Simulator::GenerateEvent(Event& E, int Id) {
	
	double t = A.CurrentTime;
	if (N.Transition[Id].transType == Timed) {
		getParams(Id);
		t += GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr);
	}
    
    //The weight of a transition is always distributed exponentially
    //It is used to solved conflict of two transitions with same time 
    //and same priority.
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

//Return the parameter of a transition
void Simulator::getParams(int Id){
	N.GetDistParameters(Id);
}
	
//Call the random generator to generate fire time.
double Simulator::GenerateTime(int distribution, vector<double> &param) {
	
	switch (distribution) {
		case 1:
		{//UNIF
			boost::uniform_real<> UNIF(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			return gen();
			break;
		}
			
		case 2:
		{//EXP
			//Exponential distribution is the only marking dependent parameters. Check of validity is required
			
			//-------------- Rare Event -----------------
			//cout << "rate:" << param[0] << endl;
			if(param[0] <= 0) { return 1e200; };
			//------------- /Rare Event -----------------
			
			if (param[0] <= 0) {
				cout << "Exponential ditribution should be with rate > 0 not "
                << param[0] << "\n End of Simulation" << endl;
				exit(1);
			}
			
			boost::exponential_distribution<> EXP(param[0]);
			boost::variate_generator<boost::mt19937&, boost::exponential_distribution<> > gen(RandomNumber, EXP);
			return gen();
			
		}
			
		case 3:
		{//DETERMINISTIC
			return param[0];
		}
			
		case 4:
		{//LogNormal
			boost::lognormal_distribution<> LOGNORMAL(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::lognormal_distribution<> > gen(RandomNumber, LOGNORMAL);
			return gen();
		}
			
		case 5:
		{//Triangle
			boost::triangle_distribution<> TRIANGLE(param[0], param[1], param[2]);
			boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > gen(RandomNumber, TRIANGLE);
			return gen();
		}
		case 6:
		{//GOEMETRIC
			boost::uniform_real<> UNIF(0, 1);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			double p = gen();
			if (p >= param[0]) return param[1];
			else return param[1] * ceil(log(p / param[0]) / log(1 - param[0]) + 1);
		}
		case 7:
        {//ERLANG           
            boost::uniform_real<> UNIF(0, 1);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            double prod = 1;
            for (int i = 0; i < param[0]; i++)
                prod = prod * gen();
            return -log(prod) / param[1];
			
        }
        case 8:
        {//GAMMA      
            boost::gamma_distribution<> GAMMA(param[0]);
            boost::variate_generator<boost::mt19937&, boost::gamma_distribution<> > gen(RandomNumber, GAMMA);
            return param[1] * gen();
        }

			
			
		default: cerr << "Unknown distribution: "<< distribution << endl;
			break;
	}
	return DBL_MIN;
	
}

//Run a batch of simulation, the result is return as a BatchR structure.
BatchR* Simulator::RunBatch(){
	BatchR* batchResult = new BatchR(A.FormulaVal.size());
	
	while (batchResult->I < BatchSize) {
		
		
		SimulateSinglePath();
		
        batchResult->addSim(&Result);
		
		if(verbose>3)batchResult->print();
		
		if (Result.first && logResult){
			for(size_t i=0; i<Result.second.size();i++){
				if (i>0)logvalue << "\t";
				logvalue << Result.second[i];
			}
			logvalue << endl;
		}
		
		reset();
    }
	
	return (batchResult);
	
}
