/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini, Benoit Barbot & Hilal Djafri                      *
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
#include "timeGen.hpp"

#include <iostream>
#include <fstream>



using namespace std;

#ifndef _SIMULATOR_HPP
#define _SIMULATOR_HPP



class Simulator:public timeGen {
public:
	Simulator();
	~Simulator();
	
	//! verbose level of the simulator
    int verbose;

    //! Path to the temporary directory
    string tmpPath;
    string dotFile;

	/**
	 * \brief Set the batch size
	 * @param RI the new batch size to use
	 */
    void SetBatchSize(const size_t); // set the batch size
	
	/**
	 * \brief Open an output stream to a file to log the result value of each trajectory.
	 * @param path is a path to a file in which the value will be log in.
	 */
	void logValue(const char*);    //Make the simulator output each result in a file.
	
	void logTrace(const char*,double);     //Make the simulator output each trace in a file.

	/**
	 * \brief Main entry point of the object simulate a batch of trajectory .
	 *
	 * Run a batch of simulation, the result is return as a BatchR structure.
	 * @return a new BatchR structure containing the result
	 * of the batch of simulation.
	 */
    virtual BatchR RunBatch();

protected:
	
	//! a Temporary event
	Event F;

	//! File stream to log value.
	fstream logvalue;
	//! File stream to trace.
	fstream logtrace;
	
	//! boolean set to true when result value should be log.
    bool logResult;
	
	//! interval time on which trace is log
	double sampleTrace;
	double lastSampled;
	
	//! Store result beetween two trajectory simulation.
	SimOutput Result;
	
	//! Size of the batch.
	size_t BatchSize;
	
    
	SPN N; //!The object representing the SPN
	LHA A; //!The object representing the LHA
	
    
    /**
	 * \brief The event queue of the simulator.
	 * The event queue is a datastructure containing the
	 * enabled transitions with
     * the time at wich they will be fire if still enabled
	 */
	EventsQueue* EQ;
	
	/**
	 * \brief Simulate a step of the system,
	 * this function do most of the simulation job.
	 */
	virtual bool SimulateOneStep();
	
	/**
	 * \brief Simulate single path
	 * this function loop over SimulateOneStep until a the path terminate.
	 */
	virtual void SimulateSinglePath();

    void printLog();

	void interactiveSimulation(); //!Wait for the user to choose the next transition
    double minInteractiveTime;

    void printSedCmd();
	
	virtual void InitialEventsQueue(); //!initialize the event queue
	
	virtual void reset(); //! reset the simulator
	
	virtual void GenerateEvent(Event &,size_t,const abstractBinding&); //! generate a new event use Generate Time
	
	virtual void returnResultTrue();
	
	//! update value in the SPN after a transition
	virtual void updateSPN(size_t,const abstractBinding& );
	
	//! update the likelyhood for the Rare event case
	virtual void updateLikelihood(size_t);
    
	//! Stop the simulation if sink transition is taken
	virtual bool transitionSink(size_t);
	
	//! return the parameters of a transition distribution
	virtual void getParams(size_t, const abstractBinding&);
};


#endif  /* _SIMULATOR_HPP */

