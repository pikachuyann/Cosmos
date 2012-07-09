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


/*
 * This file implement a structure for the result of a batch of 
 * Simulation it also implement input/output on it.
 * It is used both by the simulator and the main program.
 */

#include <vector>
#include <iostream>
#include <fstream>

#ifndef _BATCHR_HPP
#define	_BATCHR_HPP

typedef std::pair<bool, std::vector<double> > SimOutput;

class BatchR {
public:
//    BatchR();
    BatchR(int i);
    virtual ~BatchR();
    int I;
    int Isucc;
    int TableLength;
    std::vector<bool> IsBernoulli;
    std::vector<double> Mean;
    std::vector<double> M2;
    
    void addSim(SimOutput*);
    void unionR(BatchR*);
    void outputR();
    void inputR(FILE* f);
    void print();
    
};


#endif /* _BATCHR_HPP */
