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

#define TR_PL_ID unsigned char
#define REAL_TYPE float

#include <math.h>
#include "macro.hpp"

#ifndef Cosmos_marking_h
#define Cosmos_marking_h


void print(const char *);
void print(TR_PL_ID i);
void print(REAL_TYPE r);



class abstractMarkingImpl;

class abstractMarking {
public:
    /**
     * Pointer to to the actual marking inmplementation
     * which is generated.
     */
    abstractMarkingImpl* P;

    abstractMarking();
    ~abstractMarking();

    void printHeader()const;
    void print()const;

    void resetToInitMarking();
    
};

typedef char abstractBinding;


inline bool contains(int i, int j){ return i>=j;}
#endif


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
	const TR_PL_ID pl;
	//! Number of transitions
	const TR_PL_ID tr;
	//! Current marking
	abstractMarking Marking;

	//! set the marking to the initial marking
	void
	reset();

	/**
	 * \brief A vector use to store temporary parameters value.
	 * This vector is used to to store parameter of distribution
	 * When the simulator ask for parameters the function GetDistParameter
	 * store them inside this vector.
	 * This is done to avoid allocating a new vector too frequently.
	 */
	mutable double ParamDistr[2];

	/**
	 * \brief Check if a given transition is enabled.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	bool
	IsEnabled(TR_PL_ID tr)const;
	
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
	fire(TR_PL_ID tr, double time);
	
	/**
	 * \brief unfire a given transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * This function is only used for rare event
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void unfire(TR_PL_ID tr);
	
	
	void setConditionsVector();
	
	/**
	 * \brief compute the the parameters value of a given
	 * transition.
	 * The implementation of this function is generated
	 * at runtime.
	 * @param tr a transition of the SPN
	 * @param b a binding of the transition of the SPN
	 */
	void GetDistParameters(TR_PL_ID tr)const;
	
	//! compute the the weight value of a given transition
	double GetWeight(TR_PL_ID)const;
	
	//! compute the the priority value of a given transition
    double GetPriority(TR_PL_ID)const;

    //! A table of set of transitions that may be enabled after firing the last transition
    static const int* PossiblyEnabled[];

    //! A table of set of transitions that may be disabled after firing the last transition
    static const int* PossiblyDisabled[];

    //! A table of set of transition without constrain but marking dependant
    static const int* FreeMarkDepT[];

    TR_PL_ID lastTransition; //! store the last fired transition
	
};
#endif  /* _SPN_HPP */
