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
#include <iomanip>
#include <boost/algorithm/string/replace.hpp>

//#include "tree.hh"
#include "tree/tree_util.hh"


#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "Gspn_gmlparser.hpp"
#include "Gspn-Reader.hpp"


Eval Evaluate_gml;

using namespace std;

gmlinputexception gmlioexc;

// Do not remove, sometime usefull for debugging
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

string MyModelHandler::simplifyString(string str) {
    size_t n1 = str.find_first_not_of(" \n\t");
    size_t n2 = str.find_last_not_of(" \n\t");
    if (n1 == std::string::npos)return "";
    auto str2 = str.substr(n1, n2 - n1 + 1);
    using boost::algorithm::replace_all;
    replace_all(str2, "&amp;", "&");
    replace_all(str2, "&lt;", "<");
    replace_all(str2, "&gt;", ">");

    return str2;
}

expr MyModelHandler::eval_expr(tree<string>::pre_order_iterator it) {
    if ((P.verbose - 3) > 1)cout << *it << endl;
    if (*it == "function") {
        return eval_expr(it.begin());
    } else if (*it == "expr") {
        return eval_expr(it.begin());
    } else if (*it == "intValue" || *it == "numValue") {
        const auto str = simplifyString(it.node->first_child->data);
        if (*it == "intValue")return expr(stoi(str));
        else return expr(stod(str));
    } else if (*it == "unParsed") {
        const auto str = simplifyString(it.node->first_child->data);
        return expr(str);
    } else if (*it == "name") {
        string var = simplifyString(it.node->first_child->data);
        if (MyGspn->IntConstant.count(var) > 0
            || MyGspn->RealConstant.count(var) > 0
            || MyGspn->ExternalConstant.count(var) > 0
            || any_of(MyGspn->hybridVars.begin(), MyGspn->hybridVars.end(), [&](const hybridVariable &v){return v.name == var;})){
            return expr(Constant, var);
        } else {
            if ((P.verbose - 3) > 1)cout << "\t" << var << endl;
            if (MyGspn->PlacesId.count(var) == 0) {
                cerr << "Identifier " << var << " unbound" << endl;
                throw gmlioexc;
            }
            if (MyGspn->placeStruct[MyGspn->PlacesId[var]].colorDom != 0) {
                return expr(PlaceName, var + ".card()");
            } else return expr(PlaceName, var);
        }
    } else if (*it == "+" || *it == "*"
            || *it == "min" || *it == "max"
            || *it == "floor" || *it == "minus" || *it == "-"
            || *it == "/" || *it == "power" || *it == "exp") {

        expr rhs;
        expr lhs;

        for (treeSI it2 = (it.begin()); it2 != (it.end()); ++it2) {
            if (it2 != it.begin()) {
                rhs = eval_expr(it2);
            } else {
                lhs = eval_expr(it2);
            };

        }

        if (!rhs.empty()){
            if (*it == "ceil") {
                return expr(Ceil, lhs, rhs);
            } else if (*it == "exp") {
                return expr(Exp, lhs, rhs);
            } else if (*it == "floor") {
                return expr(Floor, lhs, rhs);
            } else if(!lhs.empty()){
                if (*it == "+") {
                    return expr(Plus, lhs, rhs);
                } else if (*it == "*") {
                    return expr(Times, lhs, rhs);
                } else if (*it == "minus" || *it == "-") {
                    return expr(Minus, lhs, rhs);
                } else if (*it == "/") {
                    return expr(Div, lhs, rhs);
                } else if (*it == "power") {
                    return expr(Pow, lhs, rhs);
                }
            }
        }
        cout << "fail eval expr: '" << *it << "'" << endl;
        throw (gmlioexc);
    } else if (simplifyString(*it).empty()){
        return expr(0);
    } else if (it.node->parent->data =="function" ){
        if ((P.verbose - 3) > 1)cout << "newfunction:'" << *it << "'" << endl;
        expr lhs(*it);
        expr rhs;
        for (treeSI it2 = (it.begin()); it2 != (it.end()); ++it2) {
            if (it2 != it.begin()) {
                expr rhs2 = rhs;
                expr interm = eval_expr(it2);
                rhs = expr(ListContinuation,rhs2,interm);
            } else {
                rhs = eval_expr(it2);
            };
            
        }
        return expr(App, lhs, rhs);
    }
    

    try {
        return expr(stoi(simplifyString(*it)));
    } catch (const invalid_argument& ia) {
        cout << "fail eval expr: '" << *it << "'" << endl;
        throw (gmlioexc);
    }
}

