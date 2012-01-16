/*
 *  numSolverSH.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/01/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include <time.h>
#include "numSolverSH.hpp"

bool readbit(int a,int b){
	int c = a & (1 << b);
	return (0 != c);
}


void numSolverSH::initVect(int nT){
    time_t start, endt;
    time(&start);
    
	T=nT;
	u=T;
	l = log2(T);
	
	//cerr << "T: " <<T << " l: " << l << endl;
	
	
	//powTVect = new vector< boostmat::vector<double> > (l+1, *finalVector);
	lastOne = new vector< boostmat::vector<double> > (l+2, *finalVector);
    ktable = new vector< double > (l+2,0);
	lastPowT= 1<<l;
	
	//cerr << "lastPow" << lastPowT << " log(T) " << l << endl;
	
	boostmat::vector<double> itervect = *finalVector;
    boostmat::vector<double> itervect2=
        boostmat::zero_vector<double> (finalVector->size());
    
    cerr << "time for allocation:" << difftime(endt, start) << endl;
	
	for(int i=1; i<=lastPowT ; i++){
		//cerr << "currPow " << currPow << " newPow " << nextPow << endl;
        itervect2.clear();
        sparseProd(&itervect2,&itervect, transitionsMatrix);
        itervect=itervect2;
        //cerr << "i: " <<i << " v: " <<itervect << endl;
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
	}
    (*lastOne)[l]= itervect;
    (*ktable)[l] = lastPowT;
    (*ktable)[l+1] = 0;
	
    cerr << "time for precalculation:" << difftime(endt, start) << endl;
    
	cerr << "Starting the simulation" << endl;
	//cerr << "finish init" << endl;
}

void numSolverSH::compPow(int kp,int up){
    //cerr << "compPow("<< kp << "," << up << ")" << endl;
    
    int k = kp-1;
    boostmat::vector<double> itervect = (*lastOne)[kp];
	boostmat::vector<double> itervect2 = 
        boostmat::zero_vector<double> (finalVector->size());   
    
    while (k>0 && readbit(up, k)==0){
        //cerr << itervect<< endl;
        (*lastOne)[k]=itervect;
        (*ktable)[k] =(*ktable)[kp];
        //cerr << "k--" << endl;
        k--;
    }
    
	int m = 1<<k;
    for (int i = (*ktable)[kp]+1; i<=up; i++) {
		//cerr << "i: " << i << " k: " << k << " m: " << m << endl;
        itervect2.clear();
        sparseProd(&itervect2,&itervect, transitionsMatrix);
        itervect=itervect2;
		//itervect = boostmat::prod ((*transitionsMatrix), itervect);
		m--;
		if(m==0){
			(*lastOne)[k]=itervect;
            (*ktable)[k] = i;
			k--;
			//cerr << "k--1" << endl;
			while (k>0 && readbit(up, k)==0){
				(*lastOne)[k]=itervect;
                (*ktable)[k] =i;
				//cerr << "k--" << endl;
				k--;
			}
			
			m= 1<<k;
		}
		
	}
	//cerr << "finish";
    //cerr << itervect << endl;
	previous_vect = current_vect;
    current_vect=itervect;
    is_previous=false;
    /*current_vect= boostmat::zero_vector<double> (itervect.size());
    sparseProd(&current_vect, &itervect, transitionsMatrix);*/
	//current_vect = boostmat::prod ((*transitionsMatrix), itervect);
	//cerr << "finish reset" << endl; 
    
    
}

void numSolverSH::reset(){
	//is_previous=true;
	u=T;
    compPow(l, T);
    
	//cerr << "finish reset" << endl; 
    
    
}


void numSolverSH::stepVect(){
    //cerr << "step vect" << endl;
	u--;
	if(is_previous){ is_previous=false;}
	else {
        if(u==0){
            previous_vect = current_vect;
            current_vect = *finalVector;
        }else{
            int kp = log2((u^(u+1))+1);
            //cerr << "u: " << u<< ": kp: " << kp << endl;
            compPow(kp, u);
        }
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
