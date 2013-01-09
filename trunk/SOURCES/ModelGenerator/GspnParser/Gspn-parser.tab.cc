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
#define yylex   gspnlex

/* First part of user declarations.  */

/* Line 279 of lalr1.cc  */
#line 40 "Gspn-parser.tab.cc"


#include "Gspn-parser.tab.hh"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 48 "Gspn-parser.tab.cc"
/* Unqualified %code blocks.  */
/* Line 286 of lalr1.cc  */
#line 40 "Gspn-parser.yy"

#include "Gspn-Reader.hpp"
#include <set>
#include <vector>

vector<string> Par;
std::string distrib;
Eval Evaluate;


int NbServers;
bool SingleService;
bool MarkingDependent;
bool AgeMemory;



/* Line 286 of lalr1.cc  */
#line 70 "Gspn-parser.tab.cc"


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


namespace gspn {
/* Line 353 of lalr1.cc  */
#line 165 "Gspn-parser.tab.cc"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Gspn_parser::yytnamerr_ (const char *yystr)
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
  Gspn_parser::Gspn_parser (Gspn_Reader& Reader_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      Reader (Reader_yyarg)
  {
  }

  Gspn_parser::~Gspn_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Gspn_parser::yy_symbol_value_print_ (int yytype,
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
#line 110 "Gspn-parser.yy"
        { debug_stream () << *((*yyvaluep).name); };
/* Line 423 of lalr1.cc  */
#line 241 "Gspn-parser.tab.cc"
        break;
      case 5: /* rval */
/* Line 423 of lalr1.cc  */
#line 114 "Gspn-parser.yy"
        { debug_stream () << ((*yyvaluep).RealVal); };
/* Line 423 of lalr1.cc  */
#line 248 "Gspn-parser.tab.cc"
        break;
      case 6: /* ival */
/* Line 423 of lalr1.cc  */
#line 113 "Gspn-parser.yy"
        { debug_stream () << ((*yyvaluep).IntVal); };
/* Line 423 of lalr1.cc  */
#line 255 "Gspn-parser.tab.cc"
        break;
       default:
	  break;
      }
  }


  void
  Gspn_parser::yy_symbol_print_ (int yytype,
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
  Gspn_parser::yydestruct_ (const char* yymsg,
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
#line 111 "Gspn-parser.yy"
        { delete ((*yyvaluep).name); };
/* Line 455 of lalr1.cc  */
#line 293 "Gspn-parser.tab.cc"
        break;

	default:
	  break;
      }
  }

