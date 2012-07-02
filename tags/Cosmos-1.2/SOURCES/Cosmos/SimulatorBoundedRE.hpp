/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 * file SimulatorBoundedRE.hpp created by Benoit Barbot on 06/12/11.           *
 *******************************************************************************
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
    int maxStep;
	simulationState(){
		//EQ = new EventsQueue(n);
        maxStep=0;
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
