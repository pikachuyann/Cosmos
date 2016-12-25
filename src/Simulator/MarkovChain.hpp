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
 * file MarkovChain.hpp created by Benoit Barbot on 13/12/2016.                *
 *******************************************************************************
 */

#ifndef MarkovChain_hpp
#define MarkovChain_hpp

#include <iostream>
#include <vector>
#include <array>

#include "timeGen.hpp"
#include "marking.hpp"

class Edge{
public:
    size_t Id;
    DistributionType DistTypeIndex;
    std::string label;
    std::array<abstractBinding, 1> bindingList;
};

template <class EQT>
class MarkovChain{
public:
    abstractMarking Marking;
    std::vector<Edge> Transition;
    
    size_t lastTransition;
    double lastTransitionTime;
    std::array<double,PARAM_TBL_SIZE> &ParamDistr;
    const CustomDistr& customDistr;
    
    MarkovChain():ParamDistr(*(new std::array<double, PARAM_TBL_SIZE>())),
                  customDistr(*(new CustomDistr())){};
    
    void reset();
    void initialEventsQueue(EQT &,timeGen &);
    void fire(size_t tr,const abstractBinding& b, double time);
    void update(double ctime,size_t, const abstractBinding&,EQT &,timeGen &);
private:
    
    void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &TG);
};


#endif /* MarkovChain_hpp */
