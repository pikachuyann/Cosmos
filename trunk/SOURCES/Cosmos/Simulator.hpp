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



class Simulator {
public:
	Simulator();
	~Simulator();
	
    int verbose;    //Set the verbose level
    
	void initRandomGenerator(const unsigned int);
		//Initialize the random generator with the given seed
    void SetBatchSize(const size_t); // set the batch size
	void logValue(const char*);    //Make the simulator output each result in a file
    
    //main entry point of the object simulate a batch of trajectory
    virtual BatchR* RunBatch(); 
    
protected:
	fstream logvalue; // file to log value
    
	SimOutput Result; // store result beetween two trajectory simulation

	time_t SysTime;
	
	size_t BatchSize;
	bool logResult;
    
	SPN N; //The object representing the SPN
	LHA A; //The object representing the LHA
	
    
    //A datastructure containing the enabled transitions with
    //the time at wich they will be fire if still enabled
	EventsQueue* EQ;  
	
	bool Initialized;
    
    //The random Generator Mersenne Twister from the boost library
	boost::mt19937 RandomNumber;
	
	
  	
	double max(double, double);
	
	virtual bool SimulateOneStep(AutEdge&); //Simulate a step of the system, this function do most of the simulation job
	virtual void SimulateSinglePath(); //Simulate a single path 
	
	virtual void InitialEventsQueue(); //initialize the event queue
	//virtual void resetSimVarsTable();
	virtual void reset(); // reset the simulator
	
	virtual void GenerateEvent(Event &, int); // generate a new event use Generate Time
	
	// generate a time acording to the distribution d with parameters p
	virtual double GenerateTime(int, vector<double>& p); 
	
	
	virtual void returnResultTrue(); 
	virtual void returnResultFalse();
	
	virtual void updateLHA( double );
	// update value in the LHA by elapsing time
	
	virtual void fireLHA(int,double );
		//fire the transition of an LHA
	
	virtual void updateSPN(int); // update value in the SPN after a transition
	
	virtual void updateLikelihood(int); // update the likelyhood for the Rare event case 
    virtual bool transitionSink(int); // Stop the simulation if sink transition is taken
	
	virtual void getParams(int); // return the parameters of a transition distribution
	
};


#endif  /* _SIMULATOR_HPP */

