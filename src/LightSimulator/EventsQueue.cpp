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

#include "EventsQueue.hpp"
#include "Event.hpp"

using namespace std;

/**
 *	Build an Event queue for the Petri net given as parameter.
 */
EventsQueue::EventsQueue(const SPN& N):evtTbl(N.tr,Event()){
    for(size_t it = 0; it< N.tr; ++it ){
            //evtTbl.push_back(vector<Event>());
		evtHeapIndex.push_back(-1);
	}
    evtHeap.reserve(N.tr);
}

/**
 * Clear the events queue. The resulting events queues does not contain any event.
 */
void EventsQueue::reset() {
    for(size_t it = 0; it< evtHeapIndex.size(); ++it ){
			evtHeapIndex[it]= -1;
			evtTbl[it].time = -1.0;
    }
	evtHeap.clear();
	//Qsize = 0;
}

/**
 * Copy of events queue
 */
EventsQueue::EventsQueue(const EventsQueue& orig) {
    
    //Qsize = orig.Qsize;
	
	evtTbl = orig.evtTbl;
	evtHeap = orig.evtHeap;
	evtHeapIndex = orig.evtHeapIndex;
	
	/*eq = orig.eq;
	 TransTableSize = orig.TransTableSize;
	 TransTable = orig.TransTable;*/
}

EventsQueue::~EventsQueue() {
}

/*
 *	Insert a new event in the events queue and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueue::insert(const Event &e) {
	//assert(!isScheduled(e.transition, e.binding.id()));
	evtTbl[e.transition] = e;
	evtHeapIndex[e.transition] = evtHeap.size();
	evtHeap.push_back(e.transition);
	
	siftUp(evtHeap.size()-1);
}

/*
 *	Replace the time, priority,service of an event and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueue::replace(const Event &e) {
	//assert(isScheduled(e.transition, e.binding.id()));
	long int k = evtHeapIndex[e.transition];
	evtTbl[e.transition] = e;
	
	siftUp(k);
	siftDown(k);
}

/*
 *	Remove an event and update the tree.
 *  @param tr a transition of the Petri net.
 *  @param b a binding of the Petri net.
 */
void EventsQueue::remove(size_t tr) {
	long int i = evtHeapIndex[tr];
	evtTbl[tr].time = -1.0;
	//assert(i>=0);
	if(i>=0){
		if ((size_t)i == evtHeap.size()-1) {
			evtHeapIndex[tr] = -1;
			evtHeap.pop_back();
		} else {
			evtHeapIndex[evtHeap.back()] = i;
			evtHeapIndex[tr] = -1 ;
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
void EventsQueue::pause(double t, size_t tr){
	evtTbl[tr].time -= t;
	long int i = evtHeapIndex[tr];
	//assert(i>=0);
	if(i>=0){
		if ((size_t)i == evtHeap.size()-1) {
			evtHeapIndex[tr] = -1;
			evtHeap.pop_back();
		} else {
			evtHeapIndex[evtHeap.back()] = i;
			evtHeapIndex[tr] = -1 ;
			evtHeap[i] = evtHeap.back();
			evtHeap.pop_back();
			
			siftDown(i);
			siftUp(i);
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
bool EventsQueue::restart(double t, size_t tr){
	if(evtTbl[tr].time < 0.0)return false;
	evtTbl[tr].time += t;
	evtHeapIndex[tr] = evtHeap.size();
	evtHeap.push_back(tr);
	
	siftUp(evtHeap.size()-1);
	return true;
}

const Event& EventsQueue::InPosition(size_t i)const {
	//assert(i < evtHeap.size());
    return evtTbl[evtHeap[i]];
}

bool EventsQueue::isScheduled(size_t tr)const {
	return (evtHeapIndex[tr] >= 0);
}

void EventsQueue::swapEvt(size_t i,size_t j){
	//assert((size_t)evtHeapIndex[evtHeap[j].first][evtHeap[j].second] ==j
	//	   && (size_t)evtHeapIndex[evtHeap[i].first][evtHeap[i].second] == i);
	evtHeapIndex[evtHeap[j]] = i;
	evtHeapIndex[evtHeap[i]] = j;
	
	size_t swappair = evtHeap[j];
	evtHeap[j] = evtHeap[i];
	evtHeap[i] = swappair;
}

void EventsQueue::siftUp(size_t i) {
    size_t parentIndex;
	
    if (i != 0) {
        parentIndex = getParentIndex(i);
		
		if (InPosition(i).isPriorer(InPosition(parentIndex))){
			swapEvt(i, parentIndex);
			siftUp(parentIndex);
		}
	}
}

void EventsQueue::siftDown(size_t i) {
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

bool EventsQueue::isEmpty()const {
    return (evtHeap.size()==0);
}

size_t EventsQueue::getSize()const {
    return evtHeap.size();
}

