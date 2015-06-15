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
 * file timeGen.cpp created by Benoit Barbot on 25/01/12.            *
 *******************************************************************************
 */

#include "timeGen.hpp"

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/lognormal.hpp>
#include <boost/math/distributions/binomial.hpp>
#include <boost/math/tools/roots.hpp>
#include <float.h>

using namespace std;

void timeGen::initRandomGenerator(unsigned int seed){
	RandomNumber.seed(seed);
}


/**
 * Call the random generator to generate fire time.
 * @param distribution is the type of distribution
 * @param param is a vector of parameters of the distribution.
 */
double timeGen::GenerateTime(DistributionType distribution,const vector<double> &param) {
	
	switch (distribution) {
		case UNIFORM:
		{//UNIF
            if(param[0] == param[1]) return param[0];
			boost::uniform_real<> UNIF(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			return gen();
		}
			
		case MASSACTION:
		case EXPONENTIAL:
		{//EXP
			//Exponential distribution is the only marking dependent parameters. Check of validity is required
			
			//-------------- Rare Event -----------------
			//cout << "rate:" << param[0] << endl;
			if(param[0] <= 0) { return 1e200; };
			//------------- /Rare Event -----------------
			
			if (param[0] <= 0) {
				cout << "Exponential ditribution should be with rate > 0 not "
                << param[0] << "\n End of Simulation" << endl;
				exit(1);
			}
			
			boost::exponential_distribution<> EXP(param[0]);
			boost::variate_generator<boost::mt19937&, boost::exponential_distribution<> > gen(RandomNumber, EXP);
			return gen();
			
		}
			
		case DETERMINISTIC:
		{//DETERMINISTIC
			return param[0];
		}
		
        case NORMAL:
        {
            boost::normal_distribution<> NORMAL(param[0], param[1]);
            boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > gen(RandomNumber, NORMAL);
            return fmax(0.0,gen());
        }
            
		case LOGNORMAL:
		{//LogNormal
			boost::lognormal_distribution<> LOGNORMAL(param[0], param[1]);
			boost::variate_generator<boost::mt19937&, boost::lognormal_distribution<> > gen(RandomNumber, LOGNORMAL);
			return gen();
		}
			
		case TRIANGLE:
		{//Triangle
			boost::triangle_distribution<> TRIANGLE(param[0], param[1], param[2]);
			boost::variate_generator<boost::mt19937&, boost::triangle_distribution<> > gen(RandomNumber, TRIANGLE);
			return gen();
		}
		case GEOMETRIC:
		{//GEOMETRIC
			boost::uniform_real<> UNIF(0, 1);
			boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
			double p = gen();
			return (param[1] * (ceil(log(p) / log(1 - param[0]))));
			/*if (p >= param[0]){
			 return param[1];
			 } else {
			 return param[1] * ceil(log(p / param[0]) / log(1 - param[0]) + 1);
			 }*/
		}
		case ERLANG:
        {//ERLANG
            boost::uniform_real<> UNIF(0, 1);
            boost::variate_generator<boost::mt19937&, boost::uniform_real<> > gen(RandomNumber, UNIF);
            double sum = 0.0;
            for (int i = 0; i < param[0]; i++)
                sum -= log(gen());
            return sum / param[1];
			
        }
        case GAMMA:
        {//GAMMA
            boost::gamma_distribution<> GAMMA(param[0]);
            boost::variate_generator<boost::mt19937&, boost::gamma_distribution<> > gen(RandomNumber, GAMMA);
            return param[1] * gen();
        }
		case DISCRETEUNIF:
		{//DISCRETEUNIF
			boost::uniform_int<> UNIF((int)param[0], (int)param[1]);
			boost::variate_generator<boost::mt19937&, boost::uniform_int<> > gen(RandomNumber, UNIF);
			return gen();
			break;
		}
        case USERDEFINE:
        {
        // Use boost to implement inverse method for sampling arbitrary distribution

            boost::uniform_01<> UNIF;
            boost::variate_generator<boost::mt19937&, boost::uniform_01<> > gen(RandomNumber, UNIF);
            auto gentime = gen();
        //cerr << "sample" << gentime <<":";
            double initialpt = userDefineLowerBound(param);
            return boost::math::tools::newton_raphson_iterate([&](double x){
                //cerr << x << " , ";
                return make_tuple(userDefineCDF(param,x)-gentime, userDefinePDF(param,x));
            }, initialpt, initialpt, numeric_limits<double>::infinity(), 10);

            break;
        }

        case DISCRETEUSERDEFINE:
        {
            boost::uniform_int<> UNIF(0, (int)param[1]);
            boost::variate_generator<boost::mt19937&, boost::uniform_int<> > gen(RandomNumber, UNIF);
            unsigned int i=gen();
            return userdefineDiscreteDistr(param,i);
        }
			
		default: cerr << "Unknown distribution: "<< distribution << endl;
			break;
	}
	return DBL_MIN;
	
}
