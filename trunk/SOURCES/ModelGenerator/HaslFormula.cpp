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

/**
 * Trivial confidence interval containing all R.
 */
ConfInt::ConfInt(){
	mean = 0;
	low = - std::numeric_limits<double>::infinity();
	up = std::numeric_limits<double>::infinity();
}

/**
 * Symetric confidence interval
 * @param meanArg is the middle of the confidence interval
 * @param width is the width of the confidence interval
 */
ConfInt::ConfInt(double meanArg,double width){
	mean = meanArg;
	low = meanArg - width/2;
	up = meanArg + width/2;
}

/**
 * Asymetric confidence interval.
 * @param meanArg is the mean of the confidence interval it is not necessary
 * the middle of the confidence interval if the distribution is not symetric
 * and is not approximated by the normal distribution wich is symetric.
 * @param lowArg the Lower bound of the confidence interval.
 * @param upArg the Upper bound of the confidence interval.
 */
ConfInt::ConfInt(double meanArg,double lowArg,double upArg){
	mean = meanArg;
	low = lowArg;
	up = upArg;
}

ConfInt::~ConfInt(){}

/**
 * Return the width of a confidence interval
 */
double ConfInt::width(){
	return (up-low);
}

/**
 * Build an HASL formula with the PROB operator.
 * Compute exact confidence interval.
 */
HaslFormulasTop::HaslFormulasTop(){
	TypeOp = PROBABILITY;
	Level =0;
	Value =0;
	Value2=0;
	Algebraic = 0;
	left = NULL;
	right = NULL;
}

/**
 * Build a CONSTANT Hasl formula.
 * @param v the value of the constant
 */
HaslFormulasTop::HaslFormulasTop(double v1,double v2,double l){
	TypeOp = CONSTANT;
	Level = l;
	Value = v1;
	Value2= v2;
	Algebraic = 0;
	left = NULL;
	right = NULL;
}

/**
 * Build an HASL formula computing the expected value of a subformula.
 * Use the approximation to the normal low to compute the confidence interval
 * @param al the index of the sub formula return by the simulator.
 * @param l the confidence level of the confidence interval.
 */
HaslFormulasTop::HaslFormulasTop(size_t al){
	TypeOp = EXPECTANCY;
	Level = 0;
	Value = 0;
	Value2 = 0;
	Algebraic = al;
	left = NULL;
	right = NULL;
}

/**
 * Build an HASL formula testing if the probability of accepting a run is above some threshold.
 * In this setting the confidence level is the probability of type
 * I and type II errors.
 * @param p is the threshold.
 * @param delta is the half width of the indiference region.
 */
HaslFormulasTop::HaslFormulasTop(double p, double delta){
	TypeOp = HYPOTHESIS	;
	Level = 0;
	Value = p -delta;
	Value2= p + delta;
	Algebraic = 0;
	left = NULL;
	right = NULL;
}


/*
 * Build an Hasl formula of a given type as a tree with two descendant.
 * @param t is the type of the node either HASL_PLUS, HASL_TIME or HASL_DIV.
 * @param l The left Hasl Formula.
 * @param r the right Hasl formula.
 */
HaslFormulasTop::HaslFormulasTop(HaslType t, HaslFormulasTop* l,HaslFormulasTop* r){
	TypeOp = t;
	Algebraic = 0;
	Level = 0;
	Value = 0;
	Value2= 0;
	left = l;
	right = r;
}

/**
 * Destructor call destructor recusively on descendant if neaded.
 */
HaslFormulasTop::~HaslFormulasTop(){
	if(!left) delete left;
	if(!right) delete right;
}

/**
 * This method return true if a haslformula is constant.
 * This is usfull to know if a subformula have a confidence level
 * different than 1.
 */
bool HaslFormulasTop::isConstant(){
	switch (TypeOp) {
		case CONSTANT:
			return true;
			
		case HASL_PLUS:
		case HASL_TIME:
		case HASL_DIV:
			return (left->isConstant() && right->isConstant());
		default:
			return false;
	}
}

/**
 * This function set the confidence level of an HASL formula.
 * When the fomula contain
 * @param l The confidence level
 */
