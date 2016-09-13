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
 * file Gspn-Writer.cpp created by Benoit Barbot on 14/01/14.                  *
 *******************************************************************************
 */


#include <algorithm>
#include <sstream>
#include <limits.h>

#include "Gspn-Writer.hpp"
#include "../casesWriter.hpp"


using namespace std;

Gspn_Writer::Gspn_Writer(GspnType& mgspn,const parameters& Q):MyGspn(mgspn),P(Q){
    markingSize = 0;
    for( let p : MyGspn.placeStruct){
        size_t t =1;
            for ( let cd : MyGspn.colDoms[p.colorDom].colorClassIndex)
            t*= MyGspn.colClasses[cd].size();
        markingSize +=t;
    }
        
    if(P.lightSimulator){
        trId = "TR_PL_ID t";
    }
}



void Gspn_Writer::writeFunT(ostream &f,
                            const std::string &rtype,
                            const std::string &name,
                            const std::string &extraArg,
                            function<void(unsigned int,stringstream &)> ft,
                            const std::string init = "")const {
    f << rtype <<" "<< objName << name << trId << extraArg << "{" << endl;
    f << init << endl;
    casesHandler weightcases("t");
    for (size_t t = 0; t < MyGspn.tr ; t++){
        stringstream newcase;
        //newcase << "\t\t" <<
        ft(t,newcase);
        //<< endl;
        weightcases.addCase(t, newcase.str(),MyGspn.transitionStruct[t].name);
    }
    weightcases.writeCases(f);
    f << "}\n" << endl;
}


// Precompute effect of transitions over other transitions
void Gspn_Writer::EnabledDisabledTr(vector< set<int> > &PossiblyEnabled,
                                    vector< set<int> > &PossiblyDisabled,
                                    vector< set<int> > &FreeMarkDepT)const {
	
	for (size_t t1 = 0; t1 < MyGspn.tr; t1++) {
		set<int> S;
		set<int> Sinhib;
		set<int> INt1;
        for(auto inarc= MyGspn.inArcsStruct.lower_bound(make_pair(t1, 0));
            inarc != MyGspn.inArcsStruct.end() && inarc->first.first==t1; ++inarc )
            if(!inarc->second.isEmpty)INt1.insert(inarc->first.second);

        for (size_t t2 = 0; t2 < MyGspn.tr; t2++)
			if (t1 != t2) {
				auto size = INt1.size();
				auto INt1t2 = INt1;

                for(auto inarc= MyGspn.inArcsStruct.lower_bound(make_pair(t2, 0));
                    inarc != MyGspn.inArcsStruct.end() && inarc->first.first==t2; ++inarc)
                    if( !inarc->second.isEmpty){
                        INt1t2.insert(inarc->first.second);
                        if (size == INt1t2.size()) {
							S.insert(t2);
                            break;
						} else size = INt1t2.size();
                    }
				
				size = INt1.size();
				set<int> INt1t2Inhib = INt1;
                for(auto inhibarc= MyGspn.inhibArcsStruct.lower_bound(make_pair(t2, 0));
                    inhibarc != MyGspn.inhibArcsStruct.end() && inhibarc->first.first==t2; ++inhibarc)
                    if(!inhibarc->second.isEmpty){
                        INt1t2Inhib.insert(inhibarc->first.second );
                        if (size == INt1t2Inhib.size()) {
							Sinhib.insert(t2);
                            break;
						} else size = INt1t2Inhib.size();
                    }
			}
		
		PossiblyDisabled.push_back(S);
		PossiblyEnabled.push_back(Sinhib);
	}
	for (size_t t1 = 0; t1 < MyGspn.tr; t1++) {
		auto S = PossiblyEnabled[t1];
		auto Sinhib = PossiblyDisabled[t1];
		set<int> OUTt1;
        for(auto outarc= MyGspn.outArcsStruct.lower_bound(make_pair(t1, 0));
            outarc != MyGspn.outArcsStruct.end() && outarc->first.first==t1; ++outarc )
            if(!outarc->second.isEmpty)OUTt1.insert(outarc->first.second);

        for (size_t t2 = 0; t2 < MyGspn.tr; t2++)
			if (t1 != t2) {
				size_t size = OUTt1.size();
				set<int> OUTt1INt2 = OUTt1;

                for(auto inarc= MyGspn.inArcsStruct.lower_bound(make_pair(t2, 0));
                    inarc != MyGspn.inArcsStruct.end() && inarc->first.first==t2; ++inarc)
                    if( !inarc->second.isEmpty){
                        OUTt1INt2.insert(inarc->first.second);
                        if (size == OUTt1INt2.size()) {
							S.insert(t2);
                            break;
						} else size = OUTt1INt2.size();
                    }
				size = OUTt1.size();
				set<int> OUTt1t2Inhib = OUTt1;
                for(auto inhibarc= MyGspn.inhibArcsStruct.lower_bound(make_pair(t2, 0));
                    inhibarc != MyGspn.inhibArcsStruct.end() && inhibarc->first.first==t2; ++inhibarc)
                    if(!inhibarc->second.isEmpty){
                        OUTt1t2Inhib.insert(inhibarc->first.second );
                        if (size == OUTt1t2Inhib.size()) {
							Sinhib.insert(t2);
                            break;
						} else size = OUTt1t2Inhib.size();
                    }
			}
		PossiblyEnabled[t1] = S;
		PossiblyDisabled[t1] = Sinhib;
	}

    // Prune with equal arcs
    for (size_t t1 = 0; t1 < MyGspn.tr; t1++) {
        auto &S = PossiblyEnabled[t1];
        auto &Sinhib = PossiblyDisabled[t1];
        set<int> OUTt1Read;
        set<int> OUTt1;
        for(auto outarc= MyGspn.outArcsStruct.lower_bound(make_pair(t1, 0));
            outarc != MyGspn.outArcsStruct.end() && outarc->first.first==t1; ++outarc )
            if(!outarc->second.isEmpty){
                OUTt1.insert(outarc->first.second); // insert out place
                const auto ina = MyGspn.access(MyGspn.inArcsStruct, t1, outarc->first.second);
                const auto inhiba = MyGspn.access(MyGspn.inhibArcsStruct, t1, outarc->first.second);
                //Check whether this is an equal arc
                if( ina.exprVal.is_concrete() && inhiba.exprVal.is_concrete()
                   && ina.exprVal.intVal == inhiba.exprVal.intVal -1)
                    OUTt1Read.insert(outarc->first.second);
            }

        for (size_t t2 = 0; t2 < MyGspn.tr; t2++)
            if (t1 != t2) {
                //Check whether all input places are output places of t1 with equal arc
                int count=0;
                int count2=0;
                for(auto inarc= MyGspn.inArcsStruct.lower_bound(make_pair(t2, 0));
                    inarc != MyGspn.inArcsStruct.end() && inarc->first.first==t2; ++inarc){
                    count2 += OUTt1Read.count(inarc->first.second);
                    if(OUTt1.count(inarc->first.second)>0 && OUTt1Read.count(inarc->first.second)==0)count++;
                }
                for(auto inhibarc= MyGspn.inhibArcsStruct.lower_bound(make_pair(t2, 0));
                    inhibarc != MyGspn.inhibArcsStruct.end() && inhibarc->first.first==t2; ++inhibarc){
                    count2 += OUTt1Read.count(inhibarc->first.second);
                    if(OUTt1.count(inhibarc->first.second)>0 && OUTt1Read.count(inhibarc->first.second)==0)count++;
                }
                if(count>0)continue;//One input place is not an equal arc place.
                if(count2==0)continue;//No input place is an equal arc place.

                for(auto inarc= MyGspn.inArcsStruct.lower_bound(make_pair(t2, 0));
                    inarc != MyGspn.inArcsStruct.end() && inarc->first.first==t2; ++inarc)
                    if(OUTt1Read.count(inarc->first.second)>0 && inarc->second.exprVal.is_concrete()){
                    if(!(inarc->second.exprVal.intVal<=MyGspn.access(MyGspn.outArcsStruct, t1, inarc->first.second).exprVal.intVal)){
                        S.erase(t2);
                    }
                    if(!(inarc->second.exprVal.intVal<=MyGspn.access(MyGspn.inArcsStruct, t1, inarc->first.second).exprVal.intVal)){
                        Sinhib.erase(t2);
                    }
                }
                for(auto inhibarc= MyGspn.inhibArcsStruct.lower_bound(make_pair(t2, 0));
                    inhibarc != MyGspn.inhibArcsStruct.end() && inhibarc->first.first==t2; ++inhibarc)
                    if(OUTt1Read.count(inhibarc->first.second)>0 && inhibarc->second.exprVal.is_concrete()){
                    if(!(inhibarc->second.exprVal.intVal > MyGspn.access(MyGspn.outArcsStruct, t1, inhibarc->first.second).exprVal.intVal)){
                        S.erase(t2);
                    }
                    if(!(inhibarc->second.exprVal.intVal > MyGspn.access(MyGspn.inArcsStruct, t1, inhibarc->first.second).exprVal.intVal)){
                        Sinhib.erase(t2);
                    }
                }
            }
    }

	set<int> MarkDepT;
	for (size_t t = 0; t < MyGspn.tr; t++)
		if (MyGspn.transitionStruct[t].markingDependant)
			MarkDepT.insert(t);
	
	for (size_t t = 0; t < MyGspn.tr; t++) {
		set<int> S;
		for (set<int>::iterator it = MarkDepT.begin(); it != MarkDepT.end(); it++) {
			if ((PossiblyEnabled[t].find((*it)) == PossiblyEnabled[t].end()) &&
				(PossiblyDisabled[t].find((*it)) == PossiblyDisabled[t].end()))
				S.insert((*it));
		}
		FreeMarkDepT.push_back(S);
	}
}

