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


typedef pair <double, double> t_interval;

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


t_interval GetEdgeEnablingTime(int,const abstractMarking&);

/**
 * Class implementing the Linear Hybrid Automaton.
 * Part of the implementation is generated at runtime for efficiency.
 */
class LHA {
public:
	LHA();
	~LHA();

    const unsigned int NbLoc; // number of locations
    
    vector<double> FormulaVal;

    /**
     * Current time of the LHA
     */
	double CurrentTime;

    /**
     * Current location of the LHA
     */
	int CurrentLocation;

    /*
     * Curent likelihood.
     * Use only for importance sampling
     */
    double Likelihood;

	/**
	 *  Copy the state of an other LHA.
	 *  It only copy pointer thus is in constant time.
	 */
	void copyState(LHA*);
	
	/**
	 * \brief Return a synchronized edge for a given transition of the SPN.
	 */
	int GetEnabled_S_Edges(size_t, const abstractMarking&,const abstractBinding&)const;
	
	/**
	 * \brief Return an autonomous edge for a given marking.
	 */
	AutEdge GetEnabled_A_Edges(const abstractMarking&,const abstractBinding&)const;
	
	//! update value in the LHA by elapsing time
	void updateLHA(double DeltaT, const abstractMarking &);
	
	//! fire the transition of an LHA
	virtual void fireLHA(int,const abstractMarking&, const abstractBinding&);
	
	//! test if the automaton is in a final state
	bool isFinal()const;
    
	/**
	 * reset the automata to its initial state according to the
	 * marking of the SPN.
	 */
    void reset(const abstractMarking&);
	
	void getFinalValues(const abstractMarking&,vector<double>&);
	
	void printState(ostream &)const;
	void printHeader(ostream &)const;
	
private:
	vector <LhaEdge> Edge;

    set <int> InitLoc; // initial locations
    set <int> FinalLoc; // final locations

	Variables *Vars; // Var[i] value of the variable indexed by i
    Variables *tempVars;

	vector<double> LinForm;
    vector<double> OldLinForm;
    vector<double> LhaFunc;

	vector < set <int> > Out_A_Edges; // for a given location l returns the set of autonomous edges  starting from l
    static const int ActionEdgesAr[];

	vector<int> EdgeCounter;

	const int NbTrans;
    const int NbVar;

    vector <string> VarLabel;
    string label;
	vector <string> LocLabel;

	void UpdateFormulaVal();
	void UpdateLinForm(const abstractMarking&);
	void UpdateLhaFuncLast();
	
	/**
	 * \brief Set the initial location of the LHA for a marking
	 * Loop over the set of initial location to find one enabled.
	 */
	void setInitLocation(const abstractMarking&);
	
	
	void DoElapsedTimeUpdate(double, const abstractMarking&);
    
	void UpdateLhaFunc( double&);

	
	void DoEdgeUpdates(int, const abstractMarking&, const abstractBinding&);
	double GetFlow(int, const abstractMarking&)const;
	bool CheckLocation(int,const abstractMarking&)const;
	bool CheckEdgeContraints(int,size_t, const abstractBinding&, const abstractMarking&)const;
	
    t_interval GetEdgeEnablingTime(int,const abstractMarking&)const;
	
	void resetVariables();
	
	
	void doPathVarsUpdate(double, double, const abstractMarking&);
	
	
	
    void ViewEdge(int);
    void ViewAllEdges();

	
	void resetPathVarsTable();
	
	bool isVar(string, double &);
	
	void resetLinForms();

    double Min(double, double, double);
    double Max(double, double, double);
    double Integral(double, double, double, double, double);
    double BoxedIntegral(double OldInt, double t, double Delta, double x, double y, double t1,double t2);

};

#endif	/* _LHA_HPP */

