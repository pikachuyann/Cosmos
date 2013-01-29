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

#ifndef _SPN_HPP
#define	_SPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>

#include "marking.hpp"

#include <stdlib.h>


using namespace std;


enum TransType {
    Timed, unTimed
};

struct _trans {
    unsigned int Id;
    string label;
    TransType transType; // Time or unTimed
    string DistType;
	int DistTypeIndex;
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



//#include "spn_orig.hpp"
class SPN {
public:
	SPN();
	
	const int pl; // Number of places
    const int tr; // Number of transitions
	
    vector <spn_trans> Transition; //contains all the transitions of the Petri net
    vector <spn_place> Place; //contains all the places of the Petri net
    
	abstractMarking Marking; // Current marking
	vector<int> getMarking(); //return  the current marking
	
	void reset(); // set the marking to the initial marking
	
	
	string Path;
	
	vector<double> ParamDistr;
	
	//------------------------- Rare Event -------------------------------------
	vector <double> Rate_Table;
	vector <double> Origine_Rate_Table;
	double Rate_Sum;
	double Origine_Rate_Sum;
	vector <int> Msimpletab; //special places
	//-------------------------/Rare Event -------------------------------------
	
	 
	//void Load();
	bool IsEnabled(const int); // Check if a given transition is enabled
	
	void fire(int); // fire a given transition
    void unfire(int); // unfire a given transition
	void setConditionsVector();
	
	void GetDistParameters(int); // compute the the parameters value of a given distribution 
	//------------------------- Rare Event ---------------------------------------
	//vector<double> GetDistParametersOrigin(int);
    void lumpingFun(vector<int>*); 
	//-------------------------/Rare Event ---------------------------------------
	
	
    double GetWeight(int); // compute the the weight value of a given transition

    double GetPriority(int); // compute the the priority value of a given transition
	
	const set<int>* PossiblyEn(); // return the set of transitions that may be enabled after firing the last transition
    const set<int>* PossiblyDis(); // return the set of transitions that may be disabled after firing the last transition
	const set<int>* FreeMarkingDependant(); //return the set of transition without constrain but marking dependant
private:
	size_t lastTransition;
	
	
	vector< set<int> > PossiblyEnabled;
    vector< set<int> > PossiblyDisabled;
    vector< set<int> > FreeMarkDepT;
	
	//------------------------- On the fly enabling disabling transition--------
	vector<int> TransitionConditions;
	vector<int> initTransitionConditions;
	//-------------------------/On the fly enabling disabling transition--------
	
	
	//------------------------- Rare Event ---------------------------------------
	void Msimple();
	//-------------------------/Rare Event ---------------------------------------
	
	double min(double, double); //return the minimum of two numbers
    double max(double, double); //return the maximum of two numbers

	
};
#endif	/* _SPN_HPP */