void Gspn_Writer::writeUpdateVect(ofstream &SpnF,const string &name,const vector< set<int> > &vect)const{
        //SpnF << "\t"<< name << " = vector< vector<int> >("<< vect.size() << ");"<< endl;
    for (size_t t = 0; t < vect.size(); t++)
        if(vect[t].size()>0){
            const auto tabname = "PE_"+name+"_"+ to_string(t);
            if(P.lightSimulator){
                SpnF << "static const TR_PL_ID " << tabname << "[" << 1+vect[t].size() <<"]"<<"= {";
            } else SpnF << "static const int " << tabname << "[" << 1+vect[t].size() <<"]"<<"= {";
			for (set<int>::iterator it = vect[t].begin(); it != vect[t].end(); it++) {
				//SpnF << "\tPossiblyEnabled[" << t << "].insert( " << *it << " );"<< endl;
				SpnF << "TR_" << MyGspn.transitionStruct[*it].name << "_RT, ";
			}
        SpnF << "-1 }; /* " << MyGspn.transitionStruct[t].name << "*/"<< endl;
            // << "\t"<< name <<"[" << t << "] = vector<int>("<<tabname<<","<< tabname<<"+"<< vect[t].size()<< ");" << endl;
		/*}else if(vect[t].size()>0)
			for (set<int>::iterator it = vect[t].begin(); it != vect[t].end(); it++)
				SpnF << "\t"<< name << "[" << t << "].push_back( " << *it << " );"<< endl;*/
	}
    if(P.lightSimulator){
        SpnF << "const TR_PL_ID* SPN::"<< name << "[] = {";
    } else SpnF << "const int* SPN::"<< name << "[] = {";
    for (size_t t = 0; t < vect.size(); t++) {
        if(t != 0)SpnF << ", ";
        if(vect[t].size()>0){ SpnF << "PE_"<<name<<"_"<< t;
        } else SpnF << "EMPTY_array";
    }
    SpnF << "};"<< endl;
	SpnF << endl;
}

void Gspn_Writer::writeEnabledDisabled(ofstream &SpnF)const{
	vector< set<int> > PossiblyEnabled;
	vector< set<int> > PossiblyDisabled;
	vector< set<int> > FreeMarkDepT;
	
	EnabledDisabledTr(PossiblyEnabled,PossiblyDisabled,FreeMarkDepT);

    if(P.lightSimulator){
        SpnF << "static const TR_PL_ID EMPTY_array[1]={-1};" << endl;
    } else SpnF << "static const int EMPTY_array[1]={-1};" << endl;
	writeUpdateVect(SpnF, "PossiblyEnabled", PossiblyEnabled);
	writeUpdateVect(SpnF, "PossiblyDisabled", PossiblyDisabled);
	writeUpdateVect(SpnF, "FreeMarkDepT", FreeMarkDepT);
}

int Gspn_Writer::varMultiplier(size_t var)const{
	int acc = 1;
	for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end()&& colvar != (MyGspn.colVars.begin() + var); ++colvar) {
		acc *= MyGspn.colClasses[colvar->type].colors.size();
	}
	return acc;
}

template <typename T1>
bool setinclusion(set<T1> s1,set<T1> s2){
	for (typename set<T1>::const_iterator it = s1.begin(); it!= s1.end(); ++it){
		if (s2.find(*it)==s2.end())return false;
	}
	
	return true;
}

/*template <typename T1>
 vector<T1> setofvect(vect<T1> s1){
 for (typename set<T1>::const_iterator it = s1.begin(); it!= s1.end(); ++it){
 if (s2.find(*it)==s2.end())return false;
 }
 
 return true;
 }*/

template <typename T1>
void printset(set<T1> s1){
	cerr<< "{";
	for (typename set<T1>::const_iterator it = s1.begin(); it!= s1.end(); ++it){
		if(it!=s1.begin())cerr << ";";
		cerr << *it;
	}
	cerr << "}";
}

void Gspn_Writer::writeTok(ostream &SpnF,const vector<coloredToken> &ct,const colorDomain &cd)const{
    if(ct.size()==1 && ct[0].field.size()==0){
        SpnF << ct[0].mult;
        return;
    }
    int count = 0;
    SpnF << "(";
    for(auto &sct : ct){
        if (count>0)SpnF << " + ";
        count++;
        SpnF << "(" ;
        if(!cd.isUncolored()){
            if(sct.hasAll)
                SpnF << cd.cname();
            else
                SpnF << cd.tokname();
            SpnF << "(" ;
            for (size_t pr = 0; pr < sct.field.size() ; pr++) {
                const auto cc = MyGspn.colClasses[cd.colorClassIndex[pr]];
                if(pr>0)SpnF << ", ";
                if(sct.Flags[pr]==CT_VARIABLE){
                    SpnF << "b.P->"+MyGspn.colVars[sct.field[pr]].name;
                    if(sct.hasAll)SpnF << ".c0";
                } else if(sct.Flags[pr]== CT_SINGLE_COLOR) {
                    SpnF<<"Color_"<<cc.name<<"_"<<cc.colors[sct.field[pr]].name;
                } else if(sct.Flags[pr]== CT_ALL)
                    //SpnF << 1;
                    SpnF << "Color_" << cc.name <<"_All";

                if(sct.varIncrement[pr] != 0)
                    SpnF << ".next(" << sct.varIncrement[pr] << ")";
            }
            SpnF << ")";
            if( !sct.mult.is_concrete() || sct.mult.intVal != 1) SpnF << " * (" << sct.mult<< ")";
            SpnF << ")";
        }else SpnF << sct.mult<< ")";
    }
    SpnF << ")";
}

void Gspn_Writer::generateStringVal(arcStore& as){
    for(auto &inarcit: as){
        auto &inarc = inarcit.second;
        if (inarc.isMarkDep) {
            stringstream stringval;
            const auto cd = MyGspn.colDoms[MyGspn.placeStruct[inarcit.first.second].colorDom];
            writeTok(stringval, inarc.coloredVal, cd);
            inarc.exprVal = expr(stringval.str());
        }
    }
}

