/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *									       *
 * Copyright (C) 2009-2011 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *									       *
 *									       *
 *******************************************************************************
 */



#include "LHA.hpp"
#include "spn.hpp"
#include "EventsQueue.hpp"

#include <iostream>
#include <fstream>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"



using namespace std;

#ifndef _SIMULATOR_HPP
#define	_SIMULATOR_HPP



typedef pair<bool, double> SimOutput;

class Simulator {
public:
    Simulator();
    void Load();

    Simulator(const Simulator& orig);
    virtual ~Simulator();
    void SimulateSinglePath();
    void InitialEventsQueue();

    void RunSimulation();
    
    SimOutput Result;
    double simTime;

    vector<double>* ResidualTime; //for transitions with Age Memory Policy
    vector<double>* ActDate; //for transitions with Age Memory Policy

    int BatchSize;
    long int MaxRuns;
    
    int Krand;

    double ConfWidth;
    double ConfLevel;

    void SetConfWidth(double);
    void SetConfLevel(double);

    void SetBatchSize(int);
    void SetMaxRuns(long int);
    void ViewParameters();


    void GenerateEvent(Event &, int);
    double GenerateTime(string&, vector<double>&);

    double max(double, double);

    void resetSimVarsTable();
    void reset();

    SPN N;
    LHA A;

    time_t SysTime;





    EventsQueue* EQ;
private:


    bool Initialized;

    map<string, int> IndexDist;
    boost::mt19937 RandomNumber;



};


#endif	/* _SIMULATOR_HPP */

