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
public:
	numericalSolver();
	void computeMatrix();
	void initVect(int);
	vector<double>* combine;
	
	vector<boostmat::vector<double> >* circularvect;
	int T;
	int nbVect;
	int matOffset;
	boostmat::vector<double> getVect();
	void stepVect();
	
};




#endif