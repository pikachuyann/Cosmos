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

#include <iostream>
#include <set>
#include <unistd.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <ratio>
#include <chrono>
#include <iomanip>

#include "Simulator.hpp"
#include "marking.hpp"

using namespace std;

/**
 * Constructor for the Simulator initialize the event queue
 * but don't fill it.
 */
Simulator::Simulator():verbose(0){
	EQ = new EventsQueue(N); //initialization of the event queue
	logResult=false;
	sampleTrace = 0.0;
	Result.second.resize(A.FormulaVal.size());
	BatchSize = 1000;
    minInteractiveTime = 0.0;
}

Simulator::~Simulator() {
  delete EQ;
}

void Simulator::logValue(const char* path){
    logvalue.open(path,fstream::out);
    logvalue.precision(15);
    logResult=true;
}

void Simulator::logTrace(const char* path,double sample){
	sampleTrace = sample;
    logtrace.open(path,fstream::out);
	//logtrace << "# sampling at:" << sample << endl;
    logtrace.precision(15);
	logtrace << "Time      ";
	N.Marking.printHeader(logtrace);
	A.printHeader(logtrace);
	logtrace << endl;
}

void Simulator::printLog(){
    if(logtrace.is_open())
        if((A.CurrentTime - lastSampled) >= sampleTrace){
            lastSampled = A.CurrentTime;
            logtrace <<setw(9)<<left<<setprecision(8)<< A.CurrentTime << "  ";
            logtrace << right;
            N.Marking.print(logtrace);
            A.printState(logtrace);
            logtrace << endl;
        }
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
	for(const auto &t : N.Transition) {
		for(auto &bindex : t.bindingList){
			if (N.IsEnabled(t.Id,bindex)) {
				GenerateEvent(E, t.Id ,bindex);
				EQ->insert(E);
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
	A.getFinalValues(N.Marking,Result.second);
	Result.first = true;
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
    
    //check if the current transition is still enabled
	for(const auto &bindex : N.Transition[E1_transitionNum].bindingList){
		bool Nenabled = N.IsEnabled(E1_transitionNum, bindex);
		bool NScheduled = EQ->isScheduled(E1_transitionNum, bindex.idcount);
		
		if (Nenabled && NScheduled && lb.idcount == bindex.idcount ) {
			GenerateEvent(F, E1_transitionNum, bindex);
			EQ->replace(F); //replace the transition with the new generated time
		} else if (Nenabled && !NScheduled) {
			GenerateEvent(F, E1_transitionNum, bindex);
			EQ->insert(F);
		} else if (!Nenabled && NScheduled) {
			EQ->remove(E1_transitionNum,bindex.idcount );
		}
	}
	
	// Possibly adding Events corresponding to newly enabled-transitions
    //const auto &net = N.PossiblyEn();
    for (size_t t=0; N.PossiblyEnabled[N.lastTransition][t] != -1;t++) {
        const auto &it = N.PossiblyEnabled[N.lastTransition][t];
		size_t bindnum = 0;
		const abstractBinding *bindex = N.nextPossiblyEnabledBinding(it, lb, &bindnum);
		while (bindex != NULL){
			if(verbose > 4){
				cerr << "consider for enabling: " << N.Transition[it].label << ",";
				bindex->print();
				cerr << endl;
			}
			
			//for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
			//	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
			if (N.IsEnabled(it,*bindex)) {
				if (!EQ->isScheduled(it,bindex->idcount)) {
					if(verbose > 4){
						cerr << "->New transition enabled: " << N.Transition[it].label << ",";
						bindex->print();
						cerr << endl;
					}
					if(!EQ->restart(A.CurrentTime,it,bindex->idcount)){
						GenerateEvent(F, (it), *bindex);
						(*EQ).insert(F);
					}
					
				} else {
					if (N.Transition[it].MarkingDependent) {
						GenerateEvent(F, it,*bindex);
						(*EQ).replace(F);
					}
				}
			}
			bindex = N.nextPossiblyEnabledBinding(it, lb, &bindnum);
		}
	}
	
	// Possibly removing Events corresponding to newly disabled-transitions
    //const auto &ndt = N.PossiblyDis();
    //for (const auto &it : ndt) {
    for (size_t t=0; N.PossiblyDisabled[N.lastTransition][t] != -1;t++) {
        const auto &it = N.PossiblyDisabled[N.lastTransition][t];
		size_t bindnum = 0;
		const abstractBinding *bindex = N.nextPossiblyDisabledBinding(it, lb, &bindnum);
		while (bindex != NULL){
			if(verbose > 4){
				cerr << "consider for disabling: " << N.Transition[it].label << ",";
				bindex->print();
				cerr << endl;
			}
			//for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
			//	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
			if (EQ->isScheduled(it, bindex->idcount)) {
				if (!N.IsEnabled(it, *bindex )){
					if(verbose > 4){
						cerr << "<-New transition disabled: " << N.Transition[it].label << ",";
						bindex->print();
						cerr << endl;
					}
					if(N.Transition[it].AgeMemory){
						EQ->pause(A.CurrentTime, it, bindex->idcount);
					}else EQ->remove(it,bindex->idcount);
				}else {
					if (N.Transition[it].MarkingDependent) {
						GenerateEvent(F, it,*bindex);
						EQ->replace(F);
					}
				}
			}
			bindex = N.nextPossiblyDisabledBinding(it, lb, &bindnum);
		}
	}
	
    // Update transition which have no precondition on the Marking
    for (size_t t=0; N.FreeMarkDepT[N.lastTransition][t]!= -1;t++) {
        const auto &it = N.FreeMarkDepT[N.lastTransition][t];
            //const auto &fmd = N.FreeMarkingDependant();
            //for (const auto &it : fmd) {
		for(const auto bindex : N.Transition[it].bindingList){
			//if (N.IsEnabled(it,bindex)) {
				if (EQ->isScheduled(it, bindex.idcount)) {
					GenerateEvent(F, it,bindex);
					(*EQ).replace(F);
				}
			//}
		}
		
	}
	//assert(cerr<< "assert!"<< endl);
	
	
        /*
	//In Debug mode check that transition are scheduled iff they are enabled
	for (const auto &t : N.Transition){
		for(const auto &bindex : t.bindingList){
			if (N.IsEnabled(t.Id, bindex) !=
				EQ->isScheduled(t.Id, bindex.idcount)){
				cerr << "N.IsEnabled(" << t.label << ",";
				bindex.print();
				cerr <<")" << endl;
				if(EQ->isScheduled(t.Id, bindex.idcount)){
					cerr << "Scheduled and not enabled!"<< endl;
				}else{
					cerr << "Enabled and not scheduled!" << endl;
				}
				assert(N.IsEnabled(t.Id, bindex) ==
					   EQ->isScheduled(t.Id, bindex.idcount));
			}
		}
	}
	 */ 
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
	static const abstractBinding dummyBinding;
	
	AutEdge AE = A.GetEnabled_A_Edges( N.Marking,dummyBinding);
	
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
			A.fireLHA(AE.Index,N.Marking, dummyBinding );
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else AE = A.GetEnabled_A_Edges( N.Marking,dummyBinding);
		}
		Result.first=false;
		return false;
	} else {
        //Take the first event in the queue
		const Event &E1 = EQ->InPosition(0);
		
        //If this transition is the sink transition refuse the simulation
        //Only usefull for Rare Event handling.
		if(transitionSink(E1.transition)){
			if(verbose>3)cerr << "\033[1;33mFiring:\033[0m" << "Transition Sink\n";
            Result.first=false;
            return false;
        }

        //Hook for rare event simulation
        updateLikelihood(E1.transition);
		
        //Take all autonomous edge in the automata before the fire time
        //of the transition of the Petri net.
		while (E1.time >= AE.FiringTime) {
            //cerr << "looping on autonomous edge";
			A.updateLHA(AE.FiringTime - A.CurrentTime, N.Marking);
            printLog();
			A.fireLHA(AE.Index,N.Marking, dummyBinding);
			if(verbose>3){
				cerr << "Autonomous transition:" << AE.Index << endl;
				A.printState(cerr);
				cerr << endl;
			}
			printLog();
			if (A.isFinal()) {
				returnResultTrue();
				return false;
			} else AE = A.GetEnabled_A_Edges( N.Marking,dummyBinding);
		}
		if(verbose>3){
			cerr << "\033[1;33mFiring:\033[0m" << N.Transition[E1.transition].label ;
			E1.binding.print();
		}
		
		//Make time elapse in the LHA
		A.updateLHA( E1.time - A.CurrentTime, N.Marking );
		
		//Print the state of the system after the time elapse
        printLog();
		
		//Fire the transition in the SPN
		N.fire(E1.transition, E1.binding, A.CurrentTime);
		
        //Check if there exist a valid transition in the automata.
		int SE = A.GetEnabled_S_Edges(E1.transition, N.Marking, E1.binding);
		
		//If no synchronisation is possible the trajectory is rejected
		if (SE < 0) {
			//cerr << "no synchronization" << endl;
			Result.first=false;
			return false;
		} else {
			if(verbose>3)cerr << " Synch with " << SE << endl;
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
    if(A.CurrentTime < minInteractiveTime)return;
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
            else if(input_line == "display" || input_line == "d"){
                if(!dotFile.empty()){
                    stringstream ss;
                    ss << "sed ";
                    N.Marking.printSedCmd(ss);
                    EQ->printSedCmd(N.Transition, ss);
                    ss << tmpPath << "/templatePetriNet.dot > " << tmpPath << "/PetriNet.dot; ";
                    ss << "dot "<< tmpPath <<"/PetriNet.dot -Tpdf -o " << dotFile << endl;
                    system(ss.str().c_str());
                } else cerr << "No dot output specified!" << endl;
            } else if(input_line.substr(0,5)=="wait "){
                try {
                    minInteractiveTime= A.CurrentTime + stod(input_line.substr(5,input_line.length()-5));
                    continueLoop = false;
                } catch (const invalid_argument& ia) {
                    cerr << "Fail to parse time!" << endl;
                } catch (const out_of_range& ia) {
                    cerr << "Fail to parse time!" << endl;
                }

            } else if(input_line.compare("help")==0 || input_line.compare("h")==0){
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
			cerr << "error on the input stream\n";
			exit(EXIT_FAILURE);
		}
		
	}
	
	
}

/**
 * Simulate a whole trajectory in the system. Result is store in SimOutput
 */
void Simulator::SimulateSinglePath() {
	
    InitialEventsQueue();
    minInteractiveTime=0.0;
	
	if(logtrace.is_open())logtrace << "New Path"<< endl;
    //cerr << "start path"<< endl;
    
	bool continueb = true;
	lastSampled = -sampleTrace;
	while (continueb) {
        //cerr << "continue path"<< endl;
        printLog();
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
        t += fmax(GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr),0.0);
        if(verbose > 4){
            cerr << "Sample " << N.Transition[Id].label << " with parameter (";
            cerr << N.ParamDistr[0];
            if (N.Transition[E.transition].DistTypeIndex == ERLANG)cerr << "," << N.ParamDistr[1];
            cerr << ")" << endl;
        }
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

BatchR Simulator::RunBatch(){
    auto starttime = chrono::steady_clock::now();
    auto currenttime = chrono::steady_clock::now();
    chrono::duration<double> timesize(0.03);
	BatchR batchResult(A.FormulaVal.size());
	while ((batchResult.I < BatchSize && BatchSize!=0) || (currenttime-starttime < timesize && BatchSize==0) ) {
		reset();
		SimulateSinglePath();
        batchResult.addSim(Result);
		if(verbose>3)batchResult.print();
		
		if (Result.first && logResult){
			for(size_t i=0; i<Result.second.size();i++){
				if (i>0)logvalue << "\t";
				logvalue << Result.second[i];
			}
			logvalue << endl;
		}
        currenttime=chrono::steady_clock::now();
    }
	return batchResult;
}
