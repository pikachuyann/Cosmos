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


#include "Event.hpp"

Event::Event() {
}

Event::Event(unsigned int tr, double t) {
    transition = tr;
    time = t;
}

Event::Event(unsigned int tr, double t, unsigned int pr, double w) {
    transition = tr;
    time = t;
    priority = pr;
    weight = w;
}

Event::Event(const Event& orig) {
    transition = orig.transition;
    time = orig.time;
    priority = orig.priority;
    weight = orig.weight;

}

Event::~Event() {
}

double Event::getTime() {
    return (this->time);
}

unsigned int Event::getPriority() {
    return (this->priority);
}

double Event::getWeight() {
    return (this->weight);
}

unsigned int Event::getTrans() {
    return (this->transition);
}

void Event::setTrans(int tr) {
    transition = tr;
}

void Event::setTime(double t) {
    time = t;
}

void Event::setPriority(unsigned int pr) {
    priority = pr;

}

void Event::setWeight(double w) {
    weight = w;

}