void MyModelHandler::eval_tokenProfileArc(coloredToken& tok, bool &markingdependant, set<size_t>& vardom, tree<string>::pre_order_iterator it) {
    if ((P.verbose - 3) > 1)cout << (*it) << endl;
    if (*it == "function") {
        eval_tokenProfileArc(tok, markingdependant, vardom, it.begin());
    } else if (*it == "++") {
        int incr = 0;
        for (treeSI it2 = it.begin(); it2 != it.end(); ++it2) {
            if (*it2 == "name") {
                eval_tokenProfileArc(tok, markingdependant, vardom, it2);
            } else incr = atoi(simplifyString(*(it2).begin()).c_str());
        }
        tok.varIncrement.back() += incr;
    } else if (*it == "all") {
        for (treeSI it2 = it.begin(); it2 != it.end(); ++it2) {
            if (*it2 == "type") {
                string colname = simplifyString(*(it2.begin()));
                vector<colorClass>::const_iterator cols;
                for (cols = MyGspn->colClasses.begin();
                        (cols != MyGspn->colClasses.end() && cols->name != colname); ++cols);
                if (cols != MyGspn->colClasses.end()) {
                    tok.field.push_back(cols - MyGspn->colClasses.begin());
                    tok.Flags.push_back(CT_ALL);
                    tok.varIncrement.push_back(0);
                    tok.hasAll = true;
                } else {
                    cerr << "Unknown colorClasse '" << colname << "'" << endl;
                }
            }
        }

    } else if (*it == "expr") {
        eval_tokenProfileArc(tok, markingdependant, vardom, it.begin());
    } else if (*it == "token") {
        for (treeSI it2 = it.begin(); it2 != it.end(); ++it2) {
            if (*it2 == "occurs") {
                const auto e = eval_expr(it2.begin());
                markingdependant |= e.is_markDep();
                stringstream ss;
                ss << e;
                tok.mult = ss.str();
            }
            if (*it2 == "tokenProfile") {
                if ((P.verbose - 3) > 1)cout << *it2 << endl;
                for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
                    eval_tokenProfileArc(tok, markingdependant, vardom, it3);
                }
            }
        }
    } else if (*it == "type") {
        string colname = simplifyString(*(it.begin()));
        vector<colorClass>::const_iterator cols;
        for (cols = MyGspn->colClasses.begin();
                cols != MyGspn->colClasses.end() && cols->name != colname; ++cols);
        if (cols != MyGspn->colClasses.end()) {
            tok.field.push_back(cols - MyGspn->colClasses.begin());
            tok.Flags.push_back(CT_SINGLE_COLOR);
            tok.varIncrement.push_back(0);
        } else {
            cerr << "Unknown color '" << colname << "'" << endl;
        }

    } else if (*it == "name") {
        string varname = simplifyString(*(it.begin()));
        vector<colorVariable>::const_iterator vars;
        for (vars = MyGspn->colVars.begin();
                vars != MyGspn->colVars.end() && vars->name != varname; ++vars);
        if (vars != MyGspn->colVars.end()) {
            tok.field.push_back(vars - MyGspn->colVars.begin());
            tok.Flags.push_back(CT_VARIABLE);
            tok.varIncrement.push_back(0);
            vardom.insert(vars - MyGspn->colVars.begin());
        } else {
            cerr << "Unknown variable '" << varname << "'" << endl;
        }
    }
}

int MyModelHandler::eval_intFormula(tree<string>::pre_order_iterator it) {
    expr ex = eval_expr(it);
    ex.eval(MyGspn->IntConstant, MyGspn->RealConstant);
    if (ex.t == Int) {
        return ex.intVal;
    } else {
        if (ex.t == Real) {
            if (ex.realVal == ceil(ex.realVal)) {
                return (int) ex.realVal;
            } else {
                cerr << "Marking should be an integer: " << ex.realVal << endl;
                ;
                throw gmlioexc;
            }
        } else {
            cerr << "Marking can not be marking dependant:" << endl << ex << endl;
            ;
            throw gmlioexc;
        }
    }
}