void Gspn_Writer::writeTransition(ofstream & spnF)const{
	size_t nbbinding = 1;
	for (size_t v = 0 ; v < MyGspn.colVars.size(); v++)
		nbbinding *= MyGspn.colClasses[MyGspn.colDoms[MyGspn.colVars[v].type].colorClassIndex[0]].colors.size();

	for (size_t t=0; t < MyGspn.tr; t++ ) {
            if (P.verbose > 7) {
                spnF << "\t\t\t\tstd::cerr << \"TRANSITION " << t << "\" << \" : \\n\";\n";
            }
        if(MyGspn.colVars.size()>0 && !P.is_domain_impl_set){
			spnF << "\t{ ";
                        spnF << "//"<< MyGspn.transitionStruct[t].name << "\n\tabstractBinding bl = Transition["<<t<<"].bindingList[0];\n";
			for (size_t it=0; it < MyGspn.colVars.size(); ++it) {
				if( MyGspn.transitionStruct[t].varDomain.count(it)==0){
					spnF<< "\tbl.P->" << MyGspn.colVars[it].name<<".mult = -1;\n";
				}
			}
                        spnF << "\t\t\tTransition["<<t<<"].bindingList[0] = bl;\n";
                        if (P.verbose > 7) {
                            //spnF << "\t\t\t\tstd::cerr << \"" << t << "\" << \" : \"; \n\t\t\t\tbl.print();\n";
                            spnF << "\t\t\t\tbl.print();\n";
                            spnF << "\t\t\t\tstd::cerr << \"\\n\";\n";
                        }
			spnF << "\twhile(bl.next()){\n";                        
            if(MyGspn.transitionStruct[t].guard.t == Bool && MyGspn.transitionStruct[t].guard.boolVal ){
                spnF << "\t\t{\n";
            } else {
                spnF << "\t\tif(" << MyGspn.transitionStruct[t].guard << "){\n";
            }
			spnF << "\t\t\tbl.idcount = Transition["<<t<<"].bindingList.size();\n";
			spnF << "\t\t\tTransition["<<t<<"].bindingList.push_back( bl );\n";
                        if (P.verbose > 7) {
                            //spnF << "\t\t\t\tstd::cerr << \"" << t << "\" << \" : \"; \n\t\t\t\tbl.print();\n";
                            spnF << "\t\t\t\tbl.print();\n";
                            spnF << "\t\t\t\tstd::cerr << \"\\n\";\n";
                        }
			spnF << "\t\t\tTransition["<<t<<"].bindingLinkTable[bl.idTotal()]= Transition["<<t<<"].bindingList.size()-1; "<< endl;
			spnF << "\t\t}\n\t}}\n";
		}
        if (P.verbose > 7) {
            spnF << "\tstd::cerr << \"\\n\\n\";\n";
        }
	}
}

void Gspn_Writer::writeVariable(ofstream & spnF)const{
	for (size_t v = 0 ; v < MyGspn.colVars.size(); v++) {
		spnF << "\t" << MyGspn.colDoms[MyGspn.colVars[v].type].cname();
		spnF << " " << MyGspn.colVars[v].name << ";\n";
	}
}

void Gspn_Writer::writeDotFile(const string &file)const{
    ofstream df(file.c_str(), ios::out | ios::trunc);
    df << "digraph G {" << endl;

    for (const auto &p : MyGspn.placeStruct ) {
        df << "\t" << p.name;
        df << " [xlabel=\""<< p.name;
        df <<"\",label=\"$"<< p.name << "$\"];" << endl;
    }

    for (const auto &t : MyGspn.transitionStruct ) {
        df << "\t" << t.name;
        df << " [shape=rect,height=0.2,style=filled,fillcolor=$CF_";
        df << t.name << "$ ,xlabel=\"" << t.name << "\",label=\"\"];"<< endl;
    }

    for (auto &p : MyGspn.placeStruct )
        for(auto &t : MyGspn.transitionStruct){
            const auto ia = MyGspn.access(MyGspn.inArcsStruct, t.id, p.id);
            if(! ia.isEmpty) {
                df << "\t" << p.name << "->" << t.name;
                df << " [label=\""<< ia.exprVal << " \"];" << endl;
            }
            const auto oa = MyGspn.access(MyGspn.outArcsStruct, t.id, p.id);
            if(! oa.isEmpty) {
                df << "\t" <<  t.name <<"->" << p.name ;
                df << " [label=\""<< oa.exprVal << " \"];" << endl;
            }
            const auto iha = MyGspn.access(MyGspn.inhibArcsStruct, t.id, p.id);
            if(! iha.isEmpty) {
                df << "\t" << p.name << "->" << t.name;
                df << " [arrowhead=odot,label=\""<< iha.exprVal << " \"];" << endl;
            }
        }
    df << "}" << endl;
}

void Gspn_Writer::writeMacro(ofstream &f)const{
    for( auto &p : MyGspn.placeStruct)
        f << "#define PL_"<< p.name << "_LP " << p.id <<endl;
    for( auto &t : MyGspn.transitionStruct)
        f << "#define TR_"<< t.name << "_RT " << t.id <<endl;
    f<< endl;
}


void Gspn_Writer::writeMarkingUpdateIn(stringstream &f,const arcStore &as, size_t t,const place &p , size_t t2, bool pos, const arcStore &as2, bool direct)const{
    if (!MyGspn.access(as,t2,p.id).isEmpty) {
        if(!MyGspn.access(as2,t,p.id).isMarkDep && !MyGspn.access(as,t2,p.id).isMarkDep){
            int decrement = MyGspn.access(as2,t,p.id).exprVal.intVal;
            int seuil = MyGspn.access(as,t2,p.id).exprVal.intVal;
            if(seuil-decrement >0){
                f << "\t\t\tif(Marking.P->_PL_" << p.name <<" < "<< seuil+ (direct? decrement: 0);
                f << " && Marking.P->_PL_" << p.name <<"+"<< (direct? 0: decrement)<<" >=" << seuil <<")";
                f << "TransitionConditions["<< t2 << (pos? "]++ ;":"]-- ;") << endl;
            } else
                f << "\t\t\tif(Marking.P->_PL_" << p.name <<" < "<< seuil+(direct? decrement: 0) << ")TransitionConditions["<< t2 << (pos? "]++ ;":"]-- ;") << endl;
        } else {
            string decrement;
            searchreplace(MyGspn.access(as2,t,p.id).exprVal.stringVal, "Marking.P->_PL_", "tmpMark_" , decrement);
            string seuil;
            searchreplace(MyGspn.access(as,t2,p.id).exprVal.stringVal, "Marking.P->_PL_", "tmpMark_" , seuil);

            f << "\t\t\tif(Marking.P->_PL_" << p.name << (direct? "": "+"+decrement) <<" >= "<< seuil;
            f << " && Marking.P->_PL_" << p.name <<" < " << seuil << (direct? "+"+decrement: "") <<")";
            f << "TransitionConditions["<< t2 <<(pos? "]++ ;":"]-- ;") << endl;
        }
    }
}

void Gspn_Writer::writeMarkingUpdate(stringstream &f, size_t t,const place &p,const arcStore &as2,bool direct)const{

    if(P.localTesting)for (size_t t2 = 0; t2 < MyGspn.tr; t2++) {
        if (!MyGspn.access(MyGspn.inArcsStruct,t2,p.id).isEmpty)
            writeMarkingUpdateIn(f, MyGspn.inArcsStruct, t, p, t2, direct  ,as2,direct);

        if (!MyGspn.access(MyGspn.inhibArcsStruct,t2,p.id).isEmpty)
            writeMarkingUpdateIn(f, MyGspn.inhibArcsStruct, t, p, t2, !direct ,as2,direct);
    }
    string decrement;
    if (MyGspn.access(as2,t,p.id).isMarkDep) {
        searchreplace(MyGspn.access(as2,t,p.id).exprVal.stringVal, "Marking.P->_PL_", "tmpMark_" , decrement);
    }else{
        decrement = to_string(MyGspn.access(as2,t,p.id).exprVal.intVal);
    }
    f << "\t\t\tMarking.P->_PL_" << p.name << (direct? " -= " : " += ") << decrement << ";"<< endl;
}


