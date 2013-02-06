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
 * file Gspn_gmlparser.cpp                                                     *
 * Created by Benoit Barbot on 05/10/12.                                       *
 *******************************************************************************
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

gmlinputexception gmlioexc;

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

string itostring (int i){
	stringstream ss;
	ss << i;
	return ss.str();
}

string* simplifyString(string str) 
{
	int n1 = str.find_first_not_of(" \n");
	int n2 = str.find_last_not_of(" \n");
	if(n1 == -1 )return new string("");
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
 for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
 if(it2!= it.begin()) st->append(str);
 eval_expr( st, it2);
 }
 st->append(")");
 }*/

void MyModelHandler::eval_expr(bool *is_mark_dep, string *st, tree<string>::pre_order_iterator it )
{
    if(verbose>1)cout << (*it) << endl;
    
	if((*it).compare("function")==0){
		eval_expr(is_mark_dep, st, it.begin());
	}else if((*it).compare("expr")==0){
		eval_expr(is_mark_dep, st, it.begin());
	}else if((*it).compare("intValue")==0){
		appendSimplify(st,it.node->first_child->data);
	}else if((*it).compare("numValue")==0){
		appendSimplify(st,it.node->first_child->data);
	}else if ((*it).compare("name")==0) {
        string *var = simplifyString(it.node->first_child->data);
        if(MyGspn->IntConstant.count(*var)>0 || 
           MyGspn->RealConstant.count(*var)>0){st->append(*var);
        }else{
            *is_mark_dep =true;
            st->append("Marking.P->_PL_");
            st->append(*var);
        }
	}else if (	(*it).compare("+")==0  || (*it).compare("*")==0  
              || (*it).compare("min")==0   || (*it).compare("max")==0
              || (*it).compare("floor")==0 || (*it).compare("minus")==0
              || (*it).compare("/")==0   || (*it).compare("power")==0)  {
		
		
		if ((*it).compare("min")==0) st->append("min");
		if ((*it).compare("max")==0) st->append("max");
		if ((*it).compare("floor")==0 ) st->append("floor");
		
		st->append("(");
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) {
				if ((*it).compare("+")==0) { st->append("+"); }
				else if ((*it).compare("*")==0) { st->append("*"); }
				else if ((*it).compare("-")==0) { st->append("-"); }
				else if ((*it).compare("/")==0) { st->append("/"); }
				else if ((*it).compare("power")==0) { st->append("^"); }
				else st->append(",");
			}
			eval_expr(is_mark_dep, st, it2);
		}
		st->append(")");
		;
	} else {
        cout << "failevaltree" <<endl;
        throw(gmlioexc);
    }
}

void MyModelHandler::eval_tokenProfileMark(string* st,tree<string>::pre_order_iterator it){
	if(verbose>1)cout << (*it) << endl;
	if(it->compare("function")==0){
		eval_tokenProfileMark(st, it.begin());
	}else if(it->compare("expr")==0){
		eval_tokenProfileMark(st, it.begin());
	}else if(it->compare("all")==0){
		st->append("(");
		eval_tokenProfileMark(st, it.begin());
		st->append("(1))");
	}else if(it->compare("type")==0){
		string coldom = *simplifyString(*(it.begin()));
		if(verbose>1)cerr << coldom << endl;
		size_t colorc =0;
		for(colorc =0; colorc < MyGspn->colDoms.size() &&
			MyGspn->colDoms[colorc].name != coldom ; colorc++);
		if(colorc == MyGspn->colDoms.size())
			cerr << "Unknown classe '" << coldom << "'"<< endl;
		else st->append(MyGspn->colDoms[colorc].cname());
	}else if (it->compare("token")==0) {
		string mark;
		st->append("(");
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(it2->compare("occurs")==0){
				bool markingdependant;
				eval_expr(&markingdependant, &mark, it2.begin());
				if( markingdependant) cerr << "Initial Marking is not marking dependant";
			}
			if (it2->compare("tokenProfile")==0) {
				if (verbose>1)cout << *it2 << endl;
				for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
					eval_tokenProfileMark(st, it3);
				}
			}
		}
		st->append(" * " + mark +")");
	} else if(it->compare("name")==0) {
		st->append("Marking.P->"+ *simplifyString(*(it.begin())));
	}
}

