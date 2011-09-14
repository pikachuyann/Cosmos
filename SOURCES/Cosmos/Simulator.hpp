

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

  bool RareEvent_mode;
  bool doubleIS_mode;

  Simulator();
  void Load();

  Simulator(const Simulator& orig);
  virtual ~Simulator();
  void SimulateSinglePath();
  void SimulateSinglePathRE();
  void InitialEventsQueue();
  void InitialEventsQueueRE();


  BatchR* RunBatch();


  SimOutput Result;
  double simTime;

  int BatchSize;
  void SetBatchSize(int);


  void GenerateEvent(Event &, int);
  void GenerateEventRE(Event &, int);
  void GenerateDummyEvent(Event &, int);
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


#endif  /* _SIMULATOR_HPP */

