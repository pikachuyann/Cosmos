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
 * file Lha_gmlparser.cpp                                                      *
 * Created by Benoit Barbot on 03/11/11.                                       *
 *******************************************************************************
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "Lha_gmlparser.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "../Eval/Eval.hpp"

#include "Lha-Reader.hpp"

//#include "tree.hh"
#include "tree/tree_util.hh"


using namespace std;

gmlinputexception lhagmlioexc;

/*void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end)
 {
 if(!tr.is_valid(it)) return;
 int rootdepth=tr.depth(it);
 while(it!=end) {
 cout << "    ";
 for(int i=0; i<tr.depth(it)-rootdepth; ++i)
 cout << "  ";
 cout << (*it) << endl << flush;
 ++it;
 }
 }*/

string* MyLhaModelHandler::simplifyString(string str)
{
	size_t n1 = str.find_first_not_of(" \n");
	size_t n2 = str.find_last_not_of(" \n");
	if(n1 ==std::string::npos )return new string("");
	return new string(str.substr(n1, n2-n1+1));
}

bool MyLhaModelHandler::is_void(string str)
{
	//int n1 = str.find_first_not_of(" \n");
	//int n2 = str.find_last_not_of(" \n");
	return str.compare("\n");
}

void MyLhaModelHandler::appendSimplify(string *st, string str)
{
	size_t n1 = str.find_first_not_of(" \n");
	size_t n2 = str.find_last_not_of(" \n");
	if(n1 !=std::string::npos )st->append(str.substr(n1, n2-n1+1));
}

/*void evalinfix(string *st, tree<string>::pre_order_iterator it , string str){
 st->append("(");
 for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
 if(it2!= it.begin()) st->append(str);
 eval_expr( st, it2);
 }
 st->append(")");
 }*/

void MyLhaModelHandler::eval_expr(bool *is_mark_dep, string *st, tree<string>::pre_order_iterator it )
{
    
	if(verbose>2)cout << (*it) << endl;
	if((*it).compare("expr")==0){
		eval_expr(is_mark_dep, st, it.begin());
	}else if((*it).compare("boolExpr")==0){
        eval_expr(is_mark_dep, st, it.begin());
    }else if((*it).compare("markingExpr")==0){
		string stmark;
		size_t colDomIndex = eval_marking_expr(stmark, it.begin());
		if (colDomIndex == UNCOLORED_DOMAIN){
			st->append(stmark);
		}else {
			st->append(stmark);
			st->append(".card()");
			//cerr << "Not uncolored type: " << stmark << endl;
		}
		*is_mark_dep = true;
    }else if((*it).compare("function")==0){
        eval_expr(is_mark_dep, st, it.begin());
    }else if((*it).compare("numValue")==0){
		if(verbose>2)cout << "\t" << it.node->first_child->data<<endl;
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("boolValue")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("name")==0) {
        string *var = simplifyString(it.node->first_child->data);
        if(MyLHA->LhaIntConstant.count(*var)>0 ||
           MyLHA->LhaRealConstant.count(*var)>0){st->append(*var);
        }else {
			vector<string>::const_iterator vn = find(MyLHA->Vars.label.begin(), MyLHA->Vars.label.end(), *var);
			if(vn != MyLHA->Vars.label.end()){
				std::ostringstream s; s<<"Vars->"<< *var;
				st->append(s.str());
				
			}else{
				*is_mark_dep =true;
				std::ostringstream s; s<<"Marking.P->_PL_"<<var->c_str()<<" ";
				st->append(s.str());
			}
		}
    }else if (	(*it).compare("+")==0  || (*it).compare("*")==0
			  || (*it).compare("min")==0   || (*it).compare("max")==0
			  || (*it).compare("floor")==0 || (*it).compare("-")==0
			  || (*it).compare("/")==0   || (*it).compare("power")==0
			  || (*it).compare("or")==0   || (*it).compare("and")==0
			  || (*it).compare("not")==0   || (*it).compare("equal")==0
			  || (*it).compare("notEqual")==0   || (*it).compare("greater")==0
			  || (*it).compare("greaterEqual")==0   || (*it).compare("less")==0
			  || (*it).compare("lessEqual")==0 ){
		
		
		if ((*it).compare("min")==0) st->append("min");
		if ((*it).compare("max")==0) st->append("max");
		if ((*it).compare("floor")==0 ) st->append("floor");
		
		st->append("(");
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) {
				if ((*it).compare("+")==0 ) { st->append("+"); }
				else if ((*it).compare("*")==0 ) { st->append("*"); }
				else if ((*it).compare("-")==0 ) { st->append("-"); }
				else if ((*it).compare("/")==0) { st->append("/"); }
				else if ((*it).compare("power")==0) { st->append("^"); }
				else if ((*it).compare("or")==0) { st->append(" || "); }
				else if ((*it).compare("and")==0) { st->append(" && "); }
				else if ((*it).compare("not")==0) { st->append(" !"); }
				else if ((*it).compare("notEqual")==0) { st->append(" !="); }
				else if ((*it).compare("equal")==0) { st->append("=="); }
				else if ((*it).compare("greater")==0) { st->append(">"); }
				else if ((*it).compare("greaterEqual")==0) { st->append(">="); }
				else if ((*it).compare("less")==0) { st->append("<"); }
				else if ((*it).compare("lessEqual")==0) { st->append("<="); }
				else st->append(",");
			}
			eval_expr(is_mark_dep, st, it2);
		}
		st->append(")");
		;
	} else throw(lhagmlioexc);
}

