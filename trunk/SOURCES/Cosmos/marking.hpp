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
 * file marking.cpp created by Benoit Barbot on 28/01/13.                      *
 *******************************************************************************
 */

#ifndef Cosmos_marking_h
#define Cosmos_marking_h

#include <vector>

class abstractMarkingImpl;

class abstractMarking {
public:
	abstractMarkingImpl* P;
	
	abstractMarking();
	abstractMarking(const std::vector<int>& m);
	abstractMarking(const abstractMarking& m);
	abstractMarking& operator = (const abstractMarking& m);
	~abstractMarking();
	
	void print()const;
	void resetToInitMarking();
	int getNbOfTokens(int)const;
	std::vector<int> getVector()const;
	void setVector(const std::vector<int>&);

};

struct markingEqState{
	bool operator()(const abstractMarking &t1,const abstractMarking &t2) const;
};

struct markingHashState{
	int operator()(const abstractMarking &t1) const;
};

class abstractBindingImpl;

class abstractBinding {
public:
	abstractBindingImpl* P;
	abstractBinding();
	~abstractBinding();
	abstractBinding(const abstractBinding& b);
	abstractBinding& operator = (const abstractBinding& m);
	bool next();
	void print()const;
	int transition()const;
	int id()const;
private:
	int idcount;
};

#endif
