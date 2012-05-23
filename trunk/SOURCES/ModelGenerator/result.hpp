/*******************************************************************************
 *									                                           *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *			                                    						       *
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
 * file result.hpp created by Benoit Barbot on 22/05/12.                       *
 *******************************************************************************
 */


#include "parameters.hpp"
#include "../Cosmos/BatchR.hpp"
#include <istream>
#include <fstream>
#include <time.h>

#ifndef Cosmos_result_h
#define Cosmos_result_h

class result {
public:
    result(parameters &Q);
    ~result();
    parameters P;
    int K; //counter of generated paths
    int Ksucc; //counter of succesfull generated paths
    double Ksucc_sqrt; //square root of Ksucc
    
    double CurrentWidth;
    double RelErr;
    
    double Mean;
    double Var; //variance
    double stdev; //standard deviation
    double M2;
    double Normal_quantile;
    
    double low, up;
    bool IsBernoulli;
    double Dif;
    
    time_t start, end;
    double cpu_time_used;
    
    void addBatch(BatchR*);
    bool continueSim();
    void printProgress();
    void stopclock();
    void printResult();
    void printResultFile(string);
    void printAlligator();
};


#endif
