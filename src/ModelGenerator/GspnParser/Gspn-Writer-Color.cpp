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
 * file Gspn-Writer-Color.cpp                                                  *
 * Created by Benoit Barbot on 17/04/15.                                       *
 *******************************************************************************
 */

#include <assert.h>
#include <sstream>

#include "Gspn-Writer-Color.hpp"
#include "../casesWriter.hpp"

using namespace std;

Gspn_Writer_Color::Gspn_Writer_Color(GspnType& mgspn,parameters& Q):Gspn_Writer(mgspn,Q){}

void Gspn_Writer_Color::writeEnabledDisabledBinding(ofstream &SpnF)const{
    SpnF << "const abstractBinding* "<<objName<<"nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {" << endl;
    SpnF << "\tswitch(lastTransition*(tr+1) + targettr){"<< endl;
    for(size_t trit = 0; trit != MyGspn.tr;++trit){
        if(!MyGspn.transitionStruct[trit].varDomain.empty())
            for (size_t trit2= 0; trit2 != MyGspn.tr; ++trit2) {
                set<size_t> varList = MyGspn.transitionStruct[trit2].varDomain;
                if(!varList.empty()){

                    size_t nbp = 0;
                    size_t pivotplace = MyGspn.pl;
                    bool fallback = false;
                    for(size_t itp = 0; itp!=MyGspn.pl; ++itp){
                        //Check that that there is at least one variable on the two arcs
                        if(MyGspn.access(MyGspn.outArcsStruct,trit,itp).isColored
                           && MyGspn.access(MyGspn.inArcsStruct,trit2,itp).isColored
                           ){
                            //Check that there is only one token on each arcs
                            if(MyGspn.access(MyGspn.outArcsStruct,trit,itp).coloredVal.size()==1
                               && MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal.size()==1){
                                //Check that the token is not the ALL token.
                                if(!MyGspn.access(MyGspn.outArcsStruct,trit,itp).coloredVal[0].hasAll &&
                                   !MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].hasAll){
                                    nbp++;
                                    pivotplace = itp;
                                    for(size_t varpt = 0;varpt < MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].field.size(); ++varpt){
                                        if(MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].Flags[varpt] == CT_VARIABLE){
                                            varList.erase(MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].field[varpt]);
                                        }
                                    }
                                }else fallback = true;//Handling of ALL token not yet implemented
                            }else
                                fallback= true; // Handling of several token not yet implemented
                        } else {
                            //Sychronization over an uncolored place
                            nbp++;
                            pivotplace= itp;
                        }
                    }
                    if ( nbp==1 && varList.empty() && !fallback) {
                        // Here we implement only the case with one place one token on the arc
                        // For all other casess fall back to enumeration.
                        SpnF << "\tcase " << trit*(MyGspn.tr+1) + trit2 <<
                        ":\t//" << MyGspn.transitionStruct[trit].name << "->"
                        << MyGspn.placeStruct[pivotplace].name <<
                        "->" << MyGspn.transitionStruct[trit2].name << endl;
                        SpnF << "\t{"<< endl;
                        SpnF << "\t\tif(*bindingNum==1)return NULL;" << endl; //return NULL if it is the second call
                        SpnF << "\t\tsize_t btotal = b.idTotal();" << endl;
                        assert(pivotplace < MyGspn.pl);
                        const auto tok = MyGspn.access(MyGspn.outArcsStruct,trit,pivotplace);
                        assert(tok.coloredVal.size()>0 && tok.coloredVal[0].field.size());
                        const auto cc1 = tok.coloredVal[0];
                        SpnF << "\t\tbtotal += " << ((cc1.varIncrement[0]
                                                      + MyGspn.colClasses[cc1.field[0]].colors.size()) % MyGspn.colClasses[cc1.field[0]].colors.size() ) *
                        varMultiplier(cc1.field[0]) <<  ";"<< endl;
                        //Compute the number of the new binding in the global numerotation.

                        SpnF << "\t\tsize_t bloc = Transition[targettr].bindingLinkTable[btotal];" << endl;
                        SpnF << "\t\tif(bloc==string::npos)return NULL;" << endl;

                        SpnF << "\t\t*bindingNum=1;" << endl;
                        SpnF << "\t\treturn &(Transition[targettr].bindingList[bloc]);" << endl;
                        SpnF << "\t}"<< endl;
                    }else if(fallback){
                        SpnF << "\t\t//Fallback:" << MyGspn.transitionStruct[trit].name << "->" << MyGspn.transitionStruct[trit2].name << endl;
                    } else if(varList.size() < MyGspn.transitionStruct[trit2].varDomain.size()){
                        SpnF << "\t\t//Partial synch over variable: " << MyGspn.transitionStruct[trit].name << "->" << MyGspn.transitionStruct[trit2].name << " var ";
                        for (set<size_t>::const_iterator itset = varList.begin(); itset != varList.end(); ++itset) {
                            SpnF << MyGspn.colVars[*itset].name << ", ";
                        }
                        SpnF << "Not set" <<endl;
                    }
                }
            }
    }
    SpnF << "\tdefault:"<< endl;
    SpnF << "\t\tif(*bindingNum==Transition[targettr].bindingList.size())return NULL;"<<endl;
    SpnF << "\t\t*bindingNum = *bindingNum +1;"<< endl;
    SpnF << "\t\treturn &(Transition[targettr].bindingList[*bindingNum-1]);"<< endl;
    SpnF << "}}"<< endl;

    SpnF << "const abstractBinding* "<<objName<<"nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {" << endl;
    SpnF << "\tswitch(lastTransition*(tr+1) + targettr){"<< endl;

    for(size_t trit = 0; trit != MyGspn.tr;++trit){
        if(!MyGspn.transitionStruct[trit].varDomain.empty())
            for (size_t trit2= 0; trit2 != MyGspn.tr; ++trit2) {
                set<size_t> varList = MyGspn.transitionStruct[trit2].varDomain;
                if(!varList.empty()){

                    size_t nbp = 0;
                    size_t pivotplace= MyGspn.pl;
                    bool fallback = false;
                    for(size_t itp = 0; itp!=MyGspn.pl; ++itp){
                        //Check that that there is at least one variable on the two arcs
                        if(MyGspn.access(MyGspn.inArcsStruct,trit,itp).isColored
                           && MyGspn.access(MyGspn.inArcsStruct,trit2,itp).isColored){
                            //Check that there is only one token on each arcs
                            if(MyGspn.access(MyGspn.inArcsStruct,trit,itp).coloredVal.size()==1
                               && MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal.size()==1){
                                //Check that the token is not the ALL token.
                                if(!MyGspn.access(MyGspn.inArcsStruct,trit,itp).coloredVal[0].hasAll &&
                                   !MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].hasAll){
                                    nbp++;
                                    pivotplace = itp;
                                    for(size_t varpt = 0;varpt < MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].field.size(); ++varpt){
                                        if(MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].Flags[varpt] == CT_VARIABLE){
                                            varList.erase(MyGspn.access(MyGspn.inArcsStruct,trit2,itp).coloredVal[0].field[varpt]);
                                        }
                                    }
                                }else fallback = true;//Handling of ALL token not yet implemented
                            }else {
                                fallback= true; // Handling of several token not yet implemented
                            }
                        }else {
                            //Sychronization over an uncolored place
                            nbp++;
                            pivotplace= itp;
                        }
                    }
                    if ( nbp==1 && varList.empty() && !fallback) {
                        // Here we implement only the case with one place one token on the arc
                        // For all other casess fall back to enumeration.
                        SpnF << "\tcase " << trit*(MyGspn.tr+1) + trit2 <<
                        ":\t//" << MyGspn.transitionStruct[trit].name << "->"
                        << MyGspn.placeStruct[pivotplace].name <<
                        "->" << MyGspn.transitionStruct[trit2].name << endl;
                        SpnF << "\t{"<< endl;
                        SpnF << "\t\tif(*bindingNum==1)return NULL;" << endl; //return NULL if it is the second call
                        SpnF << "\t\tsize_t btotal = b.idTotal();" << endl;
                        assert(pivotplace < MyGspn.pl);
                        const auto tok = MyGspn.access(MyGspn.inArcsStruct,trit,pivotplace);
                        assert(tok.coloredVal.size()>0 && tok.coloredVal[0].field.size());
                        const auto cc1 = tok.coloredVal[0];
                        SpnF << "\t\tbtotal += " << ((cc1.varIncrement[0]
                                                      + MyGspn.colClasses[cc1.field[0]].colors.size()) % MyGspn.colClasses[cc1.field[0]].colors.size() ) *
                        varMultiplier(cc1.field[0]) <<  ";"<< endl;
                        //Compute the number of the new binding in the global numerotation.

                        SpnF << "\t\tsize_t bloc = Transition[targettr].bindingLinkTable[btotal];" << endl;
                        SpnF << "\t\tif(bloc==string::npos)return NULL;" << endl;

                        SpnF << "\t\t*bindingNum=1;" << endl;
                        SpnF << "\t\treturn &(Transition[targettr].bindingList[bloc]);" << endl;
                        SpnF << "\t}"<< endl;
                    }else if(fallback){
                        SpnF << "\t\t//Fallback:" << MyGspn.transitionStruct[trit].name << "->" << MyGspn.transitionStruct[trit2].name << endl;
                    } else if(varList.size() < MyGspn.transitionStruct[trit2].varDomain.size()){
                        SpnF << "\t\t//Partial synch over variable: " << MyGspn.transitionStruct[trit].name << "->" << MyGspn.transitionStruct[trit2].name << " var ";
                        for (set<size_t>::const_iterator itset = varList.begin(); itset != varList.end(); ++itset) {
                            SpnF << MyGspn.colVars[*itset].name << ", ";
                        }
                        SpnF << "Not set" <<endl;
                    }
                }
            }
    }


    SpnF << "\tdefault:"<< endl;
    SpnF << "\t\tif(*bindingNum==Transition[targettr].bindingList.size())return NULL;"<<endl;
    SpnF << "\t\t*bindingNum = *bindingNum +1;"<< endl;
    SpnF << "\t\treturn &(Transition[targettr].bindingList[*bindingNum-1]);"<< endl;
    SpnF << "}}"<< endl;


    /*SpnF << "\tconst abstractBinding* result = &(Transition[targettr].bindingList[*bindingNum]);"<< endl;
     SpnF << "\tif(*bindingNum==Transition[targettr].bindingList.size()-1){*bindingNum= string::npos;}"<<endl;
     SpnF << "\telse{*bindingNum = *bindingNum +1;};"<< endl;
     SpnF << "\treturn result;"<< endl;
     SpnF << "}"<< endl;*/

}

