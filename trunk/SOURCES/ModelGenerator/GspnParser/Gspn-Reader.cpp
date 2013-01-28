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

#include "lex.gspn.c"

#include "Gspn-parser.tab.hh"
#include "Gspn-Reader.hpp"
#include "Gspn_gmlparser.hpp"


#include "string.h"

#include <string>
#include <sstream>
#include <fstream>
#include <set>




using namespace std;

Gspn_Reader::Gspn_Reader() {
    trace_scanning = false;
    trace_parsing = false;
	
	IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;
	IndexDist["ERLANG"] = 7;
	IndexDist["GAMMA"] =8;
	
	
}

Gspn_Reader::~Gspn_Reader() {
}

int Gspn_Reader::parse(string& expr) {
	
    scan_expression(expr);
	
    gspn::Gspn_parser parser(*this);
	
    parser.set_debug_level(trace_parsing);
	
    int res = parser.parse();
    scan_end();
    return res;
}

int Gspn_Reader::parse_file(string &filename) {
    string str;
	
    ifstream file(filename.c_str(), ios::in);
    if (file) {
		
        while (!file.eof()) {
			
            string str2;
            getline(file, str2);
            str = str + "\n" + str2;
        }
        file.close();
        /*filename.append(".mod");
		 ifstream Modfile(filename.c_str(), ios::in);
		 if (Modfile) {
		 
		 while (!Modfile.eof()) {
		 
		 string str2;
		 getline(Modfile, str2);
		 str = str + "\n" + str2;
		 }
		 
		 }*/
        int x = parse(str);
		
        if (x) cout << "Parsing GSPN Description file failed" << endl;
		
        return x;
    } else {
        cout << "Can't open : " << filename << endl;
        return 1;
    }
}

//#include "Gspn_gmlparser.cpp";
int Gspn_Reader::parse_gml_file(string &filename,bool re) {
    ifstream ifile(filename.c_str());
    if(ifile){
		//cout << "parse GML:" << filename << endl;
        ModelHandlerPtr handlerPtr(new MyModelHandler(&MyGspn,re));
		ExpatModelParser parser = ExpatModelParser(handlerPtr);
		parser.parse_file(filename);
		//cout << "end parse GML:"<< MyGspn.pl << endl;
        if (re)addSinkTrans();
		return 0;
    }else{
        cout << "File " << filename << " does not exist!" << endl;
        exit(EXIT_FAILURE);
    }
    
}

void
Gspn_Reader::error(const gspn::location& l, const std::string& m) {
    std::cerr << l << ": " << m << std::endl;
}

void
Gspn_Reader::error(const std::string& m) {
    std::cerr << m << std::endl;
}

/*void Gspn_Reader::addSink(){
 //Add a place
 MyGspn.Marking.push_back(0);
 string Plname = "Puit";
 MyGspn.PlacesList.insert(Plname);
 MyGspn.PlacesId[Plname]=MyGspn.pl;
 MyGspn.pl++;
 
 //Add a transition
 string Trname = "Puittrans";
 MyGspn.TransList.insert(Trname);
 MyGspn.TransId[Trname]=MyGspn.tr;
 ProbabiliteDistribution& dist = *(new ProbabiliteDistribution);
 dist.name = "EXPONENTIAL";
 dist.Param.push_back("0");
 MyGspn.Dist.push_back(dist);
 MyGspn.tType.push_back(Timed);
 MyGspn.Priority.push_back("1");
 MyGspn.Weight.push_back("1");
 MyGspn.SingleService.push_back(true);
 MyGspn.MarkingDependent.push_back(true);
 MyGspn.NbServers.push_back(1);
 MyGspn.tr++;
 }*/

void Gspn_Reader::addSinkTrans(){
    (MyGspn.outArcs)[MyGspn.tr-1][MyGspn.pl-1]=1;
}