size_t MyLhaModelHandler::eval_marking_expr(string &st, tree<string>::pre_order_iterator it){
	if(verbose>2)cout << "eval_marking_expr:"<< (*it) << endl;
	if(it->compare("markingExpr")==0)
		return eval_marking_expr(st, it.begin());
	else if(it->compare("name")==0){
		string stpl = *simplifyString(*(it.begin()));
		if(MyLHA->MyGspn->PlacesId.count(stpl)>0){
			st.append("Marking.P->_PL_");
			st.append(stpl);
			return MyLHA->MyGspn->placeStruct[MyLHA->MyGspn->PlacesId[stpl]].colorDom;
		} else {
			st.append(stpl);
			return UNCOLORED_DOMAIN;
		}
	} else if(it->compare("selectColor")==0){
		st.append(" ( ");
		size_t colClassCounter =0;
		size_t colDomIndex = (size_t)-1;
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(verbose>2)cout << (*it2) << endl;
			if(it2->compare("markingExpr")==0) colDomIndex = eval_marking_expr(st, it2);
			else if(it2->compare("name")==0){
				string cname = *simplifyString(*(it2.begin()));
				vector<color>::const_iterator itcc;
				colorClass cc = MyLHA->MyGspn->colClasses[MyLHA->MyGspn->colDoms[colDomIndex].colorClassIndex[colClassCounter]];
				for( itcc= cc.colors.begin(); itcc != cc.colors.end() && cname != itcc->name; ++itcc);
				if (itcc == cc.colors.end()) {
					cerr << "unknwon color:" << cname << "for color classe" << cc.name<< endl;
				}else{
					st.append("[ Color_" + cc.name + "_" + itcc->name +" ]");
				}
				colClassCounter++;
			}
		}
		st.append(" ) ");
		return colDomIndex;
	}
}


void MyLhaModelHandler::eval_term(vector<string> &CoeffsVector, tree<string>::pre_order_iterator it){
	if(verbose>2)cout << (*it) << endl;
	if((*it).compare("expr")==0){
		eval_term(CoeffsVector, it.begin());
	}else if((*it).compare("name")==0){
		string* var = simplifyString(*(it.begin()));
		if(verbose>2)cout << "\t" << *var << endl;
		vector<string>::const_iterator vi=find(MyLHA->Vars.label.begin(), MyLHA->Vars.label.end(), *var);
		if(vi!= MyLHA->Vars.label.end())CoeffsVector[vi-MyLHA->Vars.label.begin()]= "1";
		else cout << "Unkown Variable " << *var <<endl;
	}else cout << "fail eval tree : linexp" << endl;
	
}

