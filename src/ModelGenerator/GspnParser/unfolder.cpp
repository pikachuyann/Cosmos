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
 * file unfolder.cpp created by Benoit Barbot on 10/01/14.                     *
 *******************************************************************************
 */

#include "unfolder.hpp"

string unfolder::str_of_vect(const vector<color> &v,const string &smid)const {
	string acc;
	for( auto s=v.begin(); s != v.end(); ++s){
		if(s != v.begin())acc += smid;
		acc += s->name;
	}
	return acc;
}

void unfolder::export_grml(ofstream& fout){
	fout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
	fout << "<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">" << endl;
	
	for(const auto &p: MyGspn.placeStruct)export_place_grml(fout,p);
	
	for(const auto &t: MyGspn.transitionStruct)export_transition_grml(fout,t);
	
	for(const auto &t: MyGspn.transitionStruct)export_arc_grml(fout, t);
	
	fout << "</model>" << endl;
}

size_t unfolder::get_uid(const string &str){
	//cout << "debug:\t" << str << endl;
	if(uid.count(str)>0)return uid[str];
	size_t it = uid.size();
	uid[str] = it;
	return it;
}

void unfolder::export_place_grml(ofstream &fout,const place &p){
	iterateDom(p.name, "_", "", "", "_", "", MyGspn.colDoms[p.colorDom], 0, [&](const string& str,const string&){
		fout << "\t<node id=\"" << get_uid("place"+str) << "\" nodeType=\"place\">"<< endl;
		fout << "\t\t<attribute name=\"name\">" << str << "</attribute>" << endl;
		fout << "\t\t<attribute name=\"marking\"><attribute name=\"expr\"><attribute name=\"numValue\">" << endl;
		if(MyGspn.Marking[p.id].compare("0")==0){
			fout << "\t\t\t0" << endl;
		} else if(p.colorDom != UNCOLORED_DOMAIN) {
			fout << "\t\t\t1" << endl;
		} else fout << "\t\t\t" << MyGspn.Marking[p.id];
		fout << "\t\t</attribute></attribute></attribute>" << endl;

		
		fout << "\t</node>" << endl;
		
	});
}

void unfolder::export_transition_grml(ofstream &fout, const transition &t){
		iterateVars(t.label , "_", "", t.varDomain , 0, [&](const string& str){
			fout << "\t<node id=\"" << get_uid("transition"+str) << "\" nodeType=\"transition\">"<< endl;
			fout << "\t\t<attribute name=\"name\">" << str << "</attribute>" << endl;
			fout << "\t\t<attribute name=\"distribution\">" << endl;
            fout << "\t\t\t<attribute name=\"type\">" << t.dist.name ;
            fout << "</attribute>" << endl;
            for(auto &sparam : t.dist.Param){
                fout << "\t\t\t<attribute name=\"param\"><attribute name=\"expr\">";
                if(Evaluate_unfold.parse(sparam)){
                    fout << "<attribute name=\"numValue\">"<< endl;
                    fout << "\t\t\t\t" << MyGspn.RealConstant.find(sparam)->second << endl;
                } else {
                    fout << "<attribute name=\"numValue\">" << endl;
                    fout << "\t\t\t\t" << Evaluate_unfold.RealResult << endl;
                }
                fout << "\t\t\t</attribute></attribute></attribute>"<< endl;
            }
            fout << "\t\t</attribute>" << endl;
			fout << "\t</node>" << endl;
		});
}

void unfolder::export_coltoken(ofstream &fout,const vector<color> &vec,
							   const coloredToken &coltoken,const transition &t,const place &p,bool dir){
	size_t truid = get_uid("transition"+t.label+"_"+str_of_vect(vec, "_"));
	vector<color> vec2;
	for ( size_t i =0 ; i != coltoken.field.size(); ++i) {
		colorClass cc = MyGspn.colClasses[vec[coltoken.field[i]].cc];
		size_t col = (vec[coltoken.field[i]].id + coltoken.varIncrement[i] + cc.colors.size()) % cc.colors.size();
		vec2.push_back(cc.colors[col]);
	}
	size_t pluid = get_uid("place"+p.name+"_"+str_of_vect(vec2, "_"));
	
	fout << "\t<arc id=\"" << get_uid("arcpre_"+t.label+str_of_vect(vec, "_")+"_"+p.name);
	fout << "\" arcType=\"arc\" source=\"";
	if(dir){
		fout << pluid << "\" target=\"" << truid << "\">";
	}else fout << truid << "\" target=\"" << pluid << "\">";
	fout << "<attribute name=\"valuation\"><attribute name=\"expr\"><attribute name=\"numValue\">" << endl;
	fout << "\t\t" << coltoken.mult << endl;
	fout << "\t</attribute></attribute></attribute></arc>" << endl;
}

void unfolder::export_arc_grml(ofstream &fout, const transition &t){
	vector<color> iteratevec;
	iterateVars(iteratevec , t.varDomain , 0, [&](const vector<color> &vec){
		for(const auto &p: MyGspn.placeStruct){
			for(auto &coltoken : MyGspn.inArcsStruct[t.id][p.id].coloredVal )
				export_coltoken(fout,vec,coltoken,t,p,true);
			for(auto &coltoken : MyGspn.outArcsStruct[t.id][p.id].coloredVal )
				export_coltoken(fout,vec,coltoken,t,p,false);
		}
	});
}



