#include "Simulator.hpp"
#include "spn.hpp"
#include "LHA.hpp"
#include "EventsQueue.hpp"
//#include "SimulatorRE.h"
#include <iostream>
#include <set>
#include <math.h>
#include <float.h>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <time.h>


using namespace std;

Simulator::Simulator() {
}

void Simulator::Load() {
    N.Load(); //load the GSPN
    if (RareEvent_mode)N.gammaprob.load(); //load the hashtable for rare event
    A.Load(); //load the LHA
    int n = N.tr; //n his the number of transition
    EQ = new EventsQueue(n); //initialization of the event queue
    simTime = 0; //initialization of the time
    Initialized = false;
    IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;
    IndexDist["ERLANG"] = 7;
    IndexDist["GAMMA"] = 8;

    logvalue.open("outcosmos", fstream::out);

    //Initialize random generator
    RandomNumber.seed(time(NULL));
    srand(time(NULL));

    BatchSize = 1000;

    ResidualTime = new vector<double> (N.tr);
    ActDate = new vector<double> (N.tr);
    Krand = 0;
}

Simulator::Simulator(const Simulator& orig) {
}

Simulator::~Simulator() {
}

void Simulator::SetBatchSize(int RI) {
    BatchSize = RI;
}

double Simulator::max(double a, double b) {
    if (a >= b) return a;
    else return b;
}

void Simulator::InitialEventsQueue() {
    Initialized = true;

    for (int t = 0; t < N.tr; t++) {
        (*ResidualTime)[t] = 0;
        (*ActDate)[t] = -1;
    }
    set<int, less <int> > ent;
    ent = N.enabledTrans();
    set<int>::iterator it;
    Event E;
    for (it = ent.begin(); it != ent.end(); it++) {
        GenerateEvent(E, (*it));
        (*EQ).insert(E);

        if (N.Transition[(*it)].AgeMemory) {
            (*ResidualTime)[(*it)] = E.time;
            (*ActDate)[(*it)] = E.time;
        }
    }
}

void Simulator::reset() {

    N.reset();
    A.reset(N.initMarking);
    simTime = 0;
    (*EQ).reset();

    if (Krand >= 10000) {
        Krand = 0;
        srand(RandomNumber());
    } else
        Krand++;

    RandomNumber.seed(rand());

}

