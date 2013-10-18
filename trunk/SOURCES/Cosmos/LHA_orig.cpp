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
 * with this program; if not, write to the Free Software Foundation, Inc.,     *·
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 *******************************************************************************
 */

#include "LHA.hpp"

#include <map>
#include <float.h>
#include <math.h>


using namespace std;

LHA::~LHA() {
}

void LHA::copyState(LHA *A){
	Vars = A->Vars;
	LinForm.swap(A->LinForm);
	OldLinForm.swap(A->OldLinForm);
	LhaFunc.swap(A->LhaFunc);
	Likelihood = A->Likelihood;
	CurrentTime =A->CurrentTime;
	CurrentLocation=A->CurrentLocation;
}

/**
 *	Set the automaton to its initial location.
 * If the automaton contain several initial state only one should satisfie
 * its invarient with the given Marking due to determinicity.
 * @param Marking, A marking of the Petri net in principle the initial marking.
 */
void LHA::setInitLocation(const abstractMarking& Marking) {
    for (set<int>::iterator l = InitLoc.begin(); l != InitLoc.end(); l++) {
        if (CheckLocation((*l), Marking)){
            CurrentLocation = (*l);
			return;
		}
    }
	
    cerr << "There is no initial location enabled with the initial marking" << endl;
	exit(EXIT_FAILURE);
}

/**
 *	Return a sychronized edge index with a transition.
 * The edge is such that the location invariant will holds in the marking of the
 * Petri net after the transition.
 * @param PetriNetTransition, a Petri net transition index.
 * @param bindin, the color binding of the transition.
 * @param NextMarking, The marking in with the Petri net will be after the transition.
 * @return an index of synchronized edge or -1 if there is no suitable synchronized edge.
 */
int LHA::GetEnabled_S_Edges(size_t PetriNetTransition, const abstractMarking& NextMarking,const abstractBinding& binding)const {
	const set<int> acE = ActionEdges[CurrentLocation][PetriNetTransition];
    for (set<int>::const_iterator it = acE.begin(); it != acE.end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, NextMarking))) {
            if (CheckEdgeContraints(*it,PetriNetTransition, binding, NextMarking)) return (*it);
        }
    }

    return (-1);

}

/**
 *	Return the next autonomous edge.
 *	@param Marking is the current marking of the Petri net.
 *	@return the most urgent autonomous edge
 */
AutEdge LHA::GetEnabled_A_Edges(const abstractMarking& Marking)const {
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

/**
 * Reset all linear form.
 */
void LHA::resetLinForms() {
    for (size_t i = 0; i < LinForm.size(); i++) {
        LinForm[i] = 0;
        OldLinForm[i] = 0;
    }
    for (size_t i = 0; i < LhaFunc.size(); i++)
        LhaFunc[i] = 0;
}

/**
 *	Reset the whole automaton to its initial state for
 * the given Marking.
 */
void LHA::reset(const abstractMarking& Marking) {
  Likelihood = 1.0;
  resetLinForms();
  resetVariables();
  setInitLocation(Marking);
  CurrentTime = 0;
}

/**
 * This function makes the automaton takes an edge.
 * The edge can be either a autonomous or a synchronize on.
 * @param EdgeIndex the number of the edge of the LHA
 * @param M is the marking of the SPN
 * @param b a binding of the colored variable of the SPN for the transition.
 */
void LHA::fireLHA(int EdgeIndex,const abstractMarking &M, const abstractBinding &b){
	DoEdgeUpdates(EdgeIndex, M, b);
	CurrentLocation = Edge[EdgeIndex].Target;
}

/**
 * This function makes time elapse in the automaton.
 * @param DeltaT the ammout of time the automaton should wait.
 * @param Marking is the Marking of the SPN.
 */
void LHA::updateLHA(double DeltaT, const abstractMarking &Marking){
	DoElapsedTimeUpdate(DeltaT, Marking);
	UpdateLinForm(Marking);
	UpdateLhaFunc(DeltaT);
	CurrentTime += DeltaT;
}

/**
 *	This function is called when the automaton reach a final state.
 *	The result of path formula is stored in vector v
 */
void LHA::getFinalValues(const abstractMarking& m,vector<double>& v){
	UpdateLinForm(m);
	UpdateLhaFuncLast();
	UpdateFormulaVal();
	v=FormulaVal;
}

/**
 * @return true if the automaton is in a final state
 */
bool LHA::isFinal()const {
    return ( (FinalLoc.find(CurrentLocation) != FinalLoc.end()) ? true : false);
}

double LHA::Min(double& a, double& b, double& c) {
    double x = min(b, c);
    return min(a, x);
}

double LHA::Max(double& a, double& b, double& c) {
    double x = max(b, c);
    return max(a, x);
}

double LHA::Integral(double& OldInt, double& t, double& Delta, double& x, double& y) {
    if (x * y >= 0) return (OldInt + Delta * (x + y) / 2);
    double a = (y - x) / Delta;
    double b = x - a*t;
    double t0 = -b / a;
    return (OldInt + (t0 - t) * x / 2 + (t + Delta - t0) * y / 2);
}


