/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
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
 *******************************************************************************
 */

/* This object do the main computation of the programm
 * it contains the SPN and the LHA
 */



#include "LHA.hpp"
#include "spn.hpp"
#include "EventsQueue.hpp"
#include "BatchR.hpp"

#include <iostream>
#include <fstream>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"



using namespace std;

#ifndef _SIMULATOR_HPP
#define _SIMULATOR_HPP

typedef pair<bool, double> SimOutput;

class Simulator {
public:
	Simulator();
	Simulator(const Simulator& orig);
	~Simulator();
	
    int verbose;
    
	virtual BatchR* RunBatch(); //main entry point of the object simulate a batch of trajectory
	void SetBatchSize(int); // set the batch size
	void logValue();
    
protected:
	fstream logvalue; // file to log value
    
	SimOutput Result; // store result beetween two trajectory simulation
	double simTime; 
	time_t SysTime;
	
	int BatchSize;
	bool logResult;
    
	SPN N; //The object representing the SPN
	LHA A; //The object representing the LHA
	
	
	EventsQueue* EQ;
	
	bool Initialized;
	map<string, int> IndexDist;
	boost::mt19937 RandomNumber;
	
	
  	
	double max(double, double);
	
	virtual bool SimulateOneStep(AutEdge*); //Simulate a step of the system, this function do most of the simulation job
	virtual void SimulateSinglePath(); //Simulate a single path 
	
	virtual void InitialEventsQueue(); //initialize the event queue
	//virtual void resetSimVarsTable();
	virtual void reset(); // reset the simulator
	
	virtual void GenerateEvent(Event &, int); // generate a new event use Generate Time
	
	// generate a time acording to the distribution d with parameters p
	virtual double GenerateTime(string& d, vector<double>& p); 
	
	
	virtual void returnResultTrue(vector<int>, double); 
	virtual void returnResultFalse();
	
	virtual void updateLHA(int, double, vector<int>); // update value in the LHA after a transition
	virtual void updateSPN(int); // update value in the SPN after a transition
	
	virtual void updateLikelihood(int); // update the likelyhood for the Rare event case 
    virtual bool transitionSink(int); // Stop the simulation if sink transition is taken
	
	virtual vector<double> getParams(int); // return the parameters of a transition distribution
	
};


#endif  /* _SIMULATOR_HPP */

