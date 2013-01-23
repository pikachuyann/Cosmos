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
#line 155 "Lha-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 423 of lalr1.cc  */
#line 256 "Lha-parser.tab.cc"
        break;
      case 4: /* rval */
/* Line 423 of lalr1.cc  */
#line 159 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 263 "Lha-parser.tab.cc"
        break;
      case 5: /* ival */
/* Line 423 of lalr1.cc  */
#line 158 "Lha-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 423 of lalr1.cc  */
#line 270 "Lha-parser.tab.cc"
        break;
      case 99: /* rorival */
/* Line 423 of lalr1.cc  */
#line 159 "Lha-parser.yy"
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
#line 156 "Lha-parser.yy"
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
#line 184 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 185 "Lha-parser.yy"
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
#line 195 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 196 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 197 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 198 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 199 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 200 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 201 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 202 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s))", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 203 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 204 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 207 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 208 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 209 "Lha-parser.yy"
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
#line 220 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 221 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 222 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 223 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 224 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 225 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 226 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 227 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 228 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 229 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 231 "Lha-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 232 "Lha-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 233 "Lha-parser.yy"
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
#line 251 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 252 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s",(yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 253 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 254 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 255 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 256 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 257 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 258 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 259 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 260 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 270 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 277 "Lha-parser.yy"
    {if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yysemantic_stack_[(6) - (5)].expression);
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(6) - (3)].name)]=LhaEvaluate.RealResult;}
}
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 286 "Lha-parser.yy"
    {Reader.MyLha.NbVar=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 290 "Lha-parser.yy"
    {Reader.MyLha.NbLoc=(yysemantic_stack_[(4) - (3)].IntVal);
	
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 297 "Lha-parser.yy"
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
#line 330 "Lha-parser.yy"
    {
	
	Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.VarLabel.size()-1;
	
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 336 "Lha-parser.yy"
    {Reader.MyLha.VarLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.VarLabel.size()-1;
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 340 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
}
	
}
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 347 "Lha-parser.yy"
    {
	
	Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(1) - (1)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]=Reader.MyLha.LocLabel.size()-1;
	
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 353 "Lha-parser.yy"
    {Reader.MyLha.LocLabel.push_back(*(yysemantic_stack_[(3) - (3)].name));
	Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]=Reader.MyLha.LocLabel.size()-1;
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 363 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 371 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else cout<<"Unknown location"<<endl;
}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 378 "Lha-parser.yy"
    {
	
	if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(1) - (1)].name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 386 "Lha-parser.yy"
    {if(Reader.MyLha.LocIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 400 "Lha-parser.yy"
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 411 "Lha-parser.yy"
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
#line 432 "Lha-parser.yy"
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
#line 453 "Lha-parser.yy"
    {if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
	FuncFlowVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]=(yysemantic_stack_[(3) - (3)].expression);
	else{ cout<<"'"<<*(yysemantic_stack_[(3) - (1)].name)<<"' is not a Lha variable"<<endl;
		YYABORT;}
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 459 "Lha-parser.yy"
    {sprintf((yyval.expression),"true");}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 460 "Lha-parser.yy"
    {sprintf((yyval.expression),"false");}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 461 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 462 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s && %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 463 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s || %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 464 "Lha-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 465 "Lha-parser.yy"
    {sprintf((yyval.expression),"! %s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 467 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s == %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 468 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s <= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 469 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s >= %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 470 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s < %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 471 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s > %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 476 "Lha-parser.yy"
    {
	
}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 483 "Lha-parser.yy"
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
#line 507 "Lha-parser.yy"
    {SubSet=PetriTransitions;}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 508 "Lha-parser.yy"
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 516 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(1) - (1)].name));
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 520 "Lha-parser.yy"
    {if(Reader.MyLha.TransitionIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yysemantic_stack_[(3) - (3)].name));
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 525 "Lha-parser.yy"
    {}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 526 "Lha-parser.yy"
    {}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 530 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 535 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 540 "Lha-parser.yy"
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yysemantic_stack_[(3) - (3)].expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 550 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
	{CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]]="1";}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 554 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"("<<(yysemantic_stack_[(5) - (2)].expression)<<")";
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 559 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].IntVal);
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 112:
/* Line 670 of lalr1.cc  */
#line 564 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<(yysemantic_stack_[(3) - (1)].RealVal);
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 113:
/* Line 670 of lalr1.cc  */
#line 569 "Lha-parser.yy"
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
#line 590 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
	{CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]]="-1";}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 594 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-("<<(yysemantic_stack_[(6) - (3)].expression)<<")";
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(6) - (6)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 599 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].IntVal);
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 604 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{std::ostringstream s; s<<"-"<<(yysemantic_stack_[(4) - (2)].RealVal);
		CoeffsVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]]=s.str();}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 609 "Lha-parser.yy"
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
#line 631 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);vector<string> v1(Reader.MyLha.NbVar,"");FuncUpdateVector=v1;}
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 632 "Lha-parser.yy"
    {Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);}
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 637 "Lha-parser.yy"
    {
	if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.VarIndex.end())
    {FuncUpdateVector[Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (1)].name)]]= (yysemantic_stack_[(3) - (3)].expression);}
	else{cout<<*(yysemantic_stack_[(3) - (1)].name)<<" is not  variable label"<<endl;YYABORT;}
}
    break;

  case 126:
/* Line 670 of lalr1.cc  */
#line 646 "Lha-parser.yy"
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

  case 127:
/* Line 670 of lalr1.cc  */
#line 657 "Lha-parser.yy"
    {
	if((yysemantic_stack_[(2) - (1)].TOPHASL) != NULL){
		Reader.MyLha.HASLname.push_back("");
		Reader.MyLha.HASLtop.push_back((yysemantic_stack_[(2) - (1)].TOPHASL));
	}
}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 665 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 666 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 669 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 673 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 676 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algPDF;
		algPDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" >= "<<bucket<<"&& "<<(yysemantic_stack_[(10) - (3)].expression)<<"<"<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
								Reader.MyLha.ConfidenceLevel));
		std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 691 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algCDF;
		algCDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
		Reader.MyLha.ConfidenceLevel));
		std::ostringstream s; s<<"$_$: Value in [-infinity ,"<< bucket<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = NULL;
}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 707 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 710 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 713 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 716 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 719 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 722 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 726 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 729 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 730 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 731 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 732 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 733 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 734 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 735 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 736 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 737 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 738 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 740 "Lha-parser.yy"
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

  case 152:
/* Line 670 of lalr1.cc  */
#line 750 "Lha-parser.yy"
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

  case 153:
/* Line 670 of lalr1.cc  */
#line 760 "Lha-parser.yy"
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

  case 154:
/* Line 670 of lalr1.cc  */
#line 770 "Lha-parser.yy"
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

  case 155:
/* Line 670 of lalr1.cc  */
#line 781 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 782 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 783 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 786 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 790 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 795 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 161:
/* Line 670 of lalr1.cc  */
#line 800 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 805 "Lha-parser.yy"
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

  case 163:
