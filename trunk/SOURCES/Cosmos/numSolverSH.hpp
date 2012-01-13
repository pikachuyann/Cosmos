/*
 *  numSolverSH.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/01/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "numericalSolver.hpp"

class numSolverSH: public numericalSolver{
public:
	void initVect(int);
	void previousVect();
	void stepVect();
	void reset();
	double getMu(int);
	boostmat::vector<double> getVect(); 
protected:
	vector<boostmat::vector<double> >* powTVect;
	vector<boostmat::vector<double> >* lastOne;
    vector<double>* ktable; 
	int l;
	int u;
	int lastPowT;
    void compPow(int,int);
	
	bool is_previous;

	boostmat::vector<double> current_vect;
	boostmat::vector<double> previous_vect;
};