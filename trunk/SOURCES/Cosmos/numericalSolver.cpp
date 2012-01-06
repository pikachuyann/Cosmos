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
#include <fstream>
#include <time.h>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace std;


numericalSolver::numericalSolver(){
	inputMat();
}


void numericalSolver::initVect(int nT){
	T=nT;
	circularvect = new vector< boostmat::vector<double> > (nT+1, *finalVector);
	(*circularvect)[0] = *finalVector;
	//cerr << "itervect:" << 0 << ":"<< (*circularvect)[0] << endl;
	for(int i=1; i<=nT ; i++){
		(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
		//cerr << "itervect:" << i << ":"<< (*circularvect)[i] << endl;
	}
	nbVect = nT;
	matOffset = nT;
	
}

void numericalSolver::reset(){
	matOffset=T;
	//cerr << (*circularvect)[matOffset] << endl;

}

boostmat::vector<double> numericalSolver::getVect(){
	return (*circularvect)[matOffset];
}

double numericalSolver::getMu(int i){
	//cerr << "indice" << matOffset << endl;
	if (matOffset>=0) return (*circularvect)[matOffset][i];
	else return 0.0;
}

void numericalSolver::stepVect(){
	matOffset--;
	//cerr << " # "<< matOffset <<" # ";
}

void numericalSolver::previousVect(){
	matOffset++;
}











