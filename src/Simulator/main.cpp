#include "BatchR.hpp"
#include "clientsim.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "SPNBase.cpp"
#include "Simulator.cpp"

int main(int argc, char** argv) {
    signal(SIGINT, signalHandler);
    SPN_orig<EventsQueue<vector<_trans>>> N;
    LHA_orig<decltype(N.Marking)> A;
    Simulator<EventsQueue<vector<_trans>>,typeof N> sim(N,A);
    bool singleBatch = false;
    sim.SetBatchSize(1000);
    setSimulator(sim,argc,argv);
    if((verbose>=4) | singleBatch )sim.RunBatch();
    else while( !cin.eof() ){
        BatchR batchResult = sim.RunBatch(); //simulate a batch of trajectory
        batchResult.outputR(cout);// output the result on the standart output
    }
    return (EXIT_SUCCESS);
}

