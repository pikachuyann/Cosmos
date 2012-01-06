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
	virtual void initVect(int T); //initialise for an horizon point T
	int T;
	virtual void reset(); //this function is call before each batch
	virtual boostmat::vector<double> getVect(); 
	virtual double getMu(int);
	virtual void previousVect();
	virtual void stepVect();
	
};




#endif