void MyModelHandler::eval_tokenProfileArc( coloredToken& tok, bool &markingdependant ,set<size_t>& vardom, tree<string>::pre_order_iterator it){
	if(verbose>1)cout << (*it) << endl;
	if(it->compare("function")==0){
		eval_tokenProfileArc(tok, markingdependant, vardom, it.begin());
	}else if(it->compare("++")==0){
		int incr;
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(it2->compare("name")==0){
				eval_tokenProfileArc(tok, markingdependant, vardom, it2);
			} else incr = atoi(simplifyString(*(it2).begin())->c_str());
		}
		tok.varIncrement.back() += incr;
	}else if(it->compare("expr")==0){
		eval_tokenProfileArc(tok,markingdependant, vardom, it.begin());
	}else if (it->compare("token")==0) {
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(it2->compare("occurs")==0){
				eval_expr(&markingdependant, &tok.mult, it2.begin());
			}
			if (it2->compare("tokenProfile")==0) {
				if (verbose>1)cout << *it2 << endl;
				for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
					eval_tokenProfileArc(tok,markingdependant, vardom, it3);
				}
			}
		}
	} else if(it->compare("type")==0){
		cerr << "plain colore in arc label not yet implemented" << endl;
		
		/*string coldom = *simplifyString(*(it.begin()));
		cerr << coldom << endl;
		size_t colorc =0;
		cerr << "Simply colored tocken not yet implemented Color";
		for(colorc =0; colorc < MyGspn->co Doms.size() &&
			MyGspn->colDoms[colorc].name != coldom ; colorc++);
		if(colorc == MyGspn->colDoms.size())
			cerr << "Unknown classe '" << coldom << "'"<< endl;
		else st->append(MyGspn->colDoms[colorc].cname());*/
	}else if(it->compare("name")==0) {
		string varname= *simplifyString(*(it.begin()));
		vector<colorVariable>::const_iterator vars;
		for (vars = MyGspn->colVars.begin() ;
			 vars != MyGspn->colVars.end() && vars->name != varname; ++vars);
		if(vars != MyGspn->colVars.end()){
			tok.field.push_back(vars - MyGspn->colVars.begin());
			tok.isVar.push_back(true);
			tok.varIncrement.push_back(0);
			vardom.insert(vars-MyGspn->colVars.begin());
		}else{
			cerr << "Unknown variable '" << varname << "'"<< endl;
		}
	}
}


int eval_str (string s){
	string* val = simplifyString(s);
	int intval = atoi( (*val).c_str() );
	delete val;
	return intval;
}

int MyModelHandler::eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator it )
{
    if(verbose>1)cout<< (*it) << endl;
	if((*it).compare("expr")==0){
		//cout << *(it.begin()) << endl;
		return eval_intFormula(intconst,it.begin());
	}else if((*it).compare("intValue")==0){
		return eval_str(it.node->first_child->data);
	}else if((*it).compare("numValue")==0){
		return eval_str(it.node->first_child->data);
	}else if ((*it).compare("name")==0) {
		string* val = simplifyString(it.node->first_child->data);
		int intval = intconst[(*val).c_str()];
		delete val;
		return intval;
	}else if ((*it).compare("+")==0 || (*it).compare("*")==0  
			  || (*it).compare("min")==0  || (*it).compare("max")==0
			  || (*it).compare("power")==0|| (*it).compare("-")==0)  {
		
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
		else cout << "faileval int Formula" <<endl;
	} else if(simplifyString(*it)->compare("")==0)return 0;
	
	cout << "fail eval int formula" <<endl;
	throw(gmlioexc);
}

treeSI findbranch(treeSI t, string branch){
    if( branch.compare("")==0)return t;
    int nextnode = branch.find_first_of("/");
    for (treeSI it = (t.begin()) ; it != (t.end()) ; ++it) {
        if((*it).compare(branch.substr(0,nextnode))==0){
            return findbranch(it, branch.substr(nextnode+1,branch.length()-nextnode-1));
        }
    }
    return t.end();
}


