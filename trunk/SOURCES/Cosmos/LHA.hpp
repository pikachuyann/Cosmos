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

#ifndef _LHA_HPP
#define	_LHA_HPP
#include "LHA_orig.hpp"
class LHA: public LHA_ORIG {
public:
	void Load();
	void DoEdgeUpdates(int, vector<int>&);
	void UpdateFormulaVal();
    void UpdateLinForm(vector<int>&);
    void UpdateLhaFunc( double&);
	void UpdateLhaFuncLast();
	
    double GetFlow(int, int, vector<int>&);
    bool CheckLocation(int, vector<int>&);
    bool CheckEdgeContraints(int);
							 
	t_interval GetEdgeEnablingTime(int, vector<int>&);
	//int GetEnabled_S_Edges(int, int, double, vector<int>&, vector<int>&);
};
#endif	/* _LHA_HPP */
