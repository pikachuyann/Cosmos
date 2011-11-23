/*
 *  Lha_gmlparser.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 03/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
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
#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "../Eval/Eval.hpp"

#include "Lha-Reader.hpp"

//#include "tree.hh"
#include "tree/tree_util.hh"


using namespace std;


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
	int n1 = str.find_first_not_of(" \n");
	int n2 = str.find_last_not_of(" \n");
	return new string(str.substr(n1, n2-n1+1));
}

void MyLhaModelHandler::appendSimplify(string *st, string str)
{
	int n1 = str.find_first_not_of(" \n");
	int n2 = str.find_last_not_of(" \n");
	st->append(str.substr(n1, n2-n1+1));
}

/*void evalinfix(string *st, tree<string>::pre_order_iterator it , string str){
 st->append("(");
 for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
 if(it2!= it.begin()) st->append(str);
 eval_expr( st, it2);
 }
 st->append(")");
 }*/

void MyLhaModelHandler::eval_expr(bool *is_mark_dep, string *st, tree<string>::pre_order_iterator it )
{
	//cout << (*it) << endl;
	if((*it).compare("value")==0){
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("boolValue")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("intConst")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("realConst")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("marking")==0) {
		*is_mark_dep =true;
		st->append("Marking[_nb_Place_");
		appendSimplify(st,it.node->first_child->data);
		st->append("]");
	}else if (	(*it).compare("plus")==0  || (*it).compare("mult")==0
			  || (*it).compare("iplus")==0 || (*it).compare("imult")==0  
			  || (*it).compare("min")==0   || (*it).compare("max")==0
			  || (*it).compare("imin")==0  || (*it).compare("imax")==0
			  || (*it).compare("ipower")==0|| (*it).compare("iminus")==0
			  || (*it).compare("floor")==0 || (*it).compare("minus")==0
			  || (*it).compare("div")==0   || (*it).compare("power")==0
			  || (*it).compare("or")==0   || (*it).compare("and")==0
			  || (*it).compare("not")==0   || (*it).compare("equal")==0	
			  || (*it).compare("notEqual")==0   || (*it).compare("greater")==0
			  || (*it).compare("greaterEqual")==0   || (*it).compare("less")==0
			  || (*it).compare("lessEqual")==0 ){
		
		
		if ((*it).compare("min")==0 || (*it).compare("imin")==0 ) st->append("min");
		if ((*it).compare("max")==0 || (*it).compare("imax")==0 ) st->append("max");
		if ((*it).compare("floor")==0 ) st->append("floor");
		
		st->append("(");
		for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) {
				if ((*it).compare("plus")==0  || (*it).compare("iplus")==0) { st->append("+"); }
				else if ((*it).compare("mult")==0  || (*it).compare("imult")==0) { st->append("*"); }
				else if ((*it).compare("minus")==0  || (*it).compare("iminus")==0) { st->append("-"); }
				else if ((*it).compare("div")==0) { st->append("/"); }
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
	} else cout << "failevaltree" <<endl;
}


int MyLhaModelHandler::eval_str (string s){
	string* val = simplifyString(s);
	int intval = atoi( (*val).c_str() );
	delete val;
	return intval;
}

int MyLhaModelHandler::eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator it )
{
	if((*it).compare("intFormula")==0){
		cout << *(it.begin()) << endl;
		return eval_intFormula(intconst,it.begin());
	}else if((*it).compare("value")==0){
		return eval_str(it.node->first_child->data);
	}else if ((*it).compare("intConst")==0) {
		string* val = simplifyString(it.node->first_child->data);
		int intval = intconst[(*val).c_str()];
		delete val;
		return intval;
	}else if ((*it).compare("iplus")==0 || (*it).compare("imult")==0  
			  || (*it).compare("imin")==0  || (*it).compare("imax")==0
			  || (*it).compare("ipower")==0|| (*it).compare("iminus")==0)  {
		
		int v1,v2;
		for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) { v1 = eval_intFormula(intconst, it2);
			} else {
				v2 = eval_intFormula(intconst, it2);
			}
			
		}
		
		if ((*it).compare("iplus")==0) { return v1+v2; }
		else if ((*it).compare("imult")==0) { return v1*v2; }
		else if ((*it).compare("iminus")==0) { return v1-v2; }
		else if ((*it).compare("imin")==0) { return min(v1,v2); }
		else if ((*it).compare("imax")==0) {  return max(v1,v2); }
		else if ((*it).compare("ipower")==0) {  return v1^v2; }
		else cout << "faileval int Formula" <<endl;
		
	}else cout << "faileval int Formula" <<endl;
}



MyLhaModelHandler::MyLhaModelHandler(LHA* MyLHA2) {
	//Initialisation
	MyLHA= MyLHA2;
	countLoc=0;
	countVar=0;
	ParseLoc=true;
	//ParseDecl=true;
}
//~MyModelHandler() { }


