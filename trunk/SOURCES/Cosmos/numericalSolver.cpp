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
	cerr << "N: " << nbState << endl;	
	
	int nbState2 = nbState;
	
	mat T = zeros(nbState,nbState2);
	boostmat::vector<double> vn = *finalVector;
	
	for (int i=0; i< nbState2; i++) {
		for (int j=0; j<nbState; j++)T(j,i) = vn(j);
		if(i<nbState2)vn = boostmat::prod ((*transitionsMatrix),vn);
	}
	
	cerr << T << endl;
	
	mat Q, R;
	qr(Q,R,trans(T));
	
	vec nullvec = Q.col(nbState2-1);
	cerr << "Q:" << endl << Q;
	cerr << "R:" << endl << R;
	
	double beta0=0;
	for(int i = nbState-1; i>=0;i--){
		beta0+= nullvec(i);
		cout << "beta0 : " << beta0 << endl;
	}
	double somme = beta0;
	for(int i = nbState-1; i>=0;i--){
		somme -= nullvec(i);
		
		cout << "beta2 : " << nullvec(i) - somme << endl;
	}
	
	
	
	
	
	//nullvec /= (-nullvec(0));
	
	combineLin = nullvec;
	
	cerr << "nv:" << endl << nullvec;
	
	//combine = new vector(nbState,0.0);
	/*for (int i=0; i<nbState; i++) {
		combine[i];
	}*/
	
	cerr << "Q * nullvec:" << endl << T* nullvec<< endl;
		
	
	//mat Q2 = Q.submat(0,n,m-1,m-1);
		
}

void numericalSolver::initVect(int nT){
	T=nT;
	vectortest = new vector< boostmat::vector<double> > (T+1);
	
	boostmat::vector<double> itervect = *finalVector;
	for(int i=0; i<T-nbState-1 ; i++){
		cerr << "itervect:" << i << ":"<< itervect << endl;
		(*vectortest)[i]= itervect;
		itervect = boostmat::prod ((*transitionsMatrix),itervect);
	}
	
	(*vectortest)[T-nbState-1]= itervect;
	
	cerr << "itervect:" << T-nbState-1 << ":"<< itervect << endl;
	circularvect = new vector< boostmat::vector<double> > (nbState+1, itervect);
	(*circularvect)[0] = itervect;
	for(int i=1; i<=nbState ; i++){
		(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
		(*vectortest)[T-nbState+i-1]= (*circularvect)[i];
		cerr << "itervect:" << T-nbState+i-1 << ":"<< (*circularvect)[i] << endl;
	}
	nbVect = T;
	matOffset = nbState;
	
}

boostmat::vector<double> numericalSolver::getVect(){
	cout << nbVect-1 << " , ";
	cout << boostmat::norm_1 ((*circularvect)[matOffset] - (*vectortest)[nbVect-1]) << endl;
	
	return (*circularvect)[matOffset];
}

void numericalSolver::stepVect(){
	if (nbVect>T-nbState){
		nbVect--;
		matOffset--;
	} else if (nbVect >0){
		int offsetm = (matOffset -1 + nbState) % nbState;
		for(int i=0; i< nbState; i++) (*circularvect)[offsetm](i)=0;
		for(int i= 1; i!=nbState ; i++){
			if(combineLin(i)>0 ){
				(*circularvect)[offsetm] += combineLin(i) * (*circularvect)[(offsetm +i) % nbState ]; 
			}
		}
		for(int i= 1; i!=nbState ; i++){
			if(combineLin(i)<0){
			(*circularvect)[offsetm] += combineLin(i) * (*circularvect)[(offsetm +i) % nbState ]; 
			}
		}
		(*circularvect)[offsetm] /= (-combineLin(0));
		//cerr << "vect: " <<  (*circularvect)[offsetm] << endl;
		matOffset = offsetm;
		nbVect--;
	}
}













