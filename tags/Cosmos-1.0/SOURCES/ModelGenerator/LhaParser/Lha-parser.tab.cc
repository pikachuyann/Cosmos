/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
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
#line 42 "Lha-parser.tab.cc"


#include "Lha-parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 51 "Lha-parser.tab.cc"
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
#line 89 "Lha-parser.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
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


namespace lha {

/* Line 380 of lalr1.cc  */
#line 155 "Lha-parser.tab.cc"
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
#line 150 "Lha-parser.yy"
	{ debug_stream () << *(yyvaluep->name); };

/* Line 449 of lalr1.cc  */
#line 232 "Lha-parser.tab.cc"
	break;
      case 4: /* "rval" */

/* Line 449 of lalr1.cc  */
#line 154 "Lha-parser.yy"
	{ debug_stream () << (yyvaluep->RealVal); };

/* Line 449 of lalr1.cc  */
#line 241 "Lha-parser.tab.cc"
	break;
      case 5: /* "ival" */

/* Line 449 of lalr1.cc  */
#line 153 "Lha-parser.yy"
	{ debug_stream () << (yyvaluep->IntVal); };

/* Line 449 of lalr1.cc  */
#line 250 "Lha-parser.tab.cc"
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
#line 151 "Lha-parser.yy"
	{ delete (yyvaluep->name); };

/* Line 480 of lalr1.cc  */
#line 289 "Lha-parser.tab.cc"
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
    location_type yyerror_range[3];

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
#line 179 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 180 "Lha-parser.yy"
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
#line 190 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 194 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 197 "Lha-parser.yy"
    {sprintf((yyval.expression),"fabs( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 198 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 200 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 203 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 204 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 205 "Lha-parser.yy"
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

  case 21:

/* Line 678 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"fabs( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 225 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 226 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 228 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 229 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 230 "Lha-parser.yy"
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

  case 35:

/* Line 678 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 256 "Lha-parser.yy"
    {sprintf((yyval.expression),"fabs( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 257 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 258 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 268 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 275 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 288 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
                                        
}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 295 "Lha-parser.yy"
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

  case 57:

/* Line 678 of lalr1.cc  */
#line 329 "Lha-parser.yy"
    {
              
                Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
                
}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 335 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 339 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
						std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
						YYABORT;
						}
                                                   
                                                    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 346 "Lha-parser.yy"
    {
               
                Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
                
}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 352 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 362 "Lha-parser.yy"
    {
               
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 370 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else cout<<"Unknown location"<<endl;
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 377 "Lha-parser.yy"
    {
                
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 385 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 399 "Lha-parser.yy"
    {
for(int l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
  if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
  YYABORT;}
}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 410 "Lha-parser.yy"
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 431 "Lha-parser.yy"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 452 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
										FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
								else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl; 
									   YYABORT;}				
}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 459 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 461 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 462 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 463 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 466 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 467 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 468 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 469 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 470 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 475 "Lha-parser.yy"
    {
					    
}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 482 "Lha-parser.yy"
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

  case 97:

/* Line 678 of lalr1.cc  */
#line 506 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 507 "Lha-parser.yy"
    {set<string> temp=PetriTransitions; 
				      for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
					    temp.erase((*it));
				      SubSet=temp;}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 515 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	      else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 519 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	      else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 524 "Lha-parser.yy"
    {}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 525 "Lha-parser.yy"
    {}
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 529 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("==");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 534 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("<=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 539 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back(">=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 549 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 553 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 558 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 563 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 568 "Lha-parser.yy"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 589 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 593 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 598 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 603 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 608 "Lha-parser.yy"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 630 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 631 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 636 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
		    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
				   else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 642 "Lha-parser.yy"
    {Reader.MyLha.Algebraic=(yysemantic_stack_[(5) - (3)].expression);}
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 643 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
				 sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
				}
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 646 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 647 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 648 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 649 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 650 "Lha-parser.yy"
    {sprintf((yyval.expression),"fabs(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 651 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 652 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 653 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 654 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 655 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 656 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 657 "Lha-parser.yy"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 667 "Lha-parser.yy"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 677 "Lha-parser.yy"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 687 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Mean");
									string ss="Mean("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 697 "Lha-parser.yy"
    {std::ostringstream s; s<<(yysemantic_stack_[(4) - (3)].expression);
									if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end()) 
										{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
									Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
									Reader.MyLha.LhaFuncType.push_back("Var");
									string ss="Var("; ss.append(s.str()); ss.append(")");
									if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end()) 
										{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
									sprintf((yyval.expression),"%s", ss.c_str());
									}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 707 "Lha-parser.yy"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 718 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 719 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 720 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 723 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 727 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 732 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 737 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 742 "Lha-parser.yy"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 761 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 765 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 770 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 775 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 780 "Lha-parser.yy"
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
#line 1750 "Lha-parser.tab.cc"
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

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
  const short int Lha_parser::yypact_ninf_ = -307;
  const short int
  Lha_parser::yypact_[] =
  {
       -38,    68,    73,   102,    80,   -20,    70,    95,   154,   184,
    -307,   185,   204,    49,   178,   202,   106,   238,   239,    -3,
     212,   217,   219,   226,  -307,  -307,   273,   275,   224,   236,
     276,   286,  -307,   250,   252,  -307,  -307,   306,   309,   269,
     270,   217,  -307,   312,  -307,  -307,  -307,  -307,  -307,   332,
     342,   294,   296,  -307,  -307,   354,   355,   353,   367,  -307,
     103,  -307,    -5,  -307,     0,   368,   369,   144,   208,  -307,
       1,  -307,     2,   103,   103,   370,   373,   380,   381,   382,
     394,   401,   402,   403,   406,   277,  -307,   377,   407,   414,
     410,   421,     6,  -307,   427,   383,   369,  -307,  -307,  -307,
     144,   144,   429,   436,   437,   438,   206,  -307,  -307,   208,
     208,   441,   448,   449,   450,   127,   445,   465,   476,   472,
     289,     5,   103,   103,   103,   103,    16,    16,    16,    16,
      16,    16,   474,   103,   103,   103,   103,   103,  -307,  -307,
    -307,  -307,   478,   477,  -307,   479,   486,  -307,   298,    96,
     144,   144,   144,   144,  -307,   144,   144,   144,   144,   144,
     460,    11,   208,   208,   208,   208,  -307,   208,   208,   208,
     208,  -307,  -307,  -307,  -307,  -307,   303,   310,    51,   175,
     457,   466,   480,   144,   271,    19,  -307,   117,   169,   496,
     502,   504,  -307,   483,   483,     5,     5,  -307,   159,  -307,
     512,  -307,  -307,   324,   331,   218,   230,   491,   491,    96,
      96,  -307,  -307,   336,   467,    90,   142,   492,    11,    11,
    -307,  -307,  -307,   103,   103,   523,   524,   525,   345,   517,
     518,   529,   144,  -307,    16,    16,  -307,  -307,  -307,  -307,
    -307,   159,   159,  -307,  -307,   520,   211,  -307,   526,  -307,
    -307,   144,   144,  -307,   208,  -307,   208,   208,   357,   366,
    -307,  -307,  -307,   530,   555,   556,   557,   371,  -307,  -307,
     268,    20,  -307,   144,   144,   144,   144,   144,   514,   558,
     159,   159,   551,   378,   392,   471,   475,   481,  -307,  -307,
     559,  -307,  -307,  -307,   536,  -307,   489,   489,   489,   489,
     489,   562,  -307,  -307,   547,   560,  -307,  -307,  -307,  -307,
    -307,  -307,   564,   563,   105,  -307,    -7,  -307,   144,   562,
     561,  -307,   565,   566,   567,  -307,   489,  -307,   568,   519,
    -307,     3,    13,  -307,  -307,   570,  -307,   549,   550,   552,
     144,  -307,   339,   572,   569,   200,  -307,  -307,   578,   579,
     580,   399,   571,   573,   574,   144,    17,    13,   144,   144,
     144,    92,    92,  -307,  -307,  -307,   575,   581,   582,   583,
     404,  -307,   584,   585,  -307,   489,   489,   489,  -307,  -307,
     586,  -307,  -307,  -307,   576,   577,     4,  -307,   587,  -307,
     589,   191,   584,  -307,  -307,  -307,  -307,  -307,  -307,   191,
     191,   588,   590,   595,   596,   513,  -307,   413,   284,   191,
     191,   191,   191,   191,   191,   191,   191,   191,  -307,   425,
     434,   235,   241,   591,   591,   284,   284,  -307,  -307,  -307,
     191,   191,   439,   446,  -307,  -307
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,    47,    46,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    62,    63,     0,     0,     0,
       0,     0,    49,     0,     4,    54,    55,    53,    52,     0,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     3,
       0,    65,     0,    68,     0,     0,     0,     0,     0,    57,
       0,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,    73,     0,     0,    93,    20,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     6,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    64,
      69,    67,     0,     0,    74,     0,     0,    94,     0,    22,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,    50,     0,     0,     0,
       0,    58,    56,    61,    59,   134,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,   146,     0,     0,     0,
       0,     0,   127,   139,   138,   136,   137,   135,     0,    72,
       0,    92,    21,     0,     0,     0,     0,    23,    26,    24,
      25,    27,     7,     0,     0,     0,     0,    11,     9,    10,
      12,   132,   133,     0,     0,     0,     0,     0,     0,   154,
       0,     0,     0,   141,     0,     0,   142,   140,   145,   143,
     144,     0,     0,    80,    81,     0,     0,    82,     0,    28,
      29,     0,     0,    13,     0,    14,     0,     0,     0,     0,
     153,   152,   151,     0,     0,     0,     0,     0,   148,   147,
       0,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,   158,   157,   156,     0,    85,    87,    89,    88,    90,
      91,     0,    76,    83,    84,     0,    30,    31,    15,    16,
      17,   150,     0,     0,     0,    77,     0,   155,     0,     0,
       0,    96,    97,     0,     0,    99,    79,    78,     0,     0,
     101,     0,     0,    75,    98,     0,   100,   112,     0,     0,
       0,   105,     0,     0,   103,     0,   109,   102,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   115,   114,     0,     0,     0,     0,
       0,   123,     0,     0,   104,   106,   108,   107,   111,   110,
       0,   121,   120,   119,     0,     0,     0,   124,     0,   113,
       0,     0,     0,   122,    95,   118,    34,    32,    33,     0,
       0,     0,     0,     0,     0,   126,   125,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,    37,    40,    38,    39,    41,    42,    43,
       0,     0,     0,     0,    44,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -307,  -307,  -307,   -96,   -67,  -306,  -307,   592,  -307,   599,
     601,   594,   593,  -307,   597,  -307,  -307,   600,  -307,   603,
    -307,  -307,   598,  -307,   498,  -307,   290,  -205,  -307,   602,
     500,  -307,  -307,   265,  -307,   251,  -307,  -307,  -195,  -307,
    -307,   222,   604,   -72,  -307,   424,   -48
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   115,   245,   405,     5,    19,    20,     6,
       7,    21,    22,    70,    23,    72,    13,    14,    62,    15,
      64,    32,    33,    92,    93,   314,   315,   246,   247,    34,
      95,    96,   324,   325,   331,   343,   344,   345,   346,   373,
     386,   387,    44,    85,    86,   185,   186
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       106,   120,   121,    87,   321,   322,     1,     2,    89,   116,
     118,   335,   392,   160,   161,    91,   337,   338,   339,   180,
     181,   182,   340,    16,   341,   183,    17,    18,   371,   233,
     295,   133,   134,   148,   149,   137,   271,   272,   167,   280,
     281,   170,   342,    17,    18,   184,   323,   234,   235,    88,
     176,   177,   178,   179,    90,   117,   119,   336,   393,   223,
     143,   193,   194,   195,   196,   197,   213,   214,   215,   216,
     372,   217,   218,   219,   220,   303,   304,   133,   134,   135,
     136,   137,     8,   203,   204,   205,   206,     9,   207,   208,
     209,   210,   211,   407,   408,   337,   338,   339,   256,    30,
      31,   340,    10,   419,   420,   421,   422,   423,   424,   425,
     426,   427,    73,   319,     1,   320,   228,   167,   168,   169,
     170,   342,   155,   156,   432,   433,   159,   236,    11,    12,
      37,    38,    74,   166,    75,    76,    77,    78,    79,    80,
       2,    81,    82,    83,    84,   234,   235,    97,    98,    99,
     257,   258,   259,   100,   167,   168,   169,   170,   285,    26,
     286,   287,    97,    98,    99,   267,   378,   379,   241,   167,
     168,   169,   170,   101,   270,   102,   103,   104,   105,   237,
     242,   243,   244,   224,   283,   284,   268,   269,   101,    27,
     102,   103,   104,   105,   396,   397,   398,   234,   235,    28,
     399,   133,   134,   135,   136,   137,   296,   297,   298,   299,
     300,   107,   154,   108,   358,   359,   360,   109,    29,   278,
     400,   279,   401,   402,   403,   404,   251,    12,   361,   362,
     280,   281,   155,   156,   157,   158,   159,   110,   252,   111,
     112,   113,   114,   430,   155,   156,   157,   158,   159,   431,
      11,   326,    39,    40,    43,    16,   155,   156,   157,   158,
     159,   413,   414,   415,   416,   417,    18,   413,   414,   415,
     416,   417,    17,   351,   229,   230,   231,    49,   202,    47,
     232,    48,   273,   274,   275,   276,   277,   132,   370,    50,
      51,   375,   376,   377,   155,   156,   157,   158,   159,   175,
      52,    31,    30,   133,   134,   135,   136,   137,   202,    55,
     413,   414,    56,   221,   417,   133,   134,   135,   136,   137,
     222,    60,    57,    58,   155,   156,   157,   158,   159,   133,
     134,   135,   136,   137,   249,    61,   133,   134,   135,   136,
     137,   250,   352,   353,   354,    63,   253,    65,   355,    66,
     155,   156,   157,   158,   159,   263,    69,   155,   156,   157,
     158,   159,   254,   167,   168,   169,   170,   288,    67,    68,
      71,   155,   156,   157,   158,   159,   289,    91,    94,   122,
     138,   294,   123,   133,   134,   135,   136,   137,   306,   124,
     125,   126,   133,   134,   135,   136,   137,   155,   156,   157,
     158,   159,   307,   127,   155,   156,   157,   158,   159,   366,
     128,   129,   130,   139,   384,   131,   141,   140,   155,   156,
     157,   158,   159,   418,   142,   155,   156,   157,   158,   159,
     155,   156,   157,   158,   159,   428,   145,   146,   150,   413,
     414,   415,   416,   417,   429,   151,   152,   153,   171,   434,
     162,   413,   414,   415,   416,   417,   435,   163,   164,   165,
     413,   414,   415,   416,   417,   413,   414,   415,   416,   417,
     212,   172,   413,   414,   415,   416,   417,   255,   174,   173,
     192,   308,   200,   199,   225,   309,   198,   167,   168,   169,
     170,   310,   201,   226,   167,   168,   169,   170,   167,   168,
     169,   170,   167,   168,   169,   170,   238,   227,   167,   168,
     169,   170,   239,   137,   240,   155,   156,   157,   158,   159,
     248,   159,   170,   301,   234,   235,   260,   261,   262,   282,
     234,   235,   234,   235,   273,   274,   275,   276,   277,   413,
     414,   415,   416,   417,   264,   265,   155,   156,   157,   158,
     159,   187,   188,   189,   190,   191,   266,   290,   291,   292,
     293,   305,   311,   312,   302,   313,   280,   317,   316,   330,
     318,   328,   323,   347,   333,   332,   348,   349,   329,   350,
     356,   363,   364,   365,   381,   382,   383,   385,   357,   389,
     144,   391,   395,   394,   334,   388,   147,   409,   367,   410,
     368,   369,   380,   390,   411,   412,    25,    24,   374,   327,
       0,     0,    42,    41,   406,    36,    46,    35,     0,    45,
       0,   417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        67,    73,    74,     8,    11,    12,    44,    45,     8,     8,
       8,     8,     8,   109,   110,     9,     3,     4,     5,     3,
       4,     5,     9,    43,    11,     9,    46,    47,    11,    10,
      10,    26,    27,   100,   101,    30,   241,   242,    27,    19,
      20,    30,    29,    46,    47,    29,    53,    28,    29,    54,
     122,   123,   124,   125,    54,    54,    54,    54,    54,     8,
      54,   133,   134,   135,   136,   137,   162,   163,   164,   165,
      53,   167,   168,   169,   170,   280,   281,    26,    27,    28,
      29,    30,    14,   150,   151,   152,   153,    14,   155,   156,
     157,   158,   159,   399,   400,     3,     4,     5,     8,    50,
      51,     9,     0,   409,   410,   411,   412,   413,   414,   415,
     416,   417,     9,     8,    44,    10,   183,    27,    28,    29,
      30,    29,    26,    27,   430,   431,    30,    10,    48,    49,
      24,    25,    29,     6,    31,    32,    33,    34,    35,    36,
      45,    38,    39,    40,    41,    28,    29,     3,     4,     5,
       8,   223,   224,     9,    27,    28,    29,    30,   254,     5,
     256,   257,     3,     4,     5,   232,   361,   362,     9,    27,
      28,    29,    30,    29,   241,    31,    32,    33,    34,    10,
      21,    22,    23,     8,   251,   252,   234,   235,    29,     5,
      31,    32,    33,    34,     3,     4,     5,    28,    29,    14,
       9,    26,    27,    28,    29,    30,   273,   274,   275,   276,
     277,     3,     6,     5,    14,    15,    16,     9,    14,     8,
      29,    10,    31,    32,    33,    34,     8,    49,    28,    29,
      19,    20,    26,    27,    28,    29,    30,    29,     8,    31,
      32,    33,    34,     8,    26,    27,    28,    29,    30,     8,
      48,   318,    14,    14,    37,    43,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,    47,    26,    27,    28,
      29,    30,    46,   340,     3,     4,     5,    53,    10,     6,
       9,     6,    14,    15,    16,    17,    18,    10,   355,    53,
      14,   358,   359,   360,    26,    27,    28,    29,    30,    10,
      14,    51,    50,    26,    27,    28,    29,    30,    10,     3,
      26,    27,     3,    10,    30,    26,    27,    28,    29,    30,
      10,     9,    53,    53,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    10,     3,    26,    27,    28,    29,
      30,    10,     3,     4,     5,     3,    10,    53,     9,    53,
      26,    27,    28,    29,    30,    10,     3,    26,    27,    28,
      29,    30,    26,    27,    28,    29,    30,    10,    14,    14,
       3,    26,    27,    28,    29,    30,    10,     9,     9,     9,
       3,    10,     9,    26,    27,    28,    29,    30,    10,     9,
       9,     9,    26,    27,    28,    29,    30,    26,    27,    28,
      29,    30,    10,     9,    26,    27,    28,    29,    30,    10,
       9,     9,     9,     6,    10,     9,     6,     3,    26,    27,
      28,    29,    30,    10,     3,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,    10,     9,    54,     9,    26,
      27,    28,    29,    30,    10,     9,     9,     9,     3,    10,
       9,    26,    27,    28,    29,    30,    10,     9,     9,     9,
      26,    27,    28,    29,    30,    26,    27,    28,    29,    30,
      10,     6,    26,    27,    28,    29,    30,    10,     6,     3,
       6,    10,     3,     6,    27,    10,     8,    27,    28,    29,
      30,    10,     6,    27,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    10,    27,    27,    28,
      29,    30,    10,    30,    10,    26,    27,    28,    29,    30,
       8,    30,    30,     9,    28,    29,     3,     3,     3,     3,
      28,    29,    28,    29,    14,    15,    16,    17,    18,    26,
      27,    28,    29,    30,    27,    27,    26,    27,    28,    29,
      30,   127,   128,   129,   130,   131,    27,    27,     3,     3,
       3,    10,     3,    27,     6,     3,    19,     3,     8,     3,
       7,    10,    53,     3,     6,     8,    27,    27,    13,    27,
       8,     3,     3,     3,     3,     3,     3,     3,    19,     3,
      92,    14,     3,     6,   329,    10,    96,     9,    27,     9,
      27,    27,    27,    27,     9,     9,     7,     6,   357,   319,
      -1,    -1,    20,    19,   392,    15,    23,    14,    -1,    22,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    44,    45,    56,    57,    61,    64,    65,    14,    14,
       0,    48,    49,    71,    72,    74,    43,    46,    47,    62,
      63,    66,    67,    69,    65,    64,     5,     5,    14,    14,
      50,    51,    76,    77,    84,    74,    72,    24,    25,    14,
      14,    66,    62,    37,    97,    69,    67,     6,     6,    53,
      53,    14,    14,    84,    77,     3,     3,    53,    53,    97,
       9,     3,    73,     3,    75,    53,    53,    14,    14,     3,
      68,     3,    70,     9,    29,    31,    32,    33,    34,    35,
      36,    38,    39,    40,    41,    98,    99,     8,    54,     8,
      54,     9,    78,    79,     9,    85,    86,     3,     4,     5,
       9,    29,    31,    32,    33,    34,    59,     3,     5,     9,
      29,    31,    32,    33,    34,    58,     8,    54,     8,    54,
      98,    98,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,    10,    26,    27,    28,    29,    30,     3,     6,
       3,     6,     3,    54,    79,     9,    54,    85,    59,    59,
       9,     9,     9,     9,     6,    26,    27,    28,    29,    30,
      58,    58,     9,     9,     9,     9,     6,    27,    28,    29,
      30,     3,     6,     3,     6,    10,    98,    98,    98,    98,
       3,     4,     5,     9,    29,   100,   101,   100,   100,   100,
     100,   100,     6,    98,    98,    98,    98,    98,     8,     6,
       3,     6,    10,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    10,    58,    58,    58,    58,    58,    58,    58,
      58,    10,    10,     8,     8,    27,    27,    27,    59,     3,
       4,     5,     9,    10,    28,    29,    10,    10,    10,    10,
      10,     9,    21,    22,    23,    59,    82,    83,     8,    10,
      10,     8,     8,    10,    26,    10,     8,     8,    98,    98,
       3,     3,     3,    10,    27,    27,    27,    59,   101,   101,
      59,    82,    82,    14,    15,    16,    17,    18,     8,    10,
      19,    20,     3,    59,    59,    58,    58,    58,    10,    10,
      27,     3,     3,     3,    10,    10,    59,    59,    59,    59,
      59,     9,     6,    82,    82,    10,    10,    10,    10,    10,
      10,     3,    27,     3,    80,    81,     8,     3,     7,     8,
      10,    11,    12,    53,    87,    88,    59,    81,    10,    13,
       3,    89,     8,     6,    88,     8,    54,     3,     4,     5,
       9,    11,    29,    90,    91,    92,    93,     3,    27,    27,
      27,    59,     3,     4,     5,     9,     8,    19,    14,    15,
      16,    28,    29,     3,     3,     3,    10,    27,    27,    27,
      59,    11,    53,    94,    90,    59,    59,    59,    93,    93,
      27,     3,     3,     3,    10,     3,    95,    96,    10,     3,
      27,    14,     8,    54,     6,     3,     3,     4,     5,     9,
      29,    31,    32,    33,    34,    60,    96,    60,    60,     9,
       9,     9,     9,    26,    27,    28,    29,    30,    10,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    10,    10,
       8,     8,    60,    60,    10,    10
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
     305,   306,   307,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    65,    66,    66,    67,    68,    68,    69,
      70,    70,    71,    71,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    85,    85,    86,    87,    87,    87,    87,
      88,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Lha_parser::yyr2_[] =
  {
         0,     2,     3,     4,     3,     1,     1,     3,     2,     3,
       3,     3,     3,     4,     4,     6,     6,     6,     1,     1,
       1,     3,     2,     3,     3,     3,     3,     3,     4,     4,
       6,     6,     1,     1,     1,     3,     2,     3,     3,     3,
       3,     3,     4,     4,     6,     6,     2,     2,     1,     2,
       6,     6,     4,     4,     2,     2,     6,     1,     3,     6,
       1,     3,     2,     2,     6,     1,     3,     6,     1,     3,
       2,     2,     6,     1,     2,    10,     6,     1,     3,     3,
       1,     1,     1,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     6,     1,     2,    14,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     5,     3,     3,     3,     2,     6,     4,
       4,     4,     3,     1,     1,     3,     3,     5,     1,     6,
       6,     2,     4,     4,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     1,     3,     3,     1,
       5,     3,     3,     3,     2,     6,     4,     4,     4
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
  "DOUBLE", "INT", "DIV", "MUL", "PLUS", "MINUS", "POWER", "FLOOR", "ABS",
  "MIN", "MAX", "LhaMIN", "LhaMAX", "AVG", "LAST", "INTEGRAL", "MEAN",
  "VAR", "LhaName", "Const", "NbLoc", "NbVar", "VList", "LList", "Iloc",
  "Floc", "locations", "edges", "NEG", "'{'", "'}'", "$accept", "LHA",
  "declarations", "IntMarkingFormula", "RealMarkingFormula",
  "RealVarMarkingFormula", "Sizes", "Constants", "Constant", "NbVariables",
  "NbLocations", "Lists", "VariablesList", "VLabels", "LocationsList",
  "LLabels", "InitFinal", "init", "iLLabels", "final", "fLLabels",
  "definitions", "LocationsDef", "LOCATIONS", "LOCATION", "FLOWS", "FLOW",
  "LogExpr", "CompExpr", "EdgesDef", "EDGES", "EDGE", "ACTIONS",
  "SetOfActions", "Actions", "CONSTRAINTS", "CONSTRAINT", "LinearExp",
  "term", "UPDATES", "Updates", "Update", "HaslExp", "AlgExpr", "LhaFunc",
  "LinForm", "VarTerm", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Lha_parser::rhs_number_type
  Lha_parser::yyrhs_[] =
  {
        56,     0,    -1,    57,    71,    76,    -1,    61,    62,    66,
      97,    -1,    61,    66,    97,    -1,     5,    -1,     3,    -1,
       9,    58,    10,    -1,    29,    58,    -1,    58,    28,    58,
      -1,    58,    29,    58,    -1,    58,    27,    58,    -1,    58,
      30,    58,    -1,    31,     9,    58,    10,    -1,    32,     9,
      58,    10,    -1,    31,     9,    58,    26,    58,    10,    -1,
      33,     9,    58,     8,    58,    10,    -1,    34,     9,    58,
       8,    58,    10,    -1,     4,    -1,     5,    -1,     3,    -1,
       9,    59,    10,    -1,    29,    59,    -1,    59,    26,    59,
      -1,    59,    28,    59,    -1,    59,    29,    59,    -1,    59,
      27,    59,    -1,    59,    30,    59,    -1,    31,     9,    59,
      10,    -1,    32,     9,    59,    10,    -1,    33,     9,    59,
       8,    59,    10,    -1,    34,     9,    59,     8,    59,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     9,    60,    10,
      -1,    29,    60,    -1,    60,    26,    60,    -1,    60,    28,
      60,    -1,    60,    29,    60,    -1,    60,    27,    60,    -1,
      60,    30,    60,    -1,    31,     9,    60,    10,    -1,    32,
       9,    60,    10,    -1,    33,     9,    60,     8,    60,    10,
      -1,    34,     9,    60,     8,    60,    10,    -1,    65,    64,
      -1,    64,    65,    -1,    63,    -1,    63,    62,    -1,    43,
      25,     3,    14,    58,     6,    -1,    43,    24,     3,    14,
      59,     6,    -1,    45,    14,     5,     6,    -1,    44,    14,
       5,     6,    -1,    67,    69,    -1,    69,    67,    -1,    46,
      14,    53,    68,    54,     6,    -1,     3,    -1,    68,     8,
       3,    -1,    47,    14,    53,    70,    54,     6,    -1,     3,
      -1,    70,     8,     3,    -1,    72,    74,    -1,    74,    72,
      -1,    48,    14,    53,    73,    54,     6,    -1,     3,    -1,
      73,     8,     3,    -1,    49,    14,    53,    75,    54,     6,
      -1,     3,    -1,    75,     8,     3,    -1,    77,    84,    -1,
      84,    77,    -1,    50,    14,    53,    78,    54,     6,    -1,
      79,    -1,    78,    79,    -1,     9,     3,     8,    82,     8,
       9,    80,    10,    10,     6,    -1,     9,     3,     8,    82,
      10,     6,    -1,    81,    -1,    80,     8,    81,    -1,     3,
       7,    59,    -1,    22,    -1,    23,    -1,    83,    -1,    82,
      19,    82,    -1,    82,    20,    82,    -1,     9,    82,    10,
      -1,    21,    82,    -1,    59,    14,    59,    -1,    59,    16,
      59,    -1,    59,    15,    59,    -1,    59,    17,    59,    -1,
      59,    18,    59,    -1,    51,    14,    53,    85,    54,     6,
      -1,    86,    -1,    86,    85,    -1,     9,     9,     3,     8,
       3,    10,     8,    87,     8,    90,     8,    94,    10,     6,
      -1,    11,    -1,    12,    -1,    12,    13,    88,    -1,    88,
      -1,    53,    89,    54,    -1,     3,    -1,    89,     8,     3,
      -1,    91,    -1,    91,    19,    90,    -1,    11,    -1,    92,
      14,    59,    -1,    92,    16,    59,    -1,    92,    15,    59,
      -1,    93,    -1,    92,    29,    93,    -1,    92,    28,    93,
      -1,     3,    -1,     9,    59,    10,    27,     3,    -1,     5,
      27,     3,    -1,     4,    27,     3,    -1,     3,    27,     3,
      -1,    29,     3,    -1,    29,     9,    59,    10,    27,     3,
      -1,    29,     5,    27,     3,    -1,    29,     4,    27,     3,
      -1,    29,     3,    27,     3,    -1,    53,    95,    54,    -1,
      11,    -1,    96,    -1,    95,     8,    96,    -1,     3,    14,
      60,    -1,    37,     9,    98,    10,     6,    -1,    99,    -1,
      33,     9,    98,     8,    98,    10,    -1,    34,     9,    98,
       8,    98,    10,    -1,    29,    98,    -1,    31,     9,    98,
      10,    -1,    32,     9,    98,    10,    -1,     9,    98,    10,
      -1,    98,    30,    98,    -1,    98,    28,    98,    -1,    98,
      29,    98,    -1,    98,    27,    98,    -1,    98,    26,    98,
      -1,    38,     9,   100,    10,    -1,    35,     9,   100,    10,
      -1,    36,     9,   100,    10,    -1,    40,     9,   100,    10,
      -1,    41,     9,   100,    10,    -1,    39,     9,   100,    10,
      -1,   101,    -1,   100,    29,   101,    -1,   100,    28,   101,
      -1,     3,    -1,     9,    59,    10,    27,     3,    -1,     5,
      27,     3,    -1,     4,    27,     3,    -1,     3,    27,     3,
      -1,    29,     3,    -1,    29,     9,    59,    10,    27,     3,
      -1,    29,     5,    27,     3,    -1,    29,     4,    27,     3,
      -1,    29,     3,    27,     3,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Lha_parser::yyprhs_[] =
  {
         0,     0,     3,     7,    12,    16,    18,    20,    24,    27,
      31,    35,    39,    43,    48,    53,    60,    67,    74,    76,
      78,    80,    84,    87,    91,    95,    99,   103,   107,   112,
     117,   124,   131,   133,   135,   137,   141,   144,   148,   152,
     156,   160,   164,   169,   174,   181,   188,   191,   194,   196,
     199,   206,   213,   218,   223,   226,   229,   236,   238,   242,
     249,   251,   255,   258,   261,   268,   270,   274,   281,   283,
     287,   290,   293,   300,   302,   305,   316,   323,   325,   329,
     333,   335,   337,   339,   343,   347,   351,   354,   358,   362,
     366,   370,   374,   381,   383,   386,   401,   403,   405,   409,
     411,   415,   417,   421,   423,   427,   429,   433,   437,   441,
     443,   447,   451,   453,   459,   463,   467,   471,   474,   481,
     486,   491,   496,   500,   502,   504,   508,   512,   518,   520,
     527,   534,   537,   542,   547,   551,   555,   559,   563,   567,
     571,   576,   581,   586,   591,   596,   601,   603,   607,   611,
     613,   619,   623,   627,   631,   634,   641,   646,   651
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   169,   169,   172,   173,   179,   180,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   203,   204,
     205,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   228,   229,   230,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   261,   262,   264,   265,
     267,   274,   284,   288,   292,   293,   295,   329,   335,   339,
     346,   352,   357,   358,   360,   362,   370,   375,   377,   385,
     394,   395,   399,   406,   407,   409,   428,   450,   451,   452,
     458,   459,   460,   461,   462,   463,   464,   466,   467,   468,
     469,   470,   475,   479,   480,   482,   505,   506,   507,   511,
     513,   515,   519,   524,   525,   526,   528,   533,   538,   544,
     545,   546,   548,   552,   557,   562,   567,   588,   592,   597,
     602,   607,   630,   631,   633,   634,   636,   642,   643,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   667,   677,   687,   697,   707,   718,   719,   720,   722,
     726,   731,   736,   741,   760,   764,   769,   774,   779
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
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 645;
  const int Lha_parser::yynnts_ = 47;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 55;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 307;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha

/* Line 1054 of lalr1.cc  */
#line 2568 "Lha-parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 803 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}

