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
 * file Gspn-Writer.hpp created by Benoit Barbot on 14/01/14.                  *
 *******************************************************************************
 */

#ifndef __Cosmos__Gspn_Writer__
#define __Cosmos__Gspn_Writer__

#include <iostream>
#include "Gspn-Reader.hpp"


class Gspn_Writer {
public:
	Gspn_Writer(GspnType& mgspn,parameters& Q);
	
	GspnType MyGspn;
	parameters P;
	
	void WriteFile();
	
private:
	
	int varMultiplier(size_t var);
    void writeTok(ostream &SpnF, vector<coloredToken>&,const colorDomain&);
    void generateStringVal(arcStore&);
	void writeMarkingClasse(ofstream &, ofstream &, parameters &);
	void writeEnabledDisabled(ofstream &);
	void writeEnabledDisabledBinding(ofstream &);
	void writeUpdateVect(ofstream &,const string &name,const vector< set<int> > &vect);
	void writeTransition(ofstream &, bool);
	void writeVariable(ofstream & spnF);
	
    void error(const std::string& m);
    
    void view();
	
	
	void printloot(ofstream& sf, size_t domain, size_t nesting );
	
	void EnabledDisabledTr(vector< set<int> >&,
						   vector< set<int> >&,
						   vector< set<int> >&);

	
	
};


#endif /* defined(__Cosmos__Gspn_Writer__) */
