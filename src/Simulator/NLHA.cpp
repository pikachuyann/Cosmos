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
 * file NLHA.cpp created by Benoit Barbot on 05/08/15.                         *
 *******************************************************************************
 */

#include <float.h>

#include "NLHA.hpp"

using namespace std;

void NLHA::setInitLocation(const abstractMarking& Marking) {
    for (auto &l : InitLoc) {
        if (CheckLocation(l, Marking)){
            powerSetState->emplace(l,*Vars);
        }
    }
}

void NLHA::reset(const abstractMarking& Marking) {
    fullState fs;
    Vars = fs.var;
    resetVariables();
    powerSet[0].clear();
    powerSet[1].clear();
    powerSetState = &powerSet[0];
    selectPS=0;
    setInitLocation(Marking);
    CurrentTime = 0;
}

void NLHA::printState(ostream& s){
    s << "{";
    for(let fs : *powerSetState){
        Vars=fs.var;
        CurrentLocation=fs.loc;
        LHA::printState(s);
        s << ", ";
    }
    s << "} ";
}

void NLHA::updateLHA(double DeltaT, const abstractMarking &Marking){
    for(let fs : *powerSetState){
        Vars = fs.var;
        CurrentLocation=fs.loc;
        DoElapsedTimeUpdate(DeltaT, Marking);
    }

    CurrentTime += DeltaT;
}


/*
 In Non deterninistic LHA this function actually compute the new state. Fire will
 do nothing.
 */
int NLHA::GetEnabled_S_Edges(size_t PetriNetTransition, const abstractMarking& NextMarking,const abstractBinding& binding) {
    auto &newPS = powerSet[1-selectPS];
    for(let fs : *powerSetState){
        const auto fs2 = fs;
        Vars = fs.var;
        CurrentLocation=fs.loc;

        const size_t mult = NbLoc*NbTrans;
        for (int i =1 ; i <= LHA::ActionEdgesAr[NbTrans*CurrentLocation+ PetriNetTransition]; i++){
            //cerr << i << endl;
            const int it = ActionEdgesAr[NbTrans*CurrentLocation+ PetriNetTransition+i*mult];
            //cerr << it << endl;
            if ((CheckLocation(Edge[it].Target, NextMarking))) {
                if (CheckEdgeContraints(it,PetriNetTransition, binding, NextMarking)){
                    //Valid transition compute new state
                    DoEdgeUpdates(it, NextMarking, binding);
                    CurrentLocation = Edge[it].Target;
                    //Add it to the set of next state
                    newPS.emplace(CurrentLocation,*Vars);
                    //Restore the current state.
                    Vars=fs2.var;
                    CurrentLocation=fs2.loc;
                }
            }
        }
    }
    if(newPS.empty()){
        return (-1);
    }else{
        selectPS= 1- selectPS;
        powerSetState=&powerSet[selectPS];
        powerSet[1-selectPS].clear();
        return 1;
    }

}

void NLHA::getFinalValues(const abstractMarking& m,vector<double>& v,vector<bool>& v2){
    for(size_t i=0; i< FormulaValQual.size();i++){
        v2[i] = false;
    }
    for(let fs : *powerSetState){
        Vars = fs.var;
        CurrentLocation=fs.loc;
        UpdateFormulaVal();
        for(size_t i=0; i< FormulaValQual.size();i++){
            v2[i] = v2[i] || FormulaValQual[i];
        }
    }
}

AutEdge NLHA::GetEnabled_A_Edges(const abstractMarking& Marking,const abstractBinding& db)const {
    AutEdge Ed;
    Ed.Index = -1;
    Ed.FiringTime = DBL_MAX;
    return Ed;
}

void NLHA::fireLHA(int,const abstractMarking&, const abstractBinding&){};

bool NLHA::isFinal()const{
    for(let fs : *powerSetState){
        if(FinalLoc[fs.loc])return true;
    }
    return false;
}


