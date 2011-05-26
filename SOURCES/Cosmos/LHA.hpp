#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>

#include "spn.hpp"

#include <stdlib.h>

#ifndef _LHA_HPP
#define	_LHA_HPP


typedef pair <double, double> t_interval;

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

struct _AutEdge {
    int Index;
    double FiringTime;

};
typedef struct _AutEdge AutEdge;

class LHA {
public:
  LHA();
  void Load();
  LHA(unsigned int, unsigned int);
  LHA(const LHA& orig);
  virtual ~LHA();
  double Likelihood;
  string label;
  unsigned int NbLoc; // number of locations   
  unsigned int StartingLoc; // Chosen from the set of lha initial locations according to their properties and Petri net initial marking
  
  set <int> InitLoc; // initial locations
  set <int> FinalLoc; // final locations
  
  double CurrentTime;
  int CurrentLocation;
  
  map <string, int> LocIndex; //for a given Location label returns its index among {0, 1, ..., NLoc-1}
  vector <string> LocLabel;
  
  vector <string> StrLocProperty;
  
  
  
  map<string, int> EdgeIndex;
  vector <LhaEdge> Edge;
  vector < set <int> > Out_S_Edges; // for a given location l returns the set of synchronizing edges  starting from l
  vector < set <int> > Out_A_Edges; // for a given location l returns the set of autonomous edges  starting from l   
  vector < vector < set <int> > > ActionEdges; // ActionEdges[a][e]={t1, t2, ...} 
  
  vector <string> EdgeConstraints;
  vector < set<string> > EdgeActions;
  vector <string> StrEdgeUpdates;
  
  vector < vector <vector <string> > > ConstraintsCoeffs;
  vector < vector <string> > ConstraintsRelOp;
  vector < vector <string> > ConstraintsConstants;
  



    int NbVar;
    vector <double> Var; // Var[i] value of the variable indexed by i
    vector <double> OldVar;
    map<string, int> VarIndex; //for a given variable label return its index among {0, 1, ..., NbVar-1}
    vector <string> VarLabel;


    vector < vector <string> > StrFlow;



    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}






    int EnabledInitLocation(vector<int>&);

    double GetFlow(int, int, vector<int>&);
    bool CheckLocation(int, vector<int>&);
    bool CheckEdgeContraints(int, double, vector<int>&);

    t_interval GetEdgeEnablingTime(int, vector<int>&);


    int GetEnabled_S_Edges(int, int, double, vector<int>&, vector<int>&);
    AutEdge GetEnabled_A_Edges(unsigned int, vector<int>&);


    void DoElapsedTimeUpdate(double, vector<int>&);

    void setCurrentLocation(unsigned int);

    void DoEdgeUpdates(int, vector<int>&);
    void doPathVarsUpdate(double, double, vector<int>&);






    bool isFinal(unsigned int);
    void resetVarsTable();
    void resetPathVarsTable();
    void reset(vector<int>&);

    void ViewEdge(int);
    void ViewAllEdges();





    bool isVar(string, double &);

    double min(double&, double&);
    double max(double&, double&);

    double Min(double&, double&, double&);
    double Max(double&, double&, double&);
    double Integral(double&, double&, double&, double&, double&);

    vector<double> LinForm;
    vector<double> OldLinForm;
    vector<double> LhaFunc;
    double FormulaVal;
    double OldFormulaVal;
    void UpdateFormulaVal();
    void UpdateLinForm(vector<int>&);
    void UpdateLhaFunc(double&, double&);








    //private:

    //};

    //#endif	/* _LHA_HPP */


t_interval GetEdgeEnablingTime_0(vector<int>& );
t_interval GetEdgeEnablingTime_1(vector<int>& );
t_interval GetEdgeEnablingTime_2(vector<int>& );
t_interval GetEdgeEnablingTime_3(vector<int>& );
t_interval GetEdgeEnablingTime_4(vector<int>& );
t_interval GetEdgeEnablingTime_5(vector<int>& );
t_interval GetEdgeEnablingTime_6(vector<int>& );
t_interval GetEdgeEnablingTime_7(vector<int>& );
void DoEdgeUpdates_0(vector<int>& );
void DoEdgeUpdates_1(vector<int>& );
void DoEdgeUpdates_2(vector<int>& );
void DoEdgeUpdates_3(vector<int>& );
void DoEdgeUpdates_4(vector<int>& );
void DoEdgeUpdates_5(vector<int>& );
void DoEdgeUpdates_6(vector<int>& );
void DoEdgeUpdates_7(vector<int>& );
private:
};
#endif	/* _Lha_HPP */