MyModelHandler::MyModelHandler(GSPN* MyGspn2,bool re) {
	//Initialisation
    verbose = 0;
    rareEvent = re;
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
    if(verbose>0)cout << "read model : formalism = " << formalismUrl << endl;
}

void MyModelHandler::on_read_model_attribute(const Attribute& attribute) {
    // read model attribute 
    // If the file is well formed the only attributes are constant declaration.
    
    for(treeSI it = attribute.begin(); it != attribute.end(); ++it) {
        if(verbose>1)cout << *it << ":" << endl;
        if((*it).compare("declaration")==0){
            treeSI t1 = findbranch(it, "constants/intConsts/");
			if(t1 != it.end())
            for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
                if(verbose>1)cout << "\t" <<  *it2 << ":" << endl;
                if ((*it2).compare("intConst")==0) { // const is int or double
                    string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
                    int constvalue = eval_intFormula(MyGspn->IntConstant, find(it2.begin(),it2.end(),"expr"));
                    if(verbose>1)cout << "const int " << *constname << "=" << constvalue << endl;;
                    
                    //Evaluate_gml.parse(constvalue);
                    MyGspn->IntConstant[*constname]=constvalue; //Evaluate_gml.IntResult;
                    MyGspn->RealConstant[*constname]= constvalue; //Evaluate_gml.RealResult;
                    //cout << "\tconst int " << *constname << "=" << constvalue << endl;
                    
                } 
            }
            
            treeSI t2 = findbranch(it, "constants/realConsts/");
			if(t2 != it.end())
            for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
                if(verbose>1)cout << "\t" <<  *it2 << ":" << endl;
                if ((*it2).compare("realConst")==0) {
                    if(verbose>1)cout << "\t" <<  *it2 << ":" << endl;
                    string* constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
                    bool ismarkdep=false;
                    string constvalue;
                    eval_expr( &ismarkdep, &constvalue, find(it2.begin(),it2.end(),"expr").begin());
                    if(ismarkdep)cout<< "constante are not makring dependant!" << endl;
                    Evaluate_gml.parse(constvalue);
                    MyGspn->RealConstant[*constname]=Evaluate_gml.RealResult;
                    if(verbose>1)cout << "\tconst double " << *constname << "=" << Evaluate_gml.RealResult << endl;
                } 
            }
			
			for(t2 =it.begin(); t2 != it.end() ; ++t2){
				if(verbose>1)cout << endl <<  *t2 << ": " << endl;
				if((*t2).compare("classDeclaration")==0){
					colorClass cc;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if(verbose>1)cout << "\t" <<  *it2 << ": " ;
						if((*it2).compare("name")==0){
							cc.name = *simplifyString(*(it2.begin()));
							if(verbose>1)cout << *(it2.begin());
						}
						if((*it2).compare("classType")==0){
							treeSI tclasstypeenum = find(it2.begin(),it2.end(),"classEnum");
							if(tclasstypeenum!= it2.end())
								for (treeSI it3 = (tclasstypeenum.begin()) ;
									 it3 != (tclasstypeenum.end()) ; ++it3 ) {
									string col = *simplifyString(*(it3.begin()));
									if(verbose>1)cout << "\t\t\t" << col << endl;
									cc.colors.push_back(color(col));
								}
							
							tclasstypeenum = find(it2.begin(),it2.end(),"classIntInterval");
							if(tclasstypeenum!= it2.end()){
								int low,high;
								treeSI intBound = find(tclasstypeenum.begin(),tclasstypeenum.end(),"lowerBound");
								
								
								/////////////////
								//					Implement Interval Color Class here
								/*treeSI tclasstypeinterval = find(it2.begin(),it2.end(),"classIntInterval");
								 if(tclasstypeinterval != it2.end())
								 string *simplifyString((find(it2.begin(),it2.end(),"higherBound")).node->first_child->data)
								 */
								cerr << "Color Interval not yet implemented";
								
								
								
							}
								

							
						}
						if((*it2).compare("circular")==0){
							if(simplifyString(*(it2.begin()))->compare("true")==0)
								cc.isCircular = true;
							if(verbose>1)cout << *(it2.begin());
						}
					}
					colorDomain cd;
					cd.name = cc.name;
					cd.colorClassIndex.push_back(MyGspn->colClasses.size());
					MyGspn->colClasses.push_back(cc);
					MyGspn->colDoms.push_back(cd);
				}
				
				if((*t2).compare("domainDeclaration")==0){
					colorDomain cd;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if(verbose>1)cout << "\t" <<  *it2 << ": " ;
						if((*it2).compare("name")==0){
							cd.name = *simplifyString(*(it2.begin()));
							if(verbose>1)cout << *(it2.begin());
						}
						if((*it2).compare("domainType")==0){
							treeSI tclasstypeenum = find(it2.begin(),it2.end(),"cartesianProduct");
							if(tclasstypeenum!= it2.end())
								for (treeSI it3 = (tclasstypeenum.begin()) ;
									 it3 != (tclasstypeenum.end()) ; ++it3 ) {
									string colclass = *simplifyString(*(it3.begin()));
									if(verbose>1)cout << endl << "\t\t\t" << colclass ;
									size_t colorc =0;
									for(colorc =0; colorc < MyGspn->colClasses.size() &&
										MyGspn->colClasses[colorc].name != colclass ; colorc++);
									if(colorc == MyGspn->colClasses.size())
										cerr << "Unknown classe '" << colclass << "'"<< endl;
									else cd.colorClassIndex.push_back(colorc);
								}
						}
					}
					MyGspn->colDoms.push_back(cd);
				}
				if((*t2).compare("variableDeclaration")==0){
					colorVariable cv;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if(verbose>1)cout << "\t" <<  *it2 << ": " ;
						if((*it2).compare("name")==0){
							cv.name = *simplifyString(*(it2.begin()));
							if(verbose>1)cout << *(it2.begin());
						}
						if((*it2).compare("type")==0){
							string colclass = *simplifyString(*(it2.begin()));
							if(verbose>1)cout << "\t\t" << colclass << endl; ;
							size_t colorc =0;
							for(colorc =0; colorc < MyGspn->colDoms.size() &&
								MyGspn->colDoms[colorc].name != colclass ; colorc++);
							if(colorc == MyGspn->colDoms.size())
								cerr << "Unknown Domaine '" << colclass << "'"<< endl;
							else cv.type=colorc;
							
						}
					}
					MyGspn->colVars.push_back(cv);
				}
			}
		}
	}
}

