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

/**
 * Constructor for the Simulator initialize the event queue
 * but don't fill it.
 */
SimulatorLight::SimulatorLight():verbose(0),curr_time(0.0),EQ(N){
    Result=true;
    BatchSize = 1000;
}

void SimulatorLight::SetBatchSize(const TR_PL_ID RI) {
    BatchSize = RI;
}

/**
 * Fill the event queue with the initially enabled transition
 */
void SimulatorLight::InitialEventsQueue() {
    //Check each transition. If a transition is enabled then his fire
    //time is simulated and added to the structure.

    Event E;
    for(TR_PL_ID t=0; t<N.tr ; t++) {
        GenerateEvent(E, t);
        EQ.insert(E);
    }
}

/**
 * Reset the SPN, The LHA and the Event Queue to the initial state.
 */
void SimulatorLight::reset() {
    curr_time=0.0;
    N.reset();
    EQ.reset();
}


/**
 * Update the enabling transition of the SPN, and update the event queue.
 * @param E1_transitionNum the number of the transition which last
 * occured in the SPN.
 * @param b is the binding of the last transition.
 */
void SimulatorLight::updateSPN(TR_PL_ID){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.

    /*
    //check if the current transition is still enabled
    bool Nenabled = N.IsEnabled(E1_transitionNum);
    bool NScheduled = EQ->isScheduled(E1_transitionNum);

    if (Nenabled && NScheduled) {
        GenerateEvent(F, E1_transitionNum);
        EQ->replace(F); //replace the transition with the new generated time
    } else if (Nenabled && !NScheduled) {
        GenerateEvent(F, E1_transitionNum);
        EQ->insert(F);
    } else if (!Nenabled && NScheduled) {
        EQ->remove(E1_transitionNum);
    }


    // Possibly adding Events corresponding to newly enabled-transitions
    //const auto &net = N.PossiblyEn();
    for (size_t t=0; N.PossiblyEnabled[N.lastTransition][t] != -1;t++) {
        const auto &it = N.PossiblyEnabled[N.lastTransition][t];
            if(verbose > 4){
                cerr << "consider for enabling: " << N.Transition[it].label << ",";
                cerr << endl;
            }

            //for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
            //	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
            if (N.IsEnabled(it)) {
                if (!EQ->isScheduled(it)) {
                    if(verbose > 4){
                        cerr << "->New transition enabled: " << N.Transition[it].label << ",";
                        cerr << endl;
                    }
                    if(!EQ->restart(curr_time,it)){
                        GenerateEvent(F, (it));
                        (*EQ).insert(F);
                    }

                } else {
                    if (N.Transition[it].MarkingDependent) {
                        GenerateEvent(F, it);
                        (*EQ).replace(F);
                    }
                }
            }

    }

    // Possibly removing Events corresponding to newly disabled-transitions
    //const auto &ndt = N.PossiblyDis();
    //for (const auto &it : ndt) {
    for (size_t t=0; N.PossiblyDisabled[N.lastTransition][t] != -1;t++) {
        const auto &it = N.PossiblyDisabled[N.lastTransition][t];
            if(verbose > 4){
                cerr << "consider for disabling: " << N.Transition[it].label << ",";
                cerr << endl;
            }
            //for(vector<abstractBinding>::const_iterator bindex = N.Transition[*it].bindingList.begin() ;
            //	bindex != N.Transition[*it].bindingList.end() ; ++bindex){
            if (EQ->isScheduled(it)) {
                if (!N.IsEnabled(it )){
                    if(verbose > 4){
                        cerr << "<-New transition disabled: " << N.Transition[it].label << ",";
                        cerr << endl;
                    }
                    if(N.Transition[it].AgeMemory){
                        EQ->pause(curr_time, it);
                    }else EQ->remove(it);
                }else {
                    if (N.Transition[it].MarkingDependent) {
                        GenerateEvent(F, it);
                        EQ->replace(F);
                    }
                }
            }
               }

    // Update transition which have no precondition on the Marking
    for (size_t t=0; N.FreeMarkDepT[N.lastTransition][t]!= -1;t++) {
        const auto &it = N.FreeMarkDepT[N.lastTransition][t];
        //const auto &fmd = N.FreeMarkingDependant();
        //for (const auto &it : fmd) {
            //if (N.IsEnabled(it,bindex)) {
            if (EQ->isScheduled(it)) {
                GenerateEvent(F, it);
                (*EQ).replace(F);
            }

    }
    //assert(cerr<< "assert!"<< endl);
     */

    EQ.reset();

    //In Debug mode check that transition are scheduled iff they are enabled
    for(TR_PL_ID t=0; t<N.tr ; t++) {
        if (N.IsEnabled(t)){
            if (!EQ.isScheduled(t)) {
                    GenerateEvent(F, (t));
                    EQ.insert(F);
            }
        } else {
            if (EQ.isScheduled(t)) {
                EQ.remove(t);
            }
        }
    }
}

/**
 * Simulate one step of simulation
 * @return true if the simulation did not reach an accepting are refusing state.
 */
bool SimulatorLight::SimulateOneStep(){

    //If there is no enabled transition in the Petri net
    //try to reach an accepting state by using autonomous edge of
    //the automata refuse the simulation otherwise.
    if (EQ.isEmpty()) {
        return false;
    } else {
        //Take the first event in the queue
        const Event &E1 = EQ.InPosition(0);

        if(verbose>3){
            std::cerr << "\033[1;33mFiring:\033[0m" << E1.transition << std::endl;
        }

        curr_time = E1.time;

        //Fire the transition in the SPN
        N.fire(E1.transition, curr_time);

        updateSPN(E1.transition);
    }
    if(curr_time >= 100000)return false;
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
            N.Marking.printHeader(std::cerr);
            std::cerr << std::endl << curr_time << "\t";
            N.Marking.print(std::cerr);
            std::cerr << std::endl;
        }

        continueb = SimulateOneStep();
    }
    if(verbose>3){
        //Print marking and location of the automata
        //Usefull to track a simulation
        N.Marking.printHeader(std::cerr);
        std::cerr << std::endl;
        N.Marking.print(std::cerr);
        std::cerr << std::endl;
    }
    //cerr << "finish path"<< endl;
}

/**
 * Generate an event based on the type of his distribution
 * @param E the event to update
 * @param Id the number of the transition to of the SPN
 * @param b is the binding of the variable of the SPN for the transition.
 */
void SimulatorLight::GenerateEvent(Event& E,TR_PL_ID Id) {

    double t = curr_time;
    N.GetDistParameters(Id);
    t += N.ParamDistr[0];
    if(verbose > 4){
        std::cerr << "Sample " << Id << " with parameter (";
        std::cerr << N.ParamDistr[0];
        std::cerr << ")" << std::endl;
    }

    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = 0.0;
}


void SimulatorLight::RunBatch(){
    TR_PL_ID i=0;
    while (i < BatchSize) {
        i++;
        reset();
        SimulateSinglePath();
    }
}