double MyModelHandler::eval_realFormula(tree<string>::pre_order_iterator it) {
    expr ex = eval_expr(it);
    ex.eval(MyGspn->IntConstant, MyGspn->RealConstant);
    if (ex.t == Int) {
        return (double) ex.intVal;
    } else {
        if (ex.t == Real) {
            return ex.realVal;
        } else {
            cerr << "Should not be marking dependant:" << endl << ex << endl;
            ;
            throw gmlioexc;
        }
    }
}

treeSI MyModelHandler::findbranch(treeSI t, string branch) {
    if (branch == "")return t;
    size_t nextnode = branch.find_first_of("/");
    for (treeSI it = (t.begin()); it != (t.end()); ++it) {
        if (it->compare(branch.substr(0, nextnode)) == 0) {
            return findbranch(it, branch.substr(nextnode + 1, branch.length() - nextnode - 1));
        }
    }
    return t.end();
}

expr MyModelHandler::eval_guard(tree<string>::pre_order_iterator it) {
    if ((P.verbose - 3) > 1)cout << (*it) << endl;
    if (*it == "boolExpr") {
        return eval_guard(it.begin());
    } else if (*it == "boolValue") {
        if (simplifyString(*(it.begin())) == "true")return expr(true);
        else return expr(false);
    } else if (*it == "equal") {
        expr lhs = eval_guard(it.begin());
        expr rhs = eval_guard(++it.begin());
        return expr(Eq, lhs, rhs);
    } else if (*it == "notEqual") {
        expr lhs = eval_guard(it.begin());
        expr rhs = eval_guard(++it.begin());
        return expr(Neq, lhs, rhs);
    } else if (*it == "and") {
        expr lhs = eval_guard(it.begin());
        expr rhs = eval_guard(++it.begin());
        return expr(And, lhs, rhs);
    } else if (*it == "or") {
        expr lhs = eval_guard(it.begin());
        expr rhs = eval_guard(++it.begin());
        return expr(Or, lhs, rhs);
    } else if (*it == "not") {
        expr lhs = eval_guard(it.begin());
        expr rhs;
        return expr(Neg, lhs, rhs);
    } else if (*it == "expr") {
        return eval_guard(it.begin());
    } else if (*it == "name") {
        string varname = simplifyString(*(it.begin()));
        vector<colorVariable>::const_iterator vars;
        for (vars = MyGspn->colVars.begin();
                vars != MyGspn->colVars.end() && vars->name != varname; ++vars);
        if (vars != MyGspn->colVars.end()) {
            return expr("bl.P->" + varname + ".c0");
        } else {
            cerr << "Unknown variable '" << varname << "'" << endl;
        }
    } else if (*it == "enumConst") {
        string typestr;
        string colorstr;
        for (treeSI it2 = it.begin(); it2 != it.end(); ++it2) {
            if (*it2 == "type") {
                typestr = simplifyString(*(it2.begin()));
            }
            if (*it2 == "enumValue") {
                colorstr = simplifyString(*(it2.begin()));
            }
        }
        return expr("Color_" + typestr + "_" + colorstr);
    }
    cerr << "Unknown attribute " << *it << "\n";
    return expr();
}

MyModelHandler::MyModelHandler(GspnType &MyGspn2) : MyGspn(&MyGspn2) {
    MyGspn->tr = 0;
    ParsePl = true;
    if (MyGspn->nbpass == 0) {
        //Initialisation
        MyGspn->pl = 0;
    }
}
//~MyModelHandler() { }

MyModelHandler::MyModelHandler(GspnType &MyGspn2, map<int, bool> &mip, map<int, int> &mgp, map<int, int> &mgt) : IsPlace(mip), Gml2Place(mgp), Gml2Trans(mgt), MyGspn(&MyGspn2) {
    MyGspn->tr = 0;
    ParsePl = true;
    if (MyGspn->nbpass == 0) {
        //Initialisation
        MyGspn->pl = 0;
    }
}

void MyModelHandler::on_read_model(const XmlString& formalismUrl) {
    // output used formalism
    ParsePl = true;
    if ((P.verbose - 3) > 0)cout << "read model : formalism = " << formalismUrl << endl;
}

