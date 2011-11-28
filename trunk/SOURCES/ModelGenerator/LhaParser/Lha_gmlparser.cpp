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
	cout << (*it) << endl;
	if((*it).compare("value")==0){
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("boolean")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("intConst")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("realConst")==0) {
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("marking")==0) {
		*is_mark_dep =true;
		string* place = simplifyString(it.node->first_child->data);
		std::ostringstream s; s<<"Marking["<<MyLHA->PlaceIndex[place->c_str()]<<"]";
		st->append(s.str());
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

void MyLhaModelHandler::eval_linexpr(vector<string> CoeffsVector, tree<string>::pre_order_iterator it){
	cout << (*it) << endl;
	if((*it).compare("variable")==0){
		string* var = simplifyString(*(it.begin()));
		CoeffsVector[MyLHA->VarIndex[var->c_str()]]= "1";
	} else cout << "fail eval tree : linexp" << endl;
		
}

void MyLhaModelHandler::eval_guard(vector<vector<string> > CoeffsMatrix,vector<string> CST, vector<string> comp,tree<string>::pre_order_iterator it)
{
	cout << (*it) << endl;
	if ((*it).compare("boolean")==0) {
		cout << "\tguard = true" << it.node->first_child->data << endl;
	}else if ((*it).compare("and")==0){
		cout << "(";
		for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			eval_guard(CoeffsMatrix,CST,comp,it2);
		}
		cout << ")";
	}else if((*it).compare("equal")==0	
			  || (*it).compare("greaterEqual")==0 
			  || (*it).compare("lessEqual")==0 ){
		if((*it).compare("equal")==0)comp.push_back("==");
		if((*it).compare("greaterEqual")==0)comp.push_back("<=");
		if((*it).compare("lessEqual")==0)comp.push_back(">=");
		
		vector<string> CoeffsVector(MyLHA->NbVar,"");
		eval_linexpr(CoeffsVector,it.begin());
		cout << ";";
		CoeffsMatrix.push_back(CoeffsVector);
		string* st= new string("");
		bool markdep = false;
		eval_expr(&markdep, st, it.begin().node->next_sibling);
		cout<< "CST: " << *st << endl;
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
					MyLHA->VarIndex[*constname]=MyLHA->NbVar;
					MyLHA->NbVar++;
					
					cout << "\tvar " << *constname << " index: " << MyLHA->NbVar-1 << endl;
				}else cout << "fail to parse gml: const declaration"<< endl;
				
			}
			
			
		} else if((*it).compare("HASL Formula")==0){
			cout << "export hasl formula" << endl;
			
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
		
		tree<string>::sibling_iterator itflow = attributes.find("flow")->second.begin();
		vector<string> v1(MyLHA->NbVar,"");
		for(tree<string>::sibling_iterator it2 = itflow.begin(); it2!=itflow.end();++it2){
			string* var;
			string* varflow = new string("");
			cout << "var flow:" << endl;
			for(tree<string>::sibling_iterator it3 = it2.begin(); it3!=it2.end();++it3){
				if((*it3).compare("variable")==0)var = simplifyString(*(it3.begin()));
				if((*it3).compare("realFormula")==0)eval_expr(&markdep, varflow, it3.begin() );
			}
			int vindex = MyLHA->VarIndex[var->c_str()];
			cout << "\tvar: " << *var << " index: " << vindex << " flow: " << *varflow << endl;
			v1[vindex]= *varflow;
		}
		MyLHA->StrFlow.push_back(v1);
		MyLHA->FuncFlow.push_back(v1);
		
		string* type = simplifyString(*(attributes.find("type")->second.begin().begin()));
		cout << "\ttype:" << *type << endl; 
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
	
	cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
	//string* valuation = new string("");
	//cout << arcType << endl;
	
	int sourceGML = atoi(source.c_str());
	int targetGML = atoi(target.c_str());

	LhaEdge edge;
	edge.Index=MyLHA->Edge.size();
	edge.Source= Gml2Loc[sourceGML];
	edge.Target= Gml2Loc[targetGML];
	MyLHA->Edge.push_back(edge);

	
	tree<string> itaction = attributes.find("action")->second.begin().begin();
	set <string> SubSet;
	string* actionstr = simplifyString(*(itaction.begin()));
	if((*actionstr).compare("ALL")==0){
		SubSet= PetriTransitions;
	}else{
		for(tree<string>::sibling_iterator it2 = itaction.begin(); it2!=itaction.end();++it2){
			if ((*it2).compare("actionName")==0) {
				string* actionstr2 = simplifyString(*(it2.begin()));
				SubSet.insert(*actionstr2); 
			}
		}
	}
	MyLHA->EdgeActions.push_back(SubSet);
	if(SubSet.size()>0) MyLHA->Out_S_Edges[edge.Source].insert(edge.Index);
	else MyLHA->Out_A_Edges[edge.Source].insert(edge.Index);
	
	bool markdep=false;

	tree<string>::sibling_iterator itflow = attributes.find("update")->second.begin();	
	vector<string> v1(MyLHA->NbVar,"");
	if ((*(itflow.begin())).compare("updatevar")==0) {
		for(tree<string>::sibling_iterator it2 = itflow.begin(); it2!=itflow.end();++it2){
			string* var;
			string* varflow = new string("");
			cout << "var update:" << endl;
			for(tree<string>::sibling_iterator it3 = it2.begin(); it3!=it2.end();++it3){
				if((*it3).compare("variable")==0)var = simplifyString(*(it3.begin()));
				if((*it3).compare("realFormula")==0)eval_expr(&markdep, varflow, it3.begin() );
			}
			int vindex = MyLHA->VarIndex[var->c_str()];
			cout << "\tvar: " << *var << " index: " << vindex << " update: " << *varflow << endl;
			v1[vindex]= *varflow;
		}
	}
	MyLHA->FuncEdgeUpdates.push_back(v1);
	
	tree<string>::sibling_iterator itguard = attributes.find("guard")->second.begin();
	cout << "guard:" << endl;
	vector<vector<string> > CoeffsMatrix;
	vector<string> CST;
	vector<string> comp;
	eval_guard(CoeffsMatrix,CST,comp,itguard.begin().begin());
	MyLHA->ConstraintsCoeffs.push_back(CoeffsMatrix);
	MyLHA->ConstraintsConstants.push_back(CST);
	MyLHA->ConstraintsRelOp.push_back(comp);
	
	
}