void Gspn_Writer_Color::writeEnabledDisabledBindingSet(ofstream &SpnF)const{
    //SpnF << "const abstMarkIter = new abstractMarkingIterator();";
    SpnF << "const abstractBinding* "<<objName<<"nextPossiblyEnabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {" << endl;
    
    // Switch sur les transitions :
    
    // 1. récupérer les variables d'entrées
    // 2. itérer sur les places d'entrées
    SpnF << "\t\tassert(false);" << endl;
            /*
    SpnF << "\t\tif(*bindingNum==Transition[targettr].bindingList.size())return NULL;"<<endl;
    SpnF << "\t\t*bindingNum = *bindingNum +1;"<< endl;
    SpnF << "\t\treturn &(Transition[targettr].bindingList[*bindingNum-1]);"<< endl;
             */
    SpnF << "}"<< endl;

    SpnF << "const abstractBinding* "<<objName<<"nextPossiblyDisabledBinding(size_t targettr,const abstractBinding& b,size_t *bindingNum)const {" << endl;
    SpnF << "\t\tassert(false);" << endl;
    /*
    SpnF << "\t\tif(*bindingNum==Transition[targettr].bindingList.size())return NULL;"<<endl;
    SpnF << "\t\t*bindingNum = *bindingNum +1;"<< endl;
    SpnF << "\t\treturn &(Transition[targettr].bindingList[*bindingNum-1]);"<< endl;
    */
    SpnF << "}"<< endl;

}