void Gspn_Writer::writeGetDistParameters(ofstream &f)const{
    writeFunT(f, "void", "GetDistParameters(", ")const",
              [&](unsigned int t,stringstream &newcase){
                  if (MyGspn.transitionStruct[t].type == Timed) {
                      newcase << "\t{" << endl;
                      if (MyGspn.transitionStruct[t].singleService)
                          for (size_t i = 0; i < MyGspn.transitionStruct[t].dist.Param.size(); i++) {
                              newcase << "\t\tParamDistr[" << i << "]= ( double ) " << MyGspn.transitionStruct[t].dist.Param[i] << ";" << endl;
                          } else {
                              newcase << "\t\tdouble EnablingDegree = INT_MAX; " << endl;
                              bool AtLeastOneMarkDepArc = false;
                              for (const auto &p : MyGspn.placeStruct)
                                  if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty) {
                                      if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isMarkDep)
                                          newcase << "\t\tEnablingDegree=min(floor(Marking.P->_PL_" << p.name <<"/(double)(" << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.intVal << ")),EnablingDegree);" << endl;
                                      else {
                                          AtLeastOneMarkDepArc = true;
                                          newcase << "\t\tif(" << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << ">0)" << endl;
                                          newcase << "\t\t\tEnablingDegree=min(floor(Marking.P->_PL_" << p.name <<"/(double)(" << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << ")),EnablingDegree);" << endl;
                                      }
                                  }
                              if (AtLeastOneMarkDepArc) {
                                  if (MyGspn.transitionStruct[t].nbServers >= INT_MAX) {
                                      newcase << "\t\t\tif(EnablingDegree < INT_MAX ) ParamDistr[0] = EnablingDegree * ( " << MyGspn.transitionStruct[t].dist.Param[0] << " );" << endl;
                                      newcase << "\t\t\telse ParamDistr[0] = " << MyGspn.transitionStruct[t].dist.Param[0] << " ;" << endl;
                                  } else {
                                      newcase << "\t\t\tif(EnablingDegree < INT_MAX ) P[0] = min(EnablingDegree , " << MyGspn.transitionStruct[t].nbServers << " ) * ( " << MyGspn.transitionStruct[t].dist.Param[0] << " );" << endl;
                                      newcase << "\t\t\telse ParamDistr[0] = " << MyGspn.transitionStruct[t].dist.Param[0] << " ;" << endl;
                                  }
                              } else {
                                  if (MyGspn.transitionStruct[t].nbServers >= INT_MAX)
                                      newcase << "\t\t\tParamDistr[0] = EnablingDegree  * ( " << MyGspn.transitionStruct[t].dist.Param[0] << " );" << endl;
                                  else
                                      newcase << "\t\t\tParamDistr[0] = min(EnablingDegree , " << MyGspn.transitionStruct[t].nbServers << " ) * ( " << MyGspn.transitionStruct[t].dist.Param[0] << " );" << endl;
                              }
                          }
                      newcase << "\t}" << endl;
                  }
                  }, "using namespace hybridVar;\n");
}

void Gspn_Writer::writeIsEnabled(ofstream &f)const{
    writeFunT(f, "bool", "IsEnabled(", ")const",
              [&](unsigned int t,stringstream &newcase){
                  if(P.localTesting){
                      newcase << "\treturn (TransitionConditions[t]==0);" << endl;
                  } else {
                      newcase<<endl;
                      for (const auto &p : MyGspn.placeStruct) {
                          if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty && !MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isEmpty)
                              if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isMarkDep && !MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isMarkDep)
                                  if (MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.intVal+1 == MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.intVal) {
                                      newcase << "\t\t\tif( Marking.P->_PL_" << p.name <<" != " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.intVal << ") return false;" << endl;
                                      continue;
                                  }
                          if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty) {

                              if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isMarkDep)
                                  newcase << "\t\t\tif (!(contains(Marking.P->_PL_" << p.name <<" , " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.intVal << "))) return false;" << endl;
                              else {
                                  newcase << "\t\t\tif ( !(" << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << " < 1)) " << endl;
                                  newcase << "\t\t\tif (!(contains(Marking.P->_PL_" << p.name <<" , " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << "))) return false;" << endl;
                              }
                          }
                          if (!MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isEmpty) {

                              if (!MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isMarkDep)
                                  newcase << "    if (Marking.P->_PL_" << p.name <<" >= " << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.intVal << ") return false;" << endl;

                              else {
                                  newcase << "    if ( !(" << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.stringVal << " < 1) ) " << endl;
                                  newcase << "        if (contains(Marking.P->_PL_" << p.name <<" , " << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.stringVal << ")) return false;" << endl;
                              }
                          }
                      }
                      newcase << "\t\treturn true;";
                  }
              },(!P.magic_values.empty() ? "\tif(!magicConditional(t))return false;\n":""));
}

void Gspn_Writer::writeFire(ofstream &f)const{
    stringstream preamble;
    preamble << "\tlastTransition = t;" << endl;
    if(!P.magic_values.empty()){
        preamble << "\tmagicUpdate(t,time);" << endl;
    }
    if(!MyGspn.hybridVars.empty()){
        preamble << "\tdouble incrtime = time - lastTransitionTime;" << endl;
        preamble << "\tlastTransitionTime = time;" << endl;
        for(const auto &v:MyGspn.hybridVars)
            if (v.type == CV_CLOCK)
                preamble << "\thybridVar::" << v.name << "+= incrtime;" << endl;
    }

    writeFunT(f, "void", "fire(", ",REAL_TYPE time)",
              [&](unsigned int t,stringstream &newcase){
                newcase << "{" << endl;

                  //Write value of Marking dependant place to a temporary variable
                  for (const auto &p : MyGspn.placeStruct) {
                      if (MyGspn.access(MyGspn.inArcsStruct,t,p.id).isMarkDep || MyGspn.access(MyGspn.outArcsStruct,t,p.id).isMarkDep) {
                          newcase << "\t\t\t"<< MyGspn.colDoms[p.colorDom].cname() <<" tmpMark_" << p.name;
                          newcase << " = Marking.P->_PL_" << p.name << ";" << endl;
                      }
                  }

                  //update the marking
                  for (const auto &p : MyGspn.placeStruct) {
                      if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty) {
                          //update for place in place
                          writeMarkingUpdate(newcase, t, p,MyGspn.inArcsStruct,true);
                      }

                      if (!MyGspn.access(MyGspn.outArcsStruct,t,p.id).isEmpty) {
                          //update for outplace
                          writeMarkingUpdate(newcase, t, p,MyGspn.outArcsStruct,false);
                      }

                  }
                  const auto &ts = MyGspn.transitionStruct[t];
                  if(!ts.update.empty()){
                        newcase << "{using namespace hybridVar;" <<endl << ts.update << "}" << endl;
                  }
                  newcase << "\t}";
              },
              preamble.str()
              );

    if(!P.lightSimulator){
        writeFunT(f, "void", "unfire(", ")", [&](unsigned int t,stringstream &newcase){
            if(P.RareEvent || P.computeStateSpace){
                //update the marking
                for (const auto &p : MyGspn.placeStruct) {
                    if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty) {
                        //update for place in place
                        writeMarkingUpdate(newcase, t, p,MyGspn.inArcsStruct,false);
                    }
                    
                    if (!MyGspn.access(MyGspn.outArcsStruct,t,p.id).isEmpty) {
                        //update for outplace
                        writeMarkingUpdate(newcase, t, p,MyGspn.outArcsStruct,true);
                    }
                    
                }
            }
        });

        if (P.is_domain_impl_set) { writeEnabledDisabledBindingSet(f); }
            else { writeEnabledDisabledBinding(f); }
    }
}


