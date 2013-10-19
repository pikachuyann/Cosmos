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


/**
 * This classe is the interface for SPN
 */

#ifndef _SPN_HPP
#define _SPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <assert.h>

#include "marking.hpp"
#include <limits.h>
#include <stdlib.h>


using namespace std;

/**
 * Type of probability distribution
 */
enum DistributionType {
	GAMMA,
	UNIFORM,
	EXPONENTIAL,
	DETERMINISTIC,
	LOGNORMAL,
	TRIANGLE,
	GEOMETRIC,
	ERLANG,
	DISCRETEUNIF,
	MASSACTION
};


enum TransType {
	Timed, unTimed
};

/**
 * Datatype for transition of the SPN
 */
struct _trans {
	_trans(){};
	
	//! transition constructor
	_trans(unsigned int id,TransType tt,DistributionType dti,bool MD,size_t nbb):
	Id(id),transType(tt),DistTypeIndex(dti),MarkingDependent(MD),AgeMemory(false),bindingLinkTable(nbb,string::npos){
		abstractBinding bl;
		bl.idcount = bindingList.size();
		bindingList.push_back( bl );
		bindingLinkTable[bl.idTotal()]= bindingList.size()-1;
	};
	
	//! number of the transition
	unsigned int Id;
	
	//! Name of the transition, can be empty
	string label;
	TransType transType;
	DistributionType DistTypeIndex;
	
	//! Parameter in string format only for debug
	vector<string> DistParams;
	//! priority in string format only for debug
	string priority;
	//! weight in string format only for debug
	string weight;
	//! true if the transition is Marking Dependent
	bool MarkingDependent;
	//! true if the memory policy of the transition is age memory
	bool AgeMemory;
	//! List of alowed binding for this transition.
	vector<abstractBinding> bindingList;
	//! Table to access bindings of the transition.
	vector<size_t> bindingLinkTable;
};
typedef struct _trans spn_trans;

/**
 * DataType for place of the SPN
 */
struct _place {
	_place():isTraced(true){};
	
	//! name of the place, can be empty
	string label;
	
	//! set to true if the place should appear in outputted trace
	bool isTraced;
};
typedef struct _place spn_place;


/**
 * \brief Class of the SPN.
 *
 * All the implementation of this class are generated at runtime.
 */
class SPN {
public:
	//! Initialize all the data
	SPN();
	
	//! Number of places
	const size_t pl;
	//! Number of transitions
	const size_t tr;
	//! Current marking
	abstractMarking Marking;
	
	//!contains all the transitions of the Petri net
	vector <spn_trans> Transition;
	//!contains all the places of the Petri net
	vector <spn_place> Place;
	
	//! set the marking to the initial marking
	void
	reset();
	
	//! The path of the file use to generate the implementation
	string Path;
	
	/**
	 * \brief A vector use to store temporary parameters value.
	 * This vector is used to to store parameter of distribution
	 * When the simulator ask for parameters the function GetDistParameter
	 * store them inside this vector.
	 * This is done to avoid allocating a new vector too frequently.
	 */
	mutable vector<double> ParamDistr;
	
	//------------------------- Rare Event -------------------------------------
	vector <double> Rate_Table;
	vector <double> Origine_Rate_Table;
	double Rate_Sum;
	double Origine_Rate_Sum;
	vector <int> Msimpletab; //special places
	
	void Msimple();
	void print_state(const vector<int>&);
	void lumpingFun(const abstractMarking& ,vector<int>&);
	//-------------------------/Rare Event -------------------------------------
	
	/**
	 * \brief Check if a given transition is enabled.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	bool
	IsEnabled(size_t tr,const abstractBinding& b)const;
	
	/**
	 * \brief fire a given transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void
	fire(size_t tr,const abstractBinding& b);
	
	/**
	 * \brief unfire a given transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * This function is only used for rare event
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void unfire(size_t tr,const abstractBinding& b);
	
	
	void setConditionsVector();
	
	/**
	 * \brief compute the the parameters value of a given
	 * transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void GetDistParameters(size_t tr, const abstractBinding& b)const;
	
	//! compute the the weight value of a given transition
	double GetWeight(size_t)const;
	
	//! compute the the priority value of a given transition
	double GetPriority(size_t)const;
	
	//! return the set of transitions that may be enabled after firing the last transition
	const set<int >* PossiblyEn()const;
	
	//! return the set of transitions that may be disabled after firing the last transition
	const set<int >* PossiblyDis()const;
	
	//!return the set of transition without constrain but marking dependant
	const set<int >* FreeMarkingDependant()const;
	
	abstractBinding* nextPossiblyEnabledBinding(size_t tr,const abstractBinding& b,size_t*);
	abstractBinding* nextPossiblyDisabledBinding(size_t tr,const abstractBinding& b,size_t*);
	
private:
	size_t lastTransition; //! store the last fired transition
	
	
	vector< set<int > > PossiblyEnabled;
	vector< set<int > > PossiblyDisabled;
	vector< set<int > > FreeMarkDepT;
	
	//------------------------- On the fly enabling disabling transition--------
	vector<int> TransitionConditions;
	vector<int> initTransitionConditions;
	//-------------------------/On the fly enabling disabling transition--------
	
	
};
#endif  /* _SPN_HPP */
