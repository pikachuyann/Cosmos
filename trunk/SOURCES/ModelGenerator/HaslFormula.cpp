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

#include <iostream>
#include "HaslFormula.hpp"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <limits>

ConfInt::ConfInt(double meanArg,double width){
	mean = meanArg;
	low = meanArg - width/2;
	up = meanArg + width/2;
}

ConfInt::ConfInt(double meanArg,double lowArg,double upArg){
	mean = meanArg;
	low = lowArg;
	up = upArg;
}

ConfInt::~ConfInt(){}

HaslFormulasTop::HaslFormulasTop(double l){
	TypeOp = PROBABILITY;
	Level =l;
	Value =0;
	Algebraic = -1;
	left = NULL;
	right = NULL;
}

HaslFormulasTop::HaslFormulasTop(double l,double v){
	TypeOp = PROBABILITY;
	Level = 1;
	Value = v;
	Algebraic = -1;
	left = NULL;
	right = NULL;
}

HaslFormulasTop::HaslFormulasTop(int al,double l){
	TypeOp = EXPECTANCY;
	Level = l;
	Value = quantile(boost::math::normal() , 0.5 + l / 2.0);
	Algebraic = al;
	left = NULL;
	right = NULL;
}

HaslFormulasTop::HaslFormulasTop(int t, HaslFormulasTop* l,HaslFormulasTop* r){
	TypeOp = t;
	Algebraic = -1;
	Level = 1;
	Value = 0;
	left = l;
	right = r;
}

HaslFormulasTop::~HaslFormulasTop(){
	if(left != NULL) delete left;
	if(right != NULL) delete right;
}

ConfInt* HaslFormulasTop::eval(BatchR &batch){
	switch (TypeOp) {
		case PROBABILITY:
		{
			double mean = batch.Isucc / batch.I;
			double l = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
			double u = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
			
			return new ConfInt(mean,l,u);
		}
			
		case EXPECTANCY:
		{
			double mean = batch.Mean[Algebraic]/batch.Isucc;
			double m2 = batch.Mean[Algebraic]/batch.Isucc;
			double variance = m2 - mean * mean;
			
			variance += 1.0/batch.Isucc;
			//Here the +1 come from the Chows and Robbin algorithm
			
			double width = 2 * Value * sqrt(variance/batch.Isucc);
			
			return new ConfInt(mean,width);
		}
			
		case CONSTANT:
			return new ConfInt(Value,0);
			
		case HASL_PLUS:
		{
			ConfInt* lci = left->eval(batch);
			ConfInt* rci = right->eval(batch);
			
			double mean = lci->mean+rci->mean;
			double low = lci->low+rci->low;
			double up = lci->up +rci->up;
			
			delete lci;
			delete rci;
			
			return new ConfInt(mean,low,up);
		}
			
		case HASL_TIME:
		{
			ConfInt* lci = left->eval(batch);
			ConfInt* rci = right->eval(batch);
			
			double mean = lci->mean*rci->mean;
			double low = lci->low*rci->low;
			double up = lci->up *rci->up;
			
			delete lci;
			delete rci;
			
			return new ConfInt(mean,low,up);
		}
			
		case HASL_DIV:
		{
			ConfInt* lci = left->eval(batch);
			ConfInt* rci = right->eval(batch);
			
			if(rci->low * rci->up<=0)
				return new ConfInt(0,- std::numeric_limits<double>::infinity(),
								   std::numeric_limits<double>::infinity());
			
			double mean = lci->mean / rci->mean;
			double low,up;
			
			if(rci->low > 0){
				low = lci->low / rci->up;
				up  = lci->up  / rci->low;
			}else{
				low = lci->low / rci->low;
				up  = lci->up  / rci->up;
			}
			
			delete lci;
			delete rci;
			
			return new ConfInt(mean,low,up);
		}
			
		default:
			std::cerr << "Fail to parse Hasl Formula"<< std::endl;
			exit(EXIT_FAILURE);
	}
}
