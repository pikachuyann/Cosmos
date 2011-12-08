

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

/* This object do the main computation of the programm
 * it contains the SPN and the LHA
 */

typedef pair<bool, double> SimOutput;

class Simulator {
public:
	Simulator();
	Simulator(const Simulator& orig);
	~Simulator();
	
	virtual BatchR* RunBatch(); //main entry point of the object simulate a batch of trajectory
	void SetBatchSize(int); // set the batch size
	
protected:
	fstream logvalue; // file to log value
	SimOutput Result; // store result beetween two trajectory simulation
	double simTime; 
	time_t SysTime;
	
	int BatchSize;
	
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
	virtual void reset();
	
	virtual void GenerateEvent(Event &, int); 
	virtual double GenerateTime(string&, vector<double>&);
	
	
	virtual void returnResultTrue(vector<int>, double);
	virtual void returnResultFalse();
	virtual void updateLHA(int, double, vector<int>);
	
	virtual void updateSPN(int);
	virtual void updateLikelihood(int);
	
};


#endif  /* _SIMULATOR_HPP */

