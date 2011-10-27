
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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


/* Line 311 of lalr1.cc  */
#line 43 "Gspn-parser.tab.cc"


#include "Gspn-parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 52 "Gspn-parser.tab.cc"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
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




/* Line 318 of lalr1.cc  */
#line 75 "Gspn-parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace gspn {

/* Line 380 of lalr1.cc  */
#line 144 "Gspn-parser.tab.cc"
#if YYERROR_VERBOSE

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

#endif

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
    switch (yytype)
      {
        case 3: /* "str" */

/* Line 449 of lalr1.cc  */
#line 105 "Gspn-parser.yy"
	{ debug_stream () << *(yyvaluep->name); };

/* Line 449 of lalr1.cc  */
#line 221 "Gspn-parser.tab.cc"
	break;
      case 5: /* "rval" */

/* Line 449 of lalr1.cc  */
#line 109 "Gspn-parser.yy"
	{ debug_stream () << (yyvaluep->RealVal); };

/* Line 449 of lalr1.cc  */
#line 230 "Gspn-parser.tab.cc"
	break;
      case 6: /* "ival" */

/* Line 449 of lalr1.cc  */
#line 108 "Gspn-parser.yy"
	{ debug_stream () << (yyvaluep->IntVal); };

/* Line 449 of lalr1.cc  */
#line 239 "Gspn-parser.tab.cc"
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

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 3: /* "str" */

/* Line 480 of lalr1.cc  */
#line 106 "Gspn-parser.yy"
	{ delete (yyvaluep->name); };

/* Line 480 of lalr1.cc  */
#line 278 "Gspn-parser.tab.cc"
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

  int
  Gspn_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

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
    if (yyn == yypact_ninf_)
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
	if (yyn == 0 || yyn == yytable_ninf_)
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

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 121 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 122 "Gspn-parser.yy"
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

/* Line 678 of lalr1.cc  */
#line 133 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 134 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 135 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 136 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 137 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 138 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 139 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 140 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 141 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 144 "Gspn-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 145 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 146 "Gspn-parser.yy"
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

/* Line 678 of lalr1.cc  */
#line 156 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 157 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 158 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 159 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 160 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 161 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 162 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 163 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 164 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 183 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.IntConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.IntResult;Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 190 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 200 "Gspn-parser.yy"
    {Reader.MyGspn.pl=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 203 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
						Reader.MyGspn.pl=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                    
}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 212 "Gspn-parser.yy"
    {Reader.MyGspn.tr=(yysemantic_stack_[(4) - (3)].IntVal);
                                        //std::cout<<"nbTransitions="<<$3<<std::endl;
}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 215 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
					  Reader.MyGspn.tr=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                      
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 224 "Gspn-parser.yy"
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
                           
                                                   


}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 285 "Gspn-parser.yy"
    {
                //std::cout<<*$1<<",";
                Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(1) - (1)].name));
                int sz=Reader.MyGspn.PlacesId.size();
                Reader.MyGspn.PlacesId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 291 "Gspn-parser.yy"
    {Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.PlacesId.size();
                            Reader.MyGspn.PlacesId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                           //std::cout<<*$3<<",";
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 297 "Gspn-parser.yy"
    {
						      if(Reader.MyGspn.TransId.size()!=Reader.MyGspn.tr){
						      std::cout<<"Transition label missing or redeclared, please check your transitions list"<<std::endl;
						      YYABORT;
						    }
                                                 
                                                    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 305 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(1) - (1)].name));
               int sz=Reader.MyGspn.TransId.size();
               Reader.MyGspn.TransId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
               
                }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 310 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.TransId.size();
                            Reader.MyGspn.TransId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                           
                            }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 320 "Gspn-parser.yy"
    {}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 326 "Gspn-parser.yy"
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