void Gspn_Writer::writeSetConditionsVector(ofstream &f)const{
    f << "void "<< objName <<"setConditionsVector(){" << endl;
    if(P.localTesting)for (size_t t = 0; t < MyGspn.tr; t++) {
        f << "\tTransitionConditions["<< t <<"]=0;" << endl;
        for (const auto &p : MyGspn.placeStruct)  {
            if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isEmpty) {
                if (!MyGspn.access(MyGspn.inArcsStruct,t,p.id).isMarkDep)
                    f << "\tif (Marking.P->_PL_" << p.name <<" < " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.intVal << ")TransitionConditions["<< t <<"]++;" << endl;
                else {
                    f << "\tif ( " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << "> 0) " << endl;
                    f << "\t\tif (Marking.P->_PL_" << p.name <<" < " << MyGspn.access(MyGspn.inArcsStruct,t,p.id).exprVal.stringVal << ")TransitionConditions["<< t <<"]++;" << endl;
                }
            }
            if (!MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isEmpty) {
                if (!MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).isMarkDep)
                    f << "\tif (Marking.P->_PL_" << p.name <<" >= " << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.intVal << ")TransitionConditions["<< t <<"]++;" << endl;
                else {
                    f << "\tif ( " << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.stringVal << " > 0 ) " << endl;
                    f << "\t\tif (Marking.P->_PL_" << p.name <<" >= " << MyGspn.access(MyGspn.inhibArcsStruct,t,p.id).exprVal.stringVal << ")TransitionConditions["<< t <<"]++;" << endl;
                }
            }
        }
    }
    f << "}" << endl;
}

void Gspn_Writer::writeGetPriority(ofstream &f)const{
    writeFunT(f, "REAL_TYPE","GetPriority(", ")const",
              [&](unsigned int t,stringstream &ss){
                  ss << "\t\treturn (double)" << MyGspn.transitionStruct[t].priority << ";";
            }, "using namespace hybridVar;\n");
}


void Gspn_Writer::writeGetWeight(ofstream &f)const{
    writeFunT(f, "REAL_TYPE","GetWeight(", ")const",
              [&](unsigned int t,stringstream &ss){
                ss << "\t\treturn (double)" << MyGspn.transitionStruct[t].weight << ";";
            }, "using namespace hybridVar;\n");
}

