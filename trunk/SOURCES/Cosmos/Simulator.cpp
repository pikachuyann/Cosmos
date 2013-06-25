/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini, Benoit Barbot & Hilal Djafri                      *
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
#include <boost/math/distributions/lognormal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>
#include "marking.hpp"
//#include "interactive.hpp"


using namespace std;

/**
 * Constructor for the Simulator initialize the event queue
 * but don't fill it.
 */
Simulator::Simulator():verbose(0) {
	EQ = new EventsQueue(N); //initialization of the event queue
    logResult=false;
	Result.second = vector<double>(A.FormulaVal.size(),0.0);
	
	BatchSize = 1000;
}

Simulator::~Simulator() {
}

void Simulator::initRandomGenerator(unsigned int seed){
	RandomNumber.seed(seed);
}

void Simulator::logValue(const char* path){
    logvalue.open(path,fstream::out);
    logvalue.precision(15);
    logResult=true;
}

void Simulator::logTrace(const char* path){
    logtrace.open(path,fstream::out);
    logtrace.precision(15);
	logtrace << "Time\t";
	N.Marking.printHeader(logtrace);
	A.printHeader(logtrace);
	logtrace << endl;
}


void Simulator::SetBatchSize(const size_t RI) {
	BatchSize = RI;
}

/**
 * Fill the event queue with the initially enabled transition
 */
void Simulator::InitialEventsQueue() {
    //Check each transition. If a transition is enabled then his fire
    //time is simulated and added to the structure.
	
	Event E;
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

/**
 * Reset the SPN, The LHA and the Event Queue to the initial state.
 */
void Simulator::reset() {
	N.reset();
	A.reset(N.Marking);

	EQ->reset();
	
}

/**
 * This function is called when an accepting state is reached in
 * the automaton. It update the automaton variable before updating the
 * Hasl formula.
 */
void Simulator::returnResultTrue(){
	A.UpdateLinForm(N.Marking);
	A.UpdateLhaFuncLast();
	A.UpdateFormulaVal();
	Result.first = true;
	Result.second = vector<double>(A.FormulaVal);
}

/**
 * This function is called when a path is discarded.
 * This function is usefull in the rare event setting.
 */
void Simulator::returnResultFalse(){
	Result.first = false;
}

/**
 * Update the enabling transition of the SPN, and update the event queue.
 * @param E1_transitionNum the number of the transition which last 
 * occured in the SPN.
 * @param b is the binding of the last transition.
 */
void Simulator::updateSPN(size_t E1_transitionNum, const abstractBinding& lb){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.
    
	Event F;
    //check if the current transition is still enabled
	for(vector<abstractBinding>::const_iterator bindex = N.Transition[E1_transitionNum].bindingList.begin() ;
		bindex != N.Transition[E1_transitionNum].bindingList.end() ; ++bindex){
		bool Nenabled = N.IsEnabled(E1_transitionNum, *bindex);
		bool NScheduled = EQ->isScheduled(E1_transitionNum, bindex->id());
		
		if (Nenabled && NScheduled && lb.id() == bindex->id() ) {
			GenerateEvent(F, E1_transitionNum, *bindex);
			EQ->replace(F); //replace the transition with the new generated time
		} else if (Nenabled && !NScheduled) {
			GenerateEvent(F, E1_transitionNum, *bindex);
			EQ->insert(F);
		} else if (!Nenabled && NScheduled) {
			EQ->remove(E1_transitionNum,bindex->id() );
		} 
	}

	// Possibly adding Events corresponding to newly enabled-transitions
	const set<int>* net = N.PossiblyEn();
	for (set<int>::iterator it = net->begin(); it != net->end(); it++) {
		size_t bindnum = 0;
		abstractBinding *bindex = N.nextPossiblyEnabledBinding(*it, lb, &bindnum);
		while (bindex != NULL){
			
		//for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
		//	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
			if (N.IsEnabled(*it,*bindex)) {
				if (!EQ->isScheduled((*it),bindex->id())) {
					GenerateEvent(F, (*it), *bindex);
					(*EQ).insert(F);
				} else {
					if (N.Transition[(*it)].MarkingDependent) {
						GenerateEvent(F, (*it),*bindex);
						(*EQ).replace(F);
					}
				}
			}
			bindex = N.nextPossiblyEnabledBinding(*it, lb, &bindnum);
		}
	}
	
	// Possibly removing Events corresponding to newly disabled-transitions
	const set<int>* ndt = N.PossiblyDis();
	for (set<int>::iterator it = ndt->begin(); it != ndt->end(); it++) {
		size_t bindnum = 0;
		abstractBinding *bindex = N.nextPossiblyEnabledBinding(*it, lb, &bindnum);
		while (bindex != NULL){

		//for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
		//	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
			if (EQ->isScheduled(*it, bindex->id())) {
				if (!N.IsEnabled(*it, *bindex ))
					EQ->remove(*it,bindex->id());
				else {
					if (N.Transition[(*it)].MarkingDependent) {
						GenerateEvent(F, (*it),*bindex);
						EQ->replace(F);
					}
				}
			}
			bindex = N.nextPossiblyDisabledBinding(*it, lb, &bindnum);
		}
	}

    // Update transition which have no precondition on the Marking
	const set<int>* fmd = N.FreeMarkingDependant();
	for (set<int>::iterator it = fmd->begin(); it != fmd->end(); it++) {
		for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
			bindex != N.Transition[*it].bindingList.end() ; ++bindex){
			if (N.IsEnabled(*it,*bindex)) {
				if (!EQ->isScheduled(*it, bindex->id())) {
					GenerateEvent(F, (*it),*bindex);
					(*EQ).insert(F);
				} else {
					GenerateEvent(F, (*it),*bindex);
					(*EQ).replace(F);
				}
			}
		}
		
	}
	
#ifndef NDEBUG
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
				assert(N.IsEnabled(t->Id, *bindex) ==
					   EQ->isScheduled(t->Id, bindex->id()));
			}
		}
	}
