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

#include "spn_orig.hpp" 

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
//#include "RareEvent.hpp"


using namespace std;

SPN_ORIG::SPN_ORIG(const int pl, const int tr) :
	pl(pl),
	tr(tr),
	ParamDistr(3),
	TransitionConditions(tr,0){
}

SPN_ORIG::~SPN_ORIG() {
}


set<int, less <int> > SPN_ORIG::enabledTrans() {
    set<int, less<int> > eTrans;
    for (int i = 0; i < (this->tr); i++) {
        if (IsEnabled(i)) {
            eTrans.insert(i);
        }
    }
    this->enTrans = eTrans;
    return eTrans;
}

void SPN_ORIG::reset() {
	Marking.resetToInitMarking();
	TransitionConditions = initTransitionConditions;
}

double SPN_ORIG::min(double x1, double x2) {
    if (x1 < x2) return x1;
    else return x2;
}

double SPN_ORIG::max(double x1, double x2) {
    if (x1 > x2) return x1;
    else return x2;
}

//------------------- Rare Event -----------------------------------------------
void SPN_ORIG::Msimple(){
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

//void SPN_ORIG::lumpingFun(vector<int>* ve) {
//}
//-------------------/Rare Event -----------------------------------------------
