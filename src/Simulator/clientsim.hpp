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
 * file clientsim.hpp created by Benoît Barbot on 16/01/2017.                  *
 *******************************************************************************
 */


#ifndef clientsim_h
#define clientsim_h

#include "BatchR.hpp"
#include "Simulator.hpp"
#include "SimulatorRE.hpp"
#include "SimulatorBoundedRE.hpp"
#include "SimulatorContinuousBounded.hpp"
#include "Polynome.hpp"
#include "MarkovChain.hpp"

// Handler for interuption of the server
void signalHandler(int);

template<class SIM>
void setSimulator(SIM& sim,int argc, char* argv[] ){
    if( argc ==0){
        sim.initRandomGenerator(0);
        return;
    }
    verbose=atoi(argv[2]);
    
    sim.SetBatchSize(atoi(argv[1]));
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
}




#endif /* clientsim_h */
