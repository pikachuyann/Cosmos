#ifndef _SPN_HPP
#define	_SPN_HPP
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include "tab.hpp"
using namespace std;

enum TransType {
    Timed, unTimed
};

struct _trans {
    unsigned int Id;
    string label;
    TransType transType; // Time or unTimed
    string DistType;
    vector<string> DistParams;
    string priority;
    string weight;
    bool MarkingDependent;
};
typedef struct _trans spn_trans;

struct _place {
    unsigned int Id;
    string label;
};
typedef struct _place spn_place;

typedef vector <int> Dim1;
typedef vector <int> IntVector;
typedef vector <Dim1> Dim2;
typedef vector <IntVector> IntMatrix;

class SPN {
public:

    // Modification evenements rares.
  vector <double> Rate_Table;
  vector <double> Origine_Rate_Table;
  double Rate_Sum;
  double Origine_Rate_Sum;
  TAB gammaprob;
  

    SPN();
    void Load();
    SPN(const SPN& orig);
    virtual ~SPN();
    string Path;
    int pl; // Number of places
    int tr; // Number of transitions
    set<int, less<int> > enTrans; // the set of current enabled transition
    IntMatrix* PossiblyEnabled; //a matrix, where a row t of PossiblyEnabled refers to transitions that may be enabled after firing t
    IntMatrix* PossiblyDisabled; //a matrix, where a row t of PossiblyDisabled refers to transitions that may be disabled after firing t

    vector <int> Marking; // Current marking
    vector <int> initMarking; //initial marking
    IntMatrix inArcs; // input arcs
    IntMatrix outArcs; //output arcs
    IntMatrix inhibArcs; // inhibitor arcs

    vector <spn_trans> Transition; //contains all the transitions of the Petri net
    vector <spn_place> Place; //contains all the places of the Petri net
    vector < vector<int> > PredT; // to be deleted

    map <string, int> PlaceIndex; // for a given place label return its index among {0, 1, ..., pl-1}
    map <string, int> TransitionIndex; // for a given transition label return its index among {0, 1, ..., tr-1}

    //  map <int, string> PlaceLabel;// for a given place index return its label
    //  map <int, string> TransitionLabel;// for a given transition index return its label



    double min(double, double); //return the minimum of two numbers
    double max(double, double); //return the maximum of two numbers




    vector<int> getMarking(); //return  the current marking

    set<int, less <int> > enabledTrans(); // return the set of enabled transitions


    void EnabledDisabledTr(); // contruct for each transition t, the vector of transitions that may be enabled (PossiblyEnabled) and the vector of transitions that may be disabled (PossiblyDisabled) after firing t
    Dim1 PossiblyEn(int); // for a given transition t, return the vector of transitions that may be enabled after firing t  (it is the row t of PossiblyEnabled)
    Dim1 PossiblyDis(int); // for a given transition t, return the vector of transitions that may be disabled after firing t  (it is the row t of PossiblyDisabled)


    void reset(); // set the marking to the initial marking
    void setMarking(vector<int>&); // set the marking to a given marking



    void fire(int); // fire a given transition
    bool IsEnabled(int); // Check if a given transition is enabled
    vector<double> GetDistParameters(int); // compute the the parameters value of a given distribution 
   //------------ Rare Event ---------------------
  vector<double> GetDistParametersOrigin(int);
  //------------ /Rare Event -------------------

    double GetWeight(int); // compute the the weight value of a given transition
    double GetPriority(int); // compute the the priority value of a given transition


    //private:
    //};
    //#endif	/* _SPN_HPP */

    void fire_t0();
    bool IsEnabled_t0();
    void fire_t1();
    bool IsEnabled_t1();
    void fire_t2();
    bool IsEnabled_t2();
    void fire_t3();
    bool IsEnabled_t3();
    void fire_t4();
    bool IsEnabled_t4();
    void fire_t5();
    bool IsEnabled_t5();
    void fire_t6();
    bool IsEnabled_t6();
    void fire_t7();
    bool IsEnabled_t7();
    void fire_t8();
    bool IsEnabled_t8();
    void fire_t9();
    bool IsEnabled_t9();
    void fire_t10();
    bool IsEnabled_t10();
    void fire_t11();
    bool IsEnabled_t11();
    void fire_t12();
    bool IsEnabled_t12();
    void fire_t13();
    bool IsEnabled_t13();
    void fire_t14();
    bool IsEnabled_t14();
    void fire_t15();
    bool IsEnabled_t15();
    void fire_t16();
    bool IsEnabled_t16();
    void fire_t17();
    bool IsEnabled_t17();
    void fire_t18();
    bool IsEnabled_t18();
    void fire_t19();
    bool IsEnabled_t19();
    void fire_t20();
    bool IsEnabled_t20();
    void fire_t21();
    bool IsEnabled_t21();
    void fire_t22();
    bool IsEnabled_t22();
    void fire_t23();
    bool IsEnabled_t23();
    void fire_t24();
    bool IsEnabled_t24();
    void fire_t25();
    bool IsEnabled_t25();
    void fire_t26();
    bool IsEnabled_t26();
    void fire_t27();
    bool IsEnabled_t27();
    void fire_t28();
    bool IsEnabled_t28();
    void fire_t29();
    bool IsEnabled_t29();
    void fire_t30();
    bool IsEnabled_t30();
    void fire_t31();
    bool IsEnabled_t31();
    void fire_t32();
    bool IsEnabled_t32();
    void fire_t33();
    bool IsEnabled_t33();
    void fire_t34();
    bool IsEnabled_t34();
    void fire_t35();
    bool IsEnabled_t35();
    void fire_t36();
    bool IsEnabled_t36();
    void fire_t37();
    bool IsEnabled_t37();
    void fire_t38();
    bool IsEnabled_t38();
    void fire_t39();
    bool IsEnabled_t39();
    void fire_t40();
    bool IsEnabled_t40();
    void fire_t41();
    bool IsEnabled_t41();
    void fire_t42();
    bool IsEnabled_t42();
    void fire_t43();
    bool IsEnabled_t43();
    void fire_t44();
    bool IsEnabled_t44();
    void fire_t45();
    bool IsEnabled_t45();
private:
};
#endif	/* _SPN_HPP */