void MyLhaModelHandler::on_read_model(const XmlString& formalismUrl) {
	// output used formalism
	ParseLoc=true;
	//ParseDecl=true;
	cout << "read model : formalism = " << formalismUrl << endl;
}

void MyLhaModelHandler::on_read_model_attribute(const Attribute& attribute) {
	// read model attribute
	for(tree<string>::sibling_iterator it = attribute.begin(); it != attribute.end(); ++it) {
		cout << *it << ":" << endl;
		if((*it).compare("declarations")==0){
			// const definition
			cout << "const declarations:" << endl;
			
			for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
				if ((*it2).compare("intConstDeclaration")==0) { // const is int or double
					string* constname = simplifyString((find(it2.begin(),it2.end(),"constName")).node->first_child->data);
					//string constvalue =(find(it2.begin(),it2.end(),"intFormula")).node->first_child->data;
					cout <<  (find(it2.begin(),it2.end(),"intFormula")).node->first_child->data << endl;
					int constvalue = eval_intFormula(MyLHA->LhaIntConstant, find(it2.begin(),it2.end(),"intFormula"));
					
					//Evaluate_gml.parse(constvalue);
					MyLHA->LhaIntConstant[*constname]=constvalue; //Evaluate_gml.IntResult;
					MyLHA->LhaRealConstant[*constname]= constvalue; //Evaluate_gml.RealResult;
					cout << "\tconst int " << *constname << "=" << constvalue << endl;
					
				} else if ((*it2).compare("realConstDeclaration")==0) {
					string* constname = simplifyString((find(it2.begin(),it2.end(),"constName")).node->first_child->data);
					//string constvalue =(find(it2.begin(),it2.end(),"realFormula")).node->first_child->data;
					
					bool ismarkdep=false;
					string constvalue;
					eval_expr( &ismarkdep, &constvalue, find(it2.begin(),it2.end(),"realFormula").begin());
					//cout << constvalue<< endl;
					if(ismarkdep)cout<< "constante are not makring dependant!" << endl;
					Evaluate_gml.parse(constvalue);
					MyLHA->LhaRealConstant[*constname]=Evaluate_gml.RealResult;
					//cout << "\tconst double " << *constname << "=" << Evaluate_gml.RealResult << endl;
				} else if ((*it2).compare("variable")==0) {
					string* constname = simplifyString((find(it2.begin(),it2.end(),"varName")).node->first_child->data);
					MyLHA->VarLabel.push_back(*constname);
					MyLHA->Var.push_back(0.0);
					MyLHA->VarIndex[*constname]=countVar;
					countVar++;
					
					//cout << "\tvar " << *constname << " index: " << countVar-1 << endl;
				}else cout << "fail to parse gml: const declaration"<< endl;
				
			}
			
			
		}
	}
	//print_tree(attribute, attribute.begin(), attribute.end());
}

