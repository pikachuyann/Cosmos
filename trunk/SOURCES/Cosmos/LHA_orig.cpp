/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
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
 *******************************************************************************
 */

#include "LHA_orig.hpp"

#include <map>
#include <float.h>
#include <math.h>


using namespace std;

LHA_ORIG::LHA_ORIG() {
}

LHA_ORIG::~LHA_ORIG() {
}

/*void LHA_ORIG::printState(){
	cerr << "Automate:" << LocLabel[CurrentLocation]<< "\t,";
	for(size_t i =0 ; i< Var.size(); i++){
		cerr << VarLabel[i]<<":"<< Var[i]<< "\t,";
	}
}*/

int LHA_ORIG::EnabledInitLocation(const abstractMarking& Marking) {
    for (set<int>::iterator l = InitLoc.begin(); l != InitLoc.end(); l++) {
        if (CheckLocation((*l), Marking))
            return (*l);
    }
    return (-1);
}

int LHA_ORIG::GetEnabled_S_Edges(size_t PetriNetTransition, const abstractMarking& NextMarking,const abstractBinding& binding) {
    for (set<int>::iterator it = ActionEdges[CurrentLocation][PetriNetTransition].begin(); it != ActionEdges[CurrentLocation][PetriNetTransition].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, NextMarking))) {
            if (CheckEdgeContraints(*it, binding)) return (*it);
        }
    }

    return (-1);

}

AutEdge LHA_ORIG::GetEnabled_A_Edges(const abstractMarking& Marking) {
    AutEdge Ed;
    Ed.Index = -1;
    Ed.FiringTime = DBL_MAX;
    for (set<int>::iterator it = Out_A_Edges[CurrentLocation].begin(); it != Out_A_Edges[CurrentLocation].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, Marking))) {
            t_interval I = GetEdgeEnablingTime((*it), Marking);
            if (I.first <= I.second) {
                if (I.first < Ed.FiringTime) {
                    Ed.Index = (*it);
                    Ed.FiringTime = I.first;
                }

            }
        }
    }

    return Ed;


}

void LHA_ORIG::resetLinForms() {
    for (size_t i = 0; i < LinForm.size(); i++) {
        LinForm[i] = 0;
        OldLinForm[i] = 0;
    }
    for (size_t i = 0; i < LhaFunc.size(); i++)
        LhaFunc[i] = 0;
}

void LHA_ORIG::reset(const abstractMarking& Marking) {
  Likelihood = 1.0;
  resetLinForms();
	resetVariables();
  CurrentLocation = EnabledInitLocation(Marking);
  CurrentTime = 0;
}

void LHA_ORIG::setCurrentLocation(unsigned int loc) {
    CurrentLocation = loc;
}

bool LHA_ORIG::isFinal() {
    return ( (FinalLoc.find(CurrentLocation) != FinalLoc.end()) ? true : false);
}

double LHA_ORIG::min(double& a, double& b) {
    if (a <= b)return a;
    else return b;
}

double LHA_ORIG::max(double& a, double& b) {
    if (a >= b)return a;
    else return b;
}

double LHA_ORIG::Min(double& a, double& b, double& c) {
    double x = min(b, c);
    return min(a, x);
}

double LHA_ORIG::Max(double& a, double& b, double& c) {
    double x = max(b, c);
    return max(a, x);
}

double LHA_ORIG::Integral(double& OldInt, double& t, double& Delta, double& x, double& y) {
    if (x * y >= 0) return (OldInt + Delta * (x + y) / 2);
    double a = (y - x) / Delta;
    double b = x - a*t;
    double t0 = -b / a;
    return (OldInt + (t0 - t) * x / 2 + (t + Delta - t0) * y / 2);
}


