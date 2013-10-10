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
 * file SimulatorRE.hpp created by Benoit Barbot on 09/11/11.                  *
 *******************************************************************************
 */


#include "Simulator.hpp"
#include "stateSpace.hpp"

#ifndef _SIMULATOR_RE_HPP
#define _SIMULATOR_RE_HPP



class SimulatorRE: public Simulator{
public:
	SimulatorRE(bool);
	SimulatorRE();
	
	virtual void initVect();
	
protected:
	
	//TAB muprob;  // mu(s) table
    stateSpace muprob;
    
	bool doubleIS_mode;
	
	virtual void InitialEventsQueue();
	
	virtual void returnResultTrue();
	virtual void returnResultFalse();
	virtual void updateSPN(size_t,const abstractBinding&);
	virtual void GenerateEvent(Event &,size_t,const abstractBinding& );
	//virtual void GenerateDummyEvent(Event &, size_t);
	virtual void updateLikelihood(size_t);
    virtual bool transitionSink(size_t);
	virtual void getParams(size_t,const abstractBinding&);
	virtual void reset();
	
	virtual double mu();
	virtual double ComputeDistr(size_t i,const abstractBinding& , double origin_rate);
};


#endif  /* _SIMULATOR_RE_HPP */

