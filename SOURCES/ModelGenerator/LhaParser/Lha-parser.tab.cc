
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
#line 147 "Lha-parser.yy"
	{ debug_stream () << *(yyvaluep->name); };

/* Line 449 of lalr1.cc  */
#line 236 "Lha-parser.tab.cc"
	break;
      case 4: /* "rval" */

/* Line 449 of lalr1.cc  */
#line 151 "Lha-parser.yy"
	{ debug_stream () << (yyvaluep->RealVal); };

/* Line 449 of lalr1.cc  */
#line 245 "Lha-parser.tab.cc"
	break;
      case 5: /* "ival" */

/* Line 449 of lalr1.cc  */
#line 150 "Lha-parser.yy"
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
#line 148 "Lha-parser.yy"
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
#line 176 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 177 "Lha-parser.yy"
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
#line 187 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 188 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 189 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 190 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 194 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 200 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 201 "Lha-parser.yy"
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
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 225 "Lha-parser.yy"
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
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 262 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 269 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 278 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
                                        
}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 289 "Lha-parser.yy"
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
#line 323 "Lha-parser.yy"
    {
              
                Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
                
}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 329 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 333 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
						std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
						YYABORT;
						}
                                                   
                                                    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 340 "Lha-parser.yy"
    {
               
                Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
                
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 346 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 356 "Lha-parser.yy"
    {
               
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 364 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else cout<<"Unknown location"<<endl;
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 371 "Lha-parser.yy"
    {
                
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 379 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 393 "Lha-parser.yy"
    {
for(int l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
  if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
  YYABORT;}
}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 404 "Lha-parser.yy"
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
#line 425 "Lha-parser.yy"
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
#line 446 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
										FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
								else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl; 
									   YYABORT;}				
}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 452 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 453 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 454 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 455 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 456 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 457 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 461 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 462 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 463 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 469 "Lha-parser.yy"
    {
					    
}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 476 "Lha-parser.yy"
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
#line 500 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 501 "Lha-parser.yy"
    {set<string> temp=PetriTransitions; 
				      for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
					    temp.erase((*it));
				      SubSet=temp;}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 509 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	      else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 513 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	      else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 518 "Lha-parser.yy"
    {}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 519 "Lha-parser.yy"
    {}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 523 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("==");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 528 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("<=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 533 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back(">=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 543 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 547 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 552 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 557 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 562 "Lha-parser.yy"
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
#line 583 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 587 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 592 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 597 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 602 "Lha-parser.yy"
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
#line 624 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 625 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 630 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
		    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
				   else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 636 "Lha-parser.yy"
    {Reader.MyLha.Algebraic=(yysemantic_stack_[(5) - (3)].expression);}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 637 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
				 sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
				}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 640 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 641 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 642 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 643 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 644 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 645 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 646 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 647 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 648 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 649 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 650 "Lha-parser.yy"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 660 "Lha-parser.yy"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 670 "Lha-parser.yy"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 680 "Lha-parser.yy"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 691 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 692 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 693 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 696 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 700 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 705 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 710 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 715 "Lha-parser.yy"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 734 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 738 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 743 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 748 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 753 "Lha-parser.yy"
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
#line 1694 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -213;
  const short int
  Lha_parser::yypact_[] =
  {
        68,    71,    80,    14,   116,   -27,   -12,    62,   106,   126,
    -213,   131,   139,    74,   109,   112,   168,   171,   187,   172,
     129,   181,   164,   197,  -213,  -213,   218,   248,   205,   210,
     247,   253,  -213,   221,   233,  -213,  -213,   280,   289,   243,
     244,   181,  -213,   297,  -213,  -213,  -213,  -213,  -213,   313,
     315,   270,   277,  -213,  -213,   325,   326,   338,   345,  -213,
       6,  -213,    -3,  -213,    -2,   351,   352,    84,    94,  -213,
      -1,  -213,     0,     6,     6,   353,   365,   372,   373,   374,
     377,   378,   236,  -213,   348,   382,   381,   389,   404,    15,
    -213,   399,   358,   352,  -213,  -213,  -213,    84,    84,   407,
     408,   411,   144,  -213,  -213,    94,    94,   412,   419,   420,
     169,   415,   424,   439,   435,   269,    -7,     6,     6,     6,
     125,   125,   125,   125,   444,     6,     6,     6,     6,     6,
    -213,  -213,  -213,  -213,   446,   449,  -213,   453,   457,  -213,
     274,   255,    84,    84,    84,  -213,    84,    84,    84,    84,
      84,   409,    41,    94,    94,    94,  -213,    94,    94,    94,
      94,  -213,  -213,  -213,  -213,  -213,   281,   176,   183,   422,
     425,   437,    84,   155,   123,  -213,   433,   441,   443,  -213,
     451,   451,    -7,    -7,  -213,    69,  -213,   474,  -213,  -213,
     295,   192,   199,   454,   454,   255,   255,  -213,  -213,   302,
     222,   229,   460,    41,    41,  -213,  -213,     6,     6,   480,
     488,   501,   307,   478,   479,   481,    84,  -213,   125,   125,
    -213,  -213,  -213,    69,    69,  -213,  -213,   459,    76,  -213,
     504,  -213,    84,    84,  -213,    94,    94,    94,   316,   328,
    -213,  -213,  -213,   482,   507,   508,   509,   337,  -213,  -213,
     260,     2,  -213,    84,    84,    84,    84,    84,   505,   510,
      69,    69,   503,   342,   349,   417,   430,   438,  -213,  -213,
     512,  -213,  -213,  -213,   490,  -213,   468,   468,   468,   468,
     468,   515,  -213,  -213,   500,   513,  -213,  -213,  -213,  -213,
    -213,  -213,   517,   516,    26,  -213,    -8,  -213,    84,   515,
     514,  -213,   518,   519,   520,  -213,   468,  -213,   521,   475,
    -213,     1,   103,  -213,  -213,   523,  -213,   502,   506,   511,
      84,  -213,   310,   522,   524,   464,  -213,  -213,   529,   531,
     532,   363,   525,   526,   527,    84,    17,   103,    84,    84,
      84,   134,   134,  -213,  -213,  -213,   528,   533,   534,   536,
     370,  -213,   537,   535,  -213,   468,   468,   468,  -213,  -213,
     538,  -213,  -213,  -213,   530,   542,    10,  -213,   540,  -213,
     539,   115,   537,  -213,  -213,  -213,  -213,  -213,  -213,   115,
     115,   541,   549,   550,   473,  -213,   375,   323,   115,   115,
     115,   115,   115,   115,   115,   115,  -213,   384,   206,   215,
     543,   543,   323,   323,  -213,  -213,   115,   115,   396,   405,
    -213,  -213
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
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
      70,     0,     0,    90,    19,    17,    18,     0,     0,     0,
       0,     0,     0,     6,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    61,    66,    64,     0,     0,    71,     0,     0,    91,
       0,    21,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,    47,     0,     0,     0,
       0,    55,    53,    58,    56,   130,     0,     0,     0,   143,
       0,     0,     0,     0,     0,   140,     0,     0,     0,   124,
     135,   134,   132,   133,   131,     0,    69,     0,    89,    20,
       0,     0,     0,    22,    25,    23,    24,    26,     7,     0,
       0,     0,    11,     9,    10,    12,   129,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,   137,     0,     0,
     138,   136,   139,     0,     0,    77,    78,     0,     0,    79,
       0,    27,     0,     0,    13,     0,     0,     0,     0,     0,
     147,   146,   145,     0,     0,     0,     0,     0,   142,   141,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
       0,   152,   151,   150,     0,    82,    84,    86,    85,    87,
      88,     0,    73,    80,    81,     0,    28,    29,    14,    15,
      16,   144,     0,     0,     0,    74,     0,   149,     0,     0,
       0,    93,    94,     0,     0,    96,    76,    75,     0,     0,
      98,     0,     0,    72,    95,     0,    97,   109,     0,     0,
       0,   102,     0,     0,   100,     0,   106,    99,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   112,   111,     0,     0,     0,     0,
       0,   120,     0,     0,   101,   103,   105,   104,   108,   107,
       0,   118,   117,   116,     0,     0,     0,   121,     0,   110,
       0,     0,     0,   119,    92,   115,    32,    30,    31,     0,
       0,     0,     0,     0,   123,   122,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
      35,    38,    36,    37,    39,    40,     0,     0,     0,     0,
      41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -213,  -213,  -213,   -95,   -67,  -212,  -213,   544,  -213,   553,
     545,   546,   547,  -213,   552,  -213,  -213,   548,  -213,   554,
    -213,  -213,   551,  -213,   455,  -213,   249,  -191,  -213,   555,
     456,  -213,  -213,   238,  -213,   224,  -213,  -213,  -103,  -213,
    -213,   190,   556,   -72,  -213,   -96,    29
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   110,   227,   384,     5,    19,    20,     6,
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
       102,   115,   116,   301,   302,    84,    86,   111,   113,   315,
     151,   152,   275,    16,    10,    73,    17,    18,   372,   125,
     126,   260,   261,   129,    88,   176,   177,   178,   351,     1,
     140,   141,   251,   252,   299,    74,   300,    75,    76,    77,
      78,    79,   303,    80,    81,   166,   167,   168,    85,    87,
     112,   114,   316,   180,   181,   182,   183,   184,   199,   200,
     201,   373,   202,   203,   204,   205,   135,   352,   157,   283,
     284,   160,    94,    95,    96,   190,   191,   192,   223,   193,
     194,   195,   196,   197,   258,     8,   259,    94,    95,    96,
     224,   225,   226,    97,     9,   260,   261,   103,    98,   104,
      99,   100,   101,   105,     2,   212,   317,   318,   319,     1,
       2,    26,   320,    98,   321,    99,   100,   101,   376,   377,
     378,    30,    31,   106,   379,   107,   108,   109,   169,   170,
     171,    27,   322,   217,   172,   238,   239,   317,   318,   319,
     265,   266,   267,   320,   380,    28,   381,   382,   383,   247,
     145,   218,   219,    29,   173,    12,   250,    11,   213,   214,
     215,    11,    12,   322,   216,   263,   264,   386,   387,    16,
     146,   147,   148,   149,   150,   156,   397,   398,   399,   400,
     401,   402,   403,   404,   207,    39,   276,   277,   278,   279,
     280,   208,    37,    38,   408,   409,   157,   158,   159,   160,
     232,    40,   125,   126,   127,   128,   129,   233,    18,   125,
     126,   127,   128,   129,   406,    17,    18,    43,   146,   147,
     148,   149,   150,   407,    47,   146,   147,   148,   149,   150,
     236,   306,   391,   392,   393,   394,   395,   237,   358,   359,
      17,   391,   392,   393,   394,   395,   124,   248,   249,   157,
     158,   159,   160,   331,    48,    49,   157,   158,   159,   160,
      50,    51,   125,   126,   127,   128,   129,    52,   350,    31,
     189,   355,   356,   357,   253,   254,   255,   256,   257,   165,
      30,   146,   147,    55,   189,   150,   146,   147,   148,   149,
     150,   206,    56,    57,    58,   125,   126,   127,   128,   129,
     146,   147,   148,   149,   150,   231,    60,   125,   126,   127,
     128,   129,   234,   332,   333,   334,    61,   243,    63,   335,
      65,   146,   147,   148,   149,   150,   268,    66,   235,   157,
     158,   159,   160,   146,   147,   148,   149,   150,   269,    67,
      68,    69,   125,   126,   127,   128,   129,   274,    71,   391,
     392,   130,   286,   395,   125,   126,   127,   128,   129,   287,
      88,    91,   117,   146,   147,   148,   149,   150,   146,   147,
     148,   149,   150,   346,   118,   146,   147,   148,   149,   150,
     364,   119,   120,   121,   132,   396,   122,   123,   131,   146,
     147,   148,   149,   150,   405,   133,   146,   147,   148,   149,
     150,   391,   392,   393,   394,   395,   410,   134,   137,   138,
     391,   392,   393,   394,   395,   411,   142,   143,   161,   198,
     144,   153,   391,   392,   393,   394,   395,   288,   154,   155,
     162,   391,   392,   393,   394,   395,   157,   158,   159,   160,
     289,   164,   163,   220,   157,   158,   159,   160,   290,   209,
     179,   221,   210,   222,   185,   186,   187,   157,   158,   159,
     160,   218,   219,   188,   211,   157,   158,   159,   160,   218,
     219,   218,   219,   253,   254,   255,   256,   257,   338,   339,
     340,   129,   230,   240,   150,   146,   147,   148,   149,   150,
     160,   241,   341,   342,   146,   147,   148,   149,   150,   391,
     392,   393,   394,   395,   242,   244,   245,   262,   246,   270,
     271,   272,   273,   285,   281,   291,   282,   292,   293,   260,
     297,   296,   310,   298,   308,   303,   327,   313,   312,   328,
     336,   309,   343,   329,   344,   345,   361,   362,   330,   363,
     365,   369,   375,   337,   136,   368,   374,   314,   307,   139,
     388,    24,   347,   348,   349,   360,   371,   370,   389,   390,
      25,   354,   385,    36,    42,    41,     0,     0,    35,     0,
      46,     0,     0,   395,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    59
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        67,    73,    74,    11,    12,     8,     8,     8,     8,     8,
     105,   106,    10,    40,     0,     9,    43,    44,     8,    26,
      27,    19,    20,    30,     9,   121,   122,   123,    11,    41,
      97,    98,   223,   224,     8,    29,    10,    31,    32,    33,
      34,    35,    50,    37,    38,   117,   118,   119,    51,    51,
      51,    51,    51,   125,   126,   127,   128,   129,   153,   154,
     155,    51,   157,   158,   159,   160,    51,    50,    27,   260,
     261,    30,     3,     4,     5,   142,   143,   144,     9,   146,
     147,   148,   149,   150,     8,    14,    10,     3,     4,     5,
      21,    22,    23,     9,    14,    19,    20,     3,    29,     5,
      31,    32,    33,     9,    42,   172,     3,     4,     5,    41,
      42,     5,     9,    29,    11,    31,    32,    33,     3,     4,
       5,    47,    48,    29,     9,    31,    32,    33,     3,     4,
       5,     5,    29,    10,     9,   207,   208,     3,     4,     5,
     235,   236,   237,     9,    29,    14,    31,    32,    33,   216,
       6,    28,    29,    14,    29,    46,   223,    45,     3,     4,
       5,    45,    46,    29,     9,   232,   233,   379,   380,    40,
      26,    27,    28,    29,    30,     6,   388,   389,   390,   391,
     392,   393,   394,   395,     8,    14,   253,   254,   255,   256,
     257,     8,    24,    25,   406,   407,    27,    28,    29,    30,
       8,    14,    26,    27,    28,    29,    30,     8,    44,    26,
      27,    28,    29,    30,     8,    43,    44,    36,    26,    27,
      28,    29,    30,     8,     6,    26,    27,    28,    29,    30,
       8,   298,    26,    27,    28,    29,    30,     8,   341,   342,
      43,    26,    27,    28,    29,    30,    10,   218,   219,    27,
      28,    29,    30,   320,     6,    50,    27,    28,    29,    30,
      50,    14,    26,    27,    28,    29,    30,    14,   335,    48,
      10,   338,   339,   340,    14,    15,    16,    17,    18,    10,
      47,    26,    27,     3,    10,    30,    26,    27,    28,    29,
      30,    10,     3,    50,    50,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,    10,     9,    26,    27,    28,
      29,    30,    10,     3,     4,     5,     3,    10,     3,     9,
      50,    26,    27,    28,    29,    30,    10,    50,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,    10,    14,
      14,     3,    26,    27,    28,    29,    30,    10,     3,    26,
      27,     3,    10,    30,    26,    27,    28,    29,    30,    10,
       9,     9,     9,    26,    27,    28,    29,    30,    26,    27,
      28,    29,    30,    10,     9,    26,    27,    28,    29,    30,
      10,     9,     9,     9,     3,    10,     9,     9,     6,    26,
      27,    28,    29,    30,    10,     6,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,    10,     3,     9,    51,
      26,    27,    28,    29,    30,    10,     9,     9,     3,    10,
       9,     9,    26,    27,    28,    29,    30,    10,     9,     9,
       6,    26,    27,    28,    29,    30,    27,    28,    29,    30,
      10,     6,     3,    10,    27,    28,    29,    30,    10,    27,
       6,    10,    27,    10,     8,     6,     3,    27,    28,    29,
      30,    28,    29,     6,    27,    27,    28,    29,    30,    28,
      29,    28,    29,    14,    15,    16,    17,    18,    14,    15,
      16,    30,     8,     3,    30,    26,    27,    28,    29,    30,
      30,     3,    28,    29,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,     3,    27,    27,     3,    27,    27,
       3,     3,     3,    10,     9,     3,     6,    27,     3,    19,
       3,     8,     3,     7,    10,    50,     3,     6,     8,    27,
       8,    13,     3,    27,     3,     3,     3,     3,    27,     3,
       3,     3,     3,    19,    89,    10,     6,   309,   299,    93,
       9,     6,    27,    27,    27,    27,    14,    27,     9,     9,
       7,   337,   372,    15,    20,    19,    -1,    -1,    14,    -1,
      23,    -1,    -1,    30,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    41,    42,    53,    54,    58,    61,    62,    14,    14,
       0,    45,    46,    68,    69,    71,    40,    43,    44,    59,
      60,    63,    64,    66,    62,    61,     5,     5,    14,    14,
      47,    48,    73,    74,    81,    71,    69,    24,    25,    14,
      14,    63,    59,    36,    94,    66,    64,     6,     6,    50,
      50,    14,    14,    81,    74,     3,     3,    50,    50,    94,
       9,     3,    70,     3,    72,    50,    50,    14,    14,     3,
      65,     3,    67,     9,    29,    31,    32,    33,    34,    35,
      37,    38,    95,    96,     8,    51,     8,    51,     9,    75,
      76,     9,    82,    83,     3,     4,     5,     9,    29,    31,
      32,    33,    56,     3,     5,     9,    29,    31,    32,    33,
      55,     8,    51,     8,    51,    95,    95,     9,     9,     9,
       9,     9,     9,     9,    10,    26,    27,    28,    29,    30,
       3,     6,     3,     6,     3,    51,    76,     9,    51,    82,
      56,    56,     9,     9,     9,     6,    26,    27,    28,    29,
      30,    55,    55,     9,     9,     9,     6,    27,    28,    29,
      30,     3,     6,     3,     6,    10,    95,    95,    95,     3,
       4,     5,     9,    29,    97,    98,    97,    97,    97,     6,
      95,    95,    95,    95,    95,     8,     6,     3,     6,    10,
      56,    56,    56,    56,    56,    56,    56,    56,    10,    55,
      55,    55,    55,    55,    55,    55,    10,     8,     8,    27,
      27,    27,    56,     3,     4,     5,     9,    10,    28,    29,
      10,    10,    10,     9,    21,    22,    23,    56,    79,    80,
       8,    10,     8,     8,    10,    26,     8,     8,    95,    95,
       3,     3,     3,    10,    27,    27,    27,    56,    98,    98,
      56,    79,    79,    14,    15,    16,    17,    18,     8,    10,
      19,    20,     3,    56,    56,    55,    55,    55,    10,    10,
      27,     3,     3,     3,    10,    10,    56,    56,    56,    56,
      56,     9,     6,    79,    79,    10,    10,    10,    10,    10,
      10,     3,    27,     3,    77,    78,     8,     3,     7,     8,
      10,    11,    12,    50,    84,    85,    56,    78,    10,    13,
       3,    86,     8,     6,    85,     8,    51,     3,     4,     5,
       9,    11,    29,    87,    88,    89,    90,     3,    27,    27,
      27,    56,     3,     4,     5,     9,     8,    19,    14,    15,
      16,    28,    29,     3,     3,     3,    10,    27,    27,    27,
      56,    11,    50,    91,    87,    56,    56,    56,    90,    90,
      27,     3,     3,     3,    10,     3,    92,    93,    10,     3,
      27,    14,     8,    51,     6,     3,     3,     4,     5,     9,
      29,    31,    32,    33,    57,    93,    57,    57,     9,     9,
       9,    26,    27,    28,    29,    30,    10,    57,    57,    57,
      57,    57,    57,    57,    57,    10,     8,     8,    57,    57,
      10,    10
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
     123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    63,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      82,    82,    83,    84,    84,    84,    84,    85,    86,    86,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    93,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98
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
       1,     1,     3,     3,     5,     1,     6,     6,     2,     4,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       1,     3,     3,     1,     5,     3,     3,     3,     2,     6,
       4,     4,     4
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
  "NEG", "'{'", "'}'", "$accept", "LHA", "declarations",
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
        53,     0,    -1,    54,    68,    73,    -1,    58,    59,    63,
      94,    -1,    58,    63,    94,    -1,     5,    -1,     3,    -1,
       9,    55,    10,    -1,    29,    55,    -1,    55,    28,    55,
      -1,    55,    29,    55,    -1,    55,    27,    55,    -1,    55,
      30,    55,    -1,    31,     9,    55,    10,    -1,    31,     9,
      55,    26,    55,    10,    -1,    32,     9,    55,     8,    55,
      10,    -1,    33,     9,    55,     8,    55,    10,    -1,     4,
      -1,     5,    -1,     3,    -1,     9,    56,    10,    -1,    29,
      56,    -1,    56,    26,    56,    -1,    56,    28,    56,    -1,
      56,    29,    56,    -1,    56,    27,    56,    -1,    56,    30,
      56,    -1,    31,     9,    56,    10,    -1,    32,     9,    56,
       8,    56,    10,    -1,    33,     9,    56,     8,    56,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     9,    57,    10,
      -1,    29,    57,    -1,    57,    26,    57,    -1,    57,    28,
      57,    -1,    57,    29,    57,    -1,    57,    27,    57,    -1,
      57,    30,    57,    -1,    31,     9,    57,    10,    -1,    32,
       9,    57,     8,    57,    10,    -1,    33,     9,    57,     8,
      57,    10,    -1,    62,    61,    -1,    61,    62,    -1,    60,
      -1,    60,    59,    -1,    40,    25,     3,    14,    55,     6,
      -1,    40,    24,     3,    14,    56,     6,    -1,    42,    14,
       5,     6,    -1,    41,    14,     5,     6,    -1,    64,    66,
      -1,    66,    64,    -1,    43,    14,    50,    65,    51,     6,
      -1,     3,    -1,    65,     8,     3,    -1,    44,    14,    50,
      67,    51,     6,    -1,     3,    -1,    67,     8,     3,    -1,
      69,    71,    -1,    71,    69,    -1,    45,    14,    50,    70,
      51,     6,    -1,     3,    -1,    70,     8,     3,    -1,    46,
      14,    50,    72,    51,     6,    -1,     3,    -1,    72,     8,
       3,    -1,    74,    81,    -1,    81,    74,    -1,    47,    14,
      50,    75,    51,     6,    -1,    76,    -1,    75,    76,    -1,
       9,     3,     8,    79,     8,     9,    77,    10,    10,     6,
      -1,     9,     3,     8,    79,    10,     6,    -1,    78,    -1,
      77,     8,    78,    -1,     3,     7,    56,    -1,    22,    -1,
      23,    -1,    80,    -1,    79,    19,    79,    -1,    79,    20,
      79,    -1,     9,    79,    10,    -1,    21,    79,    -1,    56,
      14,    56,    -1,    56,    16,    56,    -1,    56,    15,    56,
      -1,    56,    17,    56,    -1,    56,    18,    56,    -1,    48,
      14,    50,    82,    51,     6,    -1,    83,    -1,    83,    82,
      -1,     9,     9,     3,     8,     3,    10,     8,    84,     8,
      87,     8,    91,    10,     6,    -1,    11,    -1,    12,    -1,
      12,    13,    85,    -1,    85,    -1,    50,    86,    51,    -1,
       3,    -1,    86,     8,     3,    -1,    88,    -1,    88,    19,
      87,    -1,    11,    -1,    89,    14,    56,    -1,    89,    16,
      56,    -1,    89,    15,    56,    -1,    90,    -1,    89,    29,
      90,    -1,    89,    28,    90,    -1,     3,    -1,     9,    56,
      10,    27,     3,    -1,     5,    27,     3,    -1,     4,    27,
       3,    -1,     3,    27,     3,    -1,    29,     3,    -1,    29,
       9,    56,    10,    27,     3,    -1,    29,     5,    27,     3,
      -1,    29,     4,    27,     3,    -1,    29,     3,    27,     3,
      -1,    50,    92,    51,    -1,    11,    -1,    93,    -1,    92,
       8,    93,    -1,     3,    14,    57,    -1,    36,     9,    95,
      10,     6,    -1,    96,    -1,    32,     9,    95,     8,    95,
      10,    -1,    33,     9,    95,     8,    95,    10,    -1,    29,
      95,    -1,    31,     9,    95,    10,    -1,     9,    95,    10,
      -1,    95,    30,    95,    -1,    95,    28,    95,    -1,    95,
      29,    95,    -1,    95,    27,    95,    -1,    95,    26,    95,
      -1,    37,     9,    97,    10,    -1,    34,     9,    97,    10,
      -1,    35,     9,    97,    10,    -1,    38,     9,    97,    10,
      -1,    98,    -1,    97,    29,    98,    -1,    97,    28,    98,
      -1,     3,    -1,     9,    56,    10,    27,     3,    -1,     5,
      27,     3,    -1,     4,    27,     3,    -1,     3,    27,     3,
      -1,    29,     3,    -1,    29,     9,    56,    10,    27,     3,
      -1,    29,     5,    27,     3,    -1,    29,     4,    27,     3,
      -1,    29,     3,    27,     3,    -1
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
     485,   487,   489,   493,   497,   503,   505,   512,   519,   522,
     527,   531,   535,   539,   543,   547,   551,   556,   561,   566,
     571,   573,   577,   581,   583,   589,   593,   597,   601,   604,
     611,   616,   621
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   166,   166,   169,   170,   176,   177,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   199,   200,   201,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     223,   224,   225,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   255,   256,   258,   259,   261,   268,   278,
     282,   286,   287,   289,   323,   329,   333,   340,   346,   351,
     352,   354,   356,   364,   369,   371,   379,   388,   389,   393,
     400,   401,   403,   422,   444,   445,   446,   452,   453,   454,
     455,   456,   457,   458,   460,   461,   462,   463,   464,   469,
     473,   474,   476,   499,   500,   501,   505,   507,   509,   513,
     518,   519,   520,   522,   527,   532,   538,   539,   540,   542,
     546,   551,   556,   561,   582,   586,   591,   596,   601,   624,
     625,   627,   628,   630,   636,   637,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   660,   670,   680,
     691,   692,   693,   695,   699,   704,   709,   714,   733,   737,
     742,   747,   752
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
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 597;
  const int Lha_parser::yynnts_ = 47;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 52;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 304;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // lha

/* Line 1054 of lalr1.cc  */
#line 2495 "Lha-parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 776 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}