void HaslFormulasTop::setLevel(double l){
	switch (TypeOp) {
		case PROBABILITY:
			Level = l;
			break;
			
		case EXPECTANCY:
		case CDF_PART:
		case PDF_PART:
		case RE_Likelyhood:
			Level = l;
			Value = quantile(boost::math::normal() , 0.5 + l / 2.0);
			break;
			
		case RE_AVG://temporary
			Level = l;
			//Here we divide the error by two because half the error come from the bernoulli evaluation.
			Value = quantile(boost::math::normal() , 0.75 + l / 4.0);
			break;

		case RE_Continuous:
		  Level = l;
		  Value = quantile(boost::math::normal() , 0.75 + l / 4.0);
		  break;
	
		case HYPOTHESIS:
			Level = l;
			break;
			
		case CONSTANT:
			break;
			
		case HASL_PLUS:
		case HASL_MINUS:
		case HASL_TIME:
		case HASL_DIV:
			Level=l;
			if (left->isConstant()){right->setLevel(l);}
			else if (right->isConstant()){left->setLevel(l);}
			else{
				//We need to increase the condidence level on each subformula
				left->setLevel((1+l)/2);
				right->setLevel((1+l)/2);
			}
			break;
			
		default:
			std::cerr << "Fail to parse Hasl Formula"<< std::endl;
			exit(EXIT_FAILURE);
	}
}

/**
 * The function eval compute confidence interval for the HASL formula
 * from the simualation result return by the simulators.
 *
 * Some remarks about the estimation of the confidence interval adopted here
 * Let \f$ l \f$ =ConfLevel, the confidence level
 * \f$ l=1-alpha \f$
 * Let \f$ w \f$ = ConfWidth, the size of the confidence interval
 *
 * Let \f$ \mu \f$ the value to estimate, and \f$ x \f$ the
 * estimation of \f$ \mu \f$
 * then \f$ \mathbb{P}( \mu \in [x-\frac{w}{2} , x+\frac{w}{2}]) = 1-alpha  \f$
 *
 * The confidence interval is given by :
 * \f$  [x-z(1-\frac{alpha}{2}) * \frac{StandardDeviation~ }
 * { \sqrt{NumberOfObservations}} ,
 *         x+z(1-\frac{alpha}{2}) * \frac{StandardDeviation~}
 * { \sqrt{NumberOfObservations}}] \f$
 * with : \f$ z(1-\frac{alpha}{2})=z(1-\frac{1-l}{2}) = z(0.5+\frac{l}{2}) \f$
 *
 * \f$ StandartDeviation~ = \sqrt{ Variance +\frac{1}{n} } \f$
 * This correction come from the Chows and Robbin algorithm to ensure
 * The correctness of the stopping condition.
 *
 */
