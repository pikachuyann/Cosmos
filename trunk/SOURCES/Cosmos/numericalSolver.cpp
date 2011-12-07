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
#include </usr/include/armadillo>
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
	cout << "N: " << nbState << endl;	
	
	mat T = zeros(nbState,nbState+1);
	boostmat::vector<double> vn = *finalVector;
	
	for (int i=0; i<= nbState; i++) {
		for (int j=0; j<nbState; j++)T(j,i) = vn(j);
		if(i<nbState)vn = boostmat::prod ((*transitionsMatrix),vn);
	}
	
	cout << T << endl;
	
	mat Q, R;
	qr(Q,R,trans(T));
	
	vec nullvec = Q.col(nbState);
	cout << "Q:" << endl << Q;
	cout << "R:" << endl << R;
	
	cout << "nv:" << endl << nullvec;
	
	//combine = new vector(nbState,0.0);
	/*for (int i=0; i<nbState; i++) {
		combine[i];
	}*/
	
	//cout << "Q * nullvec:" << endl << T* nullvec<< endl;
		
	
	//mat Q2 = Q.submat(0,n,m-1,m-1);
		
}

void numericalSolver::initVect(int nT){
	T=nT;
	boostmat::vector<double> itervect = *finalVector;
	for(int i=1; i<T-nbState-1 ; i++){
		itervect = boostmat::prod ((*transitionsMatrix),itervect);
	}
	cout << "itervect:" << T-nbState-1 << ":"<< itervect << endl;
	circularvect = new vector< boostmat::vector<double> > (nbState+1, itervect);
	(*circularvect)[0] = itervect;
	for(int i=1; i<=nbState ; i++){
		(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
		cout << "itervect:" << T-nbState-1+i << ":"<< (*circularvect)[i] << endl;
	}
	nbVect = T;
	matOffset = nbState;
	
}

boostmat::vector<double> numericalSolver::getVect(){
	return (*circularvect)[matOffset];
}

void numericalSolver::stepVect(){
	if (nbVect>=T-nbState){
		nbVect--;
		matOffset--;
	} else if (nbVect >0){
		int offsetm = (matOffset -1 + nbState) % nbState;
		for(int i=0; i< nbState; i++) (*circularvect)[offsetm](i)=0;
		for(int i= nbVect; i!=offsetm ; i= (i+1) % nbState){
			//(*circularvect)[i]+=
		}
		
	}
}













