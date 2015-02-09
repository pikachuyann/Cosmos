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

#include "Event.hpp"


Event::Event() : transition(0), time(-1.0){}
Event::Event(TR_PL_ID tr, REAL_TYPE t): transition(tr),time(t){}

const Event& Event::operator = (const Event& orig){
	transition = orig.transition;
	time = orig.time;
	return *this;
}

bool Event::isPriorer(const Event& e)const {
    //smallest time is priorer
    if (time > e.time) return false;
    if (time < e.time) return true;
    // if not(< or >) so it is =
    // highest priority is priorer
    if (getPr(transition) < getPr(e.transition)) return false;
    else return true;
}