ConfInt* HaslFormulasTop::eval(BatchR &batch)const{
	switch (TypeOp) {
		case PROBABILITY:
		{
		/*
		 * Here we used the boost librairy for computing the binomial
		 * confidence interval.
		 * According to boost documentation the algorithme used is
		 * the one from Clopper-person:
		 * Clopper, C. J. and Pearson, E. S. (1934). The use of confidence or fiducial limits illustrated in the case of the binomial. Biometrika 26 404-413.
		 */
		double mean = (double)batch.Isucc / (double)batch.I;
		double l = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		double u = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		
		return new ConfInt(mean,l,u);
		}
			
		case EXPECTANCY:
		case CDF_PART:
		case PDF_PART:
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return new ConfInt();
		
		double mean = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		double variance = m2 - mean * mean;
		
		variance += 1.0/batch.Isucc;
		//Here the +1 come from the Chows and Robbin algorithm
		
		double width = 2 * Value * sqrt(variance/batch.Isucc);
		
		return new ConfInt(mean,width);
		}
			
		case RE_Likelyhood:
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return new ConfInt();
		double mean = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		
		//If the variance is equal to 0 numerical instability can make it a negative number.
		double variance = fmax(0,m2 - mean * mean);
		
		double width = 2 * Value * sqrt(variance/batch.Isucc);
		
		return new ConfInt(mean,width);
		}
			
		case RE_AVG://temporary
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return new ConfInt();
		
		double mean = (double)batch.Isucc / (double)batch.I;
		double l = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		double u = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		double mean2 = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		double variance = fmax(0,m2 - mean2 * mean2);
		double width = Value * sqrt(variance/batch.Isucc);
		
		return new ConfInt(mean*mean2,
						   (mean2 - width)*l,
						   (mean2 + width)*u );
		}
			
	  case RE_Continuous:
	    {
	      //batch.print();
	      size_t N = batch.TableLength/3;
	      std::cout << "tablelength = "<< batch.TableLength << std::endl;
	      double LevelN = 1- ((1-Level)/N);
	      double ValueN = quantile(boost::math::normal() , (3+LevelN)/4);
	      
	      ConfInt* totalInt = new ConfInt(0.0,0.0);
	      
	      for(int i=0; i< N; i++){
		
		double var = (batch.M2[3*i+2]/batch.Mean[3*i+1]) - pow((batch.Mean[3*i+2]/batch.Mean[3*i+1]),2);
		double widthN = 0.0;
		if(var>0)widthN = 2* ValueN * sqrt(var/batch.Mean[3*i+1]);
		
		double lowberN = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.M2[3*i+1],batch.Mean[3*i+1], (1-Level)/4);
		double upberN = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.M2[3*i+1],batch.Mean[3*i+1], (1-Level)/4);
		
		double lowN = lowberN * (batch.Mean[3*i+2] - widthN/2.0);
		double upN = upberN * (batch.Mean[3*i+2] + widthN/2.0);
		
		if(true)std::cerr << "i:" << i<< "\tMean Likelyhood: "  << batch.Mean[3*i+2] << "\twidth: " << widthN << "\tcoeff: " << batch.Mean[3*i] << "\tconfint: ["<< lowN <<";"<<upN << "]";
		
		lowN *= batch.Mean[3*i]; // *(1.0-epsilon); To Fix
		upN  *= batch.Mean[3*i];
		if(true)std::cerr << "\tFinal confint: ["<< lowN <<";"<<upN << "]" << std::endl;
		
		totalInt->low += lowN;
	        totalInt->up += upN;
		
	      }
	      
	      //Add the error made on the left of the truncation point.
	      //uptotal += (epsilon/2.0)*(MeanN[0]/ IsuccN[0]);
	      
	    
	      
	      
	      //Hack to retrive confidence interval computed by the simulator
	      return totalInt;
	    }		
	    
	  case HYPOTHESIS:
		{
		//Implementation of the SPRT.
		
		double uppart = pow((Value2/Value),(double)batch.Isucc);
		double lowpart = pow(((1-Value2)/(1-Value)), (double)batch.I - (double)batch.Isucc);
		double likelyhoodRatio = uppart * lowpart;
		double a = 1-Level; //Probability of type I error
		double b = 1-Level; //Probability of type II errror
		if(likelyhoodRatio <= b /(1-a)){
			return new ConfInt((double)batch.Isucc/(double)batch.I, 0 ,Value2);
		}
		if (likelyhoodRatio >= (1-b) / a ) {
			return new ConfInt((double)batch.Isucc/(double)batch.I, Value ,1);
		}
		return new ConfInt((double)batch.Isucc/(double)batch.I, 0 ,1);
		}
			
		case CONSTANT:
			return new ConfInt(Value,Value2);
			
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
		case HASL_MINUS:
		{
		ConfInt* lci = left->eval(batch);
		ConfInt* rci = right->eval(batch);
		
		double mean = lci->mean-rci->mean;
		double low = lci->low-rci->low;
		double up = lci->up -rci->up;
		
		delete lci;
		delete rci;
		
		return new ConfInt(mean,low,up);
		}
			
		case HASL_TIME:
		{
		ConfInt* lci = left->eval(batch);
		ConfInt* rci = right->eval(batch);
		
		double mean = lci->mean*rci->mean;
		double low = fmin(fmin(lci->low*rci->low,lci->up*rci->up),
						  fmin(lci->low*rci->up,lci->up*rci->low));
		double up = fmax(fmax(lci->low*rci->low,lci->up*rci->up),
						 fmax(lci->low*rci->up,lci->up*rci->low));
		
		delete lci;
		delete rci;
		
		return new ConfInt(mean,low,up);
		}
			
		case HASL_DIV:
		{
		ConfInt* lci = left->eval(batch);
		ConfInt* rci = right->eval(batch);
		
		if(rci->low * rci->up<=0)
			return new ConfInt();
		
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

double HaslFormulasTop::bound()const{
	switch (TypeOp) {
		case PROBABILITY:
			return 0.5;
			
		case EXPECTANCY:
		case CDF_PART:
		case PDF_PART:
		case RE_AVG:
		case RE_Continuous:
			return std::numeric_limits<double>::infinity();
			
		case CONSTANT:
			return fabs(Value);
			
		case HASL_PLUS:
		{
		double v1 = left->bound();
		double v2 = right->bound();
		return (fmax(v1,v2));
		}
			
		case HASL_TIME:
		{
		double v1 = left->bound();
		double v2 = right->bound();
		return (v1*v2);
		}
			
		case HASL_DIV:
		{
		return (std::numeric_limits<double>::infinity());
		}
			
		default:
			std::cerr << "Fail to parse Hasl Formula"<< std::endl;
			exit(EXIT_FAILURE);
	}
}
