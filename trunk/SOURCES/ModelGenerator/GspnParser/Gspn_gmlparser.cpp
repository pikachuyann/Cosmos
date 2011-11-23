/*
 *  Gspn_gmlparser.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 05/10/11.
 *  Copyright 2011  All rights reserved.
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "Gspn_gmlparser.hpp"
#include "../Eval/Eval.hpp"

#include "Gspn-Reader.hpp"

//#include "tree.hh"
#include "tree/tree_util.hh"

Eval Evaluate_gml;

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

string* simplifyString(string str) 
{
	int n1 = str.find_first_not_of(" \n");
	int n2 = str.find_last_not_of(" \n");
	return new string(str.substr(n1, n2-n1+1));
}

void appendSimplify(string *st, string str)
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

void eval_expr(bool *is_mark_dep, string *st, tree<string>::pre_order_iterator it )
{
	if((*it).compare("value")==0){
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
			 || (*it).compare("div")==0   || (*it).compare("power")==0)  {
		
		
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
				else st->append(",");
			}
			eval_expr(is_mark_dep, st, it2);
		}
		st->append(")");
		;
	} else cout << "failevaltree" <<endl;
}

int eval_str (string s){
	string* val = simplifyString(s);
	int intval = atoi( (*val).c_str() );
	delete val;
	return intval;
}

int eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator it )
{
	if((*it).compare("intFormula")==0){
		//cout << *(it.begin()) << endl;
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



MyModelHandler::MyModelHandler(GSPN* MyGspn2) {
	//Initialisation
		MyGspn= MyGspn2;
		countPl=0;
		MyGspn->pl=0;
		countTr=0;
		MyGspn->tr=0;
		ParsePl=true;
	}
	//~MyModelHandler() { }
	
	
    void MyModelHandler::on_read_model(const XmlString& formalismUrl) {
	// output used formalism
		ParsePl=true;
        cout << "read model : formalism = " << formalismUrl << endl;
    }
	
    void MyModelHandler::on_read_model_attribute(const Attribute& attribute) {
		// read model attribute
		for(tree<string>::sibling_iterator it = attribute.begin(); it != attribute.end(); ++it) {
			//cout << *it << ":" << endl;
			if((*it).compare("declarations")==0){
				//const definition
				//cout << "const declarations:" << endl;
				
				for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
					if ((*it2).compare("intConstDeclaration")==0) { // const is int or double
						string* constname = simplifyString((find(it2.begin(),it2.end(),"constName")).node->first_child->data);
						//string constvalue =(find(it2.begin(),it2.end(),"intFormula")).node->first_child->data;
						//cout <<  (find(it2.begin(),it2.end(),"intFormula")).node->first_child->data << endl;
						int constvalue = eval_intFormula(MyGspn->IntConstant, find(it2.begin(),it2.end(),"intFormula"));
						
						//Evaluate_gml.parse(constvalue);
						MyGspn->IntConstant[*constname]=constvalue; //Evaluate_gml.IntResult;
						MyGspn->RealConstant[*constname]= constvalue; //Evaluate_gml.RealResult;
						//cout << "\tconst int " << *constname << "=" << constvalue << endl;
							
					} else if ((*it2).compare("realConstDeclaration")==0) {
						string* constname = simplifyString((find(it2.begin(),it2.end(),"constName")).node->first_child->data);
						//string constvalue =(find(it2.begin(),it2.end(),"realFormula")).node->first_child->data;
						
						bool ismarkdep=false;
						string constvalue;
						eval_expr( &ismarkdep, &constvalue, find(it2.begin(),it2.end(),"realFormula").begin());
						//cout << constvalue<< endl;
						if(ismarkdep)cout<< "constante are not makring dependant!" << endl;
						Evaluate_gml.parse(constvalue);
						MyGspn->RealConstant[*constname]=Evaluate_gml.RealResult;
						//cout << "\tconst double " << *constname << "=" << Evaluate_gml.RealResult << endl;
					} else cout << "fail to parse gml: const declaration"<< endl;
					
				}
					
				
			}
		}
        //print_tree(attribute, attribute.begin(), attribute.end());
    }
	
    void MyModelHandler::on_read_node(const XmlString& id,
					  const XmlString& nodeType,
					  const AttributeMap& attributes,
					  const XmlStringList& references) {
        //cout << "read node : " << id << ", " << nodeType << endl;
		if(nodeType.compare("place")==0){
			//cout << "place:"<<endl;
			flush(cout);
			MyGspn->pl++;
			int id2 = atoi(id.c_str());
			IsPlace[id2]=true;
			Gml2Place[id2]=countPl;
			
			for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
				if((*(it->second.begin())).compare("marking")==0){
					int mark = eval_intFormula(MyGspn->IntConstant, it->second.begin().begin());
					//string Plmark = *(++(it->second.begin()));
					//Evaluate_gml.parse(Plmark);
					//cout << "\tmarking:" << mark << endl ;
					MyGspn->Marking.push_back(mark);
							
				} else if((*(it->second.begin())).compare("name")==0){
					string* Plname = simplifyString(*(++(it->second.begin())));
					//cout << "\tname:" << *Plname << endl ;
					//string& Plname2 = *(new string(Plname));
					MyGspn->PlacesList.insert(*Plname);
					MyGspn->PlacesId[*Plname]=countPl;

					
				} else cout << "fail to parse gml"<< endl;
					
			}
			countPl++ ;
		
		}else {
			if (nodeType.compare("transition")==0){
				//cout << "transition:"<<endl;
				MyGspn->tr++;
				int id2 = atoi(id.c_str());
				IsPlace[id2]=false;
				Gml2Trans[id2]=countTr;
				TransType timed = Timed;
				bool singleservice = true;
				bool markingdependant = false;
				//bool agememory =false;
				int nbserver =1;
				string priority = "1";
				string weight = "1";
				
				for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
					if((*(it->second.begin())).compare("name")==0){
						string* Trname = simplifyString(*(++(it->second.begin())));
						//cout << "\tname:" << *Trname << endl ;
						//string& Trname2 = *(new string(Trname));
						MyGspn->TransList.insert(*Trname);
						MyGspn->TransId[*Trname]=countTr;
					} else if ((*(it->second.begin())).compare("distribution")==0) {
						//cout << "\tdistribution:" << endl ;
						ProbabiliteDistribution& dist = *(new ProbabiliteDistribution);
						for (tree<string>::sibling_iterator it2 = (it->second.begin()).begin() ; it2 != (it->second.begin()).end() ; ++it2 ) {
							//cout << "\t\t" << (*it2) << ":" << endl;
							if ((*it2).compare("type")==0) {
								//cout << "\t\t\t" << *(it2.begin()) << endl; 
								string* Trtype = simplifyString(*(it2.begin()));
								if((*Trtype).compare("IMDT")==0)timed=unTimed;
								dist.name = *Trtype;
							} else if ((*it2).compare("param")==0) {
								
								int number = 0;
								string* value = new string("");
								for (tree<string>::sibling_iterator it3 = it2.begin() ; it3 != it2.end() ; ++it3 ) {
									string* leaf = simplifyString(*(it3.begin()));
									if ((*it3).compare("number")==0) {
										number = atoi((*leaf).c_str());
									} else if ((*it3).compare("realFormula")==0) {
										eval_expr(&markingdependant, value, it3.begin() );
										dist.Param.push_back(*value);
									} else cout << "fail to parse gml: param"<< endl;
								}
								//cout << "\t\t\t" << "number" << ":" << number << endl;
								//cout << "\t\t\t" << "realFormula" << ":" << *value << endl;
								
								
								
							} else cout << "fail to parse gml: transition"<< endl;
							//cout << "finish distr";
						}
						MyGspn->Dist.push_back(dist);
						
					} else if ((*(it->second.begin())).compare("service")==0) {
						bool markingdependant=false;
						string* value = new string("");
						if ((*(++(it->second.begin()))).compare("intFormula")==0) {
							eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
							if(markingdependant==false) {
								if(Evaluate_gml.parse(*value)){
									cout << " Fail to parse GML: transition,service"<< endl;
								}
								else {
									int nserv=Evaluate_gml.IntResult;
									delete value;
									if(nserv == 1 ) {
										nbserver =1;
									}else {
										singleservice=false;
										nbserver=nbserver;
									}

								}
								
							}else {
								cout<<"service is not marking dependent "<<endl;
							}
						} else cout << " Fail to parse GML: transition,service"<< endl;
						
						/*if ((*(++(it->second.begin()))).compare("Infinite")==0) {
							singleservice=false;
							nbserver=INT_MAX;
						} else {
							int nbsrv = atoi((*(++(it->second.begin()))).c_str());
							if (nbsrv!=1) {
								singleservice=false;
								nbserver=nbserver;
							}
						}*/
					} else if ((*(it->second.begin())).compare("weight")==0) {
						bool markingdependant=false;
						string* value = new string("");
						if ((*(++(it->second.begin()))).compare("realFormula")==0) {
							eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
							if(markingdependant==false) {
								weight = *value;
							}else {
								cout<<"Weight is not marking dependent "<<endl;
							}
						} else cout << " Fail to parse GML: transition,weight"<< endl;
						
						
					} else if ((*(it->second.begin())).compare("priority")==0) {
						bool markingdependant=false;
						string* value = new string("");
						if ((*(++(it->second.begin()))).compare("realFormula")==0) {
							eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
							if(markingdependant==false) {
								priority = *value;
							}else {
								cout<<"Priority is not marking dependent "<<endl;
							}
						} else cout << " Fail to parse GML: transition,priority"<< endl;
						
						
					} else cout << "fail to parse gml"<< endl;

				}
				
				MyGspn->tType.push_back(timed);
				MyGspn->Priority.push_back(*(new string(priority)));
				MyGspn->Weight.push_back(*(new string(weight)));
				MyGspn->SingleService.push_back(singleservice);
				MyGspn->MarkingDependent.push_back(markingdependant);
				MyGspn->NbServers.push_back(nbserver);
				
				countTr++;
			}else cout << "fail to parse gml"<< endl;
		}

			
        /*for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
            print_tree(it->second, it->second.begin(), it->second.end());
        }
        for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }*/
    }
	
    void MyModelHandler::on_read_arc(const XmlString& id,
					 const XmlString& arcType,
					 const XmlString& source,
					 const XmlString& target,
					 const AttributeMap& attributes,
					 const XmlStringList& references) {
		if(ParsePl){
			ParsePl=false;
			
				vector<int> vplint(MyGspn->pl,0);
				vector<string> vStr(MyGspn->pl, " ");
				
				//Reader.MyGspn.Marking=v;
				vector< vector<int> > m1(MyGspn->tr,vplint);  
				vector< vector<string> > m1Str(MyGspn->tr,vStr);
				
				MyGspn->outArcs=m1;
				MyGspn->inArcs=m1;
				MyGspn->inhibArcs=m1;
				
				MyGspn->outArcsStr=m1Str;
				MyGspn->inArcsStr=m1Str;
				MyGspn->inhibArcsStr=m1Str;
			
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
		string* valuation = new string("");
		//cout << arcType << endl;
		
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
			if((*(it->second.begin())).compare("valuation")==0){
				
				bool markingdependant=false;
				if ((*(++(it->second.begin()))).compare("intFormula")==0) {
					eval_expr(&markingdependant, valuation, (++(it->second.begin())).begin() );
				} else cout << " Fail to parse GML: arc,valuation"<< endl;
				
			}else cout << "fail to parse gml"<< endl;
				
        }
		int sourceGML = atoi(source.c_str());
		if(IsPlace[sourceGML]){
			if(arcType.compare("inhibitorarc")==0){
				if(Evaluate_gml.parse(*valuation)){
					MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
					MyGspn->inhibArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]= *valuation;
				}
				else {	
					MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
					delete valuation;
				}
				//MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
			}else {
				if(Evaluate_gml.parse(*valuation)){
					MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
					MyGspn->inArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=*valuation;
				}
				else {
					MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
					delete valuation;
				}
				//MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
			}
		}else {
			if(Evaluate_gml.parse(*valuation)){
				MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=1;
				MyGspn->outArcsStr[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=*valuation;
			}
			else {
				MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=Evaluate_gml.IntResult;
				delete valuation;
			}
			//MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
		}

		
        /*for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }*/
    }
