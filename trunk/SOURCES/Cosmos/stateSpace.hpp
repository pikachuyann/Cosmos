/*
 *   *  Cosmos
 *
 *  Created by Benoit Barbot on 01/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/*
 *	This class is used to compute the state space of the synchronized product
 * between the SPN and the LHA.
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

typedef hash_map<const vector<int>*, int , hashstate , eqstate > hash_state;
class stateSpace {
public:
	stateSpace();
	hash_state S;
	double findHash(const vector<int>* vect);	
	
	int nbState;
	int nbTrans;
	boost::numeric::ublas::compressed_matrix<double>* transitionsMatrix;
	boost::numeric::ublas::vector<double>* finalVector;
	
	void exploreStateSpace();
	void buildTransitionMatrix();
	double findState(const vector<int>*);
	
	SPN N; //The object representing the SPN
	LHA A; //The object representing the LHA
	
	void printP();
	void outputMat();
	void inputMat();
	
private:
	stack<pair<pair<vector<int>, vector<int> >,double > > transitionsList;
};

#endif