void MyModelHandler::on_read_node(const XmlString& id,
                                  const XmlString& nodeType,
                                  const AttributeMap& attributes,
                                  const XmlStringList& references) {
    // Read node of the graph. If the file is well formed it
    // contain only plate and transition.
    
    if(verbose>1)cout << "read node : " << id << ", " << nodeType << endl;
    if(nodeType.compare("place")==0){
        // Read a Place:
        
        MyGspn->pl++;
        int id2 = atoi(id.c_str());
        IsPlace[id2]=true;
        Gml2Place[id2]=countPl;
		place p;
		
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
			treeSI it2 = it->second.begin();
            if(it2->compare("marking")==0){
				bool markdep=false;
				string st;
				for(treeSI ittok = it2.begin(); ittok != it2.end(); ++ittok){
					if (ittok->compare("token")==0) {
						if(st.compare("")!=0)st.append((" + "));
						eval_tokenProfileMark(&st, ittok);
						
					}
				}
				if(markdep){cerr <<"Marking can not be marking dependant";
					throw gmlioexc;
				}
				if (st.compare("")==0) {
					int mark = 0;
					mark = eval_intFormula(MyGspn->IntConstant, it2.begin());
					st.append(itostring(mark));
				}
				
				if(verbose>1)cout << "\tmarking:" << st << endl ;
				MyGspn->Marking.push_back(st);
				
			} else if(it2->compare("name")==0){
				string* Plname = simplifyString(*(it2.begin()));
				if(verbose>1)cout << "\tname:" << *Plname << endl ;
				p.name = *Plname;
				MyGspn->PlacesId[*Plname]=countPl;
			
            } else if((*(it->second.begin())).compare("domain")==0){
                string* Pldomain = simplifyString(*(it2.begin().begin()));
                if(verbose>1)cout << "\tdomain:" << *Pldomain << endl ;
				size_t colord =0;
				for(colord =0; colord < MyGspn->colDoms.size() &&
					MyGspn->colDoms[colord].name != *Pldomain ; colord++);
				if(colord == MyGspn->colDoms.size())
					cerr << "Unknown Domain '" << *Pldomain << "'"<< endl;
				else p.colorDom=colord;
                
            } else throw(gmlioexc);
            
        }
		MyGspn->placeStruct.push_back(p);
        countPl++ ;
		
    }else {
        if (nodeType.compare("transition")==0){
            //Read a transition:
            MyGspn->tr++;
            int id2 = atoi(id.c_str());
            IsPlace[id2]=false;
            Gml2Trans[id2]=countTr;
			
			transition trans;
			trans.label = "";
			trans.type = Timed;
			trans.priority = "1";
			trans.weight = "1";
			trans.singleService = true;
			trans.markingDependant = false;
			trans.ageMemory = false;
			trans.nbServers = 1;
			
            for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
                if((*(it->second.begin())).compare("name")==0){
                    string* Trname = simplifyString(*(++(it->second.begin())));
                    if(verbose>1)cout << "\tname:" << *Trname << endl ;
                    MyGspn->TransList.insert(*Trname);
					trans.label = *Trname;
                    MyGspn->TransId[*Trname]=countTr;
                } else if((*(it->second.begin())).compare("guard")==0){
					cerr << endl << "Colored guard on transition not yet implemented"<< endl;
                } else if ((*(it->second.begin())).compare("distribution")==0) {
                    if(verbose>1)cout << "\tdistribution:" << endl ;
                    for (treeSI it2 = (it->second.begin()).begin() ; it2 != (it->second.begin()).end() ; ++it2 ) {
                        if(verbose>1)cout << "\t" << (*it2) << ":" << endl;
                        if ((*it2).compare("type")==0) {
                            string* Trtype = simplifyString(*(it2.begin()));
                            if((*Trtype).compare("IMDT")==0)trans.type=unTimed;
                            trans.dist.name = *Trtype;
                            if(verbose>1)cout << "\t\t" << *Trtype << endl;
                        } else if ((*it2).compare("param")==0) {
                            
                            //int number = 0;
                            string* value = new string("");
                            for (treeSI it3 = it2.begin() ; it3 != it2.end() ; ++it3 ) {
                                //string* leaf = simplifyString(*(it3.begin()));
                                if ((*it3).compare("number")==0) {
                                    //number = atoi((*leaf).c_str());
                                } else if ((*it3).compare("expr")==0) {
                                    eval_expr(&trans.markingDependant, value, it3.begin() );
                                    trans.dist.Param.push_back(*value);
                                } else throw gmlioexc;
                            }
                        } else throw gmlioexc;
                    }
                    
                } else if ((*(it->second.begin())).compare("service")==0) {
                    bool markingdependant=false;
                    string* value = new string("");
                    if ((*(++(it->second.begin()))).compare("expr")==0) {
                        eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            if(Evaluate_gml.parse(*value)){
                                cout << " Fail to parse GML: transition,service"<< endl;
                            }
                            else {
                                int nserv=Evaluate_gml.IntResult;
                                delete value;
                                if(nserv == 1 ) {
                                    trans.nbServers =1;
                                }else {
                                    trans.singleService=false;
                                    trans.nbServers=nserv;
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
                    if ((*(++(it->second.begin()))).compare("expr")==0) {
                        eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            trans.weight = *value;
                        }else {
                            cout<<"Weight is not marking dependent "<<endl;
                        }
                    } else cout << " Fail to parse GML: transition,weight"<< endl;
                    
                    
                } else if ((*(it->second.begin())).compare("priority")==0) {
                    bool markingdependant=false;
                    string* value = new string("");
                    if ((*(++(it->second.begin()))).compare("expr")==0) {
                        eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            trans.priority = *value;
                        }else {
                            cout<<"Priority is not marking dependent "<<endl;
                        }
                    } else cout << " Fail to parse GML: transition,priority"<< endl;
                    
                    
                } else cout << "fail to parse gml"<< endl;
                
            }
            
			MyGspn->transitionStruct.push_back(trans);
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
        
        if(rareEvent){
            //Add a place
            MyGspn->Marking.push_back("0");
			place p;
            string Plname = "Puit";
			p.name = Plname;
            MyGspn->placeStruct.push_back(p);
            MyGspn->PlacesId[Plname]=MyGspn->pl;
            MyGspn->pl++;
            
            //Add a transition
			transition trans;
			trans.label = "Puittrans";
			trans.type = Timed;
			trans.dist.name =  "EXPONENTIAL";
			trans.dist.Param.push_back("0");
			trans.priority = "1";
			trans.weight = "1";
			trans.singleService = true;
			trans.markingDependant = true;
			trans.ageMemory = false;
			trans.nbServers = 1;
			MyGspn->transitionStruct.push_back(trans);
			
            MyGspn->TransList.insert(trans.label);
            MyGspn->tr++;
        }
        
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
        
    }
    
    if(verbose>1)cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
    string valuation;
	vector<coloredToken> toklist;
    //cout << arcType << endl;
    int sourceGML = atoi(source.c_str());
    for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
		treeSI it2 = it->second.begin();
        if(it2->compare("valuation")==0){
            bool markingdependant=false;
			for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
				if (it3->compare("expr")==0) {
					eval_expr(&markingdependant, &valuation, it3.begin() );
				} else if (it3->compare("token")==0) {
					coloredToken tokenType;
					if (IsPlace[sourceGML]) {
						eval_tokenProfileArc( tokenType, markingdependant,MyGspn->transitionStruct[Gml2Trans[atoi(target.c_str())]].varDomain, it3);
					} else {
						eval_tokenProfileArc( tokenType, markingdependant,MyGspn->transitionStruct[Gml2Trans[atoi(source.c_str())]].varDomain, it3);
					}
					
					size_t coldom;
					if(IsPlace[sourceGML])
						coldom = MyGspn->placeStruct[Gml2Place[sourceGML]].colorDom;
					else coldom = MyGspn->placeStruct[Gml2Place[atoi(target.c_str())]].colorDom;
					
					if (toklist.size()>0)valuation.append(" + ");
					valuation.append(MyGspn->colDoms[coldom].tokname());
					valuation.append("(");
					for (size_t pr = 0; pr < tokenType.field.size() ; pr++) {
						if(pr>0)valuation.append(", ");
						valuation.append( "b.P->"+MyGspn->colVars[tokenType.field[pr]].name);
						if(tokenType.varIncrement[pr] != 0){
							valuation.append(".next(");
							valuation.append(itostring(tokenType.varIncrement[pr]));
							valuation.append(")");
						}
					}
					valuation.append(") * ");
					valuation.append(tokenType.mult);
					toklist.push_back(tokenType);
				} else cout << " Fail to parse GML: arc,valuation"<< endl;
            }
        }else cout << "fail to parse gml"<< endl;
        
    }
    if(IsPlace[sourceGML]){
        if(arcType.compare("inhibitorarc")==0){
            if(Evaluate_gml.parse(valuation)){
                MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
                MyGspn->inhibArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]= valuation;
            }
            else {	
                MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
            }
            //MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        }else {
            if(Evaluate_gml.parse(valuation)){
                MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
                MyGspn->inArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
            }
            else {
                MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
            }
            //MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        }
    }else {
        if(Evaluate_gml.parse(valuation)){
            MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=1;
            MyGspn->outArcsStr[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
        }
        else {
            MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=Evaluate_gml.IntResult;
        }
        //MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
    }
    
    
    /*for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
     cout << "    ref => " << *it << endl;
     }*/
}
