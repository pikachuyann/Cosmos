/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
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
 * file casesWriter.cpp                                                         *
 * Created by Benoit Barbot on 11/09/13.                                       *
 *******************************************************************************
 */


#include <iostream>
#include "casesWriter.hpp"


using namespace std;

casesHandler::casesHandler(string svar):scase(svar){};

void casesHandler::addCase(int c,const string st){
  const char* cst = st.c_str();
  map<const char*,int>::iterator it = cases.find(cst);
  if(it == cases.end()){
    cases[cst]=c;
    mapping[c]=st;
    cout << "notfound" << endl;
  }else{
    mapping[c]=st;
    cout << "already there" << endl;
  }
}

void casesHandler::writeCases(ostream &s){
  s << "switch (" << scase << "){" << endl;
  for(map<const char*,int>::iterator it = cases.begin();it != cases.end(); ++it){
    for(map<int,std::string>::iterator it2 = mapping.begin(); it2 != mapping.end(); ++it2){
	if(it2->second.compare(it->first)==0)
	  s << "\tcase " << it2->first << ":"<< endl;
    }
    s << "\t\t"<< it->first << endl;
    s << "\t\tbreak;" << endl;
  }

}


int main(){
  cout << "test";
  casesHandler chandler("testcases");
  chandler.addCase(1,"test1");
  chandler.addCase(10,"test1");
  chandler.addCase(2,"test2");
  chandler.writeCases(cout);

}
