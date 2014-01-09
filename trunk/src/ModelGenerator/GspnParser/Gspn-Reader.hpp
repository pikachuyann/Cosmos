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


#include "../parameters.hpp"
#include "Gspn-parser.hh"
#include "../Eval/Eval.hpp"
#include <vector>
#include "expatmodelparser.hh"
#include "modelhandler.hh"

using namespace std;

//! A type to discriminate timed and untimmed transition.
enum TransType {
    Timed, unTimed
};

typedef vector <int> Dim1;
typedef vector <int> IntVector;
typedef vector <Dim1> Dim2;
typedef vector <IntVector> IntMatrix;

//! a structure for probability distribution
struct ProbabiliteDistribution {
    std::string name;
    vector<string> Param;
};


typedef struct ProbabiliteDistribution Distribution;

struct color {
	string name;
	color(){};
	color(const string s){ name =s;}
};
struct colorClass {
	string name;
	bool isCircular;
	vector<color> colors;
	inline string cname()const {
		return name+ "_Color_Classe";
	}
};


#define UNCOLORED_DOMAIN (0)

struct colorDomain {
	string name;
	vector<size_t> colorClassIndex;
	inline bool isUncolored()const {
		return name.size() ==0;
	}
	inline string cname()const {
		if(isUncolored())return "int";
		return name+ "_Domain";
	}
	inline string tokname()const {
		if(isUncolored())return " ";
		return name+ "_Token";
	}
};

struct colorVariable {
	string name;
	size_t type;
};

#define CT_SINGLE_COLOR 0
#define CT_VARIABLE 1
#define CT_ALL 2

struct coloredToken {
	string mult;
	vector<size_t> field;
	vector<char> Flags;
	vector<int> varIncrement;
	bool hasAll;
};

struct transition {
	string label;
	TransType type;
	Distribution dist;
	string priority;
	string weight;
	bool singleService;
	bool markingDependant;
	int nbServers;
	bool ageMemory;
	set<size_t> varDomain;
	string guard;
};

struct place {
	string name;
	size_t colorDom;
	bool isTraced;
	place(){ colorDom = UNCOLORED_DOMAIN; isTraced = true; }
};

struct GSPN {
    string Path;
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
	
    IntMatrix inArcs;
    IntMatrix outArcs;
    IntMatrix inhibArcs;
    vector < vector<string> > inArcsStr;
    vector < vector<string> > outArcsStr;
    vector < vector<string> > inhibArcsStr;
	vector < vector< vector< coloredToken> > > inArcsTok;
	vector < vector< vector< coloredToken> > > outArcsTok;
	vector < vector< vector< coloredToken> > > inhibArcsTok;
	
    vector <string> Marking;
	
    map <std::string, int> IntConstant;
    map <std::string, double> RealConstant;
	
	inline bool isColored(){
		return colClasses.size()>0;
	}
	
	GSPN(){
		nbpass=0;
		colDoms.push_back(colorDomain());
	}
	
};

typedef struct GSPN GspnType;



#define GSPN_DECL                                            \
gspn::Gspn_parser::token_type                         \
gspnlex (gspn::Gspn_parser::semantic_type* gspnlval,      \
gspn::Gspn_parser::location_type* gspnlloc,      \
Gspn_Reader& Reader)

GSPN_DECL;
using namespace std;

class Gspn_Reader {
public:
    Gspn_Reader(parameters &P);
	
    virtual ~Gspn_Reader();
	
    GspnType MyGspn;
	
	int parse(std::string&);
    int parse_file(std::string&);
	int parse_gml_file(parameters&);
    void WriteFile(parameters&);
	
	void error(const gspn::location& l, const std::string& m);
	
	//<! Index of distribution type.
	map<string, int> IndexDist;
	parameters P;
	
private:
	
	
	
	
    void scan_begin();
    void scan_end();
    void scan_expression(const string&);
	
    bool trace_scanning;
	
	int varMultiplier(size_t var);
	void writeMarkingClasse(ofstream &, ofstream &, parameters &);
	void writeEnabledDisabled(ofstream &);
	void writeEnabledDisabledBinding(ofstream &);
	void writeUpdateVect(ofstream &,const string &name,const vector< set<int> > &vect);
	void writeTransition(ofstream &, bool);
	void writeVariable(ofstream & spnF);
	
    bool trace_parsing;
	
	
    
    void error(const std::string& m);
    
    //void addSink();
    void addSinkTrans();
    
    void view();
	
	void printloot(ofstream& sf, size_t domain, size_t nesting );
	
	void EnabledDisabledTr(vector< set<int> >&,
						   vector< set<int> >&,
						   vector< set<int> >&);
};
#endif // ! GSPN_READER_HH
