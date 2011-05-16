#include "lex.gspn.c"

#include "Gspn-parser.tab.hh"
#include "Gspn-Reader.hpp"

#include "string.h"

#include <string>
#include <sstream>
#include <fstream>
#include <set>




using namespace std;

Gspn_Reader::Gspn_Reader() {
    trace_scanning = false;
    trace_parsing = false;

}

Gspn_Reader::~Gspn_Reader() {
}

int Gspn_Reader::parse(string& expr) {




    IndexDist["UNIFORM"] = 1;
    IndexDist["EXPONENTIAL"] = 2;
    IndexDist["DETERMINISTIC"] = 3;
    IndexDist["LOGNORMAL"] = 4;
    IndexDist["TRIANGLE"] = 5;
    IndexDist["GEOMETRIC"] = 6;

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
        filename.append(".mod");
        ifstream Modfile(filename.c_str(), ios::in);
        if (Modfile) {

            while (!Modfile.eof()) {

                string str2;
                getline(Modfile, str2);
                str = str + "\n" + str2;
            }

        }
        int x = parse(str);

        if (x) cout << "Parsing GSPN Description file failed" << endl;

        return x;
    } else {
        cout << "Can't open : " << filename << endl;
        return 1;
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

void Gspn_Reader::WriteFile(string& Pref) {


    string loc;

    loc = Pref + "../SOURCES/Cosmos/spn.cpp";
    ofstream SpnCppFile(loc.c_str(), ios::out | ios::trunc); // ouverture en écriture avec effacement du SpnCppFile ouvert


    loc = Pref + "../SOURCES/ModelGenerator/spn_orig.cpp";
    ifstream SpnCppFile_orig(loc.c_str(), ios::in);







    while (!SpnCppFile_orig.eof()) {
        string LineFile;
        getline(SpnCppFile_orig, LineFile);
        SpnCppFile << LineFile << endl;
    }
    SpnCppFile_orig.close();

    SpnCppFile << "void SPN::Load(){" << endl;
    SpnCppFile << "    Path =\"" << MyGspn.Path << "\";" << endl;

    //-------------- Rare Event -----------------
    SpnCppFile << "    gammaprob.load();" << endl;
    //------------- /Rare Event -----------------

    SpnCppFile << "    pl =" << MyGspn.pl << ";" << endl;

    SpnCppFile << "    tr =" << MyGspn.tr << ";" << endl;

    SpnCppFile << "    IntVector Null_Pl_Vector(pl, 0);" << endl;


    SpnCppFile << "    IntMatrix Null_PlxTr_Matrix(tr, Null_Pl_Vector);" << endl;


    SpnCppFile << "    inArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    outArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    inhibArcs = Null_PlxTr_Matrix;" << endl;
    SpnCppFile << "    Marking = Null_Pl_Vector;;" << endl;
    for (int t = 0; t < MyGspn.tr; t++) {
        for (int p = 0; p < MyGspn.pl; p++)

            if (MyGspn.inArcs[t][p] > 0)
                SpnCppFile << "    inArcs[" << t << "][" << p << "]=" << MyGspn.inArcs[t][p] << ";" << endl;
        SpnCppFile << endl;

    }

    for (int t = 0; t < MyGspn.tr; t++) {
        for (int p = 0; p < MyGspn.pl; p++)
            if (MyGspn.outArcs[t][p] > 0)
                SpnCppFile << "    outArcs[" << t << "][" << p << "]=" << MyGspn.outArcs[t][p] << ";" << endl;
        SpnCppFile << endl;

    }

    for (int t = 0; t < MyGspn.tr; t++) {
        for (int p = 0; p < MyGspn.pl; p++)

            if (MyGspn.inhibArcs[t][p] > 0)
                SpnCppFile << "    inhibArcs[" << t << "][" << p << "]=" << MyGspn.inhibArcs[t][p] << ";" << endl;
        SpnCppFile << endl;

    }

    for (int p = 0; p < MyGspn.pl; p++) {
        if (MyGspn.Marking[p] > 0)
            SpnCppFile << "    Marking[" << p << "]=" << MyGspn.Marking[p] << ";" << endl;
    }
    SpnCppFile << "\n   initMarking = Marking;\n" << endl;




    SpnCppFile << "    vector <spn_trans> t(" << MyGspn.tr << ");" << endl;

    SpnCppFile << "    Transition = t;" << endl;


    SpnCppFile << "    vector <spn_place> p(" << MyGspn.pl << ");" << endl;
    SpnCppFile << "    Place = p;" << endl;


    for (set<string>::iterator it = MyGspn.PlacesList.begin(); it != MyGspn.PlacesList.end(); it++) {
        int k = MyGspn.PlacesId[*it];
        SpnCppFile << "    Place[" << k << "].Id =" << k << ";" << endl;
        SpnCppFile << "    Place[" << k << "].label =\" " << *it << "\";" << endl;
        SpnCppFile << "    PlaceIndex[\" " << *it << "\"] =" << k << ";" << endl;

    }

    for (set<string>::iterator it = MyGspn.TransList.begin(); it != MyGspn.TransList.end(); it++) {
        int k = MyGspn.TransId[*it];
        SpnCppFile << "    Transition[" << k << "].Id =" << k << ";" << endl;
        SpnCppFile << "    Transition[" << k << "].label =\"" << *it << "\";" << endl;
        SpnCppFile << "    TransitionIndex[\"" << *it << "\"]=" << k << ";" << endl;

    }




    for (int i = 0; i < MyGspn.tr; i++) {

        if (MyGspn.tType[i] == Timed) {
            SpnCppFile << "    Transition[" << i << "].transType = Timed;" << endl;
            SpnCppFile << "    Transition[" << i << "].DistType = \"" << MyGspn.Dist[i].name << "\";" << endl;

            for (int j = 0; j < MyGspn.Dist[i].Param.size(); j++) {
                SpnCppFile << "    Transition[" << i << "].DistParams.push_back(\" " << MyGspn.Dist[i].Param[j] << "\" );" << endl;
            }

        } else {
            SpnCppFile << "    Transition[" << i << "].transType = unTimed;" << endl;


        }
        SpnCppFile << "    Transition[" << i << "].priority = \"" << MyGspn.Priority[i] << "\";" << endl;
        SpnCppFile << "    Transition[" << i << "].MarkingDependent = " << MyGspn.MarkingDependent[i] << ";" << endl;
        SpnCppFile << "    Transition[" << i << "].weight = \"" << MyGspn.Weight[i] << " \";" << endl;
        SpnCppFile << endl;
    }

    SpnCppFile << "    vector < vector <int> > vec(" << MyGspn.tr << ");" << endl;
    SpnCppFile << "    PredT = vec;" << endl;
    for (int t = 0; t < MyGspn.tr; t++) {
        for (int p = 0; p < MyGspn.pl; p++)
            if (MyGspn.inArcs[t][p] > 0) SpnCppFile << "    PredT[" << t << "].push_back(" << p << ");" << endl;

        //SpnCppFile << endl;

    }
    SpnCppFile << "    EnabledDisabledTr();" << endl;

    //-------------- Rare Event -----------------

    SpnCppFile << "vector <double> Rate_Table_init (tr);" << endl;
    SpnCppFile << "Rate_Table = Rate_Table_init;" << endl;
    SpnCppFile << "Origine_Rate_Table = Rate_Table_init;" << endl;
    for(int i =0;i<MyGspn.tr;i++){
      SpnCppFile << "Origine_Rate_Table["<<i<<"]= ( double ) " <<  MyGspn.Dist[i].Param[0] << ";" << endl;
    };
    
    //------------- /Rare Event ----------------- 

    SpnCppFile << "}\n" << endl;
    





    SpnCppFile << "bool SPN::IsEnabled(int t){" << endl;
    SpnCppFile << "    switch(t){" << endl;
    for (int i = 0; i < MyGspn.tr; i++) {
        SpnCppFile << "     case " << i << ":" << endl;
        SpnCppFile << "       return IsEnabled_t" << i << "();" << endl;
        SpnCppFile << "       break;" << endl;
    }


    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;

    for (int t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "bool SPN::IsEnabled_t" << t << "() {" << endl;
        for (int p = 0; p < MyGspn.pl; p++) {
            if (MyGspn.inArcs[t][p] > 0) {

                if (MyGspn.inArcsStr[t][p] == " ")
                    SpnCppFile << "    if (Marking[" << p << "] < " << MyGspn.inArcs[t][p] << ") return false;" << endl;

                else {
                    SpnCppFile << "    if ( " << MyGspn.inArcsStr[t][p] << "> 0) " << endl;
                    SpnCppFile << "        if (Marking[" << p << "] < " << MyGspn.inArcsStr[t][p] << ") return false;" << endl;
                }
            }
            if (MyGspn.inhibArcs[t][p] > 0) {

                if (MyGspn.inhibArcsStr[t][p] == " ")
                    SpnCppFile << "    if (Marking[" << p << "] >= " << MyGspn.inhibArcs[t][p] << ") return false;" << endl;

                else {
                    SpnCppFile << "    if ( " << MyGspn.inhibArcsStr[t][p] << " > 0 ) " << endl;
                    SpnCppFile << "        if (Marking[" << p << "] >= " << MyGspn.inhibArcsStr[t][p] << ") return false;" << endl;

                }
            }
        }
        SpnCppFile << "    return true;" << endl;
        SpnCppFile << "}\n" << endl;

    }



    SpnCppFile << "void SPN::fire(int t){" << endl;
    SpnCppFile << "   switch(t){" << endl;
    for (int t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "     case " << t << ": {" << endl;
        SpnCppFile << "       fire_t" << t << "();" << endl;
        SpnCppFile << "       break;" << endl;
        SpnCppFile << "     } " << endl;
    }


    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;

    for (int t = 0; t < MyGspn.tr; t++) {
        SpnCppFile << "void SPN::fire_t" << t << "() {" << endl;
        for (int p = 0; p < MyGspn.pl; p++) {
            if (MyGspn.inArcs[t][p] > 0) {
                if (MyGspn.inArcsStr[t][p] == " ")
                    SpnCppFile << "    Marking[" << p << "] -= " << MyGspn.inArcs[t][p] << ";" << endl;
                else
                    SpnCppFile << "    Marking[" << p << "] -= " << MyGspn.inArcsStr[t][p] << ";" << endl;
            }

            if (MyGspn.outArcs[t][p] > 0) {
                if (MyGspn.outArcsStr[t][p] == " ")
                    SpnCppFile << "    Marking[" << p << "] += " << MyGspn.outArcs[t][p] << ";" << endl;
                else
                    SpnCppFile << "    Marking[" << p << "] += " << MyGspn.outArcsStr[t][p] << ";" << endl;

            }
        }


        SpnCppFile << "}\n" << endl;
	
    }
    
    //-------------- Rare Event -------------------------
    SpnCppFile << "vector<double> SPN::GetDistParameters(int t){"<< endl;
    SpnCppFile << "   vector<double> P(1);" << endl;
    SpnCppFile << "   double origin_rate = (SPN::GetDistParametersOrigin(t))[0];"<< endl;
    SpnCppFile << "   P[0]= ComputeDistr(Marking,t,gammaprob,origin_rate,Origine_Rate_Sum);" << endl;
    SpnCppFile << "   return P;" << endl;
    SpnCppFile << "}\n " << endl;
    
    
    SpnCppFile << "vector<double> SPN::GetDistParametersOrigin(int t){" << endl;
    //-------------- /Rare Event -------------------------
    SpnCppFile << "   switch(t){" << endl;
    for (int t = 0; t < MyGspn.tr; t++) {
      if (MyGspn.tType[t] == Timed) {
	SpnCppFile << "     case " << t << ": {" << endl;
	SpnCppFile << "       vector<double> P(" << MyGspn.Dist[t].Param.size() << ");" << endl;
	if (MyGspn.SingleService[t])
	  for (int i = 0; i < MyGspn.Dist[t].Param.size(); i++) {
	    
	    SpnCppFile << "       P[" << i << "]= ( double ) " << MyGspn.Dist[t].Param[i] << ";" << endl;
	  } else {
	  SpnCppFile << "       double EnablingDegree = INT_MAX; " << endl;
	  bool AtLeastOneMarkDepArc = false;
	  for (int p = 0; p < MyGspn.pl; p++)
	    if (MyGspn.inArcs[t][p] > 0) {
	      if (MyGspn.inArcsStr[t][p] == " ")
		SpnCppFile << "       EnablingDegree=min(floor(Marking[" << p << "]/(double)(" << MyGspn.inArcs[t][p] << ")),EnablingDegree);" << endl;
	      else {
		AtLeastOneMarkDepArc = true;
		SpnCppFile << "       if(" << MyGspn.inArcsStr[t][p] << ">0)" << endl;
		SpnCppFile << "              EnablingDegree=min(floor(Marking[" << p << "]/(double)(" << MyGspn.inArcsStr[t][p] << ")),EnablingDegree);" << endl;
	      }
	      
	    }
	  if (AtLeastOneMarkDepArc) {
	    if (MyGspn.NbServers[t] >= INT_MAX) {
	      SpnCppFile << "       if(EnablingDegree < INT_MAX ) P[0] = EnablingDegree * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
	      SpnCppFile << "       else P[0] = " << MyGspn.Dist[t].Param[0] << " ;" << endl;
	    } else {
	      SpnCppFile << "       if(EnablingDegree < INT_MAX ) P[0] = min(EnablingDegree , " << MyGspn.NbServers[t] << " ) * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
	      SpnCppFile << "       else P[0] = " << MyGspn.Dist[t].Param[0] << " ;" << endl;
	    }
	  } else {
	    if (MyGspn.NbServers[t] >= INT_MAX)
	      SpnCppFile << "        P[0] = EnablingDegree  * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
	    else
	      SpnCppFile << "        P[0] = min(EnablingDegree , " << MyGspn.NbServers[t] << " ) * ( " << MyGspn.Dist[t].Param[0] << " );" << endl;
	  }
	}
	SpnCppFile << "       return P;" << endl;
	SpnCppFile << "       break;" << endl;
	SpnCppFile << "     }" << endl;
      }
    }
    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;


/////////////////////////////////////////

SpnCppFile << "double SPN::GetPriority(int t){" << endl;
SpnCppFile << "   switch(t){" << endl;
for (int t = 0; t < MyGspn.tr; t++) {
  
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
for (int t = 0; t < MyGspn.tr; t++) {
  
        SpnCppFile << "     case " << t << ":" << endl;

        SpnCppFile << "       return (double)" << MyGspn.Weight[t] << ";" << endl;
        SpnCppFile << "       break;" << endl;

    }


    SpnCppFile << "   }" << endl;
    SpnCppFile << "}\n" << endl;


    SpnCppFile.close();


    loc = Pref + "../SOURCES/Cosmos/spn.hpp";
    ofstream SpnHppFile(loc.c_str(), ios::out | ios::trunc);

    loc = Pref + "../SOURCES/ModelGenerator/spn_orig.hpp";
    ifstream SpnHppFile_orig(loc.c_str(), ios::in);




    while (!SpnHppFile_orig.eof()) {
        string LineFile;
        getline(SpnHppFile_orig, LineFile);
        SpnHppFile << LineFile << endl;
    }

    SpnHppFile_orig.close();

    for (int t = 0; t < MyGspn.tr; t++) {

        SpnHppFile << "    void fire_t" << t << "();" << endl;
        SpnHppFile << "    bool IsEnabled_t" << t << "();" << endl;
    }





    SpnHppFile << "private:" << endl;

    SpnHppFile << "};" << endl;



    SpnHppFile << "#endif	/* _SPN_HPP */" << endl;

    SpnHppFile.close();



}
