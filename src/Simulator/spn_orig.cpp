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
 * file spn_orig.cpp created by Benoit Barbot on 03/09/15.                     *
 *******************************************************************************
 */

#include "spn_orig.hpp"

using namespace std;

SPN_orig::SPN_orig(int& v):verbose(v){}

/**
 * Generate an event based on the type of his distribution
 * @param E the event to update
 * @param Id the number of the transition to of the SPN
 * @param b is the binding of the variable of the SPN for the transition.
 */
void SPN_orig::GenerateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &TG) {
    double t=ctime;
    if (Transition[Id].DistTypeIndex != IMMEDIATE) {
        GetDistParameters(Id,b);
        t += fmax(TG.GenerateTime(Transition[Id].DistTypeIndex, ParamDistr, customDistr),0.0);
        if(verbose > 4){
            cerr << "Sample " << Transition[Id].label << ": ";
            cerr << TG.string_of_dist(Transition[Id].DistTypeIndex, ParamDistr);
            cerr << endl;
        }
    }

    //The weight of a transition is always distributed exponentially
    //It is used to solved conflict of two transitions with same time
    //and same priority.
    double w=0.0;
    if (Transition[Id].DistTypeIndex > 2) {
        ParamDistr[0]= GetWeight(Id,b);
        w = TG.GenerateTime(EXPONENTIAL, ParamDistr, customDistr);
        if(verbose>4){
            cerr << "weight : ";
            cerr << TG.string_of_dist(EXPONENTIAL, ParamDistr);
            cerr << endl;
        }
    }

    E.transition = Id;
    E.time = t;
    E.priority = GetPriority(Id,b);
    E.weight = w;
    E.binding = b;
}

/**
 * Fill the event queue with the initially enabled transition
 */
void SPN_orig::InitialEventsQueue(EventsQueueSet &EQ,timeGen &TG) {
    //Check each transition. If a transition is enabled then his fire
    //time is simulated and added to the structure.

    Event E;
    for(const auto &t : Transition) {
        if (verbose > 5) {
            std::cerr << "IEQ pour Transition " << t.Id << "(" << t.label << ") : \n";
        }
        for(auto &bindex : t.bindingList){
                if (verbose > 5) {
                    std::cerr << "Transition " << t.label << " IEQ : ";
                    bindex.print();
                    std::cerr << "\n";
                }
            if (IsEnabled(t.Id,bindex)) {
                GenerateEvent(0.0,E, t.Id ,bindex,TG);
                EQ.insert(E);
            }
        }
    }
}


/**
 * Update the enabling transition of the SPN, and update the event queue.
 * @param E1_transitionNum the number of the transition which last
 * occured in the SPN.
 * @param b is the binding of the last transition.
 */
