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
 * file EventsQueueLight.hpp created by Benoit Barbot on 4/02/2015.            *
 *******************************************************************************
 */

#include "Event.hpp"
#include "spnLight.hpp"

#ifndef __Cosmos__EventsQueueLight__
#define __Cosmos__EventsQueueLight__


class EventsQueue {
public:
    //EventsQueue(size_t);
    EventsQueue(const SPN& N);

    void insert(const Event &);
    void replace(const Event &);
    void remove(size_t);
    bool isScheduled(size_t)const;

    bool isEmpty()const;

    void reset();
    size_t getSize()const ;


    const Event& InPosition(size_t)const ;

private:
    Event fstEvent;
    bool isempty;

};


#endif /* defined(__Cosmos__EventsQueueLight__) */
