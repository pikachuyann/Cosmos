/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
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
#line 42 "Gspn-parser.tab.cc"


#include "Gspn-parser.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 51 "Gspn-parser.tab.cc"
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
bool AgeMemory;




/* Line 318 of lalr1.cc  */
#line 75 "Gspn-parser.tab.cc"

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


namespace gspn {

/* Line 380 of lalr1.cc  */
#line 141 "Gspn-parser.tab.cc"
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
#line 111 "Gspn-parser.yy"
	{ debug_stream () << *(yyvaluep->name); };

/* Line 449 of lalr1.cc  */
#line 218 "Gspn-parser.tab.cc"
	break;
      case 5: /* "rval" */

/* Line 449 of lalr1.cc  */
#line 115 "Gspn-parser.yy"
	{ debug_stream () << (yyvaluep->RealVal); };

/* Line 449 of lalr1.cc  */
#line 227 "Gspn-parser.tab.cc"
	break;
      case 6: /* "ival" */

/* Line 449 of lalr1.cc  */
#line 114 "Gspn-parser.yy"
	{ debug_stream () << (yyvaluep->IntVal); };

/* Line 449 of lalr1.cc  */
#line 236 "Gspn-parser.tab.cc"
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
#line 112 "Gspn-parser.yy"
	{ delete (yyvaluep->name); };

/* Line 480 of lalr1.cc  */
#line 275 "Gspn-parser.tab.cc"
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
    location_type yyerror_range[3];

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
#line 127 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 128 "Gspn-parser.yy"
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
#line 139 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 140 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 141 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 142 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 143 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 144 "Gspn-parser.yy"
    {sprintf((yyval.expression),"fabs( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 145 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 146 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s /double(%s)", (yysemantic_stack_[(6) - (3)].expression),(yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 147 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 148 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 151 "Gspn-parser.yy"
    {sprintf((yyval.expression), "%f",(yysemantic_stack_[(1) - (1)].RealVal));}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 152 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%d",(yysemantic_stack_[(1) - (1)].IntVal));}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 153 "Gspn-parser.yy"
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

  case 17:

/* Line 678 of lalr1.cc  */
#line 163 "Gspn-parser.yy"
    {sprintf((yyval.expression),"( %s )", (yysemantic_stack_[(3) - (2)].expression));       }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 164 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s /double(%s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 165 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s + %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 166 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s - %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 167 "Gspn-parser.yy"
    {sprintf((yyval.expression),"%s * %s", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 168 "Gspn-parser.yy"
    {sprintf((yyval.expression),"pow(%s , %s)", (yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));  }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 169 "Gspn-parser.yy"
    {sprintf((yyval.expression),"fabs( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 170 "Gspn-parser.yy"
    {sprintf((yyval.expression),"floor( %s )", (yysemantic_stack_[(4) - (3)].expression));  }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 171 "Gspn-parser.yy"
    {sprintf((yyval.expression),"min(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 172 "Gspn-parser.yy"
    {sprintf((yyval.expression),"max(%s , %s)", (yysemantic_stack_[(6) - (3)].expression), (yysemantic_stack_[(6) - (5)].expression));  }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 191 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.IntConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.IntResult;Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 198 "Gspn-parser.yy"
    {if(Reader.MyGspn.RealConstant.find(*(yysemantic_stack_[(6) - (3)].name))!=Reader.MyGspn.RealConstant.end()) 
							{cout<<"Constant "<<*(yysemantic_stack_[(6) - (3)].name)<<" already defined."<<endl; YYABORT;}
					    else {string st=(yysemantic_stack_[(6) - (5)].expression);
							  Evaluate.parse(st);
							  Reader.MyGspn.RealConstant[*(yysemantic_stack_[(6) - (3)].name)]=Evaluate.RealResult;}
						}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 208 "Gspn-parser.yy"
    {Reader.MyGspn.pl=(yysemantic_stack_[(4) - (3)].IntVal);
                                    
}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 211 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
						Reader.MyGspn.pl=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                    
}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 220 "Gspn-parser.yy"
    {Reader.MyGspn.tr=(yysemantic_stack_[(4) - (3)].IntVal);
                                       
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 223 "Gspn-parser.yy"
    {if(Reader.MyGspn.IntConstant.find(*(yysemantic_stack_[(4) - (3)].name))==Reader.MyGspn.IntConstant.end())
					    {
					    std::cout<<*(yysemantic_stack_[(4) - (3)].name)<<" was not declared"<<std::endl;
					    YYABORT;
					    }
					  Reader.MyGspn.tr=Reader.MyGspn.IntConstant[*(yysemantic_stack_[(4) - (3)].name)];
                                      
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 232 "Gspn-parser.yy"
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

  case 44:

/* Line 678 of lalr1.cc  */
#line 295 "Gspn-parser.yy"
    {
              
                Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(1) - (1)].name));
                int sz=Reader.MyGspn.PlacesId.size();
                Reader.MyGspn.PlacesId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 301 "Gspn-parser.yy"
    {Reader.MyGspn.PlacesList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.PlacesId.size();
                            Reader.MyGspn.PlacesId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                         
}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 307 "Gspn-parser.yy"
    {
						      if(Reader.MyGspn.TransId.size()!=Reader.MyGspn.tr){
						      std::cout<<"Transition label missing or redeclared, please check your transitions list"<<std::endl;
						      YYABORT;
						    }
                                                 
                                                    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 315 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(1) - (1)].name));
               int sz=Reader.MyGspn.TransId.size();
               Reader.MyGspn.TransId[*(yysemantic_stack_[(1) - (1)].name)]=sz;
               
                }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 320 "Gspn-parser.yy"
    {Reader.MyGspn.TransList.insert(*(yysemantic_stack_[(3) - (3)].name));
                            int sz=Reader.MyGspn.TransId.size();
                            Reader.MyGspn.TransId[*(yysemantic_stack_[(3) - (3)].name)]=sz;
                           
                            }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 330 "Gspn-parser.yy"
    {}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 336 "Gspn-parser.yy"
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

  case 55:

/* Line 678 of lalr1.cc  */
#line 349 "Gspn-parser.yy"
    {
				  for(int i=0; i<Reader.MyGspn.Priority.size();i++){
					  if(Reader.MyGspn.Priority[i]=="")
							  {cout<<"Some transitions were not defined. All declared transitions must be defined"<<endl;
								YYABORT;
								  
							}
}
  }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 359 "Gspn-parser.yy"
    {}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 360 "Gspn-parser.yy"
    {}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 362 "Gspn-parser.yy"
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

  case 59:

/* Line 678 of lalr1.cc  */
#line 380 "Gspn-parser.yy"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 399 "Gspn-parser.yy"
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
							  cout << "In exponential distribution Lambda > 0" << endl;
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

  case 61:

/* Line 678 of lalr1.cc  */
#line 433 "Gspn-parser.yy"
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
							  cout << "In exponential distribution Lambda > 0" << endl;
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

  case 62:

/* Line 678 of lalr1.cc  */
#line 467 "Gspn-parser.yy"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 491 "Gspn-parser.yy"
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

  case 64:

/* Line 678 of lalr1.cc  */
#line 502 "Gspn-parser.yy"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 513 "Gspn-parser.yy"
    {SingleService=true; NbServers=1;}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 514 "Gspn-parser.yy"
    {SingleService=false;NbServers=INT_MAX;}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 515 "Gspn-parser.yy"
    {NbServers= (yysemantic_stack_[(4) - (3)].IntVal);
					  if(NbServers<1) 
					  { cout<<"Number of servers should be at least one"<<endl;
						YYABORT;
					  }
					  if(NbServers==1) SingleService=true;
					  else {SingleService=false;}
					  

}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 525 "Gspn-parser.yy"
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 539 "Gspn-parser.yy"
    {AgeMemory=true;}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 540 "Gspn-parser.yy"
    {AgeMemory=false;}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 543 "Gspn-parser.yy"
    {
		distrib=*(yysemantic_stack_[(4) - (1)].name);
		int np=Par.size();

		switch (Reader.IndexDist[distrib]) {
        case 1:
		{
            if (np != 2){
                cout << "Uniform distribution has two parameters: min and max where 0<=min<max" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1>=p2) || (p1<0)) {
               cout << "In uniform distribution 0 <= min< max " << endl;
               YYABORT;
            }
	   break;
	  }

        case 2:
		{ 
            if (np != 1) {
                cout << "Exponential distribution has one parameter: Lambda > 0" << endl;
                YYABORT;
            } 
                
			double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<= 0 ) {
               cout << "In exponential distribution Lambda > 0" << endl;
               YYABORT;
            }
	    break;
	  }
                    
        case 3:
		{
            if (np != 1) {
                cout << "Deterministic distribution has one parameter:  T >= 0" << endl;
                YYABORT;
            }
            
            double p1;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;			
            if (p1<0 ) {
               cout << "In Deterministic distribution T > 0" << endl;
               YYABORT;
            } 
	    break;
	  }
            
        case 4:
		{
            if (np != 2) {
                cout << "Lognormal distribution has two parameters: mu and sigma^2, with sigma^2 > 0" << endl;
                YYABORT;
            }
            
            double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if (p2<=0) {
               cout << "In Lognormal distribution sigma^2 > 0" << endl;
               YYABORT;
            }
			double x;	      
			stringstream os;
			x=sqrt(p2);
			os << x;	    
			Par[1]=os.str();
            break;
	  }

        case 5:
		{
            if (np != 3) {
                cout << "Triangle distribution has three parameters: 0 <= b <= c <= a" << endl;
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
               cout << "In Triangle distribution: 0 <= b <= c<= a" << endl;
               YYABORT;
            }

          
	    break;
	  }

	  case 6:
		{
            if (np != 2) {
                cout << "Geometric distribution has two parameters: 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
                YYABORT;
            }
			double p1,p2;
			string st=Par[0];
			Evaluate.parse(st);p1=Evaluate.RealResult;
			st=Par[1];
			Evaluate.parse(st);p2=Evaluate.RealResult;
            if ((p1<0) || (p1>1) || p2<=0) {
               cout << "In Geometric distribution 0 <= p <= 1 (probability of success) and T > 0 (duration of one step)" << endl;
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 723 "Gspn-parser.yy"
    {string st=(yysemantic_stack_[(1) - (1)].expression);
				 if(Evaluate.parse(st)) 
					{cout<<"The exponential distribution is the only marking dependent distribution: '"<<st<<"'"<<endl;YYABORT; }
				 else{std::ostringstream s;s<<Evaluate.RealResult;
				 Par.push_back(s.str());
					} 
				}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 732 "Gspn-parser.yy"
    {}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 734 "Gspn-parser.yy"
    {}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 735 "Gspn-parser.yy"
    {}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 737 "Gspn-parser.yy"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 757 "Gspn-parser.yy"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 772 "Gspn-parser.yy"
    {}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 774 "Gspn-parser.yy"
    {}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 775 "Gspn-parser.yy"
    {}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 777 "Gspn-parser.yy"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 797 "Gspn-parser.yy"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 813 "Gspn-parser.yy"
    {}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 815 "Gspn-parser.yy"
    {}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 816 "Gspn-parser.yy"
    {}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 818 "Gspn-parser.yy"
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

  case 89:

/* Line 678 of lalr1.cc  */
#line 839 "Gspn-parser.yy"
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
#line 1548 "Gspn-parser.tab.cc"
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
  const short int Gspn_parser::yypact_ninf_ = -215;
  const short int
  Gspn_parser::yypact_[] =
  {
        47,     4,    30,    72,    93,    34,    56,    62,    81,   101,
     127,    10,   158,   124,   131,  -215,   182,   155,   155,    62,
     193,   200,  -215,   148,   183,  -215,  -215,  -215,   203,   210,
     211,   217,   214,   221,   190,   228,  -215,  -215,   216,  -215,
     204,   205,  -215,  -215,  -215,  -215,  -215,  -215,    58,    54,
     250,   219,   251,   238,   260,   261,  -215,  -215,    58,   256,
     257,   258,   259,    55,  -215,  -215,  -215,    54,   262,   263,
     264,   265,     7,   266,     0,  -215,   267,   229,   268,   246,
    -215,    -5,  -215,    -2,   176,    58,    58,    58,    58,  -215,
      58,    58,    58,    58,   109,    54,    54,    54,    54,  -215,
      54,    54,    54,    54,    54,   269,   271,  -215,   277,     1,
    -215,   272,   241,   273,  -215,   280,   278,   283,   281,  -215,
      98,   102,   116,   185,   274,   149,   149,  -215,  -215,    64,
      89,   123,   137,   275,   275,    -8,    -8,  -215,    58,  -215,
     279,   282,  -215,   289,     2,  -215,   284,   253,  -215,  -215,
    -215,  -215,    58,    58,  -215,    58,  -215,    54,    54,  -215,
    -215,   192,    -1,  -215,   287,   290,  -215,   293,     3,  -215,
     291,   199,   206,   213,   144,   161,   292,   294,   296,   297,
     299,   295,  -215,   300,   298,  -215,   306,     8,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,    54,    54,    54,    54,    84,
     307,  -215,   303,   305,  -215,   128,   186,  -215,   128,   308,
     169,   309,    58,   311,   243,   310,  -215,    54,  -215,    54,
     312,    54,   220,  -215,    58,   314,   244,  -215,   128,   304,
      54,   247,   315,   227,  -215,    58,   316,   317,   318,   150,
     320,  -215,   321,   234,  -215,  -215,    54,  -215,  -215,   319,
    -215,  -215,   323,   324,   326,  -215,    -9,  -215,  -215,  -215,
     322,   248,   160,   150,   327,   325,   328,   329,  -215,  -215,
    -215,   330,  -215
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Gspn_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     1,     0,    27,     0,     0,
       0,     0,    30,     0,     0,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    28,     0,    29,
       0,     0,    37,    38,    40,    39,    42,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     2,     0,     0,
       0,     0,     0,     0,    16,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,    49,
      44,     0,    47,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      56,     0,     0,     0,    50,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     7,     5,     6,     8,    17,     0,
       0,     0,     0,    18,    21,    19,    20,    22,     0,    51,
       0,     0,    57,     0,     0,    76,     0,     0,    45,    43,
      48,    46,     0,     0,    10,     0,     9,     0,     0,    24,
      23,     0,     0,    55,     0,     0,    77,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,    82,     0,     0,    86,    12,
      13,    11,    25,    26,    54,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    87,    74,     0,    72,    64,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    71,     0,
       0,     0,     0,    79,     0,     0,     0,    73,    63,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    89,    62,     0,    70,    69,     0,
      58,    83,     0,     0,     0,    88,     0,    59,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    68,
      67,     0,    61
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yypgoto_[] =
  {
      -215,   -57,   -49,  -215,  -215,   332,   313,  -215,   331,   333,
     335,   301,  -215,   334,  -215,  -215,  -215,  -215,   285,   336,
    -215,   232,  -214,  -174,  -215,    38,  -215,  -215,    85,  -215,
    -215,   171,  -215,  -215,   168,  -215,  -215,   159,  -215
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Gspn_parser::yydefgoto_[] =
  {
        -1,    63,   208,     4,     5,     6,     7,     8,    22,     9,
      10,    23,    81,    24,    83,    17,    18,    74,    75,    36,
     109,   110,   229,   209,   261,   249,   180,   206,   207,    53,
     144,   145,    79,   168,   169,   114,   187,   188,    37
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Gspn_parser::yytable_ninf_ = -1;
  const unsigned short int
  Gspn_parser::yytable_[] =
  {
        72,    84,   177,   115,   100,   101,   117,   231,   104,    73,
     108,   143,   167,    28,    99,    11,    29,   186,    94,   100,
     101,   102,   103,   104,   211,   258,   259,   260,   120,   121,
     122,   123,   253,   124,   125,   126,   127,   116,   178,   179,
     118,    12,   106,   141,   165,   184,   129,   130,   131,   132,
     203,   133,   134,   135,   136,   137,   238,    64,    16,    65,
      66,    56,    89,    67,    57,     1,     2,    58,    90,    91,
      92,    93,   157,     3,     1,     2,   100,   101,   102,   103,
     104,   161,    20,    21,    68,    69,    70,    71,    59,    60,
      61,    62,   212,    15,   213,   171,   172,   158,   173,    13,
      14,   100,   101,   102,   103,   104,   152,     3,   174,   175,
     153,    90,    91,    92,    93,    90,    91,    92,    93,   128,
       2,   100,   101,   102,   103,   104,   154,    32,   155,    90,
      91,    92,    93,   159,    33,   100,   101,   102,   103,   104,
     100,   101,   102,   103,   104,     1,   205,   160,   210,   100,
     101,   102,   103,   104,   192,   222,   100,   101,   102,   103,
     104,    30,    90,   265,    31,    93,   266,   233,   205,    21,
     228,   193,   228,   100,   101,   102,   103,   104,   243,   220,
      35,   100,   101,   102,   103,   104,   119,   247,   248,    90,
      91,    92,    93,    34,   217,   156,   218,   228,    90,    91,
      92,    93,   176,    20,    40,    90,    91,    92,    93,   189,
      44,    41,    90,    91,    92,    93,   190,    45,    46,    90,
      91,    92,    93,   191,    47,    48,    90,    91,    92,    93,
     232,    50,    49,    90,    91,    92,    93,   242,    52,    51,
      90,    91,    92,    93,   252,    54,    55,    90,    91,    92,
      93,   224,   235,   225,   236,   239,   263,   240,   264,    73,
      76,    78,    77,    80,    82,    85,    86,    87,    88,   105,
     111,    95,    96,    97,    98,   113,   108,   138,   139,   112,
     140,   143,   146,   148,   147,   149,   150,   162,   151,   163,
      93,   104,   164,   167,   170,   181,   183,   182,   199,   194,
     186,   267,   227,   195,   196,   201,   197,   198,   200,   202,
     214,   215,   216,   226,   237,   166,   219,   221,   223,    19,
     230,   234,   241,   244,   245,    43,   246,   250,   251,   254,
     255,   262,   256,   257,   268,   269,   185,   272,   270,   271,
      25,   142,     0,    27,    26,     0,   204,     0,     0,     0,
      39,     0,     0,     0,    38,     0,     0,    42,     0,   107
  };

  /* YYCHECK.  */
  const short int
  Gspn_parser::yycheck_[] =
  {
        49,    58,     3,     8,    12,    13,     8,   221,    16,     9,
       9,     9,     9,     3,     7,    11,     6,     9,    67,    12,
      13,    14,    15,    16,   198,    34,    35,    36,    85,    86,
      87,    88,   246,    90,    91,    92,    93,    42,    39,    40,
      42,    11,    42,    42,    42,    42,    95,    96,    97,    98,
      42,   100,   101,   102,   103,   104,   230,     3,    24,     5,
       6,     3,     7,     9,     6,    18,    19,     9,    13,    14,
      15,    16,     8,    26,    18,    19,    12,    13,    14,    15,
      16,   138,    20,    21,    30,    31,    32,    33,    30,    31,
      32,    33,     8,     0,    10,   152,   153,     8,   155,    27,
      28,    12,    13,    14,    15,    16,     8,    26,   157,   158,
       8,    13,    14,    15,    16,    13,    14,    15,    16,    10,
      19,    12,    13,    14,    15,    16,    10,     3,    12,    13,
      14,    15,    16,    10,     3,    12,    13,    14,    15,    16,
      12,    13,    14,    15,    16,    18,   195,    10,   197,    12,
      13,    14,    15,    16,    10,   212,    12,    13,    14,    15,
      16,     3,    13,     3,     6,    16,     6,   224,   217,    21,
     219,    10,   221,    12,    13,    14,    15,    16,   235,    10,
      25,    12,    13,    14,    15,    16,    10,    37,    38,    13,
      14,    15,    16,    11,     8,    10,    10,   246,    13,    14,
      15,    16,    10,    20,    11,    13,    14,    15,    16,    10,
       7,    11,    13,    14,    15,    16,    10,     7,     7,    13,
      14,    15,    16,    10,     7,    11,    13,    14,    15,    16,
      10,    41,    11,    13,    14,    15,    16,    10,    22,    11,
      13,    14,    15,    16,    10,    41,    41,    13,    14,    15,
      16,     8,     8,    10,    10,     8,     8,    10,    10,     9,
      41,    23,    11,     3,     3,     9,     9,     9,     9,     3,
      41,     9,     9,     9,     9,    29,     9,     8,     7,    11,
       3,     9,    41,     3,    11,     7,     3,     8,     7,     7,
      16,    16,     3,     9,    41,     8,     3,     7,     3,     7,
       9,   263,   217,     9,     8,     7,     9,     8,     8,     3,
       3,     8,     7,     3,    10,   144,     8,     8,     7,     6,
       8,     7,     7,     7,     7,    24,     8,     7,     7,    10,
       7,     9,     8,     7,     7,    10,   168,     7,    10,    10,
       8,   109,    -1,    10,     9,    -1,   187,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    18,    -1,    -1,    23,    -1,    74
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Gspn_parser::yystos_[] =
  {
         0,    18,    19,    26,    46,    47,    48,    49,    50,    52,
      53,    11,    11,    27,    28,     0,    24,    58,    59,    49,
      20,    21,    51,    54,    56,    48,    53,    52,     3,     6,
       3,     6,     3,     3,    11,    25,    62,    81,    62,    51,
      11,    11,    56,    54,     7,     7,     7,     7,    11,    11,
      41,    11,    22,    72,    41,    41,     3,     6,     9,    30,
      31,    32,    33,    44,     3,     5,     6,     9,    30,    31,
      32,    33,    45,     9,    60,    61,    41,    11,    23,    75,
       3,    55,     3,    57,    44,     9,     9,     9,     9,     7,
      13,    14,    15,    16,    45,     9,     9,     9,     9,     7,
      12,    13,    14,    15,    16,     3,    42,    61,     9,    63,
      64,    41,    11,    29,    78,     8,    42,     8,    42,    10,
      44,    44,    44,    44,    44,    44,    44,    44,    10,    45,
      45,    45,    45,    45,    45,    45,    45,    45,     8,     7,
       3,    42,    64,     9,    73,    74,    41,    11,     3,     7,
       3,     7,     8,     8,    10,    12,    10,     8,     8,    10,
      10,    44,     8,     7,     3,    42,    74,     9,    76,    77,
      41,    44,    44,    44,    45,    45,    10,     3,    39,    40,
      69,     8,     7,     3,    42,    77,     9,    79,    80,    10,
      10,    10,    10,    10,     7,     9,     8,     9,     8,     3,
       8,     7,     3,    42,    80,    45,    70,    71,    45,    66,
      45,    66,     8,    10,     3,     8,     7,     8,    10,     8,
      10,     8,    44,     7,     8,    10,     3,    71,    45,    65,
       8,    65,    10,    44,     7,     8,    10,    10,    66,     8,
      10,     7,    10,    44,     7,     7,     8,    37,    38,    68,
       7,     7,    10,    65,    10,     7,     8,     7,    34,    35,
      36,    67,     9,     8,    10,     3,     6,    68,     7,    10,
      10,    10,     7
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
     295,   123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Gspn_parser::yyr1_[] =
  {
         0,    43,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    62,    63,    63,    64,    64,
      64,    64,    64,    65,    66,    67,    67,    67,    67,    68,
      68,    69,    70,    70,    71,    72,    73,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Gspn_parser::yyr2_[] =
  {
         0,     2,     1,     1,     3,     3,     3,     3,     3,     4,
       4,     6,     6,     6,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     4,     4,     6,     6,     2,     3,     3,
       2,     1,     2,     2,     2,     6,     6,     2,     2,     4,
       4,     4,     4,     6,     1,     3,     6,     1,     3,     4,
       5,     6,     1,     2,     6,     6,     1,     2,    10,    12,
      15,    17,    10,     1,     1,     1,     1,     4,     4,     1,
       1,     4,     1,     3,     1,     6,     1,     2,     8,     6,
       6,     1,     2,     8,     6,     6,     1,     2,     8,     6,
       1
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
  "MAX", "FLOOR", "ABS", "SINGLE", "INFINITE", "MULTIPLE",
  "ENABLINGMEMORY", "AGEMEMORY", "IMDT", "EXPO", "'{'", "'}'", "$accept",
  "IntStringFormula", "RealStringFormula", "GSPN", "declarations",
  "Constants", "Sizes", "Constant", "Lists", "NbPlaces", "NbTransitions",
  "PlacesList", "PLabels", "TransitionsList", "TLabels", "definitions",
  "PlacesDef", "PLACES", "PLACE", "TransitionsDef", "TRANSITIONS",
  "TRANSITION", "WEIGHT", "PRIORITY", "SERVICE", "MEMORY", "dist",
  "params", "param", "InArcs", "incells", "incell", "OutArcs", "outcells",
  "outcell", "Inhibitors", "inhibcells", "inhibcell", "redifinitions", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Gspn_parser::rhs_number_type
  Gspn_parser::yyrhs_[] =
  {
        46,     0,    -1,     6,    -1,     3,    -1,     9,    44,    10,
      -1,    44,    14,    44,    -1,    44,    15,    44,    -1,    44,
      13,    44,    -1,    44,    16,    44,    -1,    33,     9,    44,
      10,    -1,    32,     9,    44,    10,    -1,    32,     9,    44,
      12,    44,    10,    -1,    30,     9,    44,     8,    44,    10,
      -1,    31,     9,    44,     8,    44,    10,    -1,     5,    -1,
       6,    -1,     3,    -1,     9,    45,    10,    -1,    45,    12,
      45,    -1,    45,    14,    45,    -1,    45,    15,    45,    -1,
      45,    13,    45,    -1,    45,    16,    45,    -1,    33,     9,
      45,    10,    -1,    32,     9,    45,    10,    -1,    30,     9,
      45,     8,    45,    10,    -1,    31,     9,    45,     8,    45,
      10,    -1,    47,    58,    -1,    47,    58,    81,    -1,    48,
      49,    51,    -1,    49,    51,    -1,    50,    -1,    50,    48,
      -1,    52,    53,    -1,    53,    52,    -1,    26,    27,     3,
      11,    44,     7,    -1,    26,    28,     3,    11,    45,     7,
      -1,    54,    56,    -1,    56,    54,    -1,    18,    11,     6,
       7,    -1,    18,    11,     3,     7,    -1,    19,    11,     6,
       7,    -1,    19,    11,     3,     7,    -1,    20,    11,    41,
      55,    42,     7,    -1,     3,    -1,    55,     8,     3,    -1,
      21,    11,    41,    57,    42,     7,    -1,     3,    -1,    57,
       8,     3,    -1,    59,    62,    72,    75,    -1,    59,    62,
      72,    75,    78,    -1,    24,    11,    41,    60,    42,     7,
      -1,    61,    -1,    60,    61,    -1,     9,     3,     8,    44,
      10,     7,    -1,    25,    11,    41,    63,    42,     7,    -1,
      64,    -1,    63,    64,    -1,     9,     3,     8,    69,     8,
      66,     8,    65,    10,     7,    -1,     9,     3,     8,    69,
       8,    66,     8,    65,     8,    68,    10,     7,    -1,     9,
       3,     8,    40,     9,    45,    10,     8,    66,     8,    65,
       8,    67,    10,     7,    -1,     9,     3,     8,    40,     9,
      45,    10,     8,    66,     8,    65,     8,    67,     8,    68,
      10,     7,    -1,     9,     3,     8,    39,     8,    66,     8,
      65,    10,     7,    -1,    45,    -1,    45,    -1,    34,    -1,
      35,    -1,    36,     9,     6,    10,    -1,    36,     9,     3,
      10,    -1,    38,    -1,    37,    -1,     3,     9,    70,    10,
      -1,    71,    -1,    70,     8,    71,    -1,    45,    -1,    22,
      11,    41,    73,    42,     7,    -1,    74,    -1,    73,    74,
      -1,     9,     3,     8,     3,     8,    44,    10,     7,    -1,
       9,     3,     8,     3,    10,     7,    -1,    23,    11,    41,
      76,    42,     7,    -1,    77,    -1,    76,    77,    -1,     9,
       3,     8,     3,     8,    44,    10,     7,    -1,     9,     3,
       8,     3,    10,     7,    -1,    29,    11,    41,    79,    42,
       7,    -1,    80,    -1,    79,    80,    -1,     9,     3,     8,
       3,     8,    44,    10,     7,    -1,     9,     3,     8,     3,
      10,     7,    -1,    62,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Gspn_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    11,    15,    19,    23,    27,
      32,    37,    44,    51,    58,    60,    62,    64,    68,    72,
      76,    80,    84,    88,    93,    98,   105,   112,   115,   119,
     123,   126,   128,   131,   134,   137,   144,   151,   154,   157,
     162,   167,   172,   177,   184,   186,   190,   197,   199,   203,
     208,   214,   221,   223,   226,   233,   240,   242,   245,   256,
     269,   285,   303,   314,   316,   318,   320,   322,   327,   332,
     334,   336,   341,   343,   347,   349,   356,   358,   361,   370,
     377,   384,   386,   389,   398,   405,   412,   414,   417,   426,
     433
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Gspn_parser::yyrline_[] =
  {
         0,   127,   127,   128,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   151,   152,   153,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   176,   177,   179,
     180,   184,   185,   187,   188,   190,   197,   205,   206,   208,
     211,   220,   223,   232,   295,   301,   307,   315,   320,   327,
     328,   330,   332,   333,   335,   349,   359,   360,   362,   380,
     399,   433,   467,   490,   501,   513,   514,   515,   525,   539,
     540,   543,   718,   719,   723,   732,   734,   735,   737,   757,
     772,   774,   775,   777,   797,   813,   815,   816,   818,   839,
     856
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
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Gspn_parser::yyeof_ = 0;
  const int Gspn_parser::yylast_ = 359;
  const int Gspn_parser::yynnts_ = 39;
  const int Gspn_parser::yyempty_ = -2;
  const int Gspn_parser::yyfinal_ = 15;
  const int Gspn_parser::yyterror_ = 1;
  const int Gspn_parser::yyerrcode_ = 256;
  const int Gspn_parser::yyntokens_ = 43;

  const unsigned int Gspn_parser::yyuser_token_number_max_ = 295;
  const Gspn_parser::token_number_type Gspn_parser::yyundef_token_ = 2;


} // gspn

/* Line 1054 of lalr1.cc  */
#line 2207 "Gspn-parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 858 "Gspn-parser.yy"


void
gspn::Gspn_parser::error (const gspn::Gspn_parser::location_type& l,
                          const std::string& m)
{
  Reader.error (l, m);
}