void SPN_orig::update(double ctime,size_t E1_transitionNum, const abstractBinding& lb,EventsQueueSet &EQ,timeGen &TG){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.

    //check if the current transition is still enabled
    for(const auto &bindex : Transition[E1_transitionNum].bindingList){
        bool Nenabled = IsEnabled(E1_transitionNum, bindex);
        bool NScheduled = EQ.isScheduled(E1_transitionNum, bindex.idcount);

        if (Nenabled && NScheduled && lb.idcount == bindex.idcount ) {
            GenerateEvent(ctime,F, E1_transitionNum, bindex,TG);
            EQ.replace(F); //replace the transition with the new generated time
        } else if (Nenabled && !NScheduled) {
            GenerateEvent(ctime,F, E1_transitionNum, bindex,TG);
            EQ.insert(F);
        } else if (!Nenabled && NScheduled) {
            EQ.remove(E1_transitionNum,bindex.idcount );
        }
    }

    // Possibly adding Events corresponding to newly enabled-transitions
    //const auto &net = PossiblyEn();
    for (size_t t=0; PossiblyEnabled[lastTransition][t] != -1;t++) {
        const auto &it = PossiblyEnabled[lastTransition][t];
        size_t bindnum = 0;
        const abstractBinding *bindex = nextPossiblyEnabledBinding(it, lb, &bindnum);
        while (bindex != NULL){
            if(verbose > 4){
                std::cerr << "consider for enabling: " << Transition[it].label << ",";
                bindex->print();
                cerr << endl;
            }

            //for(vector<abstractBinding>::const_iterator bindex = Transition[*it].bindingList.begin() ;
            //	bindex != Transition[*it].bindingList.end() ; ++bindex){
            if (IsEnabled(it,*bindex)) {
                if (!EQ.isScheduled(it,bindex->idcount)) {
                    if(verbose > 4){
                        cerr << "->New transition enabled: " << Transition[it].label << ",";
                        bindex->print();
                        cerr << endl;
                    }
                    if(!EQ.restart(ctime,it,bindex->idcount)){
                        GenerateEvent(ctime,F, (it), *bindex,TG);
                        EQ.insert(F);
                    }

                } else {
                    if (Transition[it].MarkingDependent) {
                        GenerateEvent(ctime,F, it,*bindex,TG);
                        EQ.replace(F);
                    }
                }
            }
            bindex = nextPossiblyEnabledBinding(it, lb, &bindnum);
        }
    }

    // Possibly removing Events corresponding to newly disabled-transitions
    //const auto &ndt = PossiblyDis();
    //for (const auto &it : ndt) {
    for (size_t t=0; PossiblyDisabled[lastTransition][t] != -1;t++) {
        const auto &it = PossiblyDisabled[lastTransition][t];
        size_t bindnum = 0;
        const abstractBinding *bindex = nextPossiblyDisabledBinding(it, lb, &bindnum);
        while (bindex != NULL){
            if(verbose > 4){
                cerr << "consider for disabling: " << Transition[it].label << ",";
                bindex->print();
                cerr << endl;
            }
            //for(vector<abstractBinding>::const_iterator bindex = Transition[*it].bindingList.begin() ;
            //	bindex != Transition[*it].bindingList.end() ; ++bindex){
            if (EQ.isScheduled(it, bindex->idcount)) {
                if (!IsEnabled(it, *bindex )){
                    if(verbose > 4){
                        cerr << "<-New transition disabled: " << Transition[it].label << ",";
                        bindex->print();
                        cerr << endl;
                    }
                    if(Transition[it].AgeMemory){
                        EQ.pause(ctime, it, bindex->idcount);
                    }else EQ.remove(it,bindex->idcount);
                }else {
                    if (Transition[it].MarkingDependent) {
                        GenerateEvent(ctime,F, it,*bindex,TG);
                        EQ.replace(F);
                    }
                }
            }
            bindex = nextPossiblyDisabledBinding(it, lb, &bindnum);
        }
    }

    // Update transition which have no precondition on the Marking
    for (size_t t=0; FreeMarkDepT[lastTransition][t]!= -1;t++) {
        const auto &it = FreeMarkDepT[lastTransition][t];
        //const auto &fmd = FreeMarkingDependant();
        //for (const auto &it : fmd) {
        for(const auto bindex : Transition[it].bindingList){
            //if (IsEnabled(it,bindex)) {
            if (EQ.isScheduled(it, bindex.idcount)) {
                GenerateEvent(ctime,F, it,bindex,TG);
                EQ.replace(F);
            }
            //}
        }
        
    }
    //assert(cerr<< "assert!"<< endl);
    
    /*
     //In Debug mode check that transition are scheduled iff they are enabled
     for (const auto &t : Transition){
     for(const auto &bindex : t.bindingList){
     if (IsEnabled(t.Id, bindex) !=
     EQ.isScheduled(t.Id, bindex.idcount)){
     cerr << "IsEnabled(" << t.label << ",";
     bindex.print();
     cerr <<")" << endl;
     if(EQ.isScheduled(t.Id, bindex.idcount)){
					cerr << "Scheduled and not enabled!"<< endl;
     }else{
					cerr << "Enabled and not scheduled!" << endl;
     }
     assert(IsEnabled(t.Id, bindex) ==
     EQ.isScheduled(t.Id, bindex.idcount));
     }
     }
     }
     */ 

}

