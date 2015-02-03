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
 * file SimLight.hpp created by Benoit Barbot on 5/02/2015.                    *
 *******************************************************************************
 */


#ifndef __Cosmos__SimLight__
#define __Cosmos__SimLight__

#include "spnLight.hpp"
#include "EventsQueue.hpp"


using namespace std;

typedef std::pair<bool, std::vector<double> > SimOutput;

class SimulatorLight {
public:
    SimulatorLight();
    ~SimulatorLight();

    //! verbose level of the simulator
    int verbose;

    //! Path to the temporary directory
    string tmpPath;

    /**
     * \brief Set the batch size
     * @param RI the new batch size to use
     */
    void SetBatchSize(const size_t); // set the batch size

    /**
     * \brief Main entry point of the object simulate a batch of trajectory .
     *
     * Run a batch of simulation, the result is return as a BatchR structure.
     * @return a new BatchR structure containing the result
     * of the batch of simulation.
     */
    void RunBatch();

    /**
     *  Current simulation time
     */
    double curr_time;

protected:

    //! a Temporary event
    Event F;

    //! Store result beetween two trajectory simulation.
    SimOutput Result;

    //! Size of the batch.
    size_t BatchSize;

    SPN N; //!The object representing the SPN

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
    bool SimulateOneStep();

    /**
     * \brief Simulate single path
     * this function loop over SimulateOneStep until a the path terminate.
     */
    void SimulateSinglePath();

    void InitialEventsQueue(); //!initialize the event queue

    void reset(); //! reset the simulator

    void GenerateEvent(Event &,size_t); //! generate a new event use Generate Time

    //! update value in the SPN after a transition
    void updateSPN(size_t);

};


#endif /* defined(__Cosmos__SimLight__) */
