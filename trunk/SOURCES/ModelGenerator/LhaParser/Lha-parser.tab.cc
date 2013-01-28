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
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
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
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yysemantic_stack_[(1) - (1)].name)->c_str()<<" ";
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
			{std::ostringstream s; s<<"Marking.P->_PL_"<<(yysemantic_stack_[(3) - (1)].name)->c_str()<<" ";
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
			{std::ostringstream s; s<<"-Marking.P->_PL_"<<(yysemantic_stack_[(4) - (2)].name)->c_str()<<" ";
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
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,"");
		}
	}
}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 670 "Lha-parser.yy"
    {(yyval.RealVal)=(yysemantic_stack_[(1) - (1)].RealVal);}
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 671 "Lha-parser.yy"
    {(yyval.RealVal)=(double)(yysemantic_stack_[(1) - (1)].IntVal);}
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 672 "Lha-parser.yy"
    { if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
			(yyval.RealVal) = Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else { if(Reader.MyLha.LhaIntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.LhaIntConstant.end())
			(yyval.RealVal) = (double)Reader.MyLha.LhaIntConstant[*(yysemantic_stack_[(1) - (1)].name)];
		else {
			cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a definded constant "<<endl;
			YYABORT;
		}}}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 682 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 686 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 689 "Lha-parser.yy"
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

  case 134:
/* Line 670 of lalr1.cc  */
#line 705 "Lha-parser.yy"
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

  case 135:
/* Line 670 of lalr1.cc  */
#line 722 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 725 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 731 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 734 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 737 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 741 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 744 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 745 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 746 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 747 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 748 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 749 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 750 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 751 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 752 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 753 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 755 "Lha-parser.yy"
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

  case 153:
/* Line 670 of lalr1.cc  */
#line 765 "Lha-parser.yy"
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

  case 154:
/* Line 670 of lalr1.cc  */
#line 775 "Lha-parser.yy"
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

  case 155:
/* Line 670 of lalr1.cc  */
#line 785 "Lha-parser.yy"
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

  case 156:
/* Line 670 of lalr1.cc  */
#line 796 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 797 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 798 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 801 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 805 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 161:
/* Line 670 of lalr1.cc  */
#line 810 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 815 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 820 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yyval.expression),"%f * Var[%d]", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(3) - (1)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(3) - (1)].name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yyval.expression),"Marking.P->_PL_%s * Var[%d]", (yysemantic_stack_[(3) - (1)].name)->c_str() ,Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
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

  case 164:
/* Line 670 of lalr1.cc  */
#line 839 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 843 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 848 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 853 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 858 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{if(Reader.MyLha.LhaRealConstant.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yyval.expression),"-%f * Var[%d]", Reader.MyLha.LhaRealConstant[*(yysemantic_stack_[(4) - (2)].name)],Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yysemantic_stack_[(4) - (2)].name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yyval.expression),"-Marking.P->_PL_%s * Var[%d]", (yysemantic_stack_[(4) - (2)].name)->c_str() ,Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
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
#line 1771 "Lha-parser.tab.cc"
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
  const short int Lha_parser::yypact_ninf_ = -249;
  const short int
  Lha_parser::yypact_[] =
  {
        36,    12,    54,   126,    52,   182,    69,    90,   136,   141,
    -249,   138,   145,    55,   114,   121,   154,   157,   160,   176,
     143,     3,   150,   142,  -249,  -249,   229,   255,   215,   223,
     284,   291,  -249,   270,   246,  -249,  -249,   323,   349,   286,
     320,     3,  -249,   371,  -249,  -249,    15,   378,  -249,   385,
     406,  -249,     3,   230,  -249,  -249,  -249,  -249,   380,   415,
     376,   388,  -249,  -249,   439,   441,   448,   459,  -249,    15,
       5,    96,    96,    96,  -249,  -249,    15,    15,    15,  -249,
       9,  -249,    10,   465,   466,   133,   180,  -249,    13,  -249,
      17,   263,  -249,    96,    96,   467,   478,   486,   487,   500,
     516,   517,   301,  -249,    80,   211,  -249,  -249,   202,   485,
     504,   531,   529,   534,     4,  -249,   530,   488,   466,  -249,
    -249,  -249,   133,   133,   532,   535,   536,   164,  -249,  -249,
     180,   180,   537,   538,   539,   204,   540,   543,   547,   545,
    -249,   315,   240,    96,    96,    96,    41,    41,    41,    41,
    -249,    96,    96,    96,    96,    96,   356,   356,  -249,  -249,
    -249,  -249,   544,   548,  -249,   550,   549,  -249,   327,   390,
     133,   133,   133,  -249,   133,   133,   133,   133,   133,   463,
     232,   180,   180,   180,  -249,   180,   180,   180,   180,  -249,
    -249,  -249,  -249,  -249,   336,   217,   222,   511,   513,   533,
     133,   377,   111,  -249,   122,   289,   479,   526,   526,   240,
     240,  -249,  -249,  -249,  -249,   551,   553,    91,  -249,   554,
    -249,  -249,   341,   245,   252,   527,   527,   390,   390,  -249,
    -249,   348,    89,   285,   528,   232,   232,  -249,  -249,    96,
      96,   560,   561,   562,   362,   541,   542,   546,   133,  -249,
      41,    41,  -249,  -249,  -249,   356,   356,    91,    91,  -249,
    -249,   501,   330,  -249,   563,  -249,   133,   133,  -249,   180,
     180,   180,   369,   374,  -249,  -249,  -249,   552,   564,   567,
     568,   383,  -249,  -249,   566,   569,   306,   244,  -249,   133,
     133,   133,   133,   133,   571,   570,    91,    91,   565,   395,
     404,   472,   476,   484,  -249,  -249,   575,  -249,  -249,  -249,
     555,   356,   356,  -249,   274,   274,   274,   274,   274,   578,
    -249,  -249,   572,   576,  -249,  -249,  -249,  -249,  -249,  -249,
     580,   577,   579,   581,     6,  -249,    16,  -249,  -249,  -249,
     133,   578,   582,  -249,   559,   583,   585,  -249,   274,  -249,
     584,   556,  -249,    21,   213,  -249,  -249,   591,  -249,   558,
     573,   574,   133,  -249,   445,   587,   586,   469,  -249,  -249,
     593,   594,   595,   409,   588,   589,   590,   133,    24,   213,
     133,   133,   133,   151,   151,  -249,  -249,  -249,   592,   596,
     599,   600,   416,  -249,   601,   597,  -249,   274,   274,   274,
    -249,  -249,   603,  -249,  -249,  -249,   598,   604,    22,  -249,
     602,  -249,   607,   144,   601,  -249,  -249,  -249,  -249,  -249,
    -249,   144,   144,   605,   611,   612,   494,  -249,   430,   506,
     144,   144,   144,   144,   144,   144,   144,   144,  -249,   437,
     257,   280,   606,   606,   506,   506,  -249,  -249,   144,   144,
     442,   451,  -249,  -249
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
       0,     0,    46,     0,   140,   139,     0,     0,   132,     0,
       0,     4,   124,     0,    51,    52,    50,    49,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,   125,   127,     0,     0,     0,    62,
       0,    65,     0,     0,     0,     0,     0,    54,     0,    57,
       0,     0,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,   138,   137,   136,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    90,    19,
      17,    18,     0,     0,     0,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   144,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,    63,    61,
      66,    64,     0,     0,    71,     0,     0,    91,     0,    21,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,    47,     0,     0,     0,     0,    55,
      53,    58,    56,   146,     0,     0,     0,   159,     0,     0,
       0,     0,     0,   156,     0,     0,     0,   151,   150,   148,
     149,   147,   130,   128,   129,     0,     0,     0,    69,     0,
      89,    20,     0,     0,     0,    22,    25,    23,    24,    26,
       7,     0,     0,     0,    11,     9,    10,    12,   145,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,   153,
       0,     0,   154,   152,   155,     0,     0,     0,     0,    77,
      78,     0,     0,    79,     0,    27,     0,     0,    13,     0,
       0,     0,     0,     0,   163,   162,   161,     0,     0,     0,
       0,     0,   158,   157,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,   168,   167,   166,
       0,     0,     0,    82,    84,    86,    85,    87,    88,     0,
      73,    80,    81,     0,    28,    29,    14,    15,    16,   160,
       0,     0,     0,     0,     0,    74,     0,   165,   133,   134,
       0,     0,     0,    93,    94,     0,     0,    96,    76,    75,
       0,     0,    98,     0,     0,    72,    95,     0,    97,   109,
       0,     0,     0,   102,     0,     0,   100,     0,   106,    99,
       0,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   112,   111,     0,     0,
       0,     0,     0,   120,     0,     0,   101,   103,   105,   104,
     108,   107,     0,   118,   117,   116,     0,     0,     0,   121,
       0,   110,     0,     0,     0,   119,    92,   115,    32,    30,
      31,     0,     0,     0,     0,     0,   123,   122,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,    35,    38,    36,    37,    39,    40,     0,     0,
       0,     0,    41,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -249,  -249,  -249,  -126,   -85,  -234,  -249,   608,  -249,   615,
     617,   610,   609,  -249,   613,  -249,  -249,   616,  -249,   619,
    -249,  -249,   614,  -249,   497,  -249,   271,  -248,  -249,   618,
     495,  -249,  -249,   273,  -249,   247,  -249,  -249,   -36,  -249,
    -249,   216,    -5,  -249,  -154,   -35,   -71,  -249,   259,   177
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   135,   261,   426,     5,    19,    20,     6,
       7,    21,    22,    88,    23,    90,    13,    14,    80,    15,
      82,    32,    33,   114,   115,   334,   335,   262,   263,    34,
     117,   118,   346,   347,   353,   365,   366,   367,   368,   395,
     408,   409,    51,    52,   215,    53,   102,   103,   202,   203
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       127,   104,   105,   216,   179,   180,    43,    44,    45,   287,
     288,    70,    46,   113,   341,    92,   342,   109,   111,    44,
      45,   136,   141,   142,    46,   138,     8,   343,   344,   357,
     414,    76,    77,    78,    91,   393,    68,   168,   169,    47,
      48,   106,   107,   108,   197,   198,   199,    74,   321,   322,
     200,    47,    48,    49,    50,   231,   232,   233,   163,   234,
     235,   236,   237,   110,   112,    49,    50,   137,     9,   345,
     201,   139,   194,   195,   196,   358,   415,   394,     1,     2,
     207,   208,   209,   210,   211,   222,   223,   224,   156,   225,
     226,   227,   228,   229,   119,   120,   121,   270,    11,    12,
     257,   284,   285,    30,    31,    93,   151,   152,   153,   154,
     155,     1,   258,   259,   260,   244,   185,   186,   187,   188,
     123,   249,   124,   125,   126,    94,    10,    95,    96,    97,
      98,    99,   252,     2,   100,   101,   119,   120,   121,   250,
     251,    26,   122,   301,   302,   303,    27,   418,   419,   420,
     250,   251,    28,   421,   359,   360,   361,   331,   332,    29,
     362,    12,   123,   281,   124,   125,   126,    11,   272,   273,
     173,    39,   286,   422,    40,   423,   424,   425,    37,    38,
     364,   299,   300,   128,    16,   129,    17,   428,   429,   130,
     174,   175,   176,   177,   178,    18,   439,   440,   441,   442,
     443,   444,   445,   446,   314,   315,   316,   317,   318,   131,
     184,   132,   133,   134,   450,   451,   359,   360,   361,   157,
      17,    18,   362,    16,   363,   239,    17,    18,    76,    77,
     240,   185,   186,   187,   188,    56,    75,   151,   152,   153,
     154,   155,   364,   151,   152,   153,   154,   155,   151,   152,
     153,   154,   155,   266,   313,   348,    76,    77,    78,   185,
     267,    57,   188,   296,   297,   448,   151,   152,    58,   140,
     155,   174,   175,   176,   177,   178,    59,   373,   174,   175,
     176,   177,   178,   433,   434,   435,   436,   437,   449,    76,
      77,    78,   392,   271,    30,   397,   398,   399,    60,   253,
     174,   175,   176,   177,   178,    61,   433,   434,   435,   436,
     437,   150,   185,   186,   187,   188,   221,   250,   251,    31,
     289,   290,   291,   292,   293,   193,    64,   151,   152,   153,
     154,   155,   174,   175,   176,   177,   178,   221,   294,    66,
     295,   151,   152,   153,   154,   155,   238,   400,   401,   296,
     297,   265,    65,   174,   175,   176,   177,   178,   268,   212,
     213,   214,   151,   152,   153,   154,   155,   174,   175,   176,
     177,   178,   277,    67,   269,   185,   186,   187,   188,   304,
     245,   246,   247,    79,   305,    69,   248,    71,   174,   175,
     176,   177,   178,   310,    72,   151,   152,   153,   154,   155,
     151,   152,   153,   154,   155,   324,   204,   205,   206,   174,
     175,   176,   177,   178,   325,    73,   174,   175,    81,   388,
     178,   174,   175,   176,   177,   178,   406,   282,   283,    83,
     174,   175,   176,   177,   178,   174,   175,   176,   177,   178,
     438,    84,   174,   175,   176,   177,   178,   447,   374,   375,
     376,    87,   452,    85,   377,    86,   433,   434,   435,   436,
     437,   453,    89,   433,   434,   435,   436,   437,   433,   434,
     435,   436,   437,   230,   113,   116,   143,   433,   434,   435,
     436,   437,   326,   380,   381,   382,   327,   144,   158,   254,
     185,   186,   187,   188,   328,   145,   146,   383,   384,   185,
     186,   187,   188,   185,   186,   187,   188,   250,   251,   147,
     159,   185,   186,   187,   188,   289,   290,   291,   292,   293,
     433,   434,   435,   436,   437,   148,   149,   174,   175,   176,
     177,   178,   433,   434,   160,   161,   437,   162,   241,   165,
     242,   170,   166,   189,   171,   172,   181,   182,   183,   190,
     191,   192,   217,   219,   218,   220,   155,   178,   188,   255,
     243,   256,   264,   274,   275,   276,   298,   307,   278,   279,
     308,   309,   351,   280,   311,   323,   320,   312,   329,   306,
     319,   333,   330,   337,   336,   370,   352,   338,   340,   339,
     355,   296,   350,   354,   369,   378,   385,   386,   387,   403,
     371,   372,   404,   405,   407,   379,   411,   410,   416,   345,
     417,   164,   349,   167,   430,   389,   390,   391,   413,   402,
     431,   432,    25,    24,   356,   412,   396,     0,    42,    41,
     427,    36,    55,    35,     0,    54,   437,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,    62
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        85,    72,    73,   157,   130,   131,     3,     4,     5,   257,
     258,    46,     9,     9,     8,    10,    10,     8,     8,     4,
       5,     8,    93,    94,     9,     8,    14,    11,    12,     8,
       8,    26,    27,    28,    69,    11,    41,   122,   123,    36,
      37,    76,    77,    78,     3,     4,     5,    52,   296,   297,
       9,    36,    37,    50,    51,   181,   182,   183,    54,   185,
     186,   187,   188,    54,    54,    50,    51,    54,    14,    53,
      29,    54,   143,   144,   145,    54,    54,    53,    42,    43,
     151,   152,   153,   154,   155,   170,   171,   172,     8,   174,
     175,   176,   177,   178,     3,     4,     5,     8,    46,    47,
       9,   255,   256,    48,    49,     9,    26,    27,    28,    29,
      30,    42,    21,    22,    23,   200,    27,    28,    29,    30,
      29,    10,    31,    32,    33,    29,     0,    31,    32,    33,
      34,    35,    10,    43,    38,    39,     3,     4,     5,    28,
      29,     5,     9,   269,   270,   271,     5,     3,     4,     5,
      28,    29,    14,     9,     3,     4,     5,   311,   312,    14,
       9,    47,    29,   248,    31,    32,    33,    46,   239,   240,
       6,    14,   257,    29,    14,    31,    32,    33,    24,    25,
      29,   266,   267,     3,    41,     5,    44,   421,   422,     9,
      26,    27,    28,    29,    30,    45,   430,   431,   432,   433,
     434,   435,   436,   437,   289,   290,   291,   292,   293,    29,
       6,    31,    32,    33,   448,   449,     3,     4,     5,     8,
      44,    45,     9,    41,    11,     8,    44,    45,    26,    27,
       8,    27,    28,    29,    30,     6,     6,    26,    27,    28,
      29,    30,    29,    26,    27,    28,    29,    30,    26,    27,
      28,    29,    30,     8,    10,   340,    26,    27,    28,    27,
       8,     6,    30,    19,    20,     8,    26,    27,    53,     6,
      30,    26,    27,    28,    29,    30,    53,   362,    26,    27,
      28,    29,    30,    26,    27,    28,    29,    30,     8,    26,
      27,    28,   377,     8,    48,   380,   381,   382,    14,    10,
      26,    27,    28,    29,    30,    14,    26,    27,    28,    29,
      30,    10,    27,    28,    29,    30,    10,    28,    29,    49,
      14,    15,    16,    17,    18,    10,     3,    26,    27,    28,
      29,    30,    26,    27,    28,    29,    30,    10,     8,    53,
      10,    26,    27,    28,    29,    30,    10,   383,   384,    19,
      20,    10,     3,    26,    27,    28,    29,    30,    10,     3,
       4,     5,    26,    27,    28,    29,    30,    26,    27,    28,
      29,    30,    10,    53,    26,    27,    28,    29,    30,    10,
       3,     4,     5,     3,    10,    14,     9,     9,    26,    27,
      28,    29,    30,    10,     9,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,    10,   147,   148,   149,    26,
      27,    28,    29,    30,    10,     9,    26,    27,     3,    10,
      30,    26,    27,    28,    29,    30,    10,   250,   251,    53,
      26,    27,    28,    29,    30,    26,    27,    28,    29,    30,
      10,    53,    26,    27,    28,    29,    30,    10,     3,     4,
       5,     3,    10,    14,     9,    14,    26,    27,    28,    29,
      30,    10,     3,    26,    27,    28,    29,    30,    26,    27,
      28,    29,    30,    10,     9,     9,     9,    26,    27,    28,
      29,    30,    10,    14,    15,    16,    10,     9,     3,    10,
      27,    28,    29,    30,    10,     9,     9,    28,    29,    27,
      28,    29,    30,    27,    28,    29,    30,    28,    29,     9,
       6,    27,    28,    29,    30,    14,    15,    16,    17,    18,
      26,    27,    28,    29,    30,     9,     9,    26,    27,    28,
      29,    30,    26,    27,     3,     6,    30,     3,    27,     9,
      27,     9,    54,     3,     9,     9,     9,     9,     9,     6,
       3,     6,     8,     3,     6,     6,    30,    30,    30,     8,
      27,     8,     8,     3,     3,     3,     3,     3,    27,    27,
       3,     3,    13,    27,     8,    10,     6,     8,     3,    27,
       9,     3,    27,     3,     8,    27,     3,    10,     7,    10,
       6,    19,    10,     8,     3,     8,     3,     3,     3,     3,
      27,    27,     3,     3,     3,    19,     3,    10,     6,    53,
       3,   114,   341,   118,     9,    27,    27,    27,    14,    27,
       9,     9,     7,     6,   351,    27,   379,    -1,    20,    19,
     414,    15,    23,    14,    -1,    22,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    33
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
     101,   101,     3,     4,     5,    99,    99,     8,     6,     3,
       6,    10,    59,    59,    59,    59,    59,    59,    59,    59,
      10,    58,    58,    58,    58,    58,    58,    58,    10,     8,
       8,    27,    27,    27,    59,     3,     4,     5,     9,    10,
      28,    29,    10,    10,    10,     8,     8,     9,    21,    22,
      23,    59,    82,    83,     8,    10,     8,     8,    10,    26,
       8,     8,   101,   101,     3,     3,     3,    10,    27,    27,
      27,    59,   104,   104,    99,    99,    59,    82,    82,    14,
      15,    16,    17,    18,     8,    10,    19,    20,     3,    59,
      59,    58,    58,    58,    10,    10,    27,     3,     3,     3,
      10,     8,     8,    10,    59,    59,    59,    59,    59,     9,
       6,    82,    82,    10,    10,    10,    10,    10,    10,     3,
      27,    99,    99,     3,    80,    81,     8,     3,    10,    10,
       7,     8,    10,    11,    12,    53,    87,    88,    59,    81,
      10,    13,     3,    89,     8,     6,    88,     8,    54,     3,
       4,     5,     9,    11,    29,    90,    91,    92,    93,     3,
      27,    27,    27,    59,     3,     4,     5,     9,     8,    19,
      14,    15,    16,    28,    29,     3,     3,     3,    10,    27,
      27,    27,    59,    11,    53,    94,    90,    59,    59,    59,
      93,    93,    27,     3,     3,     3,    10,     3,    95,    96,
      10,     3,    27,    14,     8,    54,     6,     3,     3,     4,
       5,     9,    29,    31,    32,    33,    60,    96,    60,    60,
       9,     9,     9,    26,    27,    28,    29,    30,    10,    60,
      60,    60,    60,    60,    60,    60,    60,    10,     8,     8,
      60,    60,    10,    10
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
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104
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
       1,     4,     1,    10,    10,     3,     3,     3,     3,     1,
       1,     1,     6,     6,     2,     4,     3,     3,     3,     3,
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
       4,    -1,     5,    -1,     3,    -1,    36,     9,   101,    10,
      -1,    37,    -1,    50,     9,   101,     8,    99,     8,    99,
       8,    99,    10,    -1,    51,     9,   101,     8,    99,     8,
      99,     8,    99,    10,    -1,     9,   100,    10,    -1,   100,
      28,   100,    -1,   100,    27,   100,    -1,   100,    26,   100,
      -1,     5,    -1,     4,    -1,   102,    -1,    32,     9,   101,
       8,   101,    10,    -1,    33,     9,   101,     8,   101,    10,
      -1,    29,   101,    -1,    31,     9,   101,    10,    -1,     9,
     101,    10,    -1,   101,    30,   101,    -1,   101,    28,   101,
      -1,   101,    29,   101,    -1,   101,    27,   101,    -1,   101,
      26,   101,    -1,    38,     9,   103,    10,    -1,    34,     9,
     103,    10,    -1,    35,     9,   103,    10,    -1,    39,     9,
     103,    10,    -1,   104,    -1,   103,    29,   104,    -1,   103,
      28,   104,    -1,     3,    -1,     9,    59,    10,    27,     3,
      -1,     5,    27,     3,    -1,     4,    27,     3,    -1,     3,
      27,     3,    -1,    29,     3,    -1,    29,     9,    59,    10,
      27,     3,    -1,    29,     5,    27,     3,    -1,    29,     4,
      27,     3,    -1,    29,     3,    27,     3,    -1
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
     514,   516,   521,   523,   534,   545,   549,   553,   557,   561,
     563,   565,   567,   574,   581,   584,   589,   593,   597,   601,
     605,   609,   613,   618,   623,   628,   633,   635,   639,   643,
     645,   651,   655,   659,   663,   666,   673,   678,   683
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
     632,   634,   635,   637,   644,   644,   646,   657,   670,   671,
     672,   682,   686,   689,   705,   722,   725,   728,   731,   734,
     737,   741,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   755,   765,   775,   785,   796,   797,   798,   800,
     804,   809,   814,   819,   838,   842,   847,   852,   857
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
  const int Lha_parser::yylast_ = 651;
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
#line 2697 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 881 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
