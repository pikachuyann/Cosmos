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
#line 160 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 425 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 425 of lalr1.cc  */
#line 164 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 425 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 425 of lalr1.cc  */
#line 163 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 425 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 104: /* rorival */
/* Line 425 of lalr1.cc  */
#line 164 "Lha-parser.yy"
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
#line 161 "Lha-parser.yy"
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
#line 191 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 192 "Lha-parser.yy"
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
#line 202 "Lha-parser.yy"
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
#line 209 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 210 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 223 "Lha-parser.yy"
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
#line 235 "Lha-parser.yy"
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
#line 242 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 31:
/* Line 664 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 664 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:
/* Line 664 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 34:
/* Line 664 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 35:
/* Line 664 of lalr1.cc  */
#line 255 "Lha-parser.yy"
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
#line 274 "Lha-parser.yy"
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
#line 281 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 38:
/* Line 664 of lalr1.cc  */
#line 282 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 39:
/* Line 664 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 664 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 664 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 664 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 664 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 288 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 289 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 290 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 664 of lalr1.cc  */
#line 292 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 293 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 302 "Lha-parser.yy"
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
#line 311 "Lha-parser.yy"
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
#line 321 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 325 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 59:
/* Line 664 of lalr1.cc  */
#line 332 "Lha-parser.yy"
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
#line 365 "Lha-parser.yy"
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
	Reader.MyLha.Vars.label.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 62:
/* Line 664 of lalr1.cc  */
#line 382 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 63:
/* Line 664 of lalr1.cc  */
#line 389 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 64:
/* Line 664 of lalr1.cc  */
#line 395 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 68:
/* Line 664 of lalr1.cc  */
#line 405 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 69:
/* Line 664 of lalr1.cc  */
#line 413 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 71:
/* Line 664 of lalr1.cc  */
#line 420 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 72:
/* Line 664 of lalr1.cc  */
#line 428 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 75:
/* Line 664 of lalr1.cc  */
#line 442 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 78:
/* Line 664 of lalr1.cc  */
#line 453 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 474 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 495 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 83:
/* Line 664 of lalr1.cc  */
#line 501 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 84:
/* Line 664 of lalr1.cc  */
#line 502 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 85:
/* Line 664 of lalr1.cc  */
#line 503 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 86:
/* Line 664 of lalr1.cc  */
#line 504 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 664 of lalr1.cc  */
#line 505 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:
/* Line 664 of lalr1.cc  */
#line 506 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 89:
/* Line 664 of lalr1.cc  */
#line 507 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 90:
/* Line 664 of lalr1.cc  */
#line 509 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 91:
/* Line 664 of lalr1.cc  */
#line 510 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 92:
/* Line 664 of lalr1.cc  */
#line 511 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 664 of lalr1.cc  */
#line 512 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 664 of lalr1.cc  */
#line 513 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 95:
/* Line 664 of lalr1.cc  */
#line 518 "Lha-parser.yy"
    {
	
}
    break;

  case 98:
/* Line 664 of lalr1.cc  */
#line 525 "Lha-parser.yy"
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

  case 100:
/* Line 664 of lalr1.cc  */
#line 550 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 101:
/* Line 664 of lalr1.cc  */
#line 551 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 104:
/* Line 664 of lalr1.cc  */
#line 559 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 105:
/* Line 664 of lalr1.cc  */
#line 563 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 106:
/* Line 664 of lalr1.cc  */
#line 568 "Lha-parser.yy"
    {}
    break;

  case 107:
/* Line 664 of lalr1.cc  */
#line 569 "Lha-parser.yy"
    {}
    break;

  case 109:
/* Line 664 of lalr1.cc  */
#line 573 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 110:
/* Line 664 of lalr1.cc  */
#line 578 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 111:
/* Line 664 of lalr1.cc  */
#line 583 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 115:
/* Line 664 of lalr1.cc  */
#line 593 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 664 of lalr1.cc  */
#line 597 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 664 of lalr1.cc  */
#line 602 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 664 of lalr1.cc  */
#line 607 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 119:
/* Line 664 of lalr1.cc  */
#line 612 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 633 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 664 of lalr1.cc  */
#line 637 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 122:
/* Line 664 of lalr1.cc  */
#line 642 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 664 of lalr1.cc  */
#line 647 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 124:
/* Line 664 of lalr1.cc  */
#line 652 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 674 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 126:
/* Line 664 of lalr1.cc  */
#line 675 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 129:
/* Line 664 of lalr1.cc  */
#line 680 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 132:
/* Line 664 of lalr1.cc  */
#line 688 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 699 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 712 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 135:
/* Line 664 of lalr1.cc  */
#line 713 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 136:
/* Line 664 of lalr1.cc  */
#line 714 "Lha-parser.yy"
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
/* Line 664 of lalr1.cc  */
#line 724 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 138:
/* Line 664 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 139:
/* Line 664 of lalr1.cc  */
#line 731 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel,(yysemantic_stack_[(6) - (3)].RealVal),(yysemantic_stack_[(6) - (5)].RealVal));
}
    break;

  case 140:
/* Line 664 of lalr1.cc  */
#line 734 "Lha-parser.yy"
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

  case 141:
/* Line 664 of lalr1.cc  */
#line 750 "Lha-parser.yy"
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

  case 142:
/* Line 664 of lalr1.cc  */
#line 767 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 143:
/* Line 664 of lalr1.cc  */
#line 770 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 144:
/* Line 664 of lalr1.cc  */
#line 773 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 145:
/* Line 664 of lalr1.cc  */
#line 776 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 146:
/* Line 664 of lalr1.cc  */
#line 779 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 147:
/* Line 664 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 148:
/* Line 664 of lalr1.cc  */
#line 786 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 149:
/* Line 664 of lalr1.cc  */
#line 789 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 150:
/* Line 664 of lalr1.cc  */
#line 790 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 151:
/* Line 664 of lalr1.cc  */
#line 791 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 152:
/* Line 664 of lalr1.cc  */
#line 792 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 153:
/* Line 664 of lalr1.cc  */
#line 793 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 154:
/* Line 664 of lalr1.cc  */
#line 794 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 155:
/* Line 664 of lalr1.cc  */
#line 795 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 156:
/* Line 664 of lalr1.cc  */
#line 796 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 157:
/* Line 664 of lalr1.cc  */
#line 797 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 158:
/* Line 664 of lalr1.cc  */
#line 798 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 159:
/* Line 664 of lalr1.cc  */
#line 800 "Lha-parser.yy"
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

  case 160:
/* Line 664 of lalr1.cc  */
#line 810 "Lha-parser.yy"
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

  case 161:
/* Line 664 of lalr1.cc  */
#line 820 "Lha-parser.yy"
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

  case 162:
/* Line 664 of lalr1.cc  */
#line 830 "Lha-parser.yy"
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

  case 163:
/* Line 664 of lalr1.cc  */
#line 840 "Lha-parser.yy"
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

  case 164:
/* Line 664 of lalr1.cc  */
#line 851 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 165:
/* Line 664 of lalr1.cc  */
#line 852 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 166:
/* Line 664 of lalr1.cc  */
#line 853 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 167:
/* Line 664 of lalr1.cc  */
#line 856 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str();
			if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
	} else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable or a place name"<<endl;YYABORT;}
}
    break;

  case 168:
/* Line 664 of lalr1.cc  */
#line 866 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 169:
/* Line 664 of lalr1.cc  */
#line 871 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 170:
/* Line 664 of lalr1.cc  */
#line 876 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 171:
/* Line 664 of lalr1.cc  */
#line 882 "Lha-parser.yy"
    { sprintf((yyval.expression),"%i ", (yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 172:
/* Line 664 of lalr1.cc  */
#line 885 "Lha-parser.yy"
    { sprintf((yyval.expression),"%f ", (yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 173:
/* Line 664 of lalr1.cc  */
#line 888 "Lha-parser.yy"
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

  case 174:
/* Line 664 of lalr1.cc  */
#line 907 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 175:
/* Line 664 of lalr1.cc  */
#line 911 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 176:
/* Line 664 of lalr1.cc  */
#line 916 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 177:
/* Line 664 of lalr1.cc  */
#line 921 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 178:
/* Line 664 of lalr1.cc  */
#line 926 "Lha-parser.yy"
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
#line 1874 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -261;
  const short int
  Lha_parser::yypact_[] =
  {
        97,    -3,  -261,  -261,   107,    35,  -261,    38,    89,   101,
      59,   110,   142,   -22,   248,    77,   116,  -261,    15,   278,
     107,   200,   123,   185,   191,   206,   123,   123,  -261,   201,
     211,    37,   183,   186,   148,   224,   236,   134,   218,    15,
     231,   219,  -261,  -261,  -261,  -261,   107,   107,   107,   292,
    -261,   123,   123,   272,   274,   282,   314,   327,   329,   340,
     362,   354,  -261,   287,   284,   355,    96,   271,   306,   315,
     319,   386,  -261,   323,   359,  -261,  -261,   401,   409,   370,
     396,    15,  -261,  -261,  -261,  -261,  -261,  -261,   166,  -261,
     360,   121,   123,   123,   123,   261,   261,   261,   261,   261,
    -261,   123,   123,   123,   123,   123,   446,  -261,  -261,    34,
      34,   475,   478,   434,   435,  -261,  -261,   474,   477,   503,
     515,  -261,  -261,   365,   281,   286,   490,   491,   493,   188,
     328,    84,  -261,   103,   108,   138,   157,   499,   499,   121,
     121,  -261,   513,  -261,  -261,  -261,   524,   527,  -261,     1,
    -261,     6,   545,   546,   188,   215,  -261,     8,  -261,     9,
    -261,   123,   123,   530,   563,   564,   557,  -261,  -261,   188,
     188,   560,   561,   562,   377,   543,   544,   547,   188,  -261,
     261,   261,  -261,  -261,  -261,  -261,  -261,    34,    34,   571,
     569,   574,   572,   576,    27,  -261,   573,   522,   546,   149,
     570,  -261,   215,   215,   575,   577,   578,   256,   580,   579,
     585,   583,   388,   393,  -261,  -261,  -261,   587,   400,   423,
     188,   188,   188,   565,   188,   188,   188,   188,   188,   588,
     589,   590,   405,  -261,  -261,   591,   592,  -261,  -261,  -261,
    -261,   593,   596,  -261,   594,   597,  -261,  -261,   587,    78,
     -17,   215,   215,   215,  -261,   215,   215,   215,   215,  -261,
    -261,  -261,  -261,  -261,  -261,   598,   584,  -261,   416,   297,
     311,   595,   581,   581,   423,   423,  -261,  -261,  -261,  -261,
     566,    34,    34,   181,  -261,   599,  -261,   600,  -261,   428,
       3,   326,   582,   -17,   -17,  -261,   587,  -261,  -261,   188,
     188,  -261,   601,   605,   606,   181,   181,  -261,  -261,   528,
     352,  -261,   602,  -261,  -261,   215,   215,   215,  -261,   433,
     439,  -261,  -261,  -261,   349,     0,  -261,   188,   188,   188,
     188,   188,   608,   603,   181,   181,   609,   495,   507,   511,
    -261,  -261,  -261,   521,   521,   521,   521,   521,   607,  -261,
    -261,   604,   610,  -261,  -261,  -261,   613,    42,  -261,    29,
     188,   607,   611,  -261,   612,   619,   615,  -261,   521,  -261,
     618,   551,  -261,    18,   238,  -261,  -261,   623,  -261,   614,
     616,   617,   188,  -261,   525,   620,   621,   383,  -261,  -261,
     626,   627,   628,   444,   622,   624,   625,   188,    -9,   238,
     188,   188,   188,   273,   273,  -261,  -261,  -261,   629,   630,
     631,   632,   456,  -261,   633,   634,  -261,   521,   521,   521,
    -261,  -261,   635,  -261,  -261,  -261,   636,   639,    19,  -261,
     641,  -261,   637,   204,   633,  -261,  -261,  -261,   638,  -261,
    -261,   204,   204,   643,   647,   648,   533,  -261,   587,   467,
     451,   204,   204,   204,   204,   204,   204,   204,   204,   649,
    -261,   472,   316,   322,   640,   640,   451,   451,  -261,  -261,
    -261,   204,   204,   479,   484,  -261,  -261
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,   147,   146,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,    50,    49,   131,   133,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    65,    66,     0,     0,     0,
       0,     0,    52,     5,    57,    58,   145,   144,   143,   132,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,     4,   153,     0,     0,     0,   167,   172,   171,     0,
       0,     0,   164,     0,     0,     0,     0,   158,   157,   155,
     156,   154,     0,   136,   134,   135,     0,     0,    68,     0,
      71,     0,     0,     0,     0,     0,    60,     0,    63,     0,
     152,     0,     0,     0,     0,     0,    21,    19,    20,     0,
       0,     0,     0,     0,     0,   174,     0,     0,     0,   160,
       0,     0,   161,   159,   162,   163,   139,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,    96,     0,
       7,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   170,   169,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   165,     0,     0,    69,    67,    72,
      70,     0,     0,    77,     0,     0,    97,    54,     0,     0,
      10,     0,     0,     0,    53,     0,     0,     0,     0,    61,
      59,    64,    62,   149,   150,    47,     0,    23,     0,     0,
       0,     0,    25,    28,    26,    27,    29,   178,   177,   176,
       0,     0,     0,     0,    75,     0,    95,     0,     9,     0,
       0,     0,    13,    11,    12,    14,     0,    22,    30,     0,
       0,   168,     0,     0,     0,     0,     0,    83,    84,     0,
       0,    85,     0,     8,    15,     0,     0,     0,    48,     0,
       0,   175,   140,   141,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    88,    90,    92,    91,    93,    94,     0,    79,
      86,    87,     0,    16,    17,    18,     0,     0,    80,     0,
       0,     0,     0,    99,   100,     0,     0,   102,    82,    81,
       0,     0,   104,     0,     0,    78,   101,     0,   103,   115,
       0,     0,     0,   108,     0,     0,   106,     0,   112,   105,
       0,     0,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   118,   117,     0,     0,
       0,     0,     0,   126,     0,     0,   107,   109,   111,   110,
     114,   113,     0,   124,   123,   122,     0,     0,     0,   127,
       0,   116,     0,     0,     0,   125,    98,   121,    35,    33,
      34,     0,     0,     0,     0,     0,   129,   128,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    39,    42,    40,    41,    43,    36,
      44,     0,     0,     0,     0,    45,    46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -261,  -261,  -261,  -195,  -129,  -197,  -245,  -261,   642,  -261,
     644,   651,   645,   646,  -261,   650,  -261,  -261,   652,  -261,
     654,  -261,  -261,   537,  -261,   438,  -261,   276,  -260,  -261,
     568,   441,  -261,  -261,   277,  -261,   251,  -261,  -261,  -178,
    -261,  -261,   225,   -16,  -261,  -109,    83,   -21,  -261,   343,
      52
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,    12,    13,   207,   309,   446,   266,    14,    37,    38,
      15,    16,    39,    40,   157,    41,   159,    31,    32,   149,
      33,   151,    72,    73,   194,   195,   357,   358,   310,   311,
      74,   197,   198,   366,   367,   373,   385,   386,   387,   388,
     415,   428,   429,    17,    18,   146,    19,    61,    62,   131,
     132
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       174,   147,    44,   287,   413,    66,    67,   249,   250,   189,
     342,   316,   255,    20,   191,   258,   208,   210,     1,     2,
       3,   334,   335,    83,     4,   199,   377,   434,    29,    30,
      90,    91,   255,   256,   257,   258,   193,   143,   144,   145,
     218,   219,   363,   364,    22,   325,   326,    23,   414,   232,
     361,   318,   362,     5,     6,     7,   289,   290,   291,   190,
     292,   293,   294,   295,   192,   121,   209,   211,    26,    10,
      11,   123,   124,   125,   350,   351,   378,   435,   235,   236,
     137,   138,   139,   140,   141,   242,   365,    21,   288,    70,
      71,   268,   269,   270,   179,   272,   273,   274,   275,   276,
       1,     2,     3,    49,   109,    24,     4,   255,   256,   257,
     258,     2,     3,   182,   180,   181,     4,    25,   183,    27,
     337,   338,   339,     8,   101,   102,   103,   104,   105,    86,
      87,    88,    51,   180,   181,     5,     6,     7,   180,   181,
     212,   213,    28,     8,     9,     5,     6,     7,   184,   101,
     102,    10,    11,   105,    52,   247,    53,    54,    55,    56,
      57,    10,    11,     9,    58,    59,    60,   185,   180,   181,
     319,   320,   303,   304,    77,    78,   324,   224,   225,   226,
     227,   228,    35,    36,   166,   167,   168,   180,   181,    63,
     305,   166,   167,   168,    46,    47,    64,   169,   343,   344,
     345,   346,   347,   459,   306,   307,   308,   438,   439,   440,
      50,    65,   170,   441,   171,   172,   173,    68,   200,   170,
     201,   171,   172,   173,   202,   420,   421,    69,    46,    47,
      48,   368,   233,   234,    30,   442,    29,   443,   444,   445,
      79,   379,   380,   381,   449,   450,   203,   382,   204,   205,
     206,   383,    80,   393,   461,   462,   463,   464,   465,   466,
     467,   468,   254,    34,   126,   127,   128,    35,   412,   384,
     129,   417,   418,   419,   473,   474,   379,   380,   381,   110,
      36,    92,   382,    93,    45,   255,   256,   257,   258,   161,
     107,    94,   130,    34,   162,   106,    35,    36,    89,   101,
     102,   103,   104,   105,   384,   299,    46,    47,    48,   101,
     102,   103,   104,   105,   101,   102,   103,   104,   105,   300,
      46,    47,    48,    95,   471,   224,   225,   226,   227,   228,
     472,   175,   176,   177,   317,   113,    96,   178,    97,   224,
     225,   226,   227,   228,   454,   455,   456,   457,   458,    98,
     454,   455,   456,   457,   458,   255,   256,   257,   258,   267,
     332,   108,   333,   111,   100,   327,   328,   329,   330,   331,
     122,    99,   112,   334,   335,   160,    71,   224,   225,   226,
     227,   228,   101,   102,   103,   104,   105,   223,   101,   102,
     103,   104,   105,   101,   102,   103,   104,   105,   263,   400,
     401,   402,   114,   264,   117,   224,   225,   226,   227,   228,
     267,    70,   118,   403,   404,   280,   101,   102,   103,   104,
     105,   101,   102,   103,   104,   105,   298,   119,   224,   225,
     226,   227,   228,   224,   225,   226,   227,   228,   314,   133,
     134,   135,   136,   340,   224,   225,   226,   227,   228,   341,
     142,   224,   225,   120,   408,   228,   315,   255,   256,   257,
     258,   224,   225,   226,   227,   228,   426,   224,   225,   226,
     227,   228,   224,   225,   226,   227,   228,   460,   148,   454,
     455,   150,   470,   458,   224,   225,   226,   227,   228,   475,
     154,   152,   153,   155,   476,   454,   455,   456,   457,   458,
     454,   455,   456,   457,   458,   353,   156,   454,   455,   456,
     457,   458,   454,   455,   456,   457,   458,   354,   158,   163,
     164,   355,   165,   186,   255,   256,   257,   258,   394,   395,
     396,   105,   187,   214,   397,   188,   255,   256,   257,   258,
     255,   256,   257,   258,   327,   328,   329,   330,   331,   224,
     225,   226,   227,   228,   193,   196,   224,   225,   226,   227,
     228,   454,   455,   456,   457,   458,   215,   216,   217,   220,
     221,   222,   229,   230,   237,   238,   231,   239,   240,   241,
     245,   248,   244,   259,   251,   260,   252,   253,   261,   262,
     265,   277,   278,   279,   271,   302,   297,   285,   301,   281,
     282,   283,   284,   286,   321,   336,   296,   312,   365,   349,
     356,   116,   313,   228,   258,   322,   323,   348,   359,   352,
     360,   370,   372,   374,   375,   334,   389,   371,   398,   405,
     406,   407,   243,   423,   424,   425,   427,   369,   431,   246,
     437,   115,   399,   390,   430,   391,   392,   436,   376,   448,
     416,   409,   451,   410,   411,   433,   452,   453,   422,   447,
      43,   469,     0,     0,     0,   432,    42,     0,     0,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
      82,     0,    81,     0,     0,    76,    75,    85,     0,     0,
      84
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
       129,   110,    18,   248,    13,    26,    27,   202,   203,     8,
      10,     8,    29,    16,     8,    32,     8,     8,     3,     4,
       5,    21,    22,    39,     9,   154,     8,     8,    50,    51,
      51,    52,    29,    30,    31,    32,     9,     3,     4,     5,
     169,   170,    13,    14,     9,   305,   306,     9,    57,   178,
       8,   296,    10,    38,    39,    40,   251,   252,   253,    58,
     255,   256,   257,   258,    58,    81,    58,    58,     9,    54,
      55,    92,    93,    94,   334,   335,    58,    58,   187,   188,
     101,   102,   103,   104,   105,    58,    57,     4,    10,    52,
      53,   220,   221,   222,    10,   224,   225,   226,   227,   228,
       3,     4,     5,    20,     8,    16,     9,    29,    30,    31,
      32,     4,     5,    10,    30,    31,     9,    16,    10,     9,
     315,   316,   317,    46,    28,    29,    30,    31,    32,    46,
      47,    48,     9,    30,    31,    38,    39,    40,    30,    31,
     161,   162,     0,    46,    47,    38,    39,    40,    10,    28,
      29,    54,    55,    32,    31,     6,    33,    34,    35,    36,
      37,    54,    55,    47,    41,    42,    43,    10,    30,    31,
     299,   300,   281,   282,    26,    27,   305,    28,    29,    30,
      31,    32,    48,    49,     3,     4,     5,    30,    31,     4,
       9,     3,     4,     5,    28,    29,     5,     9,   327,   328,
     329,   330,   331,   448,    23,    24,    25,     3,     4,     5,
      10,     5,    31,     9,    33,    34,    35,    16,     3,    31,
       5,    33,    34,    35,     9,   403,   404,    16,    28,    29,
      30,   360,   180,   181,    51,    31,    50,    33,    34,    35,
      16,     3,     4,     5,   441,   442,    31,     9,    33,    34,
      35,    13,    16,   382,   451,   452,   453,   454,   455,   456,
     457,   458,     6,    45,     3,     4,     5,    48,   397,    31,
       9,   400,   401,   402,   471,   472,     3,     4,     5,     8,
      49,     9,     9,     9,     6,    29,    30,    31,    32,     8,
       6,     9,    31,    45,     8,     8,    48,    49,     6,    28,
      29,    30,    31,    32,    31,     8,    28,    29,    30,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,     8,
      28,    29,    30,     9,     8,    28,    29,    30,    31,    32,
       8,     3,     4,     5,     8,    16,     9,     9,     9,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,     9,
      28,    29,    30,    31,    32,    29,    30,    31,    32,    10,
       8,     6,    10,    57,    10,    16,    17,    18,    19,    20,
      10,     9,    57,    21,    22,    10,    53,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    10,    16,
      17,    18,    16,    10,     3,    28,    29,    30,    31,    32,
      10,    52,     3,    30,    31,    10,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,    57,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    10,    96,
      97,    98,    99,    10,    28,    29,    30,    31,    32,    10,
       4,    28,    29,    57,    10,    32,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    10,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,     3,    28,
      29,     3,    10,    32,    28,    29,    30,    31,    32,    10,
      16,    57,    57,    16,    10,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,    10,     3,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,     3,    29,
      29,    10,    29,    10,    29,    30,    31,    32,     3,     4,
       5,    32,     8,     3,     9,     8,    29,    30,    31,    32,
      29,    30,    31,    32,    16,    17,    18,    19,    20,    28,
      29,    30,    31,    32,     9,     9,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,     3,     3,    11,     9,
       9,     9,    29,    29,     3,     6,    29,     3,     6,     3,
      58,    11,     9,     3,     9,     6,     9,     9,     3,     6,
       3,     3,     3,     3,    29,    29,    12,     3,     3,     8,
       8,     8,     6,     6,     3,     3,     8,     8,    57,     6,
       3,    74,    12,    32,    32,    10,    10,     9,     8,    10,
       7,    10,     3,     8,     6,    21,     3,    15,     8,     3,
       3,     3,   194,     3,     3,     3,     3,   361,     3,   198,
       3,    73,    21,    29,    10,    29,    29,     6,   371,    11,
     399,    29,     9,    29,    29,    16,     9,     9,    29,   434,
      16,    12,    -1,    -1,    -1,    29,    15,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    37,    -1,    -1,    33,    32,    41,    -1,    -1,
      40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,     3,     4,     5,     9,    38,    39,    40,    46,    47,
      54,    55,    60,    61,    66,    69,    70,   102,   103,   105,
      16,   105,     9,     9,    16,    16,     9,     9,     0,    50,
      51,    76,    77,    79,    45,    48,    49,    67,    68,    71,
      72,    74,    70,    69,   102,     6,    28,    29,    30,   105,
      10,     9,    31,    33,    34,    35,    36,    37,    41,    42,
      43,   106,   107,     4,     5,     5,   106,   106,    16,    16,
      52,    53,    81,    82,    89,    79,    77,    26,    27,    16,
      16,    71,    67,   102,    74,    72,   105,   105,   105,     6,
     106,   106,     9,     9,     9,     9,     9,     9,     9,     9,
      10,    28,    29,    30,    31,    32,     8,     6,     6,     8,
       8,    57,    57,    16,    16,    89,    82,     3,     3,    57,
      57,   102,    10,   106,   106,   106,     3,     4,     5,     9,
      31,   108,   109,   108,   108,   108,   108,   106,   106,   106,
     106,   106,     4,     3,     4,     5,   104,   104,     3,    78,
       3,    80,    57,    57,    16,    16,     3,    73,     3,    75,
      10,     8,     8,    29,    29,    29,     3,     4,     5,     9,
      31,    33,    34,    35,    63,     3,     4,     5,     9,    10,
      30,    31,    10,    10,    10,    10,    10,     8,     8,     8,
      58,     8,    58,     9,    83,    84,     9,    90,    91,    63,
       3,     5,     9,    31,    33,    34,    35,    62,     8,    58,
       8,    58,   106,   106,     3,     3,     3,    11,    63,    63,
       9,     9,     9,    10,    28,    29,    30,    31,    32,    29,
      29,    29,    63,   109,   109,   104,   104,     3,     6,     3,
       6,     3,    58,    84,     9,    58,    90,     6,    11,    62,
      62,     9,     9,     9,     6,    29,    30,    31,    32,     3,
       6,     3,     6,    10,    10,     3,    65,    10,    63,    63,
      63,    29,    63,    63,    63,    63,    63,     3,     3,     3,
      10,     8,     8,     8,     6,     3,     6,    65,    10,    62,
      62,    62,    62,    62,    62,    62,     8,    12,    10,     8,
       8,     3,    29,   104,   104,     9,    23,    24,    25,    63,
      87,    88,     8,    12,    10,    28,     8,     8,    65,    63,
      63,     3,    10,    10,    63,    87,    87,    16,    17,    18,
      19,    20,     8,    10,    21,    22,     3,    62,    62,    62,
      10,    10,    10,    63,    63,    63,    63,    63,     9,     6,
      87,    87,    10,    10,    10,    10,     3,    85,    86,     8,
       7,     8,    10,    13,    14,    57,    92,    93,    63,    86,
      10,    15,     3,    94,     8,     6,    93,     8,    58,     3,
       4,     5,     9,    13,    31,    95,    96,    97,    98,     3,
      29,    29,    29,    63,     3,     4,     5,     9,     8,    21,
      16,    17,    18,    30,    31,     3,     3,     3,    10,    29,
      29,    29,    63,    13,    57,    99,    95,    63,    63,    63,
      98,    98,    29,     3,     3,     3,    10,     3,   100,   101,
      10,     3,    29,    16,     8,    58,     6,     3,     3,     4,
       5,     9,    31,    33,    34,    35,    64,   101,    11,    64,
      64,     9,     9,     9,    28,    29,    30,    31,    32,    65,
      10,    64,    64,    64,    64,    64,    64,    64,    64,    12,
      10,     8,     8,    64,    64,    10,    10
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
     305,   306,   307,   308,   309,   310,   311,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    70,    71,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    92,
      92,    92,    92,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109
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
       1,     2,     4,     2,     1,     1,     1,     4,     1,     6,
      10,    10,     3,     3,     3,     3,     1,     1,     1,     6,
       6,     2,     4,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     1,     3,     3,     1,     5,     3,
       3,     1,     1,     3,     2,     6,     4,     4,     4
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
  "FLOOR", "MIN", "MAX", "LhaMIN", "LhaMAX", "AVG", "PROB", "SPRT", "LAST",
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
        60,     0,    -1,    61,    76,    81,    -1,   102,    -1,    66,
      67,    71,   102,    -1,    66,    71,   102,    -1,     5,    -1,
       3,    -1,     3,    11,    65,    12,    -1,     9,    62,    10,
      -1,    31,    62,    -1,    62,    30,    62,    -1,    62,    31,
      62,    -1,    62,    29,    62,    -1,    62,    32,    62,    -1,
      33,     9,    62,    10,    -1,    33,     9,    62,    28,    62,
      10,    -1,    34,     9,    62,     8,    62,    10,    -1,    35,
       9,    62,     8,    62,    10,    -1,     4,    -1,     5,    -1,
       3,    -1,     3,    11,    65,    12,    -1,     9,    63,    10,
      -1,    31,    63,    -1,    63,    28,    63,    -1,    63,    30,
      63,    -1,    63,    31,    63,    -1,    63,    29,    63,    -1,
      63,    32,    63,    -1,    33,     9,    63,    10,    -1,    34,
       9,    63,     8,    63,    10,    -1,    35,     9,    63,     8,
      63,    10,    -1,     4,    -1,     5,    -1,     3,    -1,     3,
      11,    65,    12,    -1,     9,    64,    10,    -1,    31,    64,
      -1,    64,    28,    64,    -1,    64,    30,    64,    -1,    64,
      31,    64,    -1,    64,    29,    64,    -1,    64,    32,    64,
      -1,    33,     9,    64,    10,    -1,    34,     9,    64,     8,
      64,    10,    -1,    35,     9,    64,     8,    64,    10,    -1,
       3,    -1,     3,     8,    65,    -1,    70,    69,    -1,    69,
      70,    -1,    68,    -1,    68,    67,    -1,    45,    27,     3,
      16,    62,     6,    -1,    45,    26,     3,    16,    63,     6,
      -1,    47,    16,     5,     6,    -1,    46,    16,     5,     6,
      -1,    72,    74,    -1,    74,    72,    -1,    48,    16,    57,
      73,    58,     6,    -1,     3,    -1,    73,     8,     3,    -1,
      49,    16,    57,    75,    58,     6,    -1,     3,    -1,    75,
       8,     3,    -1,    77,    79,    -1,    79,    77,    -1,    50,
      16,    57,    78,    58,     6,    -1,     3,    -1,    78,     8,
       3,    -1,    51,    16,    57,    80,    58,     6,    -1,     3,
      -1,    80,     8,     3,    -1,    82,    89,    -1,    89,    82,
      -1,    52,    16,    57,    83,    58,     6,    -1,    84,    -1,
      83,    84,    -1,     9,     3,     8,    87,     8,     9,    85,
      10,    10,     6,    -1,     9,     3,     8,    87,    10,     6,
      -1,    86,    -1,    85,     8,    86,    -1,     3,     7,    63,
      -1,    24,    -1,    25,    -1,    88,    -1,    87,    21,    87,
      -1,    87,    22,    87,    -1,     9,    87,    10,    -1,    23,
      87,    -1,    63,    16,    63,    -1,    63,    18,    63,    -1,
      63,    17,    63,    -1,    63,    19,    63,    -1,    63,    20,
      63,    -1,    53,    16,    57,    90,    58,     6,    -1,    91,
      -1,    91,    90,    -1,     9,     9,     3,     8,     3,    10,
       8,    92,     8,    95,     8,    99,    10,     6,    -1,    13,
      -1,    14,    -1,    14,    15,    93,    -1,    93,    -1,    57,
      94,    58,    -1,     3,    -1,    94,     8,     3,    -1,    96,
      -1,    96,    21,    95,    -1,    13,    -1,    97,    16,    63,
      -1,    97,    18,    63,    -1,    97,    17,    63,    -1,    98,
      -1,    97,    31,    98,    -1,    97,    30,    98,    -1,     3,
      -1,     9,    63,    10,    29,     3,    -1,     5,    29,     3,
      -1,     4,    29,     3,    -1,     3,    29,     3,    -1,    31,
       3,    -1,    31,     9,    63,    10,    29,     3,    -1,    31,
       5,    29,     3,    -1,    31,     4,    29,     3,    -1,    31,
       3,    29,     3,    -1,    57,   100,    58,    -1,    13,    -1,
     101,    -1,   100,     8,   101,    -1,     3,    16,    64,    -1,
     103,    -1,   103,   102,    -1,     3,    16,   105,     6,    -1,
     105,     6,    -1,     4,    -1,     5,    -1,     3,    -1,    38,
       9,   106,    10,    -1,    39,    -1,    40,     9,     4,     8,
       4,    10,    -1,    54,     9,   106,     8,   104,     8,   104,
       8,   104,    10,    -1,    55,     9,   106,     8,   104,     8,
     104,     8,   104,    10,    -1,     9,   105,    10,    -1,   105,
      30,   105,    -1,   105,    29,   105,    -1,   105,    28,   105,
      -1,     5,    -1,     4,    -1,   107,    -1,    34,     9,   106,
       8,   106,    10,    -1,    35,     9,   106,     8,   106,    10,
      -1,    31,   106,    -1,    33,     9,   106,    10,    -1,     9,
     106,    10,    -1,   106,    32,   106,    -1,   106,    30,   106,
      -1,   106,    31,   106,    -1,   106,    29,   106,    -1,   106,
      28,   106,    -1,    41,     9,   108,    10,    -1,    36,     9,
     108,    10,    -1,    37,     9,   108,    10,    -1,    42,     9,
     108,    10,    -1,    43,     9,   108,    10,    -1,   109,    -1,
     108,    31,   109,    -1,   108,    30,   109,    -1,     3,    -1,
       9,    63,    10,    29,     3,    -1,     5,    29,     3,    -1,
       4,    29,     3,    -1,     5,    -1,     4,    -1,     3,    29,
       3,    -1,    31,     3,    -1,    31,     9,    63,    10,    29,
       3,    -1,    31,     5,    29,     3,    -1,    31,     4,    29,
       3,    -1,    31,     3,    29,     3,    -1
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
     553,   564,   575,   579,   583,   587,   591,   593,   595,   597,
     604,   611,   614,   619,   623,   627,   631,   635,   639,   643,
     648,   653,   658,   663,   668,   670,   674,   678,   680,   686,
     690,   694,   696,   698,   702,   705,   712,   717,   722
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   181,   181,   182,   184,   185,   191,   192,   202,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   221,
     222,   223,   235,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   253,   254,   255,   274,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   292,   293,   295,
     296,   298,   299,   301,   310,   321,   325,   329,   330,   332,
     365,   374,   382,   389,   395,   400,   401,   403,   405,   413,
     418,   420,   428,   437,   438,   442,   449,   450,   452,   471,
     493,   494,   495,   501,   502,   503,   504,   505,   506,   507,
     509,   510,   511,   512,   513,   518,   522,   523,   525,   549,
     550,   551,   555,   557,   559,   563,   568,   569,   570,   572,
     577,   582,   588,   589,   590,   592,   596,   601,   606,   611,
     632,   636,   641,   646,   651,   674,   675,   677,   678,   680,
     686,   686,   688,   699,   712,   713,   714,   724,   728,   731,
     734,   750,   767,   770,   773,   776,   779,   782,   786,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,   800,
     810,   820,   830,   840,   851,   852,   853,   855,   865,   870,
     875,   881,   884,   887,   906,   910,   915,   920,   925
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
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      55,    56
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 690;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 28;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 59;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 311;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1135 of lalr1.cc  */
#line 2826 "Lha-parser.tab.cc"
/* Line 1136 of lalr1.cc  */
#line 949 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