void Gspn_Writer_Color::printloot(ofstream& fs, const colorDomain& dom, size_t nesting )const{
    //const colorDomain& dom = MyGspn.colDoms[domain];
    if(nesting == dom.colorClassIndex.size()){
        stringstream mult;
        mult << "x.mult";
        for (size_t count = 0 ; count < dom.colorClassIndex.size(); count++ ) {
            mult << "[c" << count << "]";
        }
        fs << "\t\tif(" << mult.str() << ")\n\t\t";
        fs << "\t\t\toutprintloot << "<< mult.str();
        fs << "<< \"<\"";
        for (size_t count = 0 ; count < dom.colorClassIndex.size(); count++ ) {
            if( count > 0)fs << " << \",\"";
            fs << " << Color_"<< MyGspn.colClasses[dom.colorClassIndex[count]].name << "_names[c" << count << "]";
        }
        fs << "<< \">,\";\n";
        return;
    }
    fs << "\tfor(size_t c" << nesting << " = 0 ; c"<<nesting<<"< Color_";
    fs << MyGspn.colClasses[dom.colorClassIndex[nesting]].name << "_Total; c";
    fs << nesting << "++ )\n";
    printloot(fs, dom, nesting+1);
}


void Gspn_Writer_Color::writeDomainToken(std::ofstream &header, const colorDomain & it)const{
    //token class def
    header << "\nstruct " << it.tokname() << "{\n";
    vector<size_t>::const_iterator itcol;
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        header << "\t" << MyGspn.colClasses[*itcol].cname() << " c" << itcol - it.colorClassIndex.begin() << ";\n";
    }
    header << "\tint mult;\n";
    
    header << "\t" << it.tokname() << "( ";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        header << " "<<MyGspn.colClasses[*itcol].cname() << " cv" << itcol - it.colorClassIndex.begin()<< " = ("<< MyGspn.colClasses[*itcol].cname() << ")0, " ;
    }
    header << "int v =1) {\n";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        size_t pos = itcol - it.colorClassIndex.begin();
        header << "\t\tc" << pos << "= cv"<<pos <<";\n";
    }
    header << "\t\tmult = v;\n\t}\n";
    
    
    header << "\t" << it.tokname() << "( ";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        header << "const "<<MyGspn.colClasses[*itcol].name << "_Token& cv" << itcol - it.colorClassIndex.begin()<< ", " ;
    }
    header << "int v =1) {\n";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        size_t pos = itcol - it.colorClassIndex.begin();
        header << "\t\tc" << pos << "= cv";
        header << pos << ".c0" << ";\n";
    }
    header << "\t\tmult = v;\n\t}\n";
    
    header << "\t" << it.tokname() << " operator * (size_t v){\n";
    header << "\t\tmult *= v;\n\t\treturn *this;\n\t}\n";
    
    
    header << "\tvoid iter() {\n";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        size_t pos = itcol - it.colorClassIndex.begin();
        header << "\t\tif( c" << pos << "< ("<< MyGspn.colClasses[*itcol].cname() << ")(Color_";
        header << MyGspn.colClasses[*itcol].name << "_Total - 1) )";
        header << "{ c"<< pos << " = ("<< MyGspn.colClasses[*itcol].cname() << ")(c"<< pos <<"+ 1); return;};\n";
        header << "c"<< pos << " = ("<< MyGspn.colClasses[*itcol].cname() << ")(0);\n";
    }
    header << "\t}\n";
    
    header << "\tvoid print(std::ostream& out) const {\n\t\tout << mult << \"<\" <<";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        if(itcol != it.colorClassIndex.begin())header << "<< \" , \" << ";
        header << " Color_"<< MyGspn.colClasses[*itcol].name << "_names[c" << itcol - it.colorClassIndex.begin() << "]";
    }
    header << " << \">\";\n";
    header << "\t}\n";
    
    
    if (it.colorClassIndex.size()==1 && MyGspn.colClasses[it.colorClassIndex[0]].isCircular) {
        header << "\t" << it.tokname() << " next(int i)const {\n";
        header << "\t\t" << it.tokname() << " x(("<< MyGspn.colClasses[it.colorClassIndex[0]].cname() << ")((c0 +i) % Color_";
        header << MyGspn.colClasses[it.colorClassIndex[0]].name << "_Total), ";
        header << " mult);\n\t\treturn x;}\n";
    }
    
    header << "\tbool islast()const {\n\t\treturn (";
    for (itcol = it.colorClassIndex.begin(); itcol != it.colorClassIndex.end() ; ++itcol ) {
        size_t pos = itcol - it.colorClassIndex.begin();
        if (pos > 0)header << " && ";
        header << " c" << pos << "== ("<< MyGspn.colClasses[*itcol].cname() << ")(Color_";
        header << MyGspn.colClasses[*itcol].name << "_Total -1) ";
    }
    header << " );\n\t}\n";
    
    /* header << "\tbool operator > (const " << it.tokname() << " x){\n";
    header << "\t\treturn mult > x.mult ;\n\t}\n"; // Solution temporaire, il faudrait peut-être vérifier que c'est bien des tokens du même type ?
    header << "\tbool operator < (const " << it.tokname() << " x){\n";
    header << "\t\treturn mult < x.mult ;\n\t}\n"; */
    
    header << "\tbool operator > (const int x){\n";
    header << "\t\treturn mult > x ;\n\t}\n";
    header << "\tbool operator < (const int x){\n";
    header << "\t\treturn mult < x ;\n\t}\n";
    
    header << "\tbool operator < (const " << it.tokname() << " &tok) const {\n"; // Comparaison demandée par la structure Map
    for (size_t colIndex=0; colIndex< it.colorClassIndex.size(); colIndex++ ) {
        // Comparaison en ordre lexico
        header << "\t\tif (c" << colIndex << " < tok.c" << colIndex << ") { return true; }\n";
        header << "\t\tif (c" << colIndex << " > tok.c" << colIndex << ") { return false; }\n";
    }
    header << "\t\treturn false;\n";
    header << "\t}\n";
    
    header << "};\n";
    
}

