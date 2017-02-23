#include "timeGenBis.hpp"
#include <float.h>

using namespace std;

/**
 * Generate an event based on the type of his distribution
 * @param E the event to update
 * @param Id the number of the transition to of the SPN
 * @param b is the binding of the variable of the SPN for the transition.
 */

template<class DEDS>
void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &TG,DEDS& N) {
    double t=ctime;
    if (N.Transition[Id].DistTypeIndex != IMMEDIATE) {
        N.GetDistParameters(Id,b);
        t += fmax(TG.GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr, N.customDistr),0.0);
        if(verbose > 4){
            cerr << "Sample " << N.Transition[Id].label << ": ";
            cerr << TG.string_of_dist(N.Transition[Id].DistTypeIndex, N.ParamDistr, N.customDistr);
            cerr << endl;
        }
    }
    
    //The weight of a transition is always distributed exponentially
    //It is used to solved conflict of two transitions with same time
    //and same priority.
    double w=0.0;
    switch (N.Transition[Id].DistTypeIndex){
        case DETERMINISTIC:
        case DISCRETEUNIF:
        case IMMEDIATE:
        case DISCRETEUSERDEFINE:
            N.ParamDistr[0]= N.GetWeight(Id,b);
            w = TG.GenerateTime(EXPONENTIAL, N.ParamDistr, N.customDistr);
            if(verbose>4){
                cerr << "weight : ";
                cerr << TG.string_of_dist(EXPONENTIAL, N.ParamDistr, N.customDistr);
                cerr << endl;
            }
            break;
        case NORMAL:
        case GAMMA:
        case GEOMETRIC:
        case UNIFORM:
        case ERLANG:
        case EXPONENTIAL:
        case LOGNORMAL:
        case TRIANGLE:
        case USERDEFINE:
        case USERDEFINEPOLYNOMIAL:
        case MASSACTION:
        case PLAYER1:
            ;
    }
    
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id,b);
    E.weight = w;
    E.binding = b;
}

template void generateEvent<SPN_orig<EventsQueue<std::vector<_trans, std::allocator<_trans> > > > >(double, Event&, unsigned long, abstractBinding const&, timeGen&, SPN_orig<EventsQueue<std::vector<_trans, std::allocator<_trans> > > >&);
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPN_orig<EventsQueueSet> &);


// #include "SPNBase.hpp"
#include "EventsQueue.hpp"
#include "EventsQueueSet.hpp"
/*#include "MarkovChain.hpp"
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,MarkovChain<EventsQueue<vector<Edge>>> &);
*/