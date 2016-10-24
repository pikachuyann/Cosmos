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
 * file timeGen.hpp created by Benoit Barbot on 25/01/12.            *
 *******************************************************************************
 */

#ifndef __Cosmos__File__
#define __Cosmos__File__

#include <iostream>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

#include "spn.hpp"
#include "Event.hpp"

class timeGen {
public:
	
	//! generate a time acording to the distribution d with parameters p
	double GenerateTime(DistributionType distribution,const std::vector<double> &param, const CustomDistr&);
	
	/**
	 * \brief Initialize the random number generator with the given seed
	 * @param seed is an unsigned integer to be used as seed.
	 */
	void initRandomGenerator(unsigned int seed);

    std::string string_of_dist(DistributionType d,const std::vector<double> &param, const CustomDistr&)const;

private:
	
	//!The random Generator Mersenne Twister from the boost library
	boost::mt19937 RandomNumber;

};

template<class DEDS>
void generateEvent(double ctime,Event& E,size_t Id,const abstractBinding& b,timeGen &,DEDS &);

#endif /* defined(__Cosmos__File__) */

