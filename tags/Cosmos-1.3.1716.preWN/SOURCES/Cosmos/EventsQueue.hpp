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

#include <vector>
#include "Event.hpp"


#ifndef _EVENTSQUEUE_HPP
#define	_EVENTSQUEUE_HPP

using namespace std;

typedef vector <int> Tab;
typedef vector <Event> EQueue;
typedef vector <Event>::iterator EQit;

class EventsQueue {
public:
    EventsQueue(EQueue *);
    EventsQueue(size_t);

    EventsQueue(const EventsQueue& orig);
    virtual ~EventsQueue();

    void insert(Event &);
    void replace(Event &, size_t);
    void remove(size_t);
    void siftUp(size_t);
    void siftDown(size_t);

    bool isEmpty();
    void copyEvents(Event&, Event&);
    void view();
    bool isPriorer(Event&, Event&);

    int TransTabValue(int);
    void UpdateTransTab(int, int);
    void ViewTransTab();

    void reset();
    size_t getSize();

    EQueue* getEq();



    Event InPosition(int);
    EQueue* eq;
private:

    EQit* it;
    size_t Qsize;



    Tab* TransTable;
    size_t TransTableSize;

    size_t getLeftChildIndex(size_t nodeIndex) {
        return 2 * nodeIndex + 1;
    }

    size_t getRightChildIndex(size_t nodeIndex) {
        return 2 * nodeIndex + 2;
    }

    size_t getParentIndex(size_t nodeIndex) {
        return (nodeIndex - 1) / 2;
    }


};


#endif	/* _EVENTSQUEUE_HPP */

