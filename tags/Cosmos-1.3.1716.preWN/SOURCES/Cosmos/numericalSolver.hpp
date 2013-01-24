/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 * file numericalSolver.hpp created by Benoit Barbot on 05/12/11.              *
 *******************************************************************************
 */

/*
 *  This class implement some function of a numerical solver.
 *  It is used to compute Bounded Until importance sampling.
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
    void sparseProd(boostmat::vector<double> *result,boostmat::vector<double> *vect, boostmat::compressed_matrix<double> *mat);
	int minT;
    
public:
	numericalSolver();
    virtual int getMinT(){return minT;};
	virtual void initVect(int T); //initialise for an horizon point T
	int T;
	virtual void reset(); //this function is call before each batch
	virtual boostmat::vector<double> getVect(); 
	virtual double getMu(int);
	virtual void previousVect();
	virtual void stepVect();
	
};




#endif
