/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *                                                                             *
 *******************************************************************************
 */

#ifndef _SPN_HPP
#define	_SPN_HPP
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
using namespace std;

enum TransType {
    Timed, unTimed
};

struct _trans {
    unsigned int Id;
    string label;
    TransType transType; // Time or unTimed
    string DistType;
    vector<string> DistParams;
    string priority;
    string weight;
    bool MarkingDependent; // true if the transition is Marking Dependent
    bool AgeMemory; // true if the memory policy of the transition is age memory
};
typedef struct _trans spn_trans;

struct _place {
    unsigned int Id;
    string label;
};
typedef struct _place spn_place;

typedef vector <int> Dim1;
typedef vector <int> IntVector;
typedef vector <Dim1> Dim2;
typedef vector <IntVector> IntMatrix;

class SPN {
public:
    SPN();
    void Load();
    SPN(const SPN& orig);
    virtual ~SPN();
    string Path;
    int pl; // Number of places
    int tr; // Number of transitions
    set<int, less<int> > enTrans; // the set of current enabled transition
    // IntMatrix* PossiblyEnabled; //a matrix, where a row t of PossiblyEnabled refers to transitions that may be enabled after firing t
    //  IntMatrix* PossiblyDisabled; //a matrix, where a row t of PossiblyDisabled refers to transitions that may be disabled after firing t
    //  IntMatrix* FreeMarkDepT; //a matrix, where a row t of FreeMarkDepT refers to transitions which are marking dependent
    //but are not in (PossiblyEnabled[t] or PossiblyDisabled[t])

    vector< set<int> > PossiblyEnabled;
    vector< set<int> > PossiblyDisabled;
    vector< set<int> > FreeMarkDepT;

    vector <int> Marking; // Current marking
    vector <int> initMarking; //initial marking
    IntMatrix inArcs; // input arcs
    IntMatrix outArcs; //output arcs
    IntMatrix inhibArcs; // inhibitor arcs

    vector <spn_trans> Transition; //contains all the transitions of the Petri net
    vector <spn_place> Place; //contains all the places of the Petri net
    vector < vector<int> > PredT; // to be deleted

    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}





    double min(double, double); //return the minimum of two numbers
    double max(double, double); //return the maximum of two numbers




    vector<int> getMarking(); //return  the current marking

    set<int, less <int> > enabledTrans(); // return the set of enabled transitions


    void EnabledDisabledTr(); // contruct for each transition t, the vector of transitions that may be enabled (PossiblyEnabled) and the vector of transitions that may be disabled (PossiblyDisabled) after firing t
    set<int> PossiblyEn(int); // for a given transition t, return the vector of transitions that may be enabled after firing t  (it is the row t of PossiblyEnabled)
    set<int> PossiblyDis(int); // for a given transition t, return the vector of transitions that may be disabled after firing t  (it is the row t of PossiblyDisabled)


    void reset(); // set the marking to the initial marking
    void setMarking(vector<int>&); // set the marking to a given marking



    void fire(int); // fire a given transition
    bool IsEnabled(int); // Check if a given transition is enabled
    vector<double> GetDistParameters(int); // compute the the parameters value of a given distribution 
    double GetWeight(int); // compute the the weight value of a given transition
    double GetPriority(int); // compute the the priority value of a given transition


    //private:
    //};
    //#endif	/* _SPN_HPP */
