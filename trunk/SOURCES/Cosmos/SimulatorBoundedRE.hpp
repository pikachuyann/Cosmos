/*
 *  SimulatorBoudedRE.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorRE.hpp"


#ifndef _SIMULATOR_BOUNDED_RE_HPP
#define _SIMULATOR_BOUNDED_RE_HPP

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */

class simulationState{
private:
	vector<int> marking;
	int LHAstate;
	int LHAcurrentTime;
	AutEdge AE;
	EventsQueue* EQ;
	double timeS;
public:
	void saveState(SPN* N,LHA* A,AutEdge* AEsim,EventsQueue* EQsim, double* t){
		marking = N->Marking;
		/*cout << "marking: ";
		for (int i=0; i< marking.size(); i++)cout << marking[i] << " ; ";
		cout << endl;*/
		LHAstate= A->CurrentLocation;
		LHAcurrentTime= A->CurrentTime;
		AE = *AEsim;
		EQ = EQsim;
		timeS = *t;
	};
	void loadState(SPN* N,LHA* A,AutEdge* AEsim,EventsQueue* EQsim,double* t){
		N->Marking = marking;
		A->CurrentLocation = LHAstate;
		A->CurrentTime = LHAcurrentTime;
		*AEsim = AE; 
		EQsim = EQ;
		*t = timeS;
	};
	
};

class SimulatorBoundedRE: public Simulator{
public:
	SimulatorBoundedRE();
	
	BatchR* RunBatch();
};


#endif  /* _SIMULATOR_BOUNDED_RE_HPP */
