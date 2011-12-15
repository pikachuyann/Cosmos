/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *									       *
 * Copyright (C) 2009-2011 LSV & LACL                                          *
 * Authors: Paolo Ballarini & Hilal Djafri                                     *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *									       *
 *									       *
 *******************************************************************************
 */



#ifndef LHA_READER_HH
#define LHA_READER_HH
#include <string>
#include <map>
#include <set>

#include "Lha-parser.tab.hh"
#include <vector>
#include <map>
#include <set>


using namespace std;

enum EdgeType {
    Auto, Synch
};

struct _LhaEdge {
    unsigned int Index;
    unsigned int Source;
    unsigned int Target;
    EdgeType Type;
};
typedef struct _LhaEdge LhaEdge;

struct LHA {
    string label;
    unsigned int NbLoc; // number of locations   

    set <unsigned int, less<unsigned int> > InitLoc; // initial locations
    set <unsigned int, less<unsigned int> > FinalLoc; // final locations

    map <string, int> LocIndex; //for a given Location label returns its index among {0, 1, ..., NLoc-1}
    vector <string> LocLabel;

    vector <string> StrLocProperty;
    vector <string> FuncLocProperty;



    map<string, int> EdgeIndex;
    vector <LhaEdge> Edge;
    LhaEdge AnEdge;

    vector <string> EdgeConstraints;
    vector < set<string> > EdgeActions; //return the set of actions associated for a given edge e, EdgeActions[e]{a1,a2, ...}
    vector < vector < string > > FuncEdgeUpdates;
    vector <string> StrEdgeUpdates;

    vector < vector <vector <string> > > ConstraintsCoeffs;
    vector < vector <string> > ConstraintsRelOp;
    vector < vector <string> > ConstraintsConstants;



    vector < set <int> > Out_S_Edges; // for a given location l returns the set of synchronizing edges  starting from l
    vector < set <int> > Out_A_Edges; // for a given location l returns the set of autonomous edges  starting from l   
    vector < vector < set <int> > > ActionEdges; // return the set of edges starting from location cl such that action a is an action for these edges, ActionsLoc[cl][a]={e1, e2, ...}

    int NbVar;
    vector <double> Var; // Var[i] value of the variable indexed by i
    map<string, int> VarIndex; //for a given variable label return its index among {0, 1, ..., NbVar-1}
    vector <string> VarLabel;

    vector < vector <string> > FuncFlow;
    vector < vector <string> > StrFlow;

    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}

    map<string, int> LinearForm;
    vector<int> LhaFuncArg;
    vector<string> LhaFuncType;
    string Algebraic;

    map <std::string, int> LhaIntConstant; //contains constants defined like int
    map <std::string, double> LhaRealConstant; //contains constants defined like double and constants defined linke int
    map <std::string, int> LhaFunction;




};

typedef struct LHA LhaType;



#define LHA_DECL                                            \
  lha::Lha_parser::token_type                         \
  lhalex (lha::Lha_parser::semantic_type* lhalval,      \
         lha::Lha_parser::location_type* lhalloc,      \
         Lha_Reader& Reader)

LHA_DECL;

class Lha_Reader {
public:
    Lha_Reader();
    virtual ~Lha_Reader();

    LhaType MyLha;
   



    void scan_begin();
    void scan_end();
    void scan_expression(const string&);

    bool trace_scanning;


    int parse(std::string&);
    int parse_file(std::string&);

    string InvRelOp(string &);
    void WriteFile(string&);

    bool trace_parsing;


    void error(const lha::location& l, const std::string& m);
    void error(const std::string& m);

    void view();
};
#endif 