void MyLhaModelHandler::eval_linexpr(vector<string> &CoeffsVector, tree<string>::pre_order_iterator it){
	if(verbose>2)cout << (*it) << endl;
	if((*it).compare("expr")==0){
		eval_linexpr(CoeffsVector, it.begin());
	}else if((*it).compare("function")==0 && (((*it.begin()).compare("+")==0) || ((*it.begin()).compare("-")==0))){
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			eval_linexpr(CoeffsVector, it2);
		}
	}else eval_term(CoeffsVector, it);
	
}

void MyLhaModelHandler::eval_guard(vector<vector<string> > &CoeffsMatrix,vector<string> &CST, vector<string> &comp,tree<string>::pre_order_iterator it)
{
	if(verbose>2)cout << (*it) << endl;
	if((*it).compare("boolExpr")==0){
        eval_guard(CoeffsMatrix,CST,comp,it.begin());
    }else if ((*it).compare("boolValue")==0) {
		//cout << "\tguard = true" << it.node->first_child->data << endl;
	}else if ((*it).compare("and")==0){
		//cout << "(";
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			eval_guard(CoeffsMatrix,CST,comp,it2);
		}
		//cout << ")";
	}else if((*it).compare("equal")==0
			 || (*it).compare("greaterEqual")==0
			 || (*it).compare("lessEqual")==0 ){
		if((*it).compare("equal")==0)comp.push_back("==");
		if((*it).compare("lessEqual")==0)comp.push_back("<=");
		if((*it).compare("greaterEqual")==0)comp.push_back(">=");
		
		vector<string> CoeffsVector(MyLHA->NbVar,"");
		eval_linexpr(CoeffsVector,it.begin());
		//cout << ";";
		CoeffsMatrix.push_back(CoeffsVector);
		string* st= new string("");
		bool markdep = false;
		eval_expr(&markdep, st, it.begin().node->next_sibling);
		if(verbose>1)cout<< "CST: " << *st << endl;
		CST.push_back(*st);
		
	} else cout << "failevaltree: guard" <<endl;
}


int MyLhaModelHandler::eval_str (string s){
	string* val = simplifyString(s);
	int intval = atoi( (*val).c_str() );
	delete val;
	return intval;
}

int MyLhaModelHandler::eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator it )
{
    if(verbose>2)cout << "intformula: " <<(*it) << endl;
	if((*it).compare("expr")==0){
		return eval_intFormula(intconst,it.begin());
	}else if((*it).compare("numValue")==0){
		return eval_str(it.node->first_child->data);
	}else if ((*it).compare("name")==0) {
		string* val = simplifyString(it.node->first_child->data);
		int intval = intconst[(*val).c_str()];
		delete val;
		return intval;
	}else if ((*it).compare("+")==0 || (*it).compare("*")==0
			  || (*it).compare("min")==0  || (*it).compare("max")==0
			  || (*it).compare("ipower")==0|| (*it).compare("-")==0)  {
		
		int v1=0;
		int v2=0;
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) { v1 = eval_intFormula(intconst, it2);
			} else {
				v2 = eval_intFormula(intconst, it2);
			}
			
		}
		
		if ((*it).compare("+")==0) { return v1+v2; }
		else if ((*it).compare("*")==0) { return v1*v2; }
		else if ((*it).compare("-")==0) { return v1-v2; }
		else if ((*it).compare("min")==0) { return min(v1,v2); }
		else if ((*it).compare("max")==0) {  return max(v1,v2); }
		else if ((*it).compare("power")==0) {  return v1^v2; }
		else throw(lhagmlioexc);
		
	}else throw(lhagmlioexc);
}