/* Line 670 of lalr1.cc  */
#line 824 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 828 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 833 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 838 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 843 "Lha-parser.yy"
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
#line 1751 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -248;
  const short int
  Lha_parser::yypact_[] =
  {
        36,    12,    54,    94,    80,   138,    56,    66,   130,   132,
    -248,   115,   119,   128,   114,   100,   177,   127,   152,   254,
     129,     3,   140,   146,  -248,  -248,   215,   219,   207,   248,
     249,   290,  -248,   244,   277,  -248,  -248,   335,   356,   318,
     320,     3,  -248,   366,  -248,  -248,    15,   385,  -248,   392,
     406,  -248,     3,    91,  -248,  -248,  -248,  -248,   401,   424,
     384,   386,  -248,  -248,   427,   434,   457,   466,  -248,    15,
       5,   116,   116,   116,  -248,  -248,    15,    15,    15,  -248,
       9,  -248,    10,   472,   473,   107,   160,  -248,    13,  -248,
      17,   294,  -248,   116,   116,   474,   486,   487,   493,   494,
     506,   507,   322,  -248,   211,   240,  -248,  -248,   307,   469,
     498,   514,   525,   529,     4,  -248,   524,   315,   473,  -248,
    -248,  -248,   107,   107,   526,   527,   528,   217,  -248,  -248,
     160,   160,   534,   535,   536,   222,   531,   540,   544,   542,
    -248,   327,   235,   116,   116,   116,    41,    41,    41,    41,
    -248,   116,   116,   116,   116,   116,   388,   388,  -248,  -248,
    -248,  -248,   541,   545,  -248,   547,   546,  -248,   334,   376,
     107,   107,   107,  -248,   107,   107,   107,   107,   107,   470,
      69,   160,   160,   160,  -248,   160,   160,   160,   160,  -248,
    -248,  -248,  -248,  -248,   348,   245,   251,   530,   532,   533,
     107,   363,    78,  -248,    85,    95,   124,   523,   523,   235,
     235,  -248,  -248,  -248,   548,   550,    99,  -248,   553,  -248,
    -248,   355,   256,   279,   537,   537,   376,   376,  -248,  -248,
     360,   167,   228,   538,    69,    69,  -248,  -248,   116,   116,
     551,   552,   559,   369,   539,   543,   549,   107,  -248,    41,
      41,  -248,  -248,  -248,   388,   388,    99,    99,  -248,  -248,
     512,   316,  -248,   560,  -248,   107,   107,  -248,   160,   160,
     160,   381,   390,  -248,  -248,  -248,   554,   561,   562,   566,
     395,  -248,  -248,   563,   564,   313,   210,  -248,   107,   107,
     107,   107,   107,   565,   567,    99,    99,   568,   402,   416,
     484,   491,   495,  -248,  -248,   572,  -248,  -248,  -248,   555,
     388,   388,  -248,   205,   205,   205,   205,   205,   574,  -248,
    -248,   569,   571,  -248,  -248,  -248,  -248,  -248,  -248,   577,
     573,   575,   579,     6,  -248,    16,  -248,  -248,  -248,   107,
     574,   580,  -248,   576,   581,   583,  -248,   205,  -248,   586,
     556,  -248,    21,   213,  -248,  -248,   584,  -248,   570,   578,
     585,   107,  -248,   431,   587,   582,   274,  -248,  -248,   590,
     591,   593,   423,   588,   589,   592,   107,    24,   213,   107,
     107,   107,   169,   169,  -248,  -248,  -248,   594,   595,   596,
     597,   428,  -248,   599,   598,  -248,   205,   205,   205,  -248,
    -248,   600,  -248,  -248,  -248,   601,   603,    22,  -248,   604,
    -248,   608,   155,   599,  -248,  -248,  -248,  -248,  -248,  -248,
     155,   155,   605,   609,   611,   480,  -248,   437,   444,   155,
     155,   155,   155,   155,   155,   155,   155,  -248,   449,   284,
     289,   602,   602,   444,   444,  -248,  -248,   155,   155,   458,
     463,  -248,  -248
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
       0,     0,    46,     0,   139,   138,     0,     0,   131,     0,
       0,     4,   124,     0,    51,    52,    50,    49,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,   125,   127,     0,     0,     0,    62,
       0,    65,     0,     0,     0,     0,     0,    54,     0,    57,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,   137,   136,   135,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    90,    19,
      17,    18,     0,     0,     0,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   143,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,    63,    61,
      66,    64,     0,     0,    71,     0,     0,    91,     0,    21,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,    47,     0,     0,     0,     0,    55,
      53,    58,    56,   145,     0,     0,     0,   158,     0,     0,
       0,     0,     0,   155,     0,     0,     0,   150,   149,   147,
     148,   146,   128,   129,     0,     0,     0,    69,     0,    89,
      20,     0,     0,     0,    22,    25,    23,    24,    26,     7,
       0,     0,     0,    11,     9,    10,    12,   144,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   152,     0,
       0,   153,   151,   154,     0,     0,     0,     0,    77,    78,
       0,     0,    79,     0,    27,     0,     0,    13,     0,     0,
       0,     0,     0,   162,   161,   160,     0,     0,     0,     0,
       0,   157,   156,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,     0,   167,   166,   165,     0,
       0,     0,    82,    84,    86,    85,    87,    88,     0,    73,
      80,    81,     0,    28,    29,    14,    15,    16,   159,     0,
       0,     0,     0,     0,    74,     0,   164,   132,   133,     0,
       0,     0,    93,    94,     0,     0,    96,    76,    75,     0,
       0,    98,     0,     0,    72,    95,     0,    97,   109,     0,
       0,     0,   102,     0,     0,   100,     0,   106,    99,     0,
       0,     0,     0,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   112,   111,     0,     0,     0,
       0,     0,   120,     0,     0,   101,   103,   105,   104,   108,
     107,     0,   118,   117,   116,     0,     0,     0,   121,     0,
     110,     0,     0,     0,   119,    92,   115,    32,    30,    31,
       0,     0,     0,     0,     0,   123,   122,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    35,    38,    36,    37,    39,    40,     0,     0,     0,
       0,    41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -248,  -248,  -248,  -126,   -85,  -221,  -248,   606,  -248,   615,
     607,   610,   612,  -248,   614,  -248,  -248,   616,  -248,   613,
    -248,  -248,   617,  -248,   490,  -248,   266,  -247,  -248,   619,
     489,  -248,  -248,   273,  -248,   246,  -248,  -248,    31,  -248,
    -248,   220,    -5,  -248,  -154,   -35,   -71,  -248,   198,   212
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   135,   260,   425,     5,    19,    20,     6,
       7,    21,    22,    88,    23,    90,    13,    14,    80,    15,
      82,    32,    33,   114,   115,   333,   334,   261,   262,    34,
     117,   118,   345,   346,   352,   364,   365,   366,   367,   394,
     407,   408,    51,    52,   214,    53,   102,   103,   202,   203
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       127,   104,   105,   215,   179,   180,    43,    44,    45,   286,
     287,    70,    46,   113,   340,    92,   341,   109,   111,    44,
      45,   136,   141,   142,    46,   138,     8,   342,   343,   356,
     413,    76,    77,    78,    91,   392,    68,   168,   169,    47,
      48,   106,   107,   108,   197,   198,   199,    74,   320,   321,
     200,    47,    48,    49,    50,   230,   231,   232,   163,   233,
     234,   235,   236,   110,   112,    49,    50,   137,     9,   344,
     201,   139,   194,   195,   196,   357,   414,   393,     1,     2,
     207,   208,   209,   210,   211,   221,   222,   223,   248,   224,
     225,   226,   227,   228,    10,   251,   185,    75,     1,   188,
     283,   284,   119,   120,   121,   252,   249,   250,   256,     2,
     119,   120,   121,   249,   250,   243,   122,    76,    77,    78,
     257,   258,   259,   249,   250,    93,    11,    12,   123,    28,
     124,   125,   126,    29,   253,    26,   123,    27,   124,   125,
     126,    39,   300,   301,   302,    94,    11,    95,    96,    97,
      98,    99,   249,   250,   100,   101,   330,   331,   417,   418,
     419,    12,   280,   128,   420,   129,    40,   271,   272,   130,
      16,   285,   358,   359,   360,   269,    30,    31,   361,    16,
     298,   299,    17,    18,   421,    18,   422,   423,   424,   131,
      17,   132,   133,   134,   185,   186,   187,   188,   363,   427,
     428,    37,    38,   313,   314,   315,   316,   317,   438,   439,
     440,   441,   442,   443,   444,   445,   358,   359,   360,   156,
     312,    56,   361,   173,   362,    57,   449,   450,   184,   295,
     296,   174,   175,   176,   177,   178,   270,   151,   152,   153,
     154,   155,   363,   174,   175,   176,   177,   178,   157,   185,
     186,   187,   188,   238,   347,   185,   186,   187,   188,   239,
      58,   151,   152,    60,   265,   155,   151,   152,   153,   154,
     155,   151,   152,   153,   154,   155,   372,   151,   152,   153,
     154,   155,   174,   175,   176,   177,   178,   266,   379,   380,
     381,   391,   447,    31,   396,   397,   398,   448,    17,    18,
     140,    59,   382,   383,    61,   174,   175,   176,   177,   178,
     432,   433,   434,   435,   436,   432,   433,   434,   435,   436,
      76,    77,    78,   220,   293,    30,   294,   288,   289,   290,
     291,   292,   150,    76,    77,   295,   296,   193,    64,   174,
     175,   176,   177,   178,   220,   204,   205,   206,   151,   152,
     153,   154,   155,   151,   152,   153,   154,   155,   237,    65,
     174,   175,   176,   177,   178,   264,   244,   245,   246,   166,
     267,    66,   247,    67,   151,   152,   153,   154,   155,   276,
      69,   174,   175,   176,   177,   178,   268,   185,   186,   187,
     188,   303,   212,   213,    71,   174,   175,   176,   177,   178,
     304,    72,   174,   175,    79,   309,   178,   151,   152,   153,
     154,   155,   323,   399,   400,    73,   151,   152,   153,   154,
     155,   174,   175,   176,   177,   178,   324,    81,   174,   175,
     176,   177,   178,   387,   373,   374,   375,    83,   405,    84,
     376,    85,   174,   175,   176,   177,   178,   437,    86,   174,
     175,   176,   177,   178,   174,   175,   176,   177,   178,   446,
      87,   281,   282,   432,   433,   434,   435,   436,   451,    89,
     432,   433,   158,   452,   436,   432,   433,   434,   435,   436,
     229,   113,   116,   143,   432,   433,   434,   435,   436,   432,
     433,   434,   435,   436,   325,   144,   145,   185,   186,   187,
     188,   326,   146,   147,   159,   327,   432,   433,   434,   435,
     436,   185,   186,   187,   188,   148,   149,   160,   185,   186,
     187,   188,   185,   186,   187,   188,   288,   289,   290,   291,
     292,   161,   162,   165,   189,   170,   171,   172,   174,   175,
     176,   177,   178,   181,   182,   183,   190,   191,   192,   216,
     218,   217,   219,   155,   273,   274,   254,   240,   255,   241,
     242,   263,   275,   297,   306,   307,   277,   178,   188,   308,
     278,   310,   311,   319,   318,   328,   279,   332,   322,   335,
     336,   305,   329,   337,   351,   338,   339,   368,   295,   350,
     349,   353,   354,   384,   385,   377,   386,   369,   402,   403,
     404,   378,   406,   410,   164,   370,   348,   167,   409,   344,
     415,   416,   371,    24,   429,   388,   389,   412,   430,   390,
     431,   401,    25,   355,   395,     0,    42,    35,   411,    41,
       0,    36,   436,   426,     0,    55,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    62
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        85,    72,    73,   157,   130,   131,     3,     4,     5,   256,
     257,    46,     9,     9,     8,    10,    10,     8,     8,     4,
       5,     8,    93,    94,     9,     8,    14,    11,    12,     8,
       8,    26,    27,    28,    69,    11,    41,   122,   123,    36,
      37,    76,    77,    78,     3,     4,     5,    52,   295,   296,
       9,    36,    37,    50,    51,   181,   182,   183,    54,   185,
     186,   187,   188,    54,    54,    50,    51,    54,    14,    53,
      29,    54,   143,   144,   145,    54,    54,    53,    42,    43,
     151,   152,   153,   154,   155,   170,   171,   172,    10,   174,
     175,   176,   177,   178,     0,    10,    27,     6,    42,    30,
     254,   255,     3,     4,     5,    10,    28,    29,     9,    43,
       3,     4,     5,    28,    29,   200,     9,    26,    27,    28,
      21,    22,    23,    28,    29,     9,    46,    47,    29,    14,
      31,    32,    33,    14,    10,     5,    29,     5,    31,    32,
      33,    14,   268,   269,   270,    29,    46,    31,    32,    33,
      34,    35,    28,    29,    38,    39,   310,   311,     3,     4,
       5,    47,   247,     3,     9,     5,    14,   238,   239,     9,
      41,   256,     3,     4,     5,     8,    48,    49,     9,    41,
     265,   266,    44,    45,    29,    45,    31,    32,    33,    29,
      44,    31,    32,    33,    27,    28,    29,    30,    29,   420,
     421,    24,    25,   288,   289,   290,   291,   292,   429,   430,
     431,   432,   433,   434,   435,   436,     3,     4,     5,     8,
      10,     6,     9,     6,    11,     6,   447,   448,     6,    19,
      20,    26,    27,    28,    29,    30,     8,    26,    27,    28,
      29,    30,    29,    26,    27,    28,    29,    30,     8,    27,
      28,    29,    30,     8,   339,    27,    28,    29,    30,     8,
      53,    26,    27,    14,     8,    30,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,   361,    26,    27,    28,
      29,    30,    26,    27,    28,    29,    30,     8,    14,    15,
      16,   376,     8,    49,   379,   380,   381,     8,    44,    45,
       6,    53,    28,    29,    14,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,    26,    27,    28,    29,    30,
      26,    27,    28,    10,     8,    48,    10,    14,    15,    16,
      17,    18,    10,    26,    27,    19,    20,    10,     3,    26,
      27,    28,    29,    30,    10,   147,   148,   149,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,    10,     3,
      26,    27,    28,    29,    30,    10,     3,     4,     5,    54,
      10,    53,     9,    53,    26,    27,    28,    29,    30,    10,
      14,    26,    27,    28,    29,    30,    26,    27,    28,    29,
      30,    10,     4,     5,     9,    26,    27,    28,    29,    30,
      10,     9,    26,    27,     3,    10,    30,    26,    27,    28,
      29,    30,    10,   382,   383,     9,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,    10,     3,    26,    27,
      28,    29,    30,    10,     3,     4,     5,    53,    10,    53,
       9,    14,    26,    27,    28,    29,    30,    10,    14,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,    10,
       3,   249,   250,    26,    27,    28,    29,    30,    10,     3,
      26,    27,     3,    10,    30,    26,    27,    28,    29,    30,
      10,     9,     9,     9,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    10,     9,     9,    27,    28,    29,
      30,    10,     9,     9,     6,    10,    26,    27,    28,    29,
      30,    27,    28,    29,    30,     9,     9,     3,    27,    28,
      29,    30,    27,    28,    29,    30,    14,    15,    16,    17,
      18,     6,     3,     9,     3,     9,     9,     9,    26,    27,
      28,    29,    30,     9,     9,     9,     6,     3,     6,     8,
       3,     6,     6,    30,     3,     3,     8,    27,     8,    27,
      27,     8,     3,     3,     3,     3,    27,    30,    30,     3,
      27,     8,     8,     6,     9,     3,    27,     3,    10,     8,
       3,    27,    27,    10,     3,    10,     7,     3,    19,    13,
      10,     8,     6,     3,     3,     8,     3,    27,     3,     3,
       3,    19,     3,     3,   114,    27,   340,   118,    10,    53,
       6,     3,    27,     6,     9,    27,    27,    14,     9,    27,
       9,    27,     7,   350,   378,    -1,    20,    14,    27,    19,
      -1,    15,    30,   413,    -1,    23,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    33
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Lha_parser::yystos_[] =
  {
         0,    42,    43,    56,    57,    61,    64,    65,    14,    14,
       0,    46,    47,    71,    72,    74,    41,    44,    45,    62,
      63,    66,    67,    69,    65,    64,     5,     5,    14,    14,
      48,    49,    76,    77,    84,    74,    72,    24,    25,    14,
      14,    66,    62,     3,     4,     5,     9,    36,    37,    50,
      51,    97,    98,   100,    69,    67,     6,     6,    53,    53,
      14,    14,    84,    77,     3,     3,    53,    53,    97,    14,
     100,     9,     9,     9,    97,     6,    26,    27,    28,     3,
      73,     3,    75,    53,    53,    14,    14,     3,    68,     3,
      70,   100,    10,     9,    29,    31,    32,    33,    34,    35,
      38,    39,   101,   102,   101,   101,   100,   100,   100,     8,
      54,     8,    54,     9,    78,    79,     9,    85,    86,     3,
       4,     5,     9,    29,    31,    32,    33,    59,     3,     5,
       9,    29,    31,    32,    33,    58,     8,    54,     8,    54,
       6,   101,   101,     9,     9,     9,     9,     9,     9,     9,
      10,    26,    27,    28,    29,    30,     8,     8,     3,     6,
       3,     6,     3,    54,    79,     9,    54,    85,    59,    59,
       9,     9,     9,     6,    26,    27,    28,    29,    30,    58,
      58,     9,     9,     9,     6,    27,    28,    29,    30,     3,
       6,     3,     6,    10,   101,   101,   101,     3,     4,     5,
       9,    29,   103,   104,   103,   103,   103,   101,   101,   101,
     101,   101,     4,     5,    99,    99,     8,     6,     3,     6,
      10,    59,    59,    59,    59,    59,    59,    59,    59,    10,
      58,    58,    58,    58,    58,    58,    58,    10,     8,     8,
      27,    27,    27,    59,     3,     4,     5,     9,    10,    28,
      29,    10,    10,    10,     8,     8,     9,    21,    22,    23,
      59,    82,    83,     8,    10,     8,     8,    10,    26,     8,
       8,   101,   101,     3,     3,     3,    10,    27,    27,    27,
      59,   104,   104,    99,    99,    59,    82,    82,    14,    15,
      16,    17,    18,     8,    10,    19,    20,     3,    59,    59,
      58,    58,    58,    10,    10,    27,     3,     3,     3,    10,
       8,     8,    10,    59,    59,    59,    59,    59,     9,     6,
      82,    82,    10,    10,    10,    10,    10,    10,     3,    27,
      99,    99,     3,    80,    81,     8,     3,    10,    10,     7,
       8,    10,    11,    12,    53,    87,    88,    59,    81,    10,
      13,     3,    89,     8,     6,    88,     8,    54,     3,     4,
       5,     9,    11,    29,    90,    91,    92,    93,     3,    27,
      27,    27,    59,     3,     4,     5,     9,     8,    19,    14,
      15,    16,    28,    29,     3,     3,     3,    10,    27,    27,
      27,    59,    11,    53,    94,    90,    59,    59,    59,    93,
      93,    27,     3,     3,     3,    10,     3,    95,    96,    10,
       3,    27,    14,     8,    54,     6,     3,     3,     4,     5,
       9,    29,    31,    32,    33,    60,    96,    60,    60,     9,
       9,     9,    26,    27,    28,    29,    30,    10,    60,    60,
      60,    60,    60,    60,    60,    60,    10,     8,     8,    60,
      60,    10,    10
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
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    66,    66,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    87,    87,    87,    87,    88,    89,    89,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104
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
       1,     1,     3,     3,     1,     2,     4,     2,     1,     1,
       4,     1,    10,    10,     3,     3,     3,     3,     1,     1,
       1,     6,     6,     2,     4,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     1,     3,     3,     1,     5,
       3,     3,     3,     2,     6,     4,     4,     4
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
  "edges", "PDF", "CDF", "NEG", "'{'", "'}'", "$accept", "LHA",
  "declarations", "IntMarkingFormula", "RealMarkingFormula",
  "RealVarMarkingFormula", "Sizes", "Constants", "Constant", "NbVariables",
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
        56,     0,    -1,    57,    71,    76,    -1,    61,    62,    66,
      97,    -1,    61,    66,    97,    -1,     5,    -1,     3,    -1,
       9,    58,    10,    -1,    29,    58,    -1,    58,    28,    58,
      -1,    58,    29,    58,    -1,    58,    27,    58,    -1,    58,
      30,    58,    -1,    31,     9,    58,    10,    -1,    31,     9,
      58,    26,    58,    10,    -1,    32,     9,    58,     8,    58,
      10,    -1,    33,     9,    58,     8,    58,    10,    -1,     4,
      -1,     5,    -1,     3,    -1,     9,    59,    10,    -1,    29,
      59,    -1,    59,    26,    59,    -1,    59,    28,    59,    -1,
      59,    29,    59,    -1,    59,    27,    59,    -1,    59,    30,
      59,    -1,    31,     9,    59,    10,    -1,    32,     9,    59,
       8,    59,    10,    -1,    33,     9,    59,     8,    59,    10,
      -1,     4,    -1,     5,    -1,     3,    -1,     9,    60,    10,
      -1,    29,    60,    -1,    60,    26,    60,    -1,    60,    28,
      60,    -1,    60,    29,    60,    -1,    60,    27,    60,    -1,
      60,    30,    60,    -1,    31,     9,    60,    10,    -1,    32,
       9,    60,     8,    60,    10,    -1,    33,     9,    60,     8,
      60,    10,    -1,    65,    64,    -1,    64,    65,    -1,    63,
      -1,    63,    62,    -1,    41,    25,     3,    14,    58,     6,
      -1,    41,    24,     3,    14,    59,     6,    -1,    43,    14,
       5,     6,    -1,    42,    14,     5,     6,    -1,    67,    69,
      -1,    69,    67,    -1,    44,    14,    53,    68,    54,     6,
      -1,     3,    -1,    68,     8,     3,    -1,    45,    14,    53,
      70,    54,     6,    -1,     3,    -1,    70,     8,     3,    -1,
      72,    74,    -1,    74,    72,    -1,    46,    14,    53,    73,
      54,     6,    -1,     3,    -1,    73,     8,     3,    -1,    47,
      14,    53,    75,    54,     6,    -1,     3,    -1,    75,     8,
       3,    -1,    77,    84,    -1,    84,    77,    -1,    48,    14,
      53,    78,    54,     6,    -1,    79,    -1,    78,    79,    -1,
       9,     3,     8,    82,     8,     9,    80,    10,    10,     6,
      -1,     9,     3,     8,    82,    10,     6,    -1,    81,    -1,
      80,     8,    81,    -1,     3,     7,    59,    -1,    22,    -1,
      23,    -1,    83,    -1,    82,    19,    82,    -1,    82,    20,
      82,    -1,     9,    82,    10,    -1,    21,    82,    -1,    59,
      14,    59,    -1,    59,    16,    59,    -1,    59,    15,    59,
      -1,    59,    17,    59,    -1,    59,    18,    59,    -1,    49,
      14,    53,    85,    54,     6,    -1,    86,    -1,    86,    85,
      -1,     9,     9,     3,     8,     3,    10,     8,    87,     8,
      90,     8,    94,    10,     6,    -1,    11,    -1,    12,    -1,
      12,    13,    88,    -1,    88,    -1,    53,    89,    54,    -1,
       3,    -1,    89,     8,     3,    -1,    91,    -1,    91,    19,
      90,    -1,    11,    -1,    92,    14,    59,    -1,    92,    16,
      59,    -1,    92,    15,    59,    -1,    93,    -1,    92,    29,
      93,    -1,    92,    28,    93,    -1,     3,    -1,     9,    59,
      10,    27,     3,    -1,     5,    27,     3,    -1,     4,    27,
       3,    -1,     3,    27,     3,    -1,    29,     3,    -1,    29,
       9,    59,    10,    27,     3,    -1,    29,     5,    27,     3,
      -1,    29,     4,    27,     3,    -1,    29,     3,    27,     3,
      -1,    53,    95,    54,    -1,    11,    -1,    96,    -1,    95,
       8,    96,    -1,     3,    14,    60,    -1,    98,    -1,    98,
      97,    -1,     3,    14,   100,     6,    -1,   100,     6,    -1,
       4,    -1,     5,    -1,    36,     9,   101,    10,    -1,    37,
      -1,    50,     9,   101,     8,    99,     8,    99,     8,    99,
      10,    -1,    51,     9,   101,     8,    99,     8,    99,     8,
      99,    10,    -1,     9,   100,    10,    -1,   100,    28,   100,
      -1,   100,    27,   100,    -1,   100,    26,   100,    -1,     5,
      -1,     4,    -1,   102,    -1,    32,     9,   101,     8,   101,
      10,    -1,    33,     9,   101,     8,   101,    10,    -1,    29,
     101,    -1,    31,     9,   101,    10,    -1,     9,   101,    10,
      -1,   101,    30,   101,    -1,   101,    28,   101,    -1,   101,
      29,   101,    -1,   101,    27,   101,    -1,   101,    26,   101,
      -1,    38,     9,   103,    10,    -1,    34,     9,   103,    10,
      -1,    35,     9,   103,    10,    -1,    39,     9,   103,    10,
      -1,   104,    -1,   103,    29,   104,    -1,   103,    28,   104,
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
     485,   487,   489,   493,   497,   499,   502,   507,   510,   512,
     514,   519,   521,   532,   543,   547,   551,   555,   559,   561,
     563,   565,   572,   579,   582,   587,   591,   595,   599,   603,
     607,   611,   616,   621,   626,   631,   633,   637,   641,   643,
     649,   653,   657,   661,   664,   671,   676,   681
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
         0,   174,   174,   177,   178,   184,   185,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   207,   208,   209,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     231,   232,   233,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   263,   264,   266,   267,   269,   276,   286,
     290,   294,   295,   297,   330,   336,   340,   347,   353,   358,
     359,   361,   363,   371,   376,   378,   386,   395,   396,   400,
     407,   408,   410,   429,   451,   452,   453,   459,   460,   461,
     462,   463,   464,   465,   467,   468,   469,   470,   471,   476,
     480,   481,   483,   506,   507,   508,   512,   514,   516,   520,
     525,   526,   527,   529,   534,   539,   545,   546,   547,   549,
     553,   558,   563,   568,   589,   593,   598,   603,   608,   631,
     632,   634,   635,   637,   644,   644,   646,   657,   665,   666,
     669,   673,   676,   691,   707,   710,   713,   716,   719,   722,
     726,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   740,   750,   760,   770,   781,   782,   783,   785,   789,
     794,   799,   804,   823,   827,   832,   837,   842
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
  const int Lha_parser::yylast_ = 652;
  const int Lha_parser::yynnts_ = 50;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 55;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 307;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2677 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 866 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
