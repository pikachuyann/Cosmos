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
 * file Gspn-Grml-Output.cpp                                                   *
 * Created by Benoit Barbot on 02/11/2015.                                     *
 *******************************************************************************
 */

#include "Gspn-Grml-Output.hpp"

using namespace std;


void GspnGrmlOutput::print(ostream& os){
    os << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    os << "<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">" << endl;
    
    os << "\t<attribute name=\"declaration\">" << endl;
    os << "\t\t<attribute name=\"constants\">" << endl;
    if(!IntConstant.empty()){
        os << "\t\t\t<attribute name=\"intConsts\">"<< endl;
        for(let n:IntConstant){
            os << "\t\t\t\t<attribute name=\"intConst\"><attribute name=\"name\">";
            os << n.first << "</attribute><attribute name=\"expr\"><attribute name=\"numValue\">";
            os << n.second << "</attribute></attribute></attribute>" << endl;
        }
        os << "\t\t\t</attribute>"<< endl;
    }
    if(!RealConstant.empty()){
        os << "\t\t\t<attribute name=\"realConsts\">"<< endl;
        for(let n:RealConstant){
            os << "\t\t\t\t<attribute name=\"realConst\"><attribute name=\"name\">";
            os << n.first << "</attribute><attribute name=\"expr\"><attribute name=\"numValue\">";
            os << n.second << "</attribute></attribute></attribute>" << endl;
        }
        os << "\t\t\t</attribute>"<< endl;
    }
    os << "\t\t</attribute>" << endl;
    
    
    for(let c: colClasses){
        os << "\t\t<attribute name=\"classDeclaration\">";
        os << "<attribute name=\"name\">" << c.name << "</attribute>" << endl;
        os << "\t\t\t<attribute name=\"classType\">";
        if(c.intIntervalName.empty()){
            os << "<attribute name=\"classEnum\">"<< endl;;
            for(let cc :c.colors)os << "<attribute name=\"enumValue\">"<< cc.name << "</attribute>";
        }else{
            os << "<attribute name=\"classIntInterval\">"<< endl;;
            os << "\t\t\t\t<attribute name=\"lowerBound\">";
            expr(1).printXML(os);
            os << "</attribute>" << endl;
            os << "\t\t\t\t<attribute name=\"higherBound\">";
            expr((int)c.colors.size()).printXML(os);
            os << "</attribute>" << endl;
            os << "\t\t\t</attribute></attribute>" << endl;
        }
        os << "\t\t\t<attribute name=\"circular\">" << boolalpha << c.isCircular << "</attribute>"<<endl;
        os << "\t\t</attribute>" << endl;
    }
    
    for(let v:colVars){
        os << "\t\t<attribute name=\"variableDeclaration\">";
        os << "<attribute name=\"name\">" << v.name << "</attribute>" << endl;
        os << "<attribute name=\"type\">" << colDoms[v.type].name << "</attribute>" << endl;
        os << "\t\t</attribute>" << endl;
    }
    
    os << "\t</attribute>" << endl;
    
    for(let p: placeStruct)printPlace(os,p);
    for(let t: transitionStruct)printTransition(os,t);
    for(let inarc : inArcsStruct)
        printArc(os, make_pair(
                               get_uid("P_"+to_string(inarc.first.second)),
                               get_uid("T_"+to_string(inarc.first.first))),
                 inarc.second, false, placeStruct[inarc.first.first].colorDom);
    for(let outarc : outArcsStruct)
        printArc(os, make_pair(
                               get_uid("T_"+to_string(outarc.first.first)),
                               get_uid("P_"+to_string(outarc.first.second))),
                 outarc.second, false,placeStruct[outarc.first.first].colorDom);
    for(let inhibarc : inhibArcsStruct)
        printArc(os, make_pair(
                               get_uid("P_"+to_string(inhibarc.first.second)),
                               get_uid("T_"+to_string(inhibarc.first.first))),
                 inhibarc.second, true, placeStruct[inhibarc.first.first].colorDom);
       os << "</model>" << endl;
}