void Gspn_Reader::EnabledDisabledTr(vector< set<int> > PossiblyEnabled,
									vector< set<int> > PossiblyDisabled,
									vector< set<int> > FreeMarkDepT) {
	
    for (size_t t1 = 0; t1 < MyGspn.tr; t1++) {
        set<int> S;
        set<int> Sinhib;
        set<int> INt1;
        for (size_t p = 0; p < MyGspn.pl; p++) {
            if (MyGspn.inArcs[t1][p] > 0) {
                INt1.insert(p);
            }
        }
        for (size_t t2 = 0; t2 < MyGspn.tr; t2++)
            if (t1 != t2) {
                size_t size = INt1.size();
                set<int> INt1t2 = INt1;
                bool B = true;
                size_t p = 0;
                while (B && p < MyGspn.pl) {
                    if (MyGspn.inArcs[t2][p] > 0) {
                        INt1t2.insert(p);
                        if (size == INt1t2.size()) {
                            B = false;
                            S.insert(t2);
                        } else size = INt1t2.size();
                    }
                    p++;
                }
				
                size = INt1.size();
                set<int> INt1t2Inhib = INt1;
                B = true;
                p = 0;
                while (B && p < MyGspn.pl) {
                    if (MyGspn.inhibArcs[t2][p] > 0) {
                        INt1t2Inhib.insert(p);
                        if (size == INt1t2Inhib.size()) {
                            B = false;
                            Sinhib.insert(t2);
                        } else size = INt1t2Inhib.size();
                    }
                    p++;
                }
				
            }
		
		
        PossiblyDisabled.push_back(S);
        PossiblyEnabled.push_back(Sinhib);
    }
    for (size_t t1 = 0; t1 < MyGspn.tr; t1++) {
        set<int> S = PossiblyEnabled[t1];
        set<int> Sinhib = PossiblyDisabled[t1];
        set<int> OUTt1;
        for (size_t p = 0; p < MyGspn.pl; p++)
            if (MyGspn.outArcs[t1][p] > 0)
                OUTt1.insert(p);
        for (size_t t2 = 0; t2 < MyGspn.tr; t2++)
            if (t1 != t2) {
                size_t size = OUTt1.size();
                set<int> OUTt1INt2 = OUTt1;
                bool B = true;
                size_t p = 0;
                while (B && p < MyGspn.pl) {
                    if (MyGspn.inArcs[t2][p] > 0) {
                        OUTt1INt2.insert(p);
                        if (size == OUTt1INt2.size()) {
                            B = false;
                            S.insert(t2);
                        } else size = OUTt1INt2.size();
                    }
                    p++;
                }
                size = OUTt1.size();
                set<int> OUTt1t2Inhib = OUTt1;
                B = true;
                p = 0;
                while (B && p < MyGspn.pl) {
                    if (MyGspn.inhibArcs[t2][p] > 0) {
                        OUTt1t2Inhib.insert(p);
                        if (size == OUTt1t2Inhib.size()) {
                            B = false;
                            Sinhib.insert(t2);
                        } else size = OUTt1t2Inhib.size();
                    }
                    p++;
                }
				
            }
        PossiblyEnabled[t1] = S;
        PossiblyDisabled[t1] = Sinhib;
    }
	
    set<int> MarkDepT;
    for (size_t t = 0; t < MyGspn.tr; t++)
        if (MyGspn.MarkingDependent[t])
            MarkDepT.insert(t);
	
    for (size_t t = 0; t < MyGspn.tr; t++) {
        set<int> S;
        for (set<int>::iterator it = MarkDepT.begin(); it != MarkDepT.end(); it++) {
            if ((PossiblyEnabled[t].find((*it)) == PossiblyEnabled[t].end()) &&
				(PossiblyDisabled[t].find((*it)) == PossiblyDisabled[t].end()))
                S.insert((*it));
        }
        FreeMarkDepT.push_back(S);
    }
}

