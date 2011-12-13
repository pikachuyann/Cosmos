

#include "LHA.hpp"

#include <map>
#include <float.h>
#include <math.h>

LHA::LHA() {
}

LHA::~LHA() {
}

LHA::LHA(const LHA & orig) {
}

int LHA::EnabledInitLocation(vector<int>& Marking) {

    for (set<int>::iterator l = InitLoc.begin(); l != InitLoc.end(); l++) {
        if (CheckLocation((*l), Marking))
            return (*l);
    }
    return (-1);
}

int LHA::GetEnabled_S_Edges(int cl, int PetriNetTransition, double DeltaT, vector<int>& Marking, vector<int>& NextMarking) {
    for (set<int>::iterator it = ActionEdges[cl][PetriNetTransition].begin(); it != ActionEdges[cl][PetriNetTransition].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, NextMarking))) {
            if (CheckEdgeContraints((*it), DeltaT, Marking)) return (*it);
        }
    }

    return (-1);

}

AutEdge LHA::GetEnabled_A_Edges(unsigned int cl, vector<int>& Marking) {
    AutEdge Ed;
    Ed.Index = -1;
    Ed.FiringTime = DBL_MAX;
    for (set<int>::iterator it = Out_A_Edges[cl].begin(); it != Out_A_Edges[cl].end(); it++) {
        if ((CheckLocation(Edge[(*it)].Target, Marking))) {
            t_interval I = GetEdgeEnablingTime((*it), Marking);
            if (I.first <= I.second) {
                if (I.first < Ed.FiringTime) {
                    Ed.Index = (*it);
                    Ed.FiringTime = I.first;
                }

            }
        }
    }

    return Ed;


}

void LHA::DoElapsedTimeUpdate(double DeltaT, vector<int>& Marking) {

    for (int v = 0; v < NbVar; v++) {
        Var[v] += GetFlow(v, CurrentLocation, Marking) * DeltaT;
    }

}

void LHA::resetVarsTable() {
    for (int v = 0; v < NbVar; v++)
        Var[v] = 0;
    for (int i = 0; i < LinForm.size(); i++) {
        LinForm[i] = 0;
        OldLinForm[i] = 0;
    }
    for (int i = 0; i < LhaFunc.size(); i++)
        LhaFunc[i] = 0;
}

void LHA::reset(vector<int>& Marking) {
    Likelihood = 1.0;
    LHA::resetVarsTable();
    CurrentLocation = EnabledInitLocation(Marking);
    CurrentTime = 0;
}

void LHA::setCurrentLocation(unsigned int loc) {
    CurrentLocation = loc;
}

bool LHA::isFinal(unsigned int l) {
    return ( (FinalLoc.find(l) != FinalLoc.end()) ? true : false);
}

double LHA::min(double& a, double& b) {
    if (a <= b)return a;
    else return b;
}

double LHA::max(double& a, double& b) {
    if (a >= b)return a;
    else return b;
}

double LHA::Min(double& a, double& b, double& c) {
    double x = min(b, c);
    return min(a, x);
}

double LHA::Max(double& a, double& b, double& c) {
    double x = max(b, c);
    return max(a, x);
}


double LHA::Integral(double& LX0, double& LX1, double& Delta){
    if(Delta==0) return 0;
    double coef=(LX1-LX0)/Delta;
    if(coef==0) return Delta * LX0;
    return (pow(LX1,2)-pow(LX0,2))/(2*coef);
}

double LHA::IntegralP2(double& LX0, double& LX1, double& Delta){
    if(Delta==0) return 0;
    double coef=(LX1-LX0)/Delta;
    if(coef==0) return Delta * pow(LX0,2);
    return (pow(LX1,3)-pow(LX0,3))/(3*coef);
}


