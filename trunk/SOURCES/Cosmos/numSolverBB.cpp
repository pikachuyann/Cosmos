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
    time_t start, endt;
    time(&start);
    
    minT = -1;
	
	circularvect = new vector< boostmat::vector<double> > (l+1, boostmat::zero_vector<double> (finalVector->size()));
	checkPoint = new vector< boostmat::vector<double> > (T/l+1, *finalVector);
    
    time(&endt);
    cerr << "time for allocation:" << difftime(endt, start) << endl;
    
	lastCP = (T/l)*l;
	boostmat::vector<double> itervect = *finalVector;
    boostmat::vector<double> itervect2 = boostmat::zero_vector<double> (finalVector->size());
	//We suppose here that the initial state is the first of the vector
    if(itervect(0) != 0)minT=0;

    
    for(int i=1; i<=lastCP ; i++){
        itervect2.clear();
        sparseProd(&itervect2, &itervect, transitionsMatrix);
        itervect = itervect2;
        
        if((itervect (0) != 0) && (minT== -1))minT=i;
        //cerr << "i:" << i << "v0:\t" << itervect (0) << "mint:\t" << minT<< endl;
        
        
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
		if( i % l ==0) (*checkPoint)[i/l]= itervect;
	}
	
    time(&endt);
    cerr << "time for precalculation:" << difftime(endt, start) << endl;
    
	cerr << "Starting the simulation" << endl;
    
}

void numSolverBB::reset(){
    time_t start, endt;
    time(&start);

	(*circularvect)[0]=(*checkPoint)[lastCP/l];
	
	/*for(int i=1; i<=T-lastCP ; i++){
		(*circularvect)[i] = boostmat::prod ((*transitionsMatrix), (*circularvect)[i-1]);
	}*/
    for(int i=1; i<=T-lastCP ; i++){
        ((*circularvect)[i]).clear();
        sparseProd(&((*circularvect)[i]), &((*circularvect)[i-1]), transitionsMatrix);
        //cerr << "i:" << i << "v0:\t" << (*circularvect)[i] (0) << "mint:\t" << minT<< endl;
        if(((*circularvect)[i] (0) != 0.0) && (minT== -1))minT=i+lastCP;
        
		//cerr << "itervect:" << i << ":"<< (*circularvect)[i] << endl;
	}
    time(&endt);
    cerr << "time for reset:" << difftime(endt, start) << endl << endl;
    
	
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
