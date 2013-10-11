/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
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
 * file BatchR.hpp created by Benoit Barbot.                                   *
 *******************************************************************************
 */


#include <vector>
#include <iostream>
#include <fstream>

#ifndef _BATCHR_HPP
#define	_BATCHR_HPP

typedef std::pair<bool, std::vector<double> > SimOutput;

/**
 * This file implement a structure for the result of a batch of
 * Simulation it also implement input/output on it.
 * It is used both by the simulator and the main program.
 */
class BatchR {
public:
    BatchR(const size_t i);
	
	//! Number of simulation.
    unsigned long int I;
	
	//! Number of succesfull simulation.
    unsigned long int Isucc;
	
	//! Number of mesured variable.
    size_t TableLength;
	
	//! Is a variable a boolean.
    std::vector<bool> IsBernoulli;
	
	//! The mean value of each formula.
    std::vector<double> Mean;
	
	//! The second moment of each formula.
    std::vector<double> M2;
	
	//! The third moment of each formula.
    std::vector<double> M3;
	
	//! The fourth moment of each formula.
    std::vector<double> M4;
    
    //! Add the result of one simulation to the Batch.
    void addSim(const SimOutput*);
    
    //! Merge the result of two batch of simulation.
    void unionR(const BatchR*);
	
    void outputR();
	
    bool inputR(FILE* f);
    void print()const; //! Print human readable version of batch on stdout.
    
};


#endif /* _BATCHR_HPP */
