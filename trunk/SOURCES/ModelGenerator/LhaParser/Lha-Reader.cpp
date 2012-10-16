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

#include "lex.lha.c"

#include "Lha-parser.tab.hh"
#include "Lha-Reader.hpp"
#include "Lha_gmlparser.hpp"

#include "string.h"

#include <string>
#include <sstream>
#include <fstream>
#include <set>




using namespace std;

Lha_Reader::Lha_Reader() {
    trace_scanning = false;
    trace_parsing = false;

}

Lha_Reader::~Lha_Reader() {
}

int Lha_Reader::parse(string& expr) {




    IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;

    scan_expression(expr);

    lha::Lha_parser parser(*this);

    parser.set_debug_level(trace_parsing);

    int res = parser.parse();
    scan_end();
    return res;
}

int Lha_Reader::parse_file(string &filename) {
    string str;

    ifstream file(filename.c_str(), ios::in);
    if (file) {


        while (!file.eof()) {

            string str2;
            getline(file, str2);
            str = str + "\n" + str2;
        }

        int x = parse(str);
        if (x) cout << "Parsing LHA description file failed" << endl;


        return x;
    } else {
        cout << "Can't open : " << filename << endl;
        return 1;
    }
}
int Lha_Reader::parse_gml_file(string &filename) {
    ifstream ifile(filename.c_str());
    if(ifile){
        //cout << "parse GML:" << filename << endl;
        ModelHandlerPtr handlerPtr(new MyLhaModelHandler(&MyLha));
        ExpatModelParser parser = ExpatModelParser(handlerPtr);
        parser.parse_file(filename);
        //cout << "end parse GML"<< endl;
        return 0;
    }else{
        cout << "File " << filename << " does not exist!" << endl;
        exit(EXIT_FAILURE);
    }
    
	
}

string Lha_Reader::InvRelOp(string& str) {
    if (str == "<=") return ">=";
    if (str == ">=") return "<=";
}

void
Lha_Reader::error(const lha::location& l, const std::string& m) {
    std::cerr << l << ": " << m << std::endl;
}

void
Lha_Reader::error(const std::string& m) {
    std::cerr << m << std::endl;
}

void Lha_Reader::view() {


}

