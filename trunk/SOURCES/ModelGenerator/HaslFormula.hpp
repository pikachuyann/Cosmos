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
 * file parameters.hpp                                                         *
 * Created by Benoit Barbot on 12/12/12.                                       *
 *******************************************************************************
 */

#

#ifndef __Cosmos__HaslFormula__
#define __Cosmos__HaslFormula__

#include "../Cosmos/BatchR.hpp"

#define EXPECTANCY 0
#define PROBABILITY 1
#define CONSTANT 2
#define HASL_PLUS 3
#define HASL_TIME 4
#define HASL_DIV 5


class ConfInt {
public:
	ConfInt();
	ConfInt(double,double);
	ConfInt(double,double,double);
	~ConfInt();
	
	double mean;
	double low;
	double up;
	double width(void);
};

class HaslFormulasTop {
public:
	HaslFormulasTop(double);
	HaslFormulasTop(double,double);
	HaslFormulasTop(int,double);
	HaslFormulasTop(int, HaslFormulasTop*, HaslFormulasTop*);
	
	~HaslFormulasTop();
	
	ConfInt* eval(BatchR&);
	
protected:
	int TypeOp;
	double Level;
	double Value;
	int Algebraic;
	HaslFormulasTop* left;
	HaslFormulasTop* right;
};





#endif /* defined(__Cosmos__HaslFormula__) */
