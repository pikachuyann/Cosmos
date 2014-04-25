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
#include <parameters.hpp>

/**
 * Trivial confidence interval containing all R.
 */
ConfInt::ConfInt(){
	mean = 0;
	low = - std::numeric_limits<double>::infinity();
	up = std::numeric_limits<double>::infinity();
	min = - std::numeric_limits<double>::infinity();
	max = std::numeric_limits<double>::infinity();
	
}

/**
 * Symetric confidence interval
 * @param meanArg is the middle of the confidence interval
 * @param width is the width of the confidence interval
 * @param min the smallest value observed
 * @param max the maximal value observed
 */
ConfInt::ConfInt(double meanArg,double width,double minval,double maxval){
	mean = meanArg;
	low = meanArg - width/2;
	up = meanArg + width/2;
	min= minval;
	max= maxval;
}

/**
 * Asymetric confidence interval.
 * @param meanArg is the mean of the confidence interval it is not necessary
 * the middle of the confidence interval if the distribution is not symetric
 * and is not approximated by the normal distribution wich is symetric.
 * @param lowArg the Lower bound of the confidence interval.
 * @param upArg the Upper bound of the confidence interval.
 * @param min the smallest value observed
 * @param max the maximal value observed
 */
ConfInt::ConfInt(double meanArg,double lowArg,double upArg,double minval,double maxval){
	mean = meanArg;
	low = lowArg;
	up = upArg;
	min= minval;
	max= maxval;
}

ConfInt::~ConfInt(){}

/**
 * Return the width of a confidence interval
 */
double ConfInt::width(){
	return (up-low);
}

ConfInt & ConfInt::operator+=(const ConfInt& rhs){
	low += rhs.low;
	mean += rhs.mean;
	up += rhs.up;
	min += rhs.min;
	max += rhs.max;
	return *this;
}

ConfInt & ConfInt::operator-=(const ConfInt& rhs){
	low -= rhs.up;
	mean -= rhs.mean;
	up -= rhs.low;
	min -= rhs.max;
	max -= rhs.min;
	return *this;
}

ConfInt & ConfInt::operator*=(const ConfInt& rhs){
	mean = mean*rhs.mean;
	low = fmin(fmin(low*rhs.low,up*rhs.up),
			   fmin(low*rhs.up,up*rhs.low));
	up = fmax(fmax(low*rhs.low,up*rhs.up),
			  fmax(low*rhs.up,up*rhs.low));
	min = fmin(fmin(min*rhs.min,max*rhs.max),
			   fmin(min*rhs.max,max*rhs.min));
	max = fmax(fmax(min*rhs.min,max*rhs.max),
			   fmax(min*rhs.max,max*rhs.min));
	
	return *this;
}

