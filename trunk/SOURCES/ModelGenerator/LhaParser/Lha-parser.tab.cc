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
#line 161 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 425 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 425 of lalr1.cc  */
#line 165 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 425 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 425 of lalr1.cc  */
#line 164 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 425 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 105: /* rorival */
/* Line 425 of lalr1.cc  */
#line 165 "Lha-parser.yy"
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
#line 162 "Lha-parser.yy"
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
#line 192 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 193 "Lha-parser.yy"
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
#line 203 "Lha-parser.yy"
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
#line 210 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 211 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 212 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 213 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 214 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 215 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 216 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 217 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 218 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 219 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 224 "Lha-parser.yy"
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
#line 236 "Lha-parser.yy"
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
#line 243 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 244 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 245 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 246 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 247 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 248 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 249 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 250 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 31:
/* Line 664 of lalr1.cc  */
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 32:
/* Line 664 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:
/* Line 664 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 34:
/* Line 664 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 35:
/* Line 664 of lalr1.cc  */
#line 256 "Lha-parser.yy"
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
#line 275 "Lha-parser.yy"
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
#line 282 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 38:
/* Line 664 of lalr1.cc  */
#line 283 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 39:
/* Line 664 of lalr1.cc  */
#line 284 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 664 of lalr1.cc  */
#line 285 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 41:
/* Line 664 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 42:
/* Line 664 of lalr1.cc  */
#line 287 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 43:
/* Line 664 of lalr1.cc  */
#line 288 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 289 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 290 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 291 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 664 of lalr1.cc  */
#line 293 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]", (yysemantic_stack_[(1) - (1)].name)->c_str()); }
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 294 "Lha-parser.yy"
    {sprintf((yyval.expression),"[%s]%s", (yysemantic_stack_[(3) - (1)].name)->c_str(), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 303 "Lha-parser.yy"
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
#line 312 "Lha-parser.yy"
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
#line 322 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 326 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 59:
/* Line 664 of lalr1.cc  */
#line 333 "Lha-parser.yy"
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
#line 366 "Lha-parser.yy"
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
#line 373 "Lha-parser.yy"
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
#line 382 "Lha-parser.yy"
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
#line 389 "Lha-parser.yy"
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
#line 397 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 65:
/* Line 664 of lalr1.cc  */
#line 404 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 66:
/* Line 664 of lalr1.cc  */
#line 410 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 70:
/* Line 664 of lalr1.cc  */
#line 420 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 71:
/* Line 664 of lalr1.cc  */
#line 428 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 73:
/* Line 664 of lalr1.cc  */
#line 435 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 74:
/* Line 664 of lalr1.cc  */
#line 443 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 77:
/* Line 664 of lalr1.cc  */
#line 457 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 80:
/* Line 664 of lalr1.cc  */
#line 468 "Lha-parser.yy"
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
#line 489 "Lha-parser.yy"
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
#line 510 "Lha-parser.yy"
    {if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 85:
/* Line 664 of lalr1.cc  */
#line 516 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 86:
/* Line 664 of lalr1.cc  */
#line 517 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 87:
/* Line 664 of lalr1.cc  */
#line 518 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 88:
/* Line 664 of lalr1.cc  */
#line 519 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:
/* Line 664 of lalr1.cc  */
#line 520 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 90:
/* Line 664 of lalr1.cc  */
#line 521 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 91:
/* Line 664 of lalr1.cc  */
#line 522 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 92:
/* Line 664 of lalr1.cc  */
#line 524 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 93:
/* Line 664 of lalr1.cc  */
#line 525 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 94:
/* Line 664 of lalr1.cc  */
#line 526 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 95:
/* Line 664 of lalr1.cc  */
#line 527 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 96:
/* Line 664 of lalr1.cc  */
#line 528 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 97:
/* Line 664 of lalr1.cc  */
#line 533 "Lha-parser.yy"
    {
	
}
    break;

  case 100:
/* Line 664 of lalr1.cc  */
#line 540 "Lha-parser.yy"
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
#line 565 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 103:
/* Line 664 of lalr1.cc  */
#line 566 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 106:
/* Line 664 of lalr1.cc  */
#line 574 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 107:
/* Line 664 of lalr1.cc  */
#line 578 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 108:
/* Line 664 of lalr1.cc  */
#line 583 "Lha-parser.yy"
    {}
    break;

  case 109:
/* Line 664 of lalr1.cc  */
#line 584 "Lha-parser.yy"
    {}
    break;

  case 111:
/* Line 664 of lalr1.cc  */
#line 588 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 112:
/* Line 664 of lalr1.cc  */
#line 593 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 113:
/* Line 664 of lalr1.cc  */
#line 598 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 117:
/* Line 664 of lalr1.cc  */
#line 608 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 664 of lalr1.cc  */
#line 612 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 119:
/* Line 664 of lalr1.cc  */
#line 617 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 120:
/* Line 664 of lalr1.cc  */
#line 622 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 121:
/* Line 664 of lalr1.cc  */
#line 627 "Lha-parser.yy"
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
#line 648 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 123:
/* Line 664 of lalr1.cc  */
#line 652 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 124:
/* Line 664 of lalr1.cc  */
#line 657 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 125:
/* Line 664 of lalr1.cc  */
#line 662 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 126:
/* Line 664 of lalr1.cc  */
#line 667 "Lha-parser.yy"
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
#line 689 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 128:
/* Line 664 of lalr1.cc  */
#line 690 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 131:
/* Line 664 of lalr1.cc  */
#line 695 "Lha-parser.yy"
    {
	if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (1)].name))]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 134:
