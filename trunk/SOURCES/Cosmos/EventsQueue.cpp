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
#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;


EventsQueue::EventsQueue(const SPN& N){
	for(size_t it = 0; it< N.Transition.size(); ++it ){
		evtTbl.push_back(vector<Event>());
		evtHeapIndex.push_back(vector<int>(N.Transition[it].bindingList.size(),-1));
		for (size_t it2 = 0 ; it2< N.Transition[it].bindingList.size(); ++it2) {
			evtTbl[it].push_back(Event());
		}
	}
}


void EventsQueue::reset() {
	for(size_t it = 0; it< evtHeapIndex.size(); ++it )
		for(size_t it2 = 0; it2< evtHeapIndex[it].size(); ++it2 )
			evtHeapIndex[it][it2]= -1;
	evtHeap.clear();
	//Qsize = 0;
}

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

void EventsQueue::insert(const Event &e) {
	assert(!isScheduled(e.transition, e.binding.id()));
	evtTbl[e.transition][e.binding.id()] = e;
	evtHeapIndex[e.transition][e.binding.id()] = evtHeap.size();
	evtHeap.push_back(make_pair(e.transition,e.binding.id()));
	
	siftUp(evtHeap.size()-1);
}

void EventsQueue::replace(const Event &e) {
	assert(isScheduled(e.transition, e.binding.id()));
	int k = evtHeapIndex[e.transition][e.binding.id()];
	evtTbl[e.transition][e.binding.id()] = e;
	
	siftUp(k);
	siftDown(k);
}

void EventsQueue::remove(size_t tr, size_t b) {
	int i = evtHeapIndex[tr][b];
	assert(i>=0);
	if(i>=0){
		if (i == evtHeap.size()-1) {
			evtHeapIndex[tr][b] = -1;
			evtHeap.pop_back();
		} else {
			evtHeapIndex[evtHeap.back().first][evtHeap.back().second] = i;
			evtHeapIndex[tr][b] = -1 ;
			evtHeap[i] = evtHeap.back();
			evtHeap.pop_back();
			
			siftDown(i);
			siftUp(i);
		}
	}
}

const Event& EventsQueue::InPosition(size_t i)const {
    return evtTbl[evtHeap[i].first][evtHeap[i].second];
}

bool EventsQueue::isScheduled(size_t tr,size_t b)const {
	return (evtHeapIndex[tr][b] >= 0);
}

void EventsQueue::swapEvt(size_t i,size_t j){
	assert(evtHeapIndex[evtHeap[j].first][evtHeap[j].second] ==j
		   && evtHeapIndex[evtHeap[i].first][evtHeap[i].second] == i);
	evtHeapIndex[evtHeap[j].first][evtHeap[j].second] = i;
	evtHeapIndex[evtHeap[i].first][evtHeap[i].second] = j;
	
	pair<size_t,size_t> swappair = evtHeap[j];
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

bool EventsQueue::isEmpty() {
    return (evtHeap.size()==0);
}

void EventsQueue::view() {
    cerr << "********** EVENTS-QUEUE VIEW **********" << endl;
	
    cerr << "Qsize:" << evtHeap.size() << endl;
	
    if (evtHeap.size() == 0)
        cerr << "EVENTS-QUEUE is empty!" << endl;
    else
        for (unsigned int i = 0; i < evtHeap.size(); i++){
			Event e = InPosition(i);
            cerr << "Equeue[" << i << "]:" << "( tId" << e.transition << " ";
			e.binding.print();
			cerr << ",t=" << e.time << ", p=" << e.priority << ", w=" << e.weight << " ,";
			cerr << ")" << endl;
		}
}

/*
int EventsQueue::TransTabValue(int i) {
    return TransTable[i];
}

void EventsQueue::UpdateTransTab(int trans, int value) {
	
    TransTable[trans] = value;
	
}

void EventsQueue::ViewTransTab() {
    cout << "Position of transitions in the heap:" << endl;
	
    for (size_t i = 0; i < TransTableSize; i++)
        cout << "Trans[" << i + 1 << "]=" << TransTable[i] << endl;
	
}*/

size_t EventsQueue::getSize()const {
    return evtHeap.size();
}

