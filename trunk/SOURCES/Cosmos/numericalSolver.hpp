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

#include </usr/include/armadillo>
#include "stateSpace.hpp"
namespace boostmat = boost::numeric::ublas;
using namespace arma;

class numericalSolver: public stateSpace
{
public:
	numericalSolver();
	void computeMatrix();
	void initVect(int);
	vector<double>* combine;
	
	vec combineLin;
	vector<boostmat::vector<double> >* circularvect;
	vector<boostmat::vector<double> >* vectortest;
	int T;
	int nbVect;
	int matOffset;
	boostmat::vector<double> getVect();
	void stepVect();
	
};




#endif