void SPN_orig::updateSet(double ctime,size_t E1_transitionNum, const abstractBinding& lb,EventsQueueSet &EQ,timeGen &TG){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.

    //check if the current transition is still enabled
    abstractBindingIterator absMkIt(Marking);
    absMkIt.reset(Marking);
    
    while (absMkIt.next(E1_transitionNum, Marking)) {
        const auto& bindex = absMkIt.getBinding();
        // bindex = Transition[E1_transitionNum].bindingList[tmpbindex];
        // bindex type abstractBinding

        bool Nenabled = IsEnabled(E1_transitionNum, bindex);
        bool NScheduled = EQ.isScheduled(E1_transitionNum, bindex.idcount);

        if (Nenabled && NScheduled && lb.idcount == bindex.idcount ) {
            GenerateEvent(ctime,F, E1_transitionNum, bindex,TG);
            EQ.replace(F); //replace the transition with the new generated time
        } else if (Nenabled && !NScheduled) {
            GenerateEvent(ctime,F, E1_transitionNum, bindex,TG);
            EQ.insert(F);
        } else if (!Nenabled && NScheduled) {
            EQ.remove(E1_transitionNum,bindex.idcount );
        }
    }

    //absMkIt.reset();
    
    // Possibly adding Events corresponding to newly enabled-transitions
    //const auto &net = PossiblyEn();
    for (size_t t=0; PossiblyEnabled[lastTransition][t] != -1;t++) {
        size_t it = (size_t) PossiblyEnabled[lastTransition][t];
        size_t bindnum = 0;
        absMkIt.reset(Marking);
        while (absMkIt.next(it, Marking)) {
            const auto& bindex =  absMkIt.getBinding();

            if(verbose > 4){
                std::cerr << "consider for enabling: " << Transition[it].label << ",";
                bindex.print();
                cerr << endl;
            }

            //for(vector<abstractBinding>::const_iterator bindex = Transition[*it].bindingList.begin() ;
            //	bindex != Transition[*it].bindingList.end() ; ++bindex){
            if (IsEnabled(it,bindex)) {
                if (!EQ.isScheduled(it,bindex.idcount)) {
                    if(verbose > 4){
                        cerr << "->New transition enabled: " << Transition[it].label << ",";
                        bindex.print();
                        cerr << endl;
                    }
                    if(!EQ.restart(ctime,it,bindex.idcount)){
                        GenerateEvent(ctime,F, (it), bindex,TG);
                        EQ.insert(F);
                    }

                } else {
                    if (Transition[it].MarkingDependent) {
                        GenerateEvent(ctime,F, it,bindex,TG);
                        EQ.replace(F);
                    }
                }
            }
        }
    }

    // Possibly removing Events corresponding to newly disabled-transitions
    //const auto &ndt = PossiblyDis();
    //for (const auto &it : ndt) {
    for (size_t t=0; PossiblyDisabled[lastTransition][t] != -1;t++) {
        //const auto &it = PossiblyDisabled[lastTransition][t];
        size_t it = (size_t) PossiblyDisabled[lastTransition][t];
        size_t bindnum = 0;
        absMkIt.reset(Marking);
        while (absMkIt.next(it, Marking)) {
            const auto& bindex =  absMkIt.getBinding();
        //const abstractBinding *bindex = nextPossiblyDisabledBinding(it, lb, &bindnum);
        //while (bindex != NULL){
            if(verbose > 4){
                cerr << "consider for disabling: " << Transition[it].label << ",";
                bindex.print();
                cerr << endl;
            }
            //for(vector<abstractBinding>::const_iterator bindex = Transition[*it].bindingList.begin() ;
            //	bindex != Transition[*it].bindingList.end() ; ++bindex){
            if (EQ.isScheduled(it, bindex.idcount)) {
                if (!IsEnabled(it, bindex )){
                    if(verbose > 4){
                        cerr << "<-New transition disabled: " << Transition[it].label << ",";
                        bindex.print();
                        cerr << endl;
                    }
                    if(Transition[it].AgeMemory){
                        EQ.pause(ctime, it, bindex.idcount);
                    }else EQ.remove(it,bindex.idcount);
                }else {
                    if (Transition[it].MarkingDependent) {
                        GenerateEvent(ctime,F, it,bindex,TG);
                        EQ.replace(F);
                    }
                }
            }
            //bindex = nextPossiblyDisabledBinding(it, lb, &bindnum);
        }
    }

    // Update transition which have no precondition on the Marking
    for (size_t t=0; FreeMarkDepT[lastTransition][t]!= -1;t++) {
        //const auto &it = FreeMarkDepT[lastTransition][t];
        size_t it = (size_t) FreeMarkDepT[lastTransition][t];
        //const auto &fmd = FreeMarkingDependant();
        //for (const auto &it : fmd) {
        absMkIt.reset(Marking);
        while (absMkIt.next(it, Marking)) {
            const auto& bindex =  absMkIt.getBinding();
            //if (IsEnabled(it,bindex)) {
            if (EQ.isScheduled(it, bindex.idcount)) {
                GenerateEvent(ctime,F, it,bindex,TG);
                EQ.replace(F);
            }
            //}
        }
        
    }
    //assert(cerr<< "assert!"<< endl);
    
    /*
     //In Debug mode check that transition are scheduled iff they are enabled
     for (const auto &t : Transition){
     for(const auto &bindex : t.bindingList){
     if (IsEnabled(t.Id, bindex) !=
     EQ.isScheduled(t.Id, bindex.idcount)){
     cerr << "IsEnabled(" << t.label << ",";
     bindex.print();
     cerr <<")" << endl;
     if(EQ.isScheduled(t.Id, bindex.idcount)){
					cerr << "Scheduled and not enabled!"<< endl;
     }else{
					cerr << "Enabled and not scheduled!" << endl;
     }
     assert(IsEnabled(t.Id, bindex) ==
     EQ.isScheduled(t.Id, bindex.idcount));
     }
     }
     }
     */ 
}
