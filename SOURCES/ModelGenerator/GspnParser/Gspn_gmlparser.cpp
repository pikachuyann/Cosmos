/*
 *  Gspn_gmlparser.cpp
 *  Cosmos
 *
 *  Created by Benoit Barbot on 05/10/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

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

MyModelHandler::MyModelHandler(GSPN* MyGspn2) {
	//Initialisation
		MyGspn= MyGspn2;
		countPl=0;
		countTr=0;
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
			if((*it).compare("const")==0){
				//const definition
				//cout << "const definition" << endl;
				bool isint =true;
				string constname ="";
				string constvalue ="";
				for (tree<string>::sibling_iterator it2 = (it.begin()) ; it2 != (it.end()) ; ++it2 ) {
					//cout << "\t\t" << (*it2) << ":" << endl;
					if ((*it2).compare("type")==0) { // const is int or double
						if((*(it2.begin())).compare("int")!=0)isint=false;
					} else if ((*it2).compare("name")==0) { // const name
						constname = *(it2.begin());
					} else if ((*it2).compare("value")==0) { // const value
						constvalue = *(it2.begin());
					} else {
						cout << "fail to parse gml"<< endl;
					}
				}
				if (isint) {
					Evaluate_gml.parse(constvalue);
					MyGspn->IntConstant[*(new string(constname))]=Evaluate_gml.IntResult;
					MyGspn->RealConstant[*(new string(constname))]=Evaluate_gml.RealResult;
					cout << "\tconst int " << constname << "=" << Evaluate_gml.IntResult << endl;
				} else {
					Evaluate_gml.parse(constvalue);
					MyGspn->RealConstant[*(new string(constname))]=Evaluate_gml.RealResult;
					cout << "\tconst double " << constname << "=" << Evaluate_gml.RealResult << endl;
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
			cout << "place:"<<endl;
			flush(cout);
			MyGspn->pl++;
			int id2 = atoi(id.c_str());
			IsPlace[id2]=true;
			Gml2Place[id2]=countPl;
			
			for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
				if((*(it->second.begin())).compare("marking")==0){
					string Plmark = *(++(it->second.begin()));
					Evaluate_gml.parse(Plmark);
					cout << "\tmarking:" << Plmark << endl ;
					MyGspn->Marking.push_back(Evaluate_gml.IntResult);
							
				} else if((*(it->second.begin())).compare("name")==0){
					string Plname = *(++(it->second.begin()));
					cout << "\tname:" << Plname << endl ;
					string& Plname2 = *(new string(Plname));
					MyGspn->PlacesList.insert(Plname2);
					MyGspn->PlacesId[Plname2]=countPl;

					
				} else cout << "fail to parse gml"<< endl;
					
			}
			countPl++ ;
		
		}else {
			if (nodeType.compare("transition")==0){
				cout << "transition:"<<endl;
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
						string Trname = *(++(it->second.begin()));
						cout << "\tname:" << Trname << endl ;
						string& Trname2 = *(new string(Trname));
						MyGspn->TransList.insert(Trname2);
						MyGspn->TransId[Trname2]=countTr;
					} else if ((*(it->second.begin())).compare("distribution")==0) {
						cout << "\tdistribution:" << endl ;
						ProbabiliteDistribution& dist = *(new ProbabiliteDistribution);
						for (tree<string>::sibling_iterator it2 = (it->second.begin()).begin() ; it2 != (it->second.begin()).end() ; ++it2 ) {
							cout << "\t\t" << (*it2) << ":" << *(it2.begin())<< endl;
							if ((*it2).compare("type")==0) {
								if((*(it2.begin())).compare("IMDT")==0)timed=unTimed;
								dist.name = *(new string(*(it2.begin())));
							} else {
								if(Evaluate_gml.parse(*(it2.begin()))){
									dist.Param.push_back(*(new string(*(it2.begin()))));
									markingdependant=true;
								} else {
									std::ostringstream s;s<<Evaluate_gml.RealResult;
									dist.Param.push_back(s.str());
								}
							}
						}
						MyGspn->Dist.push_back(dist);
						
					} else if ((*(it->second.begin())).compare("service")==0) {
						if ((*(++(it->second.begin()))).compare("Infinite")==0) {
							singleservice=false;
							nbserver=INT_MAX;
						} else {
							int nbsrv = atoi((*(++(it->second.begin()))).c_str());
							if (nbsrv!=1) {
								singleservice=false;
								nbserver=nbserver;
							}
						}
					} else if ((*(it->second.begin())).compare("weight")==0) {
						string st=*(++(it->second.begin()));
						if(Evaluate_gml.parse(st)) {
								cout<<"Weight is not marking dependent: '"<<st<<"'"<<endl;
						} else {  
							if(Evaluate_gml.RealResult<0){
								cout<<"Weight is a positive value: '"<<st<<"'"<<endl;
							} else { 
								std::ostringstream s;s<<Evaluate_gml.RealResult;
								weight= s.str();
							} 
						}
						
					} else if ((*(it->second.begin())).compare("priority")==0) {
						string st=*(++(it->second.begin()));
						if(Evaluate_gml.parse(st)) {
							cout<<"Priority is not marking dependent: '"<<st<<"'"<<endl;
						} else {  
							if(Evaluate_gml.RealResult<0){
								cout<<"Priority is a positive value: '"<<st<<"'"<<endl;
							} else { 
								std::ostringstream s;s<<Evaluate_gml.RealResult;
								priority= s.str();
							} 
						}
						
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
		string valuation;
		//cout << arcType << endl;
		
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
			if((*(it->second.begin())).compare("valuation")==0){
				valuation = *(++(it->second.begin()));
			}else cout << "fail to parse gml"<< endl;
				
        }
		int sourceGML = atoi(source.c_str());
		if(IsPlace[sourceGML]){
			if(arcType.compare("inhibitorarc")){
				if(Evaluate_gml.parse(valuation)){
					MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
					MyGspn->inhibArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]= *(new string(valuation));
				}
				else MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
				//MyGspn->inhibArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
			}else {
				if(Evaluate_gml.parse(valuation)){
					MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=1;
					MyGspn->inArcsStr[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=*(new string(valuation));
				}
				else MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=Evaluate_gml.IntResult;
				//MyGspn->inArcs[Gml2Trans[atoi(target.c_str())]][Gml2Place[sourceGML]]=valuation;
			}
		}else {
			if(Evaluate_gml.parse(valuation)){
				MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=1;
				MyGspn->outArcsStr[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=*(new string(valuation));
			}
			else MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=Evaluate_gml.IntResult;
			//MyGspn->outArcs[Gml2Trans[sourceGML]][Gml2Place[atoi(target.c_str())]]=valuation;
		}

		
        /*for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }*/
    }
