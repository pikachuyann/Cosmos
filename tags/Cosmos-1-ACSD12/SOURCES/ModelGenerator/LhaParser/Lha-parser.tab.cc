
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   lhalex

/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 43 "Lha-parser.tab.cc"


#include "Lha-parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 52 "Lha-parser.tab.cc"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
#line 39 "Lha-parser.yy"

# include "Lha-Reader.hpp"
#include <set>
#include <vector>

Eval LhaEvaluate;



vector<string> StrFlowVector;
vector<string> FuncFlowVector;

vector<string> FuncUpdateVector;

set <string> PetriTransitions;
set <string> SubSet;



vector < string > CoeffsVector;
vector < vector <string> > CoeffsMatrix;
vector <string> CST;
vector <string> comp;









/* Line 318 of lalr1.cc  */
#line 90 "Lha-parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace lha {

/* Line 380 of lalr1.cc  */
#line 159 "Lha-parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Lha_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Lha_parser::Lha_parser (Lha_Reader& Reader_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      Reader (Reader_yyarg)
  {
  }

  Lha_parser::~Lha_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Lha_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 3: /* "str" */

/* Line 449 of lalr1.cc  */
#line 149 "Lha-parser.yy"
	{ debug_stream () << *(yyvaluep->name); };

/* Line 449 of lalr1.cc  */
#line 236 "Lha-parser.tab.cc"
	break;
      case 4: /* "rval" */

/* Line 449 of lalr1.cc  */
#line 153 "Lha-parser.yy"
	{ debug_stream () << (yyvaluep->RealVal); };

/* Line 449 of lalr1.cc  */
#line 245 "Lha-parser.tab.cc"
	break;
      case 5: /* "ival" */

/* Line 449 of lalr1.cc  */
#line 152 "Lha-parser.yy"
	{ debug_stream () << (yyvaluep->IntVal); };

/* Line 449 of lalr1.cc  */
#line 254 "Lha-parser.tab.cc"
	break;
       default:
	  break;
      }
  }


  void
  Lha_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Lha_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 3: /* "str" */

/* Line 480 of lalr1.cc  */
#line 150 "Lha-parser.yy"
	{ delete (yyvaluep->name); };

/* Line 480 of lalr1.cc  */
#line 293 "Lha-parser.tab.cc"
	break;

	default:
	  break;
      }
  }

  void
  Lha_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Lha_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Lha_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Lha_parser::debug_level_type
  Lha_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Lha_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Lha_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, Reader);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 5:

/* Line 678 of lalr1.cc  */
#line 178 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 179 "Lha-parser.yy"
    {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]<<" ] ";
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						 
						}
					else if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
						{std::ostringstream s; s<<Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						 
						 }
					else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 189 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 190 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 194 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 197 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 198 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 201 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 202 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 203 "Lha-parser.yy"
    {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]<<" ] ";
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						
						}
					else if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
						{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
						 sprintf((yyval.expression), "%s",(s.str()).c_str()); 
						 }

					else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 225 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 226 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 227 "Lha-parser.yy"
    {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]<<" ] ";
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						
						}
				  else{ if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
						{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
						 sprintf((yyval.expression), "%s",(s.str()).c_str()); 
						 }
						 else {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
								{
								  std::ostringstream s; s<<"Var["<<Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]<<"]";
								  sprintf((yyval.expression), "%s",(s.str()).c_str()); 
								}
								else {cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label, a lha variable or a defined constant"<<endl;YYABORT;}
							  }
						}
				  }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 264 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 271 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 280 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
                                        
}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 291 "Lha-parser.yy"
    {
						if(Reader.MyLha.VarIndex.size()!=Reader.MyLha.NbVar){
						std::cout<<"Variable label missing or redeclared, please check your variables list"<<std::endl;
						YYABORT;
						}
                                                

                                                if(true){
                                                vector<string> v1(Reader.MyLha.NbVar,"");
                                                
                                                vector< vector<string> > vv(Reader.MyLha.NbLoc,v1);  
					         
                                                StrFlowVector=v1;
						FuncFlowVector=v1;
						FuncUpdateVector=v1;
						CoeffsVector=v1;
                                                Reader.MyLha.FuncFlow=vv;
					        Reader.MyLha.StrFlow=vv;
						vector<string> v2(Reader.MyLha.NbLoc,"");
						Reader.MyLha.StrLocProperty=v2;
						Reader.MyLha.FuncLocProperty=v2;
						int sz=Reader.MyLha.TransitionIndex.size();
				set <string> Pt;
PetriTransitions=Pt;
						for(map<string, int>::iterator it=Reader.MyLha.TransitionIndex.begin();it!=Reader.MyLha.TransitionIndex.end();it++)
						  PetriTransitions.insert((*it).first);
						vector < set<int> > vi(Reader.MyLha.NbLoc);
						Reader.MyLha.Out_S_Edges=vi;
						Reader.MyLha.Out_A_Edges=vi;
}


}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 325 "Lha-parser.yy"
    {
              
                Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
                
}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 331 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 335 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
						std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
						YYABORT;
						}
                                                   
                                                    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 342 "Lha-parser.yy"
    {
               
                Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
                
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 348 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 358 "Lha-parser.yy"
    {
               
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 366 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else cout<<"Unknown location"<<endl;
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 373 "Lha-parser.yy"
    {
                
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 381 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 395 "Lha-parser.yy"
    {
for(int l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
  if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
  YYABORT;}
}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 406 "Lha-parser.yy"
    { int l;
		      if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(10) - (2)].name))!=Reader.MyLha.LocIndex.end()){
			      l=Reader.MyLha.LocIndex[*(yysemantic_stack_[(10) - (2)].name)];
		      
		      Reader.MyLha.StrLocProperty[l]=(yysemantic_stack_[(10) - (4)].expression);
		      Reader.MyLha.FuncLocProperty[l]=(yysemantic_stack_[(10) - (4)].expression);
		      Reader.MyLha.FuncFlow[l]=FuncFlowVector;
		      Reader.MyLha.StrFlow[l]=StrFlowVector;
		      
		       if(true){
                                vector<string> v(Reader.MyLha.NbVar,"");                                
                                StrFlowVector=v;
				FuncFlowVector=v;}
}
		else {cout<<"Unknown location"<<endl;YYABORT;}
					
 
                                       }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 427 "Lha-parser.yy"
    { int l;
		      if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(6) - (2)].name))!=Reader.MyLha.LocIndex.end()){
			      l=Reader.MyLha.LocIndex[*(yysemantic_stack_[(6) - (2)].name)];
		      
		      Reader.MyLha.StrLocProperty[l]=(yysemantic_stack_[(6) - (4)].expression);
		      Reader.MyLha.FuncLocProperty[l]=(yysemantic_stack_[(6) - (4)].expression);
			  if(true){
                                vector<string> v(Reader.MyLha.NbVar,"");                                
                                StrFlowVector=v;
				FuncFlowVector=v;}
			  Reader.MyLha.FuncFlow[l]=FuncFlowVector;
		      Reader.MyLha.StrFlow[l]=StrFlowVector;
		     
}
		else {cout<<"Unknown location"<<endl;YYABORT;}
					
 
                                       }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 448 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
										FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
								else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl; 
									   YYABORT;}				
}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 454 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 455 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 456 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 457 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 459 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 462 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 463 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 465 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 466 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 471 "Lha-parser.yy"
    {
					    
}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 478 "Lha-parser.yy"
    {

			   if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(14) - (3)].name))!=Reader.MyLha.LocIndex.end())
				  if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(14) - (5)].name))!=Reader.MyLha.LocIndex.end())
				      { int ne=Reader.MyLha.Edge.size();
					Reader.MyLha.AnEdge.Index=ne;
					Reader.MyLha.AnEdge.Source=Reader.MyLha.LocIndex[*(yysemantic_stack_[(14) - (3)].name)];
					Reader.MyLha.AnEdge.Target=Reader.MyLha.LocIndex[*(yysemantic_stack_[(14) - (5)].name)];
					Reader.MyLha.Edge.push_back(Reader.MyLha.AnEdge);
					Reader.MyLha.EdgeActions.push_back(SubSet);
					if(SubSet.size()>0) Reader.MyLha.Out_S_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
					else Reader.MyLha.Out_A_Edges[Reader.MyLha.AnEdge.Source].insert(ne); 
					SubSet.erase(SubSet.begin(),SubSet.end());
Reader.MyLha.ConstraintsCoeffs.push_back(CoeffsMatrix);Reader.MyLha.ConstraintsConstants.push_back(CST);
			Reader.MyLha.ConstraintsRelOp.push_back(comp);
			vector<string> vs;comp=vs;CST=vs;
			vector <vector <string> > ms;CoeffsMatrix=ms;

}
				  else {cout<<*(yysemantic_stack_[(14) - (5)].name)<<" is not a location label"<<endl;YYABORT;}
			   else  {cout<<*(yysemantic_stack_[(14) - (3)].name)<<" is not a location label"<<endl;YYABORT;}
}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 502 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 503 "Lha-parser.yy"
    {set<string> temp=PetriTransitions; 
				      for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
					    temp.erase((*it));
				      SubSet=temp;}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 511 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	      else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 515 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	      else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 520 "Lha-parser.yy"
    {}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 521 "Lha-parser.yy"
    {}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 525 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("==");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 530 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("<=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 535 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back(">=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 545 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 549 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 554 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 559 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 564 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
				  {std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(3) - (1)].name)];
				   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();
				  }
			   else
				  {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
					  {std::ostringstream s; s<<"Marking["<<Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(3) - (1)].name)]<<"]";
					   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();
					  }
				   else
					  {
					   cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not Petri-net Place or a definded constant "<<endl;
					   YYABORT;
					  }
				  }
				}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 585 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 589 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 594 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 599 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 604 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.LhaRealConstant.end())
				  {std::ostringstream s; s<<"-"<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(4) - (2)].name)];
				   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();
				  }
			   else
				  {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.PlaceIndex.end())
					  {std::ostringstream s; s<<"-Marking["<<Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(4) - (2)].name)]<<"]";
					   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();
					  }
				   else
					  {
					   cout<<*(yysemantic_stack_[(4) - (2)].name)<<" is not Petri-net Place or a definded constant "<<endl;
					   YYABORT;
					  }
				  }
				}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}
		}
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 626 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 627 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 632 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
  else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 637 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {std::ostringstream s; s<<Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)];
      FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (1)].name)]]= 
	"Var [" + s.str() + "] * Likelihood"; }
  else{cout<<*(yysemantic_stack_[(5) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 646 "Lha-parser.yy"
    {Reader.MyLha.Algebraic=(yysemantic_stack_[(5) - (3)].expression);}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 647 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
				 sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
				}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 650 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 651 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 652 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 653 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 654 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 655 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 656 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 657 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 658 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 659 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 660 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Last");
									string ss="Last("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 670 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Min");
									string ss="Min("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 680 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Max");
									string ss="Max("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 690 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Integral");
									string ss="Integral("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 701 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 702 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 703 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 706 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 710 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 715 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 720 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 725 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
				  {sprintf((yyval.expression),"%f * Var[%d]", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(3) - (1)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
				  }				  
			   else
				  {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
					  {sprintf((yyval.expression),"Marking[%d] * Var[%d]", Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(3) - (1)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
				  }						  
				   else
					  {
					   cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not Petri-net Place or a definded constant "<<endl;
					   YYABORT;
					  }
				  }
				}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 744 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 748 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 753 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 758 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 763 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.LhaRealConstant.end())
				  {sprintf((yyval.expression),"-%f * Var[%d]", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(4) - (2)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
				  }				  
			   else
				  {
				   if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.PlaceIndex.end())
					  {sprintf((yyval.expression),"-Marking[%d] * Var[%d]", Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(4) - (2)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
				  }						  
				   else
					  {
					   cout<<*(yysemantic_stack_[(4) - (2)].name)<<" is not Petri-net Place or a definded constant "<<endl;
					   YYABORT;
					  }
				  }
				}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}
		}
    break;



