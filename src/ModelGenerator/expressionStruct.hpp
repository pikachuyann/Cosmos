//
//  expressionStruct.h
//  Cosmos
//
//  Created by Benoit Barbot on 17/04/2014.
//
//

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
    expr(expType et,expr &l,expr &r):t(et),intVal(0),realVal(0.0),lhs(&l),rhs(&r){};

    bool empty()const;
    bool is_concrete()const;
    void get_places(std::set<std::string>&)const;
    void eval(const std::map<std::string,int>&,const std::map<std::string,double>&);
    friend std::ostream& operator<<(std::ostream& os, const expr& e);
private:
    double get_real()const;
    expType mix(const expr &l, const expr &r)const;

};



#endif /* defined(__Cosmos__expressionStruct__) */

