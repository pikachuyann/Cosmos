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
 * file expressionStruct.hpp                                                   *
 * Created by Benoit Barbot on 17/04/14.                                       *
 *******************************************************************************
 */

#ifndef __Cosmos__expressionStruct__
#define __Cosmos__expressionStruct__

#include <iostream>
#include <memory>
#include <map>
#include <set>

enum expType {
    Empty,
    UnParsed,

    Bool,
    Int,
    Real,
    PlaceName,
    Constant,

    Ceil,
    Floor,
    Exp,

    Plus,
    Minus,
    Times,
    Div,
    Min,
    Max,
    Pow,

    Neg,
    And,Or,
    Eq, Neq,
    Leq,Sl,
    Geq,SG
};

class expr{
public:
    expType t;
    bool boolVal;
    int intVal;
    double realVal;
    std::string stringVal;
    std::shared_ptr<expr> lhs;
    std::shared_ptr<expr> rhs;

    expr():t(Int),intVal(0),realVal(0.0){};
    expr(const std::string &p):t(UnParsed),intVal(0),realVal(0.0),stringVal(p){};
    expr(bool b):t(Bool),boolVal(b){};
    expr(int i):t(Int),intVal(i),realVal(0.0){};
    expr(double d):t(Real),intVal(0),realVal(d){};

    expr(expType et,const std::string &p):t(et),intVal(0),realVal(0.0),stringVal(p){};
    expr(expType et,expr &l,expr &r):t(et),intVal(0),realVal(0.0),
    lhs(std::make_shared<expr>(l)),rhs(std::make_shared<expr>(r)){};

    bool empty()const;
    bool is_concrete()const;
    bool is_markDep()const;
    void get_places(std::set<std::string>&)const;
    void eval(const std::map<std::string,int>&,const std::map<std::string,double>&);
    friend std::ostream& operator<<(std::ostream& os, const expr& e);
private:
    double get_real()const;
    expType mix(const expr &l, const expr &r)const;

};



#endif /* defined(__Cosmos__expressionStruct__) */

