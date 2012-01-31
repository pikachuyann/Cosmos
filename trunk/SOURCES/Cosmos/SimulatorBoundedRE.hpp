/*
 *  SimulatorBoudedRE.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 06/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/* This class inherit the class of Simulator and modify 
 * several intern function to implement rare event acceleration.
 */

#include "SimulatorRE.hpp"
#include "numericalSolver.hpp"

#ifndef _SIMULATOR_BOUNDED_RE_HPP
#define _SIMULATOR_BOUNDED_RE_HPP


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
	
	//rare event variable
	double likelihood;

	vector <double> Rate_Table;
	vector <double> Origine_Rate_Table;
	double Rate_Sum;
	double Origine_Rate_Sum;
	
	
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
		
		likelihood = A->Likelihood;
		Rate_Table = N->Rate_Table;
		Origine_Rate_Table = N->Origine_Rate_Table;
		Rate_Sum = N->Rate_Sum;
		Origine_Rate_Sum= N-> Origine_Rate_Sum;
		
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
		
		A->Likelihood = likelihood; 
		N->Rate_Table = Rate_Table;
		N->Origine_Rate_Table = Origine_Rate_Table;
		N->Rate_Sum = Rate_Sum;
		N->Origine_Rate_Sum = Origine_Rate_Sum ;
	};
	
};

class SimulatorBoundedRE: public SimulatorRE{
public:
	//SimulatorBoundedRE();
    SimulatorBoundedRE(int m);
	BatchR* RunBatch();
    void initVect(int T);
protected:
	numericalSolver* numSolv;
	
	virtual double mu();
	virtual double ComputeDistr(int i, double origin_rate);
};


#endif  /* _SIMULATOR_BOUNDED_RE_HPP */
