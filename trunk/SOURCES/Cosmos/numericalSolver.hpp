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
namespace boostmat = boost::numeric::ublas;

class numericalSolver: public stateSpace
{
protected:
	vector<boostmat::vector<double> >* circularvect;
	int matOffset;
	int nbVect;
	
public:
	numericalSolver();
	void initVect(int);
	int T;
	void reset();
	boostmat::vector<double> getVect();
	double getMu(int);
	void previousVect();
	void stepVect();
	
};




#endif