void Gspn_Reader::writeMarkingClasse(ofstream &SpnCppFile,ofstream &header){
	
	SpnCppFile << "#include \"marking.hpp\"\n";
	SpnCppFile << "#include \"markingImpl.hpp\"\n";
	
	header << "class abstractMarkingImpl {\n";
	header << "public:\n";
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        header << "	int _PL_"<< *it << ";\n";
	}
	header << "	int LHALocation;\n";
	header << "};\n";
	SpnCppFile << "\n";
	SpnCppFile << "void abstractMarking::resetToInitMarking(){\n";
	SpnCppFile << "	P->LHALocation=0;\n";
	
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        SpnCppFile << "P->_PL_"<< *it << " =" <<
			MyGspn.Marking[MyGspn.PlacesId[*it]] << ";\n";
	}
	
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "\n";
	SpnCppFile << "abstractMarking::abstractMarking() {\n";
	SpnCppFile << "	P= new abstractMarkingImpl;\n";
	SpnCppFile << "	resetToInitMarking();\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "abstractMarking::abstractMarking(const std::vector<int>& m) {\n";
	SpnCppFile << "	P = new abstractMarkingImpl;\n";
	SpnCppFile << "	setVector(m);\n";
	SpnCppFile << "}\n";
	SpnCppFile << "abstractMarking::abstractMarking(const abstractMarking& m) {\n";
	SpnCppFile << "	P= new abstractMarkingImpl;\n";
	SpnCppFile << "	\n";
	SpnCppFile << "	*this = m;\n";
	SpnCppFile << "	\n";
	SpnCppFile << "};\n";
	SpnCppFile << "\n";
	SpnCppFile << "\n";
	SpnCppFile << "abstractMarking& abstractMarking::operator = (const abstractMarking& m) {\n";
	SpnCppFile << "	*P = *(m.P);\n";
	SpnCppFile << "	return *this;\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "abstractMarking::~abstractMarking() {\n";
	SpnCppFile << "	delete(P);\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "void abstractMarking::setLocation(int l){\n";
	SpnCppFile << "	P->LHALocation = l;\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "\n";
	SpnCppFile << "int abstractMarking::retriveLocation()const{\n";
	SpnCppFile << "	return P->LHALocation;\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "void abstractMarking::print()const{\n";
	SpnCppFile << "	std::cerr << \"Marking:\"<< std::endl;\n";
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
		SpnCppFile << "	std::cerr << \""<< *it <<": \" << P->_PL_"<< *it << " << std::endl;\n";
	}
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "int abstractMarking::getNbOfTokens(int p)const {\n";
	SpnCppFile << "	switch (p) {\n";
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
		SpnCppFile << "	case "<< MyGspn.PlacesId[*it] << ": return P->_PL_"<< *it << ";\n";
	}
	SpnCppFile << "	}\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "std::vector<int> abstractMarking::getVector()const {\n";
	SpnCppFile << "	std::vector<int> v("<<MyGspn.pl << ");\n";
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        SpnCppFile << "v[" << MyGspn.PlacesId[*it] <<"] = P->_PL_" << *it << ";\n";
	}
	SpnCppFile << "	return v;\n";
	SpnCppFile << "}\n";
	SpnCppFile << "\n";
	SpnCppFile << "void abstractMarking::setVector(const std::vector<int>&v) {\n";
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        SpnCppFile << "P->_PL_" << *it << " = v[" << MyGspn.PlacesId[*it] << "];\n";
	}
	SpnCppFile << "};";
}


