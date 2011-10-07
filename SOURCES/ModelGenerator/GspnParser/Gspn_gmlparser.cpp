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
#include <map>
#include <vector>

#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "Gspn_gmlparser.hpp"
#include "../Eval/Eval.hpp"

#include "Gspn-Reader.hpp"


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

MyModelHandler::MyModelHandler(GSPN* MyGspn2) /*: ModelHandler()*/ { 
		MyGspn= MyGspn2;
		countPl=0;
	}
	//~MyModelHandler() { }
	
	
    void MyModelHandler::on_read_model(const XmlString& formalismUrl) {
        cout << "read model : formalism = " << formalismUrl << endl;
    }
	
    void MyModelHandler::on_read_model_attribute(const Attribute& attribute) {
        //print_tree(attribute, attribute.begin(), attribute.end());
    }
	
    void MyModelHandler::on_read_node(const XmlString& id,
					  const XmlString& nodeType,
					  const AttributeMap& attributes,
					  const XmlStringList& references) {
        cout << "read node : " << id << ", " << nodeType << endl;
		if(nodeType.compare("place")==0){
			cout << "place:"<<endl;
			MyGspn->pl++;
			
			for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
				if((*(it->second.begin())).compare("marking")==0){
					string Plmark = *(++(it->second.begin()));
					Evaluate_gml.parse(Plmark);
					cout << "\tmarking:" << Plmark << endl ;
					MyGspn->Marking.push_back(Evaluate_gml.IntResult);
							
				} else if((*(it->second.begin())).compare("name")==0){
					string Plname = *(++(it->second.begin()));
					cout << "\tname:" << Plname << endl ;
					MyGspn->PlacesList.insert(Plname);
					MyGspn->PlacesId[Plname]=countPl;

					
				} else cout << "fail to parse gml"<< endl;
					
			}
			countPl++ ;
		
		}else {
			if (nodeType.compare("transition")==0){
				cout << "transition!!"<<endl;
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
        cout << "read arc : " << id << ", " << arcType << ", " << source << " -> " << target << endl;
        for(AttributeMap::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
            //print_tree(it->second, it->second.begin(), it->second.end());
        }
        for(XmlStringList::const_iterator it = references.begin(); it != references.end(); ++it) {
            cout << "    ref => " << *it << endl;
        }
    }
