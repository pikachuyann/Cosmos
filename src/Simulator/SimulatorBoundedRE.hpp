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
#include "marking.hpp"
#include <vector>

#ifndef _SIMULATOR_BOUNDED_RE_HPP
#define _SIMULATOR_BOUNDED_RE_HPP


class simulationState{
private:
	abstractMarking marking;
	EventsQueue *EQ;
	LHA lhaState;
    
	//rare event variable
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
	~simulationState(){};
	
	void saveState(SPN* N,LHA* A,EventsQueue** EQsim){
		marking.swap(N->Marking);
		//AE = *AEsim;
		EQ = *EQsim; //new EventsQueue(*EQsim);
		
		lhaState.copyState(A);
		
		Rate_Table.swap(N->Rate_Table);
		Origine_Rate_Table.swap(N->Origine_Rate_Table);
		Rate_Sum = N->Rate_Sum;
		Origine_Rate_Sum = N-> Origine_Rate_Sum;
		
	};
	void loadState(SPN* N,LHA* A,EventsQueue** EQsim){
		
		N->Marking.swap(marking);
		//*AEsim = AE;
		*EQsim = EQ;
		
		A->copyState(&lhaState);
		
		N->Rate_Table.swap(Rate_Table);
		N->Origine_Rate_Table.swap(Origine_Rate_Table);
		N->Rate_Sum = Rate_Sum;
		N->Origine_Rate_Sum = Origine_Rate_Sum ;
	};
	
};

class SimulatorBoundedRE: public SimulatorRE{
public:
	//SimulatorBoundedRE();
    SimulatorBoundedRE(int m);
	BatchR RunBatch() override;
	using SimulatorRE::initVect;
    virtual void initVect(int T);
	void updateSPN(size_t, const abstractBinding&) override;
	void getParams(size_t, const abstractBinding&) override;
protected:
	numericalSolver* numSolv;
	
	double lambda;
	virtual double mu() override;
	virtual double ComputeDistr(size_t i,const abstractBinding&, double origin_rate) override;
};


#endif  /* _SIMULATOR_BOUNDED_RE_HPP */
