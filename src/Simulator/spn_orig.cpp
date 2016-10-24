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
#include "EventsQueue.hpp"
#include "EventsQueueSet.hpp"

using namespace std;

template<class EQT>
SPN_orig<EQT>::SPN_orig(int v):verbose(v){}

/**
 * Fill the event queue with the initially enabled transition
 */
template<>
void SPN_orig<EventsQueue>::initialEventsQueue(EventsQueue &EQ,timeGen &TG) {
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
                generateEvent(0.0,E, t.Id ,bindex,TG, *this);
                EQ.insert(E);
            }
        }
    }
}

template<>
void SPN_orig<EventsQueueSet>::initialEventsQueue(EventsQueueSet &EQ,timeGen &TG) {
    //Check each transition. If a transition is enabled then his fire
    //time is simulated and added to the structure.

    Event E;
    abstractBindingIterator absMkIt(Marking);
    absMkIt.reset(Marking);
    
    for(const auto &t : Transition) {
        if (verbose > 5) {
            std::cerr << "IEQ pour Transition " << t.Id << "(" << t.label << ") : \n";
        }
        
        absMkIt.reset(Marking);
        size_t it = t.Id;
        /* const auto &it = (const size_t) t.Id; */
        while (absMkIt.next(it, Marking)) {
            const auto& bindex =  absMkIt.getBinding();
            if (verbose > 5) {
                std::cerr << "Transition " << t.label << " IEQ : ";
                bindex.print();
                std::cerr << "\n";
            }
            if (IsEnabled(t.Id,bindex)) {
                generateEvent(0.0,E, t.Id ,bindex,TG, *this);
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
template<>
void SPN_orig<EventsQueue>::update(double ctime,size_t E1_transitionNum, const abstractBinding& lb,EventsQueue &EQ,timeGen &TG){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.

    //check if the current transition is still enabled
    for(const auto &bindex : Transition[E1_transitionNum].bindingList){
        bool Nenabled = IsEnabled(E1_transitionNum, bindex);
        bool NScheduled = EQ.isScheduled(E1_transitionNum, bindex.idcount);

        if (Nenabled && NScheduled && lb.idcount == bindex.idcount ) {
            generateEvent(ctime,F, E1_transitionNum, bindex,TG, *this);
            EQ.replace(F); //replace the transition with the new generated time
        } else if (Nenabled && !NScheduled) {
            generateEvent(ctime,F, E1_transitionNum, bindex,TG, *this);
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
                        generateEvent(ctime,F, (it), *bindex,TG, *this);
                        EQ.insert(F);
                    }

                } else {
                    if (Transition[it].MarkingDependent) {
                        generateEvent(ctime,F, it,*bindex,TG, *this);
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
                        generateEvent(ctime,F, it,*bindex,TG, *this);
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
                generateEvent(ctime,F, it,bindex,TG, *this);
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

template<>
void SPN_orig<EventsQueueSet>::update(double ctime,size_t E1_transitionNum, const abstractBinding& lb,EventsQueueSet &EQ,timeGen &TG){
    //This function update the Petri net according to a transition.
    //In particular it update the set of enabled transition.

    //check if the current transition is still enabled
    abstractBindingIterator absMkIt(Marking);
    absMkIt.reset(Marking);
    
    EQ.remove(E1_transitionNum, lb.idcount);
    
    //for(const auto &bindex : Transition[E1_transitionNum].bindingList){
    while (absMkIt.next(E1_transitionNum, Marking)) {
        const auto& bindex = absMkIt.getBinding();
        // bindex = Transition[E1_transitionNum].bindingList[tmpbindex];
        // bindex type abstractBinding

        if (verbose > 4) {
            std::cerr << "[!] I've been enabled !" << E1_transitionNum << ".\n";
            std::cerr << "Currently testing with token : ";
            bindex.print();
            std::cerr << ".\n";
        }
        
        bool Nenabled = IsEnabled(E1_transitionNum, bindex);
        bool NScheduled = EQ.isScheduled(E1_transitionNum, bindex.idcount);
        if (verbose > 4) {
            std::cerr << "Current status: IsEnabled ? " << Nenabled << ". Is Scheduled ? " << NScheduled << ".\n";
        }

        if (Nenabled && NScheduled && lb.idcount == bindex.idcount ) {
            generateEvent(ctime,F, E1_transitionNum, bindex,TG, *this);
            EQ.replace(F); //replace the transition with the new generated time
        } else if (Nenabled && !NScheduled) {
            generateEvent(ctime,F, E1_transitionNum, bindex,TG, *this);
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
        if (verbose > 4) {
            std::cerr << "(Possibly Enabled) Considering transition" << it << ".\n";
        }
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
                        generateEvent(ctime,F, (it), bindex,TG, *this);
                        EQ.insert(F);
                    }

                } else {
                    if (Transition[it].MarkingDependent) {
                        generateEvent(ctime,F, it,bindex,TG, *this);
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
        
        auto& transitionEQ = EQ.evtHeapIndex[it];
        
        for (const auto EventId : transitionEQ) {
            if (EventId.second >= 0) {
                const auto& realbindex = EventId.first;
                const auto& bindex = EQ.evtTbl[it][realbindex].binding;
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
                        generateEvent(ctime,F, it,bindex,TG, *this);
                        EQ.replace(F);
                    }
                }
            }
            }
        }
 /*       size_t bindnum = 0;
        if (verbose > 4) {
            std::cerr << "(Possibly Disabled) Considering transition" << it << ".\n";
        }
        absMkIt.reset(Marking);
        while (absMkIt.next(it, Marking)) {
            const auto& bindex =  absMkIt.getBinding();
            //std::cerr << "Found binding :" << bindex.print << ".\n";
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
   */
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
                generateEvent(ctime,F, it,bindex,TG, *this);
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

template class SPN_orig<EventsQueue>;
template class SPN_orig<EventsQueueSet>;


