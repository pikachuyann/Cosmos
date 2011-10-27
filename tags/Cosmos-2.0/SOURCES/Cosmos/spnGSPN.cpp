#include "spn.hpp" 

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include <set>
#include <vector>
#include <math.h>
#include <float.h>
#include <limits.h> 
#include "RareEvent.hpp"

SPN::SPN() {
}

SPN::~SPN() {
}

SPN::SPN(const SPN & orig) {

}

set<int, less <int> > SPN::enabledTrans() {
    set<int, less<int> > eTrans;
    for (int i = 0; i < (this->tr); i++) {
        if (IsEnabled(i)) {
            eTrans.insert(i);
        }
    }
    this->enTrans = eTrans;
    return eTrans;
}

void SPN::reset() {
    Marking = initMarking;
}

void SPN::setMarking(vector<int>& M) {
    Marking = M;
}

void SPN::EnabledDisabledTr() {

    for (int t1 = 0; t1 < tr; t1++) {
        set<int> S;
        set<int> Sinhib;
        set<int> INt1;
        for (int p = 0; p < pl; p++) {
            if (inArcs[t1][p] > 0) {
                INt1.insert(p);
            }
        }
        for (int t2 = 0; t2 < tr; t2++)
            if (t1 != t2) {
                int size = INt1.size();
                set<int> INt1t2 = INt1;
                bool B = true;
                int p = 0;
                while (B && p < pl) {
                    if (inArcs[t2][p] > 0) {
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
                while (B && p < pl) {
                    if (inhibArcs[t2][p] > 0) {
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
    for (int t1 = 0; t1 < tr; t1++) {
        set<int> S = PossiblyEnabled[t1];
        set<int> Sinhib = PossiblyDisabled[t1];
        set<int> OUTt1;
        for (int p = 0; p < pl; p++)
            if (outArcs[t1][p] > 0)
                OUTt1.insert(p);
        for (int t2 = 0; t2 < tr; t2++)
            if (t1 != t2) {
                int size = OUTt1.size();
                set<int> OUTt1INt2 = OUTt1;
                bool B = true;
                int p = 0;
                while (B && p < pl) {
                    if (inArcs[t2][p] > 0) {
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
                while (B && p < pl) {
                    if (inhibArcs[t2][p] > 0) {
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
    for (int t = 0; t < tr; t++)
        if (Transition[t].MarkingDependent)
            MarkDepT.insert(t);

    for (int t = 0; t < tr; t++) {
        set<int> S;
        for (set<int>::iterator it = MarkDepT.begin(); it != MarkDepT.end(); it++) {
            if ((PossiblyEnabled[t].find((*it)) == PossiblyEnabled[t].end()) && (PossiblyDisabled[t].find((*it)) == PossiblyDisabled[t].end()))
                S.insert((*it));

        }
        FreeMarkDepT.push_back(S);

    }




}

set<int> SPN::PossiblyEn(int t) {
    return (PossiblyEnabled)[t];
}

set<int> SPN::PossiblyDis(int t) {
    return (PossiblyDisabled)[t];
}

vector<int> SPN::getMarking() {
    return Marking;
}

double SPN::min(double x1, double x2) {
    if (x1 < x2) return x1;
    else return x2;
}

double SPN::max(double x1, double x2) {
    if (x1 > x2) return x1;
    else return x2;
}

//------------------- Rare Event -----------------------------------------------
void SPN::Msimple(){
  vector<int> tab;
  for(vector<spn_place>::iterator it=Place.begin(); it != Place.end(); it++){
    //cout << (*it).label<< " : " << (*it).label.substr(0,3) << endl;
    if((*it).label.substr(0,4).compare(" RE_") == 0){
      tab.push_back((*it).Id);
      //cout << ":"<<(*it).label << endl;
    }
  }
  Msimpletab = tab;
}
//-------------------/Rare Event -----------------------------------------------

    const double mu=1;
    const double rho1=1;
    const double rho2=1;
void SPN::Load(){
    Path ="tandem_simp";
    pl =2;
    tr =3;
    IntVector Null_Pl_Vector(pl, 0);
    IntMatrix Null_PlxTr_Matrix(tr, Null_Pl_Vector);
    inArcs = Null_PlxTr_Matrix;
    outArcs = Null_PlxTr_Matrix;
    inhibArcs = Null_PlxTr_Matrix;
    Marking = Null_Pl_Vector;;

    inArcs[1][0]=1;

    inArcs[2][1]=1;

    outArcs[0][0]=1;

    outArcs[1][1]=1;





    Marking[0]=1;

   initMarking = Marking;

    vector <spn_trans> t(3);
    Transition = t;
    vector <spn_place> p(2);
    Place = p;
    Place[0].Id =0;
    Place[0].label =" Queue1";
    PlaceIndex[" Queue1"] =0;
    Place[1].Id =1;
    Place[1].label =" Queue2";
    PlaceIndex[" Queue2"] =1;
    Transition[0].Id =0;
    Transition[0].label ="mu";
    TransitionIndex["mu"]=0;
    Transition[1].Id =1;
    Transition[1].label ="rho1";
    TransitionIndex["rho1"]=1;
    Transition[2].Id =2;
    Transition[2].label ="rho2";
    TransitionIndex["rho2"]=2;
    Transition[0].transType = Timed;
    Transition[0].DistType = "EXPONENTIAL";
    Transition[0].DistParams.push_back(" 1" );
    Transition[0].priority = "1";
    Transition[0].MarkingDependent = 0;
    Transition[0].weight = "1 ";

    Transition[1].transType = Timed;
    Transition[1].DistType = "EXPONENTIAL";
    Transition[1].DistParams.push_back(" 1" );
    Transition[1].priority = "1";
    Transition[1].MarkingDependent = 0;
    Transition[1].weight = "1 ";

    Transition[2].transType = Timed;
    Transition[2].DistType = "EXPONENTIAL";
    Transition[2].DistParams.push_back(" 1" );
    Transition[2].priority = "1";
    Transition[2].MarkingDependent = 0;
    Transition[2].weight = "1 ";

    vector < vector <int> > vec(3);
    PredT = vec;
    PredT[1].push_back(0);
    PredT[2].push_back(1);
    EnabledDisabledTr();
    Msimple();
vector <double> Rate_Table_init (tr);
Rate_Table = Rate_Table_init;
Origine_Rate_Table = Rate_Table_init;
}

bool SPN::IsEnabled(int t){
    switch(t){
     case 0:
       return IsEnabled_t0();
       break;
     case 1:
       return IsEnabled_t1();
       break;
     case 2:
       return IsEnabled_t2();
       break;
   }
}

bool SPN::IsEnabled_t0() {
    return true;
}

bool SPN::IsEnabled_t1() {
    if (Marking[0] < 1) return false;
    return true;
}

bool SPN::IsEnabled_t2() {
    if (Marking[1] < 1) return false;
    return true;
}

void SPN::fire(int t){
   switch(t){
     case 0: {
       fire_t0();
       break;
     } 
     case 1: {
       fire_t1();
       break;
     } 
     case 2: {
       fire_t2();
       break;
     } 
   }
}

void SPN::unfire(int t){
   switch(t){
     case 0: {
       unfire_t0();
       break;
     } 
     case 1: {
       unfire_t1();
       break;
     } 
     case 2: {
       unfire_t2();
       break;
     } 
   }
}

void SPN::fire_t0() {
    Marking[0] += 1;
}

void SPN::unfire_t0() {
    Marking[0] -= 1;
}

void SPN::fire_t1() {
    Marking[0] -= 1;
    Marking[1] += 1;
}

void SPN::unfire_t1() {
    Marking[0] += 1;
    Marking[1] -= 1;
}

void SPN::fire_t2() {
    Marking[1] -= 1;
}

void SPN::unfire_t2() {
    Marking[1] += 1;
}

vector<double> SPN::GetDistParameters(int t){
   vector<double> P(2);
   double origin_rate = (SPN::GetDistParametersOrigin(t))[0];
   P[0]= ComputeDistr( *this ,t, origin_rate);
   P[1]= origin_rate;
   return P;
}
 
vector<double> SPN::GetDistParametersOrigin(int t){
   switch(t){
     case 0: {
       vector<double> P(1);
       P[0]= ( double ) 1;
       return P;
       break;
     }
     case 1: {
       vector<double> P(1);
       P[0]= ( double ) 1;
       return P;
       break;
     }
     case 2: {
       vector<double> P(1);
       P[0]= ( double ) 1;
       return P;
       break;
     }
   }
}

double SPN::GetPriority(int t){
   switch(t){
     case 0: {
       return (double)1;
       break;
     } 
     case 1: {
       return (double)1;
       break;
     } 
     case 2: {
       return (double)1;
       break;
     } 
   }
}

double SPN::GetWeight(int t){
   switch(t){
     case 0:
       return (double)1;
       break;
     case 1:
       return (double)1;
       break;
     case 2:
       return (double)1;
       break;
   }
}