void MyLhaModelHandler::on_read_node(const XmlString& id,
								  const XmlString& nodeType,
								  const AttributeMap& attributes,
								  const XmlStringList& references) {
	
	cout << "read node : " << id << ", " << nodeType << endl;
	if(nodeType.compare("location")==0){
		cout << "location:"<<endl;
		flush(cout);
		int id2 = atoi(id.c_str());
		Gml2Loc[id2]=countLoc;
		
		bool markdep=false;
		
		//cout << "name: " << *(attributes.find("name")->second.begin()) << " and " << *((attributes.find("name")->second.begin().begin()))<< endl;
		
		string* Plname = simplifyString(*(attributes.find("name")->second.begin().begin()));
		MyLHA->LocLabel.push_back(*Plname);
		MyLHA->LocIndex[*Plname]=countLoc;
		
		string* inv = new string("");
		eval_expr(&markdep, inv, attributes.find("invariant")->second.begin().begin().begin());
		MyLHA->StrLocProperty.push_back(*inv);
		MyLHA->FuncLocProperty.push_back(*inv);
		
		vector<string> v1(MyLHA->NbVar,"");
		vector<string> StrFlowVector=v1;
		vector<string> FuncFlowVector=v1;
		tree<string> itflow = attributes.find("flow")->second.begin().begin();
		for(tree<string>::sibling_iterator it2 = itflow.begin(); it2!=itflow.end();++it2){
			string* var;
			string* varflow = new string("");
			cout << "var flow:" << endl;
			for(tree<string>::sibling_iterator it3 = it2.begin(); it3!=it2.end();++it3){
				if((*it3).compare("variable")==0)var = simplifyString(*(it3.begin()));
				if((*it3).compare("realFormula")==0)eval_expr(&markdep, varflow, it3.begin() );
			}
			int vindex = MyLHA->VarIndex[var->c_str()];
			cout << " var: " << *var << " index: " << vindex << " flow: " << *varflow << endl;
			
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
		MyLHA->NbVar= countVar;
		MyLHA->NbLoc= countLoc;
		
		vector<string> v1(MyLHA->NbVar,"");
			
		vector< vector<string> > vv(MyLHA->NbLoc,v1);  
			
		FuncUpdateVector=v1;
		CoeffsVector=v1;
		MyLHA->FuncFlow=vv;
		MyLHA->StrFlow=vv;
		vector<string> v2(MyLHA->NbLoc,"");
		MyLHA->StrLocProperty=v2;
		MyLHA->FuncLocProperty=v2;
		//int sz=MyLHA->TransitionIndex.size();
		set <string> Pt;
		PetriTransitions=Pt;
		for(map<string, int>::iterator it=MyLHA->TransitionIndex.begin();it!=MyLHA->TransitionIndex.end();it++)
			PetriTransitions.insert((*it).first);
		vector < set<int> > vi(MyLHA->NbLoc);
		MyLHA->Out_S_Edges=vi;
		MyLHA->Out_A_Edges=vi;
			
		
		
		/*vector<int> vplint(MyLHA->pl,0);
		vector<string> vStr(MyLHA->pl, " ");
		
		//Reader.MyGspn.Marking=v;
		vector< vector<int> > m1(MyGspn->tr,vplint);  
		vector< vector<string> > m1Str(MyGspn->tr,vStr);
		
		MyGspn->outArcs=m1;
		MyGspn->inArcs=m1;
		MyGspn->inhibArcs=m1;
		
		MyGspn->outArcsStr=m1Str;
		MyGspn->inArcsStr=m1Str;
		MyGspn->inhibArcsStr=m1Str;*/
		
		/*vector<TransType> vtrtt(MyGspn->tr);
		 MyGspn->tType=vtrtt;
		 
		 //vector<Distribution> vdistr(MyGspn->tr);
		 //MyGspn->Dist=vdistr;
		 
		 vector<string> vtrstr(MyGspn->tr,"");
		 MyGspn->Priority=vtrstr;
		 
		 vector<string> dtrstr(MyGspn->tr);
		 MyGspn->Weight=vtrstr;
		 
		 
		 vector<bool> vtrbool(MyGspn->tr);
		 MyGspn->MarkingDependent=vtrbool;
		 //MyGspn->AgeMemory=vtrbool;
		 
		 //vector<bool> vtrbool(MyGspn->tr);
		 MyGspn->SingleService=vtrbool;
		 
		 vector<int> vtrint(MyGspn->tr);
		 MyGspn->NbServers=vtrint;*/
		
		//MarkingDependent=false;
		//AgeMemory=false;
		
	}
	
	//cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
	//string* valuation = new string("");
	//cout << arcType << endl;
	
	set <string> SubSet;
	
	for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
		if((*(it->second.begin())).compare("action")==0){
			string* actionstr = simplifyString(*(++(it->second.begin())));
			if((*actionstr).compare("ALL")==0){
				SubSet= PetriTransitions;
			}else{
				for(tree<string>::sibling_iterator it2 = (++(it->second.begin())).begin(); it2!=(++(it->second.begin())).end();++it2){
					if ((*it2).compare("actionName")==0) {
						string* actionstr2 = simplifyString(*(it2.begin()));
						SubSet.insert(*actionstr2); 
					}
				}
			}
			
		} else if ((*(it->second.begin())).compare("guard")==0) {
			
		} else cout << "fail to parse gml"<< endl;
		
	}
	int sourceGML = atoi(source.c_str());
	int targetGML = atoi(target.c_str());

	
	int ne=MyLHA->Edge.size();
	MyLHA->AnEdge.Index=ne;
	MyLHA->AnEdge.Source= Gml2Loc[sourceGML];
	MyLHA->AnEdge.Target= Gml2Loc[targetGML];
	MyLHA->Edge.push_back(MyLHA->AnEdge);
	/*MyLHA.EdgeActions.push_back(SubSet);
	if(SubSet.size()>0) Reader.MyLha.Out_S_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
	else Reader.MyLha.Out_A_Edges[Reader.MyLha.AnEdge.Source].insert(ne); 
	SubSet.erase(SubSet.begin(),SubSet.end());
	Reader.MyLha.ConstraintsCoeffs.push_back(CoeffsMatrix);Reader.MyLha.ConstraintsConstants.push_back(CST);
	Reader.MyLha.ConstraintsRelOp.push_back(comp);
	vector<string> vs;comp=vs;CST=vs;
	vector <vector <string> > ms;CoeffsMatrix=ms;
	*/
	
	/*for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
	 cout << "    ref => " << *it << endl;
	 }*/
}
