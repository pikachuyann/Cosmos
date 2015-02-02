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
 * file SimLight.cpp created by Benoit Barbot on 5/02/2015.                    *
 *******************************************************************************
 */

#include "SimLight.hpp"



using namespace std;

/**
 * Constructor for the Simulator initialize the event queue
 * but don't fill it.
 */
SimulatorLight::SimulatorLight():verbose(0),curr_time(0.0){
    EQ = new EventsQueue(N); //initialization of the event queue
    Result.second.resize(1);
    BatchSize = 1000;
}

SimulatorLight::~SimulatorLight() {
    delete EQ;
}

void SimulatorLight::SetBatchSize(const size_t RI) {
    BatchSize = RI;
}

/**
 * Fill the event queue with the initially enabled transition
 */
void SimulatorLight::InitialEventsQueue() {
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
void SimulatorLight::reset() {
    curr_time=0.0;
    N.reset();
    EQ->reset();
}


/**
 * Update the enabling transition of the SPN, and update the event queue.
 * @param E1_transitionNum the number of the transition which last
 * occured in the SPN.
 * @param b is the binding of the last transition.
 */
void SimulatorLight::updateSPN(size_t E1_transitionNum, const abstractBinding& lb){
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
                    if(!EQ->restart(curr_time,it,bindex->idcount)){
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
                        EQ->pause(curr_time, it, bindex->idcount);
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
 * Simulate one step of simulation
 * @return true if the simulation did not reach an accepting are refusing state.
 */
bool SimulatorLight::SimulateOneStep(){
    static const abstractBinding dummyBinding;

    //If there is no enabled transition in the Petri net
    //try to reach an accepting state by using autonomous edge of
    //the automata refuse the simulation otherwise.
    if ((*EQ).isEmpty()) {
        return false;
    } else {
        //Take the first event in the queue
        const Event &E1 = EQ->InPosition(0);

        if(verbose>3){
            cerr << "\033[1;33mFiring:\033[0m" << N.Transition[E1.transition].label ;
            E1.binding.print();
        }

        curr_time = E1.time;

        //Fire the transition in the SPN
        N.fire(E1.transition, E1.binding, curr_time);

        updateSPN(E1.transition, E1.binding);
    }
    return true;
}


/**
 * Simulate a whole trajectory in the system. Result is store in SimOutput
 */
void SimulatorLight::SimulateSinglePath() {

    InitialEventsQueue();

    bool continueb = true;
    while (continueb) {
        //cerr << "continue path"<< endl;
        if(verbose>3){
            //Print marking and location of the automata
            //Usefull to track a simulation
            N.Marking.printHeader(cerr);
            cerr << endl;
            N.Marking.print(cerr);
            cerr << endl;
            if(verbose>4)EQ->view(N.Transition);
        }

        continueb = SimulateOneStep();
    }
    if(verbose>3){
        //Print marking and location of the automata
        //Usefull to track a simulation
        N.Marking.printHeader(cerr);
        cerr << endl;
        N.Marking.print(cerr);
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
void SimulatorLight::GenerateEvent(Event& E,size_t Id,const abstractBinding& b ) {
    double t = curr_time;
    if (N.Transition[Id].transType == Timed) {
        N.GetDistParameters(Id,b);
        t += N.ParamDistr[0];
        if(verbose > 4){
            cerr << "Sample " << N.Transition[Id].label << " with parameter (";
            cerr << N.ParamDistr[0];
            if (N.Transition[E.transition].DistTypeIndex == ERLANG)cerr << "," << N.ParamDistr[1];
            cerr << ")" << endl;
        }
    }

    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = 0.0;
    E.binding = b;
}


void SimulatorLight::RunBatch(){
    size_t i=0;
    while (i < BatchSize) {
        i++;
        reset();
        SimulateSinglePath();
    }
}
