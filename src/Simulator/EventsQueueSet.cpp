/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Benoît Barbot & Paolo Ballarini & Hilal Djafri                     *
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
 * file EventsQueueSet.cpp created by on 31/05/2016                            *
 *******************************************************************************
 */

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <iomanip>

#include "Event.hpp"
#include "EventsQueueSet.hpp"


using namespace std;

/**
 *	Build an Event queue for the Petri net given as parameter.
 */
EventsQueueSet::EventsQueueSet(const SPN& N):
    evtHeapIndex(N.Transition.size()),
    evtTbl(N.Transition.size()){
}

/**
 * Clear the events queue. The resulting events queues does not contain any event.
 */
void EventsQueueSet::reset() {
    for(size_t it = 0; it< evtTbl.size(); ++it ){
        evtHeapIndex[it].clear();
        evtTbl[it].clear();
        }
    evtHeap.clear();
    //Qsize = 0;
}

/**
 * Copy of events queue
 */
EventsQueueSet::EventsQueueSet(const EventsQueueSet& orig) {
    
    //Qsize = orig.Qsize;
    
    evtTbl = orig.evtTbl;
    evtHeap = orig.evtHeap;
    evtHeapIndex = orig.evtHeapIndex;
    
    /*eq = orig.eq;
     TransTableSize = orig.TransTableSize;
     TransTable = orig.TransTable;*/
}

EventsQueueSet::~EventsQueueSet() {
}

/*
 *	Insert a new event in the events queue and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueueSet::insert(const Event &e) {
    //assert(!isScheduled(e.transition, e.binding.id()));
    evtTbl[e.transition][e.binding.id()] = e;
    evtHeapIndex[e.transition][e.binding.id()] = evtHeap.size();
    evtHeap.push_back(sizeSq(e.transition,e.binding.id()));
    
    siftUp(evtHeap.size()-1);
}

/*
 *	Replace the time, priority,service of an event and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueueSet::replace(const Event &e) {
    //assert(isScheduled(e.transition, e.binding.id()));
    long int k = evtHeapIndex[e.transition][e.binding.id()];
    evtTbl[e.transition][e.binding.id()] = e;
    
    siftUp(k);
    siftDown(k);
}

/*
 *	Remove an event and update the tree.
 *  @param tr a transition of the Petri net.
 *  @param b a binding of the Petri net.
 */
void EventsQueueSet::remove(size_t tr, size_t b) {
    long int i = evtHeapIndex[tr][b];
    evtTbl[tr].erase(b);
    //assert(i>=0);
    if(i>=0){
        if ((size_t)i == evtHeap.size()-1) {
            evtHeapIndex[tr].erase(b);
            evtHeap.pop_back();
        } else {
            evtHeapIndex[evtHeap.back().tr][evtHeap.back().bid] = i;
            evtHeapIndex[tr].erase(b);
            evtHeap[i] = evtHeap.back();
            evtHeap.pop_back();
            
            siftDown(i);
            siftUp(i);
        }
    }
}

/**
 *  Pause an event, remove it from the tree
 *  @param t is the current time
 *  @param tr a transition of the Petri net.
 *  @param b a binding of the Petri net.
 */
void EventsQueueSet::pause(double t, size_t tr,size_t b){
    //assert(i>=0);
    if(evtHeapIndex[tr].count(b)>0){
        evtTbl[tr][b].time -= t;
        long int i = evtHeapIndex[tr][b];
        if(i>=0){
            if ((size_t)i == evtHeap.size()-1) {
                evtHeapIndex[tr][b] = -1;
                evtHeap.pop_back();
            } else {
                evtHeapIndex[evtHeap.back().tr][evtHeap.back().bid] = i;
                evtHeapIndex[tr][b] = -1 ;
                evtHeap[i] = evtHeap.back();
                evtHeap.pop_back();
                
                siftDown(i);
                siftUp(i);
            }
        }
    }
}

/**
 * Check if an event can be restarted. If it is possible
 * restart it otherwise return false.
 *  @param t is the current time
 *  @param tr a transition of the Petri net.
 *  @param b a binding of the Petri net.
 */
