/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *                                                                             *
 *******************************************************************************
 */



#ifndef _EVENT_HPP
#define	_EVENT_HPP

class Event {
public:
    Event();
    Event(unsigned int, double);
    Event(unsigned int, double, unsigned int, double);
    Event(const Event& orig);
    virtual ~Event();
    unsigned int getTrans();
    double getTime();
    unsigned int getPriority();
    double getWeight();
    void setTrans(int);
    void setTime(double);
    void setPriority(unsigned int);
    void setWeight(double);


    unsigned int transition;
    double time;
    unsigned int priority;
    double weight;

private:


};


#endif	/* _EVENT_HPP */

