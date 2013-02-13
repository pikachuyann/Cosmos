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
#line 158 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 423 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 423 of lalr1.cc  */
#line 162 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 423 of lalr1.cc  */
#line 161 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 423 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 102: /* rorival */
/* Line 423 of lalr1.cc  */
#line 162 "Lha-parser.yy"
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
#line 159 "Lha-parser.yy"
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
#line 187 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 188 "Lha-parser.yy"
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
#line 198 "Lha-parser.yy"
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
#line 205 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 206 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 207 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 208 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 209 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 210 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 219 "Lha-parser.yy"
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
#line 230 "Lha-parser.yy"
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
#line 237 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 238 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 239 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 240 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 241 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 242 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 250 "Lha-parser.yy"
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
#line 268 "Lha-parser.yy"
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
#line 275 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 276 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 277 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 278 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 279 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 280 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 281 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 296 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 303 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 312 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 316 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 323 "Lha-parser.yy"
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
#line 356 "Lha-parser.yy"
    {
	
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 364 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 371 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 378 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 384 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 394 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 402 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 409 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 417 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 431 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 442 "Lha-parser.yy"
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
#line 463 "Lha-parser.yy"
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
#line 484 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 490 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 491 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 492 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 493 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 494 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 495 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 496 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 498 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 499 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 500 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 501 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 502 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 507 "Lha-parser.yy"
    {
	
}
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 514 "Lha-parser.yy"
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
#line 538 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 539 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 547 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 551 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 556 "Lha-parser.yy"
    {}
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 557 "Lha-parser.yy"
    {}
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 561 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 566 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 571 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 114:
/* Line 670 of lalr1.cc  */
#line 581 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 585 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 590 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 595 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 600 "Lha-parser.yy"
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
#line 621 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 625 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 630 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 635 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 640 "Lha-parser.yy"
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
#line 662 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 125:
/* Line 670 of lalr1.cc  */
#line 663 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 668 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 677 "Lha-parser.yy"
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
#line 688 "Lha-parser.yy"
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
#line 701 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 702 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 703 "Lha-parser.yy"
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
#line 713 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 717 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 720 "Lha-parser.yy"
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
#line 736 "Lha-parser.yy"
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
#line 753 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 756 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 759 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 762 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 765 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 768 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 772 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 775 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 776 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 777 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 778 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 779 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 780 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 153:
/* Line 670 of lalr1.cc  */
#line 781 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 783 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 784 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 786 "Lha-parser.yy"
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
#line 796 "Lha-parser.yy"
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
#line 806 "Lha-parser.yy"
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
#line 816 "Lha-parser.yy"
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
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 828 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 829 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 832 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 836 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 841 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 846 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 851 "Lha-parser.yy"
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

  case 169:
/* Line 670 of lalr1.cc  */
#line 870 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 170:
/* Line 670 of lalr1.cc  */
#line 874 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 879 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 884 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 173:
/* Line 670 of lalr1.cc  */
#line 889 "Lha-parser.yy"
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
#line 1824 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -223;
  const short int
  Lha_parser::yypact_[] =
  {
       152,     0,    10,    31,   185,   205,    27,    40,    74,    91,
    -223,    88,    97,   153,    60,    80,   232,   117,   123,   282,
     100,     5,    98,   103,  -223,  -223,   151,   156,   124,   137,
     201,   221,  -223,   189,   194,  -223,  -223,   243,   246,   198,
     206,     5,  -223,   240,  -223,  -223,    15,   254,  -223,   276,
     291,  -223,     5,    12,  -223,  -223,  -223,  -223,   288,   290,
     248,   281,  -223,  -223,   350,   358,   295,   368,  -223,    15,
     130,   101,   101,   101,  -223,  -223,    15,    15,    15,  -223,
      -4,  -223,    13,   395,   401,   147,   113,  -223,    19,  -223,
      20,   324,  -223,   101,   101,   402,   405,   406,   407,   410,
     411,   433,   332,  -223,   237,   242,  -223,  -223,   310,   376,
     437,   404,   438,   409,     6,  -223,   439,   361,   401,   434,
    -223,  -223,   147,   147,   440,   443,   444,   155,   447,  -223,
     113,   113,   445,   448,   471,   170,   452,   475,   480,   476,
    -223,   355,   267,   101,   101,   101,     8,     8,     8,     8,
    -223,   101,   101,   101,   101,   101,    46,    46,  -223,  -223,
    -223,  -223,   442,   481,  -223,   482,   485,  -223,   483,   360,
     344,   147,   147,   147,  -223,   147,   147,   147,   147,   147,
     483,   511,    79,   113,   113,   113,  -223,   113,   113,   113,
     113,  -223,  -223,  -223,  -223,  -223,   365,   247,   252,   418,
     459,   461,   147,   238,   180,  -223,   546,   548,   550,   460,
     460,   267,   267,  -223,  -223,  -223,  -223,   487,   488,    96,
    -223,   510,  -223,   512,   514,  -223,   370,   279,   284,   490,
     490,   344,   344,  -223,   516,  -223,   393,    94,   319,   491,
      79,    79,  -223,  -223,   101,   101,   521,   524,   527,   398,
     464,   502,   503,   147,  -223,     8,     8,  -223,  -223,  -223,
      46,    46,    96,    96,  -223,  -223,   554,    24,  -223,   531,
     483,  -223,  -223,   147,   147,  -223,  -223,   113,   113,   113,
     403,   408,  -223,  -223,  -223,   528,   556,   563,   564,   431,
    -223,  -223,   560,   561,   327,    93,  -223,   147,   147,   147,
     147,   147,   566,   513,    96,    96,   577,  -223,   436,   441,
     515,   519,   523,  -223,  -223,   585,  -223,  -223,  -223,   562,
      46,    46,  -223,   303,   303,   303,   303,   303,   586,  -223,
    -223,   569,   584,  -223,  -223,  -223,  -223,  -223,  -223,   590,
     587,   588,   589,    25,  -223,    34,  -223,  -223,  -223,   147,
     586,   591,  -223,   579,   592,   594,  -223,   303,  -223,   593,
     545,  -223,    21,   223,  -223,  -223,   600,  -223,   575,   576,
     578,   147,  -223,   285,   598,   595,   351,  -223,  -223,   605,
     606,   607,   446,   582,   583,   596,   147,    57,   223,   147,
     147,   147,   226,   226,  -223,  -223,  -223,   597,   610,   611,
     612,   469,  -223,   614,   608,  -223,   303,   303,   303,  -223,
    -223,   616,  -223,  -223,  -223,   599,   604,    22,  -223,   615,
    -223,   619,   160,   614,  -223,  -223,  -223,   613,  -223,  -223,
     160,   160,   618,   620,   621,   533,  -223,   483,   474,   377,
     160,   160,   160,   160,   160,   160,   160,   160,   622,  -223,
     479,   289,   294,   601,   601,   377,   377,  -223,  -223,  -223,
     160,   160,   484,   507,  -223,  -223
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
       0,     0,     0,   146,     0,     0,   143,   142,   141,     0,
       0,     0,     0,     0,     0,    75,     0,     0,    95,    20,
      18,    19,     0,     0,     0,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,   149,     0,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,    68,    66,
      71,    69,     0,     0,    76,     0,     0,    96,     0,     0,
      23,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,    52,     0,     0,     0,
       0,    60,    58,    63,    61,   151,     0,     0,     0,   164,
       0,     0,     0,     0,     0,   161,     0,     0,     0,   156,
     155,   153,   154,   152,   135,   133,   134,     0,     0,     0,
      74,     0,    94,    46,     0,    22,     0,     0,     0,    24,
      27,    25,    26,    28,     0,     8,     0,     0,     0,    12,
      10,    11,    13,   150,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,   158,     0,     0,   159,   157,   160,
       0,     0,     0,     0,    82,    83,     0,     0,    84,     0,
       0,    21,    29,     0,     0,     7,    14,     0,     0,     0,
       0,     0,   168,   167,   166,     0,     0,     0,     0,     0,
     163,   162,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,   147,   148,     0,   173,   172,   171,     0,
       0,     0,    87,    89,    91,    90,    92,    93,     0,    78,
      85,    86,     0,    30,    31,    15,    16,    17,   165,     0,
       0,     0,     0,     0,    79,     0,   170,   138,   139,     0,
       0,     0,    98,    99,     0,     0,   101,    81,    80,     0,
       0,   103,     0,     0,    77,   100,     0,   102,   114,     0,
       0,     0,   107,     0,     0,   105,     0,   111,   104,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   117,   116,     0,     0,     0,
       0,     0,   125,     0,     0,   106,   108,   110,   109,   113,
     112,     0,   123,   122,   121,     0,     0,     0,   126,     0,
     115,     0,     0,     0,   124,    97,   120,    34,    32,    33,
       0,     0,     0,     0,     0,   128,   127,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,    38,    41,    39,    40,    42,    35,    43,
       0,     0,     0,     0,    44,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -223,  -223,  -223,  -124,   -85,  -222,  -175,  -223,   603,  -223,
     624,   626,   617,   623,  -223,   625,  -223,  -223,   627,  -223,
     629,  -223,  -223,   628,  -223,   525,  -223,   287,  -207,  -223,
     602,   520,  -223,  -223,   280,  -223,   253,  -223,  -223,   -52,
    -223,  -223,   222,   -16,  -223,  -154,   129,   -71,  -223,    23,
     122
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   135,   266,   435,   224,     5,    19,    20,
       6,     7,    21,    22,    88,    23,    90,    13,    14,    80,
      15,    82,    32,    33,   114,   115,   343,   344,   267,   268,
      34,   117,   118,   355,   356,   362,   374,   375,   376,   377,
     404,   417,   418,    51,    52,   217,    53,   102,   103,   204,
     205
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       127,   104,   105,   218,   109,   234,   181,   182,    43,    44,
      45,   199,   200,   201,    46,   113,     8,   202,    75,    44,
      45,   111,   141,   142,    46,    68,     9,   136,   138,   366,
     423,    10,   302,   350,   303,   351,    74,   169,   170,   203,
      76,    77,    78,    47,    48,   304,   305,   352,   353,   214,
     215,   216,   110,    47,    48,   295,   296,    49,    50,   236,
     237,   238,   163,   239,   240,   241,   242,    49,    50,   112,
     402,     1,   196,   197,   198,   137,   139,   367,   424,    26,
     209,   210,   211,   212,   213,     2,   226,   227,   228,   354,
     229,   230,   231,   232,   233,   307,    27,   330,   331,   119,
     120,   121,   278,   322,    28,   262,   292,   293,   187,    12,
      93,   190,   403,    29,   304,   305,   128,   249,   129,   263,
     264,   265,   130,   187,   188,   189,   190,   123,    11,   124,
     125,   126,    94,    39,    95,    96,    97,    98,    99,    40,
      92,   100,   101,    16,   131,    18,   132,   133,   134,    17,
     119,   120,   121,   310,   311,   312,   122,    56,    76,    77,
      78,   174,    57,   427,   428,   429,   340,   341,   289,   430,
     206,   207,   208,   280,   281,    70,   186,   294,   123,    58,
     124,   125,   126,   175,   176,   177,   178,   179,   308,   309,
     254,   431,    59,   432,   433,   434,     1,     2,    91,   187,
     188,   189,   190,    30,    31,   106,   107,   108,   438,   439,
     255,   256,   323,   324,   325,   326,   327,    60,   450,   451,
     452,   453,   454,   455,   456,   457,   368,   369,   370,   368,
     369,   370,   371,    11,    12,   371,   372,    61,   462,   463,
      31,   250,   251,   252,    30,   156,    64,   253,    16,    65,
     157,    17,    18,    66,   373,   244,    69,   373,    37,    38,
     245,    67,   448,    71,   357,   151,   152,   153,   154,   155,
     151,   152,   153,   154,   155,   151,   152,   153,   154,   155,
     151,   152,   153,   154,   155,    72,   382,   273,   383,   384,
     385,    79,   274,    81,   386,   151,   152,   460,    87,   155,
      73,   401,   461,    83,   406,   407,   408,   175,   176,   177,
     178,   179,   175,   176,   177,   178,   179,   443,   444,   445,
     446,   447,   443,   444,   445,   446,   447,   279,    17,    18,
     140,   175,   176,   177,   178,   179,    84,   225,    76,    77,
     409,   410,   150,   297,   298,   299,   300,   301,   187,   188,
     189,   190,    76,    77,    78,   175,   176,   177,   178,   179,
     151,   152,   153,   154,   155,   195,    85,   389,   390,   391,
     225,    89,   175,   176,    86,   243,   179,   290,   291,   158,
     272,   392,   393,   151,   152,   153,   154,   155,   175,   176,
     177,   178,   179,   151,   152,   153,   154,   155,   175,   176,
     177,   178,   179,   276,   113,   443,   444,   160,   285,   447,
     116,   143,   162,   313,   144,   145,   146,   166,   314,   147,
     148,   277,   187,   188,   189,   190,   175,   176,   177,   178,
     179,   151,   152,   153,   154,   155,   151,   152,   153,   154,
     155,   319,   149,   159,   161,   168,   333,   246,   165,   171,
     219,   334,   172,   173,   183,   191,   397,   184,   180,   175,
     176,   177,   178,   179,   175,   176,   177,   178,   179,   175,
     176,   177,   178,   179,   175,   176,   177,   178,   179,   415,
     185,   192,   194,   193,   449,   221,   223,   220,   247,   459,
     248,   222,   155,   286,   464,   260,   261,   175,   176,   177,
     178,   179,   443,   444,   445,   446,   447,   443,   444,   445,
     446,   447,   443,   444,   445,   446,   447,   465,   269,   329,
     270,   235,   179,   190,   282,   335,   271,   283,   275,   336,
     284,   287,   288,   337,   306,   443,   444,   445,   446,   447,
     187,   188,   189,   190,   187,   188,   189,   190,   187,   188,
     189,   190,   187,   188,   189,   190,   257,   315,   258,   316,
     259,   443,   444,   445,   446,   447,   317,   318,   320,   321,
     297,   298,   299,   300,   301,   328,   255,   256,   255,   256,
     255,   256,   175,   176,   177,   178,   179,   332,   338,   342,
     304,   339,   345,   346,   360,   361,   349,   347,   348,   364,
     354,   359,   363,   378,   379,   380,   387,   381,   394,   395,
     396,   398,   399,   412,   413,   414,   388,   416,   419,   420,
     422,   425,   426,    42,   437,   400,   411,   440,   421,   441,
     442,    25,    24,   447,   458,    62,    41,   358,   167,   164,
     365,   405,    36,    35,     0,   436,    55,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        85,    72,    73,   157,     8,   180,   130,   131,     3,     4,
       5,     3,     4,     5,     9,     9,    16,     9,     6,     4,
       5,     8,    93,    94,     9,    41,    16,     8,     8,     8,
       8,     0,     8,     8,    10,    10,    52,   122,   123,    31,
      28,    29,    30,    38,    39,    21,    22,    13,    14,     3,
       4,     5,    56,    38,    39,   262,   263,    52,    53,   183,
     184,   185,    56,   187,   188,   189,   190,    52,    53,    56,
      13,    44,   143,   144,   145,    56,    56,    56,    56,     5,
     151,   152,   153,   154,   155,    45,   171,   172,   173,    55,
     175,   176,   177,   178,   179,   270,     5,   304,   305,     3,
       4,     5,     8,    10,    16,     9,   260,   261,    29,    49,
       9,    32,    55,    16,    21,    22,     3,   202,     5,    23,
      24,    25,     9,    29,    30,    31,    32,    31,    48,    33,
      34,    35,    31,    16,    33,    34,    35,    36,    37,    16,
      10,    40,    41,    43,    31,    47,    33,    34,    35,    46,
       3,     4,     5,   277,   278,   279,     9,     6,    28,    29,
      30,     6,     6,     3,     4,     5,   320,   321,   253,     9,
     147,   148,   149,   244,   245,    46,     6,   262,    31,    55,
      33,    34,    35,    28,    29,    30,    31,    32,   273,   274,
      10,    31,    55,    33,    34,    35,    44,    45,    69,    29,
      30,    31,    32,    50,    51,    76,    77,    78,   430,   431,
      30,    31,   297,   298,   299,   300,   301,    16,   440,   441,
     442,   443,   444,   445,   446,   447,     3,     4,     5,     3,
       4,     5,     9,    48,    49,     9,    13,    16,   460,   461,
      51,     3,     4,     5,    50,     8,     3,     9,    43,     3,
       8,    46,    47,    55,    31,     8,    16,    31,    26,    27,
       8,    55,   437,     9,   349,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,     9,   371,     8,     3,     4,
       5,     3,     8,     3,     9,    28,    29,     8,     3,    32,
       9,   386,     8,    55,   389,   390,   391,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,     8,    46,    47,
       6,    28,    29,    30,    31,    32,    55,    10,    28,    29,
     392,   393,    10,    16,    17,    18,    19,    20,    29,    30,
      31,    32,    28,    29,    30,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,    16,    16,    17,    18,
      10,     3,    28,    29,    16,    10,    32,   255,   256,     3,
      10,    30,    31,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,     9,    28,    29,     3,    10,    32,
       9,     9,     3,    10,     9,     9,     9,    56,    10,     9,
       9,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    10,     9,     6,     6,    11,    10,    29,     9,     9,
       8,    10,     9,     9,     9,     3,    10,     9,    11,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    10,
       9,     6,     6,     3,    10,     3,     3,     6,    29,    10,
      29,     6,    32,    29,    10,     8,     8,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,     8,     6,
       8,    10,    32,    32,     3,    10,    12,     3,    12,    10,
       3,    29,    29,    10,     3,    28,    29,    30,    31,    32,
      29,    30,    31,    32,    29,    30,    31,    32,    29,    30,
      31,    32,    29,    30,    31,    32,    10,    29,    10,     3,
      10,    28,    29,    30,    31,    32,     3,     3,     8,     8,
      16,    17,    18,    19,    20,     9,    30,    31,    30,    31,
      30,    31,    28,    29,    30,    31,    32,    10,     3,     3,
      21,    29,     8,     3,    15,     3,     7,    10,    10,     6,
      55,    10,     8,     3,    29,    29,     8,    29,     3,     3,
       3,    29,    29,     3,     3,     3,    21,     3,    10,     3,
      16,     6,     3,    20,    11,    29,    29,     9,    29,     9,
       9,     7,     6,    32,    12,    33,    19,   350,   118,   114,
     360,   388,    15,    14,    -1,   423,    23,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    44,    45,    58,    59,    64,    67,    68,    16,    16,
       0,    48,    49,    74,    75,    77,    43,    46,    47,    65,
      66,    69,    70,    72,    68,    67,     5,     5,    16,    16,
      50,    51,    79,    80,    87,    77,    75,    26,    27,    16,
      16,    69,    65,     3,     4,     5,     9,    38,    39,    52,
      53,   100,   101,   103,    72,    70,     6,     6,    55,    55,
      16,    16,    87,    80,     3,     3,    55,    55,   100,    16,
     103,     9,     9,     9,   100,     6,    28,    29,    30,     3,
      76,     3,    78,    55,    55,    16,    16,     3,    71,     3,
      73,   103,    10,     9,    31,    33,    34,    35,    36,    37,
      40,    41,   104,   105,   104,   104,   103,   103,   103,     8,
      56,     8,    56,     9,    81,    82,     9,    88,    89,     3,
       4,     5,     9,    31,    33,    34,    35,    61,     3,     5,
       9,    31,    33,    34,    35,    60,     8,    56,     8,    56,
       6,   104,   104,     9,     9,     9,     9,     9,     9,     9,
      10,    28,    29,    30,    31,    32,     8,     8,     3,     6,
       3,     6,     3,    56,    82,     9,    56,    88,    11,    61,
      61,     9,     9,     9,     6,    28,    29,    30,    31,    32,
      11,    60,    60,     9,     9,     9,     6,    29,    30,    31,
      32,     3,     6,     3,     6,    10,   104,   104,   104,     3,
       4,     5,     9,    31,   106,   107,   106,   106,   106,   104,
     104,   104,   104,   104,     3,     4,     5,   102,   102,     8,
       6,     3,     6,     3,    63,    10,    61,    61,    61,    61,
      61,    61,    61,    61,    63,    10,    60,    60,    60,    60,
      60,    60,    60,    10,     8,     8,    29,    29,    29,    61,
       3,     4,     5,     9,    10,    30,    31,    10,    10,    10,
       8,     8,     9,    23,    24,    25,    61,    85,    86,     8,
       8,    12,    10,     8,     8,    12,    10,    28,     8,     8,
     104,   104,     3,     3,     3,    10,    29,    29,    29,    61,
     107,   107,   102,   102,    61,    85,    85,    16,    17,    18,
      19,    20,     8,    10,    21,    22,     3,    63,    61,    61,
      60,    60,    60,    10,    10,    29,     3,     3,     3,    10,
       8,     8,    10,    61,    61,    61,    61,    61,     9,     6,
      85,    85,    10,    10,    10,    10,    10,    10,     3,    29,
     102,   102,     3,    83,    84,     8,     3,    10,    10,     7,
       8,    10,    13,    14,    55,    90,    91,    61,    84,    10,
      15,     3,    92,     8,     6,    91,     8,    56,     3,     4,
       5,     9,    13,    31,    93,    94,    95,    96,     3,    29,
      29,    29,    61,     3,     4,     5,     9,     8,    21,    16,
      17,    18,    30,    31,     3,     3,     3,    10,    29,    29,
      29,    61,    13,    55,    97,    93,    61,    61,    61,    96,
      96,    29,     3,     3,     3,    10,     3,    98,    99,    10,
       3,    29,    16,     8,    56,     6,     3,     3,     4,     5,
       9,    31,    33,    34,    35,    62,    99,    11,    62,    62,
       9,     9,     9,    28,    29,    30,    31,    32,    63,    10,
      62,    62,    62,    62,    62,    62,    62,    62,    12,    10,
       8,     8,    62,    62,    10,    10
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
     305,   306,   307,   308,   309,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    69,    69,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    87,    88,    88,    89,    90,    90,
      90,    90,    91,    92,    92,    93,    93,    93,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,   100,
     100,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107
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
       4,     1,     3,     3,     1,     5,     3,     3,     3,     2,
       6,     4,     4,     4
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
  "INTEGRAL", "LhaName", "Const", "NbLoc", "NbVar", "VList", "LList",
  "Iloc", "Floc", "locations", "edges", "PDF", "CDF", "NEG", "'{'", "'}'",
  "$accept", "LHA", "declarations", "IntMarkingFormula",
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
        58,     0,    -1,    59,    74,    79,    -1,    64,    65,    69,
     100,    -1,    64,    69,   100,    -1,     5,    -1,     3,    -1,
       3,    11,    63,    12,    -1,     9,    60,    10,    -1,    31,
      60,    -1,    60,    30,    60,    -1,    60,    31,    60,    -1,
      60,    29,    60,    -1,    60,    32,    60,    -1,    33,     9,
      60,    10,    -1,    33,     9,    60,    28,    60,    10,    -1,
      34,     9,    60,     8,    60,    10,    -1,    35,     9,    60,
       8,    60,    10,    -1,     4,    -1,     5,    -1,     3,    -1,
       3,    11,    63,    12,    -1,     9,    61,    10,    -1,    31,
      61,    -1,    61,    28,    61,    -1,    61,    30,    61,    -1,
      61,    31,    61,    -1,    61,    29,    61,    -1,    61,    32,
      61,    -1,    33,     9,    61,    10,    -1,    34,     9,    61,
       8,    61,    10,    -1,    35,     9,    61,     8,    61,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     3,    11,    63,
      12,    -1,     9,    62,    10,    -1,    31,    62,    -1,    62,
      28,    62,    -1,    62,    30,    62,    -1,    62,    31,    62,
      -1,    62,    29,    62,    -1,    62,    32,    62,    -1,    33,
       9,    62,    10,    -1,    34,     9,    62,     8,    62,    10,
      -1,    35,     9,    62,     8,    62,    10,    -1,     3,    -1,
       3,     8,    63,    -1,    68,    67,    -1,    67,    68,    -1,
      66,    -1,    66,    65,    -1,    43,    27,     3,    16,    60,
       6,    -1,    43,    26,     3,    16,    61,     6,    -1,    45,
      16,     5,     6,    -1,    44,    16,     5,     6,    -1,    70,
      72,    -1,    72,    70,    -1,    46,    16,    55,    71,    56,
       6,    -1,     3,    -1,    71,     8,     3,    -1,    47,    16,
      55,    73,    56,     6,    -1,     3,    -1,    73,     8,     3,
      -1,    75,    77,    -1,    77,    75,    -1,    48,    16,    55,
      76,    56,     6,    -1,     3,    -1,    76,     8,     3,    -1,
      49,    16,    55,    78,    56,     6,    -1,     3,    -1,    78,
       8,     3,    -1,    80,    87,    -1,    87,    80,    -1,    50,
      16,    55,    81,    56,     6,    -1,    82,    -1,    81,    82,
      -1,     9,     3,     8,    85,     8,     9,    83,    10,    10,
       6,    -1,     9,     3,     8,    85,    10,     6,    -1,    84,
      -1,    83,     8,    84,    -1,     3,     7,    61,    -1,    24,
      -1,    25,    -1,    86,    -1,    85,    21,    85,    -1,    85,
      22,    85,    -1,     9,    85,    10,    -1,    23,    85,    -1,
      61,    16,    61,    -1,    61,    18,    61,    -1,    61,    17,
      61,    -1,    61,    19,    61,    -1,    61,    20,    61,    -1,
      51,    16,    55,    88,    56,     6,    -1,    89,    -1,    89,
      88,    -1,     9,     9,     3,     8,     3,    10,     8,    90,
       8,    93,     8,    97,    10,     6,    -1,    13,    -1,    14,
      -1,    14,    15,    91,    -1,    91,    -1,    55,    92,    56,
      -1,     3,    -1,    92,     8,     3,    -1,    94,    -1,    94,
      21,    93,    -1,    13,    -1,    95,    16,    61,    -1,    95,
      18,    61,    -1,    95,    17,    61,    -1,    96,    -1,    95,
      31,    96,    -1,    95,    30,    96,    -1,     3,    -1,     9,
      61,    10,    29,     3,    -1,     5,    29,     3,    -1,     4,
      29,     3,    -1,     3,    29,     3,    -1,    31,     3,    -1,
      31,     9,    61,    10,    29,     3,    -1,    31,     5,    29,
       3,    -1,    31,     4,    29,     3,    -1,    31,     3,    29,
       3,    -1,    55,    98,    56,    -1,    13,    -1,    99,    -1,
      98,     8,    99,    -1,     3,    16,    62,    -1,   101,    -1,
     101,   100,    -1,     3,    16,   103,     6,    -1,   103,     6,
      -1,     4,    -1,     5,    -1,     3,    -1,    38,     9,   104,
      10,    -1,    39,    -1,    52,     9,   104,     8,   102,     8,
     102,     8,   102,    10,    -1,    53,     9,   104,     8,   102,
       8,   102,     8,   102,    10,    -1,     9,   103,    10,    -1,
     103,    30,   103,    -1,   103,    29,   103,    -1,   103,    28,
     103,    -1,     5,    -1,     4,    -1,   105,    -1,    34,     9,
     104,     8,   104,    10,    -1,    35,     9,   104,     8,   104,
      10,    -1,    31,   104,    -1,    33,     9,   104,    10,    -1,
       9,   104,    10,    -1,   104,    32,   104,    -1,   104,    30,
     104,    -1,   104,    31,   104,    -1,   104,    29,   104,    -1,
     104,    28,   104,    -1,    40,     9,   106,    10,    -1,    36,
       9,   106,    10,    -1,    37,     9,   106,    10,    -1,    41,
       9,   106,    10,    -1,   107,    -1,   106,    31,   107,    -1,
     106,    30,   107,    -1,     3,    -1,     9,    61,    10,    29,
       3,    -1,     5,    29,     3,    -1,     4,    29,     3,    -1,
       3,    29,     3,    -1,    31,     3,    -1,    31,     9,    61,
      10,    29,     3,    -1,    31,     5,    29,     3,    -1,    31,
       4,    29,     3,    -1,    31,     3,    29,     3,    -1
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
     649,   654,   656,   660,   664,   666,   672,   676,   680,   684,
     687,   694,   699,   704
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   177,   177,   180,   181,   187,   188,   198,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   217,   218,
     219,   230,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   248,   249,   250,   268,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   286,   287,   289,   290,
     292,   293,   295,   302,   312,   316,   320,   321,   323,   356,
     364,   371,   378,   384,   389,   390,   392,   394,   402,   407,
     409,   417,   426,   427,   431,   438,   439,   441,   460,   482,
     483,   484,   490,   491,   492,   493,   494,   495,   496,   498,
     499,   500,   501,   502,   507,   511,   512,   514,   537,   538,
     539,   543,   545,   547,   551,   556,   557,   558,   560,   565,
     570,   576,   577,   578,   580,   584,   589,   594,   599,   620,
     624,   629,   634,   639,   662,   663,   665,   666,   668,   675,
     675,   677,   688,   701,   702,   703,   713,   717,   720,   736,
     753,   756,   759,   762,   765,   768,   772,   775,   776,   777,
     778,   779,   780,   781,   782,   783,   784,   786,   796,   806,
     816,   827,   828,   829,   831,   835,   840,   845,   850,   869,
     873,   878,   883,   888
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
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 662;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 57;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 309;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2764 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 912 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
