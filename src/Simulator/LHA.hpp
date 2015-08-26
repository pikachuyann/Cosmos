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

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <memory>

#include "spn.hpp"
#include "marking.hpp"

#include <stdlib.h>

#ifndef _LHA_HPP
#define	_LHA_HPP


typedef std::pair <double, double> t_interval;

using namespace std;

//!< A simple type to know if an edge is synchronize with the SPN.
enum EdgeType {
    Auto, Synch
};

/**
 * Type for edge of the LHA.
 */
struct LhaEdge {
    unsigned int Index;
    unsigned int Source;
    unsigned int Target;
    EdgeType Type;
    LhaEdge():Index(0),Source(0),Target(0),Type(Auto){};
    LhaEdge(unsigned int i,unsigned int s,unsigned int t,const EdgeType &ty):Index(i),Source(s),Target(t),Type(ty){};
};


/**
 * Auto edge need a firing time
 */
struct _AutEdge {
    int Index;
    double FiringTime;
};
typedef struct _AutEdge AutEdge;

/**
 * Strucuture for the variable of the automaton.
 * Implementation is provide only at runtime.
 */
struct Variables;
/**
 Strict order on valuation set provide at runtime.
 */
bool varOrder(const Variables &,const Variables &);

t_interval GetEdgeEnablingTime(int,const abstractMarking&);

extern bool IsLHADeterministic;

/**
 * Class implementing the Linear Hybrid Automaton.
 * Part of the implementation is generated at runtime for efficiency.
 */
class LHA {
public:
	LHA();

    const unsigned int NbLoc; // number of locations

    /**
     * Current location of the LHA
     */
    int CurrentLocation;

    /**
     * Current time of the LHA
     */
    double CurrentTime;

    vector<double> FormulaVal;
    vector<bool> FormulaValQual;

    void printHeader(ostream &)const;
    virtual void printState(ostream &);
	
protected:
	vector <LhaEdge> Edge;

    set <int> InitLoc; // initial locations
    vector<bool> FinalLoc; // final locations

	Variables *Vars; // Var[i] value of the variable indexed by i
    Variables *tempVars;

	vector<double> LinForm;
    vector<double> OldLinForm;
    vector<double> LhaFunc;

	vector < set <int> > Out_A_Edges; // for a given location l returns the set of autonomous edges  starting from l
    static const int ActionEdgesAr[];

	const int NbTrans;
    const int NbVar;

    vector <string> VarLabel;
    string label;
	vector <string> LocLabel;

    void resetVariables();
    void DoElapsedTimeUpdate(double, const abstractMarking&);
    double GetFlow(int, const abstractMarking&)const;
    bool CheckLocation(int,const abstractMarking&)const;
    bool CheckEdgeContraints(int,size_t, const abstractBinding&, const abstractMarking&)const;
    t_interval GetEdgeEnablingTime(int,const abstractMarking&)const;
    void DoEdgeUpdates(int, const abstractMarking&, const abstractBinding&);
	void UpdateLinForm(const abstractMarking&);
	void UpdateLhaFunc( double&);
	void UpdateFormulaVal();

};

class fullState {
public:
    int loc;
    Variables* var;
    inline bool operator< (const fullState& other)const {
        return this->loc < other.loc
        || (this->loc == other.loc && varOrder( *(this->var), *(other.var)));
    }
    fullState();
    fullState(int l,const Variables &v);
    fullState(const fullState&);
    ~fullState();

};
#endif	/* _LHA_HPP */

