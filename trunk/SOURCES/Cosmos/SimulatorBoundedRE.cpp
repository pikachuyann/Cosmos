/*
 *  SimulatorBoudedRE.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorBoundedRE.hpp"
#include "numericalSolver.hpp"

using namespace std;

SimulatorBoundedRE::SimulatorBoundedRE(){
	numericalSolver numSolv;
	numSolv.computeMatrix();
	numSolv.initVect(20);
	
	exit(0);
	
}

