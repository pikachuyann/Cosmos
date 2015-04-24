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

#ifndef GSPN_READER_HH
#define GSPN_READER_HH
#include <string>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>
#include <vector>

#include "../expressionStruct.hpp"
#include "../parameters.hpp"
#include "Gspn-parser.hh"
#include "../Eval/Eval.hpp"
#include "expatmodelparser.hh"
#include "modelhandler.hh"


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
    CT_ALL
};

struct coloredToken {
	std::string mult;
	std::vector<size_t> field;
	std::vector<varType> Flags;
	std::vector<int> varIncrement;
	bool hasAll;
    coloredToken():hasAll(false){};
    coloredToken(string st):mult(st),hasAll(false){};
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
    transition(){ isTraced = true; }
    transition(size_t i,const std::string &n,const expr &p,bool md):id(i),label(n),isTraced(true),
    type(Timed),dist(p),priority(expr(1)),weight(expr(1.0)),singleService(true),
    markingDependant(md),nbServers(1),ageMemory(false){};
};

struct place {
	size_t id;
	string name;
    bool isTraced;
	size_t colorDom;
    //vector<coloredToken> initMarking;
	place(){ colorDom = UNCOLORED_DOMAIN; isTraced = true; }
};

struct arc {
	arc(size_t v):isEmpty(false),isMarkDep(false),isColored(false),intVal(v){};
	arc(const string &s):isEmpty(false),isMarkDep(true),isColored(false),intVal(1),stringVal(s){};
	arc():isEmpty(true),isMarkDep(false),isColored(false),intVal(0){};
	arc(const string &s,const vector<coloredToken> &vct):isEmpty(false),isMarkDep(true),intVal(1),stringVal(s),coloredVal(vct){
			isColored = vct.size()>0;
	}
	bool isEmpty;
	bool isMarkDep;
	bool isColored;
	size_t intVal;
	string stringVal;
	vector<coloredToken> coloredVal;
};


struct classcomp {
    bool operator() (const pair<size_t,size_t> &lhs,const pair<size_t,size_t> &rhs) const
    {
    if(lhs.first == rhs.first){
        return lhs.second< rhs.second;
    }
    else return lhs.first<rhs.first;
    }
};


typedef map< pair<size_t,size_t>, arc, classcomp>  arcStore;

struct GspnType {
    size_t tr;
    size_t pl;
    size_t nbpass;
	
    set<string> TransList;
	vector<colorClass> colClasses;
	vector<colorDomain> colDoms;
	vector<colorVariable> colVars;
	
    map<string, int> PlacesId;
    map<string, int> TransId;
	
	vector<transition> transitionStruct;
	vector<place> placeStruct;

    inline pair<size_t, size_t> arckey(size_t t,size_t p)const { return make_pair(t,p); };
    inline size_t get_t(pair<size_t, size_t> key)const {return key.first;};
    inline size_t get_p(pair<size_t, size_t> key)const {return key.second;};
    inline const arc access(const arcStore &h,size_t t, size_t p)const{
        static const arc emptyarc;
        auto a = h.find(arckey(t,p));
        if(a == h.end()){return emptyarc;}else return a->second;
    };
    arcStore inArcsStruct;
    arcStore outArcsStruct;
    arcStore inhibArcsStruct;
    /*vector< vector<arc> > inArcsStruct;
	vector< vector<arc> > outArcsStruct;
	vector< vector<arc> > inhibArcsStruct;*/
	
    vector<string> Marking;
    vector<vector<coloredToken> > InitialMarking;
	
    map <std::string, int> IntConstant;
    map <std::string, double> RealConstant;
    set <std::string> ExternalConstant;
	
	inline bool isColored(){
		return colClasses.size()>0;
	}
	
	GspnType(){
		nbpass=0;
		colDoms.push_back(colorDomain());
	}
	
};

void searchreplace(const string &in,const string &motif,const string &rep,string &out);


#define GSPN_DECL                                            \
gspn::Gspn_parser::token_type                         \
gspnlex (gspn::Gspn_parser::semantic_type* gspnlval,      \
gspn::Gspn_parser::location_type* gspnlloc,      \
Gspn_Reader& Reader)

GSPN_DECL;

class Gspn_Reader {
public:
    Gspn_Reader(parameters &P);
	
    virtual ~Gspn_Reader();
	
    GspnType MyGspn;
	
	int parse(std::string&);
    int parse_file(std::string&);
	int parse_gml_file(parameters&);
	
	void error(const gspn::location& l, const std::string& m);
	
	
	void iterateDom(const string &s,const string &sop, const string &sclos ,const string &s2,const string &sop2, const string &sclos2 ,const colorDomain & cd, size_t prof,std::function<void (const string&,const string&)> func);
    void iterateDomVec(vector<color> &v, const colorDomain & cd, size_t prof,std::function<void (const vector<color>&)> func);

	
	void iterateVars(const string &s,const string &sop, const string &sclos ,const set<size_t> &varDom, size_t prof,std::function<void (const string&)> func);
	void iterateVars(vector<color> &v, const set<size_t> &varDom, size_t prof,std::function<void (const vector<color>&)> func);
	
	//<! Index of distribution type.
	map<string, int> IndexDist;
	parameters P;
	
private:
	
    void scan_begin();
    void scan_end();
    void scan_expression(const string&);
	
    bool trace_scanning;
	
    bool trace_parsing;
	
	
    
    void error(const std::string& m);
    
    //void addSink();
    void addSinkTrans();
    
    void view();
	
};
#endif // ! GSPN_READER_HH