/* Line 678 of lalr1.cc  */
#line 339 "Gspn-parser.yy"
    {
				  for(int i=0; i<Reader.MyGspn.Priority.size();i++){
					  if(Reader.MyGspn.Priority[i]=="")
							  {cout<<"Some transitions were not defined. All declared transitions must be defined"<<endl;
								YYABORT;
								  
							}
}
  }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 349 "Gspn-parser.yy"
    {}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 350 "Gspn-parser.yy"
    {}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 352 "Gspn-parser.yy"
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
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=1;
                        }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 369 "Gspn-parser.yy"
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
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(15) - (2)].name)]]=NbServers;
						MarkingDependent=false;
						}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 401 "Gspn-parser.yy"
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
						Reader.MyGspn.NbServers[Reader.MyGspn.TransId[*(yysemantic_stack_[(10) - (2)].name)]]=1;						
						
                        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 422 "Gspn-parser.yy"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 433 "Gspn-parser.yy"
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

  case 61:

/* Line 678 of lalr1.cc  */
#line 444 "Gspn-parser.yy"
    {SingleService=true; NbServers=1;}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 445 "Gspn-parser.yy"
    {SingleService=false;NbServers=INT_MAX;}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 446 "Gspn-parser.yy"
    {NbServers= (yysemantic_stack_[(4) - (3)].IntVal);
					  if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
					  

}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 456 "Gspn-parser.yy"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 471 "Gspn-parser.yy"
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

        default: cout << "\nUnknown distribution !" << endl;
            YYABORT;

    }
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 600 "Gspn-parser.yy"
    {string st=(yysemantic_stack_[(1) - (1)].expression);
				 if(Evaluate.parse(st)) 
					{cout<<"The exponential ditribution is the only marking dependent distribution: '"<<st<<"'"<<endl;YYABORT; }
				 else{std::ostringstream s;s<<Evaluate.RealResult;
				 Par.push_back(s.str());
					} 
				}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 609 "Gspn-parser.yy"
    {}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 611 "Gspn-parser.yy"
    {}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 612 "Gspn-parser.yy"
    {}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 614 "Gspn-parser.yy"
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

  case 73:

/* Line 678 of lalr1.cc  */
#line 634 "Gspn-parser.yy"
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 649 "Gspn-parser.yy"
    {}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 651 "Gspn-parser.yy"
    {}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 652 "Gspn-parser.yy"
    {}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 654 "Gspn-parser.yy"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 674 "Gspn-parser.yy"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 690 "Gspn-parser.yy"
    {}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 692 "Gspn-parser.yy"
    {}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 693 "Gspn-parser.yy"
    {}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 695 "Gspn-parser.yy"
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
						  cout<<st<<endl;			 
						  }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 716 "Gspn-parser.yy"
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