void Lha_Reader::WriteFile(parameters& P) {
	string Pref = P.tmpPath;

    string loc;

    //loc = Pref + "../SOURCES/Cosmos/LHA.cpp";
    loc = Pref + "/LHA.cpp";
	
	ofstream LhaCppFile(loc.c_str(), ios::out | ios::trunc);

    /*loc = Pref + "../SOURCES/ModelGenerator/LHA_orig.cpp";
    ifstream LhaCppFile_orig(loc.c_str(), ios::in);

    while (!LhaCppFile_orig.eof()) {

        string LineFile;
        getline(LhaCppFile_orig, LineFile);
        LhaCppFile << LineFile << endl;
    }
    LhaCppFile_orig.close();
	*/
	
	LhaCppFile << "#include \"LHA_orig.hpp\"" << endl;
	LhaCppFile << "#include <math.h>" << endl;
	LhaCppFile << "#include <float.h>" << endl;
	
	LhaCppFile << "class LHA: " << endl << "public LHA_ORIG {" << endl;
	LhaCppFile << "public:"<< endl;
	LhaCppFile << "    void Load();" <<endl;
	LhaCppFile << "    double GetFlow(int, int, vector<int>&);" <<endl;
	LhaCppFile << "    bool CheckLocation(int, vector<int>&);" <<endl;
	LhaCppFile << "    bool CheckEdgeContraints(int, double, vector<int>&);" <<endl;
	LhaCppFile << "    t_interval GetEdgeEnablingTime(int, vector<int>&);" <<endl;
	LhaCppFile << "    int GetEnabled_S_Edges(int, int, double, vector<int>&, vector<int>&);" <<endl;
	LhaCppFile << "    void DoEdgeUpdates(int, vector<int>&);" <<endl;
	LhaCppFile << "    void UpdateLinForm(vector<int>&);" <<endl;
	LhaCppFile << "    void UpdateLhaFunc(double&, double&);" <<endl;
	LhaCppFile << "    void UpdateFormulaVal();" <<endl;
	
	
	//LhaCppFile << "private:" << endl;
	
	/*
	for (int e = 0; e < MyLha.Edge.size(); e++)
        LhaCppFile << "t_interval GetEdgeEnablingTime_" << e << "(vector<int>& );" << endl;
	 */
	/*
    for (int e = 0; e < MyLha.Edge.size(); e++)
        LhaCppFile << "void DoEdgeUpdates_" << e << "(vector<int>& );" << endl;
	*/
    
	
	LhaCppFile << "};"<< endl;
	

	for (map<string,double>::iterator it= MyLha.LhaRealConstant.begin(); it!= MyLha.LhaRealConstant.end() ; it++) {
		LhaCppFile << "    const double " << it->first << "=" << it->second << ";" << endl;
	}

    LhaCppFile << "void LHA::Load(){" << endl;


    LhaCppFile << "    NbLoc =" << MyLha.NbLoc << ";" << endl;
    LhaCppFile << "    NbVar =" << MyLha.NbVar << ";" << endl;
    for (set<unsigned int>::iterator it = MyLha.InitLoc.begin(); it != MyLha.InitLoc.end(); it++)
        LhaCppFile << "    InitLoc.insert(" << (*it) << ");" << endl;
    for (set<unsigned int>::iterator it = MyLha.FinalLoc.begin(); it != MyLha.FinalLoc.end(); it++)
        LhaCppFile << "    FinalLoc.insert(" << (*it) << ");" << endl;

	if(P.CountTrans)
		LhaCppFile << "    EdgeCounter = vector<int>("<<MyLha.Edge.size()<<",0);"<< endl;
    LhaCppFile << "    vector<LhaEdge> ve(" << MyLha.Edge.size() << ");" << endl;
    LhaCppFile << "    Edge= ve;\n" << endl;
	
	if(P.StringInSpnLHA){
		for (map <string, int>::iterator it = MyLha.LocIndex.begin(); it != MyLha.LocIndex.end(); it++)
			LhaCppFile << "    LocIndex[\"" << (*it).first << "\"]=" << (*it).second << ";" << endl;
		
		LhaCppFile << "\n    vector<string> vlstr(NbLoc);" << endl;
		LhaCppFile << "    LocLabel= vlstr;" << endl;
		LhaCppFile << "    StrLocProperty= vlstr;\n" << endl;
		
		LhaCppFile << "    vector < vector <string> >  vestr(" << MyLha.Edge.size() << ");" << endl;
		LhaCppFile << "    ConstraintsRelOp= vestr;" << endl;
		LhaCppFile << "    ConstraintsConstants= vestr;" << endl;
		
		
		LhaCppFile << "    vector < vector< vector <string> > > mvestr(" << MyLha.Edge.size() << ");" << endl;
		
		LhaCppFile << "    ConstraintsCoeffs= mvestr;\n" << endl;
	
		for (int i = 0; i < MyLha.LocLabel.size(); i++)
			LhaCppFile << "    LocLabel[" << i << "]=\"" << MyLha.LocLabel[i] << "\";" << endl;

		for (int i = 0; i < MyLha.StrLocProperty.size(); i++)
			LhaCppFile << "    StrLocProperty[" << i << "]=\"" << MyLha.StrLocProperty[i] << "\";" << endl;
	}
		
    for (map <string, int>::iterator it = MyLha.EdgeIndex.begin(); it != MyLha.EdgeIndex.end(); it++)
        LhaCppFile << "    EdgeIndex[\"" << (*it).first << "\"]=" << (*it).second << ";" << endl;

    for (int i = 0; i < MyLha.Edge.size(); i++) {
        LhaCppFile << "    Edge[" << i << "].Index=" << MyLha.Edge[i].Index << ";" << endl;
        LhaCppFile << "    Edge[" << i << "].Source=" << MyLha.Edge[i].Source << ";" << endl;
        LhaCppFile << "    Edge[" << i << "].Target=" << MyLha.Edge[i].Target << ";" << endl;
        if (MyLha.EdgeActions[i].size() < 1)
            LhaCppFile << "    Edge[" << i << "].Type= Auto ;" << endl;
        else
            LhaCppFile << "    Edge[" << i << "].Type= Synch;" << endl;

    }

    for (int i = 0; i < MyLha.Edge.size(); i++) {
		
        int NbC = MyLha.ConstraintsRelOp[i].size();
		
		if(P.StringInSpnLHA){
			LhaCppFile << "\n    {" << endl;
			LhaCppFile << "    vector <string> vcstr(" << NbC << ");" << endl;
			LhaCppFile << "    ConstraintsRelOp[" << i << "]=vcstr;" << endl;
			LhaCppFile << "    ConstraintsConstants[" << i << "]=vcstr;" << endl;
			LhaCppFile << "    vector <string>  vcvstr(NbVar, \"\");" << endl;
			LhaCppFile << "    vector < vector <string> > v2cvstr(" << NbC << ",vcvstr);" << endl;
			LhaCppFile << "    ConstraintsCoeffs[" << i << "]=v2cvstr;" << endl;
			LhaCppFile << "    }" << endl;
			
			for (int c = 0; c < NbC; c++) {
				LhaCppFile << "    ConstraintsRelOp[" << i << "][" << c << "]=\"" << MyLha.ConstraintsRelOp[i][c] << "\";" << endl;
				LhaCppFile << "    ConstraintsConstants[" << i << "][" << c << "]=\"" << MyLha.ConstraintsConstants[i][c] << "\";" << endl;
				for (int v = 0; v < MyLha.NbVar; v++)
					LhaCppFile << "    ConstraintsCoeffs[" << i << "][" << c << "][" << v << "]=\"" << MyLha.ConstraintsCoeffs[i][c][v] << "\";" << endl;
			}
		}
    }
	

    LhaCppFile << "\n    vector<double> vdouble(NbVar);" << endl;
    LhaCppFile << "    Var=vdouble;" << endl;
	if(P.StringInSpnLHA){
		LhaCppFile << "    vector<string> VarStr(NbVar);" << endl;
		LhaCppFile << "    VarLabel=VarStr;" << endl;
	}
		
    for (int v = 0; v < MyLha.NbVar; v++) {
        LhaCppFile << "    Var[" << v << "]=" << 0 << ";" << endl;
		if(P.StringInSpnLHA){
			LhaCppFile << "    VarLabel[" << v << "]=\"" << MyLha.VarLabel[v] << "\";" << endl;
			LhaCppFile << "    VarIndex[\"" << MyLha.VarLabel[v] << "\"]=" << v << ";" << endl;
		}
	}

	if(P.StringInSpnLHA){
		LhaCppFile << "\n    vector<string> vStr(NbVar);" << endl;
		LhaCppFile << "    vector< vector <string > > vvStr(NbLoc,vStr);" << endl;
		LhaCppFile << "    StrFlow=vvStr;" << endl;
	}
    
	if(P.StringInSpnLHA){
	for (int l = 0; l < MyLha.NbLoc; l++)
        for (int v = 0; v < MyLha.NbVar; v++) {
            LhaCppFile << "    StrFlow[" << l << "][" << v << "]=\"" << MyLha.StrFlow[l][v] << "\";" << endl;
        }
	}

    LhaCppFile << "\n    vector< set < int > > vset(NbLoc);" << endl;
    LhaCppFile << "    Out_S_Edges =vset;" << endl;
    LhaCppFile << "    Out_A_Edges =vset;" << endl;
    for (int e = 0; e < MyLha.Edge.size(); e++) {
        if (MyLha.EdgeActions[e].size() < 1)
            LhaCppFile << "    Out_A_Edges[" << MyLha.Edge[e].Source << "].insert(" << e << ");" << endl;
        else
            LhaCppFile << "    Out_S_Edges[" << MyLha.Edge[e].Source << "].insert(" << e << ");" << endl;
    }

	if(P.StringInSpnLHA){
		LhaCppFile << "\n    vector< set <string> > vStrSet(" << MyLha.Edge.size() << ");" << endl;
		LhaCppFile << "    EdgeActions=vStrSet;" << endl;
	}
		
    LhaCppFile << "    vector< set<int> > vSetInt(" << MyLha.TransitionIndex.size() << ");" << endl;
    LhaCppFile << "    vector < vector < set <int> > > vvSetInt(NbLoc,vSetInt);" << endl;

    LhaCppFile << "    ActionEdges=vvSetInt;" << endl;
    for (int e = 0; e < MyLha.Edge.size(); e++) {
        for (set<string>::iterator it = MyLha.EdgeActions[e].begin(); it != MyLha.EdgeActions[e].end(); it++) {
            if(P.StringInSpnLHA)LhaCppFile << "    EdgeActions[" << e << "].insert(\"" << *it << "\");" << endl;
            LhaCppFile << "    ActionEdges[" << MyLha.Edge[e].Source << "][" << MyLha.TransitionIndex[*it] << "].insert(" << e << ");" << endl;
        }
    }
    LhaCppFile << "    if(true){" << endl;
    LhaCppFile << "    			vector<double> vL(" << MyLha.LinearForm.size() << ",0);" << endl;
    LhaCppFile << "    			LinForm=vL;" << endl;
    LhaCppFile << "    			OldLinForm=vL;" << endl;
    LhaCppFile << "    			vector<double> vF(" << MyLha.LhaFuncArg.size() << ",0);" << endl;
    LhaCppFile << "    			LhaFunc=vF;" << endl;
	if(P.CountTrans){
		LhaCppFile << "    			vector<double> vA(" << MyLha.Algebraic.size() + MyLha.Edge.size() << ",0);" << endl;
	} else {
		LhaCppFile << "    			vector<double> vA(" << MyLha.Algebraic.size() << ",0);" << endl;
    }
		
	LhaCppFile << "    			FormulaVal=vA;" << endl;
    LhaCppFile << "    }" << endl;
    LhaCppFile << "}\n" << endl;


    LhaCppFile << "double LHA::GetFlow(int v, int loc, vector<int>& Marking){" << endl;
    LhaCppFile << "    switch(v){" << endl;
    for (int x = 0; x < MyLha.NbVar; x++) {

        LhaCppFile << "    case " << x << ":" << endl;
        LhaCppFile << "         switch(loc){" << endl;
        for (int l = 0; l < MyLha.NbLoc; l++) {
            LhaCppFile << "         case " << l << ":" << endl;
            if (MyLha.FuncFlow[l][x] != "")
                LhaCppFile << "             return " << MyLha.FuncFlow[l][x] << ";" << endl;
            else
                LhaCppFile << "             return " << 0.0 << ";" << endl;
            LhaCppFile << "             break;" << endl;
        }
        LhaCppFile << "       }" << endl;
        LhaCppFile << "       break;" << endl;
    }
    LhaCppFile << "	}\n" << endl;
    LhaCppFile << "}\n" << endl;

    LhaCppFile << "bool LHA::CheckLocation(int loc, vector<int>& Marking){" << endl;
    LhaCppFile << "    switch(loc){" << endl;
    for (int l = 0; l < MyLha.NbLoc; l++) {
        LhaCppFile << "     case " << l << ":" << endl;
        LhaCppFile << "         return " << MyLha.FuncLocProperty[l] << ";" << endl;
        LhaCppFile << "         break;" << endl;
    }
    LhaCppFile << "    }" << endl;


    LhaCppFile << "}\n" << endl;

    LhaCppFile << "bool LHA::CheckEdgeContraints(int ed, double DeltaT, vector<int>& Marking){" << endl;
    LhaCppFile << "    switch(ed){" << endl;
    for (int e = 0; e < MyLha.Edge.size(); e++) {
        LhaCppFile << "    case " << e << ": {" << endl;
        for (int c = 0; c < MyLha.ConstraintsRelOp[e].size(); c++) {
            LhaCppFile << "         if(!( ";
            for (int v = 0; v < MyLha.NbVar; v++) {
                if (MyLha.ConstraintsCoeffs[e][c][v] != "")
                    LhaCppFile << "+(" << MyLha.ConstraintsCoeffs[e][c][v] << ")*(Var[" << v << "]+DeltaT*GetFlow(" << v << "," << MyLha.Edge[e].Source << ", Marking))";

            }
            LhaCppFile << MyLha.ConstraintsRelOp[e][c] << MyLha.ConstraintsConstants[e][c] << ")) return false;" << endl;


        }
        LhaCppFile << "         return true; " << endl;
        LhaCppFile << "         break;" << endl;
        LhaCppFile << "     }" << endl;
    }
    LhaCppFile << "    }" << endl;


    LhaCppFile << "}\n" << endl;


    LhaCppFile << "t_interval LHA::GetEdgeEnablingTime(int ed, vector<int>& Marking){" << endl;
    LhaCppFile << "    switch(ed){" << endl;
    for (int e = 0; e < MyLha.Edge.size(); e++) {
        LhaCppFile << "     case " << e << ":" << endl;

        //LhaCppFile << "         return GetEdgeEnablingTime_" << e << "( Marking);" << endl;
		LhaCppFile << "         {" << endl;
		
		LhaCppFile << "             t_interval EnablingT;\n" << endl;
        LhaCppFile << "             EnablingT.first=CurrentTime;" << endl;
        LhaCppFile << "             EnablingT.second=DBL_MAX;\n" << endl;
        LhaCppFile << "             t_interval EmptyInterval;\n" << endl;
        LhaCppFile << "             EmptyInterval.first=0;" << endl;
        LhaCppFile << "             EmptyInterval.second=-1;\n" << endl;
		
        LhaCppFile << "             double SumAF;" << endl;
        LhaCppFile << "             double SumAX;" << endl;
		
		
		
        LhaCppFile << "\n" << endl;
		
		
        for (int c = 0; c < MyLha.ConstraintsRelOp[e].size(); c++) {
			
            LhaCppFile << "             SumAF=";
            for (int v = 0; v < MyLha.NbVar; v++)
                if (MyLha.ConstraintsCoeffs[e][c][v] != "")
                    LhaCppFile << "+(" << MyLha.ConstraintsCoeffs[e][c][v] << ")*GetFlow(" << v << "," << MyLha.Edge[e].Source << ", Marking)";
            LhaCppFile << ";\n             SumAX=";
            for (int v = 0; v < MyLha.NbVar; v++)
                if (MyLha.ConstraintsCoeffs[e][c][v] != "")
                    LhaCppFile << "+(" << MyLha.ConstraintsCoeffs[e][c][v] << ")*Var[" << v << "]";
            LhaCppFile << ";\n" << endl;
			
            string RelOp = MyLha.ConstraintsRelOp[e][c];
			
            LhaCppFile << "             if(SumAF==0){" << endl;
            LhaCppFile << "                  if(!(SumAX" << MyLha.ConstraintsRelOp[e][c] << MyLha.ConstraintsConstants[e][c] << "))" << endl;
            LhaCppFile << "                      return EmptyInterval;" << endl;
            LhaCppFile << "             }" << endl;
            LhaCppFile << "             else{" << endl;
            LhaCppFile << "                  double t=CurrentTime+(" << MyLha.ConstraintsConstants[e][c] << "-SumAX)/(double)SumAF;" << endl;
            if (RelOp == "==") {
				
                LhaCppFile << "                  if(t>=EnablingT.first && t<=EnablingT.second){" << endl;
                LhaCppFile << "                      EnablingT.first=t; EnablingT.second=t;" << endl;
                LhaCppFile << "                  }" << endl;
                LhaCppFile << "                  else return EmptyInterval;" << endl;
				
            } else {
                LhaCppFile << "                  if(SumAF>0){" << endl;
                if (RelOp == "<=") {
                    LhaCppFile << "                     if(EnablingT.second>t) EnablingT.second=t;" << endl;
                    LhaCppFile << "                     if(EnablingT.second<EnablingT.first) return EmptyInterval;" << endl;
					
                } else {
                    LhaCppFile << "                     if(EnablingT.first<t) EnablingT.first=t;" << endl;
                    LhaCppFile << "                     if(EnablingT.second<EnablingT.first) return EmptyInterval;" << endl;
                }
				
                LhaCppFile << "                      }" << endl;
				
                LhaCppFile << "                  else{" << endl;
                RelOp = InvRelOp(RelOp);
                if (RelOp == "<=") {
                    LhaCppFile << "                     if(EnablingT.second>t) EnablingT.second=t;" << endl;
                    LhaCppFile << "                     if(EnablingT.second<EnablingT.first) return EmptyInterval;" << endl;
					
                } else {
                    LhaCppFile << "                     if(EnablingT.first<t) EnablingT.first=t;" << endl;
                    LhaCppFile << "                     if(EnablingT.second<EnablingT.first) return EmptyInterval;" << endl;
                }
				
                LhaCppFile << "                      }" << endl;
            }
            LhaCppFile << "             }" << endl;			
			
        }
		
        LhaCppFile << "             return EnablingT;" << endl;
		LhaCppFile << "         }"<< endl;
		
		
		//LhaCppFile << "         }" << endl;
        //LhaCppFile << "         break;" << endl;
		
	}
    
	LhaCppFile << "    }" << endl;

    LhaCppFile << "}\n" << endl;



    LhaCppFile << "void LHA::DoEdgeUpdates(int ed, vector<int>& Marking){" << endl;
    LhaCppFile << "    switch(ed){" << endl;
    for (int e = 0; e < MyLha.Edge.size(); e++) {
        LhaCppFile << "     case " << e << ":" << endl;
		LhaCppFile << "         {"<< endl;

		int k = 0;
		if(P.CountTrans)
			LhaCppFile << "         EdgeCounter[" << e << "]++ ;"<< endl;
        for (int v = 0; v < MyLha.NbVar; v++)
            if (MyLha.FuncEdgeUpdates[e][v] != "") {
                k++;
                break;
            }
        if (k > 0) {
            LhaCppFile << "         vector<double> TempVar(NbVar);" << endl;
            for (int v = 0; v < MyLha.NbVar; v++)
                if (MyLha.FuncEdgeUpdates[e][v] != "")
                    LhaCppFile << "         TempVar[" << v << "]=" << MyLha.FuncEdgeUpdates[e][v] << ";" << endl;
			
            for (int v = 0; v < MyLha.NbVar; v++)
                if (MyLha.FuncEdgeUpdates[e][v] != "") {
                    LhaCppFile << "         Var[" << v << "]=TempVar[" << v << "];" << endl;
					
					
                }
        }
        LhaCppFile << endl;
        for (map<string, int>::iterator it = MyLha.LinearForm.begin(); it != MyLha.LinearForm.end(); it++) {
            LhaCppFile << "         OldLinForm[" << (*it).second << "]=LinForm[" << (*it).second << "];" << endl;
			
        }
		
        //LhaCppFile << "         DoEdgeUpdates_" << e << "( Marking);" << endl;
        LhaCppFile << "         }"<< endl;
		LhaCppFile << "         break;" << endl;
    }
    LhaCppFile << "    }" << endl;


    LhaCppFile << "}\n" << endl;



    /*for (int e = 0; e < MyLha.Edge.size(); e++) {
        LhaCppFile << "void LHA::DoEdgeUpdates_" << e << "(vector<int>& Marking){" << endl;
        
        LhaCppFile << "    }\n" << endl;
    }*/

    LhaCppFile << "void LHA::UpdateLinForm(vector<int>& Marking){" << endl;
    for (map<string, int>::iterator it = MyLha.LinearForm.begin(); it != MyLha.LinearForm.end(); it++) {
        LhaCppFile << "    LinForm[" << (*it).second << "]=" << (*it).first << ";" << endl;

    }
    LhaCppFile << "    }\n" << endl;

    LhaCppFile << "void LHA::UpdateLhaFunc(double& t, double& Delta ){" << endl;
    for (int i = 0; i < MyLha.LhaFuncArg.size(); i++) {
        if (MyLha.LhaFuncType[i] == "Last")
            LhaCppFile << "    LhaFunc[" << i << "]=LinForm[" << MyLha.LhaFuncArg[i] << "];" << endl;
        else {
            if (MyLha.LhaFuncType[i] == "Min")
                LhaCppFile << "    LhaFunc[" << i << "]=Min(LhaFunc[" << i << "],LinForm[" << MyLha.LhaFuncArg[i] << "],OldLinForm[" << MyLha.LhaFuncArg[i] << "]);" << endl;
            else {
                if (MyLha.LhaFuncType[i] == "Max")
                    LhaCppFile << "    LhaFunc[" << i << "]=Max(LhaFunc[" << i << "],LinForm[" << MyLha.LhaFuncArg[i] << "],OldLinForm[" << MyLha.LhaFuncArg[i] << "]);" << endl;
                else {
                    if (MyLha.LhaFuncType[i] == "Integral")
                        LhaCppFile << "    LhaFunc[" << i << "]=Integral(LhaFunc[" << i << "], t, Delta, OldLinForm[" << MyLha.LhaFuncArg[i] << "],LinForm[" << MyLha.LhaFuncArg[i] << "]);" << endl;

                }
            }
        }

    }

    LhaCppFile << "\n    }\n" << endl;
    LhaCppFile << "void LHA::UpdateFormulaVal(){\n" << endl;
    for(int i=0;i<MyLha.Algebraic.size();i++){
      LhaCppFile << "    OldFormulaVal=FormulaVal["<<i<<"];" << endl;
      LhaCppFile << "    FormulaVal["<<i<<"]=" << MyLha.Algebraic[i] << ";\n" << endl;
    }
	if (P.CountTrans) {
			for(int i=0;i<MyLha.Edge.size();i++){
				int j = i+ MyLha.Algebraic.size();
				LhaCppFile << "    FormulaVal["<<j<<"]= EdgeCounter[" << i << "];\n";
			}
	}
    LhaCppFile << "}\n" << endl;


    LhaCppFile.close();


}
