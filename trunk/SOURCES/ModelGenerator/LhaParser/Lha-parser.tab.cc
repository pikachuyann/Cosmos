/* A Bison parser, made by GNU Bison 2.6.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

/* Line 278 of lalr1.cc  */
#line 40 "Lha-parser.tab.cc"


#include "Lha-parser.tab.hh"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 48 "Lha-parser.tab.cc"
/* Unqualified %code blocks.  */
/* Line 285 of lalr1.cc  */
#line 39 "Lha-parser.yy"

#include "../HaslFormula.hpp"
#include "Lha-Reader.hpp"
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








/* Line 285 of lalr1.cc  */
#line 85 "Lha-parser.tab.cc"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

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

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


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
/* Line 352 of lalr1.cc  */
#line 180 "Lha-parser.tab.cc"

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
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
        case 3: /* str */
/* Line 422 of lalr1.cc  */
#line 150 "Lha-parser.yy"
	{ debug_stream () << *((*yyvaluep).name); };
/* Line 422 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
	break;
      case 4: /* rval */
/* Line 422 of lalr1.cc  */
#line 154 "Lha-parser.yy"
	{ debug_stream () << ((*yyvaluep).RealVal); };
/* Line 422 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
	break;
      case 5: /* ival */
/* Line 422 of lalr1.cc  */
#line 153 "Lha-parser.yy"
	{ debug_stream () << ((*yyvaluep).IntVal); };
/* Line 422 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
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
        case 3: /* str */
/* Line 453 of lalr1.cc  */
#line 151 "Lha-parser.yy"
	{ delete ((*yyvaluep).name); };
/* Line 453 of lalr1.cc  */
#line 307 "Lha-parser.tab.cc"
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

  inline bool
  Lha_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Lha_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Lha_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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
/* Line 661 of lalr1.cc  */
#line 179 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
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
/* Line 661 of lalr1.cc  */
#line 190 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 194 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 197 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 198 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 202 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 203 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 204 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 226 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 227 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 228 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 265 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 272 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 281 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
                                        
}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 292 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 326 "Lha-parser.yy"
    {
              
                Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
                
}
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 332 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 336 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
						std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
						YYABORT;
						}
                                                   
                                                    }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 343 "Lha-parser.yy"
    {
               
                Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
                
}
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 349 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 359 "Lha-parser.yy"
    {
               
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 367 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else cout<<"Unknown location"<<endl;
}
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 374 "Lha-parser.yy"
    {
                
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 382 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 396 "Lha-parser.yy"
    {
for(int l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
  if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
  YYABORT;}
}
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 407 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 428 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 449 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
										FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
								else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl; 
									   YYABORT;}				
}
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 455 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 456 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 457 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 459 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 461 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 463 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 465 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 466 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 467 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 472 "Lha-parser.yy"
    {
					    
}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 479 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 503 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 504 "Lha-parser.yy"
    {set<string> temp=PetriTransitions; 
				      for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
					    temp.erase((*it));
				      SubSet=temp;}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 512 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	      else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 516 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	      else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 521 "Lha-parser.yy"
    {}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 522 "Lha-parser.yy"
    {}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 526 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("==");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 531 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("<=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 536 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back(">=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 546 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 550 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 555 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 560 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 565 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 586 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 590 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 595 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 600 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 605 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 627 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 628 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 633 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
  else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 638 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {std::ostringstream s; s<<Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)];
      FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (1)].name)]]= 
	"Var [" + s.str() + "] * Likelihood"; }
  else{cout<<*(yysemantic_stack_[(5) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 649 "Lha-parser.yy"
    {
		Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(7) - (5)].expression));
		Reader.MyLha.HASLname.push_back(*(yysemantic_stack_[(7) - (1)].name));
		Reader.MyLha.HASLtop.push_back(HaslFormulasTop((int)Reader.MyLha.Algebraic.size()-1,0.5));
	}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 654 "Lha-parser.yy"
    {
		Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(5) - (3)].expression));
		Reader.MyLha.HASLname.push_back("");
		Reader.MyLha.HASLtop.push_back(HaslFormulasTop((int)Reader.MyLha.Algebraic.size()-1,0.5));
	}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 660 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
				 sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
				}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 663 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 664 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 665 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 666 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 667 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 668 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 669 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 670 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 671 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 672 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 673 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 683 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 693 "Lha-parser.yy"
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
/* Line 661 of lalr1.cc  */
#line 703 "Lha-parser.yy"
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

  case 144:
/* Line 661 of lalr1.cc  */
#line 714 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 715 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 716 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 719 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 723 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 733 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 738 "Lha-parser.yy"
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

  case 152:
/* Line 661 of lalr1.cc  */
#line 757 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 761 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 766 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 771 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 776 "Lha-parser.yy"
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


/* Line 661 of lalr1.cc  */
#line 1625 "Lha-parser.tab.cc"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
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
	if (!yy_pact_value_is_default_ (yyn))
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  Lha_parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Lha_parser::yypact_ninf_ = -303;
  const short int
  Lha_parser::yypact_[] =
  {
        68,   -11,    20,    26,   189,    31,    35,   -12,    67,   100,
    -303,   117,   126,   103,    96,    69,   231,   145,   148,   216,
      84,     9,   130,   142,  -303,  -303,   184,   214,   158,   186,
     243,   260,  -303,   227,   259,  -303,  -303,   304,   310,   268,
     269,     9,  -303,   307,   331,  -303,     9,  -303,  -303,  -303,
    -303,   339,   358,   290,   311,  -303,  -303,   349,   368,   381,
     400,  -303,   347,   149,  -303,  -303,    -3,  -303,    -2,   395,
     396,   123,   168,  -303,    10,  -303,    15,   415,   149,   149,
     416,   417,   436,   437,   438,   457,   458,   302,  -303,   465,
     468,   472,   474,   478,    18,  -303,   486,   444,   396,  -303,
    -303,  -303,   123,   123,   488,   489,   490,   213,  -303,  -303,
     168,   168,   491,   492,   498,   119,   505,   503,   507,   506,
     149,   317,    12,   149,   149,   149,   202,   202,   202,   202,
     508,   149,   149,   149,   149,   149,  -303,  -303,  -303,  -303,
     509,   510,  -303,   512,   513,  -303,   323,   197,   123,   123,
     123,  -303,   123,   123,   123,   123,   123,   443,   195,   168,
     168,   168,  -303,   168,   168,   168,   168,  -303,  -303,  -303,
    -303,   329,  -303,   338,   218,   224,   484,   493,   494,   123,
     163,    63,  -303,    78,   105,   147,  -303,   483,   483,    12,
      12,  -303,    90,  -303,   514,  -303,  -303,   344,   241,   253,
     495,   495,   197,   197,  -303,  -303,   350,   281,   287,   496,
     195,   195,  -303,   517,  -303,   149,   149,   515,   521,   524,
     359,   501,   502,   504,   123,  -303,   202,   202,  -303,  -303,
    -303,    90,    90,  -303,  -303,   476,   110,  -303,   527,  -303,
     123,   123,  -303,   168,   168,   168,  -303,   365,   371,  -303,
    -303,  -303,   511,   529,   530,   531,   380,  -303,  -303,   308,
     169,  -303,   123,   123,   123,   123,   123,   526,   533,    90,
      90,   532,   386,   392,   449,   455,   459,  -303,  -303,   534,
    -303,  -303,  -303,   516,  -303,   270,   270,   270,   270,   270,
     537,  -303,  -303,   522,   528,  -303,  -303,  -303,  -303,  -303,
    -303,   541,   538,   188,  -303,    29,  -303,   123,   537,   536,
    -303,   535,   544,   542,  -303,   270,  -303,   543,   500,  -303,
      16,   199,  -303,  -303,   549,  -303,   539,   540,   545,   123,
    -303,   212,   546,   550,     0,  -303,  -303,   552,   553,   554,
     401,   547,   548,   551,   123,    -7,   199,   123,   123,   123,
     209,   209,  -303,  -303,  -303,   555,   556,   557,   558,   407,
    -303,   559,   560,  -303,   270,   270,   270,  -303,  -303,   561,
    -303,  -303,  -303,   562,   563,    17,  -303,   565,  -303,   570,
       4,   559,  -303,  -303,  -303,  -303,  -303,  -303,   132,   132,
     567,   571,   572,   564,   275,  -303,   413,   203,   132,   132,
     132,   576,   132,   132,   132,   132,   132,  -303,   422,   258,
     264,  -303,   523,   523,   203,   203,  -303,  -303,   132,   132,
     428,   434,  -303,  -303
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     0,     0,    44,    43,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    59,    60,     0,     0,     0,
       0,     0,    46,     0,     0,     4,   125,    51,    52,    50,
      49,     0,     0,     0,     0,    67,    68,     0,     0,     0,
       0,     3,     0,     0,   126,    62,     0,    65,     0,     0,
       0,     0,     0,    54,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    90,    19,
      17,    18,     0,     0,     0,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    61,    66,    64,
       0,     0,    71,     0,     0,    91,     0,    21,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,    47,     0,     0,     0,     0,    55,    53,    58,
      56,     0,   134,     0,     0,     0,   147,     0,     0,     0,
       0,     0,   144,     0,     0,     0,   128,   139,   138,   136,
     137,   135,     0,    69,     0,    89,    20,     0,     0,     0,
      22,    25,    23,    24,    26,     7,     0,     0,     0,    11,
       9,    10,    12,     0,   133,     0,     0,     0,     0,     0,
       0,   152,     0,     0,     0,   141,     0,     0,   142,   140,
     143,     0,     0,    77,    78,     0,     0,    79,     0,    27,
       0,     0,    13,     0,     0,     0,   127,     0,     0,   151,
     150,   149,     0,     0,     0,     0,     0,   146,   145,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
     156,   155,   154,     0,    82,    84,    86,    85,    87,    88,
       0,    73,    80,    81,     0,    28,    29,    14,    15,    16,
     148,     0,     0,     0,    74,     0,   153,     0,     0,     0,
      93,    94,     0,     0,    96,    76,    75,     0,     0,    98,
       0,     0,    72,    95,     0,    97,   109,     0,     0,     0,
     102,     0,     0,   100,     0,   106,    99,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   112,   111,     0,     0,     0,     0,     0,
     120,     0,     0,   101,   103,   105,   104,   108,   107,     0,
     118,   117,   116,     0,     0,     0,   121,     0,   110,     0,
       0,     0,   119,    92,   115,    32,    30,    31,     0,     0,
       0,     0,     0,     0,   123,   122,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,   124,    35,    38,    36,    37,    39,    40,     0,     0,
       0,     0,    41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -303,  -303,  -303,  -100,   -71,  -302,  -303,   566,  -303,   577,
     579,   568,   569,  -303,   573,  -303,  -303,   575,  -303,   574,
    -303,  -303,   578,  -303,   464,  -303,   255,  -180,  -303,   580,
     467,  -303,  -303,   250,  -303,   237,  -303,  -303,   -88,  -303,
    -303,   215,   -24,  -303,   -77,  -303,  -108,    38
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   115,   235,   394,     5,    19,    20,     6,
       7,    21,    22,    74,    23,    76,    13,    14,    66,    15,
      68,    32,    33,    94,    95,   303,   304,   236,   237,    34,
      97,    98,   313,   314,   320,   332,   333,   334,   335,   362,
     375,   376,    45,    46,    87,    88,   181,   182
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       107,   121,   122,     8,   360,    89,    91,   385,   386,   387,
     157,   158,    43,   388,   347,   348,   349,    61,   116,   183,
     184,   185,    64,   118,   324,   381,    10,    93,   350,   351,
       2,   146,   147,   389,     9,   390,   391,   392,   131,   132,
     310,   311,   135,   171,   361,    44,   173,   174,   175,    90,
      92,   260,   261,   393,   187,   188,   189,   190,   191,   206,
     207,   208,   117,   209,   210,   211,   212,   119,   325,   382,
     141,    16,    26,   225,    17,    18,     1,   197,   198,   199,
     312,   200,   201,   202,   203,   204,   396,   397,   228,   292,
     293,   226,   227,    99,   100,   101,   408,   409,   410,   231,
     412,   413,   414,   415,   416,    27,   226,   227,   220,     1,
       2,   232,   233,   234,    11,   229,   420,   421,   267,   103,
     268,   104,   105,   106,    16,   162,    99,   100,   101,   269,
     270,    28,   102,   226,   227,   385,   386,   387,   247,   248,
      29,   388,    12,   274,   275,   276,   163,   164,   165,   166,
      30,    31,   103,   256,   104,   105,   106,   230,    78,    39,
     259,   389,    40,   390,   391,   392,   221,   222,   223,   272,
     273,   108,   224,   109,    18,   226,   227,   110,    79,   284,
      80,    81,    82,    83,    84,    17,    85,    86,   269,   270,
      49,   285,   286,   287,   288,   289,   308,   111,   309,   112,
     113,   114,   326,   327,   328,   176,   177,   178,   329,    51,
     330,   179,   326,   327,   328,   341,   342,   343,   329,   151,
      50,   344,   163,   152,   153,   166,   215,   156,   331,   402,
     403,   180,   216,   406,    11,    12,   315,    52,   331,   152,
     153,   154,   155,   156,   131,   132,   133,   134,   135,   240,
     131,   132,   133,   134,   135,    37,    38,    53,   340,    17,
      18,   241,   367,   368,   257,   258,   418,   152,   153,   154,
     155,   156,   419,   359,    54,    31,   364,   365,   366,   152,
     153,   154,   155,   156,   402,   403,   404,   405,   406,   244,
     402,   403,   404,   405,   406,   245,   152,   153,   154,   155,
     156,   402,   403,   404,   405,   406,    30,    57,   163,   164,
     165,   166,   130,    58,   163,   164,   165,   166,   196,    59,
      60,    62,   262,   263,   264,   265,   266,   172,   131,   132,
     133,   134,   135,   196,   152,   153,   154,   155,   156,   213,
      63,    69,    65,   131,   132,   133,   134,   135,   214,   152,
     153,   154,   155,   156,   239,   131,   132,   133,   134,   135,
     242,    67,    70,    71,   131,   132,   133,   134,   135,   252,
     152,   153,   154,   155,   156,   277,   243,   163,   164,   165,
     166,   278,    72,    77,    73,   152,   153,   154,   155,   156,
     283,   131,   132,   133,   134,   135,   295,   131,   132,   133,
     134,   135,   296,    75,    93,    96,   152,   153,   154,   155,
     156,   355,   152,   153,   154,   155,   156,   373,   152,   153,
     154,   155,   156,   407,   120,   123,   124,   152,   153,   154,
     155,   156,   417,   152,   153,   154,   155,   156,   422,   402,
     403,   404,   405,   406,   423,   125,   126,   127,   402,   403,
     404,   405,   406,   205,   402,   403,   404,   405,   406,   297,
     402,   403,   404,   405,   406,   298,   128,   129,   136,   299,
     163,   164,   165,   166,   137,   138,   163,   164,   165,   166,
     139,   140,   163,   164,   165,   166,   163,   164,   165,   166,
     262,   263,   264,   265,   266,   143,   144,   148,   149,   150,
     159,   160,   152,   153,   154,   155,   156,   161,   167,   168,
     169,   217,   170,   135,   186,   194,   193,   192,   249,   195,
     218,   219,   238,   246,   250,   156,   166,   251,   253,   254,
     271,   255,   280,   281,   282,   290,   305,   300,   279,   291,
     302,   269,   294,   301,   306,   307,   317,   319,   318,   322,
     321,   312,   336,   406,   345,   352,   353,   354,   142,   370,
     371,   372,   374,   316,   378,   145,   337,   338,   323,   346,
     377,   383,   339,   384,   356,   357,   398,   380,   358,   411,
     399,   400,   369,   363,    25,    24,    42,    41,    35,   379,
      36,   401,    48,     0,     0,    47,   395,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    55
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        71,    78,    79,    14,    11,     8,     8,     3,     4,     5,
     110,   111,     3,     9,    14,    15,    16,    41,     8,   127,
     128,   129,    46,     8,     8,     8,     0,     9,    28,    29,
      42,   102,   103,    29,    14,    31,    32,    33,    26,    27,
      11,    12,    30,   120,    51,    36,   123,   124,   125,    52,
      52,   231,   232,    49,   131,   132,   133,   134,   135,   159,
     160,   161,    52,   163,   164,   165,   166,    52,    52,    52,
      52,    40,     5,    10,    43,    44,    41,   148,   149,   150,
      51,   152,   153,   154,   155,   156,   388,   389,    10,   269,
     270,    28,    29,     3,     4,     5,   398,   399,   400,     9,
     402,   403,   404,   405,   406,     5,    28,    29,   179,    41,
      42,    21,    22,    23,    45,    10,   418,   419,     8,    29,
      10,    31,    32,    33,    40,     6,     3,     4,     5,    19,
      20,    14,     9,    28,    29,     3,     4,     5,   215,   216,
      14,     9,    46,   243,   244,   245,    27,    28,    29,    30,
      47,    48,    29,   224,    31,    32,    33,    10,     9,    14,
     231,    29,    14,    31,    32,    33,     3,     4,     5,   240,
     241,     3,     9,     5,    44,    28,    29,     9,    29,    10,
      31,    32,    33,    34,    35,    43,    37,    38,    19,    20,
       6,   262,   263,   264,   265,   266,     8,    29,    10,    31,
      32,    33,     3,     4,     5,     3,     4,     5,     9,    51,
      11,     9,     3,     4,     5,     3,     4,     5,     9,     6,
       6,     9,    27,    26,    27,    30,     8,    30,    29,    26,
      27,    29,     8,    30,    45,    46,   307,    51,    29,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,     8,
      26,    27,    28,    29,    30,    24,    25,    14,   329,    43,
      44,     8,   350,   351,   226,   227,     8,    26,    27,    28,
      29,    30,     8,   344,    14,    48,   347,   348,   349,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,     8,
      26,    27,    28,    29,    30,     8,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,    47,     3,    27,    28,
      29,    30,    10,     3,    27,    28,    29,    30,    10,    51,
      51,    14,    14,    15,    16,    17,    18,    10,    26,    27,
      28,    29,    30,    10,    26,    27,    28,    29,    30,    10,
       9,    51,     3,    26,    27,    28,    29,    30,    10,    26,
      27,    28,    29,    30,    10,    26,    27,    28,    29,    30,
      10,     3,    51,    14,    26,    27,    28,    29,    30,    10,
      26,    27,    28,    29,    30,    10,    26,    27,    28,    29,
      30,    10,    14,    36,     3,    26,    27,    28,    29,    30,
      10,    26,    27,    28,    29,    30,    10,    26,    27,    28,
      29,    30,    10,     3,     9,     9,    26,    27,    28,    29,
      30,    10,    26,    27,    28,    29,    30,    10,    26,    27,
      28,    29,    30,    10,     9,     9,     9,    26,    27,    28,
      29,    30,    10,    26,    27,    28,    29,    30,    10,    26,
      27,    28,    29,    30,    10,     9,     9,     9,    26,    27,
      28,    29,    30,    10,    26,    27,    28,    29,    30,    10,
      26,    27,    28,    29,    30,    10,     9,     9,     3,    10,
      27,    28,    29,    30,     6,     3,    27,    28,    29,    30,
       6,     3,    27,    28,    29,    30,    27,    28,    29,    30,
      14,    15,    16,    17,    18,     9,    52,     9,     9,     9,
       9,     9,    26,    27,    28,    29,    30,     9,     3,     6,
       3,    27,     6,    30,     6,     3,     6,     8,     3,     6,
      27,    27,     8,     6,     3,    30,    30,     3,    27,    27,
       3,    27,     3,     3,     3,     9,     8,     3,    27,     6,
       3,    19,    10,    27,     3,     7,    10,     3,    13,     6,
       8,    51,     3,    30,     8,     3,     3,     3,    94,     3,
       3,     3,     3,   308,     3,    98,    27,    27,   318,    19,
      10,     6,    27,     3,    27,    27,     9,    14,    27,     3,
       9,     9,    27,   346,     7,     6,    20,    19,    14,    27,
      15,    27,    23,    -1,    -1,    22,   381,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    33
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
      14,    64,    60,     3,    36,    95,    96,    67,    65,     6,
       6,    51,    51,    14,    14,    82,    75,     3,     3,    51,
      51,    95,    14,     9,    95,     3,    71,     3,    73,    51,
      51,    14,    14,     3,    66,     3,    68,    36,     9,    29,
      31,    32,    33,    34,    35,    37,    38,    97,    98,     8,
      52,     8,    52,     9,    76,    77,     9,    83,    84,     3,
       4,     5,     9,    29,    31,    32,    33,    57,     3,     5,
       9,    29,    31,    32,    33,    56,     8,    52,     8,    52,
       9,    97,    97,     9,     9,     9,     9,     9,     9,     9,
      10,    26,    27,    28,    29,    30,     3,     6,     3,     6,
       3,    52,    77,     9,    52,    83,    57,    57,     9,     9,
       9,     6,    26,    27,    28,    29,    30,    56,    56,     9,
       9,     9,     6,    27,    28,    29,    30,     3,     6,     3,
       6,    97,    10,    97,    97,    97,     3,     4,     5,     9,
      29,    99,   100,    99,    99,    99,     6,    97,    97,    97,
      97,    97,     8,     6,     3,     6,    10,    57,    57,    57,
      57,    57,    57,    57,    57,    10,    56,    56,    56,    56,
      56,    56,    56,    10,    10,     8,     8,    27,    27,    27,
      57,     3,     4,     5,     9,    10,    28,    29,    10,    10,
      10,     9,    21,    22,    23,    57,    80,    81,     8,    10,
       8,     8,    10,    26,     8,     8,     6,    97,    97,     3,
       3,     3,    10,    27,    27,    27,    57,   100,   100,    57,
      80,    80,    14,    15,    16,    17,    18,     8,    10,    19,
      20,     3,    57,    57,    56,    56,    56,    10,    10,    27,
       3,     3,     3,    10,    10,    57,    57,    57,    57,    57,
       9,     6,    80,    80,    10,    10,    10,    10,    10,    10,
       3,    27,     3,    78,    79,     8,     3,     7,     8,    10,
      11,    12,    51,    85,    86,    57,    79,    10,    13,     3,
      87,     8,     6,    86,     8,    52,     3,     4,     5,     9,
      11,    29,    88,    89,    90,    91,     3,    27,    27,    27,
      57,     3,     4,     5,     9,     8,    19,    14,    15,    16,
      28,    29,     3,     3,     3,    10,    27,    27,    27,    57,
      11,    51,    92,    88,    57,    57,    57,    91,    91,    27,
       3,     3,     3,    10,     3,    93,    94,    10,     3,    27,
      14,     8,    52,     6,     3,     3,     4,     5,     9,    29,
      31,    32,    33,    49,    58,    94,    58,    58,     9,     9,
       9,    27,    26,    27,    28,    29,    30,    10,    58,    58,
      58,     3,    58,    58,    58,    58,    58,    10,     8,     8,
      58,    58,    10,    10
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
      92,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100
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
       1,     1,     3,     3,     5,     1,     2,     7,     5,     1,
       6,     6,     2,     4,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     1,     3,     3,     1,     5,     3,
       3,     3,     2,     6,     4,     4,     4
  };


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
  "Update", "HaslExps", "HaslExp", "AlgExpr", "LhaFunc", "LinForm",
  "VarTerm", YY_NULL
  };

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
      27,     3,    -1,    96,    -1,    96,    95,    -1,     3,    14,
      36,     9,    97,    10,     6,    -1,    36,     9,    97,    10,
       6,    -1,    98,    -1,    32,     9,    97,     8,    97,    10,
      -1,    33,     9,    97,     8,    97,    10,    -1,    29,    97,
      -1,    31,     9,    97,    10,    -1,     9,    97,    10,    -1,
      97,    30,    97,    -1,    97,    28,    97,    -1,    97,    29,
      97,    -1,    97,    27,    97,    -1,    97,    26,    97,    -1,
      37,     9,    99,    10,    -1,    34,     9,    99,    10,    -1,
      35,     9,    99,    10,    -1,    38,     9,    99,    10,    -1,
     100,    -1,    99,    29,   100,    -1,    99,    28,   100,    -1,
       3,    -1,     9,    57,    10,    27,     3,    -1,     5,    27,
       3,    -1,     4,    27,     3,    -1,     3,    27,     3,    -1,
      29,     3,    -1,    29,     9,    57,    10,    27,     3,    -1,
      29,     5,    27,     3,    -1,    29,     4,    27,     3,    -1,
      29,     3,    27,     3,    -1
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
     485,   487,   489,   493,   497,   503,   505,   508,   516,   522,
     524,   531,   538,   541,   546,   550,   554,   558,   562,   566,
     570,   575,   580,   585,   590,   592,   596,   600,   602,   608,
     612,   616,   620,   623,   630,   635,   640
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   169,   169,   172,   173,   179,   180,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   202,   203,   204,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     226,   227,   228,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   258,   259,   261,   262,   264,   271,   281,
     285,   289,   290,   292,   326,   332,   336,   343,   349,   354,
     355,   357,   359,   367,   372,   374,   382,   391,   392,   396,
     403,   404,   406,   425,   447,   448,   449,   455,   456,   457,
     458,   459,   460,   461,   463,   464,   465,   466,   467,   472,
     476,   477,   479,   502,   503,   504,   508,   510,   512,   516,
     521,   522,   523,   525,   530,   535,   541,   542,   543,   545,
     549,   554,   559,   564,   585,   589,   594,   599,   604,   627,
     628,   630,   631,   633,   638,   647,   647,   649,   654,   660,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   683,   693,   703,   714,   715,   716,   718,   722,   727,
     732,   737,   756,   760,   765,   770,   775
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
  const int Lha_parser::yylast_ = 613;
  const int Lha_parser::yynnts_ = 48;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 53;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 305;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1106 of lalr1.cc  */
#line 2500 "Lha-parser.tab.cc"
/* Line 1107 of lalr1.cc  */
#line 799 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}
