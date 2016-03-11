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
 * file Gspn-model.hpp                                                         *
 * Created by Benoit Barbot on 09/06/15.                                       *
 *******************************************************************************
 */

#include <fstream>

#include "Gspn-model.hpp"

using namespace std;

size_t userDefineDistribution::nbparam = 1;
string userDefineDistribution::polyfile;

void searchreplace(const string &in,const string &motif,const string &rep,string &out){
    out = in;
    size_t pos = out.find(motif);
    while (pos != string::npos) {
        out.replace(pos, motif.size(), rep);
        pos = out.find(motif,pos);
    }
}


void GspnType::iterateDom(const string &s,const string &sop, const string &sclos ,const string &s2,const string &sop2, const string &sclos2 ,const colorDomain & cd, size_t prof,function<void (const string&,const string&)> func){
    if(prof == cd.colorClassIndex.size() ){func(s,s2);}
    else{
        for(const auto cc : colClasses[cd.colorClassIndex[prof]].colors )
            iterateDom(s+ sop + cc.name + sclos, sop, sclos,
                       s2+sop2+ "Color_"+colClasses[cd.colorClassIndex[prof]].name+"_"+cc.name+sclos2,sop2, sclos2, cd, prof+1, func);
    }

}

void GspnType::iterateDomVec(vector<color> &v, const colorDomain & cd, size_t prof,function<void (const vector<color>&)> func){
    if(prof == cd.colorClassIndex.size() ){func(v);}
    else{
        for(const auto cc : colClasses[cd.colorClassIndex[prof]].colors ){
            v.push_back(cc);
            iterateDomVec(v, cd, prof+1, func);
            v.pop_back();
        }
    }

}

void GspnType::iterateVars(const string &s,const string &sop, const string &sclos ,const set<size_t> &vd, size_t prof,function<void (const string&)> func){
    if(prof == colVars.size() ){func(s);}
    else{
        if (vd.count(prof)>0) {
            for(const auto cc : colClasses[colDoms[colVars[prof].type].colorClassIndex[0]].colors )
                iterateVars(s+ sop + cc.name + sclos, sop, sclos, vd, prof+1, func);
        }else{
            iterateVars(s, sop, sclos,vd, prof+1, func);
        }
    }
}

void GspnType::iterateVars(vector<color> &v,const set<size_t> &vd, size_t prof,function<void (const vector<color>&)> func){
    if(prof == colVars.size() ){func(v);}
    else{
        if (vd.count(prof)>0) {
            for(const auto cc : colClasses[colDoms[colVars[prof].type].colorClassIndex[0]].colors ){
                v.push_back(cc);
                iterateVars(v, vd, prof+1, func);
                v.pop_back();
            }
        }else{
            iterateVars(v,vd, prof+1, func);
        }
    }
}


size_t GspnType::get_uid(const string &str){
    //cout << "debug:\t" << str;
    if(uid.count(str)>0){
        //cout << " -> " << uid[str] << endl;
        return uid[str];
    }
    size_t it = uid.size();
    uid[str] = it;
    //cout << " -> " << uid[str] << endl;
    return it;
}

size_t GspnType::new_uid(const string &str){
    const auto i = uid.size();
    return get_uid(str+"U"+ to_string(i));
}

namespace textOutput{
    std::ostream& operator<<(std::ostream& os, const place& obj){
        os << "place " << obj.name << "(" << obj.id << "){" << endl;
        os << "\tmarking:" << obj.Marking << endl;
        return os;
    }
    
    
    std::ostream& operator<<(std::ostream& os, const ProbabiliteDistribution& obj){
        os << obj.name << "(";
        for( const auto &e : obj.Param){
            os << e << ",";
        }
        os << ")";
        
        return os;
    }
    
    std::ostream& operator<<(std::ostream& os, const transition& obj){
        os << "transition " << obj.name << "(" << obj.id << "){" << endl;
        os << "\tdistribution:" << obj.dist << endl;
        os << "\tpriority:" << obj.priority << endl;
        os << "\tweight:" << obj.weight << endl << "}" << endl;
        return os;
    }
    
    std::ostream& operator<<(std::ostream& os, const userDefineDistribution& obj){
        os << "UserDefineDistribution " << obj.name << "{" << endl;
        os << "\tvar:" << obj.var << endl;
        os << "\tcdf:" << obj.cdf << endl;
        os << "\tpdf:" << obj.pdf << endl;
        os << "\tlowerBound:" << obj.lowerBound << endl << "}" << endl;
        return os;
    }
}



