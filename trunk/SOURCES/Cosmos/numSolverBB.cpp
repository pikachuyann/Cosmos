/*
 *  numericalSolverBB.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/01/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "numSolverBB.hpp"

void numSolverBB::initVect(int nT){
	T=nT;
	u=T;
	l = sqrt(T);
	
	circularvect = new vector< boostmat::vector<double> > (l+1, boostmat::zero_vector<double> (finalVector->size()));
	checkPoint = new vector< boostmat::vector<double> > (T/l+1, *finalVector);
    
	lastCP = (T/l)*l;
	boostmat::vector<double> itervect = *finalVector;
    boostmat::vector<double> itervect2 = boostmat::zero_vector<double> (finalVector->size());
	for(int i=1; i<=lastCP ; i++){
        itervect2.clear();
        sparseProd(&itervect2, &itervect, transitionsMatrix);
        itervect = itervect2;
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
		if( i % l ==0) (*checkPoint)[i/l]= itervect;
	}
	
}

void numSolverBB::reset(){
	(*circularvect)[0]=(*checkPoint)[lastCP/l];
	
	/*for(int i=1; i<=T-lastCP ; i++){
		(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
	}*/
    for(int i=1; i<=T-lastCP ; i++){
        ((*circularvect)[i]).clear();
        sparseProd(&((*circularvect)[i]), &((*circularvect)[i-1]), transitionsMatrix);
        
		//cerr << "itervect:" << i << ":"<< (*circularvect)[i] << endl;
	}
    
	
	u=T;
	matOffset = T-lastCP;	
}


void numSolverBB::stepVect(){
	//cerr << "step:" << u << endl; 
	if(matOffset > 0 || u==0){
		matOffset--;
		u--;
	}else{
		u--;
		(*circularvect)[l]=(*circularvect)[0];
		(*circularvect)[0]=(*checkPoint)[u/l];
		for(int i=1; i<l ; i++){
            (*circularvect)[i].clear();
            sparseProd(&((*circularvect)[i]), &((*circularvect)[i-1]), transitionsMatrix);
			//(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
		}
		matOffset=l-1;
	}
}

void numSolverBB::previousVect(){
	u++;
	matOffset++;
}
