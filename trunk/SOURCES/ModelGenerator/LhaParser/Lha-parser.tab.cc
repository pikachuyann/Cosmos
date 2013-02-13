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
          case 5:
/* Line 670 of lalr1.cc  */
#line 188 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 189 "Lha-parser.yy"
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

  case 7:
/* Line 670 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 206 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 207 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 208 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 209 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 210 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 220 "Lha-parser.yy"
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

  case 21:
/* Line 670 of lalr1.cc  */
#line 231 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 238 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 239 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 240 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 241 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 242 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 251 "Lha-parser.yy"
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

  case 35:
/* Line 670 of lalr1.cc  */
#line 269 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 276 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 277 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 278 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 279 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 280 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 281 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 288 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 297 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 304 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 313 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 317 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 324 "Lha-parser.yy"
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

  case 59:
/* Line 670 of lalr1.cc  */
#line 357 "Lha-parser.yy"
    {
	
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 365 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 372 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 379 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 385 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 395 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 403 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 410 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 418 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 432 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 443 "Lha-parser.yy"
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

  case 78:
/* Line 670 of lalr1.cc  */
#line 464 "Lha-parser.yy"
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

  case 81:
/* Line 670 of lalr1.cc  */
#line 485 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 491 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 492 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 493 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 494 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 495 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 496 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 497 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 499 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 500 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 501 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 502 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 503 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 508 "Lha-parser.yy"
    {
	
}
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 515 "Lha-parser.yy"
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

  case 99:
/* Line 670 of lalr1.cc  */
#line 539 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 540 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 548 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 552 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 557 "Lha-parser.yy"
    {}
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 558 "Lha-parser.yy"
    {}
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 562 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 567 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 572 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 114:
/* Line 670 of lalr1.cc  */
#line 582 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 586 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 591 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 596 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 601 "Lha-parser.yy"
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

  case 119:
/* Line 670 of lalr1.cc  */
#line 622 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 626 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 631 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 636 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 641 "Lha-parser.yy"
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

  case 124:
/* Line 670 of lalr1.cc  */
#line 663 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 125:
/* Line 670 of lalr1.cc  */
#line 664 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 669 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 678 "Lha-parser.yy"
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

  case 132:
/* Line 670 of lalr1.cc  */
#line 689 "Lha-parser.yy"
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

  case 133:
/* Line 670 of lalr1.cc  */
#line 702 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 703 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 704 "Lha-parser.yy"
    { if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
			(yyval.RealVal) = Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else { if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
			(yyval.RealVal) = (double)Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else {
			cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a definded constant "<<endl;
			YYABORT;
		}}}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 714 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 718 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 721 "Lha-parser.yy"
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

  case 139:
/* Line 670 of lalr1.cc  */
#line 737 "Lha-parser.yy"
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

  case 140:
/* Line 670 of lalr1.cc  */
#line 754 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 757 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 760 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 763 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 766 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 769 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 773 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 776 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 777 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 778 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 779 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 780 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 781 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 783 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 784 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 785 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 787 "Lha-parser.yy"
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

  case 158:
/* Line 670 of lalr1.cc  */
#line 797 "Lha-parser.yy"
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

  case 159:
/* Line 670 of lalr1.cc  */
#line 807 "Lha-parser.yy"
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

  case 160:
/* Line 670 of lalr1.cc  */
#line 817 "Lha-parser.yy"
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

  case 161:
/* Line 670 of lalr1.cc  */
#line 827 "Lha-parser.yy"
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

  case 162:
/* Line 670 of lalr1.cc  */
#line 838 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 839 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 840 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 843 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	} else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 850 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 855 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 860 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 169:
/* Line 670 of lalr1.cc  */
#line 865 "Lha-parser.yy"
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

  case 170:
/* Line 670 of lalr1.cc  */
#line 884 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 888 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 893 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 173:
/* Line 670 of lalr1.cc  */
#line 898 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 174:
/* Line 670 of lalr1.cc  */
#line 903 "Lha-parser.yy"
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
#line 1842 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -222;
  const short int
  Lha_parser::yypact_[] =
  {
         4,     9,    24,    11,   101,   286,    -3,    83,   147,   174,
    -222,   168,   172,   215,   157,   160,   250,   222,   229,   245,
     209,     5,   275,   299,  -222,  -222,   354,   382,   329,   341,
     383,   384,  -222,   305,   347,  -222,  -222,   410,   422,   370,
     371,     5,  -222,   412,  -222,  -222,    15,   427,  -222,   428,
     429,  -222,     5,   134,  -222,  -222,  -222,  -222,   436,   438,
     408,   409,  -222,  -222,   450,   451,   466,   473,  -222,    15,
     319,    91,    91,    91,  -222,  -222,    15,    15,    15,  -222,
      13,  -222,    19,   468,   469,   156,   177,  -222,    20,  -222,
      21,   233,  -222,    91,    91,   483,   495,   496,   499,   500,
     509,   510,   511,   340,  -222,    73,   226,  -222,  -222,   278,
     476,   524,   503,   525,   529,    -5,  -222,   533,   486,   469,
     534,  -222,  -222,   156,   156,   535,   537,   538,   241,   543,
    -222,   177,   177,   539,   546,   547,    81,   554,   552,   556,
     555,  -222,   346,   138,    91,    91,    91,   144,   144,   144,
     144,   144,  -222,    91,    91,    91,    91,    91,    29,    29,
    -222,  -222,  -222,  -222,   557,   558,  -222,   559,   560,  -222,
     564,   351,   330,   156,   156,   156,  -222,   156,   156,   156,
     156,   156,   564,   481,   246,   177,   177,   177,  -222,   177,
     177,   177,   177,  -222,  -222,  -222,  -222,  -222,   363,   252,
     257,   531,   540,   541,   156,   237,    16,  -222,    41,   175,
     191,   205,   536,   536,   138,   138,  -222,  -222,  -222,  -222,
     563,   565,   111,  -222,   566,  -222,   567,   551,  -222,   374,
     266,   271,   544,   544,   330,   330,  -222,   568,  -222,   379,
     308,   312,   545,   246,   246,  -222,  -222,    91,    91,   569,
     575,   576,   386,   553,   561,   562,   156,  -222,   144,   144,
    -222,  -222,  -222,  -222,    29,    29,   111,   111,  -222,  -222,
     521,   133,  -222,   578,   564,  -222,  -222,   156,   156,  -222,
    -222,   177,   177,   177,   391,   402,  -222,  -222,  -222,   570,
     580,   581,   582,   414,  -222,  -222,   579,   584,   335,    96,
    -222,   156,   156,   156,   156,   156,   577,   583,   111,   111,
     585,  -222,   419,   425,   493,   497,   504,  -222,  -222,   590,
    -222,  -222,  -222,   571,    29,    29,  -222,   167,   167,   167,
     167,   167,   591,  -222,  -222,   586,   588,  -222,  -222,  -222,
    -222,  -222,  -222,   594,   592,   593,   597,   113,  -222,    -1,
    -222,  -222,  -222,   156,   591,   595,  -222,   573,   598,   600,
    -222,   167,  -222,   603,   542,  -222,    22,    32,  -222,  -222,
     607,  -222,   587,   589,   596,   156,  -222,   512,   604,   599,
     301,  -222,  -222,   608,   610,   611,   430,   601,   602,   605,
     156,    35,    32,   156,   156,   156,   228,   228,  -222,  -222,
    -222,   606,   612,   614,   616,   442,  -222,   618,   613,  -222,
     167,   167,   167,  -222,  -222,   619,  -222,  -222,  -222,   609,
     617,    23,  -222,   620,  -222,   621,   169,   618,  -222,  -222,
    -222,   625,  -222,  -222,   169,   169,   623,   628,   630,   220,
    -222,   564,   453,   358,   169,   169,   169,   169,   169,   169,
     169,   169,   615,  -222,   458,   283,   296,   574,   574,   358,
     358,  -222,  -222,  -222,   169,   169,   465,   470,  -222,  -222
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,     0,    49,    48,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    64,    65,     0,     0,     0,
       0,     0,    51,     0,   145,   144,     0,     0,   137,     0,
       0,     4,   129,     0,    56,    57,    55,    54,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,   130,   132,     0,     0,     0,    67,
       0,    70,     0,     0,     0,     0,     0,    59,     0,    62,
       0,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,   143,   142,   141,
       0,     0,     0,     0,     0,     0,    75,     0,     0,    95,
      20,    18,    19,     0,     0,     0,     0,     0,     0,     6,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   149,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
      68,    66,    71,    69,     0,     0,    76,     0,     0,    96,
       0,     0,    23,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,     0,    52,     0,
       0,     0,     0,    60,    58,    63,    61,   151,     0,     0,
       0,   165,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,   156,   155,   153,   154,   152,   135,   133,   134,
       0,     0,     0,    74,     0,    94,    46,     0,    22,     0,
       0,     0,    24,    27,    25,    26,    28,     0,     8,     0,
       0,     0,    12,    10,    11,    13,   150,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,   158,     0,     0,
     159,   157,   160,   161,     0,     0,     0,     0,    82,    83,
       0,     0,    84,     0,     0,    21,    29,     0,     0,     7,
      14,     0,     0,     0,     0,     0,   169,   168,   167,     0,
       0,     0,     0,     0,   164,   163,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,   147,   148,     0,
     174,   173,   172,     0,     0,     0,    87,    89,    91,    90,
      92,    93,     0,    78,    85,    86,     0,    30,    31,    15,
      16,    17,   166,     0,     0,     0,     0,     0,    79,     0,
     171,   138,   139,     0,     0,     0,    98,    99,     0,     0,
     101,    81,    80,     0,     0,   103,     0,     0,    77,   100,
       0,   102,   114,     0,     0,     0,   107,     0,     0,   105,
       0,   111,   104,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   117,
     116,     0,     0,     0,     0,     0,   125,     0,     0,   106,
     108,   110,   109,   113,   112,     0,   123,   122,   121,     0,
       0,     0,   126,     0,   115,     0,     0,     0,   124,    97,
     120,    34,    32,    33,     0,     0,     0,     0,     0,   128,
     127,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,     0,    38,    41,    39,
      40,    42,    35,    43,     0,     0,     0,     0,    44,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -222,  -222,  -222,  -125,   -85,  -221,  -177,  -222,   622,  -222,
     633,   635,   624,   626,  -222,   629,  -222,  -222,   631,  -222,
     634,  -222,  -222,   627,  -222,   513,  -222,   290,  -210,  -222,
     632,   526,  -222,  -222,   265,  -222,   255,  -222,  -222,   -75,
    -222,  -222,   223,   142,  -222,  -156,    61,   -71,  -222,  -133,
      77
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   136,   270,   439,   227,     5,    19,    20,
       6,     7,    21,    22,    88,    23,    90,    13,    14,    80,
      15,    82,    32,    33,   115,   116,   347,   348,   271,   272,
      34,   118,   119,   359,   360,   366,   378,   379,   380,   381,
     408,   421,   422,    51,    52,   220,    53,   103,   104,   206,
     207
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       128,   105,   106,   221,   114,   237,   183,   184,    43,    44,
      45,    10,   356,   357,    46,   208,   209,   210,   211,    44,
      45,   110,   142,   143,    46,     8,   257,   112,   137,   139,
     370,   427,   217,   218,   219,   372,   373,   374,   171,   172,
       9,   375,     1,    47,    48,   376,   258,   259,   406,     1,
       2,   260,   165,    47,    48,   358,   299,   300,    49,    50,
     239,   240,   241,   377,   242,   243,   244,   245,    49,    50,
     111,   258,   259,   198,   199,   200,   113,   138,   140,   371,
     428,   158,   212,   213,   214,   215,   216,   188,   229,   230,
     231,   407,   232,   233,   234,   235,   236,   311,   334,   335,
      93,   153,   154,   155,   156,   157,   326,    70,   296,   297,
     189,   190,   191,   192,   120,   121,   122,   308,   309,   252,
     266,   354,    94,   355,    95,    96,    97,    98,    99,     2,
      91,   100,   101,   102,   267,   268,   269,   107,   108,   109,
      75,   306,   124,   307,   125,   126,   127,   201,   202,   203,
      11,    12,    26,   204,   308,   309,   314,   315,   316,   120,
     121,   122,    76,    77,    78,   123,   153,   154,   344,   345,
     157,   293,   431,   432,   433,   205,   284,   285,   434,    27,
     129,   298,   130,    68,    28,   261,   131,   124,    29,   125,
     126,   127,   312,   313,    74,   177,   178,   179,   180,   181,
     435,   262,   436,   437,   438,   258,   259,    12,   132,    11,
     133,   134,   135,   442,   443,   263,   327,   328,   329,   330,
     331,   258,   259,   454,   455,   456,   457,   458,   459,   460,
     461,   372,   373,   374,   159,   258,   259,   375,    39,   141,
     253,   254,   255,   466,   467,    40,   256,   176,   447,   448,
     449,   450,   451,    16,   153,   154,   155,   156,   157,   377,
     247,    76,    77,    78,   452,   248,    30,    31,   361,   177,
     178,   179,   180,   181,   277,   189,    37,    38,   192,   278,
     153,   154,   155,   156,   157,   153,   154,   155,   156,   157,
     386,   464,    17,    18,   177,   178,   179,   180,   181,   177,
     178,   179,   180,   181,   465,   405,    76,    77,   410,   411,
     412,   447,   448,   449,   450,   451,   282,   393,   394,   395,
     283,   413,   414,    18,   447,   448,   449,   450,   451,    92,
      16,   396,   397,    17,    18,   294,   295,   189,   190,   191,
     192,   189,   190,   191,   192,   228,    17,    76,    77,    78,
     152,   301,   302,   303,   304,   305,   197,    31,   177,   178,
      56,   228,   181,   177,   178,   179,   180,   181,   153,   154,
     155,   156,   157,   246,   153,   154,   155,   156,   157,   177,
     178,   179,   180,   181,   276,    58,   447,   448,    57,   280,
     451,   153,   154,   155,   156,   157,   289,    59,    30,    60,
      61,   317,   177,   178,   179,   180,   181,   281,   189,   190,
     191,   192,   318,    64,   177,   178,   179,   180,   181,   153,
     154,   155,   156,   157,   323,    65,    66,    67,    69,   337,
     153,   154,   155,   156,   157,   338,    71,    72,    73,    79,
     401,    81,   177,   178,   179,   180,   181,   177,   178,   179,
     180,   181,   419,   177,   178,   179,   180,   181,   177,   178,
     179,   180,   181,   453,    83,    84,    85,    86,   463,    87,
     177,   178,   179,   180,   181,   468,    89,   114,   117,   160,
     469,   447,   448,   449,   450,   451,   447,   448,   449,   450,
     451,   238,   144,   447,   448,   449,   450,   451,   447,   448,
     449,   450,   451,   339,   145,   146,   162,   340,   147,   148,
     189,   190,   191,   192,   341,   387,   388,   389,   149,   150,
     151,   390,   189,   190,   191,   192,   189,   190,   191,   192,
     161,   163,   164,   189,   190,   191,   192,   301,   302,   303,
     304,   305,   167,   168,   173,   170,   174,   175,   185,   177,
     178,   179,   180,   181,   182,   186,   187,   193,   194,   195,
     249,   196,   224,   275,   223,   222,   225,   226,   157,   250,
     251,   264,   286,   265,   273,   274,   181,   192,   287,   288,
     279,   310,   290,   320,   321,   322,   332,   324,   364,   333,
     291,   292,   325,   342,   346,   336,   349,   350,   358,   319,
     343,   365,   351,   352,   353,   363,   451,   308,   367,   368,
     382,   398,   391,   399,   400,   416,   383,   417,   384,   418,
     392,   420,   424,   423,   430,   385,   429,   462,   166,   369,
     402,   403,   444,   426,   404,   415,   441,   445,   425,   446,
      25,    24,    42,    41,   362,   169,    36,   409,    35,    55,
     440,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,    62
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        85,    72,    73,   159,     9,   182,   131,   132,     3,     4,
       5,     0,    13,    14,     9,   148,   149,   150,   151,     4,
       5,     8,    93,    94,     9,    16,    10,     8,     8,     8,
       8,     8,     3,     4,     5,     3,     4,     5,   123,   124,
      16,     9,    45,    38,    39,    13,    30,    31,    13,    45,
      46,    10,    57,    38,    39,    56,   266,   267,    53,    54,
     185,   186,   187,    31,   189,   190,   191,   192,    53,    54,
      57,    30,    31,   144,   145,   146,    57,    57,    57,    57,
      57,     8,   153,   154,   155,   156,   157,     6,   173,   174,
     175,    56,   177,   178,   179,   180,   181,   274,   308,   309,
       9,    28,    29,    30,    31,    32,    10,    46,   264,   265,
      29,    30,    31,    32,     3,     4,     5,    21,    22,   204,
       9,     8,    31,    10,    33,    34,    35,    36,    37,    46,
      69,    40,    41,    42,    23,    24,    25,    76,    77,    78,
       6,     8,    31,    10,    33,    34,    35,     3,     4,     5,
      49,    50,     5,     9,    21,    22,   281,   282,   283,     3,
       4,     5,    28,    29,    30,     9,    28,    29,   324,   325,
      32,   256,     3,     4,     5,    31,   247,   248,     9,     5,
       3,   266,     5,    41,    16,    10,     9,    31,    16,    33,
      34,    35,   277,   278,    52,    28,    29,    30,    31,    32,
      31,    10,    33,    34,    35,    30,    31,    50,    31,    49,
      33,    34,    35,   434,   435,    10,   301,   302,   303,   304,
     305,    30,    31,   444,   445,   446,   447,   448,   449,   450,
     451,     3,     4,     5,     8,    30,    31,     9,    16,     6,
       3,     4,     5,   464,   465,    16,     9,     6,    28,    29,
      30,    31,    32,    44,    28,    29,    30,    31,    32,    31,
       8,    28,    29,    30,   441,     8,    51,    52,   353,    28,
      29,    30,    31,    32,     8,    29,    26,    27,    32,     8,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
     375,     8,    47,    48,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,     8,   390,    28,    29,   393,   394,
     395,    28,    29,    30,    31,    32,     8,    16,    17,    18,
       8,   396,   397,    48,    28,    29,    30,    31,    32,    10,
      44,    30,    31,    47,    48,   258,   259,    29,    30,    31,
      32,    29,    30,    31,    32,    10,    47,    28,    29,    30,
      10,    16,    17,    18,    19,    20,    10,    52,    28,    29,
       6,    10,    32,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    10,    56,    28,    29,     6,    10,
      32,    28,    29,    30,    31,    32,    10,    56,    51,    16,
      16,    10,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    10,     3,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    10,     3,    56,    56,    16,    10,
      28,    29,    30,    31,    32,    10,     9,     9,     9,     3,
      10,     3,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    10,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,    56,    56,    16,    16,    10,     3,
      28,    29,    30,    31,    32,    10,     3,     9,     9,     3,
      10,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    10,     9,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,     9,     9,     3,    10,     9,     9,
      29,    30,    31,    32,    10,     3,     4,     5,     9,     9,
       9,     9,    29,    30,    31,    32,    29,    30,    31,    32,
       6,     6,     3,    29,    30,    31,    32,    16,    17,    18,
      19,    20,     9,    57,     9,    11,     9,     9,     9,    28,
      29,    30,    31,    32,    11,     9,     9,     3,     6,     3,
      29,     6,     3,    12,     6,     8,     6,     3,    32,    29,
      29,     8,     3,     8,     8,     8,    32,    32,     3,     3,
      12,     3,    29,     3,     3,     3,     9,     8,    15,     6,
      29,    29,     8,     3,     3,    10,     8,     3,    56,    29,
      29,     3,    10,    10,     7,    10,    32,    21,     8,     6,
       3,     3,     8,     3,     3,     3,    29,     3,    29,     3,
      21,     3,     3,    10,     3,    29,     6,    12,   115,   364,
      29,    29,     9,    16,    29,    29,    11,     9,    29,     9,
       7,     6,    20,    19,   354,   119,    15,   392,    14,    23,
     427,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    33
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    45,    46,    59,    60,    65,    68,    69,    16,    16,
       0,    49,    50,    75,    76,    78,    44,    47,    48,    66,
      67,    70,    71,    73,    69,    68,     5,     5,    16,    16,
      51,    52,    80,    81,    88,    78,    76,    26,    27,    16,
      16,    70,    66,     3,     4,     5,     9,    38,    39,    53,
      54,   101,   102,   104,    73,    71,     6,     6,    56,    56,
      16,    16,    88,    81,     3,     3,    56,    56,   101,    16,
     104,     9,     9,     9,   101,     6,    28,    29,    30,     3,
      77,     3,    79,    56,    56,    16,    16,     3,    72,     3,
      74,   104,    10,     9,    31,    33,    34,    35,    36,    37,
      40,    41,    42,   105,   106,   105,   105,   104,   104,   104,
       8,    57,     8,    57,     9,    82,    83,     9,    89,    90,
       3,     4,     5,     9,    31,    33,    34,    35,    62,     3,
       5,     9,    31,    33,    34,    35,    61,     8,    57,     8,
      57,     6,   105,   105,     9,     9,     9,     9,     9,     9,
       9,     9,    10,    28,    29,    30,    31,    32,     8,     8,
       3,     6,     3,     6,     3,    57,    83,     9,    57,    89,
      11,    62,    62,     9,     9,     9,     6,    28,    29,    30,
      31,    32,    11,    61,    61,     9,     9,     9,     6,    29,
      30,    31,    32,     3,     6,     3,     6,    10,   105,   105,
     105,     3,     4,     5,     9,    31,   107,   108,   107,   107,
     107,   107,   105,   105,   105,   105,   105,     3,     4,     5,
     103,   103,     8,     6,     3,     6,     3,    64,    10,    62,
      62,    62,    62,    62,    62,    62,    62,    64,    10,    61,
      61,    61,    61,    61,    61,    61,    10,     8,     8,    29,
      29,    29,    62,     3,     4,     5,     9,    10,    30,    31,
      10,    10,    10,    10,     8,     8,     9,    23,    24,    25,
      62,    86,    87,     8,     8,    12,    10,     8,     8,    12,
      10,    28,     8,     8,   105,   105,     3,     3,     3,    10,
      29,    29,    29,    62,   108,   108,   103,   103,    62,    86,
      86,    16,    17,    18,    19,    20,     8,    10,    21,    22,
       3,    64,    62,    62,    61,    61,    61,    10,    10,    29,
       3,     3,     3,    10,     8,     8,    10,    62,    62,    62,
      62,    62,     9,     6,    86,    86,    10,    10,    10,    10,
      10,    10,     3,    29,   103,   103,     3,    84,    85,     8,
       3,    10,    10,     7,     8,    10,    13,    14,    56,    91,
      92,    62,    85,    10,    15,     3,    93,     8,     6,    92,
       8,    57,     3,     4,     5,     9,    13,    31,    94,    95,
      96,    97,     3,    29,    29,    29,    62,     3,     4,     5,
       9,     8,    21,    16,    17,    18,    30,    31,     3,     3,
       3,    10,    29,    29,    29,    62,    13,    56,    98,    94,
      62,    62,    62,    97,    97,    29,     3,     3,     3,    10,
       3,    99,   100,    10,     3,    29,    16,     8,    57,     6,
       3,     3,     4,     5,     9,    31,    33,    34,    35,    63,
     100,    11,    63,    63,     9,     9,     9,    28,    29,    30,
      31,    32,    64,    10,    63,    63,    63,    63,    63,    63,
      63,    63,    12,    10,     8,     8,    63,    63,    10,    10
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
         0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    70,    70,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    77,    77,    78,
      79,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    91,    91,
      91,    91,    92,    93,    93,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Lha_parser::yyr2_[] =
  {
         0,     2,     3,     4,     3,     1,     1,     4,     3,     2,
       3,     3,     3,     3,     4,     6,     6,     6,     1,     1,
       1,     4,     3,     2,     3,     3,     3,     3,     3,     4,
       6,     6,     1,     1,     1,     4,     3,     2,     3,     3,
       3,     3,     3,     4,     6,     6,     1,     3,     2,     2,
       1,     2,     6,     6,     4,     4,     2,     2,     6,     1,
       3,     6,     1,     3,     2,     2,     6,     1,     3,     6,
       1,     3,     2,     2,     6,     1,     2,    10,     6,     1,
       3,     3,     1,     1,     1,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     6,     1,     2,    14,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     5,     3,     3,     3,     2,
       6,     4,     4,     4,     3,     1,     1,     3,     3,     1,
       2,     4,     2,     1,     1,     1,     4,     1,    10,    10,
       3,     3,     3,     3,     1,     1,     1,     6,     6,     2,
       4,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     1,     3,     3,     1,     5,     3,     3,     3,
       2,     6,     4,     4,     4
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
        59,     0,    -1,    60,    75,    80,    -1,    65,    66,    70,
     101,    -1,    65,    70,   101,    -1,     5,    -1,     3,    -1,
       3,    11,    64,    12,    -1,     9,    61,    10,    -1,    31,
      61,    -1,    61,    30,    61,    -1,    61,    31,    61,    -1,
      61,    29,    61,    -1,    61,    32,    61,    -1,    33,     9,
      61,    10,    -1,    33,     9,    61,    28,    61,    10,    -1,
      34,     9,    61,     8,    61,    10,    -1,    35,     9,    61,
       8,    61,    10,    -1,     4,    -1,     5,    -1,     3,    -1,
       3,    11,    64,    12,    -1,     9,    62,    10,    -1,    31,
      62,    -1,    62,    28,    62,    -1,    62,    30,    62,    -1,
      62,    31,    62,    -1,    62,    29,    62,    -1,    62,    32,
      62,    -1,    33,     9,    62,    10,    -1,    34,     9,    62,
       8,    62,    10,    -1,    35,     9,    62,     8,    62,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     3,    11,    64,
      12,    -1,     9,    63,    10,    -1,    31,    63,    -1,    63,
      28,    63,    -1,    63,    30,    63,    -1,    63,    31,    63,
      -1,    63,    29,    63,    -1,    63,    32,    63,    -1,    33,
       9,    63,    10,    -1,    34,     9,    63,     8,    63,    10,
      -1,    35,     9,    63,     8,    63,    10,    -1,     3,    -1,
       3,     8,    64,    -1,    69,    68,    -1,    68,    69,    -1,
      67,    -1,    67,    66,    -1,    44,    27,     3,    16,    61,
       6,    -1,    44,    26,     3,    16,    62,     6,    -1,    46,
      16,     5,     6,    -1,    45,    16,     5,     6,    -1,    71,
      73,    -1,    73,    71,    -1,    47,    16,    56,    72,    57,
       6,    -1,     3,    -1,    72,     8,     3,    -1,    48,    16,
      56,    74,    57,     6,    -1,     3,    -1,    74,     8,     3,
      -1,    76,    78,    -1,    78,    76,    -1,    49,    16,    56,
      77,    57,     6,    -1,     3,    -1,    77,     8,     3,    -1,
      50,    16,    56,    79,    57,     6,    -1,     3,    -1,    79,
       8,     3,    -1,    81,    88,    -1,    88,    81,    -1,    51,
      16,    56,    82,    57,     6,    -1,    83,    -1,    82,    83,
      -1,     9,     3,     8,    86,     8,     9,    84,    10,    10,
       6,    -1,     9,     3,     8,    86,    10,     6,    -1,    85,
      -1,    84,     8,    85,    -1,     3,     7,    62,    -1,    24,
      -1,    25,    -1,    87,    -1,    86,    21,    86,    -1,    86,
      22,    86,    -1,     9,    86,    10,    -1,    23,    86,    -1,
      62,    16,    62,    -1,    62,    18,    62,    -1,    62,    17,
      62,    -1,    62,    19,    62,    -1,    62,    20,    62,    -1,
      52,    16,    56,    89,    57,     6,    -1,    90,    -1,    90,
      89,    -1,     9,     9,     3,     8,     3,    10,     8,    91,
       8,    94,     8,    98,    10,     6,    -1,    13,    -1,    14,
      -1,    14,    15,    92,    -1,    92,    -1,    56,    93,    57,
      -1,     3,    -1,    93,     8,     3,    -1,    95,    -1,    95,
      21,    94,    -1,    13,    -1,    96,    16,    62,    -1,    96,
      18,    62,    -1,    96,    17,    62,    -1,    97,    -1,    96,
      31,    97,    -1,    96,    30,    97,    -1,     3,    -1,     9,
      62,    10,    29,     3,    -1,     5,    29,     3,    -1,     4,
      29,     3,    -1,     3,    29,     3,    -1,    31,     3,    -1,
      31,     9,    62,    10,    29,     3,    -1,    31,     5,    29,
       3,    -1,    31,     4,    29,     3,    -1,    31,     3,    29,
       3,    -1,    56,    99,    57,    -1,    13,    -1,   100,    -1,
      99,     8,   100,    -1,     3,    16,    63,    -1,   102,    -1,
     102,   101,    -1,     3,    16,   104,     6,    -1,   104,     6,
      -1,     4,    -1,     5,    -1,     3,    -1,    38,     9,   105,
      10,    -1,    39,    -1,    53,     9,   105,     8,   103,     8,
     103,     8,   103,    10,    -1,    54,     9,   105,     8,   103,
       8,   103,     8,   103,    10,    -1,     9,   104,    10,    -1,
     104,    30,   104,    -1,   104,    29,   104,    -1,   104,    28,
     104,    -1,     5,    -1,     4,    -1,   106,    -1,    34,     9,
     105,     8,   105,    10,    -1,    35,     9,   105,     8,   105,
      10,    -1,    31,   105,    -1,    33,     9,   105,    10,    -1,
       9,   105,    10,    -1,   105,    32,   105,    -1,   105,    30,
     105,    -1,   105,    31,   105,    -1,   105,    29,   105,    -1,
     105,    28,   105,    -1,    40,     9,   107,    10,    -1,    36,
       9,   107,    10,    -1,    37,     9,   107,    10,    -1,    41,
       9,   107,    10,    -1,    42,     9,   107,    10,    -1,   108,
      -1,   107,    31,   108,    -1,   107,    30,   108,    -1,     3,
      -1,     9,    62,    10,    29,     3,    -1,     5,    29,     3,
      -1,     4,    29,     3,    -1,     3,    29,     3,    -1,    31,
       3,    -1,    31,     9,    62,    10,    29,     3,    -1,    31,
       5,    29,     3,    -1,    31,     4,    29,     3,    -1,    31,
       3,    29,     3,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Lha_parser::yyprhs_[] =
  {
         0,     0,     3,     7,    12,    16,    18,    20,    25,    29,
      32,    36,    40,    44,    48,    53,    60,    67,    74,    76,
      78,    80,    85,    89,    92,    96,   100,   104,   108,   112,
     117,   124,   131,   133,   135,   137,   142,   146,   149,   153,
     157,   161,   165,   169,   174,   181,   188,   190,   194,   197,
     200,   202,   205,   212,   219,   224,   229,   232,   235,   242,
     244,   248,   255,   257,   261,   264,   267,   274,   276,   280,
     287,   289,   293,   296,   299,   306,   308,   311,   322,   329,
     331,   335,   339,   341,   343,   345,   349,   353,   357,   360,
     364,   368,   372,   376,   380,   387,   389,   392,   407,   409,
     411,   415,   417,   421,   423,   427,   429,   433,   435,   439,
     443,   447,   449,   453,   457,   459,   465,   469,   473,   477,
     480,   487,   492,   497,   502,   506,   508,   510,   514,   518,
     520,   523,   528,   531,   533,   535,   537,   542,   544,   555,
     566,   570,   574,   578,   582,   584,   586,   588,   595,   602,
     605,   610,   614,   618,   622,   626,   630,   634,   639,   644,
     649,   654,   659,   661,   665,   669,   671,   677,   681,   685,
     689,   692,   699,   704,   709
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   178,   178,   181,   182,   188,   189,   199,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   218,   219,
     220,   231,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   249,   250,   251,   269,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   287,   288,   290,   291,
     293,   294,   296,   303,   313,   317,   321,   322,   324,   357,
     365,   372,   379,   385,   390,   391,   393,   395,   403,   408,
     410,   418,   427,   428,   432,   439,   440,   442,   461,   483,
     484,   485,   491,   492,   493,   494,   495,   496,   497,   499,
     500,   501,   502,   503,   508,   512,   513,   515,   538,   539,
     540,   544,   546,   548,   552,   557,   558,   559,   561,   566,
     571,   577,   578,   579,   581,   585,   590,   595,   600,   621,
     625,   630,   635,   640,   663,   664,   666,   667,   669,   676,
     676,   678,   689,   702,   703,   704,   714,   718,   721,   737,
     754,   757,   760,   763,   766,   769,   773,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   787,   797,   807,
     817,   827,   838,   839,   840,   842,   849,   854,   859,   864,
     883,   887,   892,   897,   902
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
  const int Lha_parser::yylast_ = 665;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 58;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 310;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2784 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 926 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
