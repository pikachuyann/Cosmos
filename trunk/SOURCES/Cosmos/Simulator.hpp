

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

  fstream logvalue;

  Simulator();
  //void Load();

  Simulator(const Simulator& orig);
  ~Simulator();
	
  virtual void SimulateSinglePath();
  //void SimulateSinglePathRE();
  void InitialEventsQueue();
  //void InitialEventsQueueRE();


  BatchR* RunBatch();


  SimOutput Result;
  double simTime;

  int BatchSize;
  void SetBatchSize(int);


  void GenerateEvent(Event &, int);
  double GenerateTime(string&, vector<double>&);

  double max(double, double);

  void resetSimVarsTable();
  void reset();

  SPN N;
  LHA A;

  time_t SysTime;

  EventsQueue* EQ;
protected:

  bool Initialized;
  map<string, int> IndexDist;
  boost::mt19937 RandomNumber;

};


#endif  /* _SIMULATOR_HPP */