void Gspn_Writer::writeMarkingClasse(ofstream &SpnCppFile,ofstream &header)const{
    header << "class abstractBindingImpl {\npublic:\n";
    for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) {
        header << "\t" << MyGspn.colDoms[colvar->type].tokname() << " " << colvar->name << ";\n";
    }
    header << "};\n";

    header << "class abstractMarkingImpl {\n";
    header << "public:\n";

    for (vector<place>::const_iterator plit = MyGspn.placeStruct.begin();
         plit!= MyGspn.placeStruct.end(); ++plit) {

        header << "\t"<< MyGspn.colDoms[plit->colorDom].cname() << " _PL_"<< plit->name << ";\n";

    }
    writeVariable(header);
    header << "};\n";

    SpnCppFile << "\n";
    SpnCppFile << "void abstractMarking::resetToInitMarking(){\n";
    if(!P.magic_values.empty()){
        SpnCppFile << "\tmagicReset();" << endl;
    }
    for (const auto &plit : MyGspn.placeStruct) {
        SpnCppFile << "\tP->_PL_"<< plit.name << " =" << plit.Marking << ";\n";
    }
    if (!MyGspn.hybridVars.empty()) {
        for(const auto &v:MyGspn.hybridVars)
            SpnCppFile << "\thybridVar::" << v.name << "=" << v.initialValue << ";" << endl;
    }

    SpnCppFile << "}\n";
    SpnCppFile << "\n";
    SpnCppFile << "\n";

    SpnCppFile << "abstractMarking::abstractMarking() {\n";
    SpnCppFile << "\tP= new abstractMarkingImpl;\n";
    SpnCppFile << "\tresetToInitMarking();\n";
    SpnCppFile << "}\n";
    SpnCppFile << "\n";
    if(!P.lightSimulator){
        SpnCppFile << "abstractMarking::abstractMarking(const std::vector<int>& m) {\n";
        SpnCppFile << "\tP = new abstractMarkingImpl;\n";
        SpnCppFile << "\tsetVector(m);\n";
        SpnCppFile << "}\n";
        SpnCppFile << "abstractMarking::abstractMarking(const abstractMarking& m) {\n";
        SpnCppFile << "\tP= new abstractMarkingImpl;\n";
        SpnCppFile << "\t*this = m;\n";
        SpnCppFile << "};\n";
        SpnCppFile << "\n";
        SpnCppFile << "abstractMarking& abstractMarking::operator = (const abstractMarking& m) {\n";
        SpnCppFile << "\t*P = *(m.P);\n";
        SpnCppFile << "\treturn *this;\n";
        SpnCppFile << "}\n";
        SpnCppFile << "\n";
    }
    SpnCppFile << "abstractMarking::~abstractMarking() {\n";
    SpnCppFile << "\tdelete(P);\n";
    SpnCppFile << "}\n";
    SpnCppFile << "\n";
    SpnCppFile << "\n";
    if(!P.lightSimulator){
        SpnCppFile << "void abstractMarking::swap(abstractMarking& m) {\n";
        SpnCppFile << "\tabstractMarkingImpl* tmp = m.P;\n";
        SpnCppFile << "\tm.P = P;\n";
        SpnCppFile << "\tP = tmp;\n";
        SpnCppFile << "}\n";
    }

    size_t maxNameSize =5;
    for (const auto &plit : MyGspn.placeStruct)
        if (plit.isTraced)
            maxNameSize = max(maxNameSize, plit.name.length());
    vector<place> plitcp((MyGspn.placeStruct.size()));

    auto it = copy_if(MyGspn.placeStruct.begin(), MyGspn.placeStruct.end(), plitcp.begin(), [](const place &plit){
        return plit.isTraced;
    });
    plitcp.resize(distance(plitcp.begin(),it));


    sort(plitcp.begin(), plitcp.end(), [&](const place &p1, const place &p2){
        if (P.tracedPlace.count(p1.name)>0 && P.tracedPlace.count(p2.name)>0){
            const auto i1= P.tracedPlace.at(p1.name);
            const auto i2= P.tracedPlace.at(p2.name);
            return i1 < i2;
        } else return false;
    });

    if(P.lightSimulator){
        if(P.StringInSpnLHA){
            SpnCppFile << "void abstractMarking::printHeader()const{\n";
            if(P.StringInSpnLHA)
                for (const auto &plit : plitcp)
                    SpnCppFile << "::print(\"" << plit.name << "\t\");"<<endl;
            SpnCppFile << "}\n";
            SpnCppFile << "\n";
            SpnCppFile << "void abstractMarking::print()const{\n";
            if(P.StringInSpnLHA){
                for (const auto &plit : plitcp){
                    SpnCppFile << "print_magic(P->_PL_"<< plit.name << ");"<<endl;
                    SpnCppFile << "::print(\"\t\");"<<endl;
                }
            }
            SpnCppFile << "}\n";
        }
    } else {
        SpnCppFile << "void abstractMarking::printHeader(ostream &s)const{\n";
        if(P.StringInSpnLHA){
            for (const auto &plit : plitcp)
                if (plit.isTraced){
                    SpnCppFile << "s << ";
                    SpnCppFile << " setw(" << maxNameSize << ") << ";
                    SpnCppFile << "\"" <<plit.name  << " \";"<<endl;
                }
            for (const auto &v : MyGspn.hybridVars)
                if(v.isTraced){
                    SpnCppFile << "s << ";
                    SpnCppFile << " setw(" << maxNameSize << ") << ";
                    SpnCppFile << "\"" << v.name  << "\";"<<endl;
                }

        }
        SpnCppFile << "}\n";
        SpnCppFile << "\n";

        SpnCppFile << "void abstractMarking::print(ostream &s,double eTime)const{\n";
        if(P.StringInSpnLHA){
            //SpnCppFile << "\tstd::cerr << \"Marking:\"<< std::endl;\n";
            for(const auto &plit : plitcp)
                if (plit.isTraced){
                    SpnCppFile << "\ts << ";
                    SpnCppFile << " setw(" << maxNameSize-1 << ") << ";
                    if (not P.use_magic_print){ SpnCppFile << "P->_PL_"<< plit.name << "<<\" \";\n";
                    }else{ SpnCppFile << "print_magic(P->_PL_"<< plit.name << ")<<\" \";\n";
                    }
                }
            for (const auto &v : MyGspn.hybridVars)
                if(v.isTraced){
                SpnCppFile << "s << ";
                SpnCppFile << " setw(" << maxNameSize-1 << ") ";
                SpnCppFile << " << hybridVar::"<< v.name  <<"+ eTime <<\" \";"<<endl;
            }
        }
        SpnCppFile << "}\n";
    }


    if(!P.lightSimulator){
        SpnCppFile << "void abstractMarking::printSedCmd(ostream &s)const{\n";
        if(P.StringInSpnLHA){
            //SpnCppFile << "\tstd::cerr << \"Marking:\"<< std::endl;\n";
            for (const auto &plit : MyGspn.placeStruct){
                SpnCppFile << "\ts << \"-e 's/\\\\$"<< plit.name <<"\\\\$/\";"<< endl;
                if(not P.use_magic_print){
                    SpnCppFile << "\ts << P->_PL_"<< plit.name << ";"<<endl;
                } else {
                    SpnCppFile << "\ts << print_magic(P->_PL_"<< plit.name << ");"<<endl;
                }
                SpnCppFile << "\ts <<\"/g' \";"<<endl;
            }
        }
        SpnCppFile << "}\n";

        SpnCppFile << "\n";
        SpnCppFile << "int abstractMarking::getNbOfTokens(int p)const {\n";
        if(MyGspn.isColored() || P.lightSimulator){
            SpnCppFile << "\texit(EXIT_FAILURE);\n";
        }else{
            SpnCppFile << "\tswitch (p) {\n";
            for (const auto &plit : MyGspn.placeStruct) {
                SpnCppFile << "\t\tcase "<< plit.id << ": return P->_PL_"<< plit.name << ";\n";
            }
            SpnCppFile << "     }\n";
        }
        SpnCppFile << "}\n";
        SpnCppFile << "\n";        
        SpnCppFile << "std::vector<int> abstractMarking::getVector()const {\n";
        if( P.lightSimulator || P.is_domain_impl_set){
            SpnCppFile << "\texit(EXIT_FAILURE);\n";
        }else{
            SpnCppFile << "\tstd::vector<int> v("<< markingSize <<");" << endl;
            SpnCppFile << "\tv.reserve("<< markingSize +1<<");" << endl;
            SpnCppFile << "\tsize_t i = 0;" << endl;
            for (let plit : MyGspn.placeStruct) {
                if(plit.colorDom == UNCOLORED_DOMAIN ){SpnCppFile << "\tv[i++]= P->_PL_"<< plit.name << ";"<< endl;}
                else SpnCppFile << "\ti= P->_PL_"<< plit.name << ".copyVector(v,i);"<< endl;
            }
            //SpnCppFile << "\tcopy((int*) P,(int*)P + "<< markingSize <<",v.data() );"<< endl;
            SpnCppFile << "     return v;\n";
        }
        SpnCppFile << "}\n";
        SpnCppFile << "\n";
        SpnCppFile << "void abstractMarking::setVector(const std::vector<int>&v) {\n";
        if(P.lightSimulator){
            SpnCppFile << "\texit(EXIT_FAILURE);\n";
        }else{
            SpnCppFile << "\tsize_t i = 0;" << endl;
            for (let plit : MyGspn.placeStruct) {
                if(plit.colorDom == UNCOLORED_DOMAIN ){SpnCppFile << "\tP->_PL_"<< plit.name << " = v[i++];"<< endl;}
                else SpnCppFile << "\ti= P->_PL_"<< plit.name << ".setVector(v,i);"<< endl;
            }
        }
        SpnCppFile << "};"<<endl<<endl;
        
        
        SpnCppFile << "void abstractMarking::Symmetrize(){" << endl;
        if(P.lumpStateSpace)
        for (size_t cci=0 ; cci<MyGspn.colClasses.size(); cci++) {
            let cc = MyGspn.colClasses[cci];
            SpnCppFile << "\t{"<< endl;
            SpnCppFile << "\tconst vector<contains_"<< cc.cname()<< "* > vClasse = {" << endl;
            for(let plit: MyGspn.placeStruct){
                let cciv = MyGspn.colDoms[plit.colorDom].colorClassIndex;
                if( count(cciv.begin(), cciv.end(), cci )>0 )
                    SpnCppFile << "\t\t&(P->_PL_"<<plit.name << ")," << endl;
            }
            SpnCppFile << "\t\t};" << endl;
            
            SpnCppFile << "\t\tconst vector<size_t> v = getPerm(vClasse, Color_"<< cc.name <<"_Total);"<< endl;
            SpnCppFile << "\t\tapplyPerm(vClasse, Color_"<< cc.name <<"_Total, v);"<<endl;
            SpnCppFile << "\t}"<< endl;
        }
        SpnCppFile << "}";

        

        SpnCppFile << "bool abstractBinding::next() {\n";
        SpnCppFile << "\tidcount++;\n";
        for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) {
            SpnCppFile << "\tif(P->" << colvar->name << ".mult >= 0){\n";
            SpnCppFile << "\t\tif (! P->"<< colvar->name << ".islast()){";
            SpnCppFile << "\tP->"<< colvar->name << ".iter(); return true; };\n";
            SpnCppFile << "\t\tP->"<< colvar->name << " = "<< MyGspn.colDoms[colvar->type].tokname() << "();\n";
            SpnCppFile << "\t}\n";
        }
        SpnCppFile << "\treturn false;\n};\n";


        SpnCppFile << "abstractBinding::abstractBinding() {\n";
        if(MyGspn.isColored())SpnCppFile << " P= new abstractBindingImpl;\n";
        SpnCppFile << "       idcount=0;\n";
        SpnCppFile << "}\n";

        SpnCppFile << "abstractBinding::abstractBinding(const abstractBinding& m) {\n";
        if(MyGspn.isColored())SpnCppFile << " P= new abstractBindingImpl;\n";
        if(MyGspn.isColored())SpnCppFile << " *P = *m.P;\n";
        SpnCppFile << "\tidcount = m.idcount;\n";
        SpnCppFile << "}\n";

        SpnCppFile << "abstractBinding::~abstractBinding() {\n";
        if(MyGspn.isColored())SpnCppFile << " delete P;\n";
        SpnCppFile << "}\n";

        SpnCppFile << "abstractBinding& abstractBinding::operator = (const abstractBinding& m) {\n";
        if(MyGspn.isColored())SpnCppFile << " *P = *m.P;\n";
        SpnCppFile << "\tidcount = m.idcount;\n";
        SpnCppFile << "       return *this;\n";
        SpnCppFile << "}\n";

        SpnCppFile << "void abstractBinding::print()const{\n";
        //SpnCppFile << "\tstd::cerr << \"Binding:\"<< std::endl;\n";
        for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) {
            
            SpnCppFile << "\tstd::cerr << \"\\t"<< colvar->name <<": \";";
            SpnCppFile << "P->"<< colvar->name << ".print(std::cerr);\n"; //\tcerr << endl;\n
        }
        SpnCppFile << "}\n";

        SpnCppFile << "int abstractBinding::id()const{\n";
        /*for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) {
         SpnCppFile << "\tstd::cerr << \"\\t"<< colvar->name <<": \";";
         SpnCppFile << "P->"<< colvar->name << ".print();\n\tcerr << endl;\n";
         }*/
        SpnCppFile << "\treturn idcount;\n}\n";

        SpnCppFile << "int abstractBinding::idTotal()const{\n";
        SpnCppFile << "\t return ";
        for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) {
            SpnCppFile << "P->"<< colvar->name << ".c0 + Color_"<< MyGspn.colDoms[colvar->type].name << "_Total *(";
        }
        SpnCppFile << "0";
        for (vector<colorVariable>::const_iterator colvar = MyGspn.colVars.begin() ; colvar != MyGspn.colVars.end(); ++colvar) SpnCppFile << ")";
        
        SpnCppFile << ";\n}\n";
    }

}

