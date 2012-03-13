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
    EventsQueue(int);

    EventsQueue(const EventsQueue& orig);
    virtual ~EventsQueue();

    void insert(Event &);
    void replace(Event &, int);
    void remove(int);
    void siftUp(int);
    void siftDown(int);

    bool isEmpty();
    void copyEvents(Event&, Event&);
    void view();
    bool isPriorer(Event&, Event&);

    int TransTabValue(int);
    void UpdateTransTab(int, int);
    void ViewTransTab();

    void reset();
    int getSize();

    EQueue* getEq();



    Event InPosition(int);
    EQueue* eq;
private:

    EQit* it;
    int Qsize;



    Tab* TransTable;
    int TransTableSize;

    int getLeftChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 1;
    }

    int getRightChildIndex(int nodeIndex) {
        return 2 * nodeIndex + 2;
    }

    int getParentIndex(int nodeIndex) {
        return (nodeIndex - 1) / 2;
    }


};


#endif	/* _EVENTSQUEUE_HPP */

