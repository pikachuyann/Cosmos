/*
 *  numericalSolver.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 05/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _NUMERICAL_SOLVER_HPP
#define	_NUMERICAL_SOLVER_HPP

#include "stateSpace.hpp"

class numericalSolver: public stateSpace
{
public:
	numericalSolver();
	void computeMatrix();
};




#endif