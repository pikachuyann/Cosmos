/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2013 Free Software Foundation, Inc.
   
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

/* Line 283 of lalr1.cc  */
#line 40 "Lha-parser.tab.cc"


#include "Lha-parser.tab.hh"

/* User implementation prologue.  */

/* Line 289 of lalr1.cc  */
#line 48 "Lha-parser.tab.cc"
/* Unqualified %code blocks.  */
/* Line 290 of lalr1.cc  */
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
	
	
	
	
	
	


/* Line 290 of lalr1.cc  */
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
/* Line 357 of lalr1.cc  */
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
/* Line 425 of lalr1.cc  */
#line 162 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 425 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 425 of lalr1.cc  */
#line 166 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 425 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 425 of lalr1.cc  */
#line 165 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 425 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 106: /* rorival */
/* Line 425 of lalr1.cc  */
#line 166 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 425 of lalr1.cc  */
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
/* Line 452 of lalr1.cc  */
#line 163 "Lha-parser.yy"
        { delete ((*yyvaluep).name); };
/* Line 452 of lalr1.cc  */
#line 316 "Lha-parser.tab.cc"
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
    yystate_stack_.clear ();
    yysemantic_stack_.clear ();
    yylocation_stack_.clear ();
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
/* Line 664 of lalr1.cc  */
#line 193 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 194 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 204 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 9:
/* Line 664 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 225 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str();
		if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}
	
	else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
    break;

  case 22:
/* Line 664 of lalr1.cc  */
#line 237 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 23:
/* Line 664 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 31:
/* Line 664 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 664 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:
/* Line 664 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 34:
/* Line 664 of lalr1.cc  */
#line 256 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 35:
/* Line 664 of lalr1.cc  */
#line 257 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str();
		if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
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
/* Line 664 of lalr1.cc  */
#line 276 "Lha-parser.yy"
    {
	if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yysemantic_stack_[(4) - (1)].name)->c_str()<< ".mult";
	 s << (yysemantic_stack_[(4) - (3)].expression);
		sprintf((yyval.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yysemantic_stack_[(4) - (1)].name)<<"' is not a place label "<<endl;YYABORT;}}
    break;

  case 37:
/* Line 664 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 38:
/* Line 664 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 39:
/* Line 664 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 664 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 664 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 664 of lalr1.cc  */
#line 288 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 664 of lalr1.cc  */
#line 289 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 290 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 291 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 292 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 664 of lalr1.cc  */
#line 294 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 295 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 304 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		if (Reader.P.constants.count(*(yysemantic_stack_[(6) - (3)].name))>0)st = Reader.P.constants[*(yysemantic_stack_[(6) - (3)].name)];
		
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 54:
/* Line 664 of lalr1.cc  */
#line 313 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		if (Reader.P.constants.count(*(yysemantic_stack_[(6) - (3)].name))>0)st = Reader.P.constants[*(yysemantic_stack_[(6) - (3)].name)];
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 55:
/* Line 664 of lalr1.cc  */
#line 323 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 327 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 59:
/* Line 664 of lalr1.cc  */
#line 334 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 367 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 61:
/* Line 664 of lalr1.cc  */
#line 374 "Lha-parser.yy"
    {
	
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(2) - (2)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(DISCRETE_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
    break;

  case 62:
/* Line 664 of lalr1.cc  */
#line 383 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 63:
/* Line 664 of lalr1.cc  */
#line 390 "Lha-parser.yy"
    {
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(4) - (4)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(DISCRETE_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 64:
/* Line 664 of lalr1.cc  */
#line 398 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 65:
/* Line 664 of lalr1.cc  */
#line 405 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 66:
/* Line 664 of lalr1.cc  */
#line 411 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 70:
/* Line 664 of lalr1.cc  */
#line 421 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 71:
/* Line 664 of lalr1.cc  */
#line 429 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 73:
/* Line 664 of lalr1.cc  */
#line 436 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 74:
/* Line 664 of lalr1.cc  */
#line 444 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 77:
/* Line 664 of lalr1.cc  */
#line 458 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 80:
/* Line 664 of lalr1.cc  */
#line 469 "Lha-parser.yy"
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

  case 81:
/* Line 664 of lalr1.cc  */
#line 490 "Lha-parser.yy"
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

  case 84:
/* Line 664 of lalr1.cc  */
#line 511 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 85:
/* Line 664 of lalr1.cc  */
#line 517 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 86:
/* Line 664 of lalr1.cc  */
#line 518 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 87:
/* Line 664 of lalr1.cc  */
#line 519 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 88:
/* Line 664 of lalr1.cc  */
#line 520 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:
/* Line 664 of lalr1.cc  */
#line 521 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 90:
/* Line 664 of lalr1.cc  */
#line 522 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 91:
/* Line 664 of lalr1.cc  */
#line 523 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 92:
/* Line 664 of lalr1.cc  */
#line 525 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 664 of lalr1.cc  */
#line 526 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 664 of lalr1.cc  */
#line 527 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 95:
/* Line 664 of lalr1.cc  */
#line 528 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 96:
/* Line 664 of lalr1.cc  */
#line 529 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 97:
/* Line 664 of lalr1.cc  */
#line 534 "Lha-parser.yy"
    {
	
}
    break;

  case 100:
/* Line 664 of lalr1.cc  */
#line 541 "Lha-parser.yy"
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
		Reader.MyLha.unTimeEdgeConstraints.push_back("true");
		vector<string> vs;comp=vs;CST=vs;
		vector <vector <string> > ms;CoeffsMatrix=ms;
		
	}
	else {cout<<*(yysemantic_stack_[(14) - (5)].name)<<" is not a location label"<<endl;YYABORT;}
	else  {cout<<*(yysemantic_stack_[(14) - (3)].name)<<" is not a location label"<<endl;YYABORT;}
}
    break;

  case 102:
/* Line 664 of lalr1.cc  */
#line 566 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 103:
/* Line 664 of lalr1.cc  */
#line 567 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 106:
/* Line 664 of lalr1.cc  */
#line 575 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 107:
/* Line 664 of lalr1.cc  */
#line 579 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 108:
/* Line 664 of lalr1.cc  */
#line 584 "Lha-parser.yy"
    {}
    break;

  case 109:
/* Line 664 of lalr1.cc  */
#line 585 "Lha-parser.yy"
    {}
    break;

  case 111:
/* Line 664 of lalr1.cc  */
#line 589 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 112:
/* Line 664 of lalr1.cc  */
#line 594 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 113:
/* Line 664 of lalr1.cc  */
#line 599 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 117:
/* Line 664 of lalr1.cc  */
#line 609 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 664 of lalr1.cc  */
#line 613 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 119:
/* Line 664 of lalr1.cc  */
#line 618 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 120:
/* Line 664 of lalr1.cc  */
#line 623 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 664 of lalr1.cc  */
#line 628 "Lha-parser.yy"
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

  case 122:
/* Line 664 of lalr1.cc  */
#line 649 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 664 of lalr1.cc  */
#line 653 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 124:
/* Line 664 of lalr1.cc  */
#line 658 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 125:
/* Line 664 of lalr1.cc  */
#line 663 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 126:
/* Line 664 of lalr1.cc  */
#line 668 "Lha-parser.yy"
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

  case 127:
/* Line 664 of lalr1.cc  */
#line 690 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 128:
/* Line 664 of lalr1.cc  */
#line 691 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 131:
/* Line 664 of lalr1.cc  */
#line 696 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 134:
/* Line 664 of lalr1.cc  */
#line 704 "Lha-parser.yy"
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

  case 135:
/* Line 664 of lalr1.cc  */
#line 715 "Lha-parser.yy"
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

  case 136:
/* Line 664 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 137:
/* Line 664 of lalr1.cc  */
#line 729 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 138:
/* Line 664 of lalr1.cc  */
#line 730 "Lha-parser.yy"
    { if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
			(yyval.RealVal) = Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else { if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
			(yyval.RealVal) = (double)Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else {
			cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a definded constant "<<endl;
			YYABORT;
		}}}
    break;

  case 139:
/* Line 664 of lalr1.cc  */
#line 740 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1);
}
    break;

  case 140:
/* Line 664 of lalr1.cc  */
#line 744 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop();
}
    break;

  case 141:
/* Line 664 of lalr1.cc  */
#line 747 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop((yysemantic_stack_[(6) - (3)].RealVal),(yysemantic_stack_[(6) - (5)].RealVal));
}
    break;

  case 142:
/* Line 664 of lalr1.cc  */
#line 750 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algPDF;
		algPDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" >= "<<bucket<<"&& "<<(yysemantic_stack_[(10) - (3)].expression)<<"<"<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1));
		Reader.MyLha.HASLtop.back()->TypeOp = PDF_PART;
		std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 143:
/* Line 664 of lalr1.cc  */
#line 765 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algCDF;
		algCDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1));
		Reader.MyLha.HASLtop.back()->TypeOp = CDF_PART;
		std::ostringstream s; s<<"$_$: Value in [-infinity , "<< bucket<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 144:
/* Line 664 of lalr1.cc  */
#line 780 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	char tmp[2048];
	sprintf(tmp,"(%s * %s)", (yysemantic_stack_[(4) - (3)].expression),(yysemantic_stack_[(4) - (3)].expression));
	Reader.MyLha.Algebraic.push_back(tmp);
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_MINUS,
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1),
		new HaslFormulasTop(HASL_TIME,
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-2),
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-2)));
}
    break;

  case 145:
/* Line 664 of lalr1.cc  */
#line 791 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 146:
/* Line 664 of lalr1.cc  */
#line 794 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 147:
/* Line 664 of lalr1.cc  */
#line 797 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_MINUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 148:
/* Line 664 of lalr1.cc  */
#line 800 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 149:
/* Line 664 of lalr1.cc  */
#line 803 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 150:
/* Line 664 of lalr1.cc  */
#line 806 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop((double)(yysemantic_stack_[(1) - (1)].IntVal),(double)(yysemantic_stack_[(1) - (1)].IntVal),1.0);
}
    break;

  case 151:
/* Line 664 of lalr1.cc  */
#line 809 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop((double)(yysemantic_stack_[(1) - (1)].RealVal),(double)(yysemantic_stack_[(1) - (1)].RealVal),1.0);
}
    break;

  case 152:
/* Line 664 of lalr1.cc  */
#line 813 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 153:
/* Line 664 of lalr1.cc  */
#line 816 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 154:
/* Line 664 of lalr1.cc  */
#line 817 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 155:
/* Line 664 of lalr1.cc  */
#line 818 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 156:
/* Line 664 of lalr1.cc  */
#line 819 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 157:
/* Line 664 of lalr1.cc  */
#line 820 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 158:
/* Line 664 of lalr1.cc  */
#line 821 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 159:
/* Line 664 of lalr1.cc  */
#line 822 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 160:
/* Line 664 of lalr1.cc  */
#line 823 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 161:
/* Line 664 of lalr1.cc  */
#line 824 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 162:
/* Line 664 of lalr1.cc  */
#line 825 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 163:
/* Line 664 of lalr1.cc  */
#line 827 "Lha-parser.yy"
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

  case 164:
/* Line 664 of lalr1.cc  */
#line 837 "Lha-parser.yy"
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

  case 165:
/* Line 664 of lalr1.cc  */
#line 847 "Lha-parser.yy"
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

  case 166:
/* Line 664 of lalr1.cc  */
#line 857 "Lha-parser.yy"
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

  case 167:
/* Line 664 of lalr1.cc  */
#line 867 "Lha-parser.yy"
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

  case 168:
/* Line 664 of lalr1.cc  */
#line 878 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 169:
/* Line 664 of lalr1.cc  */
#line 879 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 170:
/* Line 664 of lalr1.cc  */
#line 880 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 171:
/* Line 664 of lalr1.cc  */
#line 883 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str();
			if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
	} else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable or a place name"<<endl;YYABORT;}
}
    break;

  case 172:
/* Line 664 of lalr1.cc  */
#line 893 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 173:
/* Line 664 of lalr1.cc  */
#line 898 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 174:
/* Line 664 of lalr1.cc  */
#line 903 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 175:
/* Line 664 of lalr1.cc  */
#line 909 "Lha-parser.yy"
    { sprintf((yyval.expression),"%i ", (yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 176:
/* Line 664 of lalr1.cc  */
#line 912 "Lha-parser.yy"
    { sprintf((yyval.expression),"%f ", (yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 177:
/* Line 664 of lalr1.cc  */
#line 915 "Lha-parser.yy"
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

  case 178:
/* Line 664 of lalr1.cc  */
#line 934 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 179:
/* Line 664 of lalr1.cc  */
#line 938 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 180:
/* Line 664 of lalr1.cc  */
#line 943 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 181:
/* Line 664 of lalr1.cc  */
#line 948 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 182:
/* Line 664 of lalr1.cc  */
#line 953 "Lha-parser.yy"
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


/* Line 664 of lalr1.cc  */
#line 1920 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -252;
  const short int
  Lha_parser::yypact_[] =
  {
        34,     4,  -252,  -252,    98,    97,   114,  -252,   119,    95,
      99,   135,   140,   153,   -22,   260,   123,   129,  -252,    13,
     257,    98,   536,   125,   125,   159,   184,   203,   125,   125,
    -252,   194,   210,   170,   183,   212,   279,   224,   258,   330,
     219,    13,   264,   267,  -252,  -252,  -252,  -252,    98,    98,
      98,    98,   261,  -252,   125,   125,   299,   342,   380,   413,
     436,   448,   449,   450,   372,  -252,   378,   384,   454,   463,
     265,   271,   409,   412,   480,   481,  -252,   415,   419,  -252,
    -252,   495,   496,   442,   452,    13,  -252,  -252,  -252,  -252,
    -252,  -252,   328,   328,  -252,   383,   284,   125,   125,   125,
     126,   126,   126,   126,   126,  -252,   125,   125,   125,   125,
     125,  -252,   504,  -252,  -252,     9,     9,   506,   507,   465,
     477,  -252,  -252,   521,   522,    12,   537,  -252,  -252,   395,
     290,   296,   523,   524,   533,   178,   115,    18,  -252,   102,
     142,   231,   348,   531,   531,   284,   284,  -252,   563,  -252,
    -252,  -252,   566,   567,  -252,    -4,  -252,    -2,   568,   569,
     178,   188,  -252,   573,    11,  -252,    19,  -252,   125,   125,
     576,   582,   583,   577,  -252,  -252,   178,   178,   578,   580,
     581,   406,   562,   564,   565,   178,  -252,   126,   126,  -252,
    -252,  -252,  -252,  -252,     9,     9,   589,   590,   592,   591,
     595,     2,  -252,   593,   539,   569,   252,   594,  -252,   188,
     188,   597,   598,   599,    15,  -252,   106,   603,   600,   604,
     411,   418,  -252,  -252,  -252,   601,   423,   321,   178,   178,
     178,   571,   178,   178,   178,   178,   178,   608,   609,   610,
     434,  -252,  -252,   606,   607,  -252,  -252,  -252,  -252,   611,
     612,  -252,   613,   614,  -252,  -252,   601,   169,    -3,   188,
     188,   188,  -252,   188,   188,   188,   188,  -252,   618,  -252,
    -252,  -252,  -252,  -252,   615,   605,  -252,   446,   301,   306,
     619,   596,   596,   321,   321,  -252,  -252,  -252,  -252,   572,
       9,     9,   161,  -252,   616,  -252,   617,  -252,   451,   340,
     344,   602,    -3,    -3,  -252,  -252,   601,  -252,  -252,   178,
     178,  -252,   622,   620,   621,   161,   161,  -252,  -252,   552,
     100,  -252,   623,  -252,  -252,   188,   188,   188,  -252,   457,
     462,  -252,  -252,  -252,   367,    14,  -252,   178,   178,   178,
     178,   178,   624,   626,   161,   161,   625,   239,   525,   529,
    -252,  -252,  -252,   336,   336,   336,   336,   336,   633,  -252,
    -252,   627,   629,  -252,  -252,  -252,   631,   180,  -252,    91,
     178,   633,   630,  -252,   628,   636,   634,  -252,   336,  -252,
     635,   585,  -252,    24,   247,  -252,  -252,   642,  -252,   632,
     637,   638,   178,  -252,   250,   639,   641,   324,  -252,  -252,
     643,   646,   647,   474,   640,   644,   645,   178,    55,   247,
     178,   178,   178,   234,   234,  -252,  -252,  -252,   648,   649,
     650,   651,   485,  -252,   652,   653,  -252,   336,   336,   336,
    -252,  -252,   654,  -252,  -252,  -252,   655,   656,    32,  -252,
     658,  -252,   657,   211,   652,  -252,  -252,  -252,   659,  -252,
    -252,   211,   211,   662,   666,   667,   519,  -252,   601,   490,
     362,   211,   211,   211,   211,   211,   211,   211,   211,   668,
    -252,   497,   315,   331,   660,   660,   362,   362,  -252,  -252,
    -252,   211,   211,   502,   513,  -252,  -252
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,   151,   150,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,    50,    49,   133,   135,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,    67,
      68,     0,     0,     0,     0,     0,    52,     5,    57,    58,
     149,   148,   146,   147,   134,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   144,     0,    56,    55,     0,     0,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     4,   157,     0,
       0,     0,   171,   176,   175,     0,     0,     0,   168,     0,
       0,     0,     0,   162,   161,   159,   160,   158,     0,   138,
     136,   137,     0,     0,    70,     0,    73,     0,     0,     0,
       0,     0,    60,     0,     0,    65,     0,   156,     0,     0,
       0,     0,     0,    21,    19,    20,     0,     0,     0,     0,
       0,     0,   178,     0,     0,     0,   164,     0,     0,   165,
     163,   166,   167,   141,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    98,     0,     7,     6,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,   177,   174,   173,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   169,     0,     0,    71,    69,    74,    72,     0,
       0,    79,     0,     0,    99,    54,     0,     0,    10,     0,
       0,     0,    53,     0,     0,     0,     0,    62,     0,    59,
      66,    64,   153,   154,    47,     0,    23,     0,     0,     0,
       0,    25,    28,    26,    27,    29,   182,   181,   180,     0,
       0,     0,     0,    77,     0,    97,     0,     9,     0,     0,
       0,    13,    11,    12,    14,    63,     0,    22,    30,     0,
       0,   172,     0,     0,     0,     0,     0,    85,    86,     0,
       0,    87,     0,     8,    15,     0,     0,     0,    48,     0,
       0,   179,   142,   143,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    90,    92,    94,    93,    95,    96,     0,    81,
      88,    89,     0,    16,    17,    18,     0,     0,    82,     0,
       0,     0,     0,   101,   102,     0,     0,   104,    84,    83,
       0,     0,   106,     0,     0,    80,   103,     0,   105,   117,
       0,     0,     0,   110,     0,     0,   108,     0,   114,   107,
       0,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   120,   119,     0,     0,
       0,     0,     0,   128,     0,     0,   109,   111,   113,   112,
     116,   115,     0,   126,   125,   124,     0,     0,     0,   129,
       0,   118,     0,     0,     0,   127,   100,   123,    35,    33,
      34,     0,     0,     0,     0,     0,   131,   130,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    39,    42,    40,    41,    43,    36,
      44,     0,     0,     0,     0,    45,    46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -252,  -252,  -252,  -200,  -135,  -234,  -251,  -252,   587,  -252,
     661,   663,   664,   665,  -252,   669,  -252,  -252,   670,  -252,
     672,  -252,  -252,   671,  -252,   455,  -252,   280,  -199,  -252,
     588,   453,  -252,  -252,   278,  -252,   259,  -252,  -252,    16,
    -252,  -252,   237,   -18,  -252,  -114,    92,   -21,  -252,   316,
     244
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,    13,    14,   214,   319,   456,   275,    15,    39,    40,
      16,    17,    41,    42,   164,    43,   166,    33,    34,   155,
      35,   157,    76,    77,   201,   202,   367,   368,   320,   321,
      78,   204,   205,   376,   377,   383,   395,   396,   397,   398,
     425,   438,   439,    18,    19,   152,    20,    64,    65,   137,
     138
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       181,    46,   153,    66,   196,   296,   198,    70,    71,   257,
     258,   200,   149,   150,   151,   162,     1,     2,     3,   216,
      21,   262,     4,    87,   352,   206,   263,   218,   186,   266,
      31,    32,   387,    95,    96,   344,   345,     1,     2,     3,
     444,   226,   227,     4,   263,   264,   265,   266,   187,   188,
     240,     5,     6,     7,     8,   328,   197,   163,   199,   298,
     299,   300,   250,   301,   302,   303,   304,   127,   423,    11,
      12,   217,     5,     6,     7,     8,   129,   130,   131,   219,
     243,   244,     9,    10,   388,   143,   144,   145,   146,   147,
      11,    12,   445,   277,   278,   279,    22,   281,   282,   283,
     284,   285,     2,     3,   373,   374,    23,     4,   342,   267,
     343,    26,   189,    52,   424,    27,   335,   336,   182,   183,
     184,   344,   345,    24,   185,   347,   348,   349,    25,   132,
     133,   134,   187,   188,    54,   135,     5,     6,     7,     8,
      90,    91,    92,    93,    28,   360,   361,   220,   221,    29,
     375,   268,   190,    30,    11,    12,    55,   136,    56,    57,
      58,    59,    60,    67,   173,   174,   175,    61,    62,    63,
     315,     9,   187,   188,   329,   330,   313,   314,    10,   297,
     334,   173,   174,   175,   316,   317,   318,   176,   371,    68,
     372,   207,   177,   208,   178,   179,   180,   209,   263,   264,
     265,   266,   353,   354,   355,   356,   357,   469,    69,   177,
      72,   178,   179,   180,   448,   449,   450,   459,   460,   210,
     451,   211,   212,   213,    74,    75,    73,   471,   472,   473,
     474,   475,   476,   477,   478,   378,    32,   389,   390,   391,
      83,   191,   452,   392,   453,   454,   455,   483,   484,   363,
     389,   390,   391,   404,   405,   406,   392,   403,   255,   407,
     393,   187,   188,    47,    31,   394,    36,    94,   263,   264,
     265,   266,   422,   115,    84,   427,   428,   429,   394,   116,
     232,   233,   234,   235,   236,    48,    49,    50,    51,    48,
      49,    50,    51,   106,   107,   108,   109,   110,   168,   106,
     107,   108,   109,   110,   169,    81,    82,    36,    97,   309,
      37,    38,   106,   107,   310,    38,   110,    37,   106,   107,
     108,   109,   110,   481,   106,   107,   108,   109,   110,   232,
     233,   234,   235,   236,   232,   233,   234,   235,   236,   482,
     410,   411,   412,   464,   465,   466,   467,   468,   326,   232,
     233,    98,   327,   236,   413,   414,    48,    49,   192,   464,
     465,   466,   467,   468,   232,   233,   234,   235,   236,   263,
     264,   265,   266,   263,   264,   265,   266,   276,   187,   188,
      37,    38,   105,   337,   338,   339,   340,   341,   111,    99,
     464,   465,   112,   128,   468,   232,   233,   234,   235,   236,
     106,   107,   108,   109,   110,   167,   106,   107,   108,   109,
     110,   106,   107,   108,   109,   110,   231,   139,   140,   141,
     142,   272,   100,   106,   107,   108,   109,   110,   273,   430,
     431,   241,   242,   276,   232,   233,   234,   235,   236,   106,
     107,   108,   109,   110,   289,   101,   106,   107,   108,   109,
     110,   232,   233,   234,   235,   236,   308,   102,   103,   104,
     113,   324,   232,   233,   234,   235,   236,   350,   117,   114,
      75,   118,   351,    74,   232,   233,   234,   235,   236,   325,
     263,   264,   265,   266,   418,   232,   233,   234,   235,   236,
     232,   233,   234,   235,   236,   436,   119,   120,   123,   124,
     470,   125,   232,   233,   234,   235,   236,   480,   148,   154,
     156,   126,   485,   232,   233,   234,   235,   236,   464,   465,
     466,   467,   468,   486,   158,   464,   465,   466,   467,   468,
     464,   465,   466,   467,   468,   364,   159,   160,   161,   365,
     165,   464,   465,   466,   467,   468,    53,   464,   465,   466,
     467,   468,   170,   171,   263,   264,   265,   266,   263,   264,
     265,   266,   172,   110,    48,    49,    50,    51,   337,   338,
     339,   340,   341,   193,   194,   195,   215,   200,   203,   222,
     232,   233,   234,   235,   236,   223,   224,   228,   225,   229,
     230,   237,   245,   238,   239,   247,   246,   248,   249,   253,
     280,   312,   252,   270,   274,   256,   259,   260,   261,   269,
     271,   286,   287,   288,   290,   291,   294,   307,   293,   292,
     295,   305,   311,   306,   322,   331,   346,    86,   236,   323,
     332,   333,   359,   358,   266,   362,   366,   369,   370,   382,
     380,   385,   384,   381,   375,   399,   415,   408,   344,   416,
     417,   379,   433,   434,   435,   437,   251,   441,   254,   386,
     447,   400,   409,   440,   446,   121,   401,   402,   426,   419,
     458,   461,   443,   420,   421,   462,   463,   432,    45,    44,
     479,   457,     0,     0,   442,     0,     0,     0,     0,     0,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,    80,    79,     0,    89,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
       135,    19,   116,    24,     8,   256,     8,    28,    29,   209,
     210,     9,     3,     4,     5,     3,     3,     4,     5,     8,
      16,     6,     9,    41,    10,   160,    29,     8,    10,    32,
      52,    53,     8,    54,    55,    21,    22,     3,     4,     5,
       8,   176,   177,     9,    29,    30,    31,    32,    30,    31,
     185,    38,    39,    40,    41,   306,    60,    45,    60,   259,
     260,   261,    60,   263,   264,   265,   266,    85,    13,    56,
      57,    60,    38,    39,    40,    41,    97,    98,    99,    60,
     194,   195,    48,    49,    60,   106,   107,   108,   109,   110,
      56,    57,    60,   228,   229,   230,     4,   232,   233,   234,
     235,   236,     4,     5,    13,    14,     9,     9,     8,     3,
      10,    16,    10,    21,    59,    16,   315,   316,     3,     4,
       5,    21,    22,     9,     9,   325,   326,   327,     9,     3,
       4,     5,    30,    31,     9,     9,    38,    39,    40,    41,
      48,    49,    50,    51,     9,   344,   345,   168,   169,     9,
      59,    45,    10,     0,    56,    57,    31,    31,    33,    34,
      35,    36,    37,     4,     3,     4,     5,    42,    43,    44,
       9,    48,    30,    31,   309,   310,   290,   291,    49,    10,
     315,     3,     4,     5,    23,    24,    25,     9,     8,     5,
      10,     3,    31,     5,    33,    34,    35,     9,    29,    30,
      31,    32,   337,   338,   339,   340,   341,   458,     5,    31,
      16,    33,    34,    35,     3,     4,     5,   451,   452,    31,
       9,    33,    34,    35,    54,    55,    16,   461,   462,   463,
     464,   465,   466,   467,   468,   370,    53,     3,     4,     5,
      16,    10,    31,     9,    33,    34,    35,   481,   482,    10,
       3,     4,     5,     3,     4,     5,     9,   392,     6,     9,
      13,    30,    31,     6,    52,    31,    47,     6,    29,    30,
      31,    32,   407,     8,    16,   410,   411,   412,    31,     8,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    28,
      29,    30,    31,    28,    29,    30,    31,    32,     8,    28,
      29,    30,    31,    32,     8,    26,    27,    47,     9,     8,
      50,    51,    28,    29,     8,    51,    32,    50,    28,    29,
      30,    31,    32,     8,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,     8,
      16,    17,    18,    28,    29,    30,    31,    32,     8,    28,
      29,     9,     8,    32,    30,    31,    28,    29,    10,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    29,
      30,    31,    32,    29,    30,    31,    32,    10,    30,    31,
      50,    51,    10,    16,    17,    18,    19,    20,    10,     9,
      28,    29,     8,    10,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,   101,   102,   103,
     104,    10,     9,    28,    29,    30,    31,    32,    10,   413,
     414,   187,   188,    10,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    10,     9,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,     9,     9,     9,
       6,    10,    28,    29,    30,    31,    32,    10,    59,     6,
      55,    59,    10,    54,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    10,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,    16,    16,     3,     3,
      10,    59,    28,    29,    30,    31,    32,    10,     4,     3,
       3,    59,    10,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,    59,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,    59,    16,    16,    10,
       3,    28,    29,    30,    31,    32,    10,    28,    29,    30,
      31,    32,    29,    29,    29,    30,    31,    32,    29,    30,
      31,    32,    29,    32,    28,    29,    30,    31,    16,    17,
      18,    19,    20,    10,     8,     8,     3,     9,     9,     3,
      28,    29,    30,    31,    32,     3,     3,     9,    11,     9,
       9,    29,     3,    29,    29,     3,     6,     6,     3,    60,
      29,    29,     9,     3,     3,    11,     9,     9,     9,     6,
       6,     3,     3,     3,     8,     8,     3,    12,     6,     8,
       6,     3,     3,     8,     8,     3,     3,    40,    32,    12,
      10,    10,     6,     9,    32,    10,     3,     8,     7,     3,
      10,     6,     8,    15,    59,     3,     3,     8,    21,     3,
       3,   371,     3,     3,     3,     3,   201,     3,   205,   381,
       3,    29,    21,    10,     6,    77,    29,    29,   409,    29,
      11,     9,    16,    29,    29,     9,     9,    29,    17,    16,
      12,   444,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    35,    34,    -1,    43,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,     3,     4,     5,     9,    38,    39,    40,    41,    48,
      49,    56,    57,    62,    63,    68,    71,    72,   104,   105,
     107,    16,   107,     9,     9,     9,    16,    16,     9,     9,
       0,    52,    53,    78,    79,    81,    47,    50,    51,    69,
      70,    73,    74,    76,    72,    71,   104,     6,    28,    29,
      30,    31,   107,    10,     9,    31,    33,    34,    35,    36,
      37,    42,    43,    44,   108,   109,   108,     4,     5,     5,
     108,   108,    16,    16,    54,    55,    83,    84,    91,    81,
      79,    26,    27,    16,    16,    73,    69,   104,    76,    74,
     107,   107,   107,   107,     6,   108,   108,     9,     9,     9,
       9,     9,     9,     9,     9,    10,    28,    29,    30,    31,
      32,    10,     8,     6,     6,     8,     8,    59,    59,    16,
      16,    91,    84,     3,     3,    59,    59,   104,    10,   108,
     108,   108,     3,     4,     5,     9,    31,   110,   111,   110,
     110,   110,   110,   108,   108,   108,   108,   108,     4,     3,
       4,     5,   106,   106,     3,    80,     3,    82,    59,    59,
      16,    16,     3,    45,    75,     3,    77,    10,     8,     8,
      29,    29,    29,     3,     4,     5,     9,    31,    33,    34,
      35,    65,     3,     4,     5,     9,    10,    30,    31,    10,
      10,    10,    10,    10,     8,     8,     8,    60,     8,    60,
       9,    85,    86,     9,    92,    93,    65,     3,     5,     9,
      31,    33,    34,    35,    64,     3,     8,    60,     8,    60,
     108,   108,     3,     3,     3,    11,    65,    65,     9,     9,
       9,    10,    28,    29,    30,    31,    32,    29,    29,    29,
      65,   111,   111,   106,   106,     3,     6,     3,     6,     3,
      60,    86,     9,    60,    92,     6,    11,    64,    64,     9,
       9,     9,     6,    29,    30,    31,    32,     3,    45,     6,
       3,     6,    10,    10,     3,    67,    10,    65,    65,    65,
      29,    65,    65,    65,    65,    65,     3,     3,     3,    10,
       8,     8,     8,     6,     3,     6,    67,    10,    64,    64,
      64,    64,    64,    64,    64,     3,     8,    12,    10,     8,
       8,     3,    29,   106,   106,     9,    23,    24,    25,    65,
      89,    90,     8,    12,    10,    28,     8,     8,    67,    65,
      65,     3,    10,    10,    65,    89,    89,    16,    17,    18,
      19,    20,     8,    10,    21,    22,     3,    64,    64,    64,
      10,    10,    10,    65,    65,    65,    65,    65,     9,     6,
      89,    89,    10,    10,    10,    10,     3,    87,    88,     8,
       7,     8,    10,    13,    14,    59,    94,    95,    65,    88,
      10,    15,     3,    96,     8,     6,    95,     8,    60,     3,
       4,     5,     9,    13,    31,    97,    98,    99,   100,     3,
      29,    29,    29,    65,     3,     4,     5,     9,     8,    21,
      16,    17,    18,    30,    31,     3,     3,     3,    10,    29,
      29,    29,    65,    13,    59,   101,    97,    65,    65,    65,
     100,   100,    29,     3,     3,     3,    10,     3,   102,   103,
      10,     3,    29,    16,     8,    60,     6,     3,     3,     4,
       5,     9,    31,    33,    34,    35,    66,   103,    11,    66,
      66,     9,     9,     9,    28,    29,    30,    31,    32,    67,
      10,    66,    66,    66,    66,    66,    66,    66,    66,    12,
      10,     8,     8,    66,    66,    10,    10
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   123,
     125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      75,    75,    75,    75,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    82,    82,    83,    83,    84,    85,    85,
      86,    86,    87,    87,    88,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    91,    92,    92,
      93,    94,    94,    94,    94,    95,    96,    96,    97,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   109,   109,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111
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
       1,     2,     3,     4,     6,     1,     3,     2,     2,     6,
       1,     3,     6,     1,     3,     2,     2,     6,     1,     2,
      10,     6,     1,     3,     3,     1,     1,     1,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     6,     1,     2,
      14,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     5,     3,
       3,     3,     2,     6,     4,     4,     4,     3,     1,     1,
       3,     3,     1,     2,     4,     2,     1,     1,     1,     4,
       1,     6,    10,    10,     4,     3,     3,     3,     3,     3,
       1,     1,     1,     6,     6,     2,     4,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     1,     3,
       3,     1,     5,     3,     3,     1,     1,     3,     2,     6,
       4,     4,     4
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
  "FLOOR", "MIN", "MAX", "LhaMIN", "LhaMAX", "AVG", "VAR", "PROB", "SPRT",
  "LAST", "INTEGRAL", "MEAN", "DISC", "LhaName", "Const", "NbLoc", "NbVar",
  "VList", "LList", "Iloc", "Floc", "locations", "edges", "PDF", "CDF",
  "NEG", "'{'", "'}'", "$accept", "LHA", "declarations",
  "IntMarkingFormula", "RealMarkingFormula", "RealVarMarkingFormula",
  "ColorClassList", "Sizes", "Constants", "Constant", "NbVariables",
  "NbLocations", "Lists", "VariablesList", "VLabels", "LocationsList",
  "LLabels", "InitFinal", "init", "iLLabels", "final", "fLLabels",
  "definitions", "LocationsDef", "LOCATIONS", "LOCATION", "FLOWS", "FLOW",
  "LogExpr", "CompExpr", "EdgesDef", "EDGES", "EDGE", "ACTIONS",
  "SetOfActions", "Actions", "CONSTRAINTS", "CONSTRAINT", "LinearExp",
  "term", "UPDATES", "Updates", "Update", "HaslExps", "HaslExp", "rorival",
  "TopHaslExp", "AlgExpr", "LhaFunc", "LinForm", "VarTerm", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Lha_parser::rhs_number_type
  Lha_parser::yyrhs_[] =
  {
        62,     0,    -1,    63,    78,    83,    -1,   104,    -1,    68,
      69,    73,   104,    -1,    68,    73,   104,    -1,     5,    -1,
       3,    -1,     3,    11,    67,    12,    -1,     9,    64,    10,
      -1,    31,    64,    -1,    64,    30,    64,    -1,    64,    31,
      64,    -1,    64,    29,    64,    -1,    64,    32,    64,    -1,
      33,     9,    64,    10,    -1,    33,     9,    64,    28,    64,
      10,    -1,    34,     9,    64,     8,    64,    10,    -1,    35,
       9,    64,     8,    64,    10,    -1,     4,    -1,     5,    -1,
       3,    -1,     3,    11,    67,    12,    -1,     9,    65,    10,
      -1,    31,    65,    -1,    65,    28,    65,    -1,    65,    30,
      65,    -1,    65,    31,    65,    -1,    65,    29,    65,    -1,
      65,    32,    65,    -1,    33,     9,    65,    10,    -1,    34,
       9,    65,     8,    65,    10,    -1,    35,     9,    65,     8,
      65,    10,    -1,     4,    -1,     5,    -1,     3,    -1,     3,
      11,    67,    12,    -1,     9,    66,    10,    -1,    31,    66,
      -1,    66,    28,    66,    -1,    66,    30,    66,    -1,    66,
      31,    66,    -1,    66,    29,    66,    -1,    66,    32,    66,
      -1,    33,     9,    66,    10,    -1,    34,     9,    66,     8,
      66,    10,    -1,    35,     9,    66,     8,    66,    10,    -1,
       3,    -1,     3,     8,    67,    -1,    72,    71,    -1,    71,
      72,    -1,    70,    -1,    70,    69,    -1,    47,    27,     3,
      16,    64,     6,    -1,    47,    26,     3,    16,    65,     6,
      -1,    49,    16,     5,     6,    -1,    48,    16,     5,     6,
      -1,    74,    76,    -1,    76,    74,    -1,    50,    16,    59,
      75,    60,     6,    -1,     3,    -1,    45,     3,    -1,    75,
       8,     3,    -1,    75,     8,    45,     3,    -1,    51,    16,
      59,    77,    60,     6,    -1,     3,    -1,    77,     8,     3,
      -1,    79,    81,    -1,    81,    79,    -1,    52,    16,    59,
      80,    60,     6,    -1,     3,    -1,    80,     8,     3,    -1,
      53,    16,    59,    82,    60,     6,    -1,     3,    -1,    82,
       8,     3,    -1,    84,    91,    -1,    91,    84,    -1,    54,
      16,    59,    85,    60,     6,    -1,    86,    -1,    85,    86,
      -1,     9,     3,     8,    89,     8,     9,    87,    10,    10,
       6,    -1,     9,     3,     8,    89,    10,     6,    -1,    88,
      -1,    87,     8,    88,    -1,     3,     7,    65,    -1,    24,
      -1,    25,    -1,    90,    -1,    89,    21,    89,    -1,    89,
      22,    89,    -1,     9,    89,    10,    -1,    23,    89,    -1,
      65,    16,    65,    -1,    65,    18,    65,    -1,    65,    17,
      65,    -1,    65,    19,    65,    -1,    65,    20,    65,    -1,
      55,    16,    59,    92,    60,     6,    -1,    93,    -1,    93,
      92,    -1,     9,     9,     3,     8,     3,    10,     8,    94,
       8,    97,     8,   101,    10,     6,    -1,    13,    -1,    14,
      -1,    14,    15,    95,    -1,    95,    -1,    59,    96,    60,
      -1,     3,    -1,    96,     8,     3,    -1,    98,    -1,    98,
      21,    97,    -1,    13,    -1,    99,    16,    65,    -1,    99,
      18,    65,    -1,    99,    17,    65,    -1,   100,    -1,    99,
      31,   100,    -1,    99,    30,   100,    -1,     3,    -1,     9,
      65,    10,    29,     3,    -1,     5,    29,     3,    -1,     4,
      29,     3,    -1,     3,    29,     3,    -1,    31,     3,    -1,
      31,     9,    65,    10,    29,     3,    -1,    31,     5,    29,
       3,    -1,    31,     4,    29,     3,    -1,    31,     3,    29,
       3,    -1,    59,   102,    60,    -1,    13,    -1,   103,    -1,
     102,     8,   103,    -1,     3,    16,    66,    -1,   105,    -1,
     105,   104,    -1,     3,    16,   107,     6,    -1,   107,     6,
      -1,     4,    -1,     5,    -1,     3,    -1,    38,     9,   108,
      10,    -1,    40,    -1,    41,     9,     4,     8,     4,    10,
      -1,    56,     9,   108,     8,   106,     8,   106,     8,   106,
      10,    -1,    57,     9,   108,     8,   106,     8,   106,     8,
     106,    10,    -1,    39,     9,   108,    10,    -1,     9,   107,
      10,    -1,   107,    30,   107,    -1,   107,    31,   107,    -1,
     107,    29,   107,    -1,   107,    28,   107,    -1,     5,    -1,
       4,    -1,   109,    -1,    34,     9,   108,     8,   108,    10,
      -1,    35,     9,   108,     8,   108,    10,    -1,    31,   108,
      -1,    33,     9,   108,    10,    -1,     9,   108,    10,    -1,
     108,    32,   108,    -1,   108,    30,   108,    -1,   108,    31,
     108,    -1,   108,    29,   108,    -1,   108,    28,   108,    -1,
      42,     9,   110,    10,    -1,    36,     9,   110,    10,    -1,
      37,     9,   110,    10,    -1,    43,     9,   110,    10,    -1,
      44,     9,   110,    10,    -1,   111,    -1,   110,    31,   111,
      -1,   110,    30,   111,    -1,     3,    -1,     9,    65,    10,
      29,     3,    -1,     5,    29,     3,    -1,     4,    29,     3,
      -1,     5,    -1,     4,    -1,     3,    29,     3,    -1,    31,
       3,    -1,    31,     9,    65,    10,    29,     3,    -1,    31,
       5,    29,     3,    -1,    31,     4,    29,     3,    -1,    31,
       3,    29,     3,    -1
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
     244,   246,   249,   253,   258,   265,   267,   271,   274,   277,
     284,   286,   290,   297,   299,   303,   306,   309,   316,   318,
     321,   332,   339,   341,   345,   349,   351,   353,   355,   359,
     363,   367,   370,   374,   378,   382,   386,   390,   397,   399,
     402,   417,   419,   421,   425,   427,   431,   433,   437,   439,
     443,   445,   449,   453,   457,   459,   463,   467,   469,   475,
     479,   483,   487,   490,   497,   502,   507,   512,   516,   518,
     520,   524,   528,   530,   533,   538,   541,   543,   545,   547,
     552,   554,   561,   572,   583,   588,   592,   596,   600,   604,
     608,   610,   612,   614,   621,   628,   631,   636,   640,   644,
     648,   652,   656,   660,   665,   670,   675,   680,   685,   687,
     691,   695,   697,   703,   707,   711,   713,   715,   719,   722,
     729,   734,   739
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   183,   183,   184,   186,   187,   193,   194,   204,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   223,
     224,   225,   237,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   255,   256,   257,   276,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   294,   295,   297,
     298,   300,   301,   303,   312,   323,   327,   331,   332,   334,
     367,   374,   383,   390,   398,   405,   411,   416,   417,   419,
     421,   429,   434,   436,   444,   453,   454,   458,   465,   466,
     468,   487,   509,   510,   511,   517,   518,   519,   520,   521,
     522,   523,   525,   526,   527,   528,   529,   534,   538,   539,
     541,   565,   566,   567,   571,   573,   575,   579,   584,   585,
     586,   588,   593,   598,   604,   605,   606,   608,   612,   617,
     622,   627,   648,   652,   657,   662,   667,   690,   691,   693,
     694,   696,   702,   702,   704,   715,   728,   729,   730,   740,
     744,   747,   750,   765,   780,   791,   794,   797,   800,   803,
     806,   809,   813,   816,   817,   818,   819,   820,   821,   822,
     823,   824,   825,   827,   837,   847,   857,   867,   878,   879,
     880,   882,   892,   897,   902,   908,   911,   914,   933,   937,
     942,   947,   952
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
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      55,    56,    57,    58
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 749;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 30;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 61;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 313;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1135 of lalr1.cc  */
#line 2892 "Lha-parser.tab.cc"
/* Line 1136 of lalr1.cc  */
#line 976 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
