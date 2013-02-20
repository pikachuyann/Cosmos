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
#line 41 "Lha-parser.yy"

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
#line 159 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 423 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 423 of lalr1.cc  */
#line 163 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 423 of lalr1.cc  */
#line 162 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 423 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 103: /* rorival */
/* Line 423 of lalr1.cc  */
#line 163 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 277 "Lha-parser.tab.cc"
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
#line 160 "Lha-parser.yy"
        { delete ((*yyvaluep).name); };
/* Line 455 of lalr1.cc  */
#line 315 "Lha-parser.tab.cc"
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
          case 6:
/* Line 670 of lalr1.cc  */
#line 190 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 191 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 201 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 208 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 209 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 210 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	
	else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 233 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 240 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 241 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 242 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	else{ if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
			sprintf((yyval.expression), "%s",(s.str()).c_str());
		}
		else {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
			{
				std::ostringstream s; s<<"Vars->"<< (yysemantic_stack_[(1) - (1)].name)->c_str();
				sprintf((yyval.expression), "%s",(s.str()).c_str());
			}
			else {cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label, a lha variable or a defined constant"<<endl;YYABORT;}
		}
	}
}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 271 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 278 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 279 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 280 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 281 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 289 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 290 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 299 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 306 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 315 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 319 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 326 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.label.size()!=Reader.MyLha.NbVar){
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

  case 60:
/* Line 670 of lalr1.cc  */
#line 359 "Lha-parser.yy"
    {
	
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 367 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 374 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 381 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 387 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 397 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 405 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 412 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 420 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 434 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 445 "Lha-parser.yy"
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

  case 79:
/* Line 670 of lalr1.cc  */
#line 466 "Lha-parser.yy"
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

  case 82:
/* Line 670 of lalr1.cc  */
#line 487 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 493 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 494 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 495 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 496 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 497 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 498 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 499 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 501 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 502 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 503 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 504 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 505 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 510 "Lha-parser.yy"
    {
	
}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 517 "Lha-parser.yy"
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

  case 100:
/* Line 670 of lalr1.cc  */
#line 541 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 542 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 550 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 554 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 559 "Lha-parser.yy"
    {}
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 560 "Lha-parser.yy"
    {}
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 564 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 569 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 574 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 584 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 588 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 593 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 598 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 119:
/* Line 670 of lalr1.cc  */
#line 603 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(3) - (1)].name)];
			CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"Marking.P->_PL_"<<(yysemantic_stack_[(3) - (1)].name)->c_str()<<" ";
				CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();
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

  case 120:
/* Line 670 of lalr1.cc  */
#line 624 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 628 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 633 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 638 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 124:
/* Line 670 of lalr1.cc  */
#line 643 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<"-"<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(4) - (2)].name)];
			CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"-Marking.P->_PL_"<<(yysemantic_stack_[(4) - (2)].name)->c_str()<<" ";
				CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();
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

  case 125:
/* Line 670 of lalr1.cc  */
#line 665 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 126:
/* Line 670 of lalr1.cc  */
#line 666 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 671 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 679 "Lha-parser.yy"
    {
	if((yysemantic_stack_[(4) - (3)].TOPHASL) != NULL){
		Reader.MyLha.HASLname.push_back(*(yysemantic_stack_[(4) - (1)].name));
		Reader.MyLha.HASLtop.push_back((yysemantic_stack_[(4) - (3)].TOPHASL));
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,*(yysemantic_stack_[(4) - (1)].name));
		}
	}
}
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 690 "Lha-parser.yy"
    {
	if((yysemantic_stack_[(2) - (1)].TOPHASL) != NULL){
		Reader.MyLha.HASLname.push_back("");
		Reader.MyLha.HASLtop.push_back((yysemantic_stack_[(2) - (1)].TOPHASL));
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,"");
		}
	}
}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 703 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 704 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 705 "Lha-parser.yy"
    { if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
			(yyval.RealVal) = Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else { if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
			(yyval.RealVal) = (double)Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else {
			cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a definded constant "<<endl;
			YYABORT;
		}}}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 715 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 719 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 722 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algPDF;
		algPDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" >= "<<bucket<<"&& "<<(yysemantic_stack_[(10) - (3)].expression)<<"<"<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
								Reader.MyLha.ConfidenceLevel));
		Reader.MyLha.HASLtop.back()->TypeOp = PDF_PART;
		std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 738 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algCDF;
		algCDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
		Reader.MyLha.ConfidenceLevel));
		Reader.MyLha.HASLtop.back()->TypeOp = CDF_PART;
		std::ostringstream s; s<<"$_$: Value in [-infinity , "<< bucket<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 755 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 758 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 761 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 764 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 767 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 770 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 774 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 777 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 778 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 779 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 780 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 781 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 783 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 784 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 785 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 786 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 788 "Lha-parser.yy"
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

  case 159:
/* Line 670 of lalr1.cc  */
#line 798 "Lha-parser.yy"
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

  case 160:
/* Line 670 of lalr1.cc  */
#line 808 "Lha-parser.yy"
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

  case 161:
/* Line 670 of lalr1.cc  */
#line 818 "Lha-parser.yy"
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

  case 162:
/* Line 670 of lalr1.cc  */
#line 828 "Lha-parser.yy"
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

  case 163:
/* Line 670 of lalr1.cc  */
#line 839 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 840 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 841 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 844 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str();
			if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
	} else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable or a place name"<<endl;YYABORT;}
}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 854 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 859 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 169:
/* Line 670 of lalr1.cc  */
#line 864 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 170:
/* Line 670 of lalr1.cc  */
#line 870 "Lha-parser.yy"
    { sprintf((yyval.expression),"%i ", (yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 873 "Lha-parser.yy"
    { sprintf((yyval.expression),"%f ", (yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 876 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yyval.expression),"%f * Vars->%s", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(3) - (1)].name)],(yysemantic_stack_[(3) - (3)].name)->c_str());
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yyval.expression),"Marking.P->_PL_%s * Vars->%s", (yysemantic_stack_[(3) - (1)].name)->c_str() ,(yysemantic_stack_[(3) - (3)].name)->c_str());
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

  case 173:
/* Line 670 of lalr1.cc  */
#line 895 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 174:
/* Line 670 of lalr1.cc  */
#line 899 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 175:
/* Line 670 of lalr1.cc  */
#line 904 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 176:
/* Line 670 of lalr1.cc  */
#line 909 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 177:
/* Line 670 of lalr1.cc  */
#line 914 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yyval.expression),"-%f * Vars->%s", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(4) - (2)].name)],(yysemantic_stack_[(4) - (4)].name)->c_str());
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yyval.expression),"-Marking.P->_PL_%s * Vars->%s", (yysemantic_stack_[(4) - (2)].name)->c_str() ,(yysemantic_stack_[(4) - (4)].name)->c_str());
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
#line 1857 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -286;
  const short int
  Lha_parser::yypact_[] =
  {
        60,    25,  -286,  -286,   103,    38,  -286,    34,    39,    64,
      79,    92,   -27,    56,    57,    69,  -286,     7,    81,   103,
     536,   112,   115,   117,   112,   112,  -286,   116,   123,   167,
      94,   101,   208,   139,   145,   258,   122,     7,   125,   135,
    -286,  -286,  -286,  -286,   103,   103,   103,   164,  -286,   112,
     112,   186,   193,   195,   241,   292,   302,   306,   374,   343,
    -286,   242,   252,   249,   254,   207,   247,   297,   331,  -286,
     334,   340,  -286,  -286,   413,   420,   368,   369,     7,  -286,
    -286,  -286,  -286,  -286,  -286,   321,  -286,   349,   236,   112,
     112,   112,   131,   131,   131,   131,   131,  -286,   112,   112,
     112,   112,   112,  -286,  -286,    33,    33,   423,   425,   373,
     375,  -286,  -286,   414,   446,   436,   460,  -286,  -286,   366,
     259,   264,   435,   438,   439,   172,   295,   153,  -286,   522,
     524,   530,   532,   433,   433,   236,   236,  -286,  -286,  -286,
    -286,   462,   464,  -286,     5,  -286,     9,   486,   493,   172,
     182,  -286,    10,  -286,    17,  -286,   112,   112,   466,   500,
     501,   496,  -286,  -286,   172,   172,   497,   502,   509,   372,
     479,   481,   490,   172,  -286,   131,   131,  -286,  -286,  -286,
    -286,    33,    33,   538,   527,   540,   529,   541,    19,  -286,
     547,   488,   493,   224,   546,  -286,   182,   182,   549,   550,
     563,   214,   570,   568,   572,   571,   377,   382,  -286,  -286,
    -286,   573,   389,   356,   172,   172,   172,   555,   172,   172,
     172,   172,   172,   575,   582,   583,   405,  -286,  -286,   579,
     580,  -286,  -286,  -286,  -286,   581,   584,  -286,   588,   586,
    -286,  -286,   573,   491,     0,   182,   182,   182,  -286,   182,
     182,   182,   182,  -286,  -286,  -286,  -286,  -286,  -286,   585,
     587,  -286,   412,   289,   294,   591,   564,   564,   356,   356,
    -286,  -286,  -286,  -286,   566,    33,    33,   155,  -286,   589,
    -286,   590,  -286,   417,   308,   333,   569,     0,     0,  -286,
     573,  -286,  -286,   172,   172,  -286,   595,   593,   594,   155,
     155,  -286,  -286,   551,   239,  -286,   597,  -286,  -286,   182,
     182,   182,  -286,   422,   428,  -286,  -286,  -286,   338,   109,
    -286,   172,   172,   172,   172,   172,   596,   600,   155,   155,
     598,   495,   499,   507,  -286,  -286,  -286,   314,   314,   314,
     314,   314,   604,  -286,  -286,   592,   601,  -286,  -286,  -286,
     603,   157,  -286,    -5,   172,   604,   602,  -286,   599,   608,
     607,  -286,   314,  -286,   610,   561,  -286,    18,   120,  -286,
    -286,   615,  -286,   605,   606,   609,   172,  -286,   305,   611,
     612,     3,  -286,  -286,   617,   618,   619,   445,   613,   614,
     616,   172,    29,   120,   172,   172,   172,   228,   228,  -286,
    -286,  -286,   620,   621,   622,   623,   451,  -286,   624,   626,
    -286,   314,   314,   314,  -286,  -286,   625,  -286,  -286,  -286,
     627,   628,    27,  -286,   631,  -286,   629,   205,   624,  -286,
    -286,  -286,   630,  -286,  -286,   205,   205,   637,   638,   639,
     519,  -286,   573,   456,   361,   205,   205,   205,   205,   205,
     205,   205,   205,   640,  -286,   461,   299,   304,   632,   632,
     361,   361,  -286,  -286,  -286,   205,   205,   468,   484,  -286,
    -286
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,   146,   145,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
      50,    49,   131,   133,     0,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,    65,    66,     0,     0,     0,     0,     0,    52,
       5,    57,    58,   144,   143,   142,   132,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,    56,    55,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     4,   152,     0,
       0,     0,   166,   171,   170,     0,     0,     0,   163,     0,
       0,     0,     0,   157,   156,   154,   155,   153,   136,   134,
     135,     0,     0,    68,     0,    71,     0,     0,     0,     0,
       0,    60,     0,    63,     0,   151,     0,     0,     0,     0,
       0,    21,    19,    20,     0,     0,     0,     0,     0,     0,
     173,     0,     0,     0,   159,     0,     0,   160,   158,   161,
     162,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    96,     0,     7,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   169,
     168,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   164,     0,
       0,    69,    67,    72,    70,     0,     0,    77,     0,     0,
      97,    54,     0,     0,    10,     0,     0,     0,    53,     0,
       0,     0,     0,    61,    59,    64,    62,   148,   149,    47,
       0,    23,     0,     0,     0,     0,    25,    28,    26,    27,
      29,   177,   176,   175,     0,     0,     0,     0,    75,     0,
      95,     0,     9,     0,     0,     0,    13,    11,    12,    14,
       0,    22,    30,     0,     0,   167,     0,     0,     0,     0,
       0,    83,    84,     0,     0,    85,     0,     8,    15,     0,
       0,     0,    48,     0,     0,   174,   139,   140,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    88,    90,    92,    91,
      93,    94,     0,    79,    86,    87,     0,    16,    17,    18,
       0,     0,    80,     0,     0,     0,     0,    99,   100,     0,
       0,   102,    82,    81,     0,     0,   104,     0,     0,    78,
     101,     0,   103,   115,     0,     0,     0,   108,     0,     0,
     106,     0,   112,   105,     0,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     118,   117,     0,     0,     0,     0,     0,   126,     0,     0,
     107,   109,   111,   110,   114,   113,     0,   124,   123,   122,
       0,     0,     0,   127,     0,   116,     0,     0,     0,   125,
      98,   121,    35,    33,    34,     0,     0,     0,     0,     0,
     129,   128,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    39,    42,
      40,    41,    43,    36,    44,     0,     0,     0,     0,    45,
      46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -286,  -286,  -286,  -193,  -125,  -224,  -241,  -286,   633,  -286,
     635,   641,   636,   634,  -286,   642,  -286,  -286,   643,  -286,
     645,  -286,  -286,   552,  -286,   441,  -286,   275,  -285,  -286,
     644,   447,  -286,  -286,   266,  -286,   260,  -286,  -286,   -46,
    -286,  -286,   212,   -10,  -286,  -104,    82,   -19,  -286,   180,
     185
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,    11,    12,   201,   303,   440,   260,    13,    35,    36,
      14,    15,    37,    38,   152,    39,   154,    29,    30,   144,
      31,   146,    69,    70,   188,   189,   351,   352,   304,   305,
      71,   191,   192,   360,   361,   367,   379,   380,   381,   382,
     409,   422,   423,    16,    17,   141,    18,    59,    60,   127,
     128
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       169,   281,   142,   243,   244,    63,    64,    42,   357,   358,
       1,     2,     3,   183,   319,   320,     4,   185,   202,   394,
     395,   396,    27,    28,   193,   204,   371,    80,   187,   249,
      87,    88,   252,   397,   398,   428,   138,   139,   140,   212,
     213,    19,   407,   344,   345,     5,     6,    21,   226,   312,
      22,   359,   283,   284,   285,    23,   286,   287,   288,   289,
       9,    10,   184,     1,     2,     3,   186,   203,   117,     4,
     119,   120,   121,    24,   205,   372,   236,   229,   230,   133,
     134,   135,   136,   137,   429,   408,    20,    43,    25,   262,
     263,   264,    26,   266,   267,   268,   269,   270,     5,     6,
      32,    47,     7,    33,    34,     7,     8,     2,     3,    44,
      45,    46,     4,     9,    10,     8,   331,   332,   333,   336,
      61,    49,    62,   373,   374,   375,    83,    84,    85,   376,
     328,   329,    65,   377,   122,   123,   124,   206,   207,    66,
     125,     5,     6,    50,    28,    51,    52,    53,    54,    55,
      27,   378,    56,    57,    58,    76,     9,    10,   161,   162,
     163,    77,   126,   174,   299,   355,    32,   356,   313,   314,
      86,   297,   298,    34,   318,   161,   162,   163,   300,   301,
     302,   164,    33,   175,   176,   194,   165,   195,   166,   167,
     168,   196,    44,    45,    46,    89,   337,   338,   339,   340,
     341,   453,    90,   165,    91,   166,   167,   168,   432,   433,
     434,   443,   444,   197,   435,   198,   199,   200,    67,    68,
     248,   455,   456,   457,   458,   459,   460,   461,   462,   362,
     241,   373,   374,   375,    74,    75,   436,   376,   437,   438,
     439,   467,   468,   249,   250,   251,   252,   326,   103,   327,
      92,   387,   218,   219,   220,   221,   222,   105,   104,   378,
     328,   329,   106,   107,    98,    99,   406,   156,   102,   411,
     412,   413,   157,   129,   130,   131,   132,    98,    99,   100,
     101,   102,    98,    99,   100,   101,   102,    98,    99,   100,
     101,   102,    98,    99,   100,   101,   102,   293,   170,   171,
     172,    93,   294,   108,   173,    33,    34,   465,   388,   389,
     390,    94,   466,   109,   391,    95,   310,   218,   219,   220,
     221,   222,   218,   219,   220,   221,   222,   448,   449,   450,
     451,   452,   448,   449,   450,   451,   452,   249,   250,   251,
     252,   311,   218,   219,   220,   221,   222,   110,   261,    44,
      45,   414,   415,    97,   321,   322,   323,   324,   325,   118,
     227,   228,   249,   250,   251,   252,   218,   219,   220,   221,
     222,    98,    99,   100,   101,   102,   155,    98,    99,   100,
     101,   102,   217,    96,   218,   219,    68,   257,   222,   448,
     449,    67,   258,   452,    98,    99,   100,   101,   102,   261,
     218,   219,   220,   221,   222,    98,    99,   100,   101,   102,
      98,    99,   100,   101,   102,   274,   113,   218,   219,   220,
     221,   222,   292,   114,   115,   116,   143,   308,   145,   147,
     149,   148,   334,   218,   219,   220,   221,   222,   335,   151,
     218,   219,   220,   221,   222,   309,   249,   250,   251,   252,
     218,   219,   220,   221,   222,   402,   218,   219,   220,   221,
     222,   420,   150,   153,   158,   102,   454,   159,   160,   208,
     181,   464,   182,   218,   219,   220,   221,   222,   469,   218,
     219,   220,   221,   222,   448,   449,   450,   451,   452,   448,
     449,   450,   451,   452,   470,   187,   448,   449,   450,   451,
     452,   282,   190,   209,   210,   347,   214,   211,   223,   348,
     224,   215,   448,   449,   450,   451,   452,   349,   216,   225,
     249,   250,   251,   252,   249,   250,   251,   252,   249,   250,
     251,   252,   177,   232,   178,   234,   249,   250,   251,   252,
     179,   231,   180,   233,   235,   239,    48,   448,   449,   450,
     451,   452,   175,   176,   175,   176,   238,   242,   245,   246,
     175,   176,   175,   176,    44,    45,    46,   321,   322,   323,
     324,   325,   247,   253,   254,   255,   259,   256,   271,   218,
     219,   220,   221,   222,   265,   272,   273,   275,   276,   277,
     278,   279,   280,   290,   295,   296,   222,   306,   315,   291,
     330,   252,   307,   316,   317,   342,   343,   350,   346,   353,
     354,   366,   364,   328,   365,   368,   369,   359,   383,   392,
     399,   400,   401,   112,   417,   418,   419,   421,   425,   237,
     363,   370,   431,   393,   384,   385,   424,   430,   386,   240,
     441,   442,   403,   404,   427,   405,   445,   446,   447,   416,
      41,     0,   463,   410,     0,    40,   426,     0,     0,     0,
       0,     0,     0,     0,   452,     0,     0,     0,     0,    79,
       0,    78,     0,    82,    73,    72,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
       125,   242,   106,   196,   197,    24,    25,    17,    13,    14,
       3,     4,     5,     8,   299,   300,     9,     8,     8,    16,
      17,    18,    49,    50,   149,     8,     8,    37,     9,    29,
      49,    50,    32,    30,    31,     8,     3,     4,     5,   164,
     165,    16,    13,   328,   329,    38,    39,     9,   173,   290,
      16,    56,   245,   246,   247,    16,   249,   250,   251,   252,
      53,    54,    57,     3,     4,     5,    57,    57,    78,     9,
      89,    90,    91,     9,    57,    57,    57,   181,   182,    98,
      99,   100,   101,   102,    57,    56,     4,     6,     9,   214,
     215,   216,     0,   218,   219,   220,   221,   222,    38,    39,
      44,    19,    45,    47,    48,    45,    46,     4,     5,    28,
      29,    30,     9,    53,    54,    46,   309,   310,   311,    10,
       5,     9,     5,     3,     4,     5,    44,    45,    46,     9,
      21,    22,    16,    13,     3,     4,     5,   156,   157,    16,
       9,    38,    39,    31,    50,    33,    34,    35,    36,    37,
      49,    31,    40,    41,    42,    16,    53,    54,     3,     4,
       5,    16,    31,    10,     9,     8,    44,    10,   293,   294,
       6,   275,   276,    48,   299,     3,     4,     5,    23,    24,
      25,     9,    47,    30,    31,     3,    31,     5,    33,    34,
      35,     9,    28,    29,    30,     9,   321,   322,   323,   324,
     325,   442,     9,    31,     9,    33,    34,    35,     3,     4,
       5,   435,   436,    31,     9,    33,    34,    35,    51,    52,
       6,   445,   446,   447,   448,   449,   450,   451,   452,   354,
       6,     3,     4,     5,    26,    27,    31,     9,    33,    34,
      35,   465,   466,    29,    30,    31,    32,     8,     6,    10,
       9,   376,    28,    29,    30,    31,    32,     8,     6,    31,
      21,    22,     8,    56,    28,    29,   391,     8,    32,   394,
     395,   396,     8,    93,    94,    95,    96,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,     8,     3,     4,
       5,     9,     8,    56,     9,    47,    48,     8,     3,     4,
       5,     9,     8,    16,     9,     9,     8,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    29,    30,    31,
      32,     8,    28,    29,    30,    31,    32,    16,    10,    28,
      29,   397,   398,    10,    16,    17,    18,    19,    20,    10,
     175,   176,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,    28,    29,    30,
      31,    32,    10,     9,    28,    29,    52,    10,    32,    28,
      29,    51,    10,    32,    28,    29,    30,    31,    32,    10,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,     3,    28,    29,    30,
      31,    32,    10,     3,    56,    56,     3,    10,     3,    56,
      16,    56,    10,    28,    29,    30,    31,    32,    10,     3,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,    28,    29,    30,    31,
      32,    10,    16,     3,    29,    32,    10,    29,    29,     3,
       8,    10,     8,    28,    29,    30,    31,    32,    10,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    10,     9,    28,    29,    30,    31,
      32,    10,     9,     3,     3,    10,     9,    11,    29,    10,
      29,     9,    28,    29,    30,    31,    32,    10,     9,    29,
      29,    30,    31,    32,    29,    30,    31,    32,    29,    30,
      31,    32,    10,     6,    10,     6,    29,    30,    31,    32,
      10,     3,    10,     3,     3,    57,    10,    28,    29,    30,
      31,    32,    30,    31,    30,    31,     9,    11,     9,     9,
      30,    31,    30,    31,    28,    29,    30,    16,    17,    18,
      19,    20,     9,     3,     6,     3,     3,     6,     3,    28,
      29,    30,    31,    32,    29,     3,     3,     8,     8,     8,
       6,     3,     6,     8,     3,    29,    32,     8,     3,    12,
       3,    32,    12,    10,    10,     9,     6,     3,    10,     8,
       7,     3,    10,    21,    15,     8,     6,    56,     3,     8,
       3,     3,     3,    71,     3,     3,     3,     3,     3,   188,
     355,   365,     3,    21,    29,    29,    10,     6,    29,   192,
     428,    11,    29,    29,    16,    29,     9,     9,     9,    29,
      15,    -1,    12,   393,    -1,    14,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    36,
      -1,    35,    -1,    39,    31,    30,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,     3,     4,     5,     9,    38,    39,    45,    46,    53,
      54,    59,    60,    65,    68,    69,   101,   102,   104,    16,
     104,     9,    16,    16,     9,     9,     0,    49,    50,    75,
      76,    78,    44,    47,    48,    66,    67,    70,    71,    73,
      69,    68,   101,     6,    28,    29,    30,   104,    10,     9,
      31,    33,    34,    35,    36,    37,    40,    41,    42,   105,
     106,     5,     5,   105,   105,    16,    16,    51,    52,    80,
      81,    88,    78,    76,    26,    27,    16,    16,    70,    66,
     101,    73,    71,   104,   104,   104,     6,   105,   105,     9,
       9,     9,     9,     9,     9,     9,     9,    10,    28,    29,
      30,    31,    32,     6,     6,     8,     8,    56,    56,    16,
      16,    88,    81,     3,     3,    56,    56,   101,    10,   105,
     105,   105,     3,     4,     5,     9,    31,   107,   108,   107,
     107,   107,   107,   105,   105,   105,   105,   105,     3,     4,
       5,   103,   103,     3,    77,     3,    79,    56,    56,    16,
      16,     3,    72,     3,    74,    10,     8,     8,    29,    29,
      29,     3,     4,     5,     9,    31,    33,    34,    35,    62,
       3,     4,     5,     9,    10,    30,    31,    10,    10,    10,
      10,     8,     8,     8,    57,     8,    57,     9,    82,    83,
       9,    89,    90,    62,     3,     5,     9,    31,    33,    34,
      35,    61,     8,    57,     8,    57,   105,   105,     3,     3,
       3,    11,    62,    62,     9,     9,     9,    10,    28,    29,
      30,    31,    32,    29,    29,    29,    62,   108,   108,   103,
     103,     3,     6,     3,     6,     3,    57,    83,     9,    57,
      89,     6,    11,    61,    61,     9,     9,     9,     6,    29,
      30,    31,    32,     3,     6,     3,     6,    10,    10,     3,
      64,    10,    62,    62,    62,    29,    62,    62,    62,    62,
      62,     3,     3,     3,    10,     8,     8,     8,     6,     3,
       6,    64,    10,    61,    61,    61,    61,    61,    61,    61,
       8,    12,    10,     8,     8,     3,    29,   103,   103,     9,
      23,    24,    25,    62,    86,    87,     8,    12,    10,    28,
       8,     8,    64,    62,    62,     3,    10,    10,    62,    86,
      86,    16,    17,    18,    19,    20,     8,    10,    21,    22,
       3,    61,    61,    61,    10,    10,    10,    62,    62,    62,
      62,    62,     9,     6,    86,    86,    10,    10,    10,    10,
       3,    84,    85,     8,     7,     8,    10,    13,    14,    56,
      91,    92,    62,    85,    10,    15,     3,    93,     8,     6,
      92,     8,    57,     3,     4,     5,     9,    13,    31,    94,
      95,    96,    97,     3,    29,    29,    29,    62,     3,     4,
       5,     9,     8,    21,    16,    17,    18,    30,    31,     3,
       3,     3,    10,    29,    29,    29,    62,    13,    56,    98,
      94,    62,    62,    62,    97,    97,    29,     3,     3,     3,
      10,     3,    99,   100,    10,     3,    29,    16,     8,    57,
       6,     3,     3,     4,     5,     9,    31,    33,    34,    35,
      63,   100,    11,    63,    63,     9,     9,     9,    28,    29,
      30,    31,    32,    64,    10,    63,    63,    63,    63,    63,
      63,    63,    63,    12,    10,     8,     8,    63,    63,    10,
      10
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
     305,   306,   307,   308,   309,   310,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    70,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    88,    89,    89,    90,    91,
      91,    91,    91,    92,    93,    93,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     101,   101,   102,   102,   103,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Lha_parser::yyr2_[] =
  {
         0,     2,     3,     1,     4,     3,     1,     1,     4,     3,
       2,     3,     3,     3,     3,     4,     6,     6,     6,     1,
       1,     1,     4,     3,     2,     3,     3,     3,     3,     3,
       4,     6,     6,     1,     1,     1,     4,     3,     2,     3,
       3,     3,     3,     3,     4,     6,     6,     1,     3,     2,
       2,     1,     2,     6,     6,     4,     4,     2,     2,     6,
       1,     3,     6,     1,     3,     2,     2,     6,     1,     3,
       6,     1,     3,     2,     2,     6,     1,     2,    10,     6,
       1,     3,     3,     1,     1,     1,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     6,     1,     2,    14,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     5,     3,     3,     3,
       2,     6,     4,     4,     4,     3,     1,     1,     3,     3,
       1,     2,     4,     2,     1,     1,     1,     4,     1,    10,
      10,     3,     3,     3,     3,     1,     1,     1,     6,     6,
       2,     4,     3,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     1,     3,     3,     1,     5,     3,     3,
       1,     1,     3,     2,     6,     4,     4,     4
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Lha_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "str", "rval", "ival",
  "SEMICOLON", "COLON", "COMMA", "LB", "RB", "LSB", "RSB", "SHARP", "ALL",
  "BackSlash", "EQ", "GEQ", "LEQ", "LL", "GG", "AND", "OR", "NOT", "TRUE",
  "FALSE", "DOUBLE", "INT", "DIV", "MUL", "PLUS", "MINUS", "POWER",
  "FLOOR", "MIN", "MAX", "LhaMIN", "LhaMAX", "AVG", "PROB", "LAST",
  "INTEGRAL", "MEAN", "LhaName", "Const", "NbLoc", "NbVar", "VList",
  "LList", "Iloc", "Floc", "locations", "edges", "PDF", "CDF", "NEG",
  "'{'", "'}'", "$accept", "LHA", "declarations", "IntMarkingFormula",
  "RealMarkingFormula", "RealVarMarkingFormula", "ColorClassList", "Sizes",
  "Constants", "Constant", "NbVariables", "NbLocations", "Lists",
  "VariablesList", "VLabels", "LocationsList", "LLabels", "InitFinal",
  "init", "iLLabels", "final", "fLLabels", "definitions", "LocationsDef",
  "LOCATIONS", "LOCATION", "FLOWS", "FLOW", "LogExpr", "CompExpr",
  "EdgesDef", "EDGES", "EDGE", "ACTIONS", "SetOfActions", "Actions",
  "CONSTRAINTS", "CONSTRAINT", "LinearExp", "term", "UPDATES", "Updates",
  "Update", "HaslExps", "HaslExp", "rorival", "TopHaslExp", "AlgExpr",
  "LhaFunc", "LinForm", "VarTerm", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Lha_parser::rhs_number_type
  Lha_parser::yyrhs_[] =
  {
        59,     0,    -1,    60,    75,    80,    -1,   101,    -1,    65,
      66,    70,   101,    -1,    65,    70,   101,    -1,     5,    -1,
       3,    -1,     3,    11,    64,    12,    -1,     9,    61,    10,
      -1,    31,    61,    -1,    61,    30,    61,    -1,    61,    31,
      61,    -1,    61,    29,    61,    -1,    61,    32,    61,    -1,
      33,     9,    61,    10,    -1,    33,     9,    61,    28,    61,
      10,    -1,    34,     9,    61,     8,    61,    10,    -1,    35,
       9,    61,     8,    61,    10,    -1,     4,    -1,     5,    -1,
       3,    -1,     3,    11,    64,    12,    -1,     9,    62,    10,
      -1,    31,    62,    -1,    62,    28,    62,    -1,    62,    30,
      62,    -1,    62,    31,    62,    -1,    62,    29,    62,    -1,
      62,    32,    62,    -1,    33,     9,    62,    10,    -1,    34,
       9,    62,     8,    62,    10,    -1,    35,     9,    62,     8,
      62,    10,    -1,     4,    -1,     5,    -1,     3,    -1,     3,
      11,    64,    12,    -1,     9,    63,    10,    -1,    31,    63,
      -1,    63,    28,    63,    -1,    63,    30,    63,    -1,    63,
      31,    63,    -1,    63,    29,    63,    -1,    63,    32,    63,
      -1,    33,     9,    63,    10,    -1,    34,     9,    63,     8,
      63,    10,    -1,    35,     9,    63,     8,    63,    10,    -1,
       3,    -1,     3,     8,    64,    -1,    69,    68,    -1,    68,
      69,    -1,    67,    -1,    67,    66,    -1,    44,    27,     3,
      16,    61,     6,    -1,    44,    26,     3,    16,    62,     6,
      -1,    46,    16,     5,     6,    -1,    45,    16,     5,     6,
      -1,    71,    73,    -1,    73,    71,    -1,    47,    16,    56,
      72,    57,     6,    -1,     3,    -1,    72,     8,     3,    -1,
      48,    16,    56,    74,    57,     6,    -1,     3,    -1,    74,
       8,     3,    -1,    76,    78,    -1,    78,    76,    -1,    49,
      16,    56,    77,    57,     6,    -1,     3,    -1,    77,     8,
       3,    -1,    50,    16,    56,    79,    57,     6,    -1,     3,
      -1,    79,     8,     3,    -1,    81,    88,    -1,    88,    81,
      -1,    51,    16,    56,    82,    57,     6,    -1,    83,    -1,
      82,    83,    -1,     9,     3,     8,    86,     8,     9,    84,
      10,    10,     6,    -1,     9,     3,     8,    86,    10,     6,
      -1,    85,    -1,    84,     8,    85,    -1,     3,     7,    62,
      -1,    24,    -1,    25,    -1,    87,    -1,    86,    21,    86,
      -1,    86,    22,    86,    -1,     9,    86,    10,    -1,    23,
      86,    -1,    62,    16,    62,    -1,    62,    18,    62,    -1,
      62,    17,    62,    -1,    62,    19,    62,    -1,    62,    20,
      62,    -1,    52,    16,    56,    89,    57,     6,    -1,    90,
      -1,    90,    89,    -1,     9,     9,     3,     8,     3,    10,
       8,    91,     8,    94,     8,    98,    10,     6,    -1,    13,
      -1,    14,    -1,    14,    15,    92,    -1,    92,    -1,    56,
      93,    57,    -1,     3,    -1,    93,     8,     3,    -1,    95,
      -1,    95,    21,    94,    -1,    13,    -1,    96,    16,    62,
      -1,    96,    18,    62,    -1,    96,    17,    62,    -1,    97,
      -1,    96,    31,    97,    -1,    96,    30,    97,    -1,     3,
      -1,     9,    62,    10,    29,     3,    -1,     5,    29,     3,
      -1,     4,    29,     3,    -1,     3,    29,     3,    -1,    31,
       3,    -1,    31,     9,    62,    10,    29,     3,    -1,    31,
       5,    29,     3,    -1,    31,     4,    29,     3,    -1,    31,
       3,    29,     3,    -1,    56,    99,    57,    -1,    13,    -1,
     100,    -1,    99,     8,   100,    -1,     3,    16,    63,    -1,
     102,    -1,   102,   101,    -1,     3,    16,   104,     6,    -1,
     104,     6,    -1,     4,    -1,     5,    -1,     3,    -1,    38,
       9,   105,    10,    -1,    39,    -1,    53,     9,   105,     8,
     103,     8,   103,     8,   103,    10,    -1,    54,     9,   105,
       8,   103,     8,   103,     8,   103,    10,    -1,     9,   104,
      10,    -1,   104,    30,   104,    -1,   104,    29,   104,    -1,
     104,    28,   104,    -1,     5,    -1,     4,    -1,   106,    -1,
      34,     9,   105,     8,   105,    10,    -1,    35,     9,   105,
       8,   105,    10,    -1,    31,   105,    -1,    33,     9,   105,
      10,    -1,     9,   105,    10,    -1,   105,    32,   105,    -1,
     105,    30,   105,    -1,   105,    31,   105,    -1,   105,    29,
     105,    -1,   105,    28,   105,    -1,    40,     9,   107,    10,
      -1,    36,     9,   107,    10,    -1,    37,     9,   107,    10,
      -1,    41,     9,   107,    10,    -1,    42,     9,   107,    10,
      -1,   108,    -1,   107,    31,   108,    -1,   107,    30,   108,
      -1,     3,    -1,     9,    62,    10,    29,     3,    -1,     5,
      29,     3,    -1,     4,    29,     3,    -1,     5,    -1,     4,
      -1,     3,    29,     3,    -1,    31,     3,    -1,    31,     9,
      62,    10,    29,     3,    -1,    31,     5,    29,     3,    -1,
      31,     4,    29,     3,    -1,    31,     3,    29,     3,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Lha_parser::yyprhs_[] =
  {
         0,     0,     3,     7,     9,    14,    18,    20,    22,    27,
      31,    34,    38,    42,    46,    50,    55,    62,    69,    76,
      78,    80,    82,    87,    91,    94,    98,   102,   106,   110,
     114,   119,   126,   133,   135,   137,   139,   144,   148,   151,
     155,   159,   163,   167,   171,   176,   183,   190,   192,   196,
     199,   202,   204,   207,   214,   221,   226,   231,   234,   237,
     244,   246,   250,   257,   259,   263,   266,   269,   276,   278,
     282,   289,   291,   295,   298,   301,   308,   310,   313,   324,
     331,   333,   337,   341,   343,   345,   347,   351,   355,   359,
     362,   366,   370,   374,   378,   382,   389,   391,   394,   409,
     411,   413,   417,   419,   423,   425,   429,   431,   435,   437,
     441,   445,   449,   451,   455,   459,   461,   467,   471,   475,
     479,   482,   489,   494,   499,   504,   508,   510,   512,   516,
     520,   522,   525,   530,   533,   535,   537,   539,   544,   546,
     557,   568,   572,   576,   580,   584,   586,   588,   590,   597,
     604,   607,   612,   616,   620,   624,   628,   632,   636,   641,
     646,   651,   656,   661,   663,   667,   671,   673,   679,   683,
     687,   689,   691,   695,   698,   705,   710,   715
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   180,   180,   181,   183,   184,   190,   191,   201,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   220,
     221,   222,   233,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   251,   252,   253,   271,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   289,   290,   292,
     293,   295,   296,   298,   305,   315,   319,   323,   324,   326,
     359,   367,   374,   381,   387,   392,   393,   395,   397,   405,
     410,   412,   420,   429,   430,   434,   441,   442,   444,   463,
     485,   486,   487,   493,   494,   495,   496,   497,   498,   499,
     501,   502,   503,   504,   505,   510,   514,   515,   517,   540,
     541,   542,   546,   548,   550,   554,   559,   560,   561,   563,
     568,   573,   579,   580,   581,   583,   587,   592,   597,   602,
     623,   627,   632,   637,   642,   665,   666,   668,   669,   671,
     677,   677,   679,   690,   703,   704,   705,   715,   719,   722,
     738,   755,   758,   761,   764,   767,   770,   774,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   788,   798,
     808,   818,   828,   839,   840,   841,   843,   853,   858,   863,
     869,   872,   875,   894,   898,   903,   908,   913
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
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 714;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 26;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 58;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 310;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2812 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 937 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