void Gspn_Writer::writeFile(){
	
	string Pref = P.tmpPath;
	string loc;

    generateStringVal(MyGspn.inArcsStruct);
    generateStringVal(MyGspn.outArcsStruct);
    generateStringVal(MyGspn.inhibArcsStruct);
    for(auto &p: MyGspn.placeStruct){
        stringstream ss;
        writeTok(ss, p.initMarking,MyGspn.colDoms[p.colorDom]);
        p.Marking = ss.str();
    }

	//loc = Pref + "../SOURCES/Cosmos/spn.cpp";
	loc = Pref + "/spn.cpp";

	//loc= "/Users/barbot/Documents/Cosmos/SOURCES/Cosmos/spn.cpp";
	ofstream SpnCppFile(loc.c_str(), ios::out | ios::trunc);
	// ouverture en écriture avec effacement du SpnCppFile ouvert
	//cout << loc << endl;
	string headerloc = Pref + "/markingImpl.hpp";
	ofstream header(headerloc.c_str(), ios::out | ios::trunc);
	header << "#ifndef _MarkingImpl_HPP" << endl;
	header << "#define    _MarkingImpl_HPP" << endl;

    if(P.lightSimulator){
        loc = Pref + "/macro.h";
        ofstream macroF(loc.c_str(),ios::out | ios::trunc);
        macroF << "#define NB_EVENT " << MyGspn.tr << endl;
        if(!P.StringInSpnLHA)macroF << "#define NO_STRING_SIM" <<endl;
        macroF << "#define FAST_SIM" << endl;
        macroF << "#define TR_PL_ID unsigned char" << endl;
        macroF << "#define REAL_TYPE float" << endl;
        macroF << "#define VERBOSE_LEVEL " << P.verbose << endl;

        macroF << "#define uint8 unsigned char" << endl;
        macroF << "#define uint16 unsigned int" << endl;
        macroF << "#define uint32 unsigned long" << endl;
        macroF.close();
    }
	
	//SpnCppFile << "#include \"spn_orig.hpp\"" << endl;
    if(P.lightSimulator){
        SpnCppFile << "#include \"spnLight.hpp\"" << endl;
    }else{
        SpnCppFile << "#include \"spn.hpp\"" << endl;
    }
    if(!P.lightSimulator){
        SpnCppFile << "#include <iomanip>" << endl;
        header << "using namespace std;" <<endl;
        SpnCppFile << "using namespace std;" <<endl;
    }

	//------------- Writing constant--------------------------------------------
    writeMacro(SpnCppFile);
    for (map<string,double>::iterator it= MyGspn.RealConstant.begin();
		 it!= MyGspn.RealConstant.end() ; it++) {
		SpnCppFile << "const double "<<it->first<<"="<<it->second << ";" << endl;
	}
	for (const auto &plit : MyGspn.placeStruct) {
		SpnCppFile << "const int _nb_Place_"<< plit.name << "=" << plit.id << ";" << endl;
	}

    //------------- Hybrid Variable --------------------------------------------
    SpnCppFile << "namespace hybridVar {" << endl;
    //if (!MyGspn.hybridVars.empty()){
        for(const auto &v:MyGspn.hybridVars)
            SpnCppFile << (v.type == CV_INT? "\tint ":"\tdouble ") << v.name << "=" << v.initialValue << ";" << endl;
    //}
    SpnCppFile << "}" << endl;

	
    if (P.magic_values != "")
        SpnCppFile << "#include \"" << P.magic_values << "\"" << endl;
    if(P.RareEvent){
	SpnCppFile << "#include \"lumpingfun.cpp\"" << endl;
    }else if(!P.lightSimulator){
	SpnCppFile << "void "<<"REHandling::"<<"print_state(const vector<int> &vect){}" << endl;
	SpnCppFile << "void "<<"REHandling::"<<"lumpingFun(const abstractMarking &M,vector<int> &vect){}" << endl;
	SpnCppFile << "bool "<<"REHandling::"<<"precondition(const abstractMarking &M){return true;}" << endl;
    }
    
	//------------- Writing Marking type and header ----------------------------
    if(!P.lightSimulator)SpnCppFile << "#include \"marking.hpp\"\n";
    SpnCppFile << "#include \"markingImpl.hpp\"\n";
    header << "#include <string.h>\n";
	writeMarkingClasse(SpnCppFile,header);
	header << "#endif" << endl;
	header.close();
	
	//------------- Writing Color name -----------------------------------------
	for (vector<colorClass>::const_iterator it = MyGspn.colClasses.begin();
		 it != MyGspn.colClasses.end(); ++it ) {
		SpnCppFile << "const char *Color_"<< it->name << "_names[Color_" << it->name << "_Total] = {\n";
		for (vector<color>::const_iterator it2 = it->colors.begin();
			 it2 != it->colors.end(); ++it2 ) {
			SpnCppFile << "\"" << it2->name << "\",";
		}
		SpnCppFile << "\n};\n";
	}

    
    //------------ Writing polynomials ------------------------------------------
    if(!P.lightSimulator && !MyGspn.distribStruct.empty()){
        if(!userDefineDistribution::polyfile.empty()){
            writePolynome(SpnCppFile);
        }else{
            writeUserDefineDistr(SpnCppFile);
        }
    }



    //--------------- Writing synchronization tables ---------------------------
    //if(!P.lightSimulator)
    writeEnabledDisabled(SpnCppFile);

    //--------------- Writing transitions tables -------------------------------
    if(!P.lightSimulator){
        size_t nbbinding = 1;
        for (size_t v = 0 ; v < MyGspn.colVars.size(); v++)
            nbbinding *= MyGspn.colClasses[MyGspn.colDoms[MyGspn.colVars[v].type].colorClassIndex[0]].colors.size();
        SpnCppFile << "static spn_trans TransArray[" << MyGspn.tr << "] = { ";
        for (size_t t=0; t < MyGspn.tr; t++ ) {
            SpnCppFile << "_trans(" << t << ",";

            if (MyGspn.transitionStruct[t].type==Timed) {
                SpnCppFile  << MyGspn.transitionStruct[t].dist.name << ",";
            }else{
                SpnCppFile << "IMMEDIATE,";
            }

            if (!P.is_domain_impl_set) {
                SpnCppFile << MyGspn.transitionStruct[t].markingDependant << ","<< nbbinding;
            } else {
                SpnCppFile << MyGspn.transitionStruct[t].markingDependant << ",1";
            }
            SpnCppFile << ", " << MyGspn.transitionStruct[t].ageMemory;
            if(P.StringInSpnLHA)SpnCppFile << ", \"" << MyGspn.transitionStruct[t].name<< "\"";
            SpnCppFile <<"), ";
        }
        SpnCppFile << " }; " << endl;
    }

    //--------------- Writing implementation of SPN ----------------------------
    SpnCppFile << objName<<"SPN():" << endl;
    if(!MyGspn.distribStruct.empty()){
        if(!userDefineDistribution::polyfile.empty()){
            SpnCppFile << "customDistr(*(new CustomDistrPoly())),";
        }else{
            SpnCppFile << "customDistr(*(new CustomDistrOverride())),";
        }
    }else{
        SpnCppFile << "customDistr(*(new CustomDistr())),";
    }
    
	SpnCppFile << "pl(" << MyGspn.pl << "), ";
	SpnCppFile << "tr(" << MyGspn.tr << ") ";
    if(!P.lightSimulator){
        SpnCppFile << ",Transition(TransArray,TransArray +"<< MyGspn.tr <<")";
        SpnCppFile << ",Place("<< MyGspn.pl << ")";
        SpnCppFile << ",ParamDistr(10)";
        SpnCppFile << ",TransitionConditions(" << MyGspn.tr <<",0)";
    }

    SpnCppFile << "{" << endl;
	if(!P.lightSimulator)SpnCppFile << "    Path =\"" << P.PathGspn << "\";" << endl;

	
	if(P.localTesting){
		SpnCppFile << "\tsetConditionsVector();"<< endl;
		SpnCppFile << "\tinitTransitionConditions = TransitionConditions;" << endl;
	}
	
	for (const auto &plit : MyGspn.placeStruct) {
        if(P.StringInSpnLHA && !P.lightSimulator){
			SpnCppFile << "    Place[" << plit.id << "].label =\" " << plit.name << "\";" << endl;
			SpnCppFile << "    Place[" << plit.id << "].isTraced = " << plit.isTraced << ";" << endl;
		}
	}
	
	writeTransition(SpnCppFile);
	
	//-------------- Rare Event -----------------
	if(P.RareEvent || P.computeStateSpace>0){
		SpnCppFile << "\tMsimple();" << endl;
	}
	//------------- /Rare Event -----------------
	
	SpnCppFile << "}\n" << endl;

    if(P.lightSimulator){
        SpnCppFile << "TR_PL_ID SPN::getIncomingTrans(){ return ";
        if(MyGspn.TransId.count("INCOMING_SREC")>0){
            SpnCppFile << "TR_INCOMING_SREC_RT;};\n"<< endl;
        } else {
            SpnCppFile << "UNSET_TRANS;};\n"<< endl;
        }
    }

    writeIsEnabled(SpnCppFile);
    writeFire(SpnCppFile);
    writeSetConditionsVector(SpnCppFile);
    writeGetDistParameters(SpnCppFile);
    writeGetPriority(SpnCppFile);
    writeGetWeight(SpnCppFile);

    if(!P.lightSimulator){
	SpnCppFile << "void "<<objName<<"Msimple(){"<<endl;
	SpnCppFile << "\tvector<int> tab;"<<endl;
	for (const auto &p : MyGspn.placeStruct) {
		if(p.name.substr(0,3).compare("RE_") == 0)
			SpnCppFile << "\t\ttab.push_back("<< p.id << ");" << endl;
	}
	SpnCppFile << "\tMsimpletab = tab;\n}"<< endl;
    }

	SpnCppFile << "void "<<objName<<"reset() {"<< endl;
    SpnCppFile << "\tlastTransitionTime = 0;"<< endl;
	SpnCppFile << "\tMarking.resetToInitMarking();"<< endl;
	if(P.localTesting)SpnCppFile << "\tTransitionConditions = initTransitionConditions;"<< endl;
	SpnCppFile << "}"<< endl<< endl;

	SpnCppFile.close();
}

