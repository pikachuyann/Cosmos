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

string MyModelHandler::itostring (int i){
	stringstream ss;
	ss << i;
	return ss.str();
}

string MyModelHandler::simplifyString(string str)
{
	size_t n1 = str.find_first_not_of(" \n\t");
	size_t n2 = str.find_last_not_of(" \n\t");
	if(n1 ==std::string::npos )return "";
	return str.substr(n1, n2-n1+1);
}

void MyModelHandler::appendSimplify(string &st, string str)
{
	size_t n1 = str.find_first_not_of(" \n\t");
	size_t n2 = str.find_last_not_of(" \n\t");
	if(n1 !=std::string::npos )st.append(str.substr(n1, n2-n1+1));
}

expr MyModelHandler::eval_expr(bool *is_mark_dep, string &st, tree<string>::pre_order_iterator it)
{
    if((P.verbose-3)>1)cout << *it << endl;
	if( *it == "function"){
		return eval_expr(is_mark_dep, st, it.begin());
	}else if(*it == "expr"){
		return eval_expr(is_mark_dep, st, it.begin());
	}else if(*it == "intValue" || *it == "numValue"){
        const auto str = simplifyString(it.node->first_child->data);
        st.append(str);
        if(*it=="intValue")return expr(stoi(str));
        else return expr(stod(str));
	}else if (*it == "name") {
        string var = simplifyString(it.node->first_child->data);
        if(MyGspn->IntConstant.count(var)>0 ||
           MyGspn->RealConstant.count(var)>0){
            st.append(var);
            return expr(Constant,var);
        }else{
            *is_mark_dep =true;
            st.append("Marking.P->_PL_");
            st.append(var);
			if((P.verbose-3)>1)cout << "\t" << var << endl;
			if(MyGspn->PlacesId.count(var)==0){
				cerr << "Place " << var << "being referenced before being define" << endl;
				throw gmlioexc;
			}
			if(MyGspn->placeStruct[MyGspn->PlacesId[var]].colorDom !=0 ){
                st.append(".card()");
                return expr(PlaceName,var+".card()");
            }else return expr(PlaceName,var);
        }
	}else if (	*it == "+"  || *it == "*"
              || *it == "min"   || *it == "max"
              || *it == "floor" || *it == "minus"
              || *it == "/"   || *it == "power")  {
		
		
		if (*it == "min") st.append("min");
		if (*it == "max") st.append("max");
		if (*it == "floor" ) st.append("floor");

        expr rhs;
        expr lhs;

		st.append("(");
		for (treeSI it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
			if(it2!= it.begin()) {
				if (*it == "+") { st.append("+"); }
				else if (*it == "*") { st.append("*"); }
				else if (*it == "-") { st.append("-"); }
				else if (*it == "/") { st.append("/ (double) "); }
				else if (*it == "power") { st.append("^"); }
				else st.append(",");
                rhs = eval_expr(is_mark_dep, st, it2);
			}else{
                lhs = eval_expr(is_mark_dep, st, it2);
            };

		}
		st.append(")");

        if (*it == "+") { return expr(Plus,lhs,rhs); }
        else if (*it == "*") { return expr(Times,lhs,rhs); }
        else if (*it == "-") { return expr(Minus,lhs,rhs); }
        else if (*it == "/") { return expr(Floor,lhs,rhs); }
        else if (*it == "power") { return expr(Pow,lhs,rhs); }
        else if (*it == "ceil") { return expr(Ceil,lhs,rhs); }
        else { return expr(Floor,lhs,rhs); }

	} else if(simplifyString(*it).empty())return expr(0);

    try {
        return expr(stoi(simplifyString(*it)));
    } catch (const invalid_argument& ia){
        cout << "fail eval expr: '" << *it << "'" <<endl;
        throw(gmlioexc);
    }
}

