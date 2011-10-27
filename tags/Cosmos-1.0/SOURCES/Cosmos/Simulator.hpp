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

    vector<double>* ResidualTime;

    int BatchSize;
    long int MaxRuns;

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
    //boost::rand48 RandomNumber;
	boost::mt19937 RandomNumber;



};


#endif	/* _SIMULATOR_HPP */