void Simulator::SimulateSinglePath() {


    bool QueueIsEmpty;
    AutEdge AE;
    double D = 0.0;
    A.CurrentLocation = A.EnabledInitLocation(N.Marking);
    A.CurrentTime = 0;
    simTime = 0;
    Event F;

    Simulator::InitialEventsQueue();
    QueueIsEmpty = (*EQ).isEmpty();
    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);


    while (!QueueIsEmpty || AE.Index > -1) {

        if (QueueIsEmpty) {
            while (AE.Index>-1) {

                double DeltaT = AE.FiringTime - A.CurrentTime;
                A.DoElapsedTimeUpdate(DeltaT, N.Marking);
                A.UpdateLinForm(N.Marking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(AE.Index, N.Marking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[AE.Index].Target;

                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(N.Marking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);

                }
            }
            Result.first = false;

            return;
        } else {
            Event E1 = (*EQ).InPosition(0);

            int E1_transitionNum = E1.transition;

            while (E1.time >= AE.FiringTime) {

                double DeltaT = AE.FiringTime - A.CurrentTime;
                A.DoElapsedTimeUpdate(DeltaT, N.Marking);
                A.UpdateLinForm(N.Marking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(AE.Index, N.Marking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[AE.Index].Target;

                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(N.Marking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);

                }


            }

            vector<int> OldMarking = N.Marking;
            N.fire(E1_transitionNum);
            double DeltaT = E1.time - A.CurrentTime;
            int SE = A.GetEnabled_S_Edges(A.CurrentLocation, E1_transitionNum, DeltaT, OldMarking, N.Marking);

            if (SE < 0) {
                Result.first = false;

                return;
            } else {
                A.DoElapsedTimeUpdate(DeltaT, OldMarking);
                A.UpdateLinForm(OldMarking);
                A.UpdateLhaFunc(A.CurrentTime, DeltaT);
                A.DoEdgeUpdates(SE, OldMarking);
                A.CurrentTime += DeltaT;
                simTime = A.CurrentTime;
                A.CurrentLocation = A.Edge[SE].Target;

                if (A.isFinal(A.CurrentLocation)) {
                    A.UpdateLinForm(OldMarking);
                    A.UpdateLhaFunc(A.CurrentTime, D);
                    A.UpdateFormulaVal();
                    Result.first = true;
                    Result.second = A.FormulaVal;

                    return;

                } else {
                    if (N.IsEnabled(E1_transitionNum)) {//check if the current transition is still enabled
                        GenerateEvent(F, E1_transitionNum);
                        (*EQ).replace(F, 0); //replace the transition with the new generated time
                        if (N.Transition[E1_transitionNum].AgeMemory) {
                            (*ActDate)[E1_transitionNum] = A.CurrentTime;
                            (*ResidualTime)[E1_transitionNum] = F.time - A.CurrentTime;
                        }

                    } else {
                        (*EQ).remove(0);
                        if (N.Transition[E1_transitionNum].AgeMemory) {
                            (*ActDate)[E1_transitionNum] = -1;
                        }
                    }

                    // Possibly adding Events corresponding to newly enabled-transitions

                    for (set<int>::iterator it = N.PossiblyEnabled[E1_transitionNum].begin(); it != N.PossiblyEnabled[E1_transitionNum].end(); it++) {
                        if (N.IsEnabled(*it)) {
                            if ((*EQ).TransTabValue(*it) < 0) {
                                if (N.Transition[(*it)].AgeMemory) {
                                    if ((*ActDate)[(*it)] == -1) {
                                        GenerateEvent(F, (*it));
                                        (*EQ).insert(F);
                                        (*ResidualTime)[(*it)] = F.time - A.CurrentTime;
                                    } else {
                                        GenerateEvent(F, (*it));
                                        F.time = A.CurrentTime + (*ResidualTime)[(*it)];
                                        (*EQ).insert(F);

                                    }
                                    (*ActDate)[(*it)] = A.CurrentTime;
                                } else {
                                    GenerateEvent(F, (*it));
                                    (*EQ).insert(F);
                                }


                            } else {
                                if (N.Transition[(*it)].MarkingDependent) {
                                    GenerateEvent(F, (*it));
                                    (*EQ).replace(F, (*EQ).TransTabValue(*it));

                                }

                            }
                        }

                    }

                    // Possibly removing Events corresponding to newly disabled-transitions
                    for (set<int>::iterator it = N.PossiblyDisabled[E1_transitionNum].begin(); it != N.PossiblyDisabled[E1_transitionNum].end(); it++) {
                        if ((*EQ).TransTabValue(*it)>-1) {
                            if (!N.IsEnabled(*it)) {
                                (*EQ).remove((*EQ).TransTabValue(*it));
                                if (N.Transition[(*it)].AgeMemory)
                                    (*ResidualTime)[(*it)] = (*ResidualTime)[(*it)]-(A.CurrentTime - (*ActDate)[(*it)]);
                            } else {
                                if (N.Transition[(*it)].MarkingDependent) {
                                    GenerateEvent(F, (*it));
                                    (*EQ).replace(F, (*EQ).TransTabValue(*it));

                                }
                            }
                        }
                    }

                    //
                    for (set<int>::iterator it = N.FreeMarkDepT[E1_transitionNum].begin(); it != N.FreeMarkDepT[E1_transitionNum].end(); it++) {

                        if (N.IsEnabled(*it)) {
                            if ((*EQ).TransTabValue(*it) < 0) {
                                GenerateEvent(F, (*it));
                                (*EQ).insert(F);


                            } else {
                                GenerateEvent(F, (*it));
                                (*EQ).replace(F, (*EQ).TransTabValue(*it));
                            }
                        }

                    }
                    AE = A.GetEnabled_A_Edges(A.CurrentLocation, N.Marking);
                    QueueIsEmpty = (*EQ).isEmpty();
                }
            }
        }
    }
}

void Simulator::GenerateEvent(Event& E, int Id) {

    double t = simTime;
    if (N.Transition[Id].transType == Timed) {
        vector<double> Param = N.GetDistParameters(Id);
        t += GenerateTime(N.Transition[Id].DistType, Param);
    }
    double w;
    vector<double> wParam(1, N.GetWeight(Id));
    string dist = "EXPONENTIAL";
    w = GenerateTime(dist, wParam);
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id);
    E.weight = w;

}

