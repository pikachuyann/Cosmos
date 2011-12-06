/*
 *  numericalSolver.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 05/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "numericalSolver.hpp"

#include <iostream>
#include <armadillo>
#include <time.h>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace arma;
using namespace std;


numericalSolver::numericalSolver(){
	exploreStateSpace();
	buildTransitionMatrix();
	printP();
}

void numericalSolver::computeMatrix(){
	int N = transitionsMatrix->size1();
	
	cout << "N:" << N << endl;
	
	mat T = zeros(N,N+1);
	boost::numeric::ublas::vector<double> vn = *finalVector;
	
	for (int i=0; i< N+1; i++) {
		for (int j=0; j<N; j++)T(j,i) = vn(j);
		if(i<N)vn = boost::numeric::ublas::prod ((*transitionsMatrix),vn);
	}
	
	cout << T << endl;
	
	mat Q, R;
	qr(Q,R,trans(T));
	
	vec nullvec = Q.col(N);
	cout << "Q:" << endl << Q;
	cout << "R:" << endl << R;
	
	cout << "nv:" << endl << nullvec;
	
	cout << "Q * nullvec:" << endl << T* nullvec<< endl;
		
	
	//mat Q2 = Q.submat(0,n,m-1,m-1);
	
	
		
	
}