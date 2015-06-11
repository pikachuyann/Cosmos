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
 * file Gspn-model.hpp                                                         *
 * Created by Benoit Barbot on 09/06/15.                                       *
 *******************************************************************************
 */

#ifndef __Cosmos__Gspn_model__
#define __Cosmos__Gspn_model__

#include <stdio.h>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>
#include <vector>

#include "../expressionStruct.hpp"

//! A type to discriminate timed and untimmed transition.
enum TransType {
    Timed, unTimed
};

//! a structure for probability distribution
struct ProbabiliteDistribution {
    std::string name;
    std::vector<expr> Param;
    ProbabiliteDistribution(){};
    ProbabiliteDistribution(const expr &s):name("EXPONENTIAL"),Param(1,s){};
};
typedef struct ProbabiliteDistribution Distribution;

std::ostream& operator<<(std::ostream& os, const ProbabiliteDistribution& obj);

struct userDefineDistribution{
    std::string name;
    std::string var;
    std::string cdf;
    std::string pdf;
    std::string lowerBound;
    size_t nbparam;
};

std::ostream& operator<<(std::ostream& os, const userDefineDistribution& obj);


struct color {
    std::string name;
    size_t id;
    size_t cc;
    color(){};
    color(const std::string s,size_t i,size_t c){ name =s;id = i; cc=c;}
};
struct colorClass {
    std::string name;
    bool isCircular;
    std::vector<color> colors;
    inline std::string cname()const {
        return name+ "_Color_Classe";
    }
};


#define UNCOLORED_DOMAIN (0)

struct colorDomain {
    std::string name;
    std::vector<size_t> colorClassIndex;
    inline bool isUncolored()const {
        return name.size() ==0;
    }
    inline std::string cname()const {
        if(isUncolored())return "int";
        return name+ "_Domain";
    }
    inline std::string tokname()const {
        if(isUncolored())return " ";
        return name+ "_Token";
    }
};

struct colorVariable {
    std::string name;
    size_t type;
};

enum varType {
    CT_SINGLE_COLOR,
    CT_VARIABLE,
    CT_ALL,
    CV_CLOCK,
    CV_REAL,
    CV_INT
};

struct hybridVariable {
    std::string name;
    varType type;
    bool isTraced;
    std::string initialValue;
    hybridVariable():type(CV_CLOCK),isTraced(true) {}
};

struct coloredToken {
    std::string mult;
    std::vector<size_t> field;
    std::vector<varType> Flags;
    std::vector<int> varIncrement;
    bool hasAll;
    coloredToken():hasAll(false){};
    coloredToken(std::string st):mult(st),hasAll(false){};
    coloredToken(int i):mult(std::to_string(i)),hasAll(false){};
};

struct transition {
    size_t id;
    std::string label;
    bool isTraced;
    TransType type;
    Distribution dist;
    expr priority;
    expr weight;
    bool singleService;
    bool markingDependant;
    int nbServers;
    bool ageMemory;
    std::set<size_t> varDomain;
    expr guard;
    std::string update;
    transition(){ isTraced = true; }
    transition(size_t i,const std::string &n,const expr &p,bool md):id(i),label(n),isTraced(true),
    type(Timed),dist(p),priority(expr(1)),weight(expr(1.0)),singleService(true),
    markingDependant(md),nbServers(1),ageMemory(false){};
};

std::ostream& operator<<(std::ostream& os, const transition& obj);

struct place {
    size_t id;
    std::string name;
    bool isTraced;
    size_t colorDom;
    std::vector<coloredToken> initMarking;
    std::string Marking;
    place(){ colorDom = UNCOLORED_DOMAIN; isTraced = true; }
};
std::ostream& operator<<(std::ostream& os, const place& obj);

struct arc {
    arc(size_t v):isEmpty(false),isMarkDep(false),isColored(false),intVal(v){};
    arc(const std::string &s):isEmpty(false),isMarkDep(true),isColored(false),intVal(1),stringVal(s){};
    arc():isEmpty(true),isMarkDep(false),isColored(false),intVal(0){};
    arc(const std::string &s,const std::vector<coloredToken> &vct):isEmpty(false),isMarkDep(true),intVal(1),stringVal(s),coloredVal(vct){
        isColored = vct.size()>0;
    }
    bool isEmpty;
    bool isMarkDep;
    bool isColored;
    size_t intVal;
    std::string stringVal;
    std::vector<coloredToken> coloredVal;
};

struct classcomp {
    bool operator() (const std::pair<size_t,size_t> &lhs,const std::pair<size_t,size_t> &rhs) const
    {
    if(lhs.first == rhs.first){
        return lhs.second< rhs.second;
    }
    else return lhs.first<rhs.first;
    }
};

typedef std::map< std::pair<size_t,size_t>, arc, classcomp>  arcStore;

struct GspnType {
    size_t tr;
    size_t pl;
    size_t nbpass;

    std::set<std::string> TransList;
    std::vector<colorClass> colClasses;
    std::vector<colorDomain> colDoms;
    std::vector<colorVariable> colVars;
    std::vector<hybridVariable> hybridVars;

    std::map<std::string, int> PlacesId;
    std::map<std::string, int> TransId;

    std::vector<transition> transitionStruct;
    std::vector<place> placeStruct;
    std::vector<userDefineDistribution> distribStruct;

    inline std::pair<size_t, size_t> arckey(size_t t,size_t p)const { return std::make_pair(t,p); };
    inline size_t get_t(std::pair<size_t, size_t> key)const {return key.first;};
    inline size_t get_p(std::pair<size_t, size_t> key)const {return key.second;};
    inline const arc access(const arcStore &h,size_t t, size_t p)const{
        static const arc emptyarc;
        auto a = h.find(arckey(t,p));
        if(a == h.end()){return emptyarc;}else return a->second;
    };
    arcStore inArcsStruct;
    arcStore outArcsStruct;
    arcStore inhibArcsStruct;

    std::map <std::string, int> IntConstant;
    std::map <std::string, double> RealConstant;
    std::set <std::string> ExternalConstant;
    
    inline bool isColored()const{
        return colClasses.size()>0;
    }
    
    GspnType(){
        nbpass=0;
        colDoms.push_back(colorDomain());
    }
};

void searchreplace(const std::string &in,const std::string &motif,const std::string &rep,std::string &out);



#endif /* defined(__Cosmos__Gspn_model__) */
