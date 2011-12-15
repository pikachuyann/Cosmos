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

