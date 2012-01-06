/*
 *  numericalSolverBB.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/01/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "numericalSolver.hpp"

class numSolverBB: public numericalSolver{
public:
	void initVect(int);
	void previousVect();
	void stepVect();
	void reset();

protected:
	
	vector<boostmat::vector<double> >* checkPoint;
	int l;
	int u;
	int lastCP;
	
};