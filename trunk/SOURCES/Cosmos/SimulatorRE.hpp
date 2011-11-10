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


class SimulatorRE: public Simulator{
public:
	SimulatorRE(bool);
	void SimulateSinglePath();
	void InitialEventsQueue();
		
	void returnResult(double);
	void updateLHA(AutEdge);
	void GenerateEvent(Event &, int);
	void GenerateDummyEvent(Event &, int);
private:
	bool doubleIS_mode;
};


#endif  /* _SIMULATOR_RE_HPP */

