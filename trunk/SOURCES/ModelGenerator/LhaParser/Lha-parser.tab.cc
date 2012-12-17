/* A Bison parser, made by GNU Bison 2.7.  */

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

/* Line 279 of lalr1.cc  */
#line 40 "Lha-parser.tab.cc"


#include "Lha-parser.tab.hh"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 48 "Lha-parser.tab.cc"
/* Unqualified %code blocks.  */
/* Line 286 of lalr1.cc  */
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








/* Line 286 of lalr1.cc  */
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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace lha {
/* Line 353 of lalr1.cc  */
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
/* Line 423 of lalr1.cc  */
#line 151 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 423 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 423 of lalr1.cc  */
#line 155 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 423 of lalr1.cc  */
#line 154 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 423 of lalr1.cc  */
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

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 3: /* str */
/* Line 455 of lalr1.cc  */
#line 152 "Lha-parser.yy"
        { delete ((*yyvaluep).name); };
/* Line 455 of lalr1.cc  */
#line 308 "Lha-parser.tab.cc"
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
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

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 5:
/* Line 670 of lalr1.cc  */
#line 180 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 181 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 194 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 197 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 198 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 200 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 203 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 204 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
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

  case 20:
/* Line 670 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 225 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 227 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 228 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 229 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 256 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 266 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 273 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  LhaEvaluate.parse(st);
							  Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
						}
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
                                        
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 293 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 327 "Lha-parser.yy"
    {
              
                Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
                
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 333 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 337 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
						std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
						YYABORT;
						}
                                                   
                                                    }
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 344 "Lha-parser.yy"
    {
               
                Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
                
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 350 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
                Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 360 "Lha-parser.yy"
    {
               
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 368 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else cout<<"Unknown location"<<endl;
}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 375 "Lha-parser.yy"
    {
                
		if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
		else cout<<"Unknown location"<<endl;
                
                
}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 383 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
			      Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 397 "Lha-parser.yy"
    {
for(int l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
  if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
  YYABORT;}
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 408 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 429 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 450 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
										FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
								else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl; 
									   YYABORT;}				
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 456 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 457 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 459 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 461 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 462 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 465 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 466 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 467 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 468 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 473 "Lha-parser.yy"
    {
					    
}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 480 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 504 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 505 "Lha-parser.yy"
    {set<string> temp=PetriTransitions; 
				      for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
					    temp.erase((*it));
				      SubSet=temp;}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 513 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	      else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 517 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	      SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	      else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 522 "Lha-parser.yy"
    {}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 523 "Lha-parser.yy"
    {}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 527 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("==");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 532 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back("<=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 537 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
						  comp.push_back(">=");
						  CST.push_back((yysemantic_stack_[(3) - (3)].expression));
					      vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 547 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 551 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 556 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 112:
/* Line 670 of lalr1.cc  */
#line 561 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:
/* Line 670 of lalr1.cc  */
#line 566 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 587 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 591 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 596 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 601 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
			   CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 606 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 628 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 629 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 634 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
  else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 124:
/* Line 670 of lalr1.cc  */
#line 639 "Lha-parser.yy"
    {
  if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {std::ostringstream s; s<<Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)];
      FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (1)].name)]]= 
	"Var [" + s.str() + "] * Likelihood"; }
  else{cout<<*(yysemantic_stack_[(5) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
 }
    break;

  case 127:
/* Line 670 of lalr1.cc  */
#line 650 "Lha-parser.yy"
    {
		Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(7) - (5)].expression));
		Reader.MyLha.HASLname.push_back(*(yysemantic_stack_[(7) - (1)].name));
	Reader.MyLha.HASLtop.push_back(HaslFormulasTop((int)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel));
	}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 656 "Lha-parser.yy"
    {
		Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(5) - (3)].expression));
		Reader.MyLha.HASLname.push_back("");
	Reader.MyLha.HASLtop.push_back(HaslFormulasTop((int)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel));
	}
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 661 "Lha-parser.yy"
    {
		Reader.MyLha.HASLname.push_back(*(yysemantic_stack_[(4) - (1)].name));
		Reader.MyLha.HASLtop.push_back(Reader.MyLha.ConfidenceLevel);
	}
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 665 "Lha-parser.yy"
    {
			Reader.MyLha.HASLname.push_back("");
			Reader.MyLha.HASLtop.push_back(Reader.MyLha.ConfidenceLevel);
	}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 671 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
				 sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
				}
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 674 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 675 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 676 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 677 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 678 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 679 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 680 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 681 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 682 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 683 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 684 "Lha-parser.yy"
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

  case 143:
/* Line 670 of lalr1.cc  */
#line 694 "Lha-parser.yy"
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

  case 144:
/* Line 670 of lalr1.cc  */
#line 704 "Lha-parser.yy"
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

  case 145:
/* Line 670 of lalr1.cc  */
#line 714 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 725 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 726 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 727 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 730 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
			else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 734 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 739 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 744 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 749 "Lha-parser.yy"
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
/* Line 670 of lalr1.cc  */
#line 768 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
			else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 772 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 777 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
			  {sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
			   }
			else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 787 "Lha-parser.yy"
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


/* Line 670 of lalr1.cc  */
#line 1651 "Lha-parser.tab.cc"
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
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
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
  const short int Lha_parser::yypact_ninf_ = -296;
  const short int
  Lha_parser::yypact_[] =
  {
       -39,     6,    74,    24,   130,    -7,   -30,    63,   121,   156,
    -296,   116,   124,   133,   136,   144,   193,   195,   221,   238,
     159,    68,   196,   200,  -296,  -296,   241,   268,   232,   254,
     294,   323,  -296,   228,   295,  -296,  -296,   337,   347,   299,
     311,    68,  -296,   350,   362,   368,  -296,    68,  -296,  -296,
    -296,  -296,   374,   381,   333,   345,  -296,  -296,   384,   391,
     403,   404,  -296,   259,   125,  -296,  -296,  -296,    -3,  -296,
      -2,   401,   402,    87,   175,  -296,    -1,  -296,     0,   409,
     413,   125,   125,   422,   423,   430,   431,   432,   435,   436,
     284,  -296,   405,   446,   439,   447,   463,    16,  -296,   456,
     414,   402,  -296,  -296,  -296,    87,    87,   464,   465,   468,
     186,  -296,  -296,   175,   175,   469,   470,   471,   192,   472,
     479,   484,   480,   125,  -296,   292,   246,   125,   125,   125,
      73,    73,    73,    73,   482,   125,   125,   125,   125,   125,
    -296,  -296,  -296,  -296,   499,   502,  -296,   516,   514,  -296,
     297,   312,    87,    87,    87,  -296,    87,    87,    87,    87,
      87,   441,   212,   175,   175,   175,  -296,   175,   175,   175,
     175,  -296,  -296,  -296,  -296,   305,  -296,   318,   139,   197,
     494,   495,   496,    87,   128,    65,  -296,    93,   107,   160,
    -296,   497,   497,   246,   246,  -296,   120,  -296,   517,  -296,
    -296,   326,   202,   225,   498,   498,   312,   312,  -296,  -296,
     331,   229,   263,   500,   212,   212,  -296,   518,  -296,   125,
     125,   523,   526,   528,   339,   505,   506,   507,    87,  -296,
      73,    73,  -296,  -296,  -296,   120,   120,  -296,  -296,   483,
     226,  -296,   532,  -296,    87,    87,  -296,   175,   175,   175,
    -296,   352,   360,  -296,  -296,  -296,   509,   534,   535,   536,
     365,  -296,  -296,   271,   230,  -296,    87,    87,    87,    87,
      87,   531,   537,   120,   120,   538,   373,   386,   454,   462,
     466,  -296,  -296,   539,  -296,  -296,  -296,   519,  -296,   476,
     476,   476,   476,   476,   541,  -296,  -296,   522,   542,  -296,
    -296,  -296,  -296,  -296,  -296,   544,   545,   140,  -296,    18,
    -296,    87,   541,   543,  -296,   546,   548,   547,  -296,   476,
    -296,   550,   493,  -296,     1,    10,  -296,  -296,   551,  -296,
     530,   533,   540,    87,  -296,   300,   553,   549,    12,  -296,
    -296,   555,   559,   560,   394,   552,   554,   556,    87,    20,
      10,    87,    87,    87,   182,   182,  -296,  -296,  -296,   557,
     561,   562,   563,   399,  -296,   566,   564,  -296,   476,   476,
     476,  -296,  -296,   567,  -296,  -296,  -296,   558,   568,    15,
    -296,   565,  -296,   569,    13,   566,  -296,  -296,  -296,  -296,
    -296,  -296,   170,   170,   571,   577,   578,   570,   488,  -296,
     407,   346,   170,   170,   170,   572,   170,   170,   170,   170,
     170,  -296,   420,   235,   240,  -296,   573,   573,   346,   346,
    -296,  -296,   170,   170,   428,   433,  -296,  -296
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
       0,     0,    46,     0,     0,     0,     4,   125,    51,    52,
      50,    49,     0,     0,     0,     0,    67,    68,     0,     0,
       0,     0,     3,     0,     0,   130,   126,    62,     0,    65,
       0,     0,     0,     0,     0,    54,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    70,     0,
       0,    90,    19,    17,    18,     0,     0,     0,     0,     0,
       0,     6,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    61,    66,    64,     0,     0,    71,     0,     0,    91,
       0,    21,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,    47,     0,     0,     0,
       0,    55,    53,    58,    56,     0,   136,     0,     0,     0,
     149,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     128,   141,   140,   138,   139,   137,     0,    69,     0,    89,
      20,     0,     0,     0,    22,    25,    23,    24,    26,     7,
       0,     0,     0,    11,     9,    10,    12,     0,   135,     0,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   143,
       0,     0,   144,   142,   145,     0,     0,    77,    78,     0,
       0,    79,     0,    27,     0,     0,    13,     0,     0,     0,
     127,     0,     0,   153,   152,   151,     0,     0,     0,     0,
       0,   148,   147,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,   133,     0,   158,   157,   156,     0,    82,    84,
      86,    85,    87,    88,     0,    73,    80,    81,     0,    28,
      29,    14,    15,    16,   150,     0,     0,     0,    74,     0,
     155,     0,     0,     0,    93,    94,     0,     0,    96,    76,
      75,     0,     0,    98,     0,     0,    72,    95,     0,    97,
     109,     0,     0,     0,   102,     0,     0,   100,     0,   106,
      99,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,   112,   111,     0,
       0,     0,     0,     0,   120,     0,     0,   101,   103,   105,
     104,   108,   107,     0,   118,   117,   116,     0,     0,     0,
     121,     0,   110,     0,     0,     0,   119,    92,   115,    32,
      30,    31,     0,     0,     0,     0,     0,     0,   123,   122,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     0,   124,    35,    38,    36,    37,
      39,    40,     0,     0,     0,     0,    41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -296,  -296,  -296,  -103,   -73,  -295,  -296,   529,  -296,   581,
     583,   574,   575,  -296,   579,  -296,  -296,   576,  -296,   580,
    -296,  -296,   582,  -296,   481,  -296,   261,  -200,  -296,   584,
     475,  -296,  -296,   255,  -296,   242,  -296,  -296,   -38,  -296,
    -296,   205,    48,  -296,   -80,  -296,   -32,    99
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   118,   239,   398,     5,    19,    20,     6,
       7,    21,    22,    76,    23,    78,    13,    14,    68,    15,
      70,    32,    33,    97,    98,   307,   308,   240,   241,    34,
     100,   101,   317,   318,   324,   336,   337,   338,   339,   366,
     379,   380,    46,    47,    90,    91,   185,   186
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       110,   125,   126,     1,     2,    92,    94,   119,   121,   328,
     161,   162,     1,   330,   331,   332,   389,   390,   391,   333,
       8,   334,   392,   385,    10,    96,   351,   352,   353,   314,
     315,   364,   150,   151,    16,   264,   265,    17,    18,   335,
     354,   355,   393,   175,   394,   395,   396,   177,   178,   179,
      93,    95,   120,   122,   329,   191,   192,   193,   194,   195,
     210,   211,   212,   397,   213,   214,   215,   216,   386,   145,
     316,    43,   365,   296,   297,   229,   180,   181,   182,   201,
     202,   203,   183,   204,   205,   206,   207,   208,     9,    62,
     102,   103,   104,   230,   231,    66,   105,   400,   401,   187,
     188,   189,   184,   232,    44,    45,     2,   412,   413,   414,
     224,   416,   417,   418,   419,   420,   106,   233,   107,   108,
     109,   230,   231,   102,   103,   104,    26,   424,   425,   235,
      28,   225,   226,   227,    81,   230,   231,   228,    29,   251,
     252,   236,   237,   238,   278,   279,   280,   219,   312,   106,
     313,   107,   108,   109,    82,   260,    83,    84,    85,    86,
      87,    27,   263,    88,    89,   135,   136,   137,   138,   139,
     234,   276,   277,   389,   390,   391,    11,    12,   111,   392,
     112,    30,    31,    12,   113,   330,   331,   332,   230,   231,
      11,   333,   155,   289,   290,   291,   292,   293,   166,   393,
      16,   394,   395,   396,   114,   220,   115,   116,   117,    39,
     244,   335,   156,   157,   158,   159,   160,    37,    38,   167,
     168,   169,   170,   135,   136,   137,   138,   139,   156,   157,
     158,   159,   160,   245,   271,    40,   272,   248,   319,   167,
     288,    18,   170,   422,    17,   273,   274,    50,   423,   273,
     274,   156,   157,   158,   159,   160,   167,   168,   169,   170,
     344,   406,   407,   408,   409,   410,   406,   407,   408,   409,
     410,   249,   135,   136,    51,   363,   139,    31,   368,   369,
     370,   200,    17,    18,    52,   266,   267,   268,   269,   270,
     167,   168,   169,   170,   134,    79,    80,   156,   157,   158,
     159,   160,   176,   345,   346,   347,    53,   200,    54,   348,
     135,   136,   137,   138,   139,   217,   371,   372,   135,   136,
     137,   138,   139,   156,   157,   158,   159,   160,   218,   261,
     262,   135,   136,   137,   138,   139,   243,    55,   156,   157,
      58,   246,   160,    30,   135,   136,   137,   138,   139,   256,
      59,    60,   156,   157,   158,   159,   160,   247,   167,   168,
     169,   170,   281,    61,    63,   156,   157,   158,   159,   160,
     282,    64,   406,   407,    65,   287,   410,    67,   135,   136,
     137,   138,   139,   299,    69,    71,   135,   136,   137,   138,
     139,   156,   157,   158,   159,   160,   300,    72,    73,   156,
     157,   158,   159,   160,   359,    74,    75,    77,   140,   377,
      96,    99,   156,   157,   158,   159,   160,   411,   123,   124,
     156,   157,   158,   159,   160,   156,   157,   158,   159,   160,
     421,   127,   128,   406,   407,   408,   409,   410,   426,   129,
     130,   131,   142,   427,   132,   133,   406,   407,   408,   409,
     410,   209,   141,   143,   406,   407,   408,   409,   410,   406,
     407,   408,   409,   410,   301,   147,   144,   148,   167,   168,
     169,   170,   302,   152,   153,   171,   303,   154,   163,   164,
     165,   167,   168,   169,   170,   172,   174,   173,   190,   167,
     168,   169,   170,   167,   168,   169,   170,   266,   267,   268,
     269,   270,   156,   157,   158,   159,   160,   196,   197,   156,
     157,   158,   159,   160,   406,   407,   408,   409,   410,   198,
     199,   221,   222,   223,   250,   242,   253,   139,   160,   254,
     170,   255,   257,   258,   259,   275,   283,   284,   285,   286,
     294,   273,   304,   295,   306,   316,   305,   310,   298,    42,
     309,   323,   311,   321,   340,   325,   326,   341,   356,   322,
     342,   349,   357,   358,   374,   375,   376,   343,   350,   378,
     382,   387,   388,   320,   381,   415,   149,   327,   146,   360,
     402,   361,   384,   362,   373,   383,   403,   404,    25,    24,
     399,    36,   367,    41,    35,     0,     0,   405,    49,     0,
       0,    48,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    56
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        73,    81,    82,    42,    43,     8,     8,     8,     8,     8,
     113,   114,    42,     3,     4,     5,     3,     4,     5,     9,
      14,    11,     9,     8,     0,     9,    14,    15,    16,    11,
      12,    11,   105,   106,    41,   235,   236,    44,    45,    29,
      28,    29,    29,   123,    31,    32,    33,   127,   128,   129,
      53,    53,    53,    53,    53,   135,   136,   137,   138,   139,
     163,   164,   165,    50,   167,   168,   169,   170,    53,    53,
      52,     3,    52,   273,   274,    10,     3,     4,     5,   152,
     153,   154,     9,   156,   157,   158,   159,   160,    14,    41,
       3,     4,     5,    28,    29,    47,     9,   392,   393,   131,
     132,   133,    29,    10,    36,    37,    43,   402,   403,   404,
     183,   406,   407,   408,   409,   410,    29,    10,    31,    32,
      33,    28,    29,     3,     4,     5,     5,   422,   423,     9,
      14,     3,     4,     5,     9,    28,    29,     9,    14,   219,
     220,    21,    22,    23,   247,   248,   249,     8,     8,    29,
      10,    31,    32,    33,    29,   228,    31,    32,    33,    34,
      35,     5,   235,    38,    39,    26,    27,    28,    29,    30,
      10,   244,   245,     3,     4,     5,    46,    47,     3,     9,
       5,    48,    49,    47,     9,     3,     4,     5,    28,    29,
      46,     9,     6,   266,   267,   268,   269,   270,     6,    29,
      41,    31,    32,    33,    29,     8,    31,    32,    33,    14,
       8,    29,    26,    27,    28,    29,    30,    24,    25,    27,
      28,    29,    30,    26,    27,    28,    29,    30,    26,    27,
      28,    29,    30,     8,     8,    14,    10,     8,   311,    27,
      10,    45,    30,     8,    44,    19,    20,     6,     8,    19,
      20,    26,    27,    28,    29,    30,    27,    28,    29,    30,
     333,    26,    27,    28,    29,    30,    26,    27,    28,    29,
      30,     8,    26,    27,     6,   348,    30,    49,   351,   352,
     353,    10,    44,    45,    52,    14,    15,    16,    17,    18,
      27,    28,    29,    30,    10,    36,    37,    26,    27,    28,
      29,    30,    10,     3,     4,     5,    52,    10,    14,     9,
      26,    27,    28,    29,    30,    10,   354,   355,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,    10,   230,
     231,    26,    27,    28,    29,    30,    10,    14,    26,    27,
       3,    10,    30,    48,    26,    27,    28,    29,    30,    10,
       3,    52,    26,    27,    28,    29,    30,    26,    27,    28,
      29,    30,    10,    52,    14,    26,    27,    28,    29,    30,
      10,     9,    26,    27,     6,    10,    30,     3,    26,    27,
      28,    29,    30,    10,     3,    52,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,    10,    52,    14,    26,
      27,    28,    29,    30,    10,    14,     3,     3,     3,    10,
       9,     9,    26,    27,    28,    29,    30,    10,     9,     6,
      26,    27,    28,    29,    30,    26,    27,    28,    29,    30,
      10,     9,     9,    26,    27,    28,    29,    30,    10,     9,
       9,     9,     3,    10,     9,     9,    26,    27,    28,    29,
      30,    10,     6,     6,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    10,     9,     3,    53,    27,    28,
      29,    30,    10,     9,     9,     3,    10,     9,     9,     9,
       9,    27,    28,    29,    30,     6,     6,     3,     6,    27,
      28,    29,    30,    27,    28,    29,    30,    14,    15,    16,
      17,    18,    26,    27,    28,    29,    30,     8,     6,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,     3,
       6,    27,    27,    27,     6,     8,     3,    30,    30,     3,
      30,     3,    27,    27,    27,     3,    27,     3,     3,     3,
       9,    19,     3,     6,     3,    52,    27,     3,    10,    20,
       8,     3,     7,    10,     3,     8,     6,    27,     3,    13,
      27,     8,     3,     3,     3,     3,     3,    27,    19,     3,
       3,     6,     3,   312,    10,     3,   101,   322,    97,    27,
       9,    27,    14,    27,    27,    27,     9,     9,     7,     6,
     385,    15,   350,    19,    14,    -1,    -1,    27,    23,    -1,
      -1,    22,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    33
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    42,    43,    55,    56,    60,    63,    64,    14,    14,
       0,    46,    47,    70,    71,    73,    41,    44,    45,    61,
      62,    65,    66,    68,    64,    63,     5,     5,    14,    14,
      48,    49,    75,    76,    83,    73,    71,    24,    25,    14,
      14,    65,    61,     3,    36,    37,    96,    97,    68,    66,
       6,     6,    52,    52,    14,    14,    83,    76,     3,     3,
      52,    52,    96,    14,     9,     6,    96,     3,    72,     3,
      74,    52,    52,    14,    14,     3,    67,     3,    69,    36,
      37,     9,    29,    31,    32,    33,    34,    35,    38,    39,
      98,    99,     8,    53,     8,    53,     9,    77,    78,     9,
      84,    85,     3,     4,     5,     9,    29,    31,    32,    33,
      58,     3,     5,     9,    29,    31,    32,    33,    57,     8,
      53,     8,    53,     9,     6,    98,    98,     9,     9,     9,
       9,     9,     9,     9,    10,    26,    27,    28,    29,    30,
       3,     6,     3,     6,     3,    53,    78,     9,    53,    84,
      58,    58,     9,     9,     9,     6,    26,    27,    28,    29,
      30,    57,    57,     9,     9,     9,     6,    27,    28,    29,
      30,     3,     6,     3,     6,    98,    10,    98,    98,    98,
       3,     4,     5,     9,    29,   100,   101,   100,   100,   100,
       6,    98,    98,    98,    98,    98,     8,     6,     3,     6,
      10,    58,    58,    58,    58,    58,    58,    58,    58,    10,
      57,    57,    57,    57,    57,    57,    57,    10,    10,     8,
       8,    27,    27,    27,    58,     3,     4,     5,     9,    10,
      28,    29,    10,    10,    10,     9,    21,    22,    23,    58,
      81,    82,     8,    10,     8,     8,    10,    26,     8,     8,
       6,    98,    98,     3,     3,     3,    10,    27,    27,    27,
      58,   101,   101,    58,    81,    81,    14,    15,    16,    17,
      18,     8,    10,    19,    20,     3,    58,    58,    57,    57,
      57,    10,    10,    27,     3,     3,     3,    10,    10,    58,
      58,    58,    58,    58,     9,     6,    81,    81,    10,    10,
      10,    10,    10,    10,     3,    27,     3,    79,    80,     8,
       3,     7,     8,    10,    11,    12,    52,    86,    87,    58,
      80,    10,    13,     3,    88,     8,     6,    87,     8,    53,
       3,     4,     5,     9,    11,    29,    89,    90,    91,    92,
       3,    27,    27,    27,    58,     3,     4,     5,     9,     8,
      19,    14,    15,    16,    28,    29,     3,     3,     3,    10,
      27,    27,    27,    58,    11,    52,    93,    89,    58,    58,
      58,    92,    92,    27,     3,     3,     3,    10,     3,    94,
      95,    10,     3,    27,    14,     8,    53,     6,     3,     3,
       4,     5,     9,    29,    31,    32,    33,    50,    59,    95,
      59,    59,     9,     9,     9,    27,    26,    27,    28,    29,
      30,    10,    59,    59,    59,     3,    59,    59,    59,    59,
      59,    10,     8,     8,    59,    59,    10,    10
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
     305,   306,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      64,    65,    65,    66,    67,    67,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    83,
      84,    84,    85,    86,    86,    86,    86,    87,    88,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101
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
       1,     1,     3,     3,     5,     1,     2,     7,     5,     4,
       2,     1,     6,     6,     2,     4,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     1,     3,     3,     1,
       5,     3,     3,     3,     2,     6,     4,     4,     4
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
  "MAX", "LhaMIN", "LhaMAX", "AVG", "PROB", "LAST", "INTEGRAL", "LhaName",
  "Const", "NbLoc", "NbVar", "VList", "LList", "Iloc", "Floc", "locations",
  "edges", "LIKELIHOOD", "NEG", "'{'", "'}'", "$accept", "LHA",
  "declarations", "IntMarkingFormula", "RealMarkingFormula",
  "RealVarMarkingFormula", "Sizes", "Constants", "Constant", "NbVariables",
  "NbLocations", "Lists", "VariablesList", "VLabels", "LocationsList",
  "LLabels", "InitFinal", "init", "iLLabels", "final", "fLLabels",
  "definitions", "LocationsDef", "LOCATIONS", "LOCATION", "FLOWS", "FLOW",
  "LogExpr", "CompExpr", "EdgesDef", "EDGES", "EDGE", "ACTIONS",
  "SetOfActions", "Actions", "CONSTRAINTS", "CONSTRAINT", "LinearExp",
  "term", "UPDATES", "Updates", "Update", "HaslExps", "HaslExp", "AlgExpr",
  "LhaFunc", "LinForm", "VarTerm", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Lha_parser::rhs_number_type
  Lha_parser::yyrhs_[] =
  {
        55,     0,    -1,    56,    70,    75,    -1,    60,    61,    65,
      96,    -1,    60,    65,    96,    -1,     5,    -1,     3,    -1,
       9,    57,    10,    -1,    29,    57,    -1,    57,    28,    57,
      -1,    57,    29,    57,    -1,    57,    27,    57,    -1,    57,
      30,    57,    -1,    31,     9,    57,    10,    -1,    31,     9,
      57,    26,    57,    10,    -1,    32,     9,    57,     8,    57,
      10,    -1,    33,     9,    57,     8,    57,    10,    -1,     4,
      -1,     5,    -1,     3,    -1,     9,    58,    10,    -1,    29,
      58,    -1,    58,    26,    58,    -1,    58,    28,    58,    -1,
      58,    29,    58,    -1,    58,    27,    58,    -1,    58,    30,
      58,    -1,    31,     9,    58,    10,    -1,    32,     9,    58,
       8,    58,    10,    -1,    33,     9,    58,     8,    58,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     9,    59,    10,
      -1,    29,    59,    -1,    59,    26,    59,    -1,    59,    28,
      59,    -1,    59,    29,    59,    -1,    59,    27,    59,    -1,
      59,    30,    59,    -1,    31,     9,    59,    10,    -1,    32,
       9,    59,     8,    59,    10,    -1,    33,     9,    59,     8,
      59,    10,    -1,    64,    63,    -1,    63,    64,    -1,    62,
      -1,    62,    61,    -1,    41,    25,     3,    14,    57,     6,
      -1,    41,    24,     3,    14,    58,     6,    -1,    43,    14,
       5,     6,    -1,    42,    14,     5,     6,    -1,    66,    68,
      -1,    68,    66,    -1,    44,    14,    52,    67,    53,     6,
      -1,     3,    -1,    67,     8,     3,    -1,    45,    14,    52,
      69,    53,     6,    -1,     3,    -1,    69,     8,     3,    -1,
      71,    73,    -1,    73,    71,    -1,    46,    14,    52,    72,
      53,     6,    -1,     3,    -1,    72,     8,     3,    -1,    47,
      14,    52,    74,    53,     6,    -1,     3,    -1,    74,     8,
       3,    -1,    76,    83,    -1,    83,    76,    -1,    48,    14,
      52,    77,    53,     6,    -1,    78,    -1,    77,    78,    -1,
       9,     3,     8,    81,     8,     9,    79,    10,    10,     6,
      -1,     9,     3,     8,    81,    10,     6,    -1,    80,    -1,
      79,     8,    80,    -1,     3,     7,    58,    -1,    22,    -1,
      23,    -1,    82,    -1,    81,    19,    81,    -1,    81,    20,
      81,    -1,     9,    81,    10,    -1,    21,    81,    -1,    58,
      14,    58,    -1,    58,    16,    58,    -1,    58,    15,    58,
      -1,    58,    17,    58,    -1,    58,    18,    58,    -1,    49,
      14,    52,    84,    53,     6,    -1,    85,    -1,    85,    84,
      -1,     9,     9,     3,     8,     3,    10,     8,    86,     8,
      89,     8,    93,    10,     6,    -1,    11,    -1,    12,    -1,
      12,    13,    87,    -1,    87,    -1,    52,    88,    53,    -1,
       3,    -1,    88,     8,     3,    -1,    90,    -1,    90,    19,
      89,    -1,    11,    -1,    91,    14,    58,    -1,    91,    16,
      58,    -1,    91,    15,    58,    -1,    92,    -1,    91,    29,
      92,    -1,    91,    28,    92,    -1,     3,    -1,     9,    58,
      10,    27,     3,    -1,     5,    27,     3,    -1,     4,    27,
       3,    -1,     3,    27,     3,    -1,    29,     3,    -1,    29,
       9,    58,    10,    27,     3,    -1,    29,     5,    27,     3,
      -1,    29,     4,    27,     3,    -1,    29,     3,    27,     3,
      -1,    52,    94,    53,    -1,    11,    -1,    95,    -1,    94,
       8,    95,    -1,     3,    14,    59,    -1,     3,    14,    50,
      27,     3,    -1,    97,    -1,    97,    96,    -1,     3,    14,
      36,     9,    98,    10,     6,    -1,    36,     9,    98,    10,
       6,    -1,     3,    14,    37,     6,    -1,    37,     6,    -1,
      99,    -1,    32,     9,    98,     8,    98,    10,    -1,    33,
       9,    98,     8,    98,    10,    -1,    29,    98,    -1,    31,
       9,    98,    10,    -1,     9,    98,    10,    -1,    98,    30,
      98,    -1,    98,    28,    98,    -1,    98,    29,    98,    -1,
      98,    27,    98,    -1,    98,    26,    98,    -1,    38,     9,
     100,    10,    -1,    34,     9,   100,    10,    -1,    35,     9,
     100,    10,    -1,    39,     9,   100,    10,    -1,   101,    -1,
     100,    29,   101,    -1,   100,    28,   101,    -1,     3,    -1,
       9,    58,    10,    27,     3,    -1,     5,    27,     3,    -1,
       4,    27,     3,    -1,     3,    27,     3,    -1,    29,     3,
      -1,    29,     9,    58,    10,    27,     3,    -1,    29,     5,
      27,     3,    -1,    29,     4,    27,     3,    -1,    29,     3,
      27,     3,    -1
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
     527,   530,   532,   539,   546,   549,   554,   558,   562,   566,
     570,   574,   578,   583,   588,   593,   598,   600,   604,   608,
     610,   616,   620,   624,   628,   631,   638,   643,   648
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   170,   170,   173,   174,   180,   181,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   203,   204,   205,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     227,   228,   229,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   259,   260,   262,   263,   265,   272,   282,
     286,   290,   291,   293,   327,   333,   337,   344,   350,   355,
     356,   358,   360,   368,   373,   375,   383,   392,   393,   397,
     404,   405,   407,   426,   448,   449,   450,   456,   457,   458,
     459,   460,   461,   462,   464,   465,   466,   467,   468,   473,
     477,   478,   480,   503,   504,   505,   509,   511,   513,   517,
     522,   523,   524,   526,   531,   536,   542,   543,   544,   546,
     550,   555,   560,   565,   586,   590,   595,   600,   605,   628,
     629,   631,   632,   634,   639,   648,   648,   650,   656,   661,
     665,   671,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   694,   704,   714,   725,   726,   727,   729,
     733,   738,   743,   748,   767,   771,   776,   781,   786
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
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 617;
  const int Lha_parser::yynnts_ = 48;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 54;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 306;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2553 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 810 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}