#endif
}

/**
 * This function update the likelihood in the rare event context.
 * Do nothing when not in rare event context.
 * @param i Number of the transition of the SPN
 */
void Simulator::updateLikelihood(size_t){
	return;
}

/**
 * This function return true if the transition is the sink transition.
 * always return true when not in rare event context.
 * @param i Number of the transition of the SPN
 */
bool Simulator::transitionSink(size_t ){
    return false;
}

/**
 * Simulate one step of simulation
 * @return true if the simulation did not reach an accepting are refusing state.
 */
bool Simulator::SimulateOneStep(){
	
	AutEdge AE = A.GetEnabled_A_Edges( N.Marking);
	
    //If there is no enabled transition in the Petri net
    //try to reach an accepting state by using autonomous edge of 
    //the automata refuse the simulation otherwise.
	if ((*EQ).isEmpty()) {
		while (AE.Index>-1) {
            if(verbose>3){
				cerr << "Autonomous transition with Empty Queue:";
				cerr << AE.Index << endl;
				A.printState(cerr);
				cerr << endl;
			}
			A.updateLHA( AE.FiringTime - A.CurrentTime, N.Marking );
			A.fireLHA(AE.Index,N.Marking, abstractBinding() );
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
		      
        //If this transition is the sink transition refuse the simulation
        //Only usefull for Rare Event handling.
		if(transitionSink(E1.transition)){
			if(verbose>3)cerr << "Transition Sink\n";
            returnResultFalse();
            return false;
        }
        
        updateLikelihood(E1.transition);
		
        //Take all autonomous edge in the automata before the fire time
        //of the transition of the Petri net.
		while (E1.time >= AE.FiringTime) {
            //cerr << "looping on autonomous edge";
			
			A.updateLHA(AE.FiringTime - A.CurrentTime, N.Marking);
			A.fireLHA(AE.Index,N.Marking, abstractBinding());
			if(verbose>3){
				cerr << "Autonomous transition:" << AE.Index << endl;
				A.printState(cerr);
				cerr << endl;
			}
			
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else AE = A.GetEnabled_A_Edges( N.Marking);
		}
		if(verbose>3){
			//cerr << "|^^^^^^^^^^^^^^^^^^^^"<< endl;
			cerr << "\033[1;33mFiring:\033[0m" << N.Transition[E1.transition].label ;
			E1.binding.print();
			cerr << endl;
			//cerr << "|vvvvvvvvvvvvvvvvvvvv"<< endl;
		}
			
		//Make time elapse in the LHA
		A.updateLHA( E1.time - A.CurrentTime, N.Marking );
		
		//Print the state of the system after the time elapse
		if(logtrace.is_open()){
			logtrace << A.CurrentTime << "\t";
			N.Marking.print(logtrace);
			A.printState(logtrace);
			logtrace << endl;
		}
		
		//Fire the transition in the SPN
		N.fire(E1.transition, E1.binding);
		
        //Check if there exist a valid transition in the automata.
		int SE = A.GetEnabled_S_Edges(E1.transition, N.Marking, E1.binding);
		
		//If no synchronisation is possible the trajectory is rejected
		if (SE < 0) {
			returnResultFalse();
			return false;
		} else {
			//If synchronisation is possible fire it and check if the
			// reached state is final. Then update the SPN.
			A.fireLHA(SE,N.Marking, E1.binding);
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else {
				updateSPN(E1.transition, E1.binding);
			}
		}
	}
	return true;
}

/**
 * Interactive mode stop the simulation until the user choose a transition.
 */
void Simulator::interactiveSimulation(){
	string input_line;
	bool continueLoop = true;
	while(continueLoop){
		cerr << "\033[1;31mCosmosSimulator>\033[0m";
		if (cin.good()) {
			getline(cin, input_line);
			if(input_line.substr(0,5).compare("fire ")==0){
				string trans = input_line.substr(5,input_line.size()-5);
				size_t traid;
				for(traid=0; traid < N.Transition.size() && N.Transition[traid].label != trans ; traid++) ;
				if(traid == N.Transition.size())cerr << "Unknown transition: "<< trans << endl;
				else{
					if(EQ->isScheduled(traid, 0)){
						Event F;
						F.setTime(A.CurrentTime);
						F.setPriority((size_t)-1);
						F.setWeight(0.0);
						F.transition = traid;
						F.binding = N.Transition[traid].bindingList[0];
						EQ->replace(F);
						continueLoop = false;
					}else cerr << "Transition: "<< trans << " is not enabled" << endl;
				}
				
				
			}else if(input_line.compare("step")==0)continueLoop=false;
			else if(input_line.compare("stop")==0)exit(EXIT_SUCCESS);
			else if(input_line.compare("help")==0 || input_line.compare("h")==0){
				cerr << "Available command:\n\thelp:\tdisplay this message"<<endl;
				cerr << "\ts, step:\tmake one step of simulation" << endl;
				cerr << "\tfire tr:\tfire transition tr" << endl;
			} else if (input_line.compare("s")==0 || input_line.compare("s")==0)continueLoop=false;
			else if (input_line.compare("")==0);
			else {
				cerr << "Command not found:" << input_line << endl;
			}
			
		}else {
			if(cin.eof())exit(EXIT_SUCCESS);
			cerr << "error on the inpute stream\n";
			exit(EXIT_FAILURE);
		}
		
	}
	
	
}

/**
 * Simlulate a whole trajectory in the system. Result is store in SimOutput
 */
void Simulator::SimulateSinglePath() {
	
	InitialEventsQueue();
	A.setInitLocation(N.Marking);
	A.CurrentTime = 0;
	if(logtrace.is_open())logtrace << "New Path"<< endl;
    //cerr << "start path"<< endl;
    
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
			if(verbose>5)interactiveSimulation();
		}

		continueb = SimulateOneStep();
	}
    //cerr << "finish path"<< endl;
}