void Gspn_Reader::WriteFile(parameters& P){
	
	vector<string> placeNames(MyGspn.pl);
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        int k = MyGspn.PlacesId[*it];
		placeNames[k] = *it;
    }

	
	
	string Pref = P.tmpPath;
    string loc;
	
    //loc = Pref + "../SOURCES/Cosmos/spn.cpp";
	loc = Pref + "/spn.cpp";
    //loc= "/Users/barbot/Documents/Cosmos/SOURCES/Cosmos/spn.cpp";
	ofstream SpnCppFile(loc.c_str(), ios::out | ios::trunc); // ouverture en écriture avec effacement du SpnCppFile ouvert
	//cout << loc << endl;
	string headerloc = Pref + "/markingImpl.hpp";
	ofstream header(headerloc.c_str(), ios::out | ios::trunc);
	
	
	SpnCppFile << "#include \"spn_orig.hpp\"" << endl;
	SpnCppFile << "#include \"spn.hpp\"" << endl;
	
	
	
	for (map<string,double>::iterator it= MyGspn.RealConstant.begin(); it!= MyGspn.RealConstant.end() ; it++) {
		SpnCppFile << "    const double " << it->first << "=" << it->second << ";" << endl;
	}
	for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        int k = MyGspn.PlacesId[*it];
		SpnCppFile << "    const int _nb_Place_"<< *it << "=" << k << ";" << endl;
    }
    
	SpnCppFile << "#include \"lumpingfun.cpp\"" << endl;
	SpnCppFile << "#include <iostream>" << endl;
	
	
	writeMarkingClasse(SpnCppFile,header);
	header.close();
	
    SpnCppFile << "SPN::SPN():" << endl;
	SpnCppFile << "\tSPN_ORIG(" << MyGspn.pl << ", ";
	SpnCppFile << MyGspn.tr << ") {" << endl;
    SpnCppFile << "    Path =\"" << MyGspn.Path << "\";" << endl;
	
    SpnCppFile << "    IntVector Null_Pl_Vector(pl, 0);" << endl;
	
	
    SpnCppFile << "    IntMatrix Null_PlxTr_Matrix(tr, Null_Pl_Vector);" << endl;
	
	
    SpnCppFile << "    inArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    outArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    inhibArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    Marking = Null_Pl_Vector;;" << endl;
    
	{
		for (size_t t = 0; t < MyGspn.tr; t++) {
			for (size_t p = 0; p < MyGspn.pl; p++)
				if (MyGspn.inArcs[t][p] > 0)
					SpnCppFile << "    inArcs[" << t << "][" << p << "]=" << MyGspn.inArcs[t][p] << ";" << endl;
			SpnCppFile << endl;
			
		}
		for (size_t t = 0; t < MyGspn.tr; t++) {
			for (size_t p = 0; p < MyGspn.pl; p++)
				if (MyGspn.outArcs[t][p] > 0)
					SpnCppFile << "    outArcs[" << t << "][" << p << "]=" << MyGspn.outArcs[t][p] << ";" << endl;
			SpnCppFile << endl;
			
		}
		for (size_t t = 0; t < MyGspn.tr; t++) {
			for (size_t p = 0; p < MyGspn.pl; p++)
				if (MyGspn.inhibArcs[t][p] > 0)
					SpnCppFile << "    inhibArcs[" << t << "][" << p << "]=" << MyGspn.inhibArcs[t][p] << ";" << endl;
			SpnCppFile << endl;
		}
	}
	
	SpnCppFile << "\tsetConditionsVector();"<< endl;
	SpnCppFile << "\tinitTransitionConditions = TransitionConditions;" << endl;
	
	
    SpnCppFile << "    vector <spn_trans> t(" << MyGspn.tr << ");" << endl;
	
    SpnCppFile << "    Transition = t;" << endl;
	
	
    SpnCppFile << "    vector <spn_place> p(" << MyGspn.pl << ");" << endl;
    SpnCppFile << "    Place = p;" << endl;
	
	
    for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        int k = MyGspn.PlacesId[*it];
        SpnCppFile << "    Place[" << k << "].Id =" << k << ";" << endl;
		if(P.StringInSpnLHA){
			SpnCppFile << "    Place[" << k << "].label =\" " << *it << "\";" << endl;
			SpnCppFile << "    PlaceIndex[\" " << *it << "\"] =" << k << ";" << endl;
		}
    }
	
    for (set<string>::iterator it = MyGspn.TransList.begin(); it != MyGspn.TransList.end(); it++) {
        int k = MyGspn.TransId[*it];
        SpnCppFile << "    Transition[" << k << "].Id =" << k << ";" << endl;
		if(P.StringInSpnLHA){
			SpnCppFile << "    Transition[" << k << "].label =\"" << *it << "\";" << endl;
			SpnCppFile << "    TransitionIndex[\"" << *it << "\"]=" << k << ";" << endl;
		}
    }
	
	
	
	
    for (size_t i = 0; i < MyGspn.tr; i++) {
		
        if (MyGspn.tType[i] == Timed) {
            SpnCppFile << "    Transition[" << i << "].transType = Timed;" << endl;
			
			SpnCppFile << "    Transition[" << i << "].DistTypeIndex = " << IndexDist[MyGspn.Dist[i].name] << ";" << endl;
			
			if(P.StringInSpnLHA){
				SpnCppFile << "    Transition[" << i << "].DistType = \"" << MyGspn.Dist[i].name << "\";" << endl;
				for (size_t j = 0; j < MyGspn.Dist[i].Param.size(); j++) {
					SpnCppFile << "    Transition[" << i << "].DistParams.push_back(\" " << MyGspn.Dist[i].Param[j] << "\" );" << endl;
				}
			}
			
        } else {
            SpnCppFile << "    Transition[" << i << "].transType = unTimed;" << endl;
			SpnCppFile << "    Transition[" << i << "].DistTypeIndex = 3;" << endl;
			
        }
        SpnCppFile << "    Transition[" << i << "].MarkingDependent = " << MyGspn.MarkingDependent[i] << ";" << endl;
		if(P.StringInSpnLHA){
			SpnCppFile << "    Transition[" << i << "].priority = \"" << MyGspn.Priority[i] << "\";" << endl;
			SpnCppFile << "    Transition[" << i << "].weight = \"" << MyGspn.Weight[i] << " \";" << endl;
		}
        SpnCppFile << endl;
    }
	
    /*SpnCppFile << "    vector < vector <int> > vec(" << MyGspn.tr << ");" << endl;
	 SpnCppFile << "    PredT = vec;" << endl;
	 for (size_t t = 0; t < MyGspn.tr; t++) {
	 for (size_t p = 0; p < MyGspn.pl; p++)
	 if (MyGspn.inArcs[t][p] > 0) SpnCppFile << "    PredT[" << t << "].push_back(" << p << ");" << endl;
	 
	 //SpnCppFile << endl;
	 
	 }*/
    SpnCppFile << "    EnabledDisabledTr();" << endl;
	
    //-------------- Rare Event -----------------
    SpnCppFile << "    Msimple();" << endl;
    SpnCppFile << "vector <double> Rate_Table_init (tr);" << endl;
    SpnCppFile << "Rate_Table = Rate_Table_init;" << endl;
    SpnCppFile << "Origine_Rate_Table = Rate_Table_init;" << endl;
    /*for(int i =0;i<MyGspn.tr;i++){
	 SpnCppFile << "Origine_Rate_Table["<<i<<"]= ( double ) " <<  MyGspn.Dist[i].Param[0] << ";" << endl;
	 };*/
    
    //------------- /Rare Event -----------------
	
    SpnCppFile << "}\n" << endl;
    
	
	
	
	
	
    SpnCppFile << "bool SPN::IsEnabled(const int t){" << endl;
	if(P.localTesting){
		SpnCppFile << "\treturn (TransitionConditions[t]==0);" << endl;
	} else {
		SpnCppFile << "    switch(t){" << endl;
		for (size_t t = 0; t < MyGspn.tr; t++) {
			SpnCppFile << "     case " << t << ":" << endl;
			for (size_t p = 0; p < MyGspn.pl; p++) {
				if (MyGspn.inArcs[t][p] > 0) {
					
					if (MyGspn.inArcsStr[t][p] == " ")
						SpnCppFile << "    if (Marking.P->_PL_" << placeNames[p] <<" < " << MyGspn.inArcs[t][p] << ") return false;" << endl;
					
					else {
						SpnCppFile << "    if ( " << MyGspn.inArcsStr[t][p] << "> 0) " << endl;
						SpnCppFile << "        if (Marking.P->_PL_" << placeNames[p] <<" < " << MyGspn.inArcsStr[t][p] << ") return false;" << endl;
					}
				}
				if (MyGspn.inhibArcs[t][p] > 0) {
					
					if (MyGspn.inhibArcsStr[t][p] == " ")
						SpnCppFile << "    if (Marking.P->_PL_" << placeNames[p] <<" >= " << MyGspn.inhibArcs[t][p] << ") return false;" << endl;
					
					else {
						SpnCppFile << "    if ( " << MyGspn.inhibArcsStr[t][p] << " > 0 ) " << endl;
						SpnCppFile << "        if (Marking.P->_PL_" << placeNames[p] <<" >= " << MyGspn.inhibArcsStr[t][p] << ") return false;" << endl;
						
					}
				}
			}
			SpnCppFile << "    return true;" << endl;
			//SpnCppFile << "       return IsEnabled_t" << i << "();" << endl;
			SpnCppFile << "       break;" << endl;
		}
		SpnCppFile << "   }" << endl;
    }
	SpnCppFile << "}\n" << endl;
	
	
    SpnCppFile << "void SPN::fire(int t){" << endl;
	SpnCppFile << "\tlastTransition = t;" << endl;
	if(P.localTesting){
		SpnCppFile << "\tnewlyEnabled.clear();"<< endl;
		SpnCppFile << "\tnewlyDisabled.clear();"<< endl;
	}
	SpnCppFile << "\tswitch(t){" << endl;
	for (size_t t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "\t\tcase " << t << ": {" << endl;
        //SpnCppFile << "       unfire_t" << t << "();" << endl;
        for (size_t p = 0; p < MyGspn.pl; p++) {
			if (MyGspn.inArcs[t][p] > 0) {
				if (MyGspn.inArcsStr[t][p] == " "){
					int decrement = MyGspn.inArcs[t][p];
					if(P.localTesting)for (size_t t2 = 0; t2 < MyGspn.tr; t2++) {
						if (MyGspn.inArcs[t2][p] > 0) {
							if (MyGspn.inArcsStr[t2][p] == " "){
								int seuil = MyGspn.inArcs[t2][p];
								if(seuil-decrement >0){
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil+decrement;
									SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
									SpnCppFile << "incrCondition("<< t2 <<");" << endl;
								} else
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil+decrement << ")incrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" >= "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" < " << seuil <<"+"<< decrement <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}
						}
						
						if (MyGspn.inhibArcs[t2][p] > 0) {
							if (MyGspn.inhibArcsStr[t2][p] == " "){
								int seuil = MyGspn.inhibArcs[t2][p];
								if(seuil-decrement >0){
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil+decrement;
									SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
									SpnCppFile << "decrCondition("<< t2 <<");" << endl;
								} else
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil+decrement << ")decrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inhibArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil <<"+"<< decrement;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}
						}
					}
					SpnCppFile << "\t\t\tMarking.P->_PL_" << placeNames[p] <<" -= " << decrement << ";"<< endl;
				} else {
					string decrement = MyGspn.inArcsStr[t][p];
					if(P.localTesting)for (size_t t2 = 0; t2 < MyGspn.tr; t2++) {
						if (MyGspn.inArcs[t2][p] > 0) {
							if (MyGspn.inArcsStr[t2][p] == " "){
								int seuil = MyGspn.inArcs[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil <<"+"<< decrement;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil <<"+" << decrement;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}
						}
						
						if (MyGspn.inhibArcs[t2][p] > 0) {
							if (MyGspn.inhibArcsStr[t2][p] == " "){
								int seuil = MyGspn.inhibArcs[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil <<"+"<<decrement;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inhibArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil << "+" <<decrement;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}
						}
					}
					SpnCppFile << "\t\t\tMarking.P->_PL_" << placeNames[p] <<" -= " << decrement << ";"<< endl;
				}
			}
			
			if (MyGspn.outArcs[t][p] > 0) {
				if (MyGspn.outArcsStr[t][p] == " "){
					int increment = MyGspn.outArcs[t][p];
					if(P.localTesting)for (size_t t2 = 0; t2 < MyGspn.tr; t2++) {
						if (MyGspn.inArcs[t2][p] > 0) {
							if (MyGspn.inArcsStr[t2][p] == " "){
								int seuil = MyGspn.inArcs[t2][p];
								if(seuil-increment >0){
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
									SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
									SpnCppFile << "decrCondition("<< t2 <<");" << endl;
								} else
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil << ")decrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}
						}
						
						if (MyGspn.inhibArcs[t2][p] > 0) {
							if (MyGspn.inhibArcsStr[t2][p] == " "){
								int seuil = MyGspn.inhibArcs[t2][p];
								if(seuil-increment >0){
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
									SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
									SpnCppFile << "incrCondition("<< t2 <<");" << endl;
								} else
									SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil << ")incrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inhibArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}
						}
					}
					SpnCppFile << "\t\t\tMarking.P->_PL_" << placeNames[p] <<" += " << increment << ";"<< endl;
				} else {
					string increment = MyGspn.outArcsStr[t][p];
					if(P.localTesting)for (size_t t2 = 0; t2 < MyGspn.tr; t2++) {
						if (MyGspn.inArcs[t2][p] > 0) {
							if (MyGspn.inArcsStr[t2][p] == " "){
								int seuil = MyGspn.inArcs[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "decrCondition("<< t2 <<");" << endl;
							}
						}
						
						if (MyGspn.inhibArcs[t2][p] > 0) {
							if (MyGspn.inhibArcsStr[t2][p] == " "){
								int seuil = MyGspn.inhibArcs[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}else {
								string seuil = MyGspn.inhibArcsStr[t2][p];
								SpnCppFile << "\t\t\tif(Marking.P->_PL_" << placeNames[p] <<" < "<< seuil;
								SpnCppFile << " && Marking.P->_PL_" << placeNames[p] <<"+"<<increment<<" >=" << seuil <<")";
								SpnCppFile << "incrCondition("<< t2 <<");" << endl;
							}
						}
					}
					SpnCppFile << "\t\t\tMarking.P->_PL_" << placeNames[p] <<" += " << increment << ";"<< endl;
				}
			}
		}
		//
		SpnCppFile << "       break;" << endl;
        SpnCppFile << "     } " << endl;
	}
	SpnCppFile << "\t}" << endl;
	SpnCppFile << "}" << endl;
	
	SpnCppFile << "void SPN::unfire(int t){" << endl;
    SpnCppFile << "   switch(t){" << endl;
    for (size_t t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "     case " << t << ": {" << endl;
        //SpnCppFile << "       unfire_t" << t << "();" << endl;
        for (size_t p = 0; p < MyGspn.pl; p++) {
			if (MyGspn.inArcs[t][p] > 0) {
				if (MyGspn.inArcsStr[t][p] == " ")
					SpnCppFile << "    Marking.P->_PL_" << placeNames[p] <<" += " << MyGspn.inArcs[t][p] << ";" << endl;
				else
					SpnCppFile << "    Marking.P->_PL_" << placeNames[p] <<" += " << MyGspn.inArcsStr[t][p] << ";" << endl;
			}
			
			if (MyGspn.outArcs[t][p] > 0) {
				if (MyGspn.outArcsStr[t][p] == " ")
					SpnCppFile << "    Marking.P->_PL_" << placeNames[p] <<" -= " << MyGspn.outArcs[t][p] << ";" << endl;
				else
					SpnCppFile << "    Marking.P->_PL_" << placeNames[p] <<" -= " << MyGspn.outArcsStr[t][p] << ";" << endl;
			}
		}
		//
		SpnCppFile << "       break;" << endl;
        SpnCppFile << "     } " << endl;
    }
	
    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;
	
	SpnCppFile << "const set<int>* SPN::PossiblyEn() {" << endl;
	if (P.localTesting)SpnCppFile << "\treturn &newlyEnabled;" << endl;
	else SpnCppFile << "\treturn &(PossiblyEnabled[lastTransition]);" << endl;
	SpnCppFile << "}" << endl;
	
	SpnCppFile << "const set<int>* SPN::PossiblyDis() {" << endl;
	if (P.localTesting)SpnCppFile << "\treturn &newlyDisabled;" << endl;
	else SpnCppFile << "\treturn &(PossiblyDisabled[lastTransition]);" << endl;
	SpnCppFile << "}" << endl;
	
	SpnCppFile << "const set<int>* SPN::FreeMarkingDependant() {" << endl;
	SpnCppFile << "\treturn &(FreeMarkDepT[lastTransition]);" << endl;
	SpnCppFile << "}" << endl;
	
	
	SpnCppFile << "void SPN::setConditionsVector(){" << endl;
	for (size_t t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "\tTransitionConditions["<< t <<"]=0;" << endl;
		for (size_t p = 0; p < MyGspn.pl; p++) {
            if (MyGspn.inArcs[t][p] > 0) {
				
                if (MyGspn.inArcsStr[t][p] == " ")
                    SpnCppFile << "\tif (Marking.P->_PL_" << placeNames[p] <<" < " << MyGspn.inArcs[t][p] << ")TransitionConditions["<< t <<"]++;" << endl;
				
                else {
                    SpnCppFile << "\tif ( " << MyGspn.inArcsStr[t][p] << "> 0) " << endl;
                    SpnCppFile << "\t\tif (Marking.P->_PL_" << placeNames[p] <<" < " << MyGspn.inArcsStr[t][p] << ")TransitionConditions["<< t <<"]++;" << endl;
                }
            }
            if (MyGspn.inhibArcs[t][p] > 0) {
				
                if (MyGspn.inhibArcsStr[t][p] == " ")
                    SpnCppFile << "\tif (Marking.P->_PL_" << placeNames[p] <<" >= " << MyGspn.inhibArcs[t][p] << ")TransitionConditions["<< t <<"]++;" << endl;
				
                else {
                    SpnCppFile << "\tif ( " << MyGspn.inhibArcsStr[t][p] << " > 0 ) " << endl;
                    SpnCppFile << "\t\tif (Marking.P->_PL_" << placeNames[p] <<" >= " << MyGspn.inhibArcsStr[t][p] << ")TransitionConditions["<< t <<"]++;" << endl;
					
                }
            }
        }
	}
	
	SpnCppFile << "}" << endl;
    
    SpnCppFile << "void SPN::GetDistParameters(int t){" << endl;
    //-------------- /Rare Event -------------------------
    SpnCppFile << "   switch(t){" << endl;
    for (size_t t = 0; t < MyGspn.tr; t++) {
		if (MyGspn.tType[t] == Timed) {
			SpnCppFile << "     case " << t << ": {" << endl;
			//SpnCppFile << "       vector<double> P(" << MyGspn.Dist[t].Param.size() << ");" << endl;
			if (MyGspn.SingleService[t])
				for (size_t i = 0; i < MyGspn.Dist[t].Param.size(); i++) {
					
					SpnCppFile << "       ParamDistr[" << i << "]= ( double ) " << MyGspn.Dist[t].Param[i] << ";" << endl;
				} else {
					SpnCppFile << "       double EnablingDegree = INT_MAX; " << endl;
					bool AtLeastOneMarkDepArc = false;
					for (size_t p = 0; p < MyGspn.pl; p++)
						if (MyGspn.inArcs[t][p] > 0) {
							if (MyGspn.inArcsStr[t][p] == " ")
								SpnCppFile << "       EnablingDegree=min(floor(Marking.P->_PL_" << placeNames[p] <<"/(double)(" << MyGspn.inArcs[t][p] << ")),EnablingDegree);" << endl;
							else {
								AtLeastOneMarkDepArc = true;
								SpnCppFile << "       if(" << MyGspn.inArcsStr[t][p] << ">0)" << endl;
								SpnCppFile << "              EnablingDegree=min(floor(Marking.P->_PL_" << placeNames[p] <<"/(double)(" << MyGspn.inArcsStr[t][p] << ")),EnablingDegree);" << endl;
							}
							
						}
					if (AtLeastOneMarkDepArc) {
						if (MyGspn.NbServers[t] >= INT_MAX) {
							SpnCppFile << "       if(EnablingDegree < INT_MAX ) ParamDistr[0] = EnablingDegree * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
							SpnCppFile << "       else ParamDistr[0] = " << MyGspn.Dist[t].Param[0] << " ;" << endl;
						} else {
							SpnCppFile << "       if(EnablingDegree < INT_MAX ) P[0] = min(EnablingDegree , " << MyGspn.NbServers[t] << " ) * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
							SpnCppFile << "       else ParamDistr[0] = " << MyGspn.Dist[t].Param[0] << " ;" << endl;
						}
					} else {
						if (MyGspn.NbServers[t] >= INT_MAX)
							SpnCppFile << "        ParamDistr[0] = EnablingDegree  * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
						else
							SpnCppFile << "        ParamDistr[0] = min(EnablingDegree , " << MyGspn.NbServers[t] << " ) * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
					}
				}
			//SpnCppFile << "       return P;" << endl;
			SpnCppFile << "       break;" << endl;
			SpnCppFile << "     }" << endl;
		}
    }
    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;
	
	
	/////////////////////////////////////////
	
	SpnCppFile << "double SPN::GetPriority(int t){" << endl;
	SpnCppFile << "   switch(t){" << endl;
	for (size_t t = 0; t < MyGspn.tr; t++) {
		
		SpnCppFile << "     case " << t << ": {" << endl;
		
		SpnCppFile << "       return (double)" << MyGspn.Priority[t] << ";" << endl;
		SpnCppFile << "       break;" << endl;
		SpnCppFile << "     } " << endl;
		
	}
	SpnCppFile << "   }" << endl;
	SpnCppFile << "}\n" << endl;
	
	
	/////////////////////////////////////////
	SpnCppFile << "double SPN::GetWeight(int t){" << endl;
	SpnCppFile << "   switch(t){" << endl;
	for (size_t t = 0; t < MyGspn.tr; t++) {
		
        SpnCppFile << "     case " << t << ":" << endl;
		
        SpnCppFile << "       return (double)" << MyGspn.Weight[t] << ";" << endl;
        SpnCppFile << "       break;" << endl;
		
    }
	
	
    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;
	
	
    SpnCppFile.close();
	
}
