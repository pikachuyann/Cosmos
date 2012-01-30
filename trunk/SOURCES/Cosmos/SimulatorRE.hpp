/*
 *  SimulatorRE.hpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 09/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */


#include "Simulator.hpp"
#include "stateSpace.hpp"

#ifndef _SIMULATOR_RE_HPP
#define _SIMULATOR_RE_HPP



class SimulatorRE: public Simulator{
public:
	SimulatorRE(bool);
	SimulatorRE();
	
protected:
	
	//TAB muprob;  // mu(s) table
    stateSpace muprob;
    
	bool doubleIS_mode;
	
	virtual void InitialEventsQueue();
		
	virtual void returnResultTrue(vector<int>, double);
	virtual void returnResultFalse();
	virtual void updateSPN(int);
	virtual void GenerateEvent(Event &, int);
	virtual void GenerateDummyEvent(Event &, int);
	virtual void updateLikelihood(int);
	virtual vector<double> getParams(int);
	virtual void reset();
	
	virtual double mu();
	virtual double ComputeDistr(int i, double origin_rate);
};


#endif  /* _SIMULATOR_RE_HPP */