void MyModelHandler::eval_tokenProfileMark(coloredToken& tok,tree<string>::pre_order_iterator it){
	if((P.verbose-3)>1)cout << *it << endl;
	if(*it == "function"){
		eval_tokenProfileMark(tok, it.begin());
	}else if(*it == "expr"){
		eval_tokenProfileMark(tok, it.begin());
	}else if(*it == "enumConst"){
		size_t colorclass=0, enumvalue=0;
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "type"){
				string coldom = simplifyString(*(it2.begin()));
				if((P.verbose-3)>1)cerr << coldom << endl;
				for(colorclass =0; colorclass < MyGspn->colDoms.size() &&
					MyGspn->colDoms[colorclass].name != coldom ; colorclass++) ;
				if(colorclass == MyGspn->colDoms.size())
					cerr << "Unknown classe '" << coldom << "'"<< endl;
			}
			if (*it2 == "enumValue") {
				string coldom = simplifyString(*(it2.begin()));
				if((P.verbose-3)>1)cerr << coldom << endl;
				colorClass col = MyGspn->colClasses[MyGspn->colDoms[colorclass].colorClassIndex[0]];
				for(enumvalue =0; enumvalue < col.colors.size() &&
					col.colors[enumvalue].name != coldom ; enumvalue++) ;
				if(enumvalue == col.colors.size())
					cerr << "Unknown classe '" << coldom << "'"<< endl;
			}
		}
        tok.field.push_back(enumvalue);
        tok.Flags.push_back(CT_SINGLE_COLOR);
        tok.varIncrement.push_back(0);
		
	}else if(*it == "all"){
        tok.hasAll=true;
        tok.field.push_back(0);
        tok.Flags.push_back(CT_ALL);
        tok.varIncrement.push_back(0);
		eval_tokenProfileMark(tok, it.begin());
	}else if(*it == "type"){
		string coldom = simplifyString(*(it.begin()));
		if((P.verbose-3)>1)cerr << coldom << endl;
		size_t colorc =0;
		for(colorc =0; colorc < MyGspn->colDoms.size() &&
			MyGspn->colDoms[colorc].name != coldom ; colorc++) ;
		if(colorc == MyGspn->colDoms.size())
			cerr << "Unknown classe '" << coldom << "'"<< endl;
	}else if (*it == "token") {
		string mark;
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "occurs"){
				bool markingdependant = false;
				eval_expr(&markingdependant, mark, it2.begin());
				if( markingdependant) cerr << "Initial Marking is not marking dependant\n";
			}
			if (*it2 == "tokenProfile") {
				if ((P.verbose-3)>1)cout << *it2 << endl;
				for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
					eval_tokenProfileMark(tok, it3);
				}
			}
		}
        tok.mult = mark;
	}
}

void MyModelHandler::eval_tokenProfileArc( coloredToken& tok, bool &markingdependant ,set<size_t>& vardom, tree<string>::pre_order_iterator it){
	if((P.verbose-3)>1)cout << (*it) << endl;
	if(*it == "function"){
		eval_tokenProfileArc(tok, markingdependant, vardom, it.begin());
	}else if(*it == "++"){
		int incr = 0;
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "name"){
				eval_tokenProfileArc(tok, markingdependant, vardom, it2);
			} else incr = atoi(simplifyString(*(it2).begin()).c_str());
		}
		tok.varIncrement.back() += incr;
	}else if(*it == "all"){
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "type"){
				string colname= simplifyString(*(it2.begin()));
				vector<colorClass>::const_iterator cols;
				for (cols = MyGspn->colClasses.begin() ;
					 (cols != MyGspn->colClasses.end() && cols->name != colname); ++cols) ;
				if(cols != MyGspn->colClasses.end()){
					tok.field.push_back(cols - MyGspn->colClasses.begin());
					tok.Flags.push_back(CT_ALL);
					tok.varIncrement.push_back(0);
					tok.hasAll = true;
				}else{
					cerr << "Unknown colorClasse '" << colname << "'"<< endl;
				}
			}
		}
		
	}else if(*it == "expr"){
		eval_tokenProfileArc(tok,markingdependant, vardom, it.begin());
	}else if (*it == "token") {
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "occurs"){
				eval_expr(&markingdependant, tok.mult, it2.begin());
			}
			if (*it2 == "tokenProfile") {
				if ((P.verbose-3)>1)cout << *it2 << endl;
				for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
					eval_tokenProfileArc(tok,markingdependant, vardom, it3);
				}
			}
		}
	} else if(*it == "type"){
		string colname= simplifyString(*(it.begin()));
		vector<colorClass>::const_iterator cols;
		for (cols = MyGspn->colClasses.begin() ;
			 cols != MyGspn->colClasses.end() && cols->name != colname; ++cols) ;
		if(cols != MyGspn->colClasses.end()){
			tok.field.push_back(cols - MyGspn->colClasses.begin());
			tok.Flags.push_back(CT_SINGLE_COLOR);
			tok.varIncrement.push_back(0);
		}else{
			cerr << "Unknown color '" << colname << "'"<< endl;
		}
		
	}else if(*it == "name") {
		string varname= simplifyString(*(it.begin()));
		vector<colorVariable>::const_iterator vars;
		for (vars = MyGspn->colVars.begin() ;
			 vars != MyGspn->colVars.end() && vars->name != varname; ++vars) ;
		if(vars != MyGspn->colVars.end()){
			tok.field.push_back(vars - MyGspn->colVars.begin());
			tok.Flags.push_back(CT_VARIABLE);
			tok.varIncrement.push_back(0);
			vardom.insert(vars-MyGspn->colVars.begin());
		}else{
			cerr << "Unknown variable '" << varname << "'"<< endl;
		}
	}
}

