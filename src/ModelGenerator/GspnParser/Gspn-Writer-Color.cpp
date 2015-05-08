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

#include "Gspn-Writer-Color.hpp"

Gspn_Writer_Color::Gspn_Writer_Color(GspnType& mgspn,parameters& Q):Gspn_Writer(mgspn,Q){}

void Gspn_Writer_Color::writeEnabledDisabledBinding(ofstream &SpnF){
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
                        ":\t//" << MyGspn.transitionStruct[trit].label << "->"
                        << MyGspn.placeStruct[pivotplace].name <<
                        "->" << MyGspn.transitionStruct[trit2].label << endl;
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
                        SpnF << "\t\t//Fallback:" << MyGspn.transitionStruct[trit].label << "->" << MyGspn.transitionStruct[trit2].label << endl;
                    } else if(varList.size() < MyGspn.transitionStruct[trit2].varDomain.size()){
                        SpnF << "\t\t//Partial synch over variable: " << MyGspn.transitionStruct[trit].label << "->" << MyGspn.transitionStruct[trit2].label << " var ";
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
                            }else
                                fallback= true; // Handling of several token not yet implemented
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
                        ":\t//" << MyGspn.transitionStruct[trit].label << "->"
                        << MyGspn.placeStruct[pivotplace].name <<
                        "->" << MyGspn.transitionStruct[trit2].label << endl;
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
                        SpnF << "\t\t//Fallback:" << MyGspn.transitionStruct[trit].label << "->" << MyGspn.transitionStruct[trit2].label << endl;
                    } else if(varList.size() < MyGspn.transitionStruct[trit2].varDomain.size()){
                        SpnF << "\t\t//Partial synch over variable: " << MyGspn.transitionStruct[trit].label << "->" << MyGspn.transitionStruct[trit2].label << " var ";
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


void Gspn_Writer_Color::printloot(ofstream& fs, size_t domain, size_t nesting ){
    const colorDomain& dom = MyGspn.colDoms[domain];
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
    printloot(fs, domain, nesting+1);
}

void Gspn_Writer_Color::writeMarkingClasse(ofstream &SpnCppFile,ofstream &header, parameters &P){

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
    }


    for (vector<colorDomain>::const_iterator it = MyGspn.colDoms.begin()+1;
         it != MyGspn.colDoms.end(); ++it ) {

        //token class def
        header << "\nstruct " << it->tokname() << "{\n";
        vector<size_t>::const_iterator itcol;
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            header << "\t" << MyGspn.colClasses[*itcol].cname() << " c" << itcol - it->colorClassIndex.begin() << ";\n";
        }
        header << "\tint mult;\n";

        header << "\t" << it->tokname() << "( ";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            header << " "<<MyGspn.colClasses[*itcol].cname() << " cv" << itcol - it->colorClassIndex.begin()<< " = ("<< MyGspn.colClasses[*itcol].cname() << ")0, " ;
        }
        header << "int v =1) {\n";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            size_t pos = itcol - it->colorClassIndex.begin();
            header << "\t\tc" << pos << "= cv"<<pos <<";\n";
        }
        header << "\t\tmult = v;\n\t}\n";


        header << "\t" << it->tokname() << "( ";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            header << "const "<<MyGspn.colClasses[*itcol].name << "_Token& cv" << itcol - it->colorClassIndex.begin()<< ", " ;
        }
        header << "int v =1) {\n";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            size_t pos = itcol - it->colorClassIndex.begin();
            header << "\t\tc" << pos << "= cv";
            header << pos << ".c0" << ";\n";
        }
        header << "\t\tmult = v;\n\t}\n";

        header << "\t" << it->tokname() << " operator * (size_t v){\n";
        header << "\t\tmult *= v;\n\t\treturn *this;\n\t}\n";


        header << "\tvoid iter() {\n";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            size_t pos = itcol - it->colorClassIndex.begin();
            header << "\t\tif( c" << pos << "< ("<< MyGspn.colClasses[*itcol].cname() << ")(Color_";
            header << MyGspn.colClasses[*itcol].name << "_Total - 1) )";
            header << "{ c"<< pos << " = ("<< MyGspn.colClasses[*itcol].cname() << ")(c"<< pos <<"+ 1); return;};\n";
            header << "c"<< pos << " = ("<< MyGspn.colClasses[*itcol].cname() << ")(0);\n";
        }
        header << "\t}\n";

        header << "\tvoid print(){\n\t\tstd::cerr << mult << \"<\" <<";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            if(itcol != it->colorClassIndex.begin())header << "<< \" , \" << ";
            header << " Color_"<< MyGspn.colClasses[*itcol].name << "_names[c" << itcol - it->colorClassIndex.begin() << "]";
        }
        header << " << \">\";\n";
        header << "\t}\n";


        if (it->colorClassIndex.size()==1 && MyGspn.colClasses[it->colorClassIndex[0]].isCircular) {
            header << "\t" << it->tokname() << " next(int i)const {\n";
            header << "\t\t" << it->tokname() << " x(("<< MyGspn.colClasses[it->colorClassIndex[0]].cname() << ")((c0 +i) % Color_";
            header << MyGspn.colClasses[it->colorClassIndex[0]].name << "_Total), ";
            header << " mult);\n\t\treturn x;}\n";
        }

        header << "\tbool islast()const {\n\t\treturn (";
        for (itcol = it->colorClassIndex.begin(); itcol != it->colorClassIndex.end() ; ++itcol ) {
            size_t pos = itcol - it->colorClassIndex.begin();
            if (pos > 0)header << " && ";
            header << " c" << pos << "== ("<< MyGspn.colClasses[*itcol].cname() << ")(Color_";
            header << MyGspn.colClasses[*itcol].name << "_Total -1) ";
        }
        header << " );\n\t}\n";

        header << "\tbool operator > (const int x){\n";
        header << "\t\treturn mult > x ;\n\t}\n";
        header << "\tbool operator < (const int x){\n";
        header << "\t\treturn mult < x ;\n\t}\n";

        header << "};\n";



        stringstream colorArgsName;
        stringstream colorArrayAccess;
        stringstream colorArrayAccess2;
        stringstream allCondition;
        stringstream forLoop;

        header << "struct " << it->cname() << " {\n\tint mult";
        for (vector<size_t>::const_iterator it2 = it->colorClassIndex.begin();
             it2 != it->colorClassIndex.end(); ++it2 ) {
            header << "[ Color_" << MyGspn.colClasses[*it2].name << "_Total ]";
            size_t countCol = it2 - it->colorClassIndex.begin();
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
        header << ";\n";
        header << "\t" << it->cname() << "(size_t v =0) { fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), v );}"<< endl;
        header << "\t" << it->cname() << "(" << colorArgsName.str() << ") {\n";
        //header << "\t\t" << "memset(&mult,0 , sizeof(mult));\n";
        header << "\t\t" << "fill( (int*)mult ,((int*)mult) + sizeof(mult)/sizeof(int), 0 );"<< endl;
        header << "\t\t" << "if(" << allCondition.str() << ")\n";
        header << "\t\t\t" << "mult" << colorArrayAccess.str() << " = 1 ;\n";
        header << "\t\telse{\n";
        header << forLoop.str() << "\t\t\t\tmult" << colorArrayAccess2.str() << " = 1 ;\n";

        header << "\t\t}\n";
        header << "\t}\n";
        header << "\t" << it->cname() << "& operator = (const " << it->cname() << "& x){\n";
        header << "\t\tcopy((int*)x.mult,(int*)x.mult + sizeof(mult)/sizeof(int),(int*)mult);\n\t\treturn *this;\n\t}\n";

        header << "\tbool operator == (const " << it->cname() << "& x){\n";
        header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult);\n\t}\n";

        header << "\tbool operator < (const " << it->cname() << "& x){\n";
        header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::less<int>());\n\t}\n";

        header << "\tbool operator > (const " << it->cname() << "& x){\n";
        header << "\t\treturn  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());\n\t}\n";

        header << "\t" << it->cname() << " operator * (int v){\n";
        header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++) ((int*)mult)[count]*= v;\n\t\treturn *this;\n\t}\n";

        header << "\t" << it->cname() << "& operator += (const " << it->cname() << "& x){\n";
        header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
        header << "\n\t\t\t((int*)mult)[count]+= ((int*)x.mult)[count] ;\n";
        header << "\t\treturn *this;\n\t}\n";

        header << "\t" << it->cname() << "& operator += (const " << it->tokname() << "& x){\n";
        header << "\t\tmult";
        for (vector<size_t>::const_iterator it2 = it->colorClassIndex.begin();
             it2 != it->colorClassIndex.end(); ++it2 ) {
            header << "[ x.c" << it2- it->colorClassIndex.begin() << " ]" ;
        }
        header << " += x.mult;\n\t\treturn *this;\n\t}\n";

        header << "\t" << it->cname() << " operator + (const " << it->tokname() << "& x){\n";
        header << "\t\t"<< it->cname()<< " d(*this);\n\t\td+=x;\n ";
        header << "\t\treturn d;\n}\n";

        header << "\t" << it->cname() << "& operator -= (const " << it->tokname() << "& x){\n";
        header << "\t\tmult";
        for (vector<size_t>::const_iterator it2 = it->colorClassIndex.begin();
             it2 != it->colorClassIndex.end(); ++it2 ) {
            header << "[ x.c" << it2- it->colorClassIndex.begin() << " ]" ;
        }
        header << " -= x.mult;\n\t\treturn *this;\n\t}\n";

        header << "\tbool operator < (const " << it->tokname() << "& x)const{\n";
        header << "\t\treturn mult";
        for (vector<size_t>::const_iterator it2 = it->colorClassIndex.begin();
             it2 != it->colorClassIndex.end(); ++it2 ) {
            header << "[ x.c" << it2- it->colorClassIndex.begin() << " ]" ;
        }
        header << " < x.mult;\n\t}\n";

        header << "\tbool operator >= (const " << it->tokname() << "& x)const{\n";
        header << "\t\treturn mult";
        for (vector<size_t>::const_iterator it2 = it->colorClassIndex.begin();
             it2 != it->colorClassIndex.end(); ++it2 ) {
            header << "[ x.c" << it2- it->colorClassIndex.begin() << " ]" ;
        }
        header << " >= x.mult;\n\t}\n";

        header << "\t" << it->cname() << " operator + (const " << it->cname() << "& x)const{\n";
        header << "\t\t"<< it->cname() << " returnval = *this; returnval+= x;\n";
        header << "\t\treturn returnval;\n\t}\n";

        header << "\t" << it->cname() << "& operator -= (const " << it->cname() << "& x){\n";
        header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
        header << "\n\t\t\t((int*)mult)[count]-= ((int*)x.mult)[count] ;\n";
        header << "\t\treturn *this;\n\t}\n";

        header << "\t" << it->cname() << " operator - (const " << it->cname() << "& x)const{\n";
        header << "\t\t"<< it->cname() << " returnval = *this; returnval-= x;\n";
        header << "\t\treturn returnval;\n\t}\n";

        header << "\tint card (void){\n";
        header << "\tint acc=0;\n";
        header << "\t\tfor(size_t count = 0 ; count < sizeof(mult)/sizeof(int);count++)";
        header << "\n\t\t\tacc += ((int*)mult)[count] ;\n";
        header << "\t\treturn acc;\n\t}\n";

        header << "};\n";
        //end of domain class definition


        header << it->cname() << " operator + (const " << it->tokname() << "& t1 ,const " << it->tokname() << "& t2 )\n\n;";

        SpnCppFile << "" << it->cname() << " operator + (const " << it->tokname() << "& t1 ,const " << it->tokname() << "& t2 ){\n";
        SpnCppFile << "\t"<< it->cname() << " d; d += t1; d+=t2 ;\n";
        SpnCppFile << "\treturn d;\n}\n";


        SpnCppFile << "std::ostream& operator << (std::ostream& out, const " << it->cname();
        SpnCppFile << "& x) {\n";
        SpnCppFile << "\tstringstream outprintloot;" << endl;
        printloot(SpnCppFile, it - MyGspn.colDoms.begin(), 0);
        SpnCppFile << "\tout << \"(\" << outprintloot.str() << \")\";" << endl;
        SpnCppFile << "\treturn out;\n}\n";

        SpnCppFile << "inline bool contains(const "<<it->cname() << "& d1, const " << it->cname() << "& d2){";
        SpnCppFile << "\treturn (d1-d2) > -1;\n";
        SpnCppFile << "}\n";

        SpnCppFile << "inline bool contains(const "<<it->cname() << "& d1, const " << it->tokname() << "& tok){";
        SpnCppFile << "\treturn d1 >= tok;\n";
        SpnCppFile << "}\n";
    }

    Gspn_Writer::writeMarkingClasse(SpnCppFile, header, P);
}

