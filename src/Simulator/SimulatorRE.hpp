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
#include "spn_orig.hpp"

#ifndef _SIMULATOR_RE_HPP
#define _SIMULATOR_RE_HPP

class SPN_RE: public SPN_orig{
public:
    SPN_RE(int& v,bool doubleIS);

    bool rareEventEnabled;

    using SPN_orig::initialize;
    virtual void initialize(EventsQueue *eq,timeGen *tg, stateSpace *muprob);
    virtual void GenerateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b )override;
    virtual void update(double ctime,size_t, const abstractBinding& )override;
    virtual void InitialEventsQueue()override;

    virtual double mu();
    const bool doubleIS_mode;

protected:
    stateSpace * muprob;

private:
    virtual void getParams(size_t,const abstractBinding&);
    virtual double ComputeDistr(size_t i,const abstractBinding& , double origin_rate);
};


class SimulatorRE: public Simulator{
public:
	SimulatorRE(SPN_orig&,LHA_orig&);
	
	virtual void initVect();
	
protected:

    //TAB muprob;  // mu(s) table
    stateSpace * muprob;

	virtual void SimulateSinglePath() override;
	virtual void returnResultTrue() override;
	//virtual void GenerateDummyEvent(Event &, size_t);
	virtual void updateLikelihood(size_t) override;
    virtual bool transitionSink(size_t) override;
	virtual void reset() override;
	

};


#endif  /* _SIMULATOR_RE_HPP */

