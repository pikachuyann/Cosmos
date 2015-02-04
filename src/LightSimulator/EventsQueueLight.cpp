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
EventsQueue::EventsQueue(const SPN&):fstEvent(Event()),isempty(true){
}

/**
 * Clear the events queue. The resulting events queues does not contain any event.
 */
void EventsQueue::reset() {
    isempty=true;
}

/*
 *	Insert a new event in the events queue and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueue::insert(const Event &e) {
    if(isempty){
        fstEvent=e;
        isempty=false;
    }else{
        if(e.isPriorer(fstEvent))fstEvent=e;
    }
}

/*
 *	Replace the time, priority,service of an event and update the tree.
 *  @param e an event of the Petri net.
 */
void EventsQueue::replace(const Event &e) {
    if (!isempty && e.isPriorer(fstEvent)) {
        fstEvent =e;
    }
}

/*
 *	Remove an event and update the tree.
 *  @param tr a transition of the Petri net.
 *  @param b a binding of the Petri net.
 */
void EventsQueue::remove(size_t tr) {
    if (!isempty && fstEvent.transition==tr) {
        isempty=true;
    }
}

bool EventsQueue::isEmpty()const{
    return isempty;
}

const Event& EventsQueue::InPosition(size_t)const {
    return fstEvent;
}

bool EventsQueue::isScheduled(size_t tr)const {
    return (fstEvent.transition == tr && !isempty);
}
