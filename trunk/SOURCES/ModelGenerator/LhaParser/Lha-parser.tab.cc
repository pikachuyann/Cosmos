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
	Reader.MyLha.HASLname.push_back(*(yysemantic_stack_[(4) - (1)].name));
	Reader.MyLha.HASLtop.push_back((yysemantic_stack_[(4) - (3)].TOPHASL));
}
    break;

  case 127:
/* Line 670 of lalr1.cc  */
#line 650 "Lha-parser.yy"
    {
	Reader.MyLha.HASLname.push_back("");
	Reader.MyLha.HASLtop.push_back((yysemantic_stack_[(2) - (1)].TOPHASL));
}
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 656 "Lha-parser.yy"
    {
	Reader.MyLha.Algebraic.push_back((yysemantic_stack_[(4) - (3)].expression));
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,Reader.MyLha.ConfidenceLevel);
}
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 660 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(Reader.MyLha.ConfidenceLevel);
}
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 663 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algPDF;
		algPDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" >= "<<bucket<<"&& "<<(yysemantic_stack_[(10) - (3)].expression)<<"<="<<bucket+(yysemantic_stack_[(10) - (5)].RealVal)<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
								Reader.MyLha.ConfidenceLevel));
		std::ostringstream s; s<<"Bucket Value:"<< bucket;
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
								Reader.MyLha.ConfidenceLevel);
}
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 679 "Lha-parser.yy"
    {
	
	for(double bucket = (yysemantic_stack_[(10) - (7)].RealVal) ; bucket < (yysemantic_stack_[(10) - (9)].RealVal) ; bucket+= (yysemantic_stack_[(10) - (5)].RealVal)){
		std::ostringstream algCDF;
		algCDF << "(("<<(yysemantic_stack_[(10) - (3)].expression)<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
		Reader.MyLha.ConfidenceLevel));
		std::ostringstream s; s<<"Bucket Value:"<< bucket;
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yyval.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1,
	Reader.MyLha.ConfidenceLevel);
}
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 697 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = (yysemantic_stack_[(3) - (2)].TOPHASL);
}
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 700 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 703 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yysemantic_stack_[(3) - (1)].TOPHASL), (yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 706 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yysemantic_stack_[(3) - (1)].TOPHASL),(yysemantic_stack_[(3) - (3)].TOPHASL));
}
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 709 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].IntVal));
}
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 712 "Lha-parser.yy"
    {
	(yyval.TOPHASL) = new HaslFormulasTop(0.0,(double)(yysemantic_stack_[(1) - (1)].RealVal));
}
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 716 "Lha-parser.yy"
    {string ss=(yysemantic_stack_[(1) - (1)].expression);
	sprintf((yyval.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 719 "Lha-parser.yy"
    {sprintf((yyval.expression),"min(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 720 "Lha-parser.yy"
    {sprintf((yyval.expression),"max(%s,%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));}
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 721 "Lha-parser.yy"
    {sprintf((yyval.expression),"-%s", (yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 722 "Lha-parser.yy"
    {sprintf((yyval.expression),"floor(%s)", (yysemantic_stack_[(4) - (3)].expression));}
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 723 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s)", (yysemantic_stack_[(3) - (2)].expression));}
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 724 "Lha-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 725 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s + %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 726 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s - %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 727 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s * %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 728 "Lha-parser.yy"
    {sprintf((yyval.expression),"(%s / %s)", (yysemantic_stack_[(3) - (1)].expression),(yysemantic_stack_[(3) - (3)].expression));}
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 730 "Lha-parser.yy"
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

  case 150:
/* Line 670 of lalr1.cc  */
#line 740 "Lha-parser.yy"
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

  case 151:
/* Line 670 of lalr1.cc  */
#line 750 "Lha-parser.yy"
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

  case 152:
/* Line 670 of lalr1.cc  */
#line 760 "Lha-parser.yy"
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

  case 153:
/* Line 670 of lalr1.cc  */
#line 771 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s", (yysemantic_stack_[(1) - (1)].expression));  }
    break;

  case 154:
/* Line 670 of lalr1.cc  */
#line 772 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 773 "Lha-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 776 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(1) - (1)].name)]);}
	else {cout<<*(yysemantic_stack_[(1) - (1)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 780 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(5) - (5)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"(%s) * Var[%d]", (yysemantic_stack_[(5) - (2)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(5) - (5)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(5) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 785 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%d * Var[%d]", (yysemantic_stack_[(3) - (1)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 790 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(3) - (3)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"%f * Var[%d]", (yysemantic_stack_[(3) - (1)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(3) - (3)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(3) - (3)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 795 "Lha-parser.yy"
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

  case 161:
/* Line 670 of lalr1.cc  */
#line 814 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(2) - (2)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-Var[%d]", Reader.MyLha.VarIndex[*(yysemantic_stack_[(2) - (2)].name)]);}
	else {cout<<*(yysemantic_stack_[(2) - (2)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 818 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(6) - (6)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-(%s) * Var[%d]", (yysemantic_stack_[(6) - (3)].expression), Reader.MyLha.VarIndex[*(yysemantic_stack_[(6) - (6)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(6) - (5)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 823 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%d * Var[%d]", (yysemantic_stack_[(4) - (2)].IntVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 164:
/* Line 670 of lalr1.cc  */
#line 828 "Lha-parser.yy"
    { if(Reader.MyLha.VarIndex.find(*(yysemantic_stack_[(4) - (4)].name))!=Reader.MyLha.VarIndex.end())
	{sprintf((yyval.expression),"-%f * Var[%d]", (yysemantic_stack_[(4) - (2)].RealVal), Reader.MyLha.VarIndex[*(yysemantic_stack_[(4) - (4)].name)]);
	}
	else {cout<<*(yysemantic_stack_[(4) - (4)].name)<<" is not a Lha variable"<<endl;YYABORT;}}
    break;

  case 165:
/* Line 670 of lalr1.cc  */
#line 833 "Lha-parser.yy"
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
#line 1725 "Lha-parser.tab.cc"
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
         4,    -8,    -2,    26,   -14,    57,    69,    25,    36,    94,
    -222,   107,   112,    55,    86,   100,   162,   138,   140,   155,
     126,    12,   146,   151,  -222,  -222,   214,   217,   174,   211,
     248,   254,  -222,   226,   239,  -222,  -222,   299,   300,   274,
     281,    12,  -222,   332,  -222,  -222,    15,   338,  -222,   339,
     351,  -222,    12,   292,  -222,  -222,  -222,  -222,   334,   367,
     319,   321,  -222,  -222,   379,   380,   378,   392,  -222,    15,
     506,    96,    96,    96,  -222,  -222,    15,    15,    15,  -222,
      -1,  -222,     3,   393,   405,   139,   144,  -222,    10,  -222,
      17,   295,  -222,    96,    96,   406,   407,   419,   426,   427,
     428,   431,   323,  -222,    80,   210,  -222,  -222,   240,   402,
     432,   439,   435,   446,    -4,  -222,   452,   408,   405,  -222,
    -222,  -222,   139,   139,   454,   461,   462,   216,  -222,  -222,
     144,   144,   463,   466,   494,   220,   470,   498,   502,   501,
    -222,   328,   132,    96,    96,    96,     5,     5,     5,     5,
    -222,    96,    96,    96,    96,    96,   504,   507,  -222,  -222,
    -222,  -222,   509,   512,  -222,   526,   524,  -222,   335,   309,
     139,   139,   139,  -222,   139,   139,   139,   139,   139,   471,
      40,   144,   144,   144,  -222,   144,   144,   144,   144,  -222,
    -222,  -222,  -222,  -222,   349,   227,   243,   483,   518,   519,
     139,   256,   122,  -222,   135,   164,   499,   522,   522,   132,
     132,  -222,   523,   545,    91,  -222,   546,  -222,  -222,   356,
     250,   255,   525,   525,   309,   309,  -222,  -222,   361,    89,
     287,   527,    40,    40,  -222,  -222,    96,    96,   553,   555,
     556,   370,   533,   534,   535,   139,  -222,     5,     5,  -222,
    -222,  -222,   559,   560,    91,    91,  -222,  -222,   521,   280,
    -222,   562,  -222,   139,   139,  -222,   144,   144,   144,   382,
     391,  -222,  -222,  -222,   539,   564,   565,   566,   396,  -222,
    -222,   563,   567,   314,   209,  -222,   139,   139,   139,   139,
     139,   561,   568,    91,    91,   569,   403,   417,   485,   492,
     496,  -222,  -222,   570,  -222,  -222,  -222,   549,   573,   574,
    -222,   204,   204,   204,   204,   204,   577,  -222,  -222,   571,
     575,  -222,  -222,  -222,  -222,  -222,  -222,   578,   572,   576,
     580,   172,  -222,    16,  -222,  -222,  -222,   139,   577,   579,
    -222,   581,   582,   583,  -222,   204,  -222,   586,   531,  -222,
      21,   185,  -222,  -222,   585,  -222,   584,   587,   588,   139,
    -222,   364,   589,   590,   468,  -222,  -222,   592,   593,   595,
     424,   591,   594,   596,   139,    24,   185,   139,   139,   139,
     212,   212,  -222,  -222,  -222,   597,   598,   599,   600,   429,
    -222,   601,   602,  -222,   204,   204,   204,  -222,  -222,   603,
    -222,  -222,  -222,   604,   558,    22,  -222,   607,  -222,   605,
     152,   601,  -222,  -222,  -222,  -222,  -222,  -222,   152,   152,
     608,   610,   611,   514,  -222,   438,   377,   152,   152,   152,
     152,   152,   152,   152,   152,  -222,   450,   278,   283,   606,
     606,   377,   377,  -222,  -222,   152,   152,   459,   464,  -222,
    -222
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
       0,     0,    46,     0,   137,   136,     0,     0,   129,     0,
       0,     4,   124,     0,    51,    52,    50,    49,     0,     0,
       0,     0,    67,    68,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,   125,   127,     0,     0,     0,    62,
       0,    65,     0,     0,     0,     0,     0,    54,     0,    57,
       0,     0,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,   135,   134,   133,     0,
       0,     0,     0,     0,     0,    70,     0,     0,    90,    19,
      17,    18,     0,     0,     0,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   141,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,    63,    61,
      66,    64,     0,     0,    71,     0,     0,    91,     0,    21,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,    47,     0,     0,     0,     0,    55,
      53,    58,    56,   143,     0,     0,     0,   156,     0,     0,
       0,     0,     0,   153,     0,     0,     0,   148,   147,   145,
     146,   144,     0,     0,     0,    69,     0,    89,    20,     0,
       0,     0,    22,    25,    23,    24,    26,     7,     0,     0,
       0,    11,     9,    10,    12,   142,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,   150,     0,     0,   151,
     149,   152,     0,     0,     0,     0,    77,    78,     0,     0,
      79,     0,    27,     0,     0,    13,     0,     0,     0,     0,
       0,   160,   159,   158,     0,     0,     0,     0,     0,   155,
     154,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,   140,     0,   165,   164,   163,     0,     0,     0,
      82,    84,    86,    85,    87,    88,     0,    73,    80,    81,
       0,    28,    29,    14,    15,    16,   157,     0,     0,     0,
       0,     0,    74,     0,   162,   130,   131,     0,     0,     0,
      93,    94,     0,     0,    96,    76,    75,     0,     0,    98,
       0,     0,    72,    95,     0,    97,   109,     0,     0,     0,
     102,     0,     0,   100,     0,   106,    99,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   112,   111,     0,     0,     0,     0,     0,
     120,     0,     0,   101,   103,   105,   104,   108,   107,     0,
     118,   117,   116,     0,     0,     0,   121,     0,   110,     0,
       0,     0,   119,    92,   115,    32,    30,    31,     0,     0,
       0,     0,     0,   123,   122,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,    35,
      38,    36,    37,    39,    40,     0,     0,     0,     0,    41,
      42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yypgoto_[] =
  {
      -222,  -222,  -222,  -127,   -85,  -221,  -222,   609,  -222,   615,
     619,   613,   612,  -222,   616,  -222,  -222,   618,  -222,   614,
    -222,  -222,   617,  -222,   479,  -222,   261,  -215,  -222,   620,
     482,  -222,  -222,   257,  -222,   231,  -222,  -222,   -84,  -222,
    -222,   199,   -10,  -222,   -33,   -71,  -222,   -11,    78
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Lha_parser::yydefgoto_[] =
  {
        -1,     3,     4,   135,   258,   423,     5,    19,    20,     6,
       7,    21,    22,    88,    23,    90,    13,    14,    80,    15,
      82,    32,    33,   114,   115,   331,   332,   259,   260,    34,
     117,   118,   343,   344,   350,   362,   363,   364,   365,   392,
     405,   406,    51,    52,    53,   102,   103,   202,   203
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Lha_parser::yytable_ninf_ = -1;
  const unsigned short int
  Lha_parser::yytable_[] =
  {
       127,   104,   105,   179,   180,   113,     8,   109,   197,   198,
     199,   111,     9,    70,   200,    43,    44,    45,   136,    44,
      45,    46,   141,   142,    46,   138,    10,   340,   341,   354,
     411,    68,    11,    12,   201,   390,    91,   168,   169,   284,
     285,    26,    74,   106,   107,   108,     1,     2,    47,    48,
     163,    47,    48,   110,   228,   229,   230,   112,   231,   232,
     233,   234,    49,    50,   137,    49,    50,   185,     2,   342,
     188,   139,   194,   195,   196,   355,   412,   391,   318,   319,
     207,   208,   209,   210,   211,   219,   220,   221,   156,   222,
     223,   224,   225,   226,   119,   120,   121,   267,    16,    27,
     254,    17,    18,    30,    31,    93,   151,   152,   153,   154,
     155,     1,   255,   256,   257,   241,   185,   186,   187,   188,
     123,    28,   124,   125,   126,    94,    29,    95,    96,    97,
      98,    99,   246,    12,   100,   101,   204,   205,   206,   298,
     299,   300,   119,   120,   121,   249,    11,   128,   122,   129,
     247,   248,    39,   130,    40,   415,   416,   417,   151,   152,
     278,   418,   155,   247,   248,   269,   270,    16,   123,   283,
     124,   125,   126,   131,   250,   132,   133,   134,   296,   297,
     338,   419,   339,   420,   421,   422,    37,    38,   356,   357,
     358,    18,   247,   248,   359,    17,   360,   425,   426,    17,
      18,   311,   312,   313,   314,   315,   436,   437,   438,   439,
     440,   441,   442,   443,   361,   356,   357,   358,   157,   310,
      56,   359,   173,    57,   447,   448,   184,    58,   293,   294,
     174,   175,   176,   177,   178,   236,   151,   152,   153,   154,
     155,   361,   174,   175,   176,   177,   178,   185,   186,   187,
     188,   237,   345,   151,   152,   153,   154,   155,   263,   242,
     243,   244,    60,   264,    59,   245,    76,    77,    61,   151,
     152,   153,   154,   155,   370,    31,   174,   175,   176,   177,
     178,   174,   175,   176,   177,   178,   445,    30,   291,   389,
     292,   446,   394,   395,   396,   268,   397,   398,    75,   293,
     294,   140,    64,    65,   430,   431,   432,   433,   434,   430,
     431,   432,   433,   434,   185,   186,   187,   188,    76,    77,
      78,    76,    77,    78,   218,   279,   280,    66,   286,   287,
     288,   289,   290,   150,    67,   174,   175,    79,   193,   178,
     174,   175,   176,   177,   178,   218,    69,    71,    72,   151,
     152,   153,   154,   155,   151,   152,   153,   154,   155,   235,
      73,   174,   175,   176,   177,   178,   262,   371,   372,   373,
      81,   265,    83,   374,    84,   151,   152,   153,   154,   155,
     274,    87,   174,   175,   176,   177,   178,   266,   185,   186,
     187,   188,   301,    85,    86,    89,   174,   175,   176,   177,
     178,   302,   113,   430,   431,   158,   307,   434,   151,   152,
     153,   154,   155,   321,   116,   143,   144,   151,   152,   153,
     154,   155,   174,   175,   176,   177,   178,   322,   145,   174,
     175,   176,   177,   178,   385,   146,   147,   148,   159,   403,
     149,   161,   160,   174,   175,   176,   177,   178,   435,   162,
     174,   175,   176,   177,   178,   174,   175,   176,   177,   178,
     444,   165,   166,   170,   430,   431,   432,   433,   434,   449,
     171,   172,   181,   189,   450,   182,   430,   431,   432,   433,
     434,   227,   377,   378,   379,   430,   431,   432,   433,   434,
     430,   431,   432,   433,   434,   323,   380,   381,   185,   186,
     187,   188,   324,   183,   190,   191,   325,   192,   212,   251,
     238,   213,   185,   186,   187,   188,    92,   214,   215,   185,
     186,   187,   188,   185,   186,   187,   188,   247,   248,   216,
     217,   252,    76,    77,    78,   286,   287,   288,   289,   290,
     430,   431,   432,   433,   434,   239,   240,   174,   175,   176,
     177,   178,   155,   253,   261,   178,   271,   188,   272,   273,
     275,   276,   277,   281,   282,   295,   303,   304,   305,   306,
     316,   308,   410,   326,   317,   309,   327,   328,   329,   320,
     330,   334,   335,   333,   342,   349,   336,   337,   366,   347,
     293,   351,   352,   164,   348,   382,   383,   375,   384,   346,
     167,   400,   401,   402,   404,   353,   408,   393,   414,   376,
     424,   367,   407,   413,   368,   369,     0,   427,   386,   428,
     429,   387,    25,   388,   399,    24,     0,     0,    35,    42,
       0,   409,    41,    36,     0,    55,   434,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,     0,    62
  };

  /* YYCHECK.  */
  const short int
  Lha_parser::yycheck_[] =
  {
        85,    72,    73,   130,   131,     9,    14,     8,     3,     4,
       5,     8,    14,    46,     9,     3,     4,     5,     8,     4,
       5,     9,    93,    94,     9,     8,     0,    11,    12,     8,
       8,    41,    46,    47,    29,    11,    69,   122,   123,   254,
     255,     5,    52,    76,    77,    78,    42,    43,    36,    37,
      54,    36,    37,    54,   181,   182,   183,    54,   185,   186,
     187,   188,    50,    51,    54,    50,    51,    27,    43,    53,
      30,    54,   143,   144,   145,    54,    54,    53,   293,   294,
     151,   152,   153,   154,   155,   170,   171,   172,     8,   174,
     175,   176,   177,   178,     3,     4,     5,     8,    41,     5,
       9,    44,    45,    48,    49,     9,    26,    27,    28,    29,
      30,    42,    21,    22,    23,   200,    27,    28,    29,    30,
      29,    14,    31,    32,    33,    29,    14,    31,    32,    33,
      34,    35,    10,    47,    38,    39,   147,   148,   149,   266,
     267,   268,     3,     4,     5,    10,    46,     3,     9,     5,
      28,    29,    14,     9,    14,     3,     4,     5,    26,    27,
     245,     9,    30,    28,    29,   236,   237,    41,    29,   254,
      31,    32,    33,    29,    10,    31,    32,    33,   263,   264,
       8,    29,    10,    31,    32,    33,    24,    25,     3,     4,
       5,    45,    28,    29,     9,    44,    11,   418,   419,    44,
      45,   286,   287,   288,   289,   290,   427,   428,   429,   430,
     431,   432,   433,   434,    29,     3,     4,     5,     8,    10,
       6,     9,     6,     6,   445,   446,     6,    53,    19,    20,
      26,    27,    28,    29,    30,     8,    26,    27,    28,    29,
      30,    29,    26,    27,    28,    29,    30,    27,    28,    29,
      30,     8,   337,    26,    27,    28,    29,    30,     8,     3,
       4,     5,    14,     8,    53,     9,    26,    27,    14,    26,
      27,    28,    29,    30,   359,    49,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,     8,    48,     8,   374,
      10,     8,   377,   378,   379,     8,   380,   381,     6,    19,
      20,     6,     3,     3,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    27,    28,    29,    30,    26,    27,
      28,    26,    27,    28,    10,   247,   248,    53,    14,    15,
      16,    17,    18,    10,    53,    26,    27,     3,    10,    30,
      26,    27,    28,    29,    30,    10,    14,     9,     9,    26,
      27,    28,    29,    30,    26,    27,    28,    29,    30,    10,
       9,    26,    27,    28,    29,    30,    10,     3,     4,     5,
       3,    10,    53,     9,    53,    26,    27,    28,    29,    30,
      10,     3,    26,    27,    28,    29,    30,    26,    27,    28,
      29,    30,    10,    14,    14,     3,    26,    27,    28,    29,
      30,    10,     9,    26,    27,     3,    10,    30,    26,    27,
      28,    29,    30,    10,     9,     9,     9,    26,    27,    28,
      29,    30,    26,    27,    28,    29,    30,    10,     9,    26,
      27,    28,    29,    30,    10,     9,     9,     9,     6,    10,
       9,     6,     3,    26,    27,    28,    29,    30,    10,     3,
      26,    27,    28,    29,    30,    26,    27,    28,    29,    30,
      10,     9,    54,     9,    26,    27,    28,    29,    30,    10,
       9,     9,     9,     3,    10,     9,    26,    27,    28,    29,
      30,    10,    14,    15,    16,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,    10,    28,    29,    27,    28,
      29,    30,    10,     9,     6,     3,    10,     6,     4,    10,
      27,     4,    27,    28,    29,    30,    10,     8,     6,    27,
      28,    29,    30,    27,    28,    29,    30,    28,    29,     3,
       6,     8,    26,    27,    28,    14,    15,    16,    17,    18,
      26,    27,    28,    29,    30,    27,    27,    26,    27,    28,
      29,    30,    30,     8,     8,    30,     3,    30,     3,     3,
      27,    27,    27,     4,     4,     3,    27,     3,     3,     3,
       9,     8,    14,     3,     6,     8,    27,     4,     4,    10,
       3,     3,    10,     8,    53,     3,    10,     7,     3,    10,
      19,     8,     6,   114,    13,     3,     3,     8,     3,   338,
     118,     3,     3,     3,     3,   348,     3,   376,     3,    19,
     411,    27,    10,     6,    27,    27,    -1,     9,    27,     9,
       9,    27,     7,    27,    27,     6,    -1,    -1,    14,    20,
      -1,    27,    19,    15,    -1,    23,    30,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    33
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
      51,    97,    98,    99,    69,    67,     6,     6,    53,    53,
      14,    14,    84,    77,     3,     3,    53,    53,    97,    14,
      99,     9,     9,     9,    97,     6,    26,    27,    28,     3,
      73,     3,    75,    53,    53,    14,    14,     3,    68,     3,
      70,    99,    10,     9,    29,    31,    32,    33,    34,    35,
      38,    39,   100,   101,   100,   100,    99,    99,    99,     8,
      54,     8,    54,     9,    78,    79,     9,    85,    86,     3,
       4,     5,     9,    29,    31,    32,    33,    59,     3,     5,
       9,    29,    31,    32,    33,    58,     8,    54,     8,    54,
       6,   100,   100,     9,     9,     9,     9,     9,     9,     9,
      10,    26,    27,    28,    29,    30,     8,     8,     3,     6,
       3,     6,     3,    54,    79,     9,    54,    85,    59,    59,
       9,     9,     9,     6,    26,    27,    28,    29,    30,    58,
      58,     9,     9,     9,     6,    27,    28,    29,    30,     3,
       6,     3,     6,    10,   100,   100,   100,     3,     4,     5,
       9,    29,   102,   103,   102,   102,   102,   100,   100,   100,
     100,   100,     4,     4,     8,     6,     3,     6,    10,    59,
      59,    59,    59,    59,    59,    59,    59,    10,    58,    58,
      58,    58,    58,    58,    58,    10,     8,     8,    27,    27,
      27,    59,     3,     4,     5,     9,    10,    28,    29,    10,
      10,    10,     8,     8,     9,    21,    22,    23,    59,    82,
      83,     8,    10,     8,     8,    10,    26,     8,     8,   100,
     100,     3,     3,     3,    10,    27,    27,    27,    59,   103,
     103,     4,     4,    59,    82,    82,    14,    15,    16,    17,
      18,     8,    10,    19,    20,     3,    59,    59,    58,    58,
      58,    10,    10,    27,     3,     3,     3,    10,     8,     8,
      10,    59,    59,    59,    59,    59,     9,     6,    82,    82,
      10,    10,    10,    10,    10,    10,     3,    27,     4,     4,
       3,    80,    81,     8,     3,    10,    10,     7,     8,    10,
      11,    12,    53,    87,    88,    59,    81,    10,    13,     3,
      89,     8,     6,    88,     8,    54,     3,     4,     5,     9,
      11,    29,    90,    91,    92,    93,     3,    27,    27,    27,
      59,     3,     4,     5,     9,     8,    19,    14,    15,    16,
      28,    29,     3,     3,     3,    10,    27,    27,    27,    59,
      11,    53,    94,    90,    59,    59,    59,    93,    93,    27,
       3,     3,     3,    10,     3,    95,    96,    10,     3,    27,
      14,     8,    54,     6,     3,     3,     4,     5,     9,    29,
      31,    32,    33,    60,    96,    60,    60,     9,     9,     9,
      26,    27,    28,    29,    30,    10,    60,    60,    60,    60,
      60,    60,    60,    60,    10,     8,     8,    60,    60,    10,
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
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103
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
       1,     1,     3,     3,     1,     2,     4,     2,     4,     1,
      10,    10,     3,     3,     3,     3,     1,     1,     1,     6,
       6,     2,     4,     3,     3,     3,     3,     3,     3,     4,
       4,     4,     4,     1,     3,     3,     1,     5,     3,     3,
       3,     2,     6,     4,     4,     4
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
  "term", "UPDATES", "Updates", "Update", "HaslExps", "HaslExp",
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
      97,    -1,     3,    14,    99,     6,    -1,    99,     6,    -1,
      36,     9,   100,    10,    -1,    37,    -1,    50,     9,   100,
       8,     4,     8,     4,     8,     4,    10,    -1,    51,     9,
     100,     8,     4,     8,     4,     8,     4,    10,    -1,     9,
      99,    10,    -1,    99,    28,    99,    -1,    99,    27,    99,
      -1,    99,    26,    99,    -1,     5,    -1,     4,    -1,   101,
      -1,    32,     9,   100,     8,   100,    10,    -1,    33,     9,
     100,     8,   100,    10,    -1,    29,   100,    -1,    31,     9,
     100,    10,    -1,     9,   100,    10,    -1,   100,    30,   100,
      -1,   100,    28,   100,    -1,   100,    29,   100,    -1,   100,
      27,   100,    -1,   100,    26,   100,    -1,    38,     9,   102,
      10,    -1,    34,     9,   102,    10,    -1,    35,     9,   102,
      10,    -1,    39,     9,   102,    10,    -1,   103,    -1,   102,
      29,   103,    -1,   102,    28,   103,    -1,     3,    -1,     9,
      59,    10,    27,     3,    -1,     5,    27,     3,    -1,     4,
      27,     3,    -1,     3,    27,     3,    -1,    29,     3,    -1,
      29,     9,    59,    10,    27,     3,    -1,    29,     5,    27,
       3,    -1,    29,     4,    27,     3,    -1,    29,     3,    27,
       3,    -1
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
     485,   487,   489,   493,   497,   499,   502,   507,   510,   515,
     517,   528,   539,   543,   547,   551,   555,   557,   559,   561,
     568,   575,   578,   583,   587,   591,   595,   599,   603,   607,
     612,   617,   622,   627,   629,   633,   637,   639,   645,   649,
     653,   657,   660,   667,   672,   677
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
     632,   634,   635,   637,   644,   644,   646,   650,   656,   660,
     663,   679,   697,   700,   703,   706,   709,   712,   716,   719,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   730,
     740,   750,   760,   771,   772,   773,   775,   779,   784,   789,
     794,   813,   817,   822,   827,   832
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
  const int Lha_parser::yylast_ = 653;
  const int Lha_parser::yynnts_ = 49;
  const int Lha_parser::yyempty_ = -2;
  const int Lha_parser::yyfinal_ = 10;
  const int Lha_parser::yyterror_ = 1;
  const int Lha_parser::yyerrcode_ = 256;
  const int Lha_parser::yyntokens_ = 55;

  const unsigned int Lha_parser::yyuser_token_number_max_ = 307;
  const Lha_parser::token_number_type Lha_parser::yyundef_token_ = 2;


} // lha
/* Line 1141 of lalr1.cc  */
#line 2651 "Lha-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 856 "Lha-parser.yy"


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
