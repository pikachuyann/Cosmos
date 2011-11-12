/*
 *  SimulatorRE.hpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 09/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Simulator.hpp"


#ifndef _SIMULATOR_RE_HPP
#define _SIMULATOR_RE_HPP

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */


class SimulatorRE: public Simulator{
public:
	SimulatorRE(bool);
	
protected:
	bool doubleIS_mode;
	
	void InitialEventsQueue();
		
	void returnResultTrue(vector<int>, double);
	void returnResultFalse();
	void updateSPN(int);
	void GenerateEvent(Event &, int);
	void GenerateDummyEvent(Event &, int);
	void updateLikelihood(int);
	
};


#endif  /* _SIMULATOR_RE_HPP */

