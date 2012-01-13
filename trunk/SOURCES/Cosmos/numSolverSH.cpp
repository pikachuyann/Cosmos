/*
 *  numSolverSH.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/01/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "numSolverSH.hpp"

bool readbit(int a,int b){
	int c = a & (1 << b);
	return (0 != c);
}


void numSolverSH::initVect(int nT){
	T=nT;
	u=T;
	l = log2(T);
	
	cerr << "T:l " <<T << ":" << l << endl;
	
	cerr << "xor: " <<120 << ":" << 119 << ":" << (120^119) << endl;
	
	powTVect = new vector< boostmat::vector<double> > (l+1, *finalVector);
	lastOne = new vector< boostmat::vector<double> > (l+1, *finalVector);
	lastPowT= 1<<l;
	
	//cerr << "lastPow" << lastPowT << " log(T) " << l << endl;
	
	boostmat::vector<double> itervect = *finalVector;
    boostmat::vector<double> itervect2=
        boostmat::zero_vector<double> (finalVector->size());
    
	int nextPow =1;
	int currPow =0;
	
	for(int i=1; i<=lastPowT ; i++){
		//cerr << "currPow " << currPow << " newPow " << nextPow << endl;
        itervect2.clear();
        sparseProd(&itervect2,&itervect, transitionsMatrix);
        itervect=itervect2;
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
		if( i == nextPow){
			cerr << "test: " << currPow << ":" << nextPow << endl;
			(*powTVect)[currPow]=itervect;
			currPow++;
			nextPow <<= 1;
		}
	}
	
	cerr << "finish" << endl;
}

void numSolverSH::reset(){
	is_previous=true;
	u=T;
	
	int k = l-1;
	int m = 1<<k;
	(*lastOne)[l] = (*powTVect)[l];
	boostmat::vector<double> itervect = (*powTVect)[l];
	boostmat::vector<double> itervect2 = 
        boostmat::zero_vector<double> (finalVector->size());   
    for (int i = lastPowT+1; i<=T; i++) {
		cerr << "i:" << i << "k:" << k << "m:" << m << endl;
        itervect2.clear();
        sparseProd(&itervect2,&itervect, transitionsMatrix);
        itervect=itervect2;
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
		m--;
		if(m==0){
			(*lastOne)[k]=itervect;
			k--;
			cerr << "k--" << endl;
			while (k>0 && readbit(T, k)==0){
				(*lastOne)[k]=itervect;
				cerr << "k--" << endl;
				k--;
			}
			
			m= 1<<k;
		}
		
	}
	cerr << "finish2";
	previous_vect = itervect;
    current_vect= boostmat::zero_vector<double> (itervect.size());
    sparseProd(&current_vect, &itervect, transitionsMatrix);
	//current_vect = boostmat::prod ((*transitionsMatrix), itervect);
	cerr << "finish reset" << endl; 
    
    
}


void numSolverSH::stepVect(){
    cerr << "step vect" << endl;
	u--;
	if(is_previous){ is_previous=false;}
	else {
		
        
	}

	
}

void numSolverSH::previousVect(){
	u++;
	if(is_previous){
		cerr << "fail to compute previous vect" << endl;
	}else{
		is_previous=true;
	}
}

boostmat::vector<double> numSolverSH::getVect(){
	if(is_previous){
		return previous_vect;
	}else return current_vect;
}

double numSolverSH::getMu(int i){
	if(u<0)return 0.0;
	
	if(is_previous){
		return previous_vect[i];
	}else return current_vect[i];
}