void MyModelHandler::on_read_model_attribute(const Attribute& attribute) {
    if (MyGspn->nbpass == 1)return;

    // read model attribute
    // If the file is well formed the only attributes are constant declaration.

    for (treeSI it = attribute.begin(); it != attribute.end(); ++it) {
        if ((P.verbose - 3) > 1)cout << *it << ":" << endl;
        
        if (*it == "externalDeclaration" && P.magic_values.empty() ) {
            const auto extdef = simplifyString(*(it.begin()));
            if ((P.verbose - 3) > 1)cout <<  extdef << endl;
            P.magic_values = "magic.hpp";
            ofstream extdefhand( P.tmpPath+"/magic.hpp", ios::out | ios::trunc);
            extdefhand << "#include <string>\nusing namespace std;\n" << extdef << endl;
            extdefhand.close();
            if(P.lightSimulator){auto cmd = "sed -ibackup -e 's/return \\(\"[^\"]*\"\\);/print(\\1);break;/g' -e 's/return to_string2(v)/print((TR_PL_ID)v);break;/g' -e 's/ string / void /g' "+ P.tmpPath+"/magic.hpp";
            if(P.verbose>2)cout << cmd << endl;
            system(cmd.c_str());
            }
        }

        if (*it == "declaration") {
            treeSI t1 = findbranch(it, "constants/intConsts/");
            if (t1 != it.end())
                for (treeSI it2 = (t1.begin()); it2 != (t1.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "intConst") { // const is int or double
                        string constname = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        int constvalue = eval_intFormula(find(it2.begin(), it2.end(), "expr"));
                        if ((P.verbose - 3) > 1)cout << "const int " << constname << "=" << constvalue << endl;
                        if (P.constants.count(constname) > 0) {
                            constvalue = stoi(P.constants[constname]);
                            if ((P.verbose - 3) > 0)cout << "const int " << constname << " overwrite to " << constvalue << endl;
                            ;
                        }
                        MyGspn->IntConstant[constname] = constvalue;
                        MyGspn->RealConstant[constname] = constvalue;
                    }
                }

            treeSI t2 = findbranch(it, "constants/realConsts/");
            if (t2 != it.end())
                for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "realConst") {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                        string constname = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        double constvalue = eval_realFormula(find(it2.begin(), it2.end(), "expr").begin());
                        if (P.constants.count(constname) > 0) {
                            constvalue = stod(P.constants[constname]);
                            if ((P.verbose - 3) > 0)cout << "const double " << constname << " overwrite to " << constvalue << endl;
                            ;
                        }
                        MyGspn->RealConstant[constname] = constvalue;
                        if ((P.verbose - 3) > 1)cout << "\tconst double " << constname << "=" << MyGspn->RealConstant[constname] << endl;

                    }
                }
            
            t2 = findbranch(it, "constants/extConsts/");
            if (t2 != it.end())
                for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "extConst") {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                        string constname = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        MyGspn->ExternalConstant.emplace(constname);
                        if ((P.verbose - 3) > 1)cout << "\tconst External " << constname << endl;
                        
                    }
                }
            t2 = findbranch(it, "variables/clocks/");
            if (t2 != it.end())
                for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "clock") {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                        hybridVariable cl;
                        cl.name = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        cl.initialValue = "0";
                        cl.type = CV_CLOCK;
                        MyGspn->hybridVars.push_back(cl);
                        if ((P.verbose - 3) > 1)cout << "\tclock " << cl.name << endl;

                    }
                }
            t2 = findbranch(it, "variables/reals/");
            if (t2 != it.end())
                for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "real") {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                        hybridVariable cl;
                        cl.name = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        cl.initialValue = simplifyString(*((find(it2.begin(), it2.end(), "value").begin())));
                        cl.type = CV_REAL;
                        MyGspn->hybridVars.push_back(cl);
                        if ((P.verbose - 3) > 1)cout << "\treal " << cl.name << endl;

                    }
                }

            t2 = findbranch(it, "variables/ints/");
            if (t2 != it.end())
                for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                    if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                    if (*it2 == "int") {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ":" << endl;
                        hybridVariable cl;
                        cl.name = simplifyString((find(it2.begin(), it2.end(), "name")).node->first_child->data);
                        cl.initialValue = simplifyString(*((find(it2.begin(), it2.end(), "value").begin())));
                        cl.type = CV_INT;
                        MyGspn->hybridVars.push_back(cl);
                        if ((P.verbose - 3) > 1)cout << "\tint " << cl.name << endl;

                    }
                }

            for (t2 = it.begin(); t2 != it.end(); ++t2) {
                if ((P.verbose - 3) > 1)cout << endl << *t2 << ": " << endl;
                if (*t2 == "classDeclaration") {
                    colorClass cc;
                    for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ": ";
                        if (*it2 == "name") {
                            cc.name = simplifyString(*(it2.begin()));
                            if ((P.verbose - 3) > 1)cout << *(it2.begin());
                        }
                        if (*it2 == "classType") {
                            treeSI tclasstypeenum = find(it2.begin(), it2.end(), "classEnum");
                            if (tclasstypeenum != it2.end())
                                for (treeSI it3 = (tclasstypeenum.begin());
                                        it3 != (tclasstypeenum.end()); ++it3) {
                                    string col = simplifyString(*(it3.begin()));
                                    if ((P.verbose - 3) > 1)cout << "\t\t\t" << col << endl;
                                    cc.colors.push_back(color(col, cc.colors.size(), MyGspn->colClasses.size()));
                                }

                            tclasstypeenum = find(it2.begin(), it2.end(), "classIntInterval");
                            if (tclasstypeenum != it2.end()) {
                                int low, high;
                                treeSI intBound = find(tclasstypeenum.begin(), tclasstypeenum.end(), "lowerBound");
                                low = eval_intFormula(intBound.begin());
                                intBound = find(tclasstypeenum.begin(), tclasstypeenum.end(), "higherBound");
                                high = eval_intFormula(intBound.begin());

                                for (int i = low; i <= high; i++) {
                                    stringstream ss;
                                    ss << cc.name << "_IC_" << i;
                                    cc.colors.push_back(color(ss.str(), cc.colors.size(), MyGspn->colClasses.size()));
                                }

                            }

                        }
                        if (*it2 == "circular") {
                            if (simplifyString(*(it2.begin())) == "true")
                                cc.isCircular = true;
                            if ((P.verbose - 3) > 1)cout << *(it2.begin());
                        }
                    }
                    colorDomain cd;
                    cd.name = cc.name;
                    cd.colorClassIndex.push_back(MyGspn->colClasses.size());
                    MyGspn->colClasses.push_back(cc);
                    MyGspn->colDoms.push_back(cd);
                }

                if (*t2 == "domainDeclaration") {
                    colorDomain cd;
                    for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ": ";
                        if (*it2 == "name") {
                            cd.name = simplifyString(*(it2.begin()));
                            if ((P.verbose - 3) > 1)cout << *(it2.begin());
                        }
                        if (*it2 == "domainType") {
                            treeSI tclasstypeenum = find(it2.begin(), it2.end(), "cartesianProduct");
                            if (tclasstypeenum != it2.end())
                                for (treeSI it3 = (tclasstypeenum.begin());
                                        it3 != (tclasstypeenum.end()); ++it3) {
                                    string colclass = simplifyString(*(it3.begin()));
                                    if ((P.verbose - 3) > 1)cout << endl << "\t\t\t" << colclass;
                                    size_t colorc = 0;
                                    for (colorc = 0; colorc < MyGspn->colClasses.size() &&
                                            MyGspn->colClasses[colorc].name != colclass; colorc++);
                                    if (colorc == MyGspn->colClasses.size())
                                        cerr << "Unknown classe '" << colclass << "'" << endl;
                                    else cd.colorClassIndex.push_back(colorc);
                                }
                        }
                    }
                    MyGspn->colDoms.push_back(cd);
                }
                if (*t2 == "variableDeclaration") {
                    colorVariable cv;
                    for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ": ";
                        if (*it2 == "name") {
                            cv.name = simplifyString(*(it2.begin()));
                            if ((P.verbose - 3) > 1)cout << *(it2.begin());
                        }
                        if (*it2 == "type") {
                            string colclass = simplifyString(*(it2.begin()));
                            if ((P.verbose - 3) > 1)cout << "\t\t" << colclass << endl;
                            ;
                            size_t colorc = 0;
                            for (colorc = 0; colorc < MyGspn->colDoms.size() &&
                                    MyGspn->colDoms[colorc].name != colclass; colorc++);
                            if (colorc == MyGspn->colDoms.size())
                                cerr << "Unknown Domaine '" << colclass << "'" << endl;
                            else cv.type = colorc;

                        }
                    }
                    MyGspn->colVars.push_back(cv);
                }

                if (*t2 == "UserDefineDistribution") {
                    userDefineDistribution dist;
                    dist.lowerBound = "0";
                    dist.upperBound = "0";
                    for (treeSI it2 = (t2.begin()); it2 != (t2.end()); ++it2) {
                        if ((P.verbose - 3) > 1)cout << "\t" << *it2 << ": ";
                        if (*it2 == "name") {
                            dist.name = simplifyString(*(it2.begin()));
                        }
                        if (*it2 == "var") {
                            dist.var = simplifyString(*(it2.begin()));
                        }
                        if (*it2 == "cdf") {
                            dist.cdf = simplifyString(*(it2.begin()));
                        }
                        if (*it2 == "pdf") {
                            dist.pdf = simplifyString(*(it2.begin()));
                        }
                        if (*it2 == "lowerBound") {
                            dist.lowerBound = simplifyString(*(it2.begin()));
                        }
                        if (*it2 == "upperBound") {
                            dist.upperBound = simplifyString(*(it2.begin()));
                        }
                    }
                    MyGspn->distribStruct.push_back(dist);
                    if ((P.verbose - 3) > 1)cout << dist << endl;
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

    if ((P.verbose - 3) > 1)cout << "read node : " << id << ", " << nodeType << endl;
    if (nodeType == "place") {
        if (MyGspn->nbpass == 1)return;

        // Read a Place:

        MyGspn->pl++;
        int id2 = atoi(id.c_str());
        IsPlace[id2] = true;
        Gml2Place[id2] = MyGspn->pl - 1;
        place p;
        p.name = id;
        p.id = MyGspn->placeStruct.size();

        for (AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
            treeSI it2 = it->second.begin();
            if (*it2 == "marking") {
                vector<coloredToken> inMark;
                bool markdep = false;

                for (treeSI ittok = it2.begin(); ittok != it2.end(); ++ittok) {
                    if (*ittok == "token") {
                        coloredToken tok;
                        bool markingdependant = false;
                        set<size_t> varset;
                        eval_tokenProfileArc(tok, markingdependant, varset, ittok);
                        inMark.push_back(tok);
                    }
                }
                if (markdep) {
                    cerr << "Marking can not be marking dependant";
                    throw gmlioexc;
                }
                string st;
                if (inMark.empty()) {
                    int mark = 0;
                    mark = eval_intFormula(it2.begin());
                    inMark.push_back(coloredToken(mark));
                    st.append(to_string(mark));
                }

                if ((P.verbose - 3) > 1)cout << "\tmarking:" << st << endl;
                p.Marking=st;
                p.initMarking=inMark;

            } else if (*it2 == "name") {
                string Plname = simplifyString(*(it2.begin()));
                if ((P.verbose - 3) > 1)cout << "\tname:" << Plname << endl;
                p.name = Plname;
                if (MyGspn->PlacesId.count(Plname) > 0) {
                    cerr << "error:Two places with the name:" << Plname << endl;
                    throw gmlioexc;
                }
                MyGspn->PlacesId[Plname] = MyGspn->pl - 1;

            } else if ((*(it->second.begin())) == "domain") {
                string Pldomain = simplifyString(*(it2.begin().begin()));
                if ((P.verbose - 3) > 1)cout << "\tdomain:" << Pldomain << endl;
                size_t colord = 0;
                for (colord = 0; colord < MyGspn->colDoms.size() &&
                        MyGspn->colDoms[colord].name != Pldomain; colord++);
                if (colord == MyGspn->colDoms.size())
                    cerr << "Unknown Domain '" << Pldomain << "'" << endl;
                else p.colorDom = colord;

            } else throw (gmlioexc);

        }
        if(P.verbose>2)cout << p;
        MyGspn->placeStruct.push_back(p);

    } else {
        if (nodeType == "transition") {
            if (MyGspn->nbpass == 0)return;
            //Read a transition:
            MyGspn->tr++;
            int id2 = atoi(id.c_str());
            IsPlace[id2] = false;
            Gml2Trans[id2] = MyGspn->tr - 1;

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

            for (AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
                if ((*(it->second.begin())) == "name") {
                    string Trname = simplifyString(*(++(it->second.begin())));
                    if ((P.verbose - 3) > 1)cout << "\tname:" << Trname << endl;
                    MyGspn->TransList.insert(Trname);
                    trans.label = Trname;
                    if (MyGspn->TransId.count(Trname) > 0) {
                        cerr << "error:Two transitions with the name:" << Trname << endl;
                        throw gmlioexc;
                    }
                    MyGspn->TransId[Trname] = MyGspn->tr - 1;
                } else if ((*(it->second.begin())) == "guard") {
                    trans.guard = eval_guard(it->second.begin().begin());
                    //if(trans.guard == "")trans.guard = "true";
                } else if ((*(it->second.begin())) == "distribution") {
                    if ((P.verbose - 3) > 1)cout << "\tdistribution:" << endl;
                    for (treeSI it2 = (it->second.begin()).begin(); it2 != (it->second.begin()).end(); ++it2) {
                        if ((P.verbose - 3) > 1)cout << "\t" << (*it2) << ":" << endl;
                        if (*it2 == "type") {
                            string Trtype = simplifyString(*(it2.begin()));
                            if (Trtype == "IMDT")trans.type = unTimed;
                            trans.dist.name = Trtype;
                            if ((P.verbose - 3) > 1)cout << "\t\t" << Trtype << endl;
                        } else if (*it2 == "param") {

                            //int number = 0;
                            for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
                                //string* leaf = simplifyString(*(it3.begin()));
                                if (*it3 == "number") {
                                    //number = atoi((*leaf).c_str());
                                } else if (*it3 == "expr") {
                                    expr pe;
                                    if(trans.dist.Param.size()==0 && trans.dist.name == "USERDEFINE" ){
                                        string distname = simplifyString(*(it3.begin()));
                                        auto did = find_if(MyGspn->distribStruct.begin(), MyGspn->distribStruct.end(), [&](userDefineDistribution &d){
                                            return (d.name == distname);});
                                        if( did != MyGspn->distribStruct.end()){
                                            pe = expr((int)(did - MyGspn->distribStruct.begin()));
                                        } else {
                                            cerr << "Unkown distribution " << distname << endl;
                                            throw gmlioexc;
                                        }
                                    }else {
                                        pe = eval_expr(it3.begin());
                                        trans.markingDependant |= pe.is_markDep();
                                    }
                                    trans.dist.Param.push_back(pe);
                                    if ((P.verbose - 3) > 1)cout << "\tDistrib Param:'" << setw(0) << pe << "'" << endl;
                                } else throw gmlioexc;
                            }
                        } else throw gmlioexc;
                    }

                } else if ((*(it->second.begin())) == "service") {
                    if ((*(++(it->second.begin()))) == "expr") {
                        const auto nserv = eval_intFormula((++(it->second.begin())).begin());
                        if (nserv == 1) {
                            trans.nbServers = 1;
                        } else {
                            trans.singleService = false;
                            trans.nbServers = nserv;
                        }
                    } else cout << " Fail to parse GML: transition,service" << endl;

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
                    if ((*(++(it->second.begin()))) == "expr") {
                        expr e = eval_expr((++(it->second.begin())).begin());
                        if (!e.is_markDep()) {
                            trans.weight = e;
                        } else {
                            cout << "Weight is not marking dependent " << endl;
                        }
                    } else cout << " Fail to parse GML: transition,weight" << endl;


                } else if ((*(it->second.begin())) == "priority") {
                    if ((*(++(it->second.begin()))) == "expr") {
                        expr e = eval_expr((++(it->second.begin())).begin());
                        if (!e.is_markDep()) {
                            trans.priority = e;
                        } else {
                            cout << "Priority is not marking dependent " << endl;
                        }
                    } else cout << " Fail to parse GML: transition,priority" << endl;

                } else if ((*(it->second.begin())) == "ageMemory") {
                    trans.ageMemory = true;
                } else if ((*(it->second.begin())) == "update") {
                    trans.update = simplifyString(*(++(it->second.begin())));

                } else cout << "fail to parse gml transition attribute" << endl;

            }

            if (trans.dist.name == "") {
                trans.type = Timed;
                trans.dist.name = "EXPONENTIAL";
                trans.dist.Param.push_back(expr(1.0));
                if ((P.verbose - 3) >= 0) {
                    cout << "[Warning] Transition " << trans.label;
                    cout << " have no distribution.";
                    cout << " Assigne exponential with parameter 1" << endl;
                }
            }

            if(P.verbose>2)cout << trans ;
            MyGspn->transitionStruct.push_back(trans);
        } else cout << "fail to parse gml" << endl;
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
    if (MyGspn->nbpass == 0)return;

    if (ParsePl) {
        ParsePl = false;

        if (P.RareEvent) {
            if (P.BoundedContinuous || P.BoundedRE > 0) {
                //add a transition for self-loop due to uniformization
                transition trans(MyGspn->transitionStruct.size(), "selfloop", expr(0.0), true);
                MyGspn->transitionStruct.push_back(trans);

                MyGspn->TransId["selfloop"] = MyGspn->tr;
                MyGspn->TransList.insert(trans.label);
                MyGspn->tr++;
            }

            //Add a place
            place p;
            p.Marking = "0";
            coloredToken ctok(0);
            p.initMarking=vector<coloredToken>(1, ctok);

            string Plname = "Puit";
            p.name = Plname;
            p.id = MyGspn->pl;
            MyGspn->placeStruct.push_back(p);
            MyGspn->PlacesId[Plname] = MyGspn->pl;
            MyGspn->pl++;


            //Add a transition
            transition trans(MyGspn->transitionStruct.size(), "Puittrans", expr(0.0), true);
            MyGspn->transitionStruct.push_back(trans);

            MyGspn->TransList.insert(trans.label);
            MyGspn->tr++;
        }
    }

    if ((P.verbose - 3) > 1)cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
    string valuation;
    vector<coloredToken> toklist;
    //cout << arcType << endl;
    int sourceGML = atoi(source.c_str());
    for (AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
        treeSI it2 = it->second.begin();
        if (*it2 == "valuation") {
            bool markingdependant = false;
            for (treeSI it3 = it2.begin(); it3 != it2.end(); ++it3) {
                if (*it3 == "expr") {
                    const auto e = eval_expr(it3.begin());
                    stringstream ss;
                    ss << e;
                    valuation = ss.str();
                    markingdependant |= e.is_markDep();
                } else if (*it3 == "token") {
                    coloredToken tokenType;
                    tokenType.hasAll = false;
                    if (IsPlace[sourceGML]) {
                        eval_tokenProfileArc(tokenType, markingdependant, MyGspn->transitionStruct[Gml2Trans[atoi(target.c_str())]].varDomain, it3);
                    } else {
                        eval_tokenProfileArc(tokenType, markingdependant, MyGspn->transitionStruct[Gml2Trans[atoi(source.c_str())]].varDomain, it3);
                    }

                    toklist.push_back(tokenType);
                } else cout << " Fail to parse GML: arc,valuation" << endl;
            }
            if (toklist.empty()) {
                toklist.push_back(coloredToken(valuation));
            } else {
                valuation = "COLORED";
            }
        } else cout << "fail to parse gml" << endl;
    }

    if (IsPlace[sourceGML]) {
        if (arcType == "inhibitorarc") {
            if (Evaluate_gml.parse(valuation)) {
                MyGspn->inhibArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())], Gml2Place[sourceGML]), arc(("(" + valuation + ")"), toklist)));
            } else {
                MyGspn->inhibArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())], Gml2Place[sourceGML]), arc(Evaluate_gml.IntResult)));
            }
            //MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        } else {
            if (Evaluate_gml.parse(valuation)) {
                MyGspn->inArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())], Gml2Place[sourceGML]), arc(("(" + valuation + ")"), toklist)));
            } else {
                MyGspn->inArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[atoi(target.c_str())], Gml2Place[sourceGML]), arc(Evaluate_gml.IntResult)));
            }
            //MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
        }
    } else {
        if (Evaluate_gml.parse(valuation)) {
            MyGspn->outArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[sourceGML], Gml2Place[atoi(target.c_str())]), arc(("(" + valuation + ")"), toklist)));
        } else {
            MyGspn->outArcsStruct.insert(make_pair<pair<size_t, size_t>, arc>(MyGspn->arckey(Gml2Trans[sourceGML], Gml2Place[atoi(target.c_str())]), arc(Evaluate_gml.IntResult)));
        }
        //MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
    }

}