void GspnGrmlOutput::printToken(ostream& os, const coloredToken& c,size_t cd)const{
    if( c.mult.t == Int && c.mult.intVal == 0)return;
    os << "\t\t\t<attribute name=\"token\">" << endl;
    os << "\t\t\t\t<attribute name=\"occurs\">";
    c.mult.printXML(os);
    os << "</attribute>" << endl;
    if(cd != UNCOLORED_DOMAIN){
        os << "\t\t\t\t<attribute name=\"tokenProfile\"><attribute name=\"expr\">"<<endl;
        if(c.hasAll){
            os << "\t\t\t\t\t<attribute name=\"function\"><attribute name=\"all\"><attribute name=\"type\">";
            os << colDoms[cd].name;
            os << "</attribute></attribute></attribute>" << endl;
        }else{
            os << "\t\t\t\t\t<attribute name=\"expr\">" << endl;
            for(size_t i =0 ; i < c.field.size(); i++)
                switch (c.Flags[i]){
                    case CT_VARIABLE:
                        if( c.varIncrement[i] == 0 ){
                            os << "\t\t\t\t\t<attribute name=\"name\">";
                            os << colVars[c.field[i]].name;
                            os << "</attribute>"<<endl;
                        }else{
                            os << "\t\t\t\t\t<attribute name=\"function\"><attribute name=\"++\">" << endl;
                            os << "\t\t\t\t\t\t<attribute name=\"name\">";
                            os << colVars[c.field[i]].name;
                            os << "</attribute>"<< endl;
                            os << "\t\t\t\t\t\t<attribute name=\"intValue\">";
                            os << c.varIncrement[i];
                            os << "</attribute>"<< endl;
                            os << "\t\t\t\t\t</attribute></attribute>"<< endl;
                        }
                        break;
                    default:
                        os << "<FAILFAIL>";
                }
            os << "\t\t\t\t\t</attribute>"<< endl;
        }
        os << "\t\t\t\t</attribute></attribute>"<<endl;
    }
    os << "\t\t\t</attribute>" << endl;
}

void GspnGrmlOutput::printDistribution(ostream& os, const Distribution& d){
    os << "\t\t<attribute name=\"distribution\">" << endl;
    os << "\t\t\t<attribute name=\"type\">" << d.name << "</attribute>"<< endl;
    for( let p : d.Param){
        os << "\t\t\t<attribute name=\"param\">";
        p.printXML(os);
        os << "</attribute>"<< endl;
    }
    os << "\t\t</attribute>"<< endl;
}

void GspnGrmlOutput::printArc(ostream& os, const pair<size_t,size_t>& p, const arc& a, bool isInhib, size_t cd){
    os << "\t<arc id=\""<< GspnType::new_uid("Arc") << "\" ";
    os << "arcType=\"" <<(isInhib? "inhibitorarc":"arc") << "\" ";
    os << "source=\"" << p.first << "\" ";
    os << "target=\"" << p.second << "\" ";
    os << ">"<<endl;
    os << "\t\t<attribute name=\"valuation\">";
    if(!a.isColored){
        os << "<attribute name=\"numValue\">";
        a.coloredVal[0].mult.printXML(os);
        os << "</attribute>"<<endl;
    } else {
        os << endl;
        for (let t: a.coloredVal) {
            printToken(os, t, cd);
        }
    }
    os << "\t\t</attribute>" << endl;
    os << "\t</arc>"<< endl;

    
        /*
       
         <attribute name="valuation">
         <attribute name="token">
         <attribute name="occurs">
         <attribute name="intValue">
         1
         </attribute>
         </attribute>
         <attribute name="tokenProfile">
         <attribute name="expr">
         <attribute name="name">
         x
         </attribute>
         </attribute>
         </attribute>
         </attribute>
         </attribute>
       */
}

void GspnGrmlOutput::printTransition(ostream& os, const transition& t){
    os << "\t<node id=\""<< GspnType::get_uid("T_"+ to_string(t.id)) << "\" nodeType=\"transition\">"<<endl;
    os << "\t\t<attribute name=\"name\">" + t.name + "</attribute>"<< endl;
    os << "\t\t<attribute name=\"weight\">";
    t.weight.printXML(os);
    os << "</attribute>" << endl;
    os << "\t\t<attribute name=\"guard\">";
    t.guard.printXML(os);
    os << "</attribute>" << endl;
    os << "\t\t<attribute name=\"priority\">";
    t.priority.printXML(os);
    os << "</attribute>" << endl;
    os << "\t\t<attribute name=\"service\">";
    expr(t.nbServers).printXML(os);
    os << "</attribute>" << endl;
    printDistribution(os, t.dist);
    os << "\t</node>"<< endl;
}


void GspnGrmlOutput::printPlace(ostream& os, const place& p){
    os << "\t<node id=\""<< GspnType::get_uid("P_"+ to_string(p.id)) << "\" nodeType=\"place\">"<<endl;
    os << "\t\t<attribute name=\"name\">" + p.name + "</attribute>"<< endl;
    if(p.colorDom != UNCOLORED_DOMAIN){
        os << "\t\t<attribute name=\"domain\"><attribute name=\"type\">";
        os << colDoms[p.colorDom].name;
        os << "</attribute></attribute>" << endl;
    }
    os << "\t\t<attribute name=\"marking\">";
    if(p.colorDom == UNCOLORED_DOMAIN){
        os << "<attribute name=\"numValue\">";
        p.initMarking[0].mult.printXML(os);
        os << "</attribute>"<<endl;
    } else {
        os << endl;
        for (let t: p.initMarking) {
            printToken(os, t,p.colorDom);
        }
    }
    os << "\t\t</attribute>" << endl;
    os << "\t</node>"<< endl;
}