/* Line 678 of lalr1.cc  */
#line 1708 "Lha-parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Lha_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Lha_parser::yypact_ninf_ = -296;
  const short int
  Lha_parser::yypact_[] =
  {
       -21,     2,    11,    29,    61,   -25,     0,    -9,    69,    99,
    -296,   102,   104,    82,   109,    89,   114,   144,   156,   141,
     135,   169,   137,   168,  -296,  -296,   212,   215,   174,   182,
     240,   241,  -296,   211,   210,  -296,  -296,   259,   262,   246,
     247,   169,  -296,   290,  -296,  -296,  -296,  -296,  -296,   298,
     299,   252,   255,  -296,  -296,   303,   304,   316,   323,  -296,
     145,  -296,    -4,  -296,    -3,   318,   319,   119,   164,  -296,
       9,  -296,    14,   145,   145,   322,   329,   330,   331,   343,
     350,   351,    60,  -296,   326,   355,   359,   358,   363,    17,
    -296,   356,   321,   319,  -296,  -296,  -296,   119,   119,   376,
     377,   378,   209,  -296,  -296,   164,   164,   385,   386,   387,
     213,   394,   393,   403,   401,   315,   190,   145,   145,   145,
     198,   198,   198,   198,   402,   145,   145,   145,   145,   145,
    -296,  -296,  -296,  -296,   412,   422,  -296,   424,   423,  -296,
     320,   202,   119,   119,   119,  -296,   119,   119,   119,   119,
     119,   455,    10,   164,   164,   164,  -296,   164,   164,   164,
     164,  -296,  -296,  -296,  -296,  -296,   327,   117,   218,   405,
     406,   407,   119,   159,    -1,  -296,    98,   143,   184,  -296,
     400,   400,   190,   190,  -296,    88,  -296,   433,  -296,  -296,
     341,   248,   253,   425,   425,   202,   202,  -296,  -296,   348,
     222,   285,   432,    10,    10,  -296,  -296,   145,   145,   450,
     460,   461,   353,   427,   439,   440,   119,  -296,   198,   198,
    -296,  -296,  -296,    88,    88,  -296,  -296,   501,   250,  -296,
     471,  -296,   119,   119,  -296,   164,   164,   164,   362,   374,
    -296,  -296,  -296,   448,   473,   485,   486,   383,  -296,  -296,
     306,    93,  -296,   119,   119,   119,   119,   119,   478,   495,
      88,    88,   490,   388,   395,   463,   476,   484,  -296,  -296,
     499,  -296,  -296,  -296,   480,  -296,   469,   469,   469,   469,
     469,   505,  -296,  -296,   491,   517,  -296,  -296,  -296,  -296,
    -296,  -296,   506,   519,    34,  -296,    27,  -296,   119,   505,
     522,  -296,   520,   531,   527,  -296,   469,  -296,   530,   487,
    -296,    15,   195,  -296,  -296,   534,  -296,   512,   513,   514,
     119,  -296,   291,   535,   523,   276,  -296,  -296,   541,   542,
     543,   409,   521,   524,   525,   119,    -8,   195,   119,   119,
     119,   205,   205,  -296,  -296,  -296,   526,   544,   546,   547,
     416,  -296,   551,   545,  -296,   469,   469,   469,  -296,  -296,
     553,  -296,  -296,  -296,   532,   548,    16,  -296,   552,  -296,
     554,     3,   551,  -296,  -296,  -296,  -296,  -296,  -296,   128,
     128,   555,   556,   557,   533,   494,  -296,   421,   237,   128,
     128,   128,   558,   128,   128,   128,   128,   128,  -296,   430,
     258,   281,  -296,   537,   537,   237,   237,  -296,  -296,   128,
     128,   442,   451,  -296,  -296
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,    44,    43,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    59,    60,     0,     0,     0,
       0,     0,    46,     0,     4,    51,    52,    50,    49,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     3,
       0,    62,     0,    65,     0,     0,     0,     0,     0,    54,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
      70,     0,     0,    90,    19,    17,    18,     0,     0,     0,
       0,     0,     0,     6,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    61,    66,    64,     0,     0,    71,     0,     0,    91,
       0,    21,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,    47,     0,     0,     0,
       0,    55,    53,    58,    56,   131,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   141,     0,     0,     0,   125,
     136,   135,   133,   134,   132,     0,    69,     0,    89,    20,
       0,     0,     0,    22,    25,    23,    24,    26,     7,     0,
       0,     0,    11,     9,    10,    12,   130,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   138,     0,     0,
     139,   137,   140,     0,     0,    77,    78,     0,     0,    79,
       0,    27,     0,     0,    13,     0,     0,     0,     0,     0,
     148,   147,   146,     0,     0,     0,     0,     0,   143,   142,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   153,   152,   151,     0,    82,    84,    86,    85,    87,
      88,     0,    73,    80,    81,     0,    28,    29,    14,    15,
      16,   145,     0,     0,     0,    74,     0,   150,     0,     0,
       0,    93,    94,     0,     0,    96,    76,    75,     0,     0,
      98,     0,     0,    72,    95,     0,    97,   109,     0,     0,
       0,   102,     0,     0,   100,     0,   106,    99,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   112,   111,     0,     0,     0,     0,
       0,   120,     0,     0,   101,   103,   105,   104,   108,   107,
       0,   118,   117,   116,     0,     0,     0,   121,     0,   110,
       0,     0,     0,   119,    92,   115,    32,    30,    31,     0,
       0,     0,     0,     0,     0,   123,   122,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,   124,    35,    38,    36,    37,    39,    40,     0,
       0,     0,     0,    41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -296,  -296,  -296,   -95,   -67,  -295,  -296,   549,  -296,   561,
     564,   559,   540,  -296,   550,  -296,  -296,   560,  -296,   562,
    -296,  -296,   539,  -296,   482,  -296,   275,  -210,  -296,   563,
     488,  -296,  -296,   268,  -296,   242,  -296,  -296,  -150,  -296,
    -296,   208,   565,   -72,  -296,   -50,     4
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   110,   227,   385,     5,    19,    20,     6,
       7,    21,    22,    70,    23,    72,    13,    14,    62,    15,
      64,    32,    33,    89,    90,   294,   295,   228,   229,    34,
      92,    93,   304,   305,   311,   323,   324,   325,   326,   353,
     366,   367,    44,    82,    83,   174,   175
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       102,   115,   116,   351,    84,    86,   376,   377,   378,   217,
     151,   152,   379,   251,   252,    16,     8,   111,    17,    18,
       1,     2,   113,   315,   372,     9,    88,   218,   219,    10,
     140,   141,   380,     2,   381,   382,   383,   157,   301,   302,
     160,     1,   299,   352,   300,   166,   167,   168,    85,    87,
     283,   284,   384,   180,   181,   182,   183,   184,   199,   200,
     201,   112,   202,   203,   204,   205,   114,   316,   373,   135,
     124,   176,   177,   178,    26,   190,   191,   192,   303,   193,
     194,   195,   196,   197,   387,   388,   125,   126,   127,   128,
     129,    94,    95,    96,   399,   400,   401,   223,   403,   404,
     405,   406,   407,   275,    27,   212,    11,    12,   220,   224,
     225,   226,   260,   261,   411,   412,    28,    98,    29,    99,
     100,   101,    94,    95,    96,   207,   218,   219,    97,    30,
      31,   376,   377,   378,    11,   238,   239,   379,    37,    38,
     265,   266,   267,   125,   126,   127,   128,   129,    98,   247,
      99,   100,   101,   221,    73,    12,   250,   380,    39,   381,
     382,   383,   213,   214,   215,   263,   264,   103,   216,   104,
      40,   218,   219,   105,    74,    16,    75,    76,    77,    78,
      79,    18,    80,    81,    17,    18,   276,   277,   278,   279,
     280,   358,   359,   106,   222,   107,   108,   109,   317,   318,
     319,   169,   170,   171,   320,    43,   321,   172,   317,   318,
     319,    17,   218,   219,   320,   145,   125,   126,    47,   156,
     129,    48,   248,   249,   322,    49,   208,   173,   146,   147,
     236,   306,   150,    50,   322,   146,   147,   148,   149,   150,
     157,   158,   159,   160,   125,   126,   127,   128,   129,   157,
     158,   159,   160,   331,    51,    52,   232,    30,   258,    31,
     259,   233,    55,   393,   394,    56,   409,   397,   350,   260,
     261,   355,   356,   357,   146,   147,   148,   149,   150,   146,
     147,   148,   149,   150,   393,   394,   395,   396,   397,   410,
     338,   339,   340,   237,   332,   333,   334,    57,    58,    60,
     335,    61,    63,    65,   341,   342,    66,   393,   394,   395,
     396,   397,   157,   158,   159,   160,   189,    67,    68,    69,
     253,   254,   255,   256,   257,   165,    71,    88,    91,   130,
     189,   117,   146,   147,   148,   149,   150,   206,   118,   119,
     120,   125,   126,   127,   128,   129,   146,   147,   148,   149,
     150,   231,   121,   125,   126,   127,   128,   129,   234,   122,
     123,   131,   132,   243,   133,   137,   134,   146,   147,   148,
     149,   150,   268,   138,   235,   157,   158,   159,   160,   146,
     147,   148,   149,   150,   269,   142,   143,   144,   125,   126,
     127,   128,   129,   274,   153,   154,   155,   161,   286,   162,
     125,   126,   127,   128,   129,   287,   163,   164,   179,   146,
     147,   148,   149,   150,   146,   147,   148,   149,   150,   346,
     185,   146,   147,   148,   149,   150,   364,   187,   186,   188,
     129,   398,   209,   210,   211,   146,   147,   148,   149,   150,
     408,   230,   146,   147,   148,   149,   150,   393,   394,   395,
     396,   397,   413,   240,   244,   150,   393,   394,   395,   396,
     397,   414,   160,   241,   242,   198,   245,   246,   393,   394,
     395,   396,   397,   288,   262,   270,   271,   393,   394,   395,
     396,   397,   157,   158,   159,   160,   289,   281,   272,   273,
     157,   158,   159,   160,   290,   146,   147,   148,   149,   150,
     285,   282,   291,   157,   158,   159,   160,   292,   293,   297,
     260,   157,   158,   159,   160,   253,   254,   255,   256,   257,
     393,   394,   395,   396,   397,   296,   298,   146,   147,   148,
     149,   150,   308,   309,   310,   312,   313,   327,   303,   328,
     329,   330,   337,   336,   343,   344,   345,   361,   347,   362,
     363,   348,   349,   360,   365,   368,   369,   375,   374,   370,
     392,   402,   371,    46,   389,   390,   391,   397,    25,    42,
      24,   136,    45,    54,   307,    36,    35,   314,    41,   354,
     386,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        67,    73,    74,    11,     8,     8,     3,     4,     5,    10,
     105,   106,     9,   223,   224,    40,    14,     8,    43,    44,
      41,    42,     8,     8,     8,    14,     9,    28,    29,     0,
      97,    98,    29,    42,    31,    32,    33,    27,    11,    12,
      30,    41,     8,    51,    10,   117,   118,   119,    52,    52,
     260,   261,    49,   125,   126,   127,   128,   129,   153,   154,
     155,    52,   157,   158,   159,   160,    52,    52,    52,    52,
      10,   121,   122,   123,     5,   142,   143,   144,    51,   146,
     147,   148,   149,   150,   379,   380,    26,    27,    28,    29,
      30,     3,     4,     5,   389,   390,   391,     9,   393,   394,
     395,   396,   397,    10,     5,   172,    45,    46,    10,    21,
      22,    23,    19,    20,   409,   410,    14,    29,    14,    31,
      32,    33,     3,     4,     5,     8,    28,    29,     9,    47,
      48,     3,     4,     5,    45,   207,   208,     9,    24,    25,
     235,   236,   237,    26,    27,    28,    29,    30,    29,   216,
      31,    32,    33,    10,     9,    46,   223,    29,    14,    31,
      32,    33,     3,     4,     5,   232,   233,     3,     9,     5,
      14,    28,    29,     9,    29,    40,    31,    32,    33,    34,
      35,    44,    37,    38,    43,    44,   253,   254,   255,   256,
     257,   341,   342,    29,    10,    31,    32,    33,     3,     4,
       5,     3,     4,     5,     9,    36,    11,     9,     3,     4,
       5,    43,    28,    29,     9,     6,    26,    27,     6,     6,
      30,     6,   218,   219,    29,    51,     8,    29,    26,    27,
       8,   298,    30,    51,    29,    26,    27,    28,    29,    30,
      27,    28,    29,    30,    26,    27,    28,    29,    30,    27,
      28,    29,    30,   320,    14,    14,     8,    47,     8,    48,
      10,     8,     3,    26,    27,     3,     8,    30,   335,    19,
      20,   338,   339,   340,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,     8,
      14,    15,    16,     8,     3,     4,     5,    51,    51,     9,
       9,     3,     3,    51,    28,    29,    51,    26,    27,    28,
      29,    30,    27,    28,    29,    30,    10,    14,    14,     3,
      14,    15,    16,    17,    18,    10,     3,     9,     9,     3,
      10,     9,    26,    27,    28,    29,    30,    10,     9,     9,
       9,    26,    27,    28,    29,    30,    26,    27,    28,    29,
      30,    10,     9,    26,    27,    28,    29,    30,    10,     9,
       9,     6,     3,    10,     6,     9,     3,    26,    27,    28,
      29,    30,    10,    52,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    10,     9,     9,     9,    26,    27,
      28,    29,    30,    10,     9,     9,     9,     3,    10,     6,
      26,    27,    28,    29,    30,    10,     3,     6,     6,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,    10,
       8,    26,    27,    28,    29,    30,    10,     3,     6,     6,
      30,    10,    27,    27,    27,    26,    27,    28,    29,    30,
      10,     8,    26,    27,    28,    29,    30,    26,    27,    28,
      29,    30,    10,     3,    27,    30,    26,    27,    28,    29,
      30,    10,    30,     3,     3,    10,    27,    27,    26,    27,
      28,    29,    30,    10,     3,    27,     3,    26,    27,    28,
      29,    30,    27,    28,    29,    30,    10,     9,     3,     3,
      27,    28,    29,    30,    10,    26,    27,    28,    29,    30,
      10,     6,     3,    27,    28,    29,    30,    27,     3,     3,
      19,    27,    28,    29,    30,    14,    15,    16,    17,    18,
      26,    27,    28,    29,    30,     8,     7,    26,    27,    28,
      29,    30,    10,    13,     3,     8,     6,     3,    51,    27,
      27,    27,    19,     8,     3,     3,     3,     3,    27,     3,
       3,    27,    27,    27,     3,    10,     3,     3,     6,    27,
      27,     3,    14,    23,     9,     9,     9,    30,     7,    20,
       6,    89,    22,    34,   299,    15,    14,   309,    19,   337,
     372,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    41,    42,    54,    55,    59,    62,    63,    14,    14,
       0,    45,    46,    69,    70,    72,    40,    43,    44,    60,
      61,    64,    65,    67,    63,    62,     5,     5,    14,    14,
      47,    48,    74,    75,    82,    72,    70,    24,    25,    14,
      14,    64,    60,    36,    95,    67,    65,     6,     6,    51,
      51,    14,    14,    82,    75,     3,     3,    51,    51,    95,
       9,     3,    71,     3,    73,    51,    51,    14,    14,     3,
      66,     3,    68,     9,    29,    31,    32,    33,    34,    35,
      37,    38,    96,    97,     8,    52,     8,    52,     9,    76,
      77,     9,    83,    84,     3,     4,     5,     9,    29,    31,
      32,    33,    57,     3,     5,     9,    29,    31,    32,    33,
      56,     8,    52,     8,    52,    96,    96,     9,     9,     9,
       9,     9,     9,     9,    10,    26,    27,    28,    29,    30,
       3,     6,     3,     6,     3,    52,    77,     9,    52,    83,
      57,    57,     9,     9,     9,     6,    26,    27,    28,    29,
      30,    56,    56,     9,     9,     9,     6,    27,    28,    29,
      30,     3,     6,     3,     6,    10,    96,    96,    96,     3,
       4,     5,     9,    29,    98,    99,    98,    98,    98,     6,
      96,    96,    96,    96,    96,     8,     6,     3,     6,    10,
      57,    57,    57,    57,    57,    57,    57,    57,    10,    56,
      56,    56,    56,    56,    56,    56,    10,     8,     8,    27,
      27,    27,    57,     3,     4,     5,     9,    10,    28,    29,
      10,    10,    10,     9,    21,    22,    23,    57,    80,    81,
       8,    10,     8,     8,    10,    26,     8,     8,    96,    96,
       3,     3,     3,    10,    27,    27,    27,    57,    99,    99,
      57,    80,    80,    14,    15,    16,    17,    18,     8,    10,
      19,    20,     3,    57,    57,    56,    56,    56,    10,    10,
      27,     3,     3,     3,    10,    10,    57,    57,    57,    57,
      57,     9,     6,    80,    80,    10,    10,    10,    10,    10,
      10,     3,    27,     3,    78,    79,     8,     3,     7,     8,
      10,    11,    12,    51,    85,    86,    57,    79,    10,    13,
       3,    87,     8,     6,    86,     8,    52,     3,     4,     5,
       9,    11,    29,    88,    89,    90,    91,     3,    27,    27,
      27,    57,     3,     4,     5,     9,     8,    19,    14,    15,
      16,    28,    29,     3,     3,     3,    10,    27,    27,    27,
      57,    11,    51,    92,    88,    57,    57,    57,    91,    91,
      27,     3,     3,     3,    10,     3,    93,    94,    10,     3,
      27,    14,     8,    52,     6,     3,     3,     4,     5,     9,
      29,    31,    32,    33,    49,    58,    94,    58,    58,     9,
       9,     9,    27,    26,    27,    28,    29,    30,    10,    58,
      58,    58,     3,    58,    58,    58,    58,    58,    10,     8,
       8,    58,    58,    10,    10
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Lha_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    64,    64,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    79,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    82,
      83,    83,    84,    85,    85,    85,    85,    86,    87,    87,
      88,    88,    88,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Lha_parser::yyr2_[] =
  {
         0,     2,     3,     4,     3,     1,     1,     3,     2,     3,
       3,     3,     3,     4,     6,     6,     6,     1,     1,     1,
       3,     2,     3,     3,     3,     3,     3,     4,     6,     6,
       1,     1,     1,     3,     2,     3,     3,     3,     3,     3,
       4,     6,     6,     2,     2,     1,     2,     6,     6,     4,
       4,     2,     2,     6,     1,     3,     6,     1,     3,     2,
       2,     6,     1,     3,     6,     1,     3,     2,     2,     6,
       1,     2,    10,     6,     1,     3,     3,     1,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     6,
       1,     2,    14,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       5,     3,     3,     3,     2,     6,     4,     4,     4,     3,
       1,     1,     3,     3,     5,     5,     1,     6,     6,     2,
       4,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     1,     3,     3,     1,     5,     3,     3,     3,     2,
       6,     4,     4,     4
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Lha_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "str", "rval", "ival",
  "SEMICOLON", "COLON", "COMMA", "LB", "RB", "SHARP", "ALL", "BackSlash",
  "EQ", "GEQ", "LEQ", "LL", "GG", "AND", "OR", "NOT", "TRUE", "FALSE",
  "DOUBLE", "INT", "DIV", "MUL", "PLUS", "MINUS", "POWER", "FLOOR", "MIN",
  "MAX", "LhaMIN", "LhaMAX", "AVG", "LAST", "INTEGRAL", "LhaName", "Const",
  "NbLoc", "NbVar", "VList", "LList", "Iloc", "Floc", "locations", "edges",
  "LIKELIHOOD", "NEG", "'{'", "'}'", "$accept", "LHA", "declarations",
  "IntMarkingFormula", "RealMarkingFormula", "RealVarMarkingFormula",
  "Sizes", "Constants", "Constant", "NbVariables", "NbLocations", "Lists",
  "VariablesList", "VLabels", "LocationsList", "LLabels", "InitFinal",
  "init", "iLLabels", "final", "fLLabels", "definitions", "LocationsDef",
  "LOCATIONS", "LOCATION", "FLOWS", "FLOW", "LogExpr", "CompExpr",
  "EdgesDef", "EDGES", "EDGE", "ACTIONS", "SetOfActions", "Actions",
  "CONSTRAINTS", "CONSTRAINT", "LinearExp", "term", "UPDATES", "Updates",
  "Update", "HaslExp", "AlgExpr", "LhaFunc", "LinForm", "VarTerm", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Lha_parser::rhs_number_type
  Lha_parser::yyrhs_[] =
  {
        54,     0,    -1,    55,    69,    74,    -1,    59,    60,    64,
      95,    -1,    59,    64,    95,    -1,     5,    -1,     3,    -1,
       9,    56,    10,    -1,    29,    56,    -1,    56,    28,    56,
      -1,    56,    29,    56,    -1,    56,    27,    56,    -1,    56,
      30,    56,    -1,    31,     9,    56,    10,    -1,    31,     9,
      56,    26,    56,    10,    -1,    32,     9,    56,     8,    56,
      10,    -1,    33,     9,    56,     8,    56,    10,    -1,     4,
      -1,     5,    -1,     3,    -1,     9,    57,    10,    -1,    29,
      57,    -1,    57,    26,    57,    -1,    57,    28,    57,    -1,
      57,    29,    57,    -1,    57,    27,    57,    -1,    57,    30,
      57,    -1,    31,     9,    57,    10,    -1,    32,     9,    57,
       8,    57,    10,    -1,    33,     9,    57,     8,    57,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     9,    58,    10,
      -1,    29,    58,    -1,    58,    26,    58,    -1,    58,    28,
      58,    -1,    58,    29,    58,    -1,    58,    27,    58,    -1,
      58,    30,    58,    -1,    31,     9,    58,    10,    -1,    32,
       9,    58,     8,    58,    10,    -1,    33,     9,    58,     8,
      58,    10,    -1,    63,    62,    -1,    62,    63,    -1,    61,
      -1,    61,    60,    -1,    40,    25,     3,    14,    56,     6,
      -1,    40,    24,     3,    14,    57,     6,    -1,    42,    14,
       5,     6,    -1,    41,    14,     5,     6,    -1,    65,    67,
      -1,    67,    65,    -1,    43,    14,    51,    66,    52,     6,
      -1,     3,    -1,    66,     8,     3,    -1,    44,    14,    51,
      68,    52,     6,    -1,     3,    -1,    68,     8,     3,    -1,
      70,    72,    -1,    72,    70,    -1,    45,    14,    51,    71,
      52,     6,    -1,     3,    -1,    71,     8,     3,    -1,    46,
      14,    51,    73,    52,     6,    -1,     3,    -1,    73,     8,
       3,    -1,    75,    82,    -1,    82,    75,    -1,    47,    14,
      51,    76,    52,     6,    -1,    77,    -1,    76,    77,    -1,
       9,     3,     8,    80,     8,     9,    78,    10,    10,     6,
      -1,     9,     3,     8,    80,    10,     6,    -1,    79,    -1,
      78,     8,    79,    -1,     3,     7,    57,    -1,    22,    -1,
      23,    -1,    81,    -1,    80,    19,    80,    -1,    80,    20,
      80,    -1,     9,    80,    10,    -1,    21,    80,    -1,    57,
      14,    57,    -1,    57,    16,    57,    -1,    57,    15,    57,
      -1,    57,    17,    57,    -1,    57,    18,    57,    -1,    48,
      14,    51,    83,    52,     6,    -1,    84,    -1,    84,    83,
      -1,     9,     9,     3,     8,     3,    10,     8,    85,     8,
      88,     8,    92,    10,     6,    -1,    11,    -1,    12,    -1,
      12,    13,    86,    -1,    86,    -1,    51,    87,    52,    -1,
       3,    -1,    87,     8,     3,    -1,    89,    -1,    89,    19,
      88,    -1,    11,    -1,    90,    14,    57,    -1,    90,    16,
      57,    -1,    90,    15,    57,    -1,    91,    -1,    90,    29,
      91,    -1,    90,    28,    91,    -1,     3,    -1,     9,    57,
      10,    27,     3,    -1,     5,    27,     3,    -1,     4,    27,
       3,    -1,     3,    27,     3,    -1,    29,     3,    -1,    29,
       9,    57,    10,    27,     3,    -1,    29,     5,    27,     3,
      -1,    29,     4,    27,     3,    -1,    29,     3,    27,     3,
      -1,    51,    93,    52,    -1,    11,    -1,    94,    -1,    93,
       8,    94,    -1,     3,    14,    58,    -1,     3,    14,    49,
      27,     3,    -1,    36,     9,    96,    10,     6,    -1,    97,
      -1,    32,     9,    96,     8,    96,    10,    -1,    33,     9,
      96,     8,    96,    10,    -1,    29,    96,    -1,    31,     9,
      96,    10,    -1,     9,    96,    10,    -1,    96,    30,    96,
      -1,    96,    28,    96,    -1,    96,    29,    96,    -1,    96,
      27,    96,    -1,    96,    26,    96,    -1,    37,     9,    98,
      10,    -1,    34,     9,    98,    10,    -1,    35,     9,    98,
      10,    -1,    38,     9,    98,    10,    -1,    99,    -1,    98,
      29,    99,    -1,    98,    28,    99,    -1,     3,    -1,     9,
      57,    10,    27,     3,    -1,     5,    27,     3,    -1,     4,
      27,     3,    -1,     3,    27,     3,    -1,    29,     3,    -1,
      29,     9,    57,    10,    27,     3,    -1,    29,     5,    27,
       3,    -1,    29,     4,    27,     3,    -1,    29,     3,    27,
       3,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Lha_parser::yyprhs_[] =
  {
         0,     0,     3,     7,    12,    16,    18,    20,    24,    27,
      31,    35,    39,    43,    48,    55,    62,    69,    71,    73,
      75,    79,    82,    86,    90,    94,    98,   102,   107,   114,
     121,   123,   125,   127,   131,   134,   138,   142,   146,   150,
     154,   159,   166,   173,   176,   179,   181,   184,   191,   198,
     203,   208,   211,   214,   221,   223,   227,   234,   236,   240,
     243,   246,   253,   255,   259,   266,   268,   272,   275,   278,
     285,   287,   290,   301,   308,   310,   314,   318,   320,   322,
     324,   328,   332,   336,   339,   343,   347,   351,   355,   359,
     366,   368,   371,   386,   388,   390,   394,   396,   400,   402,
     406,   408,   412,   414,   418,   422,   426,   428,   432,   436,
     438,   444,   448,   452,   456,   459,   466,   471,   476,   481,
     485,   487,   489,   493,   497,   503,   509,   511,   518,   525,
     528,   533,   537,   541,   545,   549,   553,   557,   562,   567,
     572,   577,   579,   583,   587,   589,   595,   599,   603,   607,
     610,   617,   622,   627
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   168,   168,   171,   172,   178,   179,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   201,   202,   203,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     225,   226,   227,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   257,   258,   260,   261,   263,   270,   280,
     284,   288,   289,   291,   325,   331,   335,   342,   348,   353,
     354,   356,   358,   366,   371,   373,   381,   390,   391,   395,
     402,   403,   405,   424,   446,   447,   448,   454,   455,   456,
     457,   458,   459,   460,   462,   463,   464,   465,   466,   471,
     475,   476,   478,   501,   502,   503,   507,   509,   511,   515,
     520,   521,   522,   524,   529,   534,   540,   541,   542,   544,
     548,   553,   558,   563,   584,   588,   593,   598,   603,   626,
     627,   629,   630,   632,   637,   646,   647,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   670,   680,
     690,   701,   702,   703,   705,   709,   714,   719,   724,   743,
     747,   752,   757,   762
  };

  // Print the state stack on the debug stream.
  void
  Lha_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Lha_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Lha_parser::token_number_type
  Lha_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 606;
  const int Lha_parser::yynnts_ = 47;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 53;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 305;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // lha

/* Line 1054 of lalr1.cc  */
#line 2512 "Lha-parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 786 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}