MyLhaModelHandler::MyLhaModelHandler(LHA_D* MyLHA2, int v) {
	//Initialisation
    verbose=max(0,v-3);
	MyLHA= MyLHA2;
	MyLHA->NbVar = 0;
	countLoc=0;
	ParseLoc=true;
	//ParseDecl=true;
}
//~MyModelHandler() { }


void MyLhaModelHandler::on_read_model(const XmlString& formalismUrl) {
	// output used formalism
	ParseLoc=true;
	//ParseDecl=true;
	if(verbose>0)cout << "read model : formalism = " << formalismUrl << endl;
}

HaslFormulasTop* MyLhaModelHandler::exportHASLTop(tree<string>::pre_order_iterator it){
	
	if(verbose>2)cout << *it << ":" << endl;
	if((*it).compare("AVG")==0){
		string* lhafunc = exportHASL(it.begin());
        if(verbose>1)cout << *lhafunc << endl;
		stringstream ss;
		ss << "LhaFunc[" << MyLHA->LhaFunction[*lhafunc] << "]";
		MyLHA->Algebraic.push_back( ss.str() );
		return (new HaslFormulasTop(MyLHA->Algebraic.size()-1,MyLHA->ConfidenceLevel));
	} else if(it->compare("PDF")==0 || it->compare("CDF")==0){
		string* lhafunc;
		double deltab = 1;
		double minb =0;
		double maxb =0;
		for(treeSI it2 = it.begin(); it2 != it.end(); it2++){
			if (it2->compare("min")==0)minb = atof(exportHASL(it2)->c_str());
			else if (it2->compare("max")==0)maxb = atof(exportHASL(it2)->c_str());
			else if (it2->compare("delta")==0)deltab = atof(exportHASL(it2)->c_str());
			else lhafunc = exportHASL(it2);
		}
		
        if(verbose>1)cout << *lhafunc << endl;
		stringstream ss;
		ss << "LhaFunc[" << MyLHA->LhaFunction[*lhafunc] << "]";
		
		
		for(double bucket = minb ; bucket < maxb ; bucket+= deltab){
			std::ostringstream algPDF;
			if(it->compare("PDF")==0)
				algPDF << "(("<< ss.str() <<" >= "<<bucket<<"&& "<<ss.str() <<"<"<<bucket+deltab<<") ? 1:0)";
			else
				algPDF << "(("<< ss.str() <<" <= "<<bucket<<") ? 1:0)";
			
			MyLHA->Algebraic.push_back(algPDF.str());
			MyLHA->HASLtop.push_back(new HaslFormulasTop((size_t)MyLHA->Algebraic.size()-1,
															   MyLHA->ConfidenceLevel));
			MyLHA->HASLtop.back()->TypeOp = PDF_PART;
			std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+deltab<<"]";
			MyLHA->HASLname.push_back(s.str());
		}

		return (NULL);
	} else throw(lhagmlioexc);
}

		
string* MyLhaModelHandler::exportHASL(tree<string>::pre_order_iterator it){
	if(verbose>2)cout << *it << ":" << endl;
	if(it->compare("YHF")==0){
		return exportHASL(it.begin());
	}else if(it->compare("delta")==0){
		return simplifyString(*(it.begin()));
	}else if(it->compare("min")==0){
		return simplifyString(*(it.begin()));
	}else if(it->compare("max")==0){
		return simplifyString(*(it.begin()));
	}else if(it->compare("last")==0){
		//cout << *(it.begin()) << endl;
		string* linForm = exportHASL(it.begin());
		const char* linformc = linForm->c_str();
		if(MyLHA->LinearForm.find(linformc)==MyLHA->LinearForm.end()){
			size_t i=MyLHA->LinearForm.size();
			MyLHA->LinearForm[linformc]=i;
		}
		
		MyLHA->LhaFuncArg.push_back(MyLHA->LinearForm[linformc]);
		MyLHA->LhaFuncType.push_back("Last");
		string ss="Last("; ss.append(linformc); ss.append(")");
		if(MyLHA->LhaFunction.find(ss)==MyLHA->LhaFunction.end()){
			size_t i=MyLHA->LhaFunction.size();
			MyLHA->LhaFunction[ss]=i;
		}
		return new string(ss);
		
	}else if((*it).compare("expr")==0){
		return exportHASL(it.begin());
	}else if((*it).compare("name")==0){
		string* var = simplifyString(it.node->first_child->data);
		stringstream ss;
		ss << "Vars->" << *var;
		
		
		return new string(ss.str());
		
	} else throw(lhagmlioexc);
	
}

