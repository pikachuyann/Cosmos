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
 * file InstanceSPNSim.cpp created by Benoît Barbot on 19/01/2017.             *
 *******************************************************************************
 */


//   Classes in SPNBase
#include "SPNBase.cpp"

template class SPNBase<SPN_orig<EventsQueue<vector<_trans>>>,EventsQueue<vector<_trans>>>;
template class SPNBase<SPN_orig<EventsQueueSet>,EventsQueueSet>;
template class SPN_orig<EventsQueue<vector<_trans>>>;
template class SPN_orig<EventsQueueSet>;

#include "SimulatorBoundedRE.hpp"
template class SPNBase<SPN_RE,EventsQueue<vector<_trans>>>;
template class SPNBase<SPN_BoundedRE,EventsQueue<vector<_trans>>>;


//    Classes in Simulator
#include "Simulator.cpp"

template class SimulatorBase<Simulator<EventsQueue<vector<_trans>>,SPN_orig<EventsQueue<vector<_trans>>>>, EventsQueue<vector<_trans>>,SPN_orig<EventsQueue<vector<_trans>>> >;
template class SimulatorBase<Simulator<EventsQueueSet,SPN_orig<EventsQueueSet>>, EventsQueueSet,SPN_orig<EventsQueueSet> >;
template class Simulator<EventsQueue<vector<_trans>>,SPN_orig<EventsQueue<vector<_trans>>> >;
template class Simulator<EventsQueueSet,SPN_orig<EventsQueueSet> >;

#include "SimulatorRE.hpp"
template class SimulatorBase<SimulatorRE<SPN_RE>, EventsQueue<vector<_trans>>,SPN_RE>;

#include "SimulatorBoundedRE.hpp"
template class SimulatorBase<SimulatorBoundedRE<SPN_BoundedRE>, EventsQueue<vector<_trans>>,SPN_BoundedRE>;
template class SimulatorBase<SimulatorBoundedRE<SPN_RE>, EventsQueue<vector<_trans>>,SPN_RE>;


#include "SimulatorContinuousBounded.hpp"
template class SimulatorBase<SimulatorContinuousBounded<SPN_BoundedRE>, EventsQueue<vector<_trans>>,SPN_BoundedRE>;


// Classes in SimulatorRE
#include "SimulatorRE.cpp"

template class SimulatorREBase<SimulatorRE<SPN_RE>, SPN_RE>;
template class SimulatorRE<SPN_RE>;
template class SPNBaseRE<SPN_RE>;

template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPNBaseRE<SPN_RE> &);
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPN_RE &);

#include "SimulatorBoundedRE.hpp"
template class SimulatorREBase<SimulatorBoundedRE<SPN_RE>, SPN_RE>;
template class SimulatorREBase<SimulatorBoundedRE<SPN_BoundedRE>, SPN_BoundedRE>;
template class SPNBaseRE<SPN_BoundedRE>;
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPNBaseRE<SPN_BoundedRE> &);
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPN_BoundedRE &);

#include "SimulatorContinuousBounded.hpp"
template class SimulatorREBase<SimulatorContinuousBounded<SPN_BoundedRE>, SPN_BoundedRE>;

//  Classes in SimulatorBounded
#include "SimulatorBoundedRE.cpp"
template class SimulatorBoundedREBase<SimulatorBoundedRE<SPN_BoundedRE>,SPN_BoundedRE>;
template class SimulatorBoundedRE<SPN_BoundedRE>;
template class SPNBaseBoundedRE<SPN_BoundedRE>;

#include "SimulatorContinuousBounded.hpp"
template class SimulatorBoundedREBase<SimulatorContinuousBounded<SPN_BoundedRE>,SPN_BoundedRE>;

//  Classes in SimulatorContinuousBounded
#include "SimulatorContinuousBounded.cpp"
template class SimulatorContinuousBounded<SPN_BoundedRE>;

