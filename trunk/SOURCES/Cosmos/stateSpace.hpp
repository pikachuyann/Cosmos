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
 * file stateSpace.hpp created by Benoit Barbot on 01/12/11.                   *
 *******************************************************************************
 */

/*
 *	This class is used to compute the state space of the synchronized product
 * between the SPN and the LHA.
 *
 * This class also export and import this state space and the transition matrix
 *
 */

#include <set>
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <cstring>
#include "LHA.hpp"
#include "spn.hpp"

#include <iostream>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/io.hpp>

//using namespace arma;
using namespace std;

#ifdef __GNUC__
#include <ext/hash_map>
#else
#include <hash_map>
#endif


#ifndef _STATESPACE_HPP
#define	_STATESPACE_HPP

using namespace __gnu_cxx;

struct eqstate{
	bool operator()(const vector<int>* t1,const vector<int>* t2) const {
		for(int it=0; it < t1->size() ; it++)
			if((*t1)[it] != (*t2)[it]) return false;
		return true;
	}
};

struct hashstate{
	int operator()(const vector<int>* t1) const {
		int h = 0;
		for(int it=0; it < t1->size() ; it++)
			h = h * 524287 + (*t1)[it];
		return h;
	}
};

/* 
 * The hash_map structure implement a mapping between a state as a vector
 * of integer and its indice.
 */
typedef hash_map<const vector<int>*, int , hashstate , eqstate > hash_state;

/*
 * This class manage the state space of the model. The state space is
 * stored as a mapping between the states and [0..nbState] the number of state.
 * This class can generate the state space by exploring it.
 *
 */
class stateSpace {
public:
	stateSpace();
	hash_state S;
    vector<const vector<int>* > revertHash;
	double findHash(const vector<int>* vect);	
    
	int nbState;
	int nbTrans;
	boost::numeric::ublas::compressed_matrix<double>* transitionsMatrix;
	boost::numeric::ublas::vector<double>* finalVector;
    vector<double>* muvect;
    
	void exploreStateSpace();
	void buildTransitionMatrix();
		
	SPN N; //The object representing the SPN
	LHA A; //The object representing the LHA
	
    //double maxRate();
    double uniformizeMatrix();
    
	void printP();
	void outputMat();
	void inputMat();
    void inputVect();
    void outputPrism();
	
private:
    vector<vector<int> > *findstate;
    void add_state(vector<int> v);
};

#endif