treeSI findbranchlha(treeSI t, string branch){
    if( branch.compare("")==0)return t;
    size_t nextnode = branch.find_first_of("/");
    for (treeSI it = (t.begin()) ; it != (t.end()) ; ++it) {
        if((*it).compare(branch.substr(0,nextnode))==0){
            return findbranchlha(it, branch.substr(nextnode+1,branch.length()-nextnode-1));
        }
    }
    cerr << "Fail to find branch:" << branch << "in the file\n";
	return t.end();
}

void MyLhaModelHandler::on_read_model_attribute(const Attribute& attribute) {
	// read model attribute
	for(treeSI it = attribute.begin(); it != attribute.end(); ++it) {
		if(verbose>1)cout << *it << ":" << endl;
		if((*it).compare("declaration")==0){
            //cout<< "start int const" << endl;
            treeSI t1 = findbranchlha(it, "constants/intConsts/");
            //cout << "find branch" << endl;
			if (t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					if ((*it2).compare("intConst")==0) {
						//cout << "start intConst" << endl;
						string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						//cout << "finish name:"<< *constname << endl;
						//treeSI test = find(it2.begin(),it2.end(),"expr");
						//cout << "find expr" << endl;
						int constvalue = eval_intFormula(MyLHA->LhaIntConstant,find(it2.begin(),it2.end(),"expr"));
						//cout << "finish expr" << endl;
						//Evaluate_gml.parse(constvalue);
						MyLHA->LhaIntConstant[*constname]=constvalue; //Evaluate_gml.IntResult;
						MyLHA->LhaRealConstant[*constname]= constvalue; //Evaluate_gml.RealResult;
						if(verbose>1)cout << "\tconst int " << *constname << "=" << constvalue << endl;
					}
				}
            //cout << "finished intconst" << endl;
            t1 = findbranchlha(it, "constants/realConsts/");
			if (t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					//cout << "test:" << *it2 << ":"<< endl;
					if ((*it2).compare("realConst")==0) {
						string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						
						bool ismarkdep=false;
						string constvalue;
						eval_expr( &ismarkdep, &constvalue, find(it2.begin(),it2.end(),"expr").begin());
						if(ismarkdep){
							cout<< "constante are not marking dependant!" << endl;
							throw lhagmlioexc;
						}
						Evaluate_gml.parse(constvalue);
						MyLHA->LhaRealConstant[*constname]=Evaluate_gml.RealResult;
						if(verbose>1)cout << "\tconst double " << *constname << "=" << Evaluate_gml.RealResult << endl;
					}
				}
            //cout << "finished realconst" << endl;
            t1 = findbranchlha(it, "variables/reals/");
			if (t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					if ((*it2).compare("real")==0) {
						string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						MyLHA->Vars.label.push_back(*constname);
						MyLHA->Vars.initialValue.push_back(0.0);
						treeSI dom = find(it2.begin(),it2.end(),"domain");
						if (dom != it2.end()) {
							string domname = *simplifyString(*(it2.begin()));
							vector<colorDomain>::const_iterator domit;
							for(domit = MyLHA->MyGspn->colDoms.begin(); domit != MyLHA->MyGspn->colDoms.end() && domit->name != domname; ++domit);
							if(domit != MyLHA->MyGspn->colDoms.end())MyLHA->Vars.colorDomain.push_back(domit - MyLHA->MyGspn->colDoms.begin());
							else cerr << "Unknown color Domain " << domname << endl;
						}else MyLHA->Vars.colorDomain.push_back(0);
						MyLHA->Vars.type.push_back(CONTINIOUS_VARIABLE);
						MyLHA->NbVar++;
						
						if(verbose>1)cout << "\tcontinious var " << *constname << " index: " << MyLHA->NbVar-1 << endl;
					} else cout << "Unknown variable Type" << *it2 << endl;
				}
            //cout << "finished realvar" << endl;
            t1 = findbranchlha(it, "variables/discretes/");
			if (t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					if ((*it2).compare("discrete")==0) {
						string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						MyLHA->Vars.label.push_back(*constname);
						MyLHA->Vars.initialValue.push_back(0.0);
						treeSI dom = find(it2.begin(),it2.end(),"domain");
						if (dom != it2.end()) {
							string domname = *simplifyString(*(it2.begin()));
							vector<colorDomain>::const_iterator domit;
							for(domit = MyLHA->MyGspn->colDoms.begin(); domit != MyLHA->MyGspn->colDoms.end() && domit->name != domname; ++domit);
							if(domit != MyLHA->MyGspn->colDoms.end())MyLHA->Vars.colorDomain.push_back(domit - MyLHA->MyGspn->colDoms.begin());
							else cerr << "Unknown color Domain " << domname << endl;
						}else MyLHA->Vars.colorDomain.push_back(0);

						MyLHA->Vars.type.push_back(DISCRETE_VARIABLE);
						MyLHA->NbVar++;
						if(verbose>1)cout << "\tdiscrete var " << *constname << " index: " << MyLHA->NbVar-1 << endl;
					}
				}
			t1 = findbranchlha(it, "variables/colors/");
			if (t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					if ((*it2).compare("color")==0) {
						string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						MyLHA->Vars.label.push_back(*constname);
						MyLHA->Vars.initialValue.push_back(0.0);
						treeSI dom = find(it2.begin(),it2.end(),"domain");
						if (dom != it2.end()) {
							string domname = *simplifyString(*(dom.begin()));
							vector<colorClass>::const_iterator domit;
							for(domit = MyLHA->MyGspn->colClasses.begin(); domit != MyLHA->MyGspn->colClasses.end() && domit->name != domname; ++domit);
							if(domit != MyLHA->MyGspn->colClasses.end())MyLHA->Vars.colorDomain.push_back(domit - MyLHA->MyGspn->colClasses.begin());
							else cerr << "Unknown color Domain " << domname << endl;
						}else cerr << "No color class specify for color variable " << *constname << endl;

						MyLHA->Vars.type.push_back(COLOR_VARIABLE);
						MyLHA->NbVar++;
						if(verbose>1)cout << "\tcolor var " << *constname << " index: " << MyLHA->NbVar-1<< " domain: " << MyLHA->Vars.colorDomain[MyLHA->NbVar-1] << endl;
					}
				}
			//cout << "finished discrete var" << endl;
		} else if((*it).compare("HASLFormula")==0){
			//cout << "export hasl formula" << endl;
			HaslFormulasTop* haslform =  exportHASLTop(it.begin());
			if(haslform != NULL){
				MyLHA->HASLtop.push_back(haslform);
				MyLHA->HASLname.push_back("HASLFormula");
			}
		} else throw lhagmlioexc;
	}
	//print_tree(attribute, attribute.begin(), attribute.end());
}

