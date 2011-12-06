/*
 *  SimulatorBoudedRE.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorRE.hpp"


#ifndef _SIMULATOR_BOUNDED_RE_HPP
#define _SIMULATOR_BOUNDED_RE_HPP

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */


class SimulatorBoundedRE: public SimulatorRE{
public:
	SimulatorBoundedRE();
	
};


#endif  /* _SIMULATOR_BOUNDED_RE_HPP */