bool EventsQueueSet::restart(double t, size_t tr,size_t b){
    if(evtTbl[tr].count(b) == 0)return false;
    if(evtTbl[tr][b].time < 0.0)return false;
    evtTbl[tr][b].time += t;
    evtHeapIndex[tr][b] = evtHeap.size();
    evtHeap.push_back(sizeSq(tr,b));
    
    siftUp(evtHeap.size()-1);
    return true;
}

const Event& EventsQueueSet::InPosition(size_t i)const {
    //cerr << i << "," << evtHeap.size() << endl;
    //assert(i < evtHeap.size());
    const sizeSq& evsq = evtHeap[i];
    return evtTbl[evsq.tr].at(evsq.bid);
}

bool EventsQueueSet::isScheduled(size_t tr,size_t b)const {
    return (evtHeapIndex[tr].count(b) > 0);
}

void EventsQueueSet::swapEvt(size_t i,size_t j){
    //assert((size_t)evtHeapIndex[evtHeap[j].first][evtHeap[j].second] ==j
    //	   && (size_t)evtHeapIndex[evtHeap[i].first][evtHeap[i].second] == i);
    evtHeapIndex[evtHeap[j].tr][evtHeap[j].bid] = i;
    evtHeapIndex[evtHeap[i].tr][evtHeap[i].bid] = j;
    
    sizeSq swappair = evtHeap[j];
    evtHeap[j] = evtHeap[i];
    evtHeap[i] = swappair;
}

void EventsQueueSet::siftUp(size_t i) {
    size_t parentIndex;
    
    if (i != 0) {
        parentIndex = getParentIndex(i);
        
        if (InPosition(i).isPriorer(InPosition(parentIndex))){
            swapEvt(i, parentIndex);
            siftUp(parentIndex);
        }
    }
}

void EventsQueueSet::siftDown(size_t i) {
    size_t leftChildIndex, rightChildIndex, minIndex;
    leftChildIndex = getLeftChildIndex(i);
    rightChildIndex = getRightChildIndex(i);
    if (rightChildIndex >= evtHeap.size()) {
        if (leftChildIndex >= evtHeap.size())
            return;
        else
            minIndex = leftChildIndex;
    } else {
        
        if (InPosition(leftChildIndex).isPriorer(InPosition(rightChildIndex)))
            minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }
    
    if (InPosition(minIndex).isPriorer(InPosition(i))) {
        swapEvt(minIndex,i);
        siftDown(minIndex);
    }
    
    
}

bool EventsQueueSet::isEmpty()const {
    return (evtHeap.size()==0);
}

void EventsQueueSet::printSedCmd(const vector<_trans> &trlabl,ostream& df)const {
    if(evtHeap.size()>0){
        df << "-e 's/\\$CF_" << trlabl[InPosition(0).transition].label << "\\$/Red/g' ";
        for (unsigned int i = 1; i < evtHeap.size(); i++){
            df << "-e 's/\\$CF_" << trlabl[InPosition(i).transition].label << "\\$/Blue/g' ";
        }
    }
    df << "-e 's/\\$CF_[^\\$]*\\$/Black/g' ";
}

/**
 *	Print the content of the queues in a human readable format.
 */
void EventsQueueSet::view(const vector<_trans> &trlabl)const {
    cerr << "********** EVENTS-QUEUE VIEW **********" << endl;
    
    //cerr << "Qsize:" << evtHeap.size() << endl;
    
    if (evtHeap.size() == 0)
        cerr << "EVENTS-QUEUE is empty!" << endl;
    else
        for (unsigned int i = 0; i < evtHeap.size(); i++){
            Event e = InPosition(i);
            //cerr << "Equeue[" << i << "]:" << "( ";
            auto tr = trlabl[e.transition];
            if(tr.DistTypeIndex == IMMEDIATE)cerr << "\033[1;33m";
            cerr << setw(15) << left << tr.label << ":";
            //cerr << "tr ID:" << setw(4)<< e.transition << " ";
            e.binding.print();
            cerr << ",\tt=" << e.time << ",\tp=" << e.priority << ",\tw=" << e.weight;
            if(tr.DistTypeIndex == IMMEDIATE)cerr << "\033[0m";
            cerr << endl;
        }
}

size_t EventsQueueSet::getSize()const {
    return evtHeap.size();
}