/* Line 664 of lalr1.cc  */
#line 703 "Lha-parser.yy"
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
#line 714 "Lha-parser.yy"
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
#line 727 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 137:
/* Line 664 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 138:
/* Line 664 of lalr1.cc  */
#line 729 "Lha-parser.yy"
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
#line 739 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 140:
/* Line 664 of lalr1.cc  */
#line 743 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 141:
/* Line 664 of lalr1.cc  */
#line 746 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel,(yysemantic_stack_[(6) - (3)].RealVal),(yysemantic_stack_[(6) - (5)].RealVal));
}
    break;

  case 142:
/* Line 664 of lalr1.cc  */
#line 749 "Lha-parser.yy"
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

  case 143:
/* Line 664 of lalr1.cc  */
#line 765 "Lha-parser.yy"
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

  case 144:
/* Line 664 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 145:
/* Line 664 of lalr1.cc  */
#line 785 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 146:
/* Line 664 of lalr1.cc  */
#line 788 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 147:
/* Line 664 of lalr1.cc  */
#line 791 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 148:
/* Line 664 of lalr1.cc  */
#line 794 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 149:
/* Line 664 of lalr1.cc  */
#line 797 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 150:
/* Line 664 of lalr1.cc  */
#line 801 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 151:
/* Line 664 of lalr1.cc  */
#line 804 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 152:
/* Line 664 of lalr1.cc  */
#line 805 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 153:
/* Line 664 of lalr1.cc  */
#line 806 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 154:
/* Line 664 of lalr1.cc  */
#line 807 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 155:
/* Line 664 of lalr1.cc  */
#line 808 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 156:
/* Line 664 of lalr1.cc  */
#line 809 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 157:
/* Line 664 of lalr1.cc  */
#line 810 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 158:
/* Line 664 of lalr1.cc  */
#line 811 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 159:
/* Line 664 of lalr1.cc  */
#line 812 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 160:
/* Line 664 of lalr1.cc  */
#line 813 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 161:
/* Line 664 of lalr1.cc  */
#line 815 "Lha-parser.yy"
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

  case 162:
/* Line 664 of lalr1.cc  */
#line 825 "Lha-parser.yy"
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

  case 163:
/* Line 664 of lalr1.cc  */
#line 835 "Lha-parser.yy"
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

  case 164:
/* Line 664 of lalr1.cc  */
#line 845 "Lha-parser.yy"
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

  case 165:
/* Line 664 of lalr1.cc  */
#line 855 "Lha-parser.yy"
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

  case 166:
/* Line 664 of lalr1.cc  */
#line 866 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 167:
/* Line 664 of lalr1.cc  */
#line 867 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 168:
/* Line 664 of lalr1.cc  */
#line 868 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 169:
/* Line 664 of lalr1.cc  */
#line 871 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"Vars->%s", (yysemantic_stack_[(1) - (1)].name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yysemantic_stack_[(1) - (1)].name)->c_str();
			if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yysemantic_stack_[(1) - (1)].name)]].colorDom !=0 )s <<".card()";
		sprintf((yyval.expression), "%s ",(s.str()).c_str());
	} else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable or a place name"<<endl;YYABORT;}
}
    break;

  case 170:
/* Line 664 of lalr1.cc  */
#line 881 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"(%s) * Vars->%s", (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (5)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 171:
/* Line 664 of lalr1.cc  */
#line 886 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%d * Vars->%s", (yysemantic_stack_[(3) - (1)].IntVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 172:
/* Line 664 of lalr1.cc  */
#line 891 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"%f * Vars->%s", (yysemantic_stack_[(3) - (1)].RealVal), (yysemantic_stack_[(3) - (3)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 173:
/* Line 664 of lalr1.cc  */
#line 897 "Lha-parser.yy"
    { sprintf((yyval.expression),"%i ", (yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 174:
/* Line 664 of lalr1.cc  */
#line 900 "Lha-parser.yy"
    { sprintf((yyval.expression),"%f ", (yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 175:
/* Line 664 of lalr1.cc  */
#line 903 "Lha-parser.yy"
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

  case 176:
/* Line 664 of lalr1.cc  */
#line 922 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-Vars->%s", (yysemantic_stack_[(2) - (2)].name)->c_str());}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 177:
/* Line 664 of lalr1.cc  */
#line 926 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-(%s) * Vars->%s", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (6)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 178:
/* Line 664 of lalr1.cc  */
#line 931 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%d * Vars->%s", (yysemantic_stack_[(4) - (2)].IntVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 179:
/* Line 664 of lalr1.cc  */
#line 936 "Lha-parser.yy"
    { if(Reader.MyLha.Vars.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yyval.expression),"-%f * Vars->%s", (yysemantic_stack_[(4) - (2)].RealVal), (yysemantic_stack_[(4) - (4)].name)->c_str());
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 180:
/* Line 664 of lalr1.cc  */
#line 941 "Lha-parser.yy"
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
#line 1898 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -292;
  const short int
  Lha_parser::yypact_[] =
  {
        67,     5,  -292,  -292,   107,    49,  -292,   104,   108,   155,
     120,   184,   234,    36,   518,   194,   196,  -292,    99,   195,
     107,   522,   148,   191,   237,   244,   148,   148,  -292,   239,
     246,   -14,   221,   223,    93,   271,   273,    85,   251,    99,
     248,   253,  -292,  -292,  -292,  -292,   107,   107,   107,   328,
    -292,   148,   148,   294,   295,   321,   351,   390,   402,   403,
     404,   201,  -292,   406,   326,   419,   263,   277,   364,   392,
     435,   436,  -292,   399,   409,  -292,  -292,   452,   460,   407,
     420,    99,  -292,  -292,  -292,  -292,  -292,  -292,   171,  -292,
     360,   141,   148,   148,   148,    87,    87,    87,    87,    87,
    -292,   148,   148,   148,   148,   148,   486,  -292,  -292,    26,
      26,   461,   488,   434,   443,  -292,  -292,   477,   487,    12,
     499,  -292,  -292,   365,   282,   288,   476,   489,   504,   205,
     324,     4,  -292,    79,   111,   118,   182,   474,   474,   141,
     141,  -292,   524,  -292,  -292,  -292,   520,   532,  -292,    -7,
    -292,    -5,   554,   556,   205,   217,  -292,   563,     3,  -292,
       8,  -292,   148,   148,   566,   567,   568,   561,  -292,  -292,
     205,   205,   564,   565,   569,   372,   546,   547,   548,   205,
    -292,    87,    87,  -292,  -292,  -292,  -292,  -292,    26,    26,
     576,   574,   578,   577,   579,    19,  -292,   575,   527,   556,
     250,   580,  -292,   217,   217,   581,   583,   584,    14,  -292,
      35,   582,   586,   588,   377,   388,  -292,  -292,  -292,   592,
     400,   344,   205,   205,   205,   558,   205,   205,   205,   205,
     205,   593,   594,   595,   405,  -292,  -292,   591,   596,  -292,
    -292,  -292,  -292,   597,   600,  -292,   598,   601,  -292,  -292,
     592,   490,   342,   217,   217,   217,  -292,   217,   217,   217,
     217,  -292,   599,  -292,  -292,  -292,  -292,  -292,   602,   573,
    -292,   411,   293,   307,   605,   571,   571,   344,   344,  -292,
    -292,  -292,  -292,   585,    26,    26,   163,  -292,   603,  -292,
     604,  -292,   416,   229,   332,   587,   342,   342,  -292,  -292,
     592,  -292,  -292,   205,   205,  -292,   606,   590,   607,   163,
     163,  -292,  -292,   525,   278,  -292,   609,  -292,  -292,   217,
     217,   217,  -292,   428,   439,  -292,  -292,  -292,   349,   143,
    -292,   205,   205,   205,   205,   205,   611,   612,   163,   163,
     613,   494,   507,   517,  -292,  -292,  -292,   313,   313,   313,
     313,   313,   610,  -292,  -292,   608,   614,  -292,  -292,  -292,
     617,    43,  -292,    -1,   205,   610,   615,  -292,   616,   618,
     619,  -292,   313,  -292,   620,   557,  -292,     9,   127,  -292,
    -292,   625,  -292,   621,   622,   623,   205,  -292,   526,   624,
     626,     6,  -292,  -292,   627,   630,   631,   444,   628,   629,
     632,   205,    -9,   127,   205,   205,   205,   147,   147,  -292,
    -292,  -292,   633,   634,   635,   636,   451,  -292,   637,   638,
    -292,   313,   313,   313,  -292,  -292,   639,  -292,  -292,  -292,
     640,   643,    18,  -292,   647,  -292,   641,   212,   637,  -292,
    -292,  -292,   644,  -292,  -292,   212,   212,   645,   651,   654,
     530,  -292,   592,   456,   395,   212,   212,   212,   212,   212,
     212,   212,   212,   652,  -292,   467,   318,   323,   642,   642,
     395,   395,  -292,  -292,  -292,   212,   212,   479,   484,  -292,
    -292
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Lha_parser::yydefact_[] =
  {
         0,     0,   149,   148,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,    50,    49,   133,   135,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    67,    68,     0,     0,     0,
       0,     0,    52,     5,    57,    58,   147,   146,   145,   134,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     4,   155,     0,     0,     0,   169,   174,   173,     0,
       0,     0,   166,     0,     0,     0,     0,   160,   159,   157,
     158,   156,     0,   138,   136,   137,     0,     0,    70,     0,
      73,     0,     0,     0,     0,     0,    60,     0,     0,    65,
       0,   154,     0,     0,     0,     0,     0,    21,    19,    20,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     162,     0,     0,   163,   161,   164,   165,   141,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    98,
       0,     7,     6,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,   175,   172,   171,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,   167,     0,     0,    71,
      69,    74,    72,     0,     0,    79,     0,     0,    99,    54,
       0,     0,    10,     0,     0,     0,    53,     0,     0,     0,
       0,    62,     0,    59,    66,    64,   151,   152,    47,     0,
      23,     0,     0,     0,     0,    25,    28,    26,    27,    29,
     180,   179,   178,     0,     0,     0,     0,    77,     0,    97,
       0,     9,     0,     0,     0,    13,    11,    12,    14,    63,
       0,    22,    30,     0,     0,   170,     0,     0,     0,     0,
       0,    85,    86,     0,     0,    87,     0,     8,    15,     0,
       0,     0,    48,     0,     0,   177,   142,   143,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    90,    92,    94,    93,
      95,    96,     0,    81,    88,    89,     0,    16,    17,    18,
       0,     0,    82,     0,     0,     0,     0,   101,   102,     0,
       0,   104,    84,    83,     0,     0,   106,     0,     0,    80,
     103,     0,   105,   117,     0,     0,     0,   110,     0,     0,
     108,     0,   114,   107,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     120,   119,     0,     0,     0,     0,     0,   128,     0,     0,
     109,   111,   113,   112,   116,   115,     0,   126,   125,   124,
       0,     0,     0,   129,     0,   118,     0,     0,     0,   127,
     100,   123,    35,    33,    34,     0,     0,     0,     0,     0,
     131,   130,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    39,    42,
      40,    41,    43,    36,    44,     0,     0,     0,     0,    45,
      46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -292,  -292,  -292,  -194,  -129,  -192,  -245,  -292,   646,  -292,
     649,   653,   648,   650,  -292,   655,  -292,  -292,   656,  -292,
     658,  -292,  -292,   562,  -292,   440,  -292,   276,  -291,  -292,
     570,   446,  -292,  -292,   274,  -292,   243,  -292,  -292,  -189,
    -292,  -292,   218,   -12,  -292,  -108,   113,   -19,  -292,   287,
      46
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,    12,    13,   208,   313,   450,   269,    14,    37,    38,
      15,    16,    39,    40,   158,    41,   160,    31,    32,   149,
      33,   151,    72,    73,   195,   196,   361,   362,   314,   315,
      74,   198,   199,   370,   371,   377,   389,   390,   391,   392,
     419,   432,   433,    17,    18,   146,    19,    61,    62,   131,
     132
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       175,   190,   147,   192,   417,   290,    44,    66,    67,   251,
     252,   210,   367,   368,   180,   156,   212,   381,   329,   330,
     256,    20,   404,   405,   406,   200,   438,    83,   194,   143,
     144,   145,    90,    91,   181,   182,   407,   408,   261,    70,
      71,   220,   221,   257,   258,   259,   260,   354,   355,   418,
     234,   365,   191,   366,   193,   322,   157,   369,    22,   292,
     293,   294,   211,   295,   296,   297,   298,   213,   382,   121,
       1,     2,     3,   123,   124,   125,     4,   439,   244,   262,
     237,   238,   137,   138,   139,   140,   141,    29,    30,   183,
     126,   127,   128,   271,   272,   273,   129,   275,   276,   277,
     278,   279,     1,     2,     3,     5,     6,     7,     4,   181,
     182,     2,     3,    23,     8,     9,     4,    21,   130,    77,
      78,   184,    10,    11,    24,   341,   342,   343,   185,    26,
     383,   384,   385,    49,    35,    36,   386,     5,     6,     7,
     387,   181,   182,   214,   215,     5,     6,     7,   181,   182,
     383,   384,   385,   346,    10,    11,   386,    51,   388,    86,
      87,    88,    10,    11,   338,   339,   167,   168,   169,   101,
     102,    25,   309,   105,   323,   324,   307,   308,   388,    52,
     328,    53,    54,    55,    56,    57,   310,   311,   312,    58,
      59,    60,   186,    27,   171,    63,   172,   173,   174,    46,
      47,    45,   347,   348,   349,   350,   351,   463,   167,   168,
     169,   100,   181,   182,   170,   442,   443,   444,   424,   425,
     201,   445,   202,    46,    47,    48,   203,   235,   236,   101,
     102,   103,   104,   105,    28,   372,   171,   320,   172,   173,
     174,     8,    64,   446,     9,   447,   448,   449,   204,    65,
     205,   206,   207,   453,   454,    68,   249,   397,   257,   258,
     259,   260,    69,   465,   466,   467,   468,   469,   470,   471,
     472,   109,   416,    30,    29,   421,   422,   423,   226,   227,
     228,   229,   230,   477,   478,   110,   336,    79,   337,    80,
     162,   101,   102,   103,   104,   105,   163,    34,    36,   338,
     339,   303,    35,    92,    93,   101,   102,   103,   104,   105,
     101,   102,   103,   104,   105,   304,   101,   102,   103,   104,
     105,   226,   227,   228,   229,   230,   475,   176,   177,   178,
      94,   476,   107,   179,    89,   226,   227,   228,   229,   230,
     321,   226,   227,   228,   229,   230,   458,   459,   460,   461,
     462,   458,   459,   460,   461,   462,    46,    47,    48,   270,
      95,   257,   258,   259,   260,   331,   332,   333,   334,   335,
     122,   257,   226,   227,   260,   161,   230,   226,   227,   228,
     229,   230,   225,   133,   134,   135,   136,   266,   101,   102,
     103,   104,   105,   101,   102,   103,   104,   105,   267,    96,
     226,   227,   228,   229,   230,   101,   102,   103,   104,   105,
     270,    97,    98,    99,   106,   283,   101,   102,   103,   104,
     105,   302,   111,   458,   459,   108,   318,   462,   226,   227,
     228,   229,   230,   226,   227,   228,   229,   230,   344,   226,
     227,   228,   229,   230,   319,   257,   258,   259,   260,   345,
     112,   113,   114,    71,   412,   117,   226,   227,   228,   229,
     230,   430,    70,   118,   148,   119,   464,   226,   227,   228,
     229,   230,   226,   227,   228,   229,   230,   474,   120,   226,
     227,   228,   229,   230,   458,   459,   460,   461,   462,   479,
     142,   150,   152,   154,   480,   458,   459,   460,   461,   462,
     291,   153,   159,   155,   357,   164,   105,   458,   459,   460,
     461,   462,   458,   459,   460,   461,   462,   358,   165,   257,
     258,   259,   260,   257,   258,   259,   260,   359,   188,   398,
     399,   400,    50,   166,   187,   401,   257,   258,   259,   260,
     189,   331,   332,   333,   334,   335,   257,   258,   259,   260,
      46,    47,    48,   226,   227,   228,   229,   230,   458,   459,
     460,   461,   462,   194,    34,   197,   209,    35,    36,   216,
     217,   218,   219,   222,   223,   231,   232,   233,   224,   239,
     240,   241,   243,   242,   246,   301,   247,   274,   263,   264,
     253,   250,   254,   255,   265,   268,   280,   281,   282,   284,
     326,   288,   299,   230,   285,   286,   287,   289,   305,   325,
     300,   316,   340,   360,   306,   369,   317,   327,   353,   260,
     352,   376,   363,   356,   364,   374,   379,   378,   393,   338,
     409,   375,   402,   410,   411,   245,   116,   427,   428,   429,
     431,   373,   435,   115,   441,   248,   420,   403,   434,   380,
     394,   395,   396,   440,   455,   452,   451,   413,   414,   437,
     456,   415,   426,   457,   473,    43,     0,     0,    42,   436,
       0,     0,     0,     0,   462,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    81,     0,     0,     0,    76,
      75,    85,     0,     0,     0,    84
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
       129,     8,   110,     8,    13,   250,    18,    26,    27,   203,
     204,     8,    13,    14,    10,     3,     8,     8,   309,   310,
       6,    16,    16,    17,    18,   154,     8,    39,     9,     3,
       4,     5,    51,    52,    30,    31,    30,    31,     3,    53,
      54,   170,   171,    29,    30,    31,    32,   338,   339,    58,
     179,     8,    59,    10,    59,   300,    44,    58,     9,   253,
     254,   255,    59,   257,   258,   259,   260,    59,    59,    81,
       3,     4,     5,    92,    93,    94,     9,    59,    59,    44,
     188,   189,   101,   102,   103,   104,   105,    51,    52,    10,
       3,     4,     5,   222,   223,   224,     9,   226,   227,   228,
     229,   230,     3,     4,     5,    38,    39,    40,     9,    30,
      31,     4,     5,     9,    47,    48,     9,     4,    31,    26,
      27,    10,    55,    56,    16,   319,   320,   321,    10,     9,
       3,     4,     5,    20,    49,    50,     9,    38,    39,    40,
      13,    30,    31,   162,   163,    38,    39,    40,    30,    31,
       3,     4,     5,    10,    55,    56,     9,     9,    31,    46,
      47,    48,    55,    56,    21,    22,     3,     4,     5,    28,
      29,    16,     9,    32,   303,   304,   284,   285,    31,    31,
     309,    33,    34,    35,    36,    37,    23,    24,    25,    41,
      42,    43,    10,     9,    31,     4,    33,    34,    35,    28,
      29,     6,   331,   332,   333,   334,   335,   452,     3,     4,
       5,    10,    30,    31,     9,     3,     4,     5,   407,   408,
       3,     9,     5,    28,    29,    30,     9,   181,   182,    28,
      29,    30,    31,    32,     0,   364,    31,     8,    33,    34,
      35,    47,     5,    31,    48,    33,    34,    35,    31,     5,
      33,    34,    35,   445,   446,    16,     6,   386,    29,    30,
      31,    32,    16,   455,   456,   457,   458,   459,   460,   461,
     462,     8,   401,    52,    51,   404,   405,   406,    28,    29,
      30,    31,    32,   475,   476,     8,     8,    16,    10,    16,
       8,    28,    29,    30,    31,    32,     8,    46,    50,    21,
      22,     8,    49,     9,     9,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,     8,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,     8,     3,     4,     5,
       9,     8,     6,     9,     6,    28,    29,    30,    31,    32,
       8,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    28,    29,    30,    10,
       9,    29,    30,    31,    32,    16,    17,    18,    19,    20,
      10,    29,    28,    29,    32,    10,    32,    28,    29,    30,
      31,    32,    10,    96,    97,    98,    99,    10,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    10,     9,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      10,     9,     9,     9,     8,    10,    28,    29,    30,    31,
      32,    10,    58,    28,    29,     6,    10,    32,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    10,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    10,
      58,    16,    16,    54,    10,     3,    28,    29,    30,    31,
      32,    10,    53,     3,     3,    58,    10,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,    58,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    10,
       4,     3,    58,    16,    10,    28,    29,    30,    31,    32,
      10,    58,     3,    16,    10,    29,    32,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    10,    29,    29,
      30,    31,    32,    29,    30,    31,    32,    10,     8,     3,
       4,     5,    10,    29,    10,     9,    29,    30,    31,    32,
       8,    16,    17,    18,    19,    20,    29,    30,    31,    32,
      28,    29,    30,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,     9,    46,     9,     3,    49,    50,     3,
       3,     3,    11,     9,     9,    29,    29,    29,     9,     3,
       6,     3,     3,     6,     9,    12,    59,    29,     6,     3,
       9,    11,     9,     9,     6,     3,     3,     3,     3,     8,
      10,     3,     3,    32,     8,     8,     6,     6,     3,     3,
       8,     8,     3,     3,    29,    58,    12,    10,     6,    32,
       9,     3,     8,    10,     7,    10,     6,     8,     3,    21,
       3,    15,     8,     3,     3,   195,    74,     3,     3,     3,
       3,   365,     3,    73,     3,   199,   403,    21,    10,   375,
      29,    29,    29,     6,     9,    11,   438,    29,    29,    16,
       9,    29,    29,     9,    12,    16,    -1,    -1,    15,    29,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    37,    -1,    -1,    -1,    33,
      32,    41,    -1,    -1,    -1,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,     3,     4,     5,     9,    38,    39,    40,    47,    48,
      55,    56,    61,    62,    67,    70,    71,   103,   104,   106,
      16,   106,     9,     9,    16,    16,     9,     9,     0,    51,
      52,    77,    78,    80,    46,    49,    50,    68,    69,    72,
      73,    75,    71,    70,   103,     6,    28,    29,    30,   106,
      10,     9,    31,    33,    34,    35,    36,    37,    41,    42,
      43,   107,   108,     4,     5,     5,   107,   107,    16,    16,
      53,    54,    82,    83,    90,    80,    78,    26,    27,    16,
      16,    72,    68,   103,    75,    73,   106,   106,   106,     6,
     107,   107,     9,     9,     9,     9,     9,     9,     9,     9,
      10,    28,    29,    30,    31,    32,     8,     6,     6,     8,
       8,    58,    58,    16,    16,    90,    83,     3,     3,    58,
      58,   103,    10,   107,   107,   107,     3,     4,     5,     9,
      31,   109,   110,   109,   109,   109,   109,   107,   107,   107,
     107,   107,     4,     3,     4,     5,   105,   105,     3,    79,
       3,    81,    58,    58,    16,    16,     3,    44,    74,     3,
      76,    10,     8,     8,    29,    29,    29,     3,     4,     5,
       9,    31,    33,    34,    35,    64,     3,     4,     5,     9,
      10,    30,    31,    10,    10,    10,    10,    10,     8,     8,
       8,    59,     8,    59,     9,    84,    85,     9,    91,    92,
      64,     3,     5,     9,    31,    33,    34,    35,    63,     3,
       8,    59,     8,    59,   107,   107,     3,     3,     3,    11,
      64,    64,     9,     9,     9,    10,    28,    29,    30,    31,
      32,    29,    29,    29,    64,   110,   110,   105,   105,     3,
       6,     3,     6,     3,    59,    85,     9,    59,    91,     6,
      11,    63,    63,     9,     9,     9,     6,    29,    30,    31,
      32,     3,    44,     6,     3,     6,    10,    10,     3,    66,
      10,    64,    64,    64,    29,    64,    64,    64,    64,    64,
       3,     3,     3,    10,     8,     8,     8,     6,     3,     6,
      66,    10,    63,    63,    63,    63,    63,    63,    63,     3,
       8,    12,    10,     8,     8,     3,    29,   105,   105,     9,
      23,    24,    25,    64,    88,    89,     8,    12,    10,    28,
       8,     8,    66,    64,    64,     3,    10,    10,    64,    88,
      88,    16,    17,    18,    19,    20,     8,    10,    21,    22,
       3,    63,    63,    63,    10,    10,    10,    64,    64,    64,
      64,    64,     9,     6,    88,    88,    10,    10,    10,    10,
       3,    86,    87,     8,     7,     8,    10,    13,    14,    58,
      93,    94,    64,    87,    10,    15,     3,    95,     8,     6,
      94,     8,    59,     3,     4,     5,     9,    13,    31,    96,
      97,    98,    99,     3,    29,    29,    29,    64,     3,     4,
       5,     9,     8,    21,    16,    17,    18,    30,    31,     3,
       3,     3,    10,    29,    29,    29,    64,    13,    58,   100,
      96,    64,    64,    64,    99,    99,    29,     3,     3,     3,
      10,     3,   101,   102,    10,     3,    29,    16,     8,    59,
       6,     3,     3,     4,     5,     9,    31,    33,    34,    35,
      65,   102,    11,    65,    65,     9,     9,     9,    28,    29,
      30,    31,    32,    66,    10,    65,    65,    65,    65,    65,
      65,    65,    65,    12,    10,     8,     8,    65,    65,    10,
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
     305,   306,   307,   308,   309,   310,   311,   312,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Lha_parser::yyr1_[] =
  {
         0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    72,    72,    73,
      74,    74,    74,    74,    75,    76,    76,    77,    77,    78,
      79,    79,    80,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    90,    91,    91,
      92,    93,    93,    93,    93,    94,    95,    95,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   102,   103,   103,   104,   104,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110
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
       1,     6,    10,    10,     3,     3,     3,     3,     1,     1,
       1,     6,     6,     2,     4,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     1,     3,     3,     1,
       5,     3,     3,     1,     1,     3,     2,     6,     4,     4,
       4
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
  "INTEGRAL", "MEAN", "DISC", "LhaName", "Const", "NbLoc", "NbVar",
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
        61,     0,    -1,    62,    77,    82,    -1,   103,    -1,    67,
      68,    72,   103,    -1,    67,    72,   103,    -1,     5,    -1,
       3,    -1,     3,    11,    66,    12,    -1,     9,    63,    10,
      -1,    31,    63,    -1,    63,    30,    63,    -1,    63,    31,
      63,    -1,    63,    29,    63,    -1,    63,    32,    63,    -1,
      33,     9,    63,    10,    -1,    33,     9,    63,    28,    63,
      10,    -1,    34,     9,    63,     8,    63,    10,    -1,    35,
       9,    63,     8,    63,    10,    -1,     4,    -1,     5,    -1,
       3,    -1,     3,    11,    66,    12,    -1,     9,    64,    10,
      -1,    31,    64,    -1,    64,    28,    64,    -1,    64,    30,
      64,    -1,    64,    31,    64,    -1,    64,    29,    64,    -1,
      64,    32,    64,    -1,    33,     9,    64,    10,    -1,    34,
       9,    64,     8,    64,    10,    -1,    35,     9,    64,     8,
      64,    10,    -1,     4,    -1,     5,    -1,     3,    -1,     3,
      11,    66,    12,    -1,     9,    65,    10,    -1,    31,    65,
      -1,    65,    28,    65,    -1,    65,    30,    65,    -1,    65,
      31,    65,    -1,    65,    29,    65,    -1,    65,    32,    65,
      -1,    33,     9,    65,    10,    -1,    34,     9,    65,     8,
      65,    10,    -1,    35,     9,    65,     8,    65,    10,    -1,
       3,    -1,     3,     8,    66,    -1,    71,    70,    -1,    70,
      71,    -1,    69,    -1,    69,    68,    -1,    46,    27,     3,
      16,    63,     6,    -1,    46,    26,     3,    16,    64,     6,
      -1,    48,    16,     5,     6,    -1,    47,    16,     5,     6,
      -1,    73,    75,    -1,    75,    73,    -1,    49,    16,    58,
      74,    59,     6,    -1,     3,    -1,    44,     3,    -1,    74,
       8,     3,    -1,    74,     8,    44,     3,    -1,    50,    16,
      58,    76,    59,     6,    -1,     3,    -1,    76,     8,     3,
      -1,    78,    80,    -1,    80,    78,    -1,    51,    16,    58,
      79,    59,     6,    -1,     3,    -1,    79,     8,     3,    -1,
      52,    16,    58,    81,    59,     6,    -1,     3,    -1,    81,
       8,     3,    -1,    83,    90,    -1,    90,    83,    -1,    53,
      16,    58,    84,    59,     6,    -1,    85,    -1,    84,    85,
      -1,     9,     3,     8,    88,     8,     9,    86,    10,    10,
       6,    -1,     9,     3,     8,    88,    10,     6,    -1,    87,
      -1,    86,     8,    87,    -1,     3,     7,    64,    -1,    24,
      -1,    25,    -1,    89,    -1,    88,    21,    88,    -1,    88,
      22,    88,    -1,     9,    88,    10,    -1,    23,    88,    -1,
      64,    16,    64,    -1,    64,    18,    64,    -1,    64,    17,
      64,    -1,    64,    19,    64,    -1,    64,    20,    64,    -1,
      54,    16,    58,    91,    59,     6,    -1,    92,    -1,    92,
      91,    -1,     9,     9,     3,     8,     3,    10,     8,    93,
       8,    96,     8,   100,    10,     6,    -1,    13,    -1,    14,
      -1,    14,    15,    94,    -1,    94,    -1,    58,    95,    59,
      -1,     3,    -1,    95,     8,     3,    -1,    97,    -1,    97,
      21,    96,    -1,    13,    -1,    98,    16,    64,    -1,    98,
      18,    64,    -1,    98,    17,    64,    -1,    99,    -1,    98,
      31,    99,    -1,    98,    30,    99,    -1,     3,    -1,     9,
      64,    10,    29,     3,    -1,     5,    29,     3,    -1,     4,
      29,     3,    -1,     3,    29,     3,    -1,    31,     3,    -1,
      31,     9,    64,    10,    29,     3,    -1,    31,     5,    29,
       3,    -1,    31,     4,    29,     3,    -1,    31,     3,    29,
       3,    -1,    58,   101,    59,    -1,    13,    -1,   102,    -1,
     101,     8,   102,    -1,     3,    16,    65,    -1,   104,    -1,
     104,   103,    -1,     3,    16,   106,     6,    -1,   106,     6,
      -1,     4,    -1,     5,    -1,     3,    -1,    38,     9,   107,
      10,    -1,    39,    -1,    40,     9,     4,     8,     4,    10,
      -1,    55,     9,   107,     8,   105,     8,   105,     8,   105,
      10,    -1,    56,     9,   107,     8,   105,     8,   105,     8,
     105,    10,    -1,     9,   106,    10,    -1,   106,    30,   106,
      -1,   106,    29,   106,    -1,   106,    28,   106,    -1,     5,
      -1,     4,    -1,   108,    -1,    34,     9,   107,     8,   107,
      10,    -1,    35,     9,   107,     8,   107,    10,    -1,    31,
     107,    -1,    33,     9,   107,    10,    -1,     9,   107,    10,
      -1,   107,    32,   107,    -1,   107,    30,   107,    -1,   107,
      31,   107,    -1,   107,    29,   107,    -1,   107,    28,   107,
      -1,    41,     9,   109,    10,    -1,    36,     9,   109,    10,
      -1,    37,     9,   109,    10,    -1,    42,     9,   109,    10,
      -1,    43,     9,   109,    10,    -1,   110,    -1,   109,    31,
     110,    -1,   109,    30,   110,    -1,     3,    -1,     9,    64,
      10,    29,     3,    -1,     5,    29,     3,    -1,     4,    29,
       3,    -1,     5,    -1,     4,    -1,     3,    29,     3,    -1,
      31,     3,    -1,    31,     9,    64,    10,    29,     3,    -1,
      31,     5,    29,     3,    -1,    31,     4,    29,     3,    -1,
      31,     3,    29,     3,    -1
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
     552,   554,   561,   572,   583,   587,   591,   595,   599,   601,
     603,   605,   612,   619,   622,   627,   631,   635,   639,   643,
     647,   651,   656,   661,   666,   671,   676,   678,   682,   686,
     688,   694,   698,   702,   704,   706,   710,   713,   720,   725,
     730
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   182,   182,   183,   185,   186,   192,   193,   203,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   222,
     223,   224,   236,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   254,   255,   256,   275,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   293,   294,   296,
     297,   299,   300,   302,   311,   322,   326,   330,   331,   333,
     366,   373,   382,   389,   397,   404,   410,   415,   416,   418,
     420,   428,   433,   435,   443,   452,   453,   457,   464,   465,
     467,   486,   508,   509,   510,   516,   517,   518,   519,   520,
     521,   522,   524,   525,   526,   527,   528,   533,   537,   538,
     540,   564,   565,   566,   570,   572,   574,   578,   583,   584,
     585,   587,   592,   597,   603,   604,   605,   607,   611,   616,
     621,   626,   647,   651,   656,   661,   666,   689,   690,   692,
     693,   695,   701,   701,   703,   714,   727,   728,   729,   739,
     743,   746,   749,   765,   782,   785,   788,   791,   794,   797,
     801,   804,   805,   806,   807,   808,   809,   810,   811,   812,
     813,   815,   825,   835,   845,   855,   866,   867,   868,   870,
     880,   885,   890,   896,   899,   902,   921,   925,   930,   935,
     940
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
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      55,    56,    57
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Lha_parser::yyeof_ = 0;
  const int Lha_parser::yylast_ = 695;
  const int Lha_parser::yynnts_ = 51;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 28;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 60;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 312;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1135 of lalr1.cc  */
#line 2858 "Lha-parser.tab.cc"
/* Line 1136 of lalr1.cc  */
#line 964 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
