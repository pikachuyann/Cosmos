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


%{                                            /* -*- C++ -*- */
# include <cstdlib>
# include <errno.h>
# include <limits.h>
# include <string>
# include "Eval.hpp"
# include "Eval-parser.tab.hh"


# undef yywrap
# define yywrap() 1

# define YY_DECL EVAL_DECL

/* By default evallex returns int, we use token_type.
   Unfortunately evalterminate by default returns 0, which is
   not of token_type.  */
#define yyterminate() return token::END
%}

%option noyywrap nounput batch debug

STR [a-zA-Z][a-zA-Z_0-9]*
INT [0-9]+|[0-9]*
REAL ([0-9]+|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? 
blank [ \t]

%{
# define EVAL_USER_ACTION  evallloc->columns (evalleng);
%}
%%
%{
  evallloc->step ();
%}
{blank}+   evallloc->step ();
[\n]+      evallloc->lines (evalleng); evallloc->step ();

%{
  typedef eval::Eval_parser::token token;
%}
           /* Convert ints to the actual type of tokens.  */
[{}]     return eval::Eval_parser::token_type (evaltext[0]);



"(" {evallval->name = new std::string (evaltext); return token::LB;
            Evaluate.error (*evallloc, "( expected");}
")" {evallval->name = new std::string (evaltext); return token::RB;
            Evaluate.error (*evallloc, ") expected");}

"," {evallval->name = new std::string (evaltext); return token::COMMA;
		   Evaluate.error (*evallloc, ", expected");}

"/" {evallval->name = new std::string (evaltext); return token::DIV;
            Evaluate.error (*evallloc, "/ expected");}
"*" {evallval->name = new std::string (evaltext); return token::MUL;
            Evaluate.error (*evallloc, "* expected");}
"+" {evallval->name = new std::string (evaltext); return token::PLUS;
            Evaluate.error (*evallloc, "+ expected");}
"-" {evallval->name = new std::string (evaltext); return token::MINUS;
            Evaluate.error (*evallloc, "- expected");}
"^" {evallval->name = new std::string (evaltext); return token::POWER;
            Evaluate.error (*evallloc, "^ expected");}

           
"min" {evallval->name = new std::string (evaltext); return token::MIN;
            Evaluate.error (*evallloc, "min expected");}

"max" {evallval->name = new std::string (evaltext); return token::MAX;
            Evaluate.error (*evallloc, "max expected");}

"floor" {evallval->name = new std::string (evaltext); return token::FLOOR;
            Evaluate.error (*evallloc, "floor expected");}
"abs" {evallval->name = new std::string (evaltext); return token::ABS;
            Evaluate.error (*evallloc, "abs expected");}

"double" {evallval->name = new std::string (evaltext); return token::DOUBLE;
            Evaluate.error (*evallloc, "double expected");}


{INT}      {
  errno = 0; 
  int x=atoi(evaltext);
  evallval->IntVal = x;
  return token::ival;
}
 
{REAL}      {
  errno = 0; 
  double x=atof(evaltext);
  evallval->RealVal = x;
  return token::rval;
}

{STR}       {evallval->name = new std::string (evaltext); return token::str;
            Evaluate.error (*evallloc, "invalid character");}




%%




void
Eval::scan_end ()
{  
  evallex_destroy();
}


void Eval::scan_expression (const string& f){
  const char* ch=f.c_str();
evalset_debug(trace_scanning);


 eval_scan_string(ch);
 
}

