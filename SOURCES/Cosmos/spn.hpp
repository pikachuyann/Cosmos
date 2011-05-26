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
    void unfire(int); // unfire a given transition
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
    void unfire_t0();
    bool IsEnabled_t0();
    void fire_t1();
    void unfire_t1();
    bool IsEnabled_t1();
    void fire_t2();
    void unfire_t2();
    bool IsEnabled_t2();
    void fire_t3();
    void unfire_t3();
    bool IsEnabled_t3();
    void fire_t4();
    void unfire_t4();
    bool IsEnabled_t4();
    void fire_t5();
    void unfire_t5();
    bool IsEnabled_t5();
    void fire_t6();
    void unfire_t6();
    bool IsEnabled_t6();
    void fire_t7();
    void unfire_t7();
    bool IsEnabled_t7();
    void fire_t8();
    void unfire_t8();
    bool IsEnabled_t8();
    void fire_t9();
    void unfire_t9();
    bool IsEnabled_t9();
    void fire_t10();
    void unfire_t10();
    bool IsEnabled_t10();
    void fire_t11();
    void unfire_t11();
    bool IsEnabled_t11();
    void fire_t12();
    void unfire_t12();
    bool IsEnabled_t12();
    void fire_t13();
    void unfire_t13();
    bool IsEnabled_t13();
    void fire_t14();
    void unfire_t14();
    bool IsEnabled_t14();
    void fire_t15();
    void unfire_t15();
    bool IsEnabled_t15();
    void fire_t16();
    void unfire_t16();
    bool IsEnabled_t16();
    void fire_t17();
    void unfire_t17();
    bool IsEnabled_t17();
    void fire_t18();
    void unfire_t18();
    bool IsEnabled_t18();
    void fire_t19();
    void unfire_t19();
    bool IsEnabled_t19();
    void fire_t20();
    void unfire_t20();
    bool IsEnabled_t20();
    void fire_t21();
    void unfire_t21();
    bool IsEnabled_t21();
    void fire_t22();
    void unfire_t22();
    bool IsEnabled_t22();
    void fire_t23();
    void unfire_t23();
    bool IsEnabled_t23();
    void fire_t24();
    void unfire_t24();
    bool IsEnabled_t24();
    void fire_t25();
    void unfire_t25();
    bool IsEnabled_t25();
    void fire_t26();
    void unfire_t26();
    bool IsEnabled_t26();
    void fire_t27();
    void unfire_t27();
    bool IsEnabled_t27();
    void fire_t28();
    void unfire_t28();
    bool IsEnabled_t28();
    void fire_t29();
    void unfire_t29();
    bool IsEnabled_t29();
    void fire_t30();
    void unfire_t30();
    bool IsEnabled_t30();
    void fire_t31();
    void unfire_t31();
    bool IsEnabled_t31();
    void fire_t32();
    void unfire_t32();
    bool IsEnabled_t32();
    void fire_t33();
    void unfire_t33();
    bool IsEnabled_t33();
    void fire_t34();
    void unfire_t34();
    bool IsEnabled_t34();
    void fire_t35();
    void unfire_t35();
    bool IsEnabled_t35();
    void fire_t36();
    void unfire_t36();
    bool IsEnabled_t36();
    void fire_t37();
    void unfire_t37();
    bool IsEnabled_t37();
    void fire_t38();
    void unfire_t38();
    bool IsEnabled_t38();
    void fire_t39();
    void unfire_t39();
    bool IsEnabled_t39();
    void fire_t40();
    void unfire_t40();
    bool IsEnabled_t40();
    void fire_t41();
    void unfire_t41();
    bool IsEnabled_t41();
    void fire_t42();
    void unfire_t42();
    bool IsEnabled_t42();
    void fire_t43();
    void unfire_t43();
    bool IsEnabled_t43();
    void fire_t44();
    void unfire_t44();
    bool IsEnabled_t44();
    void fire_t45();
    void unfire_t45();
    bool IsEnabled_t45();
    void fire_t46();
    void unfire_t46();
    bool IsEnabled_t46();
    void fire_t47();
    void unfire_t47();
    bool IsEnabled_t47();
    void fire_t48();
    void unfire_t48();
    bool IsEnabled_t48();
    void fire_t49();
    void unfire_t49();
    bool IsEnabled_t49();
    void fire_t50();
    void unfire_t50();
    bool IsEnabled_t50();
    void fire_t51();
    void unfire_t51();
    bool IsEnabled_t51();
    void fire_t52();
    void unfire_t52();
    bool IsEnabled_t52();
    void fire_t53();
    void unfire_t53();
    bool IsEnabled_t53();
    void fire_t54();
    void unfire_t54();
    bool IsEnabled_t54();
    void fire_t55();
    void unfire_t55();
    bool IsEnabled_t55();
    void fire_t56();
    void unfire_t56();
    bool IsEnabled_t56();
    void fire_t57();
    void unfire_t57();
    bool IsEnabled_t57();
    void fire_t58();
    void unfire_t58();
    bool IsEnabled_t58();
    void fire_t59();
    void unfire_t59();
    bool IsEnabled_t59();
    void fire_t60();
    void unfire_t60();
    bool IsEnabled_t60();
    void fire_t61();
    void unfire_t61();
    bool IsEnabled_t61();
    void fire_t62();
    void unfire_t62();
    bool IsEnabled_t62();
    void fire_t63();
    void unfire_t63();
    bool IsEnabled_t63();
    void fire_t64();
    void unfire_t64();
    bool IsEnabled_t64();
    void fire_t65();
    void unfire_t65();
    bool IsEnabled_t65();
    void fire_t66();
    void unfire_t66();
    bool IsEnabled_t66();
    void fire_t67();
    void unfire_t67();
    bool IsEnabled_t67();
    void fire_t68();
    void unfire_t68();
    bool IsEnabled_t68();
    void fire_t69();
    void unfire_t69();
    bool IsEnabled_t69();
    void fire_t70();
    void unfire_t70();
    bool IsEnabled_t70();
    void fire_t71();
    void unfire_t71();
    bool IsEnabled_t71();
    void fire_t72();
    void unfire_t72();
    bool IsEnabled_t72();
    void fire_t73();
    void unfire_t73();
    bool IsEnabled_t73();
    void fire_t74();
    void unfire_t74();
    bool IsEnabled_t74();
    void fire_t75();
    void unfire_t75();
    bool IsEnabled_t75();
    void fire_t76();
    void unfire_t76();
    bool IsEnabled_t76();
    void fire_t77();
    void unfire_t77();
    bool IsEnabled_t77();
    void fire_t78();
    void unfire_t78();
    bool IsEnabled_t78();
    void fire_t79();
    void unfire_t79();
    bool IsEnabled_t79();
    void fire_t80();
    void unfire_t80();
    bool IsEnabled_t80();
    void fire_t81();
    void unfire_t81();
    bool IsEnabled_t81();
    void fire_t82();
    void unfire_t82();
    bool IsEnabled_t82();
    void fire_t83();
    void unfire_t83();
    bool IsEnabled_t83();
    void fire_t84();
    void unfire_t84();
    bool IsEnabled_t84();
    void fire_t85();
    void unfire_t85();
    bool IsEnabled_t85();
    void fire_t86();
    void unfire_t86();
    bool IsEnabled_t86();
    void fire_t87();
    void unfire_t87();
    bool IsEnabled_t87();
    void fire_t88();
    void unfire_t88();
    bool IsEnabled_t88();
    void fire_t89();
    void unfire_t89();
    bool IsEnabled_t89();
    void fire_t90();
    void unfire_t90();
    bool IsEnabled_t90();
    void fire_t91();
    void unfire_t91();
    bool IsEnabled_t91();
    void fire_t92();
    void unfire_t92();
    bool IsEnabled_t92();
    void fire_t93();
    void unfire_t93();
    bool IsEnabled_t93();
    void fire_t94();
    void unfire_t94();
    bool IsEnabled_t94();
    void fire_t95();
    void unfire_t95();
    bool IsEnabled_t95();
    void fire_t96();
    void unfire_t96();
    bool IsEnabled_t96();
    void fire_t97();
    void unfire_t97();
    bool IsEnabled_t97();
    void fire_t98();
    void unfire_t98();
    bool IsEnabled_t98();
    void fire_t99();
    void unfire_t99();
    bool IsEnabled_t99();
    void fire_t100();
    void unfire_t100();
    bool IsEnabled_t100();
    void fire_t101();
    void unfire_t101();
    bool IsEnabled_t101();
    void fire_t102();
    void unfire_t102();
    bool IsEnabled_t102();
    void fire_t103();
    void unfire_t103();
    bool IsEnabled_t103();
    void fire_t104();
    void unfire_t104();
    bool IsEnabled_t104();
    void fire_t105();
    void unfire_t105();
    bool IsEnabled_t105();
    void fire_t106();
    void unfire_t106();
    bool IsEnabled_t106();
    void fire_t107();
    void unfire_t107();
    bool IsEnabled_t107();
    void fire_t108();
    void unfire_t108();
    bool IsEnabled_t108();
    void fire_t109();
    void unfire_t109();
    bool IsEnabled_t109();
    void fire_t110();
    void unfire_t110();
    bool IsEnabled_t110();
    void fire_t111();
    void unfire_t111();
    bool IsEnabled_t111();
    void fire_t112();
    void unfire_t112();
    bool IsEnabled_t112();
    void fire_t113();
    void unfire_t113();
    bool IsEnabled_t113();
    void fire_t114();
    void unfire_t114();
    bool IsEnabled_t114();
    void fire_t115();
    void unfire_t115();
    bool IsEnabled_t115();
    void fire_t116();
    void unfire_t116();
    bool IsEnabled_t116();
    void fire_t117();
    void unfire_t117();
    bool IsEnabled_t117();
    void fire_t118();
    void unfire_t118();
    bool IsEnabled_t118();
    void fire_t119();
    void unfire_t119();
    bool IsEnabled_t119();
    void fire_t120();
    void unfire_t120();
    bool IsEnabled_t120();
    void fire_t121();
    void unfire_t121();
    bool IsEnabled_t121();
    void fire_t122();
    void unfire_t122();
    bool IsEnabled_t122();
    void fire_t123();
    void unfire_t123();
    bool IsEnabled_t123();
    void fire_t124();
    void unfire_t124();
    bool IsEnabled_t124();
    void fire_t125();
    void unfire_t125();
    bool IsEnabled_t125();
    void fire_t126();
    void unfire_t126();
    bool IsEnabled_t126();
    void fire_t127();
    void unfire_t127();
    bool IsEnabled_t127();
    void fire_t128();
    void unfire_t128();
    bool IsEnabled_t128();
    void fire_t129();
    void unfire_t129();
    bool IsEnabled_t129();
    void fire_t130();
    void unfire_t130();
    bool IsEnabled_t130();
    void fire_t131();
    void unfire_t131();
    bool IsEnabled_t131();
    void fire_t132();
    void unfire_t132();
    bool IsEnabled_t132();
    void fire_t133();
    void unfire_t133();
    bool IsEnabled_t133();
    void fire_t134();
    void unfire_t134();
    bool IsEnabled_t134();
    void fire_t135();
    void unfire_t135();
    bool IsEnabled_t135();
    void fire_t136();
    void unfire_t136();
    bool IsEnabled_t136();
    void fire_t137();
    void unfire_t137();
    bool IsEnabled_t137();
    void fire_t138();
    void unfire_t138();
    bool IsEnabled_t138();
    void fire_t139();
    void unfire_t139();
    bool IsEnabled_t139();
    void fire_t140();
    void unfire_t140();
    bool IsEnabled_t140();
private:
};
#endif	/* _SPN_HPP */
