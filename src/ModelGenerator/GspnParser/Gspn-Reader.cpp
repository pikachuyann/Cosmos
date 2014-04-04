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


#include "Gspn-Reader.hpp"
#include "Gspn_gmlparser.hpp"

#include "string.h"

#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;


void searchreplace(const string &in,const string &motif,const string &rep,string &out){
	out = in;
	size_t pos = out.find(motif);
	while (pos != string::npos) {
		out.replace(pos, motif.size(), rep);
		pos = out.find(motif,pos);
	}
}


Gspn_Reader::Gspn_Reader(parameters &Q):P(Q) {
	trace_scanning = false;
	trace_parsing = false;
}

Gspn_Reader::~Gspn_Reader() {
}

int Gspn_Reader::parse(string& expr) {
	
	scan_expression(expr);
	
	IndexDist["UNIFORM"] = 1;
	IndexDist["EXPONENTIAL"] = 2;
	IndexDist["DETERMINISTIC"] = 3;
	IndexDist["LOGNORMAL"] = 4;
	IndexDist["TRIANGLE"] = 5;
	IndexDist["GEOMETRIC"] = 6;
	IndexDist["ERLANG"] = 7;
	IndexDist["GAMMA"] =8;
	
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
		
		int x = parse(str);
		
		if (x) cout << "Parsing GSPN Description file failed" << endl;
		
		return x;
	} else {
		cout << "Can't open : " << filename << endl;
		return 1;
	}
}

//#include "Gspn_gmlparser.cpp";
int Gspn_Reader::parse_gml_file(parameters &P) {
	ifstream ifile(P.PathGspn.c_str());
	if(ifile){
		//cout << "parse GML:" << filename << endl;
		MyGspn.nbpass=0;
		//first pass declaration and place.
		MyModelHandler* handler = new MyModelHandler(MyGspn,P);
		ModelHandlerPtr handlerPtr(handler);
		ExpatModelParser parser = ExpatModelParser(handlerPtr);
		parser.parse_file(P.PathGspn);
		
		MyGspn.nbpass=1;
		//second pass transitions and arcs.
		ModelHandlerPtr handlerPtr2(new MyModelHandler(MyGspn,P,handler->IsPlace,handler->Gml2Place,handler->Gml2Trans));
		ExpatModelParser parser2 = ExpatModelParser(handlerPtr2);
		parser2.parse_file(P.PathGspn);
		
		
		//cout << "end parse GML:"<< MyGspn.pl << endl;
		if (P.RareEvent)addSinkTrans();
		return 0;
	}else{
		cout << "File " << P.PathGspn << " does not exist!" << endl;
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


void Gspn_Reader::addSinkTrans(){
    MyGspn.outArcsStruct.insert(make_pair(MyGspn.arckey(MyGspn.tr-1, MyGspn.pl-1), arc(1)));
}

void Gspn_Reader::iterateDom(const string &s,const string &sop, const string &sclos ,const string &s2,const string &sop2, const string &sclos2 ,const colorDomain & cd, size_t prof,function<void (const string&,const string&)> func){
	if(prof == cd.colorClassIndex.size() ){func(s,s2);}
	else{
		for(const auto cc : MyGspn.colClasses[cd.colorClassIndex[prof]].colors )
			iterateDom(s+ sop + cc.name + sclos, sop, sclos,
					   s2+sop2+ "Color_"+MyGspn.colClasses[cd.colorClassIndex[prof]].name+"_"+cc.name+sclos2,sop2, sclos2, cd, prof+1, func);
	}
	
}

void Gspn_Reader::iterateDomVec(vector<color> &v, const colorDomain & cd, size_t prof,function<void (const vector<color>&)> func){
	if(prof == cd.colorClassIndex.size() ){func(v);}
	else{
		for(const auto cc : MyGspn.colClasses[cd.colorClassIndex[prof]].colors ){
            v.push_back(cc);
            iterateDomVec(v, cd, prof+1, func);
            v.pop_back();
        }
	}

}

void Gspn_Reader::iterateVars(const string &s,const string &sop, const string &sclos ,const set<size_t> &vd, size_t prof,function<void (const string&)> func){
	if(prof == MyGspn.colVars.size() ){func(s);}
	else{
		if (vd.count(prof)>0) {
			for(const auto cc : MyGspn.colClasses[MyGspn.colDoms[MyGspn.colVars[prof].type].colorClassIndex[0]].colors )
				iterateVars(s+ sop + cc.name + sclos, sop, sclos, vd, prof+1, func);
		}else{
			iterateVars(s, sop, sclos,vd, prof+1, func);
		}
	}
}

void Gspn_Reader::iterateVars(vector<color> &v,const set<size_t> &vd, size_t prof,function<void (const vector<color>&)> func){
	if(prof == MyGspn.colVars.size() ){func(v);}
	else{
		if (vd.count(prof)>0) {
			for(const auto cc : MyGspn.colClasses[MyGspn.colDoms[MyGspn.colVars[prof].type].colorClassIndex[0]].colors ){
				v.push_back(cc);
				iterateVars(v, vd, prof+1, func);
				v.pop_back();
			}
		}else{
			iterateVars(v,vd, prof+1, func);
		}
	}
}