ConfInt & ConfInt::operator/=(const ConfInt& rhs){
	mean /= rhs.mean;
	
	if(rhs.low * rhs.up<=0){
		low = - std::numeric_limits<double>::infinity();
		up = std::numeric_limits<double>::infinity();
	} else {
		if(rhs.low > 0){
			low /= rhs.up;
			up /= rhs.low;
		}else{
			low /= rhs.low;
			up  /= rhs.up;
		}
	}
	if(rhs.min * rhs.max<=0){
		min = - std::numeric_limits<double>::infinity();
		max = std::numeric_limits<double>::infinity();
	} else {
		if(rhs.min > 0){
			min /= rhs.max;
			max /= rhs.min;
		}else{
			min /= rhs.min;
			max  /= rhs.max;
		}
	}
	
	return *this;
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
ConfInt HaslFormulasTop::eval(const BatchR &batch)const{
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
		
		if(batch.Isucc ==0)return ConfInt(mean,l,u,0.0,0.0);
		if(batch.Isucc == batch.I)return ConfInt(mean,l,u,1.0,1.0);
		
		return ConfInt(mean,l,u,0.0,1.0);
		}
			
		case EXPECTANCY:
		case CDF_PART:
		case PDF_PART:
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return ConfInt();
		
		double mean = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		double variance = m2 - mean * mean;

        if(P.Width!=0){
            variance += 1.0/batch.Isucc;
            //Here the +1 come from the Chows and Robbin algorithm
        }

		double width = 2 * Value * sqrt(variance/batch.Isucc);
		
		return ConfInt(mean,width,batch.Min[Algebraic],batch.Max[Algebraic]);
		}
			
		case RE_Likelyhood:
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return ConfInt();
		double mean = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		
		//If the variance is equal to 0 numerical instability can make it a negative number.
		double variance = fmax(0,m2 - mean * mean);
		
		double width = 2 * Value * sqrt(variance/batch.Isucc);
		
		return ConfInt(mean,width,batch.Min[Algebraic],batch.Max[Algebraic]);
		}
			
		case RE_AVG://temporary
		{
		//No accepting trajectory the condidence interval is R.
		if(batch.Isucc==0)return ConfInt();
		
		double mean = (double)batch.Isucc / (double)batch.I;
		double l = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		double u = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.I,batch.Isucc, (1-Level)/2);
		double mean2 = batch.Mean[Algebraic]/batch.Isucc;
		double m2 = batch.M2[Algebraic]/batch.Isucc;
		double variance = fmax(0,m2 - mean2 * mean2);
		double width = Value * sqrt(variance/batch.Isucc);
		
		return ConfInt(mean*mean2,
						   (mean2 - width)*l,
						   (mean2 + width)*u,0.0,1.0 * batch.Max[Algebraic] );
		}
			
		case RE_Continuous:
	    {
		//batch.print();
		size_t N = batch.Mean.size()/2;
		std::cout << "tablelength = "<< batch.Mean.size() << std::endl;
		double error = 1- Level;
		double LevelN = 1- error/(N+2);
		double ValueN = quantile(boost::math::normal() , (1+LevelN)/2);
		
		ConfInt totalInt = ConfInt(0.0,0.0,0.0,0.0);
		ConfInt likelyhood = ConfInt(0.0,0.0,0.0,0.0);
		ConfInt reacheabilityprob =  ConfInt(0.0,0.0,0.0,0.0);
		ConfInt poisson = ConfInt(0.0,0.0,0.0,0.0);
		
		if(P.verbose>1)std::cerr << "i,\tsucc,\tbatch,\tMean,\tM2,\tMin,\tMax,\tPoisson" << std::endl;
		if(P.verbose>1)std::cerr << "continuous step:\t" << P.continuousStep <<  std::endl;
		for(size_t i=0; i< N; i++){
			int i2 = (i>0 && P.continuousStep>1.0 )? i-1 : i;
			
			//evaluate the likelyhood:
			likelyhood.mean = batch.Mean[2*i+1]/batch.Mean[2*i];
			double var = (batch.M2[2*i+1]/batch.Mean[2*i]) - pow((batch.Mean[2*i+1]/batch.Mean[2*i]),2);
			double widthN = 0.0;
			if(var>0)widthN = 2* ValueN * sqrt(var/batch.Mean[2*i]);
			likelyhood.low = batch.Min[2*i2+1];
			likelyhood.up = batch.Max[2*i+1];  //likelyhood->mean + widthN/2.0;
			likelyhood.min = batch.Min[2*i2+1];
			likelyhood.max = batch.Max[2*i+1];
			
			//evaluate probability to reach final state:
			reacheabilityprob.mean = batch.Mean[2*i]/batch.M2[2*i];
      		reacheabilityprob.low = boost::math::binomial_distribution<>::find_lower_bound_on_p(batch.M2[2*i2],batch.Mean[2*i2], (1-LevelN)/2);
			reacheabilityprob.up = boost::math::binomial_distribution<>::find_upper_bound_on_p(batch.M2[2*i],batch.Mean[2*i], (1-LevelN)/2);
			reacheabilityprob.min = 0.0;
			reacheabilityprob.max = 1.0;
			//evaluate poisson:
			poisson.mean = batch.Min[2*i];
			poisson.low = (1-Value2)*batch.Min[2*i];
			poisson.up = batch.Min[2*i];
			poisson.min=poisson.low;
			poisson.max=poisson.max;
			
			if(P.verbose>1){
				std::cout << "i: " << i<< "\tsucc: "<< batch.Mean[2*i]<< "\tLikelyhood: "  << likelyhood.mean << "\t[" << likelyhood.low<<";"<<likelyhood.up << "]\twidth: "<< widthN <<"\tpoisson: " << batch.Min[2*i] << "\tconfint: ["<< poisson.low <<";"<< poisson.up << "]";
				std::cerr << i << ",\t" << batch.Mean[2*i] << ",\t" << batch.M2[2*i] << ",\t" << batch.Mean[2*i+1]/batch.Mean[2*i] << ",\t" << batch.M2[2*i+1]/batch.Mean[2*i] << ",\t" << batch.Min[2*i+1] << ",\t" << batch.Max[2*i+1] << ",\t" << batch.Mean[2*i] << std::endl;
			}
			
			//Multiply the three confidence interval:
			poisson *= likelyhood;
	        poisson *= reacheabilityprob;
			
			if(P.verbose>1){
				std::cout << "\tresult: ["<< poisson.low <<";"<< poisson.up << "]" << std::endl;
			}
			
			
			//Add the confidence interval to the total one.
			//if(poisson->width() < 1.0)
			totalInt += poisson;
			
		}
		
		//Add the error made on the left of the truncation point.
		ConfInt leftTruncationError =
		ConfInt(0.0,0.0,batch.Mean[1]/batch.M2[0]* Value2/2,0,batch.Mean[1]/batch.M2[0]* Value2/2);
		
		//Add the error made on the rigth trucation point TODO!
		ConfInt rightTruncationError = ConfInt(0.0,0.0,0.0,0.0);
		
		totalInt += leftTruncationError;
		totalInt += rightTruncationError;
		
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
			return ConfInt((double)batch.Isucc/(double)batch.I, 0 ,Value2,0.0,1.0);
		}
		if (likelyhoodRatio >= (1-b) / a ) {
			return ConfInt((double)batch.Isucc/(double)batch.I, Value ,1,0.0,1.0);
		}
		return ConfInt((double)batch.Isucc/(double)batch.I, 0 ,1,0.0,1.0);
		}
			
		case CONSTANT:
			return ConfInt(Value,Value2,Value-Value2/2.0,Value+Value2/2.0);
			
		case HASL_PLUS:
			return (left->eval(batch) += right->eval(batch));
	    
		case HASL_MINUS:
			return (left->eval(batch) -= right->eval(batch));
				
		case HASL_TIME:
			return (left->eval(batch) *= right->eval(batch));
				
		case HASL_DIV:
			return (left->eval(batch) /= right->eval(batch));
	  			
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