  void
  Gspn_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Gspn_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Gspn_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Gspn_parser::debug_level_type
  Gspn_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Gspn_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Gspn_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Gspn_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Gspn_parser::parse ()
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
          case 2:
/* Line 670 of lalr1.cc  */
#line 126 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 127 "Gspn-parser.yy"
    {
				   if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyGspn.PlacesList.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyGspn.PlacesId[*(yysemantic_stack_[(1) - (1)].name)]<<" ] ";
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						 
						}
					else if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyGspn.IntConstant.end())
						{std::ostringstream s; s<<Reader.MyGspn.IntConstant[*(yysemantic_stack_[(1) - (1)].name)];
						 sprintf((yyval.expression), "%s",(s.str()).c_str());
						
						 }
					else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' has not been declared"<<endl;YYABORT;}}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 138 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 139 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 140 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 141 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 142 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 143 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 144 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 145 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 146 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 149 "Gspn-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 150 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 151 "Gspn-parser.yy"
    {
				   if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyGspn.PlacesList.end()) 
						{std::ostringstream s; s<<" Marking[ "<<Reader.MyGspn.PlacesId[*(yysemantic_stack_[(1) - (1)].name)]<<" ] ";
						 sprintf((yyval.expression), "%s",(s.str()).c_str());						
						}
					else if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(1) - (1)].name))!=Reader.MyGspn.RealConstant.end())
						{std::ostringstream s; s<<Reader.MyGspn.RealConstant[*(yysemantic_stack_[(1) - (1)].name)];
						 sprintf((yyval.expression), "%s",(s.str()).c_str()); 
						 }
					else{cout<<"'"<<*(yysemantic_stack_[(1) - (1)].name)<<"' has not been declared"<<endl;YYABORT;}}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 161 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 162 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 163 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 164 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 165 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 166 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 167 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 168 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 169 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 188 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.IntConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.IntResult;Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 195 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 205 "Gspn-parser.yy"
    {Reader.MyGspn.pl=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 208 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
						Reader.MyGspn.pl=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                    
}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 217 "Gspn-parser.yy"
    {Reader.MyGspn.tr=(yysemantic_stack_[(4) - (3)].IntVal);
                                       
}
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 220 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
					  Reader.MyGspn.tr=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                      
}
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 229 "Gspn-parser.yy"
    {
						if(Reader.MyGspn.PlacesId.size()!=Reader.MyGspn.pl){
						std::cout<<"Place label missing or redeclared, please check your places list"<<std::endl;
						YYABORT;
						}
                                                

                                                if(true){
                                                vector<int> v(Reader.MyGspn.pl,0);
						vector<string> vStr(Reader.MyGspn.pl, " ");

                                                Reader.MyGspn.Marking=v;
                                                vector< vector<int> > m1(Reader.MyGspn.tr,v);  
					        vector< vector<string> > m1Str(Reader.MyGspn.tr,vStr);
                                               
                                                Reader.MyGspn.outArcs=m1;
						Reader.MyGspn.inArcs=m1;
						Reader.MyGspn.inhibArcs=m1;

						Reader.MyGspn.outArcsStr=m1Str;
						Reader.MyGspn.inArcsStr=m1Str;
						Reader.MyGspn.inhibArcsStr=m1Str;
}


                                                if(true){vector<TransType> v(Reader.MyGspn.tr);
                                                Reader.MyGspn.tType=v;
                                                    }
                                                if(true){
                                                    vector<Distribution> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.Dist=d;
                                                    }
                                                if(true){
                                                    vector<string> d(Reader.MyGspn.tr,"");
                                                    Reader.MyGspn.Priority=d;
                                                    }
												if(true){
                                                    vector<string> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.Weight=d;
                                                    }
											  if(true){
												vector<bool> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.MarkingDependent=d;
													Reader.MyGspn.AgeMemory=d;

														}
											  if(true){
												vector<bool> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.SingleService=d;
											  }
												if(true){
												vector<int> d(Reader.MyGspn.tr);
                                                    Reader.MyGspn.NbServers=d;
											  }

											MarkingDependent=false;
											AgeMemory=false;
                           
                                                   


}
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 292 "Gspn-parser.yy"
    {
              
                Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(1) - (1)].name));
                int sz=Reader.MyGspn.PlacesId.size();
                Reader.MyGspn.PlacesId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
}
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 298 "Gspn-parser.yy"
    {Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.PlacesId.size();
                            Reader.MyGspn.PlacesId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                         
}
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 304 "Gspn-parser.yy"
    {
						      if(Reader.MyGspn.TransId.size()!=Reader.MyGspn.tr){
						      std::cout<<"Transition label missing or redeclared, please check your transitions list"<<std::endl;
						      YYABORT;
						    }
                                                 
                                                    }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 312 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(1) - (1)].name));
               int sz=Reader.MyGspn.TransId.size();
               Reader.MyGspn.TransId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
               
                }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 317 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.TransId.size();
                            Reader.MyGspn.TransId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                           
                            }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 327 "Gspn-parser.yy"
    {}
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 333 "Gspn-parser.yy"
    { if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(6) - (2)].name))==Reader.MyGspn.PlacesList.end())
					    {cout<<"'"<<*(yysemantic_stack_[(6) - (2)].name)<<"' has not been declared"<<endl;
					    YYABORT;
					    }
				  string st=(yysemantic_stack_[(6) - (4)].expression);
				  if(Evaluate.parse(st)){
					    std::cout<<"Initial Marking is not marking dependent"<<std::endl;
					    YYABORT;
					    }				
				Reader.MyGspn.Marking[Reader.MyGspn.PlacesId[*(yysemantic_stack_[(6) - (2)].name)]]=Evaluate.IntResult;
				}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 346 "Gspn-parser.yy"
    {
				  for(size_t i=0; i<Reader.MyGspn.Priority.size();i++){
					  if(Reader.MyGspn.Priority[i]=="")
							  {cout<<"Some transitions were not defined. All declared transitions must be defined"<<endl;
								YYABORT;
								  
							}
}
  }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 356 "Gspn-parser.yy"
    {}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 357 "Gspn-parser.yy"
    {}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 359 "Gspn-parser.yy"
    {
					    if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(10) - (2)].name))==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*(yysemantic_stack_[(10) - (2)].name)<<" was not declared"<<std::endl;
						YYABORT;
						}
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]].name=distrib;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]].Param=Par;
                        vector<string> v;
                        Par=v;					    
					    Reader.MyGspn.Priority[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=(yysemantic_stack_[(10) - (6)].expression);
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=(yysemantic_stack_[(10) - (8)].expression); 
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=1;
                        }
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 377 "Gspn-parser.yy"
    {
					    if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(12) - (2)].name))==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*(yysemantic_stack_[(12) - (2)].name)<<" was not declared"<<std::endl;
						YYABORT;
						}
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]].name=distrib;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]].Param=Par;
                        vector<string> v;
                        Par=v;					    
					    Reader.MyGspn.Priority[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=(yysemantic_stack_[(12) - (6)].expression);
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=(yysemantic_stack_[(12) - (8)].expression); 
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=AgeMemory;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(12) - (2)].name)]]=1;
						AgeMemory=false;
                        }
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 396 "Gspn-parser.yy"
    {
					    if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(15) - (2)].name))==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*(yysemantic_stack_[(15) - (2)].name)<<" was not declared"<<std::endl;
						YYABORT;
						}
						
						if(!SingleService) MarkingDependent=true;
						string st=(yysemantic_stack_[(15) - (6)].expression);
						vector<string> v(1);
						if(Evaluate.parse(st)) 
							  {MarkingDependent=true;v[0]=st;
							   }
						else{ if (Evaluate.RealResult<= 0 ) {
							  cout << "In exponential ditribution Lambda > 0" << endl;
							  YYABORT;
							  }
						std::ostringstream s;s<<Evaluate.RealResult;
						v[0]=s.str();
						}
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]].Param=v;
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]].name="EXPONENTIAL";                       
						
						Reader.MyGspn.Priority[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=(yysemantic_stack_[(15) - (9)].expression);
						Reader.MyGspn.Weight[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=(yysemantic_stack_[(15) - (11)].expression);
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=SingleService;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=MarkingDependent;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=NbServers;
						MarkingDependent=false;
						
						}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 430 "Gspn-parser.yy"
    {
					    if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(17) - (2)].name))==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*(yysemantic_stack_[(17) - (2)].name)<<" was not declared"<<std::endl;
						YYABORT;
						}
						
						if(!SingleService) MarkingDependent=true;
						string st=(yysemantic_stack_[(17) - (6)].expression);
						vector<string> v(1);
						if(Evaluate.parse(st)) 
							  {MarkingDependent=true;v[0]=st;
							   }
						else{ if (Evaluate.RealResult<= 0 ) {
							  cout << "In exponential ditribution Lambda > 0" << endl;
							  YYABORT;
							  }
						std::ostringstream s;s<<Evaluate.RealResult;
						v[0]=s.str();
						}
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]].Param=v;
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=Timed;
                        Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]].name="EXPONENTIAL";                       
						
						Reader.MyGspn.Priority[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=(yysemantic_stack_[(17) - (9)].expression);
						Reader.MyGspn.Weight[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=(yysemantic_stack_[(17) - (11)].expression);
						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=SingleService;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=MarkingDependent;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=AgeMemory;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(17) - (2)].name)]]=NbServers;
						MarkingDependent=false;
						AgeMemory=false;
						}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 464 "Gspn-parser.yy"
    {
					    if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(10) - (2)].name))==Reader.MyGspn.TransList.end())
						{
						std::cout<<"Transition: "<<*(yysemantic_stack_[(10) - (2)].name)<<" was not declared"<<std::endl;
						YYABORT;
						}
					    
					    Reader.MyGspn.tType[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=unTimed;
						Reader.MyGspn.Dist[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]].name="IMMEDIATE";
                        Reader.MyGspn.Priority[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=(yysemantic_stack_[(10) - (6)].expression);
					    Reader.MyGspn.Weight[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=(yysemantic_stack_[(10) - (8)].expression);

						Reader.MyGspn.SingleService[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=true;
						Reader.MyGspn.MarkingDependent[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=false;
						Reader.MyGspn.AgeMemory[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=false;
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=1;						
						
                        }
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 488 "Gspn-parser.yy"
    {string st=(yysemantic_stack_[(1) - (1)].expression);
				 if(Evaluate.parse(st)) 
					{cout<<"Weight is not marking dependent: '"<<st<<"'"<<endl;YYABORT; }
				else{ if(Evaluate.RealResult<0)
						{cout<<"Weight is a positive value: '"<<st<<"'"<<endl; YYABORT;}
					   else{std::ostringstream s;s<<Evaluate.RealResult;
							sprintf((yyval.expression), "%s",(s.str()).c_str());
							} 
					}			    
			  }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 499 "Gspn-parser.yy"
    {string st=(yysemantic_stack_[(1) - (1)].expression);
				 if(Evaluate.parse(st)) 
					{cout<<"Priority is not marking dependent: '"<<st<<"'"<<endl;YYABORT; }
				else{ if(Evaluate.RealResult<0)
						{cout<<"Priority is a positive value: '"<<st<<"'"<<endl; YYABORT;}
					   else{std::ostringstream s;s<<Evaluate.RealResult;
							sprintf((yyval.expression), "%s",(s.str()).c_str());
							} 
					}			    
			  }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 510 "Gspn-parser.yy"
    {SingleService=true; NbServers=1;}
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 511 "Gspn-parser.yy"
    {SingleService=false;NbServers=INT_MAX;}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 512 "Gspn-parser.yy"
    {NbServers= (yysemantic_stack_[(4) - (3)].IntVal);
					  if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
					  

}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 522 "Gspn-parser.yy"
    {
					   if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))!=Reader.MyGspn.IntConstant.end()){
					   NbServers=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
					   if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
						}
				  else{cout<<*(yysemantic_stack_[(4) - (3)].name)<<" not defined or not defined like an integer constant "<<endl;}
				  
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 536 "Gspn-parser.yy"
    {AgeMemory=true;}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 537 "Gspn-parser.yy"
    {AgeMemory=false;}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 540 "Gspn-parser.yy"
    {
		distrib=*(yysemantic_stack_[(4) - (1)].name);
		int np=Par.size();

		switch (Reader.IndexDist[distrib]) {
        case 1:
		{
            if (np != 2){
                cout << "Uniform ditribution has two parameters: min and max where 0<=min<max" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1>=p2) || (p1<0)) {
               cout << "In uniform ditribution 0 <= min< max " << endl;
               YYABORT;
            }
	   break;
	  }

        case 2:
		{ 
            if (np != 1) {
                cout << "exponential ditribution has one parameter: Lambda > 0" << endl;
                YYABORT;
            } 
                
			double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<= 0 ) {
               cout << "In exponential ditribution Lambda > 0" << endl;
               YYABORT;
            }
	    break;
	  }
                    
        case 3:
		{
            if (np != 1) {
                cout << "Deterministic ditribution has one parameter:  T >= 0" << endl;
                YYABORT;
            }
            
            double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<0 ) {
               cout << "In Deterministic ditribution Lambda > 0" << endl;
               YYABORT;
            } 
	    break;
	  }
            
        case 4:
		{
            if (np != 2) {
                cout << "Lognormal ditribution has two parameters: mu and sigma^2, where mu > 0 sigma^2 > 0" << endl;
                YYABORT;
            }
            
            double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1<=0) || (p2<=0)) {
               cout << "In Lognormal ditribution mu > 0 sigma^2 > 0" << endl;
               YYABORT;
            } 
            break;
	  }

        case 5:
		{
            if (np != 3) {
                cout << "Triangle ditribution has three parameters: 0 <= b <= c <= a" << endl;
                YYABORT;
            }
            double p1,p2,p3;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
			st=Par[2];
			Evaluate.parse(st);p3=Evaluate.RealResult;
            if ((p1<0) || (p2<p1) || (p3<p2)) {
               cout << "In Triangle ditribution: 0 <= b <= c<= a" << endl;
               YYABORT;
            }

          
	    break;
	  }

	  case 6:
		{
            if (np != 2) {
                cout << "Geometric ditribution has two parameters: 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1<0) || (p1>1) || p2<=0) {
               cout << "In Geometric ditribution 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
               YYABORT;
            }            
	    break;
	  }
	  case 7:
		{
            if (np != 2) {
                cout << "Erlang distribution has two parameters: Shape and Rate, where Shape is a positive integer and Rate > 0" << endl;
                YYABORT;
            }
            
            
			string st=Par[0];
			Evaluate.parse(st);
			if(Evaluate.RealResult != Evaluate.IntResult || Evaluate.IntResult < 1){
               cout << "In Erlang distribution Shape is a positive integer" << endl;
               YYABORT;
            } 
			
			st=Par[1];
			Evaluate.parse(st);
            if (Evaluate.RealResult<=0) {
               cout << "In Erlang distribution Rate > 0" << endl;
               YYABORT;
            } 
            break;
	  }
	  case 8:
		{
            if (np != 2) {
                cout << "Gamma distribution has two parameters: Shape>0 and Scale>0" << endl;
                YYABORT;
            }
            
            
			string st=Par[0];
			Evaluate.parse(st);
			if(Evaluate.RealResult<=0){
               cout << "In Gamma distribution Shape > 0" << endl;
               YYABORT;
            } 
			
			st=Par[1];
			Evaluate.parse(st);
            if (Evaluate.RealResult<=0) {
               cout << "In Gamma distribution Scale > 0" << endl;
               YYABORT;
            } 
            break;
	  }


        default: cout << "\nUnknown distribution !" << endl;
            YYABORT;

    }
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 716 "Gspn-parser.yy"
    {string st=(yysemantic_stack_[(1) - (1)].expression);
				 if(Evaluate.parse(st)) 
					{cout<<"The exponential ditribution is the only marking dependent distribution: '"<<st<<"'"<<endl;YYABORT; }
				 else{std::ostringstream s;s<<Evaluate.RealResult;
				 Par.push_back(s.str());
					} 
				}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 725 "Gspn-parser.yy"
    {}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 727 "Gspn-parser.yy"
    {}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 728 "Gspn-parser.yy"
    {}
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 730 "Gspn-parser.yy"
    {
						  if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(8) - (2)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(8) - (2)].name)<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(8) - (4)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(8) - (4)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  string st=(yysemantic_stack_[(8) - (6)].expression);
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=1;
						 	  Reader.MyGspn.inArcsStr[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=st;
						  }
						  else Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=Evaluate.IntResult;
						  		 
						  }
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 750 "Gspn-parser.yy"
    {
						  if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(6) - (2)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(6) - (2)].name)<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(6) - (4)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(6) - (4)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  Reader.MyGspn.inArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(6) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(6) - (2)].name)]]=1;						 

						  }
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 765 "Gspn-parser.yy"
    {}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 767 "Gspn-parser.yy"
    {}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 768 "Gspn-parser.yy"
    {}
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 770 "Gspn-parser.yy"
    {
						   if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(8) - (2)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(8) - (2)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						   if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(8) - (4)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(8) - (4)].name)<<" was not declared"<<std::endl;
							YYABORT;
						      }
						  string st=(yysemantic_stack_[(8) - (6)].expression);
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (2)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (4)].name)]]=1;
						 	  Reader.MyGspn.outArcsStr[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (2)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (4)].name)]]=st;
						  }
						  else Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (2)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (4)].name)]]=Evaluate.IntResult;
						 
						  }
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 790 "Gspn-parser.yy"
    {
						   if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(6) - (2)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(6) - (2)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						   if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(6) - (4)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(6) - (4)].name)<<" was not declared"<<std::endl;
							YYABORT;
						      }
						  Reader.MyGspn.outArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(6) - (2)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(6) - (4)].name)]]=1;						 
						    }
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 806 "Gspn-parser.yy"
    {}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 808 "Gspn-parser.yy"
    {}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 809 "Gspn-parser.yy"
    {}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 811 "Gspn-parser.yy"
    {
						  if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(8) - (2)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(8) - (2)].name)<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(8) - (4)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(8) - (4)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						 string st=(yysemantic_stack_[(8) - (6)].expression);
						  
						  if(Evaluate.parse(st)){
							  Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=1;
						 	  Reader.MyGspn.inhibArcsStr[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=st;
						  }
						  else Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(8) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(8) - (2)].name)]]=Evaluate.IntResult;
							 
						  }
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 832 "Gspn-parser.yy"
    {
						  if(Reader.MyGspn.PlacesList.find(*(yysemantic_stack_[(6) - (2)].name))==Reader.MyGspn.PlacesList.end())
						      {
							std::cout<<"Place: "<<*(yysemantic_stack_[(6) - (2)].name)<<" was not declared"<<std::endl;
							YYABORT;
							}
						  if(Reader.MyGspn.TransList.find(*(yysemantic_stack_[(6) - (4)].name))==Reader.MyGspn.TransList.end())
						      {
						      std::cout<<"Transition: "<<*(yysemantic_stack_[(6) - (4)].name)<<" was not declared"<<std::endl;
						      YYABORT;
						      }
						  Reader.MyGspn.inhibArcs[Reader.MyGspn.TransId[*(yysemantic_stack_[(6) - (4)].name)]][Reader.MyGspn.PlacesId[*(yysemantic_stack_[(6) - (2)].name)]]=1;
						 
						  }
    break;


