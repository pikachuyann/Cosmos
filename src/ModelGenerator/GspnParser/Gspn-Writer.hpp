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
	Gspn_Writer(GspnType& mgspn,const parameters& Q);
	
	GspnType MyGspn;
	const parameters P;
	
	void writeFile();
    void writeDotFile(const string &file)const;


protected:

    std::string trId= "TR_PL_ID t, const abstractBinding &b";
    std::string objName= "SPN::";

    void writeFunT(std::ostream &s,const std::string &rtype,const std::string &name,const std::string &extraArg, std::function< void(unsigned int,std::stringstream &)>,std::string) const;

	int varMultiplier(size_t var)const;
    void writeTok(ostream &SpnF,const vector<coloredToken>&,const colorDomain&)const;
    void generateStringVal(arcStore&);
	virtual void writeMarkingClasse(ofstream &, ofstream &)const;
	void writeEnabledDisabled(ofstream &)const;
	virtual void writeEnabledDisabledBinding(ofstream &)const=0;
	void writeUpdateVect(ofstream &,const string &name,const vector< set<int> > &vect)const;
	void writeTransition(ofstream &)const;
	void writeVariable(ofstream & spnF)const;
	
    void error(const std::string& m);
    void view();
	
	
	virtual void printloot(ofstream& sf, size_t domain, size_t nesting )const=0;
	
	void EnabledDisabledTr(vector< set<int> >&,
						   vector< set<int> >&,
						   vector< set<int> >&)const;

    void writeMacro(ofstream &)const;

    void writeMarkingUpdate(stringstream &f, size_t t,const place &p,const arcStore &as2,bool direct)const;
    void writeMarkingUpdateIn(stringstream &f,const arcStore &as, size_t t,const place &p , size_t t2, bool pos,const arcStore &as2,bool directionxs)const;
    void writeFire(ofstream &f)const;
    void writeIsEnabled(ofstream &f)const;
    void writeSetConditionsVector(ofstream &f)const;
    void writeGetDistParameters(ofstream &f)const;
    void writeGetPriority(ofstream &f)const;
    void writeGetWeight(ofstream &f)const;
    void writeUserDefineDistr(ofstream &f)const;

};



#endif /* defined(__Cosmos__Gspn_Writer__) */
