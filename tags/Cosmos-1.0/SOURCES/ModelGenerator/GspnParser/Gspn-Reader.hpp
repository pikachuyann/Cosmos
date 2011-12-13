/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
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
 *                                                                             *
 *******************************************************************************
 */



#ifndef GSPN_READER_HH
#define GSPN_READER_HH
#include <string>
#include <map>
#include <set>

#include "Gspn-parser.tab.hh"
#include "../Eval/Eval.hpp"
#include <vector>
#include <map>
#include <set>

using namespace std;

enum TransType {
    Timed, unTimed
};

typedef vector <int> Dim1;
typedef vector <int> IntVector;
typedef vector <Dim1> Dim2;
typedef vector <IntVector> IntMatrix;

struct ProbabiliteDistribution {
    std::string name;
    vector<string> Param;
};

typedef struct ProbabiliteDistribution Distribution;

struct GSPN {
    string Path;
    int tr;
    int pl;

    set<string> PlacesList;
    set<string> TransList;

    map<string, int> PlacesId;
    map<string, int> TransId;

    vector<Distribution> Dist;
    vector<string> Priority;
    vector<string> Weight;
    vector<bool> SingleService;
    vector<bool> MarkingDependent;
    vector<int> NbServers;
    vector<bool> AgeMemory;


    vector<TransType> tType;

    IntMatrix inArcs;
    IntMatrix outArcs;
    IntMatrix inhibArcs;
    vector < vector<string> > inArcsStr;
    vector < vector<string> > outArcsStr;
    vector < vector<string> > inhibArcsStr;
    vector <int> Marking;


    map <std::string, int> IntConstant;
    map <std::string, double> RealConstant;

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
    Gspn_Reader();

    virtual ~Gspn_Reader();

    GspnType MyGspn;
    map<string, int> IndexDist;



    void scan_begin();
    void scan_end();
    void scan_expression(const string&);

    bool trace_scanning;


    int parse(std::string&);
    int parse_file(std::string&);
    void WriteFile(string&);

    bool trace_parsing;


    void error(const gspn::location& l, const std::string& m);
    void error(const std::string& m);

    void view();
};
#endif // ! GSPN_READER_HH
