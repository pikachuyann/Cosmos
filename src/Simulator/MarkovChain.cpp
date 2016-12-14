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
 * file MarkovChain.cpp created by Benoit Barbot on 13/12/2016.                *
 *******************************************************************************
 */

#include <vector>

#include "EventsQueue.hpp"
#include "MarkovChain.hpp"

template<class EQT>
void MarkovChain<EQT>::initialEventsQueue(EQT &EQ, timeGen &tg){
    Event E;
    generateEvent(0.0,E, 0 ,abstractBinding() ,tg);
    EQ.insert(E);
}

template<class EQT>
void MarkovChain<EQT>::fire(size_t tr,const abstractBinding& b, double time){
}

template<class EQT>
void MarkovChain<EQT>::reset(){}

template<class EQT>
void MarkovChain<EQT>::update(double ctime,size_t, const abstractBinding&,EQT &,timeGen &){}


template<class EQT>
void MarkovChain<EQT>::generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &TG){

}



template class MarkovChain<EventsQueue<std::vector<Edge>>>;
