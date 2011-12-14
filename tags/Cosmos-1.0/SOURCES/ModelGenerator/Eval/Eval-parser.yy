/*******************************************************************************
 *									       *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)dels (S)tochastique *
 *									       *
 * Copyright (C) 2009-2011 LSV, ENS Cachan & CNRS & INRIA                      *
 * Author: Paolo Ballarini & Hilal Djafri                                      *
 * Website: http://www.lsv.ens-cachan.fr/Software/Cosmos                       *
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
 *                                                                             *
 *******************************************************************************
 */


%skeleton "lalr1.cc"                          /*  -*- C++ -*- */
%require "2.4"
%defines
%define parser_class_name "Eval_parser"

%code requires {
#include <math.h>
#include <limits.h>
# include <string>

#include <fstream>
#include <sstream>
#include <set>
class Eval;


}

// The parsing context.
%parse-param { Eval& Evaluate }
%lex-param   { Eval& Evaluate }

%locations

%debug
%error-verbose

// Symbols.
%union
{
  double       RealVal;
  int 	       IntVal;  
  std::string *name;
  
};

%code {
#include "Eval.hpp"
#include <set>
#include <vector>

}

%token        END      0 "end of file"

%token <name>  	 str
%token <RealVal>  rval
%token <IntVal>  ival

%token <name>     MIN
%token <name>     MAX
%token <name>	  FLOOR  
%token <name>	  ABS
%token <name>	  PLUS 
%token <name>	  MINUS
%token <name>	  MUL 
%token <name>	  DIV 
%token <name>	  POWER 
%token <name>	  LB
%token <name>	  RB
%token <name>	  COMMA
%token <name>	  DOUBLE

%type<RealVal>	exp



%printer    { debug_stream () << *$$; } str
%destructor { delete $$; } str 

%printer    { debug_stream () << $$; } <IntVal>
%printer    { debug_stream () << $$; } <RealVal>

%%

%left PLUS MINUS;
%left NEG;
%left MUL  DIV;
%left POWER;
%left DOUBLE;
%start ArithmethicExp;
ArithmethicExp:exp {Evaluate.IntResult=(int) $1;Evaluate.RealResult=$1;};
exp:
	ival {$$=$1;}
	|rval {$$=$1;}
	|LB exp RB {$$=$2;}
	|str {YYABORT; }
	|MINUS exp %prec NEG {$$=-$2;}
	|exp PLUS exp{$$=$1+$3;}
	|exp MUL exp{$$=$1*$3;}
	|exp MINUS exp{$$=$1-$3;}
	|DOUBLE exp {$$=double($2);}
	|exp DIV exp	{if($3==0)	  {cout<<"Division by zero !";YYABORT;} 
					 else $$=$1/double $3;
					}
	|exp POWER exp {$$=pow($1,$3);}
	|MIN   LB exp COMMA exp RB	{if($3<=$5) $$=$3; else $$=$5;}
	|MAX   LB exp COMMA exp RB	{if($3>=$5) $$=$3;	 else $$=$5;}
	|FLOOR LB exp  RB			{$$=floor($3);}
	|ABS LB exp  RB			{$$=fabs($3);};
	
%%

void
eval::Eval_parser::error (const eval::Eval_parser::location_type& l,
                          const std::string& m)
{
 Evaluate.error (l, m);
}