/* Line 670 of lalr1.cc  */
#line 1496 "Gspn-parser.tab.cc"
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
  Gspn_parser::yysyntax_error_ (int yystate, int yytoken)
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
  const short int Gspn_parser::yypact_ninf_ = -210;
  const short int
  Gspn_parser::yypact_[] =
  {
        -7,    44,    62,     7,    13,    35,    48,    73,    58,    69,
      85,    59,   155,   120,   127,  -210,   162,   147,   147,    73,
     169,   175,  -210,   158,   176,  -210,  -210,  -210,   188,   195,
     196,   202,   199,   206,   183,   213,  -210,  -210,   194,  -210,
     203,   204,  -210,  -210,  -210,  -210,  -210,  -210,    55,    51,
     222,   207,   234,   223,   245,   246,  -210,  -210,    55,   241,
     242,   243,     9,  -210,  -210,  -210,    51,   244,   247,   248,
      56,   251,     0,  -210,   249,   215,   250,   230,  -210,    -5,
    -210,    -2,   161,    55,    55,    55,  -210,    55,    55,    55,
      55,    64,    51,    51,    51,  -210,    51,    51,    51,    51,
      51,   252,   255,  -210,   260,     1,  -210,   256,   226,   253,
    -210,   264,   261,   266,   263,  -210,   101,   105,   112,   257,
       2,     2,  -210,  -210,    83,    92,   119,   258,   258,   217,
     217,  -210,    55,  -210,   267,   265,  -210,   268,     5,  -210,
     269,   236,  -210,  -210,  -210,  -210,    55,    55,  -210,    55,
      51,    51,  -210,   168,    -1,  -210,   271,   270,  -210,   277,
      11,  -210,   272,   177,   184,   191,   129,   136,   275,   274,
     276,   278,   280,   282,  -210,   281,   279,  -210,   287,    12,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,    51,    51,    51,
      51,    -3,   288,  -210,   284,   286,  -210,   141,   224,  -210,
     141,   289,   153,   290,    55,   292,   227,   291,  -210,    51,
    -210,    51,   293,    51,   198,  -210,    55,   295,   228,  -210,
     141,   285,    51,   231,   296,   205,  -210,    55,   297,   298,
     299,   100,   301,  -210,   302,   212,  -210,  -210,    51,  -210,
    -210,   300,  -210,  -210,   304,   305,   307,  -210,    77,  -210,
    -210,  -210,   303,   232,   182,   100,   308,   306,   309,   310,
    -210,  -210,  -210,   311,  -210
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Gspn_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     1,     0,    25,     0,     0,
       0,     0,    28,     0,     0,    30,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    26,     0,    27,
       0,     0,    35,    36,    38,    37,    40,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     2,     0,     0,
       0,     0,     0,    15,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,    47,    42,     0,
      45,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    54,     0,     0,     0,
      48,     0,     0,     0,     0,     4,     0,     0,     0,     7,
       5,     6,     8,    16,     0,     0,     0,    17,    20,    18,
      19,    21,     0,    49,     0,     0,    55,     0,     0,    74,
       0,     0,    43,    41,    46,    44,     0,     0,     9,     0,
       0,     0,    22,     0,     0,    53,     0,     0,    75,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,    80,     0,     0,
      84,    11,    12,    10,    23,    24,    52,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    85,    72,     0,    70,
      62,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      69,     0,     0,     0,     0,    77,     0,     0,     0,    71,
      61,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    76,     0,     0,    87,    60,     0,    68,
      67,     0,    56,    81,     0,     0,     0,    86,     0,    57,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    66,    65,     0,    59
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yypgoto_[] =
  {
      -210,   -57,   -49,  -210,  -210,   313,   294,  -210,   312,   314,
     316,   315,  -210,   273,  -210,  -210,  -210,  -210,   254,   317,
    -210,   201,  -209,  -182,  -210,    67,  -210,  -210,   108,  -210,
    -210,   185,  -210,  -210,   167,  -210,  -210,   149,  -210
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yydefgoto_[] =
  {
        -1,    62,   200,     4,     5,     6,     7,     8,    22,     9,
      10,    23,    79,    24,    81,    17,    18,    72,    73,    36,
     105,   106,   221,   201,   253,   241,   172,   198,   199,    53,
     138,   139,    77,   160,   161,   110,   179,   180,    37
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Gspn_parser::yytable_ninf_ = -1;
  const unsigned short int
  Gspn_parser::yytable_[] =
  {
        70,    82,   169,   111,   223,   204,   113,   205,   203,    71,
     104,     1,     2,    15,   137,    87,    86,    91,    90,     3,
     159,   178,    87,    88,    89,    90,   116,   117,   118,   245,
     119,   120,   121,   122,    13,    14,   112,   170,   171,   114,
     230,   102,   135,   124,   125,   126,   157,   127,   128,   129,
     130,   131,   176,   195,    63,    11,    64,    65,    56,    16,
      66,    57,    28,    95,    58,    29,     1,     2,    96,    97,
      98,    99,   100,    12,   123,   153,    96,    97,    98,    99,
     100,    67,    68,    69,     3,    59,    60,    61,     2,   163,
     164,   150,   165,    20,    21,    96,    97,    98,    99,   100,
     151,   166,   167,     1,    96,    97,    98,    99,   100,   146,
     250,   251,   252,   147,    87,    88,    89,    90,    87,    88,
      89,    90,   148,    32,   149,    87,    88,    89,    90,   152,
      33,    96,    97,    98,    99,   100,   239,   240,   197,   184,
     202,    96,    97,    98,    99,   100,   185,   214,    96,    97,
      98,    99,   100,    96,    97,    98,    99,   100,    30,   225,
     197,    31,   220,   212,   220,    96,    97,    98,    99,   100,
     235,   115,    35,    34,    87,    88,    89,    90,   168,    21,
      40,    87,    88,    89,    90,   257,    41,   181,   258,   220,
      87,    88,    89,    90,   182,    44,    20,    87,    88,    89,
      90,   183,    45,    46,    87,    88,    89,    90,   224,    47,
      48,    87,    88,    89,    90,   234,    52,    49,    87,    88,
      89,    90,   244,    50,    51,    87,    88,    89,    90,    96,
      97,    71,   209,   100,   210,   216,   227,   217,   228,   231,
     255,   232,   256,    54,    55,    75,    76,    74,    78,    80,
      83,    84,    85,    92,   101,   107,    93,    94,   104,   109,
     132,   108,   133,   134,   141,   137,   140,   142,   143,   144,
     145,   156,   155,    90,   100,   154,   162,   174,   159,   173,
     175,   178,   186,   187,   188,   191,   193,   189,   190,   192,
     194,   206,   207,   208,   218,   229,    42,   211,   213,   215,
      19,   222,   226,   233,   236,   237,   136,   238,   242,   243,
     246,   247,   254,   248,   249,   260,   261,   219,   264,   262,
     263,    25,   259,   158,    27,    26,   103,   177,   196,     0,
       0,    39,     0,     0,     0,    38,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  Gspn_parser::yycheck_[] =
  {
        49,    58,     3,     8,   213,     8,     8,    10,   190,     9,
       9,    18,    19,     0,     9,    13,     7,    66,    16,    26,
       9,     9,    13,    14,    15,    16,    83,    84,    85,   238,
      87,    88,    89,    90,    27,    28,    41,    38,    39,    41,
     222,    41,    41,    92,    93,    94,    41,    96,    97,    98,
      99,   100,    41,    41,     3,    11,     5,     6,     3,    24,
       9,     6,     3,     7,     9,     6,    18,    19,    12,    13,
      14,    15,    16,    11,    10,   132,    12,    13,    14,    15,
      16,    30,    31,    32,    26,    30,    31,    32,    19,   146,
     147,     8,   149,    20,    21,    12,    13,    14,    15,    16,
       8,   150,   151,    18,    12,    13,    14,    15,    16,     8,
      33,    34,    35,     8,    13,    14,    15,    16,    13,    14,
      15,    16,    10,     3,    12,    13,    14,    15,    16,    10,
       3,    12,    13,    14,    15,    16,    36,    37,   187,    10,
     189,    12,    13,    14,    15,    16,    10,   204,    12,    13,
      14,    15,    16,    12,    13,    14,    15,    16,     3,   216,
     209,     6,   211,    10,   213,    12,    13,    14,    15,    16,
     227,    10,    25,    11,    13,    14,    15,    16,    10,    21,
      11,    13,    14,    15,    16,     3,    11,    10,     6,   238,
      13,    14,    15,    16,    10,     7,    20,    13,    14,    15,
      16,    10,     7,     7,    13,    14,    15,    16,    10,     7,
      11,    13,    14,    15,    16,    10,    22,    11,    13,    14,
      15,    16,    10,    40,    11,    13,    14,    15,    16,    12,
      13,     9,     8,    16,    10,     8,     8,    10,    10,     8,
       8,    10,    10,    40,    40,    11,    23,    40,     3,     3,
       9,     9,     9,     9,     3,    40,     9,     9,     9,    29,
       8,    11,     7,     3,    11,     9,    40,     3,     7,     3,
       7,     3,     7,    16,    16,     8,    40,     7,     9,     8,
       3,     9,     7,     9,     8,     3,     7,     9,     8,     8,
       3,     3,     8,     7,     3,    10,    23,     8,     8,     7,
       6,     8,     7,     7,     7,     7,   105,     8,     7,     7,
      10,     7,     9,     8,     7,     7,    10,   209,     7,    10,
      10,     8,   255,   138,    10,     9,    72,   160,   179,    -1,
      -1,    19,    -1,    -1,    -1,    18,    -1,    -1,    -1,    24
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Gspn_parser::yystos_[] =
  {
         0,    18,    19,    26,    45,    46,    47,    48,    49,    51,
      52,    11,    11,    27,    28,     0,    24,    57,    58,    48,
      20,    21,    50,    53,    55,    47,    52,    51,     3,     6,
       3,     6,     3,     3,    11,    25,    61,    80,    61,    50,
      11,    11,    55,    53,     7,     7,     7,     7,    11,    11,
      40,    11,    22,    71,    40,    40,     3,     6,     9,    30,
      31,    32,    43,     3,     5,     6,     9,    30,    31,    32,
      44,     9,    59,    60,    40,    11,    23,    74,     3,    54,
       3,    56,    43,     9,     9,     9,     7,    13,    14,    15,
      16,    44,     9,     9,     9,     7,    12,    13,    14,    15,
      16,     3,    41,    60,     9,    62,    63,    40,    11,    29,
      77,     8,    41,     8,    41,    10,    43,    43,    43,    43,
      43,    43,    43,    10,    44,    44,    44,    44,    44,    44,
      44,    44,     8,     7,     3,    41,    63,     9,    72,    73,
      40,    11,     3,     7,     3,     7,     8,     8,    10,    12,
       8,     8,    10,    43,     8,     7,     3,    41,    73,     9,
      75,    76,    40,    43,    43,    43,    44,    44,    10,     3,
      38,    39,    68,     8,     7,     3,    41,    76,     9,    78,
      79,    10,    10,    10,    10,    10,     7,     9,     8,     9,
       8,     3,     8,     7,     3,    41,    79,    44,    69,    70,
      44,    65,    44,    65,     8,    10,     3,     8,     7,     8,
      10,     8,    10,     8,    43,     7,     8,    10,     3,    70,
      44,    64,     8,    64,    10,    43,     7,     8,    10,    10,
      65,     8,    10,     7,    10,    43,     7,     7,     8,    36,
      37,    67,     7,     7,    10,    64,    10,     7,     8,     7,
      33,    34,    35,    66,     9,     8,    10,     3,     6,    67,
       7,    10,    10,    10,     7
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Gspn_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Gspn_parser::yyr1_[] =
  {
         0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      59,    59,    60,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    65,    66,    66,    66,    66,    67,    67,    68,
      69,    69,    70,    71,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Gspn_parser::yyr2_[] =
  {
         0,     2,     1,     1,     3,     3,     3,     3,     3,     4,
       6,     6,     6,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     4,     6,     6,     2,     3,     3,     2,     1,
       2,     2,     2,     6,     6,     2,     2,     4,     4,     4,
       4,     6,     1,     3,     6,     1,     3,     4,     5,     6,
       1,     2,     6,     6,     1,     2,    10,    12,    15,    17,
      10,     1,     1,     1,     1,     4,     4,     1,     1,     4,
       1,     3,     1,     6,     1,     2,     8,     6,     6,     1,
       2,     8,     6,     6,     1,     2,     8,     6,     1
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Gspn_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "str", "chr", "rval", "ival",
  "SEMICOLON", "COMMA", "LB", "RB", "EQ", "DIV", "MUL", "PLUS", "MINUS",
  "POWER", "GspnName", "NbPl", "NbTr", "PList", "TList", "in", "out",
  "marking", "transitions", "Const", "INT", "DOUBLE", "inhibitor", "MIN",
  "MAX", "FLOOR", "SINGLE", "INFINITE", "MULTIPLE", "ENABLINGMEMORY",
  "AGEMEMORY", "IMDT", "EXPO", "'{'", "'}'", "$accept", "IntStringFormula",
  "RealStringFormula", "GSPN", "declarations", "Constants", "Sizes",
  "Constant", "Lists", "NbPlaces", "NbTransitions", "PlacesList",
  "PLabels", "TransitionsList", "TLabels", "definitions", "PlacesDef",
  "PLACES", "PLACE", "TransitionsDef", "TRANSITIONS", "TRANSITION",
  "WEIGHT", "PRIORITY", "SERVICE", "MEMORY", "dist", "params", "param",
  "InArcs", "incells", "incell", "OutArcs", "outcells", "outcell",
  "Inhibitors", "inhibcells", "inhibcell", "redifinitions", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Gspn_parser::rhs_number_type
  Gspn_parser::yyrhs_[] =
  {
        45,     0,    -1,     6,    -1,     3,    -1,     9,    43,    10,
      -1,    43,    14,    43,    -1,    43,    15,    43,    -1,    43,
      13,    43,    -1,    43,    16,    43,    -1,    32,     9,    43,
      10,    -1,    32,     9,    43,    12,    43,    10,    -1,    30,
       9,    43,     8,    43,    10,    -1,    31,     9,    43,     8,
      43,    10,    -1,     5,    -1,     6,    -1,     3,    -1,     9,
      44,    10,    -1,    44,    12,    44,    -1,    44,    14,    44,
      -1,    44,    15,    44,    -1,    44,    13,    44,    -1,    44,
      16,    44,    -1,    32,     9,    44,    10,    -1,    30,     9,
      44,     8,    44,    10,    -1,    31,     9,    44,     8,    44,
      10,    -1,    46,    57,    -1,    46,    57,    80,    -1,    47,
      48,    50,    -1,    48,    50,    -1,    49,    -1,    49,    47,
      -1,    51,    52,    -1,    52,    51,    -1,    26,    27,     3,
      11,    43,     7,    -1,    26,    28,     3,    11,    44,     7,
      -1,    53,    55,    -1,    55,    53,    -1,    18,    11,     6,
       7,    -1,    18,    11,     3,     7,    -1,    19,    11,     6,
       7,    -1,    19,    11,     3,     7,    -1,    20,    11,    40,
      54,    41,     7,    -1,     3,    -1,    54,     8,     3,    -1,
      21,    11,    40,    56,    41,     7,    -1,     3,    -1,    56,
       8,     3,    -1,    58,    61,    71,    74,    -1,    58,    61,
      71,    74,    77,    -1,    24,    11,    40,    59,    41,     7,
      -1,    60,    -1,    59,    60,    -1,     9,     3,     8,    43,
      10,     7,    -1,    25,    11,    40,    62,    41,     7,    -1,
      63,    -1,    62,    63,    -1,     9,     3,     8,    68,     8,
      65,     8,    64,    10,     7,    -1,     9,     3,     8,    68,
       8,    65,     8,    64,     8,    67,    10,     7,    -1,     9,
       3,     8,    39,     9,    44,    10,     8,    65,     8,    64,
       8,    66,    10,     7,    -1,     9,     3,     8,    39,     9,
      44,    10,     8,    65,     8,    64,     8,    66,     8,    67,
      10,     7,    -1,     9,     3,     8,    38,     8,    65,     8,
      64,    10,     7,    -1,    44,    -1,    44,    -1,    33,    -1,
      34,    -1,    35,     9,     6,    10,    -1,    35,     9,     3,
      10,    -1,    37,    -1,    36,    -1,     3,     9,    69,    10,
      -1,    70,    -1,    69,     8,    70,    -1,    44,    -1,    22,
      11,    40,    72,    41,     7,    -1,    73,    -1,    72,    73,
      -1,     9,     3,     8,     3,     8,    43,    10,     7,    -1,
       9,     3,     8,     3,    10,     7,    -1,    23,    11,    40,
      75,    41,     7,    -1,    76,    -1,    75,    76,    -1,     9,
       3,     8,     3,     8,    43,    10,     7,    -1,     9,     3,
       8,     3,    10,     7,    -1,    29,    11,    40,    78,    41,
       7,    -1,    79,    -1,    78,    79,    -1,     9,     3,     8,
       3,     8,    43,    10,     7,    -1,     9,     3,     8,     3,
      10,     7,    -1,    61,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Gspn_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    11,    15,    19,    23,    27,
      32,    39,    46,    53,    55,    57,    59,    63,    67,    71,
      75,    79,    83,    88,    95,   102,   105,   109,   113,   116,
     118,   121,   124,   127,   134,   141,   144,   147,   152,   157,
     162,   167,   174,   176,   180,   187,   189,   193,   198,   204,
     211,   213,   216,   223,   230,   232,   235,   246,   259,   275,
     293,   304,   306,   308,   310,   312,   317,   322,   324,   326,
     331,   333,   337,   339,   346,   348,   351,   360,   367,   374,
     376,   379,   388,   395,   402,   404,   407,   416,   423
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Gspn_parser::yyrline_[] =
  {
         0,   126,   126,   127,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   149,   150,   151,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   173,   174,   176,   177,   181,
     182,   184,   185,   187,   194,   202,   203,   205,   208,   217,
     220,   229,   292,   298,   304,   312,   317,   324,   325,   327,
     329,   330,   332,   346,   356,   357,   359,   377,   396,   430,
     464,   487,   498,   510,   511,   512,   522,   536,   537,   540,
     711,   712,   716,   725,   727,   728,   730,   750,   765,   767,
     768,   770,   790,   806,   808,   809,   811,   832,   849
  };

  // Print the state stack on the debug stream.
  void
  Gspn_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Gspn_parser::yy_reduce_print_ (int yyrule)
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
  Gspn_parser::token_number_type
  Gspn_parser::yytranslate_ (int t)
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
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Gspn_parser::yyeof_ = 0;
  const int Gspn_parser::yylast_ = 339;
  const int Gspn_parser::yynnts_ = 39;
  const int Gspn_parser::yyempty_ = -2;
  const int Gspn_parser::yyfinal_ = 15;
  const int Gspn_parser::yyterror_ = 1;
  const int Gspn_parser::yyerrcode_ = 256;
  const int Gspn_parser::yyntokens_ = 42;

  const unsigned int Gspn_parser::yyuser_token_number_max_ = 294;
  const Gspn_parser::token_number_type Gspn_parser::yyundef_token_ = 2;


} // gspn
/* Line 1141 of lalr1.cc  */
#line 2236 "Gspn-parser.tab.cc"
/* Line 1142 of lalr1.cc  */
#line 851 "Gspn-parser.yy"


void
gspn::Gspn_parser::error (const gspn::Gspn_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}
