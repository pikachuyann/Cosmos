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
 * file EventsQueueLight.cpp created by Benoit Barbot on 4/02/2015.            *
 *******************************************************************************
 */


#include "EventsQueueLight.hpp"




/**
 *	Build an Event queue for the Petri net given as parameter.
 */
EventsQueue::EventsQueue(const SPN& N):heap_size(0){
    for(TR_PL_ID it = 0; it< N.tr; ++it ){
        evtHeapIndex[it]= -1;
        evtTbl[it].time = -1.0;
    }
}

/**
 * Clear the events queue. The resulting events queues does not contain any event.
 */
void EventsQueue::reset() {
    for(TR_PL_ID it = 0; it< heap_size; ++it ){
        evtHeapIndex[it]= -1;
        evtTbl[it].time = -1.0;
    }
    heap_size = 0;
    //Qsize = 0;
}

/*
 *	Insert a new event in the events queue and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueue::insert(const Event &e) {
    //assert(!isScheduled(e.transition, e.binding.id()));
    evtTbl[e.transition] = e;
    evtHeapIndex[e.transition] = heap_size;
    evtHeap[heap_size] = e.transition;
    heap_size++;

    siftUp(heap_size-1);
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
void EventsQueue::remove(TR_PL_ID tr) {
    long int i = evtHeapIndex[tr];
    evtTbl[tr].time = -1.0;
    //assert(i>=0);
    if(i>=0){
        if ((TR_PL_ID)i == heap_size-1) {
            evtHeapIndex[tr] = -1;
            heap_size--;
        } else {
            evtHeapIndex[evtHeap[heap_size-1]] = i;
            evtHeapIndex[tr] = -1 ;
            evtHeap[i] = evtHeap[heap_size-1];
            heap_size--;

            siftDown(i);
            siftUp(i);
        }
    }
}

const Event& EventsQueue::InPosition(TR_PL_ID i)const {
    //assert(i < evtHeap.size());
    return evtTbl[evtHeap[i]];
}

bool EventsQueue::isScheduled(TR_PL_ID tr)const {
    return (evtHeapIndex[tr] >= 0);
}







bool EventsQueue::isEmpty()const{
    return heap_size==0;
}

void EventsQueue::swapEvt(TR_PL_ID i,TR_PL_ID j){
    //assert((size_t)evtHeapIndex[evtHeap[j].first][evtHeap[j].second] ==j
    //	   && (size_t)evtHeapIndex[evtHeap[i].first][evtHeap[i].second] == i);
    evtHeapIndex[evtHeap[j]] = i;
    evtHeapIndex[evtHeap[i]] = j;

    TR_PL_ID swappair = evtHeap[j];
    evtHeap[j] = evtHeap[i];
    evtHeap[i] = swappair;
}

void EventsQueue::siftUp(TR_PL_ID i) {
    TR_PL_ID parentIndex;

    if (i != 0) {
        parentIndex = getParentIndex(i);

        if (InPosition(i).isPriorer(InPosition(parentIndex))){
            swapEvt(i, parentIndex);
            siftUp(parentIndex);
        }
    }
}

void EventsQueue::siftDown(TR_PL_ID i) {
    TR_PL_ID leftChildIndex, rightChildIndex, minIndex;
    leftChildIndex = getLeftChildIndex(i);
    rightChildIndex = getRightChildIndex(i);
    if (rightChildIndex >= heap_size) {
        if (leftChildIndex >= heap_size)
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



/**
 *	Print the content of the queues in a human readable format.
 */
/*void EventsQueue::view()const {
    print("********** EVENTS-QUEUE VIEW **********\n");

    //cerr << "Qsize:" << evtHeap.size() << endl;

    if (heap_size == 0)
        print("EVENTS-QUEUE is empty!\n");
    else
        for (TR_PL_ID i = 0; i < heap_size; i++){
            Event e = InPosition(i);
            print(e.transition);
            print(":\tt=");
            print(e.time);
            print(",\tp=");
            print(e.priority);
            print("\n");
        }
}*/



