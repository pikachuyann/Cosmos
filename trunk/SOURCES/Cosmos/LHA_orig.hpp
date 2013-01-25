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

#include "spn_orig.hpp"

#include <stdlib.h>

#ifndef _LHA_ORIG_HPP
#define	_LHA_ORIG_HPP


typedef pair <double, double> t_interval;

using namespace std;

enum EdgeType {
    Auto, Synch
};

struct _LhaEdge {
    unsigned int Index;
    unsigned int Source;
    unsigned int Target;
    EdgeType Type;
};
typedef struct _LhaEdge LhaEdge;

struct _AutEdge {
    int Index;
    double FiringTime;
	
};
typedef struct _AutEdge AutEdge;

class LHA_ORIG {
public:
	LHA_ORIG();
	//virtual void Load();
	LHA_ORIG(unsigned int, unsigned int);
	~LHA_ORIG();
	
	void printState();
	//print the state of the automaton.
	
	double Likelihood;
	string label;
	unsigned int NbLoc; // number of locations   
	unsigned int StartingLoc; // Chosen from the set of lha initial locations according to their properties and Petri net initial marking
	
	set <int> InitLoc; // initial locations
	set <int> FinalLoc; // final locations
	
	double CurrentTime;
	int CurrentLocation;
	
	map <string, int> LocIndex; //for a given Location label returns its index among {0, 1, ..., NLoc-1}
	vector <string> LocLabel;
	
	vector <string> StrLocProperty;
	
	
	
	map<string, int> EdgeIndex;
	vector <LhaEdge> Edge;
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
    vector <double> Var; // Var[i] value of the variable indexed by i
    vector <double> OldVar;
    map<string, int> VarIndex; //for a given variable label return its index among {0, 1, ..., NbVar-1}
    vector <string> VarLabel;
	
	
    vector < vector <string> > StrFlow;
	
	
	
    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}
	
	
	
	
	
	
    int EnabledInitLocation(vector<int>&);
	
  virtual double GetFlow(int, int, vector<int>&) = 0;
  virtual bool CheckLocation(int, vector<int>&) = 0;
  virtual bool CheckEdgeContraints(int) = 0;
	
    virtual t_interval GetEdgeEnablingTime(int, vector<int>&) = 0 ;
	
	
    int GetEnabled_S_Edges(int, vector<int>&);
    AutEdge GetEnabled_A_Edges(vector<int>&);
	
	
    void DoElapsedTimeUpdate(double, vector<int>&);
	
    void setCurrentLocation(unsigned int);
	
    //virtual void DoEdgeUpdates(int, vector<int>&);
    
	void doPathVarsUpdate(double, double, vector<int>&);
	
	
	
	
	
	
    bool isFinal();
    void resetVarsTable();
    void resetPathVarsTable();
    void reset(vector<int>&);
	
    void ViewEdge(int);
    void ViewAllEdges();
	
	
	
	
	
    bool isVar(string, double &);
	
    double min(double&, double&);
    double max(double&, double&);
	
    double Min(double&, double&, double&);
    double Max(double&, double&, double&);
    double Integral(double&, double&, double&, double&, double&);
	
    vector<double> LinForm;
    vector<double> OldLinForm;
    vector<double> LhaFunc;
    vector<double> FormulaVal;
    double OldFormulaVal;
    
    /*vector<double> FormulaVal;
	 vector<double> OldFormulaVal;*/
    
    //virtual void UpdateFormulaVal();
    //virtual void UpdateLinForm(vector<int>&);
    //virtual void UpdateLhaFunc(double&, double&);
	
	
	
	
	
	
	
	
    //private:
	
};

#endif	/* _LHA_ORIG_HPP */