void Gspn_Writer_Color::writeDomainTable(std::ofstream &SpnCppFile , std::ofstream &header, const colorDomain & it)const{
    
    stringstream domaindecl;
    stringstream colorArgsName;
    stringstream colorArrayAccess;
    stringstream colorArrayAccess2;
    stringstream allCondition;
    stringstream forLoop;
    
    for (vector<size_t>::const_iterator it2 = it.colorClassIndex.begin();
         it2 != it.colorClassIndex.end(); ++it2 ) {
        domaindecl << "[ Color_" << MyGspn.colClasses[*it2].name << "_Total ]";
        size_t countCol = it2 - it.colorClassIndex.begin();
        if(countCol > 0){
            colorArgsName << ",";
            allCondition << " && ";
        }
        colorArgsName << MyGspn.colClasses[ *it2 ].cname() << " c" << countCol;
        colorArrayAccess << "[c" << countCol << "]";
        colorArrayAccess2 << "[i" << countCol << "]";
        allCondition << "c" << countCol << " != Color_" << MyGspn.colClasses[*it2].name << "_All";
        forLoop << "\t\t\tfor( int i" <<
        countCol <<"= ( c" << countCol << " == Color_" << MyGspn.colClasses[*it2].name << "_All ? 0 : c" << countCol << ");";
        forLoop << "i" << countCol <<"< ( c" << countCol << " == Color_" << MyGspn.colClasses[*it2].name << "_All ? Color_"<< MyGspn.colClasses[*it2].name <<"_Total : c" << countCol << "+1);";
        forLoop << "i" << countCol << "++)\n";
        
    }
    
    header << "struct " << it.cname() << ":";
    for (let it2 : it.colorClassIndex) header << (it2==it.colorClassIndex[0]?" ":", ") << "contains_" << MyGspn.colClasses[it2].cname();
    header << " {\n\tint mult" << domaindecl.str() << ";\n";
    header << "\t" << it.cname() << "(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}"<< endl;
    header << "\t" << it.cname() << "(" << colorArgsName.str() << ") {\n";
    //header << "\t\t" << "memset(&mult,0 , sizeof(mult));\n";
    header << "\t\t" << "fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );"<< endl;
    header << "\t\t" << "if(" << allCondition.str() << ")\n";
    header << "\t\t\t" << "mult" << colorArrayAccess.str() << " = 1 ;\n";
    header << "\t\telse{\n";
    header << forLoop.str() << "\t\t\t\tmult" << colorArrayAccess2.str() << " = 1 ;\n";
    header << "\t\t}\n";
    header << "\t}\n";
    
    header << "\tsize_t copyVector(vector<int> &v ,size_t s)const{\n";
    header << "\t\tcopy((int*)mult,(int*)mult + sizeof(mult)/sizeof(int), v.begin() + s );\n\t\treturn s+sizeof(mult)/sizeof(int);\n\t}\n";
    header << "\tsize_t setVector(const vector<int> &v ,size_t s){\n";
    header << "\t\tcopy(v.begin() + s, v.begin() + s + sizeof(mult)/sizeof(int), (int*)mult );\n\t\treturn s+sizeof(mult)/sizeof(int);\n\t}\n";
    
    
    
    header << "\t" << it.cname() << "& operator = (const " << it.cname() << "& x){\n";
    header << "\t\tcopy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);\n\t\treturn *this;\n\t}\n";
    
    header << "\tbool operator == (const " << it.cname() << "& x){\n";
    header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);\n\t}\n";
    
    header << "\tbool operator < (const " << it.cname() << "& x){\n";
    header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());\n\t}\n";
    
    header << "\tbool operator > (const " << it.cname() << "& x){\n";
    header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());\n\t}\n";
    
    header << "\t" << it.cname() << " operator * (int v){\n";
    header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;\n\t\treturn *this;\n\t}\n";
    
    header << "\t" << it.cname() << "& operator += (const " << it.cname() << "& x){\n";
    header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
    header << "\n\t\t\t((int*)mult)[count]+= ((int*)x.mult)[count] ;\n";
    header << "\t\treturn *this;\n\t}\n";
    
    header << "\t" << it.cname() << "& operator += (const " << it.tokname() << "& x){\n";
    header << "\t\tmult";
    for (vector<size_t>::const_iterator it2 = it.colorClassIndex.begin();
         it2 != it.colorClassIndex.end(); ++it2 ) {
        header << "[ x.c" << it2- it.colorClassIndex.begin() << " ]" ;
    }
    header << " += x.mult;\n\t\treturn *this;\n\t}\n";
    
    header << "\t" << it.cname() << " operator + (const " << it.tokname() << "& x){\n";
    header << "\t\t"<< it.cname()<< " d(*this);\n\t\td+=x;\n ";
    header << "\t\treturn d;\n\t}\n";
    
    header << "\t" << it.cname() << "& operator -= (const " << it.tokname() << "& x){\n";
    header << "\t\tmult";
    for (vector<size_t>::const_iterator it2 = it.colorClassIndex.begin();
         it2 != it.colorClassIndex.end(); ++it2 ) {
        header << "[ x.c" << it2- it.colorClassIndex.begin() << " ]" ;
    }
    header << " -= x.mult;\n\t\treturn *this;\n\t}\n";
    
    header << "\tbool operator < (const " << it.tokname() << "& x)const{\n";
    header << "\t\treturn mult";
    for (vector<size_t>::const_iterator it2 = it.colorClassIndex.begin();
         it2 != it.colorClassIndex.end(); ++it2 ) {
        header << "[ x.c" << it2- it.colorClassIndex.begin() << " ]" ;
    }
    header << " < x.mult;\n\t}\n";
    
    header << "\tbool operator >= (const " << it.tokname() << "& x)const{\n";
    header << "\t\treturn mult";
    for (vector<size_t>::const_iterator it2 = it.colorClassIndex.begin();
         it2 != it.colorClassIndex.end(); ++it2 ) {
        header << "[ x.c" << it2- it.colorClassIndex.begin() << " ]" ;
    }
    header << " >= x.mult;\n\t}\n";
    
    header << "\t" << it.cname() << " operator + (const " << it.cname() << "& x)const{\n";
    header << "\t\t"<< it.cname() << " returnval = *this; returnval+= x;\n";
    header << "\t\treturn returnval;\n\t}\n";
    
    header << "\t" << it.cname() << "& operator -= (const " << it.cname() << "& x){\n";
    header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
    header << "\n\t\t\t((int*)mult)[count]-= ((int*)x.mult)[count] ;\n";
    header << "\t\treturn *this;\n\t}\n";
    
    header << "\t" << it.cname() << " operator - (const " << it.cname() << "& x)const{\n";
    header << "\t\t"<< it.cname() << " returnval = *this; returnval-= x;\n";
    header << "\t\treturn returnval;\n\t}\n";
    
    header << "\tint card (void){\n";
    header << "\tint acc=0;\n";
    header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
    header << "\n\t\t\tacc += ((int*)mult)[count] ;\n";
    header << "\t\treturn acc;\n\t}\n";
    
    for( let cci : it.colorClassIndex){
        let cc = MyGspn.colClasses[cci];
        header << "\tvirtual void apply_perm("<< cc.cname() <<",const std::vector<size_t> &index){\n";
        header << "\t\t"<< it.cname() <<" temp = *this ;\n";
        //header << "\t\tstd::copy( mult, mult + sizeof(mult)/sizeof(int), temp);\n";
        
        stringstream forloop2;
        stringstream accessperm;
        for (auto it2 = it.colorClassIndex.begin(); it2 != it.colorClassIndex.end(); ++it2 ) {
            size_t countCol = it2 - it.colorClassIndex.begin();
            forloop2 << "\t\tfor( int i" << countCol <<"= 0 ; i" << countCol <<"< Color_"<< MyGspn.colClasses[*it2].name <<"_Total ;";
            forloop2 << "i" << countCol << "++)\n";
            if(*it2 == cci){
                accessperm << "[ index[i"<< countCol <<"] ]";
            }else{
                accessperm << "[ i"<< countCol <<" ]";
            }
        }
 
        header << forloop2.str();
        header << "\t\t\tmult" << colorArrayAccess2.str() << " = temp.mult" << accessperm.str();
        header << ";" << endl;
        header << "\t}\n";
    }
    
    for( let cci : it.colorClassIndex){
        let cc = MyGspn.colClasses[cci];
        header << "\tvirtual int compare("<< cc.cname() <<",int cci,int ccj)const{\n";
        
        stringstream forloop2;
        stringstream accesspermi;
        stringstream accesspermj;
        for (auto it2 = it.colorClassIndex.begin(); it2 != it.colorClassIndex.end(); ++it2 ) {
            size_t countCol = it2 - it.colorClassIndex.begin();
            if(*it2 != cci){
                forloop2 << "\t\tfor( int i" << countCol <<"= 0 ; i" << countCol <<"< Color_"<< MyGspn.colClasses[*it2].name <<"_Total ;";
                forloop2 << "i" << countCol << "++)\n";
            }
            if(*it2 == cci){
                accesspermi << "[ cci ]";
                accesspermj << "[ ccj ]";
            }else{
                accesspermi << "[ i"<< countCol <<" ]";
                accesspermj << "[ i"<< countCol <<" ]";
            }
        }
        
        header << forloop2.str() << "\t\t{"<<endl;;
        header << "\t\t\tif(mult" << accesspermi.str() << " > mult" << accesspermj.str() <<")return 1;" << endl;
        header << "\t\t\tif(mult" << accesspermi.str() << " < mult" << accesspermj.str() <<")return -1;" << endl;
        header << "\t\t}"<< endl;
        
        header << "\t\treturn 0;" << endl;
        header << "\t}\n";
    }
    
    
    header << "};\n";
    //end of domain class definition
    
    
    header << it.cname() << " operator + (const " << it.tokname() << "& t1 ,const " << it.tokname() << "& t2 )\n\n;";
    header << "std::ostream& operator << (std::ostream& out, const " << it.cname() << "& x);" << endl;
    
    SpnCppFile << "" << it.cname() << " operator + (const " << it.tokname() << "& t1 ,const " << it.tokname() << "& t2 ){\n";
    SpnCppFile << "\t"<< it.cname() << " d; d += t1; d+=t2 ;\n";
    SpnCppFile << "\treturn d;\n}\n";
    
    
    SpnCppFile << "std::ostream& operator << (std::ostream& out, const " << it.cname();
    SpnCppFile << "& x) {\n";
    SpnCppFile << "\tstringstream outprintloot;" << endl;
    printloot(SpnCppFile, it, 0);
    SpnCppFile << "\tout << \"(\" << outprintloot.str() << \")\";" << endl;
    SpnCppFile << "\treturn out;\n}\n";
    
    SpnCppFile << "inline bool contains(const "<<it.cname() << "& d1, const " << it.cname() << "& d2){";
    SpnCppFile << "\treturn (d1-d2) > -1;\n";
    SpnCppFile << "}\n";
    
    SpnCppFile << "inline bool contains(const "<<it.cname() << "& d1, const " << it.tokname() << "& tok){";
    SpnCppFile << "\treturn d1 >= tok;\n";
    SpnCppFile << "}\n";
}