/**
 * Generate an event based on the type of his distribution
 * @param E the event to update
 * @param Id the number of the transition to of the SPN
 * @param b is the binding of the variable of the SPN for the transition.
 */
void Simulator::GenerateEvent(Event& E,size_t Id,const abstractBinding& b ) {
	
	double t = A.CurrentTime;
	if (N.Transition[Id].transType == Timed) {
		getParams(Id,b);
		t += GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr);
	}
    
    //The weight of a transition is always distributed exponentially
    //It is used to solved conflict of two transitions with same time 
    //and same priority.
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

/**
 * Return the parameter of a transition
 * @param Id the number of the transition of the SPN
 * @param b the binding of the transition of the SPN
 */
void Simulator::getParams(size_t Id, const abstractBinding& b){
	N.GetDistParameters(Id,b);
}

/**
 * Call the random generator to generate fire time.
 * @param distribution is the type of distribution
 * @param param is a vector of parameters of the distribution.
 */
double Simulator::GenerateTime(DistributionType distribution,const vector<double> &param) {
	
	switch (distribution) {
		case UNIFORM:
		{//UNIF
			boost::uniform_real<> UNIF(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			return gen();
			break;
		}
			
		case EXPONENTIAL:
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
			
		case DETERMINISTIC:
		{//DETERMINISTIC
			return param[0];
		}
			
		case LOGNORMAL:
		{//LogNormal
			boost::lognormal_distribution<> LOGNORMAL(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::lognormal_distribution<> > gen(RandomNumber, LOGNORMAL);
			return gen();
		}
			
		case TRIANGLE:
		{//Triangle
			boost::triangle_distribution<> TRIANGLE(param[0], param[1], param[2]);
			boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > gen(RandomNumber, TRIANGLE);
			return gen();
		}
		case GEOMETRIC:
		{//GEOMETRIC
			boost::uniform_real<> UNIF(0, 1);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			double p = gen();
			if (p >= param[0]) return param[1];
			else return param[1] * ceil(log(p / param[0]) / log(1 - param[0]) + 1);
		}
		case ERLANG:
        {//ERLANG           
            boost::uniform_real<> UNIF(0, 1);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            double prod = 1;
            for (int i = 0; i < param[0]; i++)
                prod = prod * gen();
            return -log(prod) / param[1];
			
        }
        case GAMMA:
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

BatchR* Simulator::RunBatch(){
	reset();
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