double Simulator::GenerateTime(string& distribution, vector<double> &param) {

    switch (IndexDist[distribution]) {
        case 1:
        {//UNIF
            boost::uniform_real<> UNIF(param[0], param[1]);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            return gen();
            break;
        }

        case 2:
        {//EXP
            //Exponential distribution is the only marking dependent parameters. Check of validity is required

            //-------------- Rare Event -----------------
            //cout << "rate:" << param[0] << endl;
            if ((param[0] == 0) && (RareEvent_mode)) {
                return 1e200;
            };
            //------------- /Rare Event -----------------

            if (param[0] <= 0) {
                cout << "Exponential ditribution should be with rate > 0\n End of Simulation" << endl;
                exit(1);
            }

            boost::exponential_distribution<> EXP(param[0]);
            boost::variate_generator<boost::mt19937&, boost::exponential_distribution<> > gen(RandomNumber, EXP);
            return gen();

        }

        case 3:
        {//DETERMINISTIC
            return param[0];
        }

        case 4:
        {//LogNormal
            boost::lognormal_distribution<> LOGNORMAL(param[0], param[1]);
            boost::variate_generator<boost::mt19937&, boost::lognormal_distribution<> > gen(RandomNumber, LOGNORMAL);
            return gen();
        }

        case 5:
        {//Triangle
            boost::triangle_distribution<> TRIANGLE(param[0], param[1], param[2]);
            boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > gen(RandomNumber, TRIANGLE);
            return gen();
        }
        case 6:
        {//GEOMETRIC
            boost::geometric_distribution<> GEO(1 - param[0]);
            boost::variate_generator<boost::mt19937&, boost::geometric_distribution<> > gen(RandomNumber, GEO);
            return param[1] * gen();

        }
        case 7:
        {//ERLANG           
            boost::uniform_real<> UNIF(0, 1);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            double prod = 1;
            for (int i = 0; i < param[0]; i++)
                prod = prod * gen();
            return -log(prod) / param[1];

        }
        case 8:
        {//GAMMA      
            boost::gamma_distribution<> GAMMA(param[0]);
            boost::variate_generator<boost::mt19937&, boost::gamma_distribution<> > gen(RandomNumber, GAMMA);
            return param[1] * gen();
        }

        default: cout << "\nUnknown distribution !" << endl;
            break;
    }
    return DBL_MIN;

}

#include "SimulatorRE.cpp"

BatchR* Simulator::RunBatch() {
    double Dif = 0;
    double Y = 0;
    BatchR* batchResult = new BatchR();

    while (batchResult->Isucc < BatchSize) {

        if (RareEvent_mode) {
            //cout << "rareevent";
            SimulateSinglePathRE();
        } else {
            //cout << "not rare event";
            SimulateSinglePath();
        };


        if (Result.first) {
            //------------------ Rare Event -----------------
            logvalue << Result.second << endl;
            //----------------- /Rare Event -----------------
            batchResult->Isucc++;

            if (Result.second * (1 - Result.second) != 0) batchResult->IsBernoulli = false;


            Dif = Result.second - batchResult->Mean;
            batchResult->Mean += Dif / batchResult->Isucc;

            Dif = pow(Result.second, 2) - batchResult->M2;
            batchResult->M2 += Dif / batchResult->Isucc;

            /*if (Isucc > 1) {
              Dif = pow(Result.second, 2) - Y;
              Y = Y + Dif / (Isucc - 1);
              } else x1sqr = pow(Result.second, 2);*/
        }

        reset();
        batchResult->I++;

    }

    return (batchResult);

}