void Gspn_Writer_Color::writeDomainSet(std::ofstream &SpnCppFile , std::ofstream &header, const colorDomain & it)const{
    header << "typedef DomainGen< " << it.tokname();
    /* for (let it2 : it.colorClassIndex) header << (it2==it.colorClassIndex[0]?" ":", ") << "contains_" << MyGspn.colClasses[it2].cname(); */
    header << "> " << it.cname() << ";" << endl;
    
    SpnCppFile << "inline bool contains(const "<<it.cname() << "& d1, const " << it.cname() << "& d2){";
    //SpnCppFile << "\treturn (d1-d2) > -1;\n";
    SpnCppFile << "\treturn d1 >= d2;\n";
    SpnCppFile << "}\n";
    
    SpnCppFile << "inline bool contains(const "<<it.cname() << "& d1, const " << it.tokname() << "& tok){";
    SpnCppFile << "\treturn d1 >= tok;\n";
    SpnCppFile << "}\n";
    
}

void Gspn_Writer_Color::writeMarkingClasse(ofstream &SpnCppFile,ofstream &header)const{

    for (vector<colorClass>::const_iterator it = MyGspn.colClasses.begin();
         it != MyGspn.colClasses.end(); ++it ) {
        header << "enum " << it->cname() << " {\n";
        for (vector<color>::const_iterator it2 = it->colors.begin();
             it2 != it->colors.end(); ++it2 ) {
            header << "\tColor_" << it->name << "_" << it2->name << ",\n";
        }
        header << "\tColor_" << it->name << "_Total,\n";
        header << "\tColor_"<< it->name << "_All\n};\n";
        header << "extern const char *Color_"<< it->name << "_names[];\n";
        header << "struct contains_"<< it->cname() << "{"<< endl;
        header << "\tvirtual void apply_perm("<< it->cname() << ",const std::vector<size_t> &index)=0;"<<endl;
        header << "\tvirtual int compare("<< it->cname() << ",int,int) const =0;"<<endl;
        header << "};"<< endl;
    }
    
    header << "#include \"marking.hpp\"" << endl;
    header << "#include \"markingTemplate.hpp\"" << endl;
    
    for (vector<colorDomain>::const_iterator it = MyGspn.colDoms.begin()+1;
         it != MyGspn.colDoms.end(); ++it ) {
        writeDomainToken(header, *it);
        if (P.is_domain_impl_set) { writeDomainSet(SpnCppFile, header, *it); }
        else { writeDomainTable(SpnCppFile, header, *it ); }
    }
   
    Gspn_Writer::writeMarkingClasse(SpnCppFile, header);
    
    if (P.is_domain_impl_set) {
        header << "class abstractBindingIteratorImpl {\n";
        header << "public:\n";

        for (vector<place>::const_iterator plit = MyGspn.placeStruct.begin();
            plit!= MyGspn.placeStruct.end(); ++plit) {
            if (not MyGspn.colDoms[plit->colorDom].isUncolored()) {
                header << "\tstd::map<"<< MyGspn.colDoms[plit->colorDom].tokname() << ", unsigned int>::const_iterator ItPl_"<< plit->name << ";\n";
            }
        }
        for (let var : MyGspn.colVars) {
            header << "\tsize_t ItVar_" << var.name << " = 0;\n";
            header << "\tbool IsDefItVar_" << var.name << " = false;\n";
        }
        header << "\tbool foundnint = true;";
        
        header << "\n\tvoid reset(abstractMarkingImpl& m);";
        
        SpnCppFile << "\nvoid abstractBindingIteratorImpl::reset(abstractMarkingImpl& m) {\n";
        for (vector<place>::const_iterator plit = MyGspn.placeStruct.begin();
            plit!= MyGspn.placeStruct.end(); ++plit) {
            if (not MyGspn.colDoms[plit->colorDom].isUncolored()) {
                SpnCppFile << "\n\tItPl_" << plit->name << " = m._PL_" << plit->name << ".tokens.begin();";
            }
        }
        for (let var : MyGspn.colVars) {
            SpnCppFile << "\n\tItVar_" << var.name << " = 0;";
            SpnCppFile << "\n\tIsDefItVar_" << var.name << " = false;";
        }
        SpnCppFile << "\n\tfoundnint = true;";
        if (P.verbose > 4) {
            SpnCppFile << "\n\t\tstd::cerr << \"abstractBindingIteratorImpl has been reset.\\n\";";
            SpnCppFile << "\n\t\tstd::cerr << \"[Call Values :] Found New ?\" << foundnint << \"\\n\";";
        }
        SpnCppFile << "\n}\n";
        
        header << "\nprivate:";
        header << "\n\tbool nextInterieur(size_t& t, abstractMarkingImpl& m) {\n";
        
        casesHandler bindingcases("t");
        for (size_t t = 0; t < MyGspn.tr ; t++){
            stringstream newcase;
        
            // liste des variables
            const auto& trans = MyGspn.transitionStruct[t];
            auto varlist = trans.varDomain;
            // tableau d'utilisations des placesz
            //bool estVisitee[MyGspn.placeStruct.size()];
            vector<bool> isVisited(MyGspn.placeStruct.size(),false);
            // Pour chaque variable :
            for (let var : varlist) {
                bool isUsed = false;
                for (let place : MyGspn.placeStruct) {
                    let vartemp = MyGspn.access(MyGspn.inArcsStruct, t, place.id);
                    if (not vartemp.containsVar(var)) { continue; }
                    isUsed = true;
                    if (isVisited[place.id]) { continue; }
                    isVisited[place.id] = true;
                    newcase << "\n\t\t\tif (m._PL_" << place.name << ".tokens.empty()) {";
                    newcase << "\n\t\t\t\treturn false;";
                    if (P.verbose > 4) {
                        newcase << "\n\t\t\t\tstd::cerr << \"Couldn't find tokens in place " << place.name << "\\n\";";
                    }
                    newcase << "\n\t\t\t}";
                    newcase << "\n\t\t\tif (not (ItPl_" << place.name << " == m._PL_" << place.name << ".tokens.end())) { ";
                    newcase << "\n\t\t\t\tItPl_" << place.name << "++;";
                    newcase << "\n\t\t\t\tif (not (ItPl_" << place.name << " == m._PL_" << place.name << ".tokens.end())) { ";
                    newcase << "\n\t\t\t\t\treturn true;";
                    newcase << "\n\t\t\t\t} else {";
                    newcase << "\n\t\t\t\tItPl_" << place.name << " = m._PL_" << place.name << ".tokens.begin();";
                    newcase << "\n\t\t\t\t}";
                    newcase << "\n\t\t\t}";
                    //newcase << "\n\t\t\t_IT_" << place.name << " = m._PL_" << place.name << ".tokens.begin();";
                }
                if (not isUsed) {
                    auto& currvar = MyGspn.colVars[var];
                    const auto& vardom = MyGspn.colDoms[currvar.type];
                    newcase << "\n\t\t\tif (not (ItVar_" << currvar.name << " == (((size_t) Color_" << vardom.name << "_Total) - 1) )) { ";
                    newcase << "\n\t\t\t\tItVar_" << currvar.name << "++; return true;";
                    newcase << "\n\t\t\t}";
                    newcase << "\n\t\t\tItVar_" << currvar.name << " = 0;";
                }
            }
            newcase << "\n\t\t\treturn false;";
            bindingcases.addCase(t, newcase.str(),MyGspn.transitionStruct[t].name);
        }
        bindingcases.writeCases(header);
        header << "\nreturn false;";
        header << "\n\t}";

        //header << "\nprivate:\n";
        
        //    header << "\tsize_t _ITVAR_" << var.name << ";\n";
        //    header << "\tbool _ISDEFITVAR_" << var.name << ";\n";
        
        header << "\n\tbool isCoherent(size_t& t,abstractMarkingImpl& m) {";
        for (let var : MyGspn.colVars) {
            header << "\n\t\t IsDefItVar_" << var.name << " = false;";
        }
        casesHandler bindingcasesB("t");
        for (size_t t = 0; t < MyGspn.tr ; t++){
            stringstream newcase;
        
            // liste des variables
            const auto& trans = MyGspn.transitionStruct[t];
            auto varlist = trans.varDomain;
            vector<bool> isVisited(MyGspn.placeStruct.size(),false);
            /* for (let var : varlist) {
                auto& currvar = MyGspn.colVars[var];
                bool isUsed = false;
                for (let place : MyGspn.placeStruct) {
                    if (isUsed) { continue; }
                    isUsed = true;
                }
                //if (not isUsed) { newcase << "\t _ISDEFITVAR_" << currvar.name << " = true;\n"; }
            } */
            
            // TODO : sortir le _ISDEFITVAR_ du code généré vers le code générateur
            for (let place : MyGspn.placeStruct) {
                bool placeVue = false;
                let vartempB = MyGspn.access(MyGspn.inArcsStruct, t, place.id).coloredVal;
                for (const auto& vartemp : vartempB) {
                    if (not placeVue) {
                        newcase << "\n\t\t\tif (m._PL_" << place.name << ".tokens.empty()) { return false; }";
                        placeVue = true;
                    }
                for (size_t varnum = 0;varnum < vartemp.field.size();varnum++) {
                //for (let var : vartemp) {
                    if (not (vartemp.Flags[varnum] == CT_VARIABLE)) { 
                        fprintf(stderr, "Un élément de l'arc n'est pas une variable"); exit(2);
                    }
                    auto& currvar = MyGspn.colVars[vartemp.field[varnum]];
                    newcase << "\n\t\t\tif (IsDefItVar_" << currvar.name << ") {";
                    newcase << "\n\t\t\t\tif (not (ItVar_" << currvar.name << " == (*ItPl_" << place.name << ").first.c" << varnum << ")) { return false; }";
                    // Cas où la variable est déjà définie
                    newcase << "\n\t\t\t}";
                    newcase << "\n\t\t\telse {";
                    // _IT_place : token ds un Domain
                    newcase << "\n\t\t\t\tItVar_" << currvar.name << " = (*ItPl_" << place.name << ").first.c" << varnum << ";";
                    newcase << "\n\t\t\t\tIsDefItVar_" << currvar.name << " = true;"; 
                    newcase << "\n\t\t\t\t}";
                }
                }
            }
            newcase << "\n\t\t\treturn true;";
            bindingcasesB.addCase(t, newcase.str(),MyGspn.transitionStruct[t].name);
        }
        // Lister les variables, mettre des valeurs "tentatives" en parcourant les valeurs actuelles
        // des différents itérateurs. Si échec/Collision => forcer le next
        bindingcasesB.writeCases(header);
        header << "\n\t\treturn true;";
        header << "\n\t}";
        
        header << "\npublic:\n";
        
        header << "\n\tbool next(size_t& t, abstractMarkingImpl& m);";
        SpnCppFile << "\nbool abstractBindingIteratorImpl::next(size_t& t, abstractMarkingImpl& m) {";
        SpnCppFile << "\n\tbool estCoherent = false;";
        if (P.verbose > 4) {
            SpnCppFile << "\n\t\tstd::cerr << \"abstractBindingIteratorImpl::next has been called.\\n\";";
            SpnCppFile << "\n\t\tstd::cerr << \"[Call Values :] Found New ?\" << foundnint << \" Is Coherent?\" << estCoherent << \"\\n\";";
        }
        SpnCppFile << "\n\twhile ((not estCoherent) and foundnint) {";
        SpnCppFile << "\n\t\tfoundnint = nextInterieur(t,m);";
        SpnCppFile << "\n\t\testCoherent = isCoherent(t,m);";
        if (P.verbose > 4) {
            SpnCppFile << "\n\t\tstd::cerr << \"Found New ?\" << foundnint << \" Is Coherent?\" << estCoherent << \"\\n\";";
        }
        SpnCppFile << "\n\t}";
        SpnCppFile << "\n\treturn estCoherent;";
        // Tant que c'est pas cohérent, je pop le next itérateur
        SpnCppFile << "\t}\n";
 
        // Créer une fonction qui génère concreteBinding ?
        header << "\n\tsize_t getIndex();";
        SpnCppFile << "size_t abstractBindingIteratorImpl::getIndex() {";
        SpnCppFile << "\n\tsize_t accum = 0;";
        for (let var : MyGspn.colVars) {
            size_t varclass = var.type;
            const auto& vardom = MyGspn.colDoms[varclass];
            SpnCppFile << "\n\taccum = ItVar_" << var.name << " + ((size_t) Color_" << vardom.name << "_Total) * accum;";
        }
        SpnCppFile << "\nreturn accum;";
        SpnCppFile << "\n\t}";
        
        header << "\n\tabstractBinding getBinding();";
        SpnCppFile << "abstractBinding abstractBindingIteratorImpl::getBinding() {";
        SpnCppFile << "\nabstractBinding newBind;";
        for (let var : MyGspn.colVars) {
            size_t varclass = var.type;
            const auto& classname = MyGspn.colDoms[varclass].name;
            SpnCppFile << "\nnewBind.P->" << var.name << ".c0 = (" << classname << "_Color_Classe) ItVar_" << var.name << ";";
        }
        SpnCppFile << "\n\tnewBind.idcount = getIndex();";
        SpnCppFile << "\n\treturn newBind;";
        SpnCppFile << "\n}";
        
        
        header << "};\n";
       
                
    }
    else {
        header << "\nclass abstractBindingIteratorImpl {";
        header << "\npublic:";
        header << "\n\tvoid reset(abstractMarkingImpl& m){};";
        header << "\n\tbool next(size_t& t, abstractMarkingImpl& m){return false;};";
        header << "\n\tsize_t getIndex(){return 0;};";
        header << "\n\tabstractBinding getBinding(){return abstractBinding();};";
        header << "\n};\n";
    }
    
    SpnCppFile << "\nvoid abstractBindingIterator::reset(abstractMarking& m) {";
    SpnCppFile << "\n\tP->reset(*(m.P));";
    SpnCppFile << "\n};";
        
    SpnCppFile << "\nabstractBindingIterator::abstractBindingIterator(abstractMarking& m) {";
    SpnCppFile << "\n\tP = new abstractBindingIteratorImpl;";
    SpnCppFile << "\n\treset(m);";
    SpnCppFile << "\n};";
                
    SpnCppFile << "\nbool abstractBindingIterator::next(size_t& t,abstractMarking& m) {";
    SpnCppFile << "\n\treturn P->next(t,*(m.P));";
    SpnCppFile << "\n};";
                
    SpnCppFile << "\nabstractBindingIterator::~abstractBindingIterator() {";
    SpnCppFile << "\n\tdelete(P);";
    SpnCppFile << "\n};";
    
    SpnCppFile << "\nsize_t abstractBindingIterator::getIndex() {";
    SpnCppFile << "\n\treturn P->getIndex();";
    SpnCppFile << "\n};";
    
    SpnCppFile << "\nabstractBinding abstractBindingIterator::getBinding() {";
    SpnCppFile << "\n\treturn P->getBinding();";
    SpnCppFile << "\n};\n";
}

