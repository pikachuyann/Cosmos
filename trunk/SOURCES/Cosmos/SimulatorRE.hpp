/*
 *  SimulatorRE.hpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 09/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Simulator.hpp"
#include "tab.hpp"

#ifndef _SIMULATOR_RE_HPP
#define _SIMULATOR_RE_HPP

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */


class SimulatorRE: public Simulator{
public:
	SimulatorRE(bool);
	SimulatorRE();
	
protected:
	
	TAB muprob;  // mu(s) table
	
	bool doubleIS_mode;
	
	void InitialEventsQueue();
		
	void returnResultTrue(vector<int>, double);
	void returnResultFalse();
	void updateSPN(int);
	void GenerateEvent(Event &, int);
	void GenerateDummyEvent(Event &, int);
	void updateLikelihood(int);
	vector<double> getParams(int);
	
	double mu();
	double ComputeDistr(int i, double origin_rate);
};


#endif  /* _SIMULATOR_RE_HPP */