void MyLhaModelHandler::on_read_node(const XmlString& id,
									 const XmlString& nodeType,
									 const AttributeMap& attributes,
									 const XmlStringList& references) {
	
	if(verbose>1)cout << "read node : " << id << ", " << nodeType << endl;
	if(nodeType.compare("state")==0){
		//cout << "location:"<<endl;
		flush(cout);
		int id2 = atoi(id.c_str());
		Gml2Loc[id2]=countLoc;
		
		bool markdep=false;
		
        string* Plname = simplifyString(*(attributes.find("name")->second.begin().begin()));
        if(verbose>1)cout << "name: " << *Plname << endl;
		MyLHA->LocLabel.push_back(*Plname);
		MyLHA->LocIndex[*Plname]=countLoc;
		
		string* inv = new string("");
		eval_expr(&markdep, inv, attributes.find("invariant")->second.begin().begin());
        if(verbose>1)cout << "invariant: " << *inv << endl;
		MyLHA->StrLocProperty.push_back(*inv);
		MyLHA->FuncLocProperty.push_back(*inv);
		
		treeSI itflow = attributes.find("flows")->second.begin();
		vector<string> v1(MyLHA->NbVar,"");
		for(treeSI it2 = itflow.begin(); it2!=itflow.end();++it2){
			if((*it2).compare("flow")==0){
				
				string* var = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
				string* varflow = new string("");
				
				eval_expr( &markdep, varflow, find(it2.begin(),it2.end(),"expr").begin());
				
				size_t vi = find(MyLHA->Vars.label.begin(), MyLHA->Vars.label.end(), *var) - MyLHA->Vars.label.begin();
				if(verbose>1)cout << "\tvar: " << *var << " index: " << vi << " flow: " << *varflow << endl;
				if(MyLHA->Vars.type[vi] == CONTINIOUS_VARIABLE){
					v1[vi]= *varflow;
				} else cout << "Variable "<< var << " is continious, it as no flow"<< endl;
			}
		}
		MyLHA->StrFlow.push_back(v1);
		MyLHA->FuncFlow.push_back(v1);
		
		string* type = simplifyString(*(attributes.find("type")->second.begin().begin()));
		if(verbose>1)cout << "\ttype:" << *type << endl;
		if ((*type).compare("Initial")==0) {
			MyLHA->InitLoc.insert(countLoc);
		} else if ((*type).compare("Final")==0) {
			MyLHA->FinalLoc.insert(countLoc);
		}
		
		countLoc++ ;
		
	}
	
	
	/*for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
	 print_tree(it->second, it->second.begin(), it->second.end());
	 }
	 for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
	 cout << "    ref => " << *it << endl;
	 }*/
}

