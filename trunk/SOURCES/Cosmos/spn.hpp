/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
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
 *******************************************************************************
 */

#ifndef _SPN_HPP
#define	_SPN_HPP
#include "spn_orig.hpp"
class SPN: public SPN_ORIG {
public:
	
	/*SPN();
	int pl;
	*/
	 
	void Load();
	bool IsEnabled(int); // Check if a given transition is enabled
	
	void fire(int); // fire a given transition
    void unfire(int); // unfire a given transition
	
	void GetDistParameters(int); // compute the the parameters value of a given distribution 
	//------------------------- Rare Event ---------------------------------------
	//vector<double> GetDistParametersOrigin(int);
    void lumpingFun(vector<int>*); 
	//-------------------------/Rare Event ---------------------------------------
	
	
    double GetWeight(int); // compute the the weight value of a given transition
    double GetPriority(int); // compute the the priority value of a given transition	
};
#endif	/* _SPN_HPP */
