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
struct _LhaEdge {
    unsigned int Index;
    unsigned int Source;
    unsigned int Target;
    EdgeType Type;
};
typedef struct _LhaEdge LhaEdge;

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
	//virtual void Load();
	LHA(unsigned int, unsigned int);
	~LHA();
	
  /**
   * \brief Return a synchronized edge for a given transition of the SPN.
   */
  int GetEnabled_S_Edges(size_t, const abstractMarking&,const abstractBinding&)const;

   /**
   * \brief Return an autonomous edge for a given marking.
   */
  AutEdge GetEnabled_A_Edges(const abstractMarking&)const;
	
	//! update value in the LHA by elapsing time
	void updateLHA(double DeltaT, const abstractMarking &);
	
    void UpdateFormulaVal();
	void UpdateLinForm(const abstractMarking&);
	void UpdateLhaFuncLast();

	
	//! fire the transition of an LHA
	virtual void fireLHA(int,const abstractMarking&, const abstractBinding&);

	bool isFinal()const;
    
    void reset(const abstractMarking&);

	vector<double> FormulaVal;
	void printState(ostream &)const;
	void printHeader(ostream &)const;
	
	double CurrentTime;
	int CurrentLocation;
	
	vector <LhaEdge> Edge;
	
	

	
	double Likelihood;
	Variables *Vars; // Var[i] value of the variable indexed by i
	
	vector<double> LinForm;
    vector<double> OldLinForm;
    vector<double> LhaFunc;


	set <int> FinalLoc; // final locations
private:
	
	
	
	/**
	 * \brief Set the initial location of the LHA for a marking
	 * Loop over the set of initial location to find one enabled.
	 */
	void setInitLocation(const abstractMarking&);

	
	void DoElapsedTimeUpdate(double, const abstractMarking&);
    
	void UpdateLhaFunc( double&);
	
	
	set <int> InitLoc; // initial locations
	
	
	void DoEdgeUpdates(int, const abstractMarking&, const abstractBinding&);
	double GetFlow(int, int,const abstractMarking&)const;
	bool CheckLocation(int,const abstractMarking&)const;
	bool CheckEdgeContraints(int,size_t, const abstractBinding&, const abstractMarking&)const;
	
    t_interval GetEdgeEnablingTime(int,const abstractMarking&)const;
	
	void resetVariables();
	
		
	void doPathVarsUpdate(double, double, const abstractMarking&);
	
	
	
    void ViewEdge(int);
    void ViewAllEdges();
	
	



	
	
	Variables *tempVars;
	
		
	void resetPathVarsTable();
	
	bool isVar(string, double &);
	
	void resetLinForms();
	
	//print the state of the automaton.
	
	string label;
	unsigned int NbLoc; // number of locations   
	unsigned int StartingLoc; // Chosen from the set of lha initial locations according to their properties and Petri net initial marking
	
	
	map <string, int> LocIndex; //for a given Location label returns its index among {0, 1, ..., NLoc-1}
	vector <string> LocLabel;
	
	vector <string> StrLocProperty;
	
	
	
	map<string, int> EdgeIndex;
	
	vector < set <int> > Out_S_Edges; // for a given location l returns the set of synchronizing edges  starting from l
	vector < set <int> > Out_A_Edges; // for a given location l returns the set of autonomous edges  starting from l   
	vector < vector < set <int> > > ActionEdges; // ActionEdges[a][e]={t1, t2, ...} 
	
	vector<int> EdgeCounter;
	vector <string> EdgeConstraints;
	vector < set<string> > EdgeActions;
	vector <string> StrEdgeUpdates;
	
	vector < vector <vector <string> > > ConstraintsCoeffs;
	vector < vector <string> > ConstraintsRelOp;
	vector < vector <string> > ConstraintsConstants;
	
	
	
	
    int NbVar;
    
    vector <double> OldVar;
    map<string, int> VarIndex; //for a given variable label return its index among {0, 1, ..., NbVar-1}
    vector <string> VarLabel;
	
	
    vector < vector <string> > StrFlow;
	
	
	
    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}
	
	
    //double min(double&, double&);
    //double max(double&, double&);
	
    double Min(double&, double&, double&);
    double Max(double&, double&, double&);
    double Integral(double&, double&, double&, double&, double&);
	
	double OldFormulaVal;
    
};

#endif	/* _LHA_HPP */