int MyModelHandler::eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator it )
{
    bool markdep=false;
    string st;
    expr ex = eval_expr(&markdep, st, it);
    map<string,double> dummyrealconst;
    ex.eval(intconst, dummyrealconst);
    if(ex.t == Int){
        return ex.intVal;
    } else {
        if (ex.t == Real){
            if(ex.realVal == ceil(ex.realVal)){
                return (int)ex.realVal;
            }else{
                cerr <<"Marking should be an integer: " << ex.realVal << endl; ;
                throw gmlioexc;
            }
        }else{
            cerr <<"Marking can not be marking dependant:" << endl << ex << endl; ;
            throw gmlioexc;
        }
    }
}

treeSI MyModelHandler::findbranch(treeSI t, string branch){
    if( branch == "")return t;
    size_t nextnode = branch.find_first_of("/");
    for (treeSI it = (t.begin()) ; it != (t.end()) ; ++it) {
        if(it->compare(branch.substr(0,nextnode))==0){
            return findbranch(it, branch.substr(nextnode+1,branch.length()-nextnode-1));
        }
    }
    return t.end();
}

void MyModelHandler::eval_guard(string& st, tree<string>::pre_order_iterator it){
	if((P.verbose-3)>1)cout<< (*it) << endl;
	if(*it == "boolExpr"){
		eval_guard(st, it.begin() );
	} else if(*it == "boolValue"){
		if(simplifyString(*(it.begin())) == "true")st.append(" true ");
		else st.append(" false ");
	} else if(*it == "equal"){
		st.append("(");
		eval_guard(st, it.begin());
		st.append(" == ");
		eval_guard(st, ++it.begin());
		st.append(" ) ");
	} else if(*it == "notEqual"){
		st.append("(");
		eval_guard(st, it.begin());
		st.append(" != ");
		eval_guard(st, ++it.begin());
		st.append(" ) ");
	} else if(*it == "and"){
		st.append("(");
		eval_guard(st, it.begin());
		st.append(" && ");
		eval_guard(st, ++it.begin());
		st.append(" ) ");
	} else if(*it == "or"){
		st.append("(");
		eval_guard(st, it.begin());
		st.append(" || ");
		eval_guard(st, ++it.begin());
		st.append(" ) ");
	} else if(*it == "not"){
		st.append("( !(");
		eval_guard(st, it.begin());
		st.append(" )) ");
	} else if(*it == "expr"){
		eval_guard(st, it.begin() );
	} else if(*it == "name"){
		string varname = simplifyString(*(it.begin()));
		vector<colorVariable>::const_iterator vars;
		for (vars = MyGspn->colVars.begin() ;
			 vars != MyGspn->colVars.end() && vars->name != varname; ++vars) ;
		if(vars != MyGspn->colVars.end()){
			st.append("bl.P->");
			st.append(varname);
			st.append(".c0");
		}else{
			cerr << "Unknown variable '" << varname << "'"<< endl;
		}
	}else if(*it == "enumConst"){
		string typestr;
		string colorstr;
		for (treeSI it2 = it.begin() ; it2 != it.end() ; ++it2 ) {
			if(*it2 == "type"){
				typestr = simplifyString(*(it2.begin()));
			}
			if (*it2 == "enumValue") {
				colorstr = simplifyString(*(it2.begin()));
			}
		}
		st.append("Color_"+typestr+"_"+colorstr);
	}else cerr << "Unknown attribute "<< *it << "\n";
}


