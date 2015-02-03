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

#include <limits.h>
#include <stdlib.h>


#ifndef Cosmos_marking_h
#define Cosmos_marking_h





class abstractMarkingImpl;

class abstractMarking {
public:
    /**
     * Pointer to to the actual marking inmplementation
     * which is generated.
     */
    abstractMarkingImpl* P;

    abstractMarking();
    abstractMarking(const std::vector<int>& m);
    abstractMarking(const abstractMarking& m);
    abstractMarking& operator = (const abstractMarking& m);
    ~abstractMarking();

    //! Swap marking in constant time
    void swap(abstractMarking& m);
    void printHeader(std::ostream &)const;
    void print(std::ostream &)const;
    void printSedCmd(std::ostream &)const;
    void resetToInitMarking();
    int getNbOfTokens(int)const;
    std::vector<int> getVector()const;
    void setVector(const std::vector<int>&);
    
};

typedef char abstractBinding;


inline bool contains(int i, int j){ return i>=j;}
#endif

/**
 * Type of probability distribution
 */
enum DistributionType {
    NORMAL,
    GAMMA,
    UNIFORM,
    EXPONENTIAL,
    DETERMINISTIC,
    LOGNORMAL,
    TRIANGLE,
    GEOMETRIC,
    ERLANG,
    DISCRETEUNIF,
    MASSACTION,
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
	_trans(unsigned int id,TransType tt,DistributionType,bool MD,size_t,bool am):
    Id(id),transType(tt),MarkingDependent(MD),AgeMemory(am){};

    _trans(unsigned int id,TransType tt,DistributionType,bool MD,size_t,bool am,std::string l):
    Id(id),label(l),transType(tt),MarkingDependent(MD),AgeMemory(am){};
	
	//! number of the transition
	unsigned int Id;
	
	//! Name of the transition, can be empty
    std::string label;
	TransType transType;

	bool MarkingDependent;
	//! true if the memory policy of the transition is age memory
	bool AgeMemory;
};
typedef struct _trans spn_trans;

/**
 * DataType for place of the SPN
 */
struct _place {
	_place():isTraced(true){};
	
	//! name of the place, can be empty
	std::string label;
	
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
	std::vector<spn_trans> Transition;
	//!contains all the places of the Petri net
	std::vector <spn_place> Place;
	
	//! set the marking to the initial marking
	void
	reset();
	
	//! The path of the file use to generate the implementation
	std::string Path;
	
	/**
	 * \brief A vector use to store temporary parameters value.
	 * This vector is used to to store parameter of distribution
	 * When the simulator ask for parameters the function GetDistParameter
	 * store them inside this vector.
	 * This is done to avoid allocating a new vector too frequently.
	 */
	mutable std::vector<double> ParamDistr;

	/**
	 * \brief Check if a given transition is enabled.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	bool
	IsEnabled(size_t tr)const;
	
	/**
	 * \brief fire a given transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
     * @param time, the current time of the simulation, only used when link
     * with external code.
	 */
	void
	fire(size_t tr, double time);
	
	/**
	 * \brief unfire a given transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * This function is only used for rare event
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void unfire(size_t tr);
	
	
	void setConditionsVector();
	
	/**
	 * \brief compute the the parameters value of a given
	 * transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void GetDistParameters(size_t tr)const;
	
	//! compute the the weight value of a given transition
	double GetWeight(size_t)const;
	
	//! compute the the priority value of a given transition
	double GetPriority(size_t)const;

    //! A table of set of transitions that may be enabled after firing the last transition
    static const int* PossiblyEnabled[];

    //! A table of set of transitions that may be disabled after firing the last transition
    static const int* PossiblyDisabled[];

    //! A table of set of transition without constrain but marking dependant
    static const int* FreeMarkDepT[];

    size_t lastTransition; //! store the last fired transition

private:

    //------------------------- On the fly enabling disabling transition--------
    std::vector<int> TransitionConditions;
    std::vector<int> initTransitionConditions;
    //-------------------------/On the fly enabling disabling transition--------
	
};
#endif  /* _SPN_HPP */
