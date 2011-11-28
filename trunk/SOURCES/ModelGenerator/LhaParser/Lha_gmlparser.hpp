/*
 *  Lha_gmlparser.h
 *  Cosmos
 *
 *  Created by Benoit Barbot on 03/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LHA_GML_HPP
#define	_LHA_GML_HPP

#include "expatmodelparser.hh"
#include "modelhandler.hh"
#include "Lha-Reader.hpp"
#include <map>

class MyLhaModelHandler: public ModelHandler
{
private:
	string* simplifyString(string str);
	void appendSimplify(string *st, string str);
	void eval_expr(bool *is_mark_dep, string *st, tree<string>::pre_order_iterator);
	void eval_linexpr(vector<string> , tree<string>::pre_order_iterator );
	void eval_guard(vector<vector<string> >,vector<string> , vector<string>, tree<string>::pre_order_iterator );
	int eval_str (string);
	int eval_intFormula( map<std::string,int> intconst, tree<string>::pre_order_iterator);
	Eval Evaluate_gml;
	
	vector<string> FuncUpdateVector;
	
	set <string> PetriTransitions;
	//set <string> SubSet;
	
	
	
	vector < string > CoeffsVector;
	vector < vector <string> > CoeffsMatrix;
	vector <string> CST;
	vector <string> comp;
	
	
	int countLoc;
	bool ParseLoc;
	//bool ParseDecl;
	map<int,int> Gml2Loc;
	map<int,bool> IsPlace;
	LHA* MyLHA;
public:
    MyLhaModelHandler(LHA* ) ;
	//~MyModelHandler() { }
	
	
    void on_read_model(const XmlString& formalismUrl) ;
	
    void on_read_model_attribute(const Attribute& attribute)	;
	
    void on_read_node(const XmlString& id,
					  const XmlString& nodeType,
					  const AttributeMap& attributes,
					  const XmlStringList& references) ;
	
    void on_read_arc(const XmlString& id,
					 const XmlString& arcType,
					 const XmlString& source,
					 const XmlString& target,
					 const AttributeMap& attributes,
					 const XmlStringList& references);
};








#endif


