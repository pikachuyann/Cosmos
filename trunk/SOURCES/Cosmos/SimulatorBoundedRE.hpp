/*
 *  SimulatorBoudedRE.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulatorRE.hpp"
#include "numericalSolver.hpp"

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
	EventsQueue *EQ;
	double timeS;
	
	vector<double> VarLHA;
	vector<double> LinFormLHA;
	vector<double> OldLinFormLHA;
	vector<double> LhaFuncLHA;
	
public:
	simulationState(){
		//EQ = new EventsQueue(n);
	};
	~simulationState(){
		//delete EQ;
	};
	
	void saveState(SPN* N,LHA* A,AutEdge* AEsim,EventsQueue** EQsim, double* t){
		marking = N->Marking;
		LHAstate= A->CurrentLocation;
		LHAcurrentTime= A->CurrentTime;
		AE = *AEsim;
		EQ = *EQsim; //new EventsQueue(*EQsim);
		timeS = *t;
		
		
		VarLHA=A->Var;
		LinFormLHA=A->LinForm;
		OldLinFormLHA=A->OldLinForm;
		LhaFuncLHA=A->LhaFunc;
	};
	void loadState(SPN* N,LHA* A,AutEdge* AEsim,EventsQueue** EQsim,double* t){
		
		N->Marking = marking;
		A->CurrentLocation = LHAstate;
		A->CurrentTime = LHAcurrentTime;
		*AEsim = AE; 
		*EQsim = EQ;
		*t = timeS;
		
		A->Var = VarLHA;
		A->LinForm = LinFormLHA;
		A->OldLinForm = OldLinFormLHA;
		A->LhaFunc = LhaFuncLHA;
	};
	
};

class SimulatorBoundedRE: public Simulator{
public:
	SimulatorBoundedRE();
	BatchR* RunBatch();
protected:
	numericalSolver numSolv;
};


#endif  /* _SIMULATOR_BOUNDED_RE_HPP */
