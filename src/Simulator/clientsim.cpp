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
 * file clientsim.cpp created by Benoit Barbot.                                *
 *******************************************************************************
 */

#include "BatchR.hpp"
#include "Simulator.hpp"
#include "SimulatorRE.hpp"
#include "SimulatorBoundedRE.hpp"
#include "SimulatorContinuousBounded.hpp"
#include "Polynome.hpp"
#include "MarkovChain.hpp"

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


//#include "Polynome.hpp"

// Handler for interuption of the server
void signalHandler(int);

void signalHandler( int s)
{
    if(s == SIGHUP )abort();
    //exit(EXIT_SUCCESS);
    
}

const int optioni=6;

template<class SIM>
void run_sim(SIM& sim,int argc,char **argv) {
    int verbose=atoi(argv[2]);
    
    sim.SetBatchSize(atoi(argv[1])); //set the batch size
    sim.initRandomGenerator(atoi(argv[5]));
    sim.tmpPath=argv[4];
    
    for(int i=1; i<argc ;i++){
        if(strcmp(argv[i],"-log")==0 && argc>i)
            sim.logValue(argv[i+1]);
        if(strcmp(argv[i],"-trace")==0 && argc>i){
            sim.logTrace(argv[i+1],stod(argv[i+2]));
        }
        if(strcmp(argv[i],"-dotFile")==0 && argc>i){
            sim.dotFile = argv[i+1];
        }
    }
    
    
    if(verbose>=4)sim.RunBatch();
    else while( !cin.eof() ){
        BatchR batchResult = sim.RunBatch(); //simulate a batch of trajectory
        
        batchResult.outputR(cout);// output the result on the standart output
        //batchResult.print();
        
        //cerr << batchResult->I <<":"<< batchResult->Isucc <<":"<< batchResult->Mean[0]
        //<< ":" << batchResult->M2[0] << endl;
        
    }
}


enum SimType {
    Base,
    RareEventUnbounded1,
    RareEventUnbounded2,
    RareEventBounded,
    RareEventCTMC,
    CTMC
};

template<class EQT>
void build_sim(SimType st,int argc,char **argv) {
    verbose=atoi(argv[2]);
    
    LHA_orig* Aptr;
    if(IsLHADeterministic){
        Aptr = new LHA_orig();
    }else{
        Aptr = new NLHA();
    }
    LHA_orig& A = *Aptr;
    
    switch(st){
        case Base:
        {
            auto &N = *(new SPN_orig<EQT>());
            auto sim = new Simulator<EQT,SPN_orig<EQT> >(N,A);
            run_sim(*sim,argc,argv);
        }
        case RareEventUnbounded1:
        case RareEventUnbounded2:
        {
            auto &N = *(new SPN_RE(st==RareEventUnbounded2));
            auto reSim = new SimulatorRE<SPN_RE>(N,A);
            reSim->initVect();
            run_sim(*reSim,argc,argv);
        }
        case RareEventBounded:
        {
            auto &N = *(new SPN_BoundedRE(false));
            int m = atoi(argv[optioni+1]);
            int T = atoi(argv[optioni+2]);
            auto boundedSim = new SimulatorBoundedRE<SPN_BoundedRE>(N,A,m);
            boundedSim->initVect(T);
            run_sim(*boundedSim,argc,argv);
        }
        case RareEventCTMC:
        {
            auto &N = *(new SPN_BoundedRE(false));
            int m = atoi(argv[optioni+1]);
            double t = atof(argv[optioni+2]);
            double e = atof(argv[optioni+3]);
            int stepc = atoi(argv[optioni+4]);
            auto coSim = new SimulatorContinuousBounded<SPN_BoundedRE>(N,A,m,e,stepc);
            coSim->initVectCo(t);
            run_sim(*coSim,argc,argv);
        }
        case CTMC:
        {
            auto &M = *(new MarkovChain<EventsQueue<vector<Edge>>>());
            auto sim = new Simulator<EventsQueue<vector<Edge>>, MarkovChain<EventsQueue<vector<Edge>>> >(M,A);
            run_sim(*sim,argc,argv);
        }
    }
}

/**
 * The verbose level global
 */
int verbose;


/**
 * main function it read the options given as arguments and initialyse
 * the simulator.
 * Then it start a while loop which compute a batch of trajectory
 * and output the result.
 * The loop stop only when the programme receive end_of_file on
 * his standart input
 */
int main(int argc, char** argv) {
    
    if(argc<optioni-1){
        cerr << "Not enough argument";
        return (EXIT_FAILURE);
    }
    
    SimType st = Base;
    
    string str;
    
    if(argc > optioni){
        str = argv[optioni];
        if(str== "-STSPBU"){
            stateSpace states;
            states.exploreStateSpace();
            states.buildTransitionMatrix();
            //states.uniformizeMatrix();
            states.outputMat();
            states.outputTmpLumpingFun();
            BatchR dummR(0,0);
            dummR.outputR(cout);
            cerr << "Finish Exporting" << endl;
            exit(EXIT_SUCCESS);
        }else if(str== "-STSP"){
            stateSpace states;
            states.exploreStateSpace();
            states.buildTransitionMatrix();
            states.outputPrism();
            states.launchPrism(argv[optioni+1]);
            states.importPrism();
            states.outputVect();
            states.outputTmpLumpingFun();
            //cout << "Finish Exporting" << endl;
            double prResult = states.returnPrismResult();
            BatchR dummR(1,0);
            SimOutput sd;
            sd.accept=true;
            sd.quantR.push_back(prResult);
            dummR.addSim(sd);
            dummR.outputR(cout);
            /*cout << "Prism Result:\t"<< prResult << endl;
             ofstream ResultsFile("Result.res", ios::out | ios::trunc);
             ResultsFile << "Result Computed by Prism:" << endl;
             ResultsFile << "Estimated value:\t" << prResult << endl;
             ResultsFile << "Confidence interval:\t[" <<prResult*0.9999;
             ResultsFile << " , " << prResult*1.00001 << "]" << endl;
             ResultsFile.close();*/
            exit(EXIT_SUCCESS);
        }
        
        if(str== "-RE"){
            st = RareEventUnbounded1;
        }else if(str== "-RE2"){
            st = RareEventUnbounded2;
        }else if(str== "-BURE"){
            st = RareEventBounded;
        }else if(str== "-COBURE"){
            st = RareEventBounded;
        }
        
    }
    
    bool is_domain_impl_set= (bool) atoi(argv[3]);
    if(is_domain_impl_set){
        build_sim<EventsQueueSet>(st,argc, argv);
    }else{
        build_sim<EventsQueue<vector<_trans>>>(st,argc, argv);
    }
    
    return (EXIT_SUCCESS);
    
}