void MyLhaModelHandler::on_read_arc(const XmlString& id,
									const XmlString& arcType,
									const XmlString& source,
									const XmlString& target,
									const AttributeMap& attributes,
									const XmlStringList& references) {
	if(ParseLoc){
		ParseLoc=false;
		MyLHA->NbLoc= countLoc;
		
		vector<string> v1(MyLHA->NbVar,"");
		
		vector< vector<string> > vv(MyLHA->NbLoc,v1);
		
		CoeffsVector=v1;
		vector<string> v2(MyLHA->NbLoc,"");
		//int sz=MyLHA->TransitionIndex.size();
		set <string> Pt;
		PetriTransitions=Pt;
		for(map<string, int>::iterator it=MyLHA->TransitionIndex.begin();it!=MyLHA->TransitionIndex.end();it++)
			PetriTransitions.insert((*it).first);
		
		vector < set<int> > vi(MyLHA->NbLoc);
		MyLHA->Out_S_Edges=vi;
		MyLHA->Out_A_Edges=vi;
		
		
	}
	
	if(verbose>1)cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
    
	int sourceGML = atoi(source.c_str());
	int targetGML = atoi(target.c_str());
	
	LhaEdge edge;
	edge.Index=MyLHA->Edge.size();
	edge.Source= Gml2Loc[sourceGML];
	edge.Target= Gml2Loc[targetGML];
	MyLHA->Edge.push_back(edge);
	
	set <string> SubSet;
	AttributeMap::const_iterator attrf = attributes.find("label");
	if (attrf != attributes.end()) {
		tree<string> itaction = attrf->second.begin().begin();
		string* actionstr = simplifyString(*(itaction.begin()));
		if((*actionstr).compare("ALL")==0){
			SubSet= PetriTransitions;
		}else{
			for(treeSI it2 = itaction.begin(); it2!=itaction.end();++it2){
				if ((*it2).compare("actionName")==0) {
					string* actionstr2 = simplifyString(*(it2.begin()));
					SubSet.insert(*actionstr2);
				}
			}
		}
	}
	attrf = attributes.find("action");
	if (attrf != attributes.end()) {
		tree<string> itaction = attrf->second.begin().begin();
		for(treeSI it2 = itaction.begin(); it2!=itaction.end();++it2){
			if ((*it2).compare("actionName")==0) {
				string* actionstr2 = simplifyString(*(it2.begin()));
				SubSet.insert(*actionstr2);
			}
		}
	}
	attrf = attributes.find("allExcept");
	if (attrf != attributes.end()) {
		tree<string> itaction = attrf->second.begin().begin();
		SubSet = MyLHA->MyGspn->TransList;
		
		for(treeSI it2 = itaction.begin(); it2!=itaction.end();++it2){
			if ((*it2).compare("actionName")==0) {
				string* actionstr2 = simplifyString(*(it2.begin()));
				SubSet.erase(*actionstr2);
			}
		}
	}
	
	
	
	MyLHA->EdgeActions.push_back(SubSet);
	if(SubSet.size()>0) MyLHA->Out_S_Edges[edge.Source].insert(edge.Index);
	else MyLHA->Out_A_Edges[edge.Source].insert(edge.Index);
	
	bool markdep=false;
	
	treeSI itflow = attributes.find("updates")->second.begin();
	vector<string> v1(MyLHA->NbVar,"");
	if ((*(itflow.begin())).compare("update")==0) {
		for(treeSI it2 = itflow.begin(); it2!=itflow.end();++it2){
			string* var=NULL;
			string* varflow = new string("");
			//cout << "var update:" << endl;
			for(treeSI it3 = it2.begin(); it3!=it2.end();++it3){
				if((*it3).compare("name")==0)var = simplifyString(*(it3.begin()));
				if((*it3).compare("expr")==0)eval_expr(&markdep, varflow, it3.begin() );
			}
			size_t vi = find(MyLHA->Vars.label.begin(), MyLHA->Vars.label.end(), *var) - MyLHA->Vars.label.begin();
			if(verbose>1 && var != NULL)
				cout << "\tvar: " << *var << " index: " << vi << " update: " << *varflow << endl;
			v1[vi]= *varflow;
		}
	}
	MyLHA->FuncEdgeUpdates.push_back(v1);
	
	treeSI itguard = attributes.find("guard")->second.begin();
	if(verbose>2)cout << "guard:" << endl;
	vector<vector<string> > CoeffsMatrix;
	vector<string> CST;
	vector<string> comp;
	eval_guard(CoeffsMatrix,CST,comp,itguard.begin().begin());
	if(verbose>1){
		cout << "guard:";
		for (size_t i=0; i< CoeffsMatrix.size(); i++) {
			cout << "&(";
			for (size_t j =0 ; j<CoeffsMatrix[0].size(); j++) {
				if(CoeffsMatrix[i][j].compare("")>0)
					cout << "+" << CoeffsMatrix[i][j]<< "* VAR[" <<j<<"] " ;
			}
			cout << comp[i] << CST[i]<<")";
		}
		cout << endl;
	}
	MyLHA->ConstraintsCoeffs.push_back(CoeffsMatrix);
	MyLHA->ConstraintsConstants.push_back(CST);
	MyLHA->ConstraintsRelOp.push_back(comp);
	
	
}