/* Line 678 of lalr1.cc  */
#line 1402 "Gspn-parser.tab.cc"
	default:
          break;
      }
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
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
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
	if (yyn != yypact_ninf_)
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

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Gspn_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Gspn_parser::yypact_ninf_ = -200;
  const short int
  Gspn_parser::yypact_[] =
  {
        46,    -2,     4,    92,     6,    30,   220,   174,    32,    10,
      43,    85,    94,    71,    95,  -200,    72,    41,    41,   174,
      99,   144,  -200,   106,   152,  -200,  -200,  -200,   154,   172,
     194,   195,   198,   205,   170,   212,  -200,  -200,   193,  -200,
     184,   191,  -200,  -200,  -200,  -200,  -200,  -200,    54,    50,
     221,   202,   225,   219,   238,   240,  -200,  -200,    54,   235,
     236,   237,    80,  -200,  -200,  -200,    50,   239,   241,   242,
      55,   244,     1,  -200,   243,   215,   245,   226,  -200,    -5,
    -200,     0,    63,    54,    54,    54,  -200,    54,    54,    54,
      54,   116,    50,    50,    50,  -200,    50,    50,    50,    50,
      50,   246,   250,  -200,   255,     2,  -200,   251,   223,   248,
    -200,   259,   256,   261,   258,  -200,     5,   109,   129,   233,
      -9,    -9,  -200,  -200,    91,   100,   136,   252,   252,   141,
     141,  -200,    54,  -200,   262,   260,  -200,   263,     3,  -200,
     264,   231,  -200,  -200,  -200,  -200,    54,    54,  -200,    54,
      50,    50,  -200,   176,    -1,  -200,   266,   265,  -200,   268,
       7,  -200,   267,   183,   190,   197,   153,   161,   270,   269,
     271,   272,   274,   277,  -200,   275,   278,  -200,   281,    13,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,    50,    50,    50,
      50,   101,   283,  -200,   279,   282,  -200,   121,   148,  -200,
     121,   280,   168,   284,    54,   286,   177,   287,  -200,    50,
    -200,    50,   288,    50,   204,  -200,    54,   290,   227,  -200,
     121,   285,    50,   289,   291,   211,  -200,    54,   293,   294,
     295,   297,  -200,   298,   218,  -200,  -200,    50,  -200,  -200,
     299,   300,  -200,   -10,  -200,  -200,   301,   292,   115,   302,
     303,   304,  -200,  -200,  -200
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Gspn_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     1,     0,    25,     0,     0,
       0,     0,    28,     0,     0,    30,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    26,     0,    27,
       0,     0,    35,    36,    38,    37,    40,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     2,     0,     0,
       0,     0,     0,    15,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,    47,    42,     0,
      45,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    54,     0,     0,     0,
      48,     0,     0,     0,     0,     4,     0,     0,     0,     7,
       5,     6,     8,    16,     0,     0,     0,    17,    20,    18,
      19,    21,     0,    49,     0,     0,    55,     0,     0,    70,
       0,     0,    43,    41,    46,    44,     0,     0,     9,     0,
       0,     0,    22,     0,     0,    53,     0,     0,    71,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    76,     0,     0,
      80,    11,    12,    10,    23,    24,    52,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    81,    68,     0,    66,
      60,     0,     0,     0,     0,     0,     0,     0,    79,     0,
      65,     0,     0,     0,     0,    73,     0,     0,     0,    67,
      59,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,    72,     0,     0,    83,    58,     0,    56,    77,
       0,     0,    82,     0,    61,    62,     0,     0,     0,     0,
       0,     0,    57,    64,    63
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yypgoto_[] =
  {
      -200,   -57,   -49,  -200,  -200,   307,   305,  -200,   306,   308,
     310,   296,  -200,   309,  -200,  -200,  -200,  -200,   203,   273,
    -200,   189,  -199,  -185,  -200,  -200,  -200,    98,  -200,  -200,
     178,  -200,  -200,   157,  -200,  -200,   133,  -200
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yydefgoto_[] =
  {
        -1,    62,   200,     4,     5,     6,     7,     8,    22,     9,
      10,    23,    79,    24,    81,    17,    18,    72,    73,    36,
     105,   106,   221,   201,   247,   172,   198,   199,    53,   138,
     139,    77,   160,   161,   110,   179,   180,    37
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Gspn_parser::yytable_ninf_ = -1;
  const unsigned char
  Gspn_parser::yytable_[] =
  {
        70,    82,   169,   111,    87,   203,    15,    90,   113,    11,
      71,   104,   137,   146,   223,    12,   159,    91,    87,    88,
      89,    90,   178,   244,   245,   246,   116,   117,   118,     2,
     119,   120,   121,   122,   112,   170,   171,   230,   241,   114,
     102,   135,   157,   124,   125,   126,   176,   127,   128,   129,
     130,   131,   195,    63,    16,    64,    65,    56,     3,    66,
      57,     1,    95,    58,     1,     2,    35,    96,    97,    98,
      99,   100,     3,   115,    32,   153,    87,    88,    89,    90,
      67,    68,    69,    34,    59,    60,    61,    86,    28,   163,
     164,    29,   165,    87,    88,    89,    90,    30,    33,   150,
      31,   166,   167,    96,    97,    98,    99,   100,   151,   204,
      40,   205,    96,    97,    98,    99,   100,   147,   250,    13,
      14,   251,    87,    88,    89,    90,   123,    21,    96,    97,
      98,    99,   100,    96,    97,    98,    99,   100,   197,   148,
     202,   149,    87,    88,    89,    90,   152,   214,    96,    97,
      98,    99,   100,    96,    97,    41,   209,   100,   210,   225,
     197,    44,   220,   184,   220,    96,    97,    98,    99,   100,
     234,   185,    20,    96,    97,    98,    99,   100,   212,    45,
      96,    97,    98,    99,   100,   216,   168,   217,   220,    87,
      88,    89,    90,   181,    20,    21,    87,    88,    89,    90,
     182,    46,    47,    87,    88,    89,    90,   183,    50,    48,
      87,    88,    89,    90,   224,    52,    49,    87,    88,    89,
      90,   233,    54,    51,    87,    88,    89,    90,   240,    55,
      71,    87,    88,    89,    90,   227,    75,   228,     1,     2,
      74,    78,    76,    80,    83,    84,    85,   101,    92,    90,
      93,    94,   104,   107,   132,   109,   108,   133,   134,   141,
     137,   140,   142,   143,   144,   145,   156,   155,   100,   162,
     154,   175,   174,   159,   173,   103,   178,   186,   187,   188,
     191,   189,   190,   192,   194,   193,   206,   207,   211,   208,
     218,    38,   213,   215,   136,   229,   222,   226,   232,   231,
     235,   236,   249,   237,   238,   239,   242,   219,   243,   252,
     248,    19,   196,   253,   254,    25,   158,   177,    27,    26,
      43,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,    42
  };

  /* YYCHECK.  */
  const short int
  Gspn_parser::yycheck_[] =
  {
        49,    58,     3,     8,    13,   190,     0,    16,     8,    11,
       9,     9,     9,     8,   213,    11,     9,    66,    13,    14,
      15,    16,     9,    33,    34,    35,    83,    84,    85,    19,
      87,    88,    89,    90,    39,    36,    37,   222,   237,    39,
      39,    39,    39,    92,    93,    94,    39,    96,    97,    98,
      99,   100,    39,     3,    24,     5,     6,     3,    26,     9,
       6,    18,     7,     9,    18,    19,    25,    12,    13,    14,
      15,    16,    26,    10,     3,   132,    13,    14,    15,    16,
      30,    31,    32,    11,    30,    31,    32,     7,     3,   146,
     147,     6,   149,    13,    14,    15,    16,     3,     3,     8,
       6,   150,   151,    12,    13,    14,    15,    16,     8,     8,
      11,    10,    12,    13,    14,    15,    16,     8,     3,    27,
      28,     6,    13,    14,    15,    16,    10,    21,    12,    13,
      14,    15,    16,    12,    13,    14,    15,    16,   187,    10,
     189,    12,    13,    14,    15,    16,    10,   204,    12,    13,
      14,    15,    16,    12,    13,    11,     8,    16,    10,   216,
     209,     7,   211,    10,   213,    12,    13,    14,    15,    16,
     227,    10,    20,    12,    13,    14,    15,    16,    10,     7,
      12,    13,    14,    15,    16,     8,    10,    10,   237,    13,
      14,    15,    16,    10,    20,    21,    13,    14,    15,    16,
      10,     7,     7,    13,    14,    15,    16,    10,    38,    11,
      13,    14,    15,    16,    10,    22,    11,    13,    14,    15,
      16,    10,    38,    11,    13,    14,    15,    16,    10,    38,
       9,    13,    14,    15,    16,     8,    11,    10,    18,    19,
      38,     3,    23,     3,     9,     9,     9,     3,     9,    16,
       9,     9,     9,    38,     8,    29,    11,     7,     3,    11,
       9,    38,     3,     7,     3,     7,     3,     7,    16,    38,
       8,     3,     7,     9,     8,    72,     9,     7,     9,     8,
       3,     9,     8,     8,     3,     7,     3,     8,     8,     7,
       3,    18,     8,     7,   105,    10,     8,     7,     7,    10,
       7,     7,    10,     8,     7,     7,     7,   209,     8,     7,
       9,     6,   179,    10,    10,     8,   138,   160,    10,     9,
      24,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    23
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Gspn_parser::yystos_[] =
  {
         0,    18,    19,    26,    43,    44,    45,    46,    47,    49,
      50,    11,    11,    27,    28,     0,    24,    55,    56,    46,
      20,    21,    48,    51,    53,    45,    50,    49,     3,     6,
       3,     6,     3,     3,    11,    25,    59,    77,    59,    48,
      11,    11,    53,    51,     7,     7,     7,     7,    11,    11,
      38,    11,    22,    68,    38,    38,     3,     6,     9,    30,
      31,    32,    41,     3,     5,     6,     9,    30,    31,    32,
      42,     9,    57,    58,    38,    11,    23,    71,     3,    52,
       3,    54,    41,     9,     9,     9,     7,    13,    14,    15,
      16,    42,     9,     9,     9,     7,    12,    13,    14,    15,
      16,     3,    39,    58,     9,    60,    61,    38,    11,    29,
      74,     8,    39,     8,    39,    10,    41,    41,    41,    41,
      41,    41,    41,    10,    42,    42,    42,    42,    42,    42,
      42,    42,     8,     7,     3,    39,    61,     9,    69,    70,
      38,    11,     3,     7,     3,     7,     8,     8,    10,    12,
       8,     8,    10,    41,     8,     7,     3,    39,    70,     9,
      72,    73,    38,    41,    41,    41,    42,    42,    10,     3,
      36,    37,    65,     8,     7,     3,    39,    73,     9,    75,
      76,    10,    10,    10,    10,    10,     7,     9,     8,     9,
       8,     3,     8,     7,     3,    39,    76,    42,    66,    67,
      42,    63,    42,    63,     8,    10,     3,     8,     7,     8,
      10,     8,    10,     8,    41,     7,     8,    10,     3,    67,
      42,    62,     8,    62,    10,    41,     7,     8,    10,    10,
      63,    10,     7,    10,    41,     7,     7,     8,     7,     7,
      10,    62,     7,     8,    33,    34,    35,    64,     9,    10,
       3,     6,     7,    10,    10
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
     285,   286,   287,   288,   289,   290,   291,   292,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Gspn_parser::yyr1_[] =
  {
         0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    54,    54,    55,    55,    56,
      57,    57,    58,    59,    60,    60,    61,    61,    61,    62,
      63,    64,    64,    64,    64,    65,    66,    66,    67,    68,
      69,    69,    70,    70,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77
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
       1,     2,     6,     6,     1,     2,    10,    15,    10,     1,
       1,     1,     1,     4,     4,     4,     1,     3,     1,     6,
       1,     2,     8,     6,     6,     1,     2,     8,     6,     6,
       1,     2,     8,     6,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Gspn_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "str", "chr", "rval", "ival",
  "SEMICOLON", "COMMA", "LB", "RB", "EQ", "DIV", "MUL", "PLUS", "MINUS",
  "POWER", "GspnName", "NbPl", "NbTr", "PList", "TList", "in", "out",
  "marking", "transitions", "Const", "INT", "DOUBLE", "inhibitor", "MIN",
  "MAX", "FLOOR", "SINGLE", "INFINITE", "MULTIPLE", "IMDT", "EXPO", "'{'",
  "'}'", "$accept", "IntStringFormula", "RealStringFormula", "GSPN",
  "declarations", "Constants", "Sizes", "Constant", "Lists", "NbPlaces",
  "NbTransitions", "PlacesList", "PLabels", "TransitionsList", "TLabels",
  "definitions", "PlacesDef", "PLACES", "PLACE", "TransitionsDef",
  "TRANSITIONS", "TRANSITION", "WEIGHT", "PRIORITY", "SERVICE", "dist",
  "params", "param", "InArcs", "incells", "incell", "OutArcs", "outcells",
  "outcell", "Inhibitors", "inhibcells", "inhibcell", "redifinitions", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Gspn_parser::rhs_number_type
  Gspn_parser::yyrhs_[] =
  {
        43,     0,    -1,     6,    -1,     3,    -1,     9,    41,    10,
      -1,    41,    14,    41,    -1,    41,    15,    41,    -1,    41,
      13,    41,    -1,    41,    16,    41,    -1,    32,     9,    41,
      10,    -1,    32,     9,    41,    12,    41,    10,    -1,    30,
       9,    41,     8,    41,    10,    -1,    31,     9,    41,     8,
      41,    10,    -1,     5,    -1,     6,    -1,     3,    -1,     9,
      42,    10,    -1,    42,    12,    42,    -1,    42,    14,    42,
      -1,    42,    15,    42,    -1,    42,    13,    42,    -1,    42,
      16,    42,    -1,    32,     9,    42,    10,    -1,    30,     9,
      42,     8,    42,    10,    -1,    31,     9,    42,     8,    42,
      10,    -1,    44,    55,    -1,    44,    55,    77,    -1,    45,
      46,    48,    -1,    46,    48,    -1,    47,    -1,    47,    45,
      -1,    49,    50,    -1,    50,    49,    -1,    26,    27,     3,
      11,    41,     7,    -1,    26,    28,     3,    11,    42,     7,
      -1,    51,    53,    -1,    53,    51,    -1,    18,    11,     6,
       7,    -1,    18,    11,     3,     7,    -1,    19,    11,     6,
       7,    -1,    19,    11,     3,     7,    -1,    20,    11,    38,
      52,    39,     7,    -1,     3,    -1,    52,     8,     3,    -1,
      21,    11,    38,    54,    39,     7,    -1,     3,    -1,    54,
       8,     3,    -1,    56,    59,    68,    71,    -1,    56,    59,
      68,    71,    74,    -1,    24,    11,    38,    57,    39,     7,
      -1,    58,    -1,    57,    58,    -1,     9,     3,     8,    41,
      10,     7,    -1,    25,    11,    38,    60,    39,     7,    -1,
      61,    -1,    60,    61,    -1,     9,     3,     8,    65,     8,
      63,     8,    62,    10,     7,    -1,     9,     3,     8,    37,
       9,    42,    10,     8,    63,     8,    62,     8,    64,    10,
       7,    -1,     9,     3,     8,    36,     8,    63,     8,    62,
      10,     7,    -1,    42,    -1,    42,    -1,    33,    -1,    34,
      -1,    35,     9,     6,    10,    -1,    35,     9,     3,    10,
      -1,     3,     9,    66,    10,    -1,    67,    -1,    66,     8,
      67,    -1,    42,    -1,    22,    11,    38,    69,    39,     7,
      -1,    70,    -1,    69,    70,    -1,     9,     3,     8,     3,
       8,    41,    10,     7,    -1,     9,     3,     8,     3,    10,
       7,    -1,    23,    11,    38,    72,    39,     7,    -1,    73,
      -1,    72,    73,    -1,     9,     3,     8,     3,     8,    41,
      10,     7,    -1,     9,     3,     8,     3,    10,     7,    -1,
      29,    11,    38,    75,    39,     7,    -1,    76,    -1,    75,
      76,    -1,     9,     3,     8,     3,     8,    41,    10,     7,
      -1,     9,     3,     8,     3,    10,     7,    -1,    59,    -1
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
     211,   213,   216,   223,   230,   232,   235,   246,   262,   273,
     275,   277,   279,   281,   286,   291,   296,   298,   302,   304,
     311,   313,   316,   325,   332,   339,   341,   344,   353,   360,
     367,   369,   372,   381,   388
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Gspn_parser::yyrline_[] =
  {
         0,   121,   121,   122,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   144,   145,   146,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   168,   169,   171,   172,   176,
     177,   179,   180,   182,   189,   197,   198,   200,   203,   212,
     215,   224,   285,   291,   297,   305,   310,   317,   318,   320,
     322,   323,   325,   339,   349,   350,   352,   369,   401,   421,
     432,   444,   445,   446,   456,   471,   595,   596,   600,   609,
     611,   612,   614,   634,   649,   651,   652,   654,   674,   690,
     692,   693,   695,   716,   733
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
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      35,    36,    37
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Gspn_parser::yyeof_ = 0;
  const int Gspn_parser::yylast_ = 332;
  const int Gspn_parser::yynnts_ = 38;
  const int Gspn_parser::yyempty_ = -2;
  const int Gspn_parser::yyfinal_ = 15;
  const int Gspn_parser::yyterror_ = 1;
  const int Gspn_parser::yyerrcode_ = 256;
  const int Gspn_parser::yyntokens_ = 40;

  const unsigned int Gspn_parser::yyuser_token_number_max_ = 292;
  const Gspn_parser::token_number_type Gspn_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // gspn

/* Line 1054 of lalr1.cc  */
#line 2043 "Gspn-parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 735 "Gspn-parser.yy"


void
gspn::Gspn_parser::error (const gspn::Gspn_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}