void Gspn_Writer::writeUserDefineDistr(ofstream &f)const{
    f << "class CustomDistrOverride: public CustomDistr {" << endl;
    f << "public:"<< endl;
    f << "double virtual userDefineCDF(vector<double> const& param, double funvar)const override{" <<endl;
    {
        //f<< "std::cerr << \"test\" << std::endl;"<<endl;
    auto ch = casesHandler("(int)param[0]");
    for (size_t it=0; it<MyGspn.distribStruct.size(); ++it) {
        const auto &dist = MyGspn.distribStruct[it];
        stringstream newcase;
        newcase << "\t{" << endl;
        newcase << "\t\tdouble " << dist.var << " = funvar;" << endl;
        newcase << "\t\treturn (" << dist.cdf << ");" << endl;
        newcase << "\t}" << endl;
        ch.addCase(it , newcase.str(),dist.name);
    }
    ch.writeCases(f);
    f << "}\n" << endl;
    }
    {
    f << "double virtual userDefinePDF(vector<double> const& param, double funvar)const override{" <<endl;
    auto ch = casesHandler("(int)param[0]");
    for (size_t it=0; it<MyGspn.distribStruct.size(); ++it) {
        const auto &dist = MyGspn.distribStruct[it];
        stringstream newcase;
        newcase << "\t{" << endl;
        newcase << "\t\tdouble " << dist.var << " = funvar;" << endl;
        newcase << "\t\treturn (" << dist.pdf << ");" << endl;
        newcase << "\t}" << endl;
        ch.addCase(it , newcase.str(),dist.name);
    }
    ch.writeCases(f);
    f << "}\n" << endl;
    }
    {
    f << "double virtual userDefineLowerBound(vector<double> const& param)const override{" <<endl;
    auto ch = casesHandler("(int)param[0]");
    for (size_t it=0; it<MyGspn.distribStruct.size(); ++it) {
        const auto &dist = MyGspn.distribStruct[it];
        stringstream newcase;
        newcase << "\t\treturn (" << dist.lowerBound << ");" << endl;
        ch.addCase(it , newcase.str(),dist.name);
    }
    ch.writeCases(f);
    f << "}\n" << endl;
    }
    {
    f << "double virtual userDefineUpperBound(vector<double> const& param)const override{" <<endl;
    auto ch = casesHandler("(int)param[0]");
    for (size_t it=0; it<MyGspn.distribStruct.size(); ++it) {
        const auto &dist = MyGspn.distribStruct[it];
        stringstream newcase;
        newcase << "\t\treturn (" << dist.upperBound << ");" << endl;
        ch.addCase(it , newcase.str(),dist.name);
    }
    ch.writeCases(f);
    f << "}\n" << endl;
    }

    {
    f << "double virtual userDefineDiscreteDistr(vector<double> const& param,unsigned int i)const override{" <<endl;
    if( any_of(MyGspn.transitionStruct.begin(),MyGspn.transitionStruct.end(),[](const transition &t){return t.dist.name == "DISCRETEUSERDEFINE";})){
        f << "\treturn (magicUDDD(param,i));" << endl;
    } else {
        f << "\treturn (0.0);" << endl;
    }
    f << "}\n" << endl;
    }
    f << "};" << endl;
}

void Gspn_Writer::writePolynome(ofstream &f)const{
    if(MyGspn.distribStruct.empty())return;
    size_t n = userDefineDistribution::nbparam;
    
    f << "#include \"Polynome.hpp\""<< endl;
    f << "class CustomDistrPoly: public CustomDistr {" << endl;
    f << "\tconst static int poly_table[];" << endl;
    f << "\tvector<Poly<"<<n<<">> ptable;" << endl;
    f << "public:" << endl;
    f << "\tCustomDistrPoly(){" << endl;
    f << "\t\tptable = parse<"<<n<<">(\""<< userDefineDistribution::polyfile <<"\");"<<endl;
    f << "\t}" << endl;

    f << "\tdouble virtual userDefineCDF(vector<double> const& param, double funvar)const{" <<endl;
    //f << "\tparam[0]=funvar;" << endl;
    f << "\t\treturn (eval(ptable[poly_table[ 5*((int)param[0]) ]],param,funvar)/eval(ptable[poly_table[ 5*((int)param[0])+2 ]],param,funvar))  ;"<< endl;
    f << "\t}"<<endl;

    f << "\tdouble  virtual userDefinePDF(vector<double> const& param, double funvar)const{" <<endl;
    //f << "\tparam[0]=funvar;" << endl;
    f << "\t\treturn (eval(ptable[poly_table[ 5*((int)param[0])+1 ]],param,funvar)/eval(ptable[poly_table[ 5*((int)param[0])+2 ]],param,funvar))  ;"<< endl;
    f << "\t}"<<endl;

    {
        f << "\tdouble virtual userDefineLowerBound(vector<double> const& param)const{" <<endl;
        f << "\t\treturn eval(ptable[poly_table[ 5*((int)param[0])+3 ]],param);" << endl;
        f << "\t}\n" << endl;
    }
    {
        f << "\tdouble virtual userDefineUpperBound(vector<double> const& param)const{" <<endl;
        f << "\t\treturn eval(ptable[poly_table[ 5*((int)param[0])+4] ],param);" << endl;
        f << "\t}\n" << endl;
    }
    
    {
        f << "\tdouble virtual userDefineDiscreteDistr(vector<double> const& param,unsigned int i)const{" <<endl;
        if( any_of(MyGspn.transitionStruct.begin(),MyGspn.transitionStruct.end(),[](const transition &t){return t.dist.name == "DISCRETEUSERDEFINE";})){
            f << "\t\treturn (magicUDDD(param,i));" << endl;
        } else {
            f << "\t\treturn (0.0);" << endl;
        }
        f << "\t}\n" << endl;
    }
    
    f << "\tdouble virtual evalPoly(unsigned long i,vector<double> const & param)const {"<< endl;;
    f << "\t\treturn eval(ptable[i],param);"<< endl;
    f << "\t}"<< endl;
    
    f << "};" << endl;
    
    f << "const int CustomDistrPoly::poly_table[]= { " << endl;
    for ( let d : MyGspn.distribStruct) {
        f << d.cdf <<"," ;
        f << d.pdf <<"," ;
        f << d.norm << "," ;
        f << d.lowerBound << "," ;
        f << d.upperBound << "," ;
    }
    f << "};" << endl;
    
}