MyModelHandler::MyModelHandler(GspnType &MyGspn2,parameters &Q):MyGspn(&MyGspn2), P(Q) {
	MyGspn->tr=0;
	ParsePl=true;
	if(MyGspn->nbpass==0){
		//Initialisation
		MyGspn->pl=0;
	}
}
//~MyModelHandler() { }
MyModelHandler::MyModelHandler(GspnType &MyGspn2,parameters &Q ,map<int,bool> &mip,map<int,int> &mgp,map<int,int> &mgt):IsPlace(mip),Gml2Place(mgp),Gml2Trans(mgt),MyGspn(&MyGspn2), P(Q) {
	MyGspn->tr=0;
	ParsePl=true;
	if(MyGspn->nbpass==0){
		//Initialisation
		MyGspn->pl=0;
	}
}



void MyModelHandler::on_read_model(const XmlString& formalismUrl) {
	// output used formalism
    ParsePl=true;
    if((P.verbose-3)>0)cout << "read model : formalism = " << formalismUrl << endl;
}

void MyModelHandler::on_read_model_attribute(const Attribute& attribute) {
	if(MyGspn->nbpass==1)return;
	
    // read model attribute
    // If the file is well formed the only attributes are constant declaration.
    
    for(treeSI it = attribute.begin(); it != attribute.end(); ++it) {
        if((P.verbose-3)>1)cout << *it << ":" << endl;
        if(*it == "declaration"){
            treeSI t1 = findbranch(it, "constants/intConsts/");
			if(t1 != it.end())
				for (treeSI it2 = (t1.begin()) ; it2 != (t1.end()) ; ++it2 ) {
					if((P.verbose-3)>1)cout << "\t" <<  *it2 << ":" << endl;
					if (*it2 == "intConst") { // const is int or double
						string constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						int constvalue = eval_intFormula(MyGspn->IntConstant, find(it2.begin(),it2.end(),"expr"));
						if((P.verbose-3)>1)cout << "const int " << constname << "=" << constvalue << endl;
						if (P.constants.count(constname)>0) {
							istringstream(P.constants[constname]) >> constvalue;
							if((P.verbose-3)>0)cout << "const int " << constname << " overwrite to " << constvalue << endl;;
						}
						//Evaluate_gml.parse(constvalue);
						MyGspn->IntConstant[constname]=constvalue; //Evaluate_gml.IntResult;
						MyGspn->RealConstant[constname]= constvalue; //Evaluate_gml.RealResult;
						//cout << "\tconst int " << *constname << "=" << constvalue << endl;
						
					}
				}
            
            treeSI t2 = findbranch(it, "constants/realConsts/");
			if(t2 != it.end())
				for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
					if((P.verbose-3)>1)cout << "\t" <<  *it2 << ":" << endl;
					if (*it2 == "realConst") {
						if((P.verbose-3)>1)cout << "\t" <<  *it2 << ":" << endl;
						string constname = simplifyString((find(it2.begin(),it2.end(),"name")).node->first_child->data);
						bool ismarkdep=false;
						string constvalue;
						eval_expr( &ismarkdep, constvalue, find(it2.begin(),it2.end(),"expr").begin());
						if(ismarkdep)cout<< "constante are not makring dependant!" << endl;
						if (P.constants.count(constname)>0) {
							constvalue = P.constants[constname];
							if((P.verbose-3)>0)cout << "const double " << constname << " overwrite to " << constvalue << endl;;
						}
						Evaluate_gml.parse(constvalue);
						MyGspn->RealConstant[constname]=Evaluate_gml.RealResult;
						if((P.verbose-3)>1)cout << "\tconst double " << constname << "=" << MyGspn->RealConstant[constname] << endl;
						
					}
				}
			
			for(t2 =it.begin(); t2 != it.end() ; ++t2){
				if((P.verbose-3)>1)cout << endl <<  *t2 << ": " << endl;
				if(*t2 == "classDeclaration"){
					colorClass cc;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if((P.verbose-3)>1)cout << "\t" <<  *it2 << ": " ;
						if(*it2 == "name"){
							cc.name = simplifyString(*(it2.begin()));
							if((P.verbose-3)>1)cout << *(it2.begin());
						}
						if(*it2 == "classType"){
							treeSI tclasstypeenum = find(it2.begin(),it2.end(),"classEnum");
							if(tclasstypeenum!= it2.end())
								for (treeSI it3 = (tclasstypeenum.begin()) ;
									 it3 != (tclasstypeenum.end()) ; ++it3 ) {
									string col = simplifyString(*(it3.begin()));
									if((P.verbose-3)>1)cout << "\t\t\t" << col << endl;
									cc.colors.push_back(color(col,cc.colors.size(),MyGspn->colClasses.size()));
								}
							
							tclasstypeenum = find(it2.begin(),it2.end(),"classIntInterval");
							if(tclasstypeenum!= it2.end()){
								int low,high;
								treeSI intBound = find(tclasstypeenum.begin(),tclasstypeenum.end(),"lowerBound");
								low = eval_intFormula(MyGspn->IntConstant, intBound.begin());
								intBound = find(tclasstypeenum.begin(),tclasstypeenum.end(),"higherBound");
								high = eval_intFormula(MyGspn->IntConstant, intBound.begin());
								
								for(int i = low ; i<= high ;i++){
									stringstream ss;
									ss << cc.name << "_IC_" << i;
									cc.colors.push_back(color(ss.str(),cc.colors.size(),MyGspn->colClasses.size()));
								}
								
							}
							
						}
						if(*it2 == "circular"){
							if(simplifyString(*(it2.begin())) == "true")
								cc.isCircular = true;
							if((P.verbose-3)>1)cout << *(it2.begin());
						}
					}
					colorDomain cd;
					cd.name = cc.name;
					cd.colorClassIndex.push_back(MyGspn->colClasses.size());
					MyGspn->colClasses.push_back(cc);
					MyGspn->colDoms.push_back(cd);
				}
				
				if(*t2 == "domainDeclaration"){
					colorDomain cd;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if((P.verbose-3)>1)cout << "\t" <<  *it2 << ": " ;
						if(*it2 == "name"){
							cd.name = simplifyString(*(it2.begin()));
							if((P.verbose-3)>1)cout << *(it2.begin());
						}
						if(*it2 == "domainType"){
							treeSI tclasstypeenum = find(it2.begin(),it2.end(),"cartesianProduct");
							if(tclasstypeenum!= it2.end())
								for (treeSI it3 = (tclasstypeenum.begin()) ;
									 it3 != (tclasstypeenum.end()) ; ++it3 ) {
									string colclass = simplifyString(*(it3.begin()));
									if((P.verbose-3)>1)cout << endl << "\t\t\t" << colclass ;
									size_t colorc =0;
									for(colorc =0; colorc < MyGspn->colClasses.size() &&
										MyGspn->colClasses[colorc].name != colclass ; colorc++) ;
									if(colorc == MyGspn->colClasses.size())
										cerr << "Unknown classe '" << colclass << "'"<< endl;
									else cd.colorClassIndex.push_back(colorc);
								}
						}
					}
					MyGspn->colDoms.push_back(cd);
				}
				if(*t2 == "variableDeclaration"){
					colorVariable cv;
					for (treeSI it2 = (t2.begin()) ; it2 != (t2.end()) ; ++it2 ) {
						if((P.verbose-3)>1)cout << "\t" <<  *it2 << ": " ;
						if(*it2 == "name"){
							cv.name = simplifyString(*(it2.begin()));
							if((P.verbose-3)>1)cout << *(it2.begin());
						}
						if(*it2 == "type"){
							string colclass = simplifyString(*(it2.begin()));
							if((P.verbose-3)>1)cout << "\t\t" << colclass << endl; ;
							size_t colorc =0;
							for(colorc =0; colorc < MyGspn->colDoms.size() &&
								MyGspn->colDoms[colorc].name != colclass ; colorc++) ;
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
                                  const XmlStringList&) {
    // Read node of the graph. If the file is well formed it
    // contain only place and transition.
    
    if((P.verbose-3)>1)cout << "read node : " << id << ", " << nodeType << endl;
    if(nodeType == "place"){
		if(MyGspn->nbpass==1)return;
		
        // Read a Place:
        
        MyGspn->pl++;
        int id2 = atoi(id.c_str());
        IsPlace[id2]=true;
        Gml2Place[id2]=MyGspn->pl-1;
		place p;
		p.name = id;
		p.id = MyGspn->placeStruct.size();
		
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
			treeSI it2 = it->second.begin();
            if(*it2 == "marking"){
                vector<coloredToken> inMark;
				bool markdep=false;

				for(treeSI ittok = it2.begin(); ittok != it2.end(); ++ittok){
					if (*ittok == "token") {
                        coloredToken tok;
						eval_tokenProfileMark(tok, ittok);
                        /*bool markingdependant;
                        eval_tokenProfileArc( tok, &markingdependant, , ittok);*/
						inMark.push_back(tok);
					}
				}
				if(markdep){cerr <<"Marking can not be marking dependant";
					throw gmlioexc;
				}
                string st;
				if (inMark.empty()) {
					int mark = 0;
					mark = eval_intFormula(MyGspn->IntConstant, it2.begin());
                    inMark.push_back(coloredToken(mark));
					st.append(itostring(mark));
				}
				
				if((P.verbose-3)>1)cout << "\tmarking:" << st << endl ;
				MyGspn->Marking.push_back(st);
                MyGspn->InitialMarking.push_back(inMark);
				
			} else if(*it2 == "name"){
				string Plname = simplifyString(*(it2.begin()));
				if((P.verbose-3)>1)cout << "\tname:" << Plname << endl ;
				p.name = Plname;
				if(MyGspn->PlacesId.count(Plname)>0){
					cerr << "error:Two places with the name:" << Plname << endl;
					throw gmlioexc;
				}
				MyGspn->PlacesId[Plname]=MyGspn->pl-1;
				
            } else if((*(it->second.begin())) == "domain"){
                string Pldomain = simplifyString(*(it2.begin().begin()));
                if((P.verbose-3)>1)cout << "\tdomain:" << Pldomain << endl ;
				size_t colord =0;
				for(colord =0; colord < MyGspn->colDoms.size() &&
					MyGspn->colDoms[colord].name != Pldomain ; colord++) ;
				if(colord == MyGspn->colDoms.size())
					cerr << "Unknown Domain '" << Pldomain << "'"<< endl;
				else p.colorDom=colord;
                
            } else throw(gmlioexc);
            
        }
		MyGspn->placeStruct.push_back(p);
		
    }else {
        if (nodeType == "transition"){
			if(MyGspn->nbpass==0)return;
            //Read a transition:
            MyGspn->tr++;
            int id2 = atoi(id.c_str());
            IsPlace[id2]=false;
            Gml2Trans[id2]=MyGspn->tr-1;
			
			transition trans;
			trans.id = MyGspn->transitionStruct.size();
			trans.label = id;
			trans.type = Timed;
			trans.priority = expr(1);
			trans.weight = expr(1.0);
			trans.singleService = true;
			trans.markingDependant = false;
			trans.ageMemory = false;
			trans.nbServers = 1;
			
            for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
                if((*(it->second.begin())) == "name"){
                    string Trname = simplifyString(*(++(it->second.begin())));
                    if((P.verbose-3)>1)cout << "\tname:" << Trname << endl ;
                    MyGspn->TransList.insert(Trname);
					trans.label = Trname;
					if(MyGspn->TransId.count(Trname)>0){
						cerr << "error:Two transitions with the name:" << Trname << endl;
						throw gmlioexc;
					}
                    MyGspn->TransId[Trname]=MyGspn->tr-1;
                } else if((*(it->second.begin())) == "guard"){
					eval_guard(trans.guard, it->second.begin().begin());
					//if(trans.guard == "")trans.guard = "true";
                } else if ((*(it->second.begin())) == "distribution") {
                    if((P.verbose-3)>1)cout << "\tdistribution:" << endl ;
                    for (treeSI it2 = (it->second.begin()).begin() ; it2 != (it->second.begin()).end() ; ++it2 ) {
                        if((P.verbose-3)>1)cout << "\t" << (*it2) << ":" << endl;
                        if (*it2 == "type") {
                            string Trtype = simplifyString(*(it2.begin()));
                            if(Trtype == "IMDT")trans.type=unTimed;
                            trans.dist.name = Trtype;
                            if((P.verbose-3)>1)cout << "\t\t" << Trtype << endl;
                        } else if (*it2 == "param") {
                            
                            //int number = 0;
                            string value;
                            for (treeSI it3 = it2.begin() ; it3 != it2.end() ; ++it3 ) {
                                //string* leaf = simplifyString(*(it3.begin()));
                                if (*it3 == "number") {
                                    //number = atoi((*leaf).c_str());
                                } else if (*it3 == "expr") {
                                    expr pe = eval_expr(&trans.markingDependant, value, it3.begin() );
                                    trans.dist.Param.push_back(pe);
                                } else throw gmlioexc;
                            }
                        } else throw gmlioexc;
                    }
                    
                } else if ((*(it->second.begin())) == "service") {
                    bool markingdependant=false;
                    string value;
                    if ((*(++(it->second.begin()))) == "expr") {
                        eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            if(Evaluate_gml.parse(value)){
                                cout << " Fail to parse GML: transition,service"<< endl;
                            }
                            else {
                                int nserv=Evaluate_gml.IntResult;
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
                    
                    /*if ((*(++(it->second.begin()))) == "Infinite") {
                     singleservice=false;
                     nbserver=INT_MAX;
                     } else {
                     int nbsrv = atoi((*(++(it->second.begin()))).c_str());
                     if (nbsrv!=1) {
                     singleservice=false;
                     nbserver=nbserver;
                     }
                     }*/
                } else if ((*(it->second.begin())) == "weight") {
                    bool markingdependant=false;
                    string value;
                    if ((*(++(it->second.begin()))) == "expr") {
                        expr e =eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            trans.weight = e;
                        }else {
                            cout<<"Weight is not marking dependent "<<endl;
                        }
                    } else cout << " Fail to parse GML: transition,weight"<< endl;
                    
                    
                } else if ((*(it->second.begin())) == "priority") {
                    bool markingdependant=false;
                    string value;
                    if ((*(++(it->second.begin()))) == "expr") {
                        expr e =eval_expr(&markingdependant, value, (++(it->second.begin())).begin() );
                        if(markingdependant==false) {
                            trans.priority = e;
                        }else {
                            cout<<"Priority is not marking dependent "<<endl;
                        }
                    } else cout << " Fail to parse GML: transition,priority"<< endl;
                    
				} else if ((*(it->second.begin())) == "ageMemory") {
					trans.ageMemory = true;
                } else cout << "fail to parse gml transition attribute"<< endl;
                
            }
			
			if(trans.dist.name == "" ){
				trans.type=unTimed;
				trans.dist.name = "EXPONENTIAL";
				trans.dist.Param.push_back(expr(0.0));
				if((P.verbose-3)>=0){
					cout << "[Warning] Transition " << trans.label;
					cout << " have no distribution.";
					cout << " Assigne exponential with parameter 1"<< endl;
				}
			}
            
			MyGspn->transitionStruct.push_back(trans);
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
                                 const XmlStringList&) {
	if(MyGspn->nbpass==0)return;
	
    if(ParsePl){
        ParsePl=false;
        
        if(P.RareEvent){
			if(P.BoundedContinuous || P.BoundedRE>0){
				//add a transition for self-loop due to uniformization
				transition trans(MyGspn->transitionStruct.size(),"selfloop",expr(0.0),true);
				MyGspn->transitionStruct.push_back(trans);
				
				MyGspn->TransId["selfloop"]=MyGspn->tr;
				MyGspn->TransList.insert(trans.label);
				MyGspn->tr++;
			}
			
			//Add a place
            MyGspn->Marking.push_back("0");
			place p;
            string Plname = "Puit";
			p.name = Plname;
			p.id = MyGspn->pl;
            MyGspn->placeStruct.push_back(p);
            MyGspn->PlacesId[Plname]=MyGspn->pl;
            MyGspn->pl++;
			
			
            //Add a transition
            transition trans(MyGspn->transitionStruct.size(),"Puittrans",expr(0.0),true);
			MyGspn->transitionStruct.push_back(trans);
			
            MyGspn->TransList.insert(trans.label);
            MyGspn->tr++;
        }
        
    }
    
    if((P.verbose-3)>1)cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
    string valuation;
	vector<coloredToken> toklist;
    //cout << arcType << endl;
    int sourceGML = atoi(source.c_str());
    for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
		treeSI it2 = it->second.begin();
        if(*it2 == "valuation"){
            bool markingdependant=false;
			for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
                if (*it3 == "expr") {
					eval_expr(&markingdependant, valuation, it3.begin() );
				} else if (*it3 == "token") {
                    coloredToken tokenType;
					tokenType.hasAll = false;
					if (IsPlace[sourceGML]) {
						eval_tokenProfileArc( tokenType, markingdependant,MyGspn->transitionStruct[Gml2Trans[atoi(target.c_str())]].varDomain, it3);
					} else {
						eval_tokenProfileArc( tokenType, markingdependant,MyGspn->transitionStruct[Gml2Trans[atoi(source.c_str())]].varDomain, it3);
					}

					toklist.push_back(tokenType);
				} else cout << " Fail to parse GML: arc,valuation"<< endl;
            }
            if (toklist.empty()){
                toklist.push_back(coloredToken(valuation));
            } else {
                valuation = "COLORED";
            }
        }else cout << "fail to parse gml"<< endl;
    }

    if(IsPlace[sourceGML]){
        if(arcType == "inhibitorarc"){
            if(Evaluate_gml.parse(valuation)){
                MyGspn->inhibArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())],Gml2Place[sourceGML]),arc(("("+valuation+")"),toklist)));
			}else {
                MyGspn->inhibArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())],Gml2Place[sourceGML]),arc(Evaluate_gml.IntResult)));
            }
            //MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        }else {
            if(Evaluate_gml.parse(valuation)){
                MyGspn->inArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())],Gml2Place[sourceGML]),arc(("("+valuation+")"),toklist)));
            }
            else {
                MyGspn->inArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())],Gml2Place[sourceGML]),arc(Evaluate_gml.IntResult)));
            }
            //MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        }
    }else {
        if(Evaluate_gml.parse(valuation)){
            MyGspn->outArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[sourceGML],Gml2Place[atoi(target.c_str())]),arc(("("+valuation+")"),toklist)));
        }
        else {
            MyGspn->outArcsStruct.insert(make_pair<pair<size_t,size_t>,arc>(MyGspn->arckey(Gml2Trans[sourceGML],Gml2Place[atoi(target.c_str())]),arc(Evaluate_gml.IntResult)));
        }
        //MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
    }
    
}
