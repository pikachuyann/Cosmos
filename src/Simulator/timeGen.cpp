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

string timeGen::string_of_dist(DistributionType d,const array<double,PARAM_TBL_SIZE> &param, const CustomDistr &cd)const{
    //use for debuging
    switch (d) {
        case   NORMAL:
            return "Normal("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   GAMMA:
            return "Gamma("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   UNIFORM:
            return "Uniform("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   EXPONENTIAL:
            return "Exponential("+ to_string(param[0])+")";
        case   DETERMINISTIC:
            return "Deterministic("+ to_string(param[0])+")";
        case   LOGNORMAL:
            return "LogNormal";
        case   TRIANGLE:
            return "Triangle";
        case   GEOMETRIC:
            return "Geometric";
        case   ERLANG:
            return "Erlang("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   DISCRETEUNIF:
            return "DiscreteUnif("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   MASSACTION:
            return "MassAction("+ to_string(param[0])+")";
        case   IMMEDIATE:
            return "Immediate";
        
        //    return "Userdefine("+ to_string(param[0]) +","+ to_string(param[1])+","+ to_string(param[2])+","+ to_string(param[3])+")";
        case   DISCRETEUSERDEFINE:
            return "DiscreteUserDefine("+ to_string(param[0]) +","+ to_string(param[1])+")";
        case   USERDEFINE:
        case   USERDEFINEPOLYNOMIAL:
            string s = "UserdefinePolynomial("+ to_string(param[0]) +","+ to_string(param[1])+","+ to_string(param[2])+","+ to_string(param[3])+")";
            return s + cd.print_poly( (int)param[0]);


            
    }
}

/**
 * Call the random generator to generate fire time.
 * @param distribution is the type of distribution
 * @param param is a vector of parameters of the distribution.
 */
double timeGen::GenerateTime(DistributionType distribution,const array<double,PARAM_TBL_SIZE> &param, const CustomDistr &cd) {
    //cerr << "sampling " << string_of_dist(distribution,param) << endl;;
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
		
        case IMMEDIATE:
            return 0;
            
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
            const auto gentime = gen();
            const auto lower = cd.userDefineLowerBound(param);
            const auto upper = cd.userDefineUpperBound(param);

        //cerr << "sample(" << gentime << ",[" << lower << "," << upper << "]):" <<endl;
            double initialpt = (lower+upper)/ 2.0;
            return boost::math::tools::newton_raphson_iterate([&](double x){
                const auto cdf = cd.userDefineCDF(param,x);
                const auto pdf = cd.userDefinePDF(param,x);
                //      cerr << "it:" << x << endl;
                return make_tuple(cdf-gentime, pdf);
            }, initialpt, lower, upper, 100);
            break;
        }

        case DISCRETEUSERDEFINE:
        {
            boost::uniform_int<> UNIF(0, 100000);
            boost::variate_generator<boost::mt19937&, boost::uniform_int<> > gen(RandomNumber, UNIF);
            unsigned int i=gen();
            return cd.userDefineDiscreteDistr(param,i);
        }
            
        case USERDEFINEPOLYNOMIAL:
        {
            boost::uniform_01<> UNIF;
            boost::variate_generator<boost::mt19937&, boost::uniform_01<> > gen(RandomNumber, UNIF);
            const auto gentime = gen();
            const auto lower = cd.userDefineLowerBound(param);
            const auto upper = cd.userDefineUpperBound(param);
            
            //cerr << "sample(" << gentime << ",[" << lower << "," << upper << "]):" <<endl;
            double initialpt = (lower+upper)/ 2.0;
            return boost::math::tools::newton_raphson_iterate([&](double x){
                const auto cdf = cd.userDefineCDF(param,x);
                const auto pdf = cd.userDefinePDF(param,x);
                //      cerr << "it:" << x << endl;
                return make_tuple(cdf-gentime, pdf);
            }, initialpt, lower, upper, 100);
            break;

        }
            
        case PLAYER1:
        {
            return 0;
        }
        
			
    }
	return DBL_MIN;
}


/**
 * Generate an event based on the type of his distribution
 * @param E the event to update
 * @param Id the number of the transition to of the SPN
 * @param b is the binding of the variable of the SPN for the transition.
 */
template<class DEDS>
void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &TG,DEDS& N) {
    double t=ctime;
    if (N.Transition[Id].DistTypeIndex != IMMEDIATE) {
        N.GetDistParameters(Id,b);
        t += fmax(TG.GenerateTime(N.Transition[Id].DistTypeIndex, N.ParamDistr, N.customDistr),0.0);
        if(verbose > 4){
            cerr << "Sample " << N.Transition[Id].label << ": ";
            cerr << TG.string_of_dist(N.Transition[Id].DistTypeIndex, N.ParamDistr, N.customDistr);
            cerr << endl;
        }
    }
    
    //The weight of a transition is always distributed exponentially
    //It is used to solved conflict of two transitions with same time
    //and same priority.
    double w=0.0;
    switch (N.Transition[Id].DistTypeIndex){
        case DETERMINISTIC:
        case DISCRETEUNIF:
        case IMMEDIATE:
        case DISCRETEUSERDEFINE:
            N.ParamDistr[0]= N.GetWeight(Id,b);
            w = TG.GenerateTime(EXPONENTIAL, N.ParamDistr, N.customDistr);
            if(verbose>4){
                cerr << "weight : ";
                cerr << TG.string_of_dist(EXPONENTIAL, N.ParamDistr, N.customDistr);
                cerr << endl;
            }
            break;
        case NORMAL:
        case GAMMA:
        case GEOMETRIC:
        case UNIFORM:
        case ERLANG:
        case EXPONENTIAL:
        case LOGNORMAL:
        case TRIANGLE:
        case USERDEFINE:
        case USERDEFINEPOLYNOMIAL:
        case MASSACTION:
        case PLAYER1:
            ;
    }
    
    E.transition = Id;
    E.time = t;
    E.priority = N.GetPriority(Id,b);
    E.weight = w;
    E.binding = b;
}

#include "SPNBase.hpp"
#include "EventsQueue.hpp"
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPN_orig<EventsQueue<vector<_trans>>> &);
#include "EventsQueueSet.hpp"
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,SPN_orig<EventsQueueSet> &);

/*#include "MarkovChain.hpp"
template void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,MarkovChain<EventsQueue<vector<Edge>>> &);
*/
