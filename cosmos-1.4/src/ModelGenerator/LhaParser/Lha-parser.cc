// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   lhalex

// First part of user declarations.

#line 39 "Lha-parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "Lha-parser.hh"

// User implementation prologue.

#line 53 "Lha-parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 41 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:408

	#include "../HaslFormula.hpp"
	#include "Lha-Reader.hpp"
	#include <set>
	#include <vector>
	
	Eval LhaEvaluate;
	
	

	vector<string> FuncFlowVector;
	
	vector<string> FuncUpdateVector;
    vector<string> FuncUpdateVectorIndex;
	
	set <string> PetriTransitions;
	set <string> SubSet;
	
	
	
	vector < string > CoeffsVector;
	vector < vector <string> > CoeffsMatrix;
	vector <string> CST;
	vector <string> comp;
	
	
	
	
	
	

#line 87 "Lha-parser.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace lha {
#line 173 "Lha-parser.cc" // lalr1.cc:474

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
              // Fall through.
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
  {}

  Lha_parser::~Lha_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Lha_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Lha_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Lha_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Lha_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Lha_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Lha_parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Lha_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Lha_parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Lha_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Lha_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Lha_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Lha_parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Lha_parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Lha_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Lha_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Lha_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Lha_parser::symbol_number_type
  Lha_parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Lha_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Lha_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Lha_parser::stack_symbol_type&
  Lha_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Lha_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 3: // str

#line 166 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:602
        { delete (yysym.value.name); }
#line 392 "Lha-parser.cc" // lalr1.cc:602
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Lha_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // str

#line 165 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:617
        { debug_stream () << *(yysym.value.name); }
#line 419 "Lha-parser.cc" // lalr1.cc:617
        break;

      case 4: // rval

#line 169 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:617
        { debug_stream () << (yysym.value.RealVal); }
#line 426 "Lha-parser.cc" // lalr1.cc:617
        break;

      case 5: // ival

#line 168 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:617
        { debug_stream () << (yysym.value.IntVal); }
#line 433 "Lha-parser.cc" // lalr1.cc:617
        break;

      case 108: // rorival

#line 169 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:617
        { debug_stream () << (yysym.value.RealVal); }
#line 440 "Lha-parser.cc" // lalr1.cc:617
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  Lha_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Lha_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Lha_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline Lha_parser::state_type
  Lha_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

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
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, Reader));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 6:
#line 197 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%i",(yystack_[0].value.IntVal));}
#line 667 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 198 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yystack_[0].value.name)->c_str()<<" ";
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaIntConstant.find(*(yystack_[0].value.name))!=Reader.MyLha.LhaIntConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaIntConstant[*(yystack_[0].value.name)];
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	} else {
        size_t vararray = Reader.MyLha.Vars.find(*(yystack_[0].value.name));
        if(vararray!= Reader.MyLha.NbVar && Reader.MyLha.Vars.type[vararray]==DISCRETE_VARIABLE){
            sprintf((yylhs.value.expression), " floor(Vars->%s)", Reader.MyLha.Vars.label[vararray].c_str() );
        } else {cout<<"'"<<*(yystack_[0].value.name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}
    }
}
#line 687 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 213 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[3].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yystack_[3].value.name)->c_str()<< ".mult";
	 s << (yystack_[1].value.expression);
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yystack_[3].value.name)<<"' is not a place label "<<endl;YYABORT;}}
#line 699 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 220 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    size_t vararray = Reader.MyLha.Vars.find(*(yystack_[3].value.name));
	if(vararray!= Reader.MyLha.NbVar && Reader.MyLha.Vars.type[vararray]==INT_INDEXED_DISC_ARRAY)
	{std::ostringstream s;
        s<<" Vars.P->" << Reader.MyLha.Vars.label[vararray] << "["<< *(yystack_[1].value.expression) << "]";
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yystack_[3].value.name)<<"' is not a discrete array name "<<endl;YYABORT;}}
#line 711 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 227 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"( %s )", (yystack_[1].value.expression));       }
#line 717 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 228 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"-%s",(yystack_[0].value.expression));}
#line 723 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 229 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s + %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 729 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 230 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s - %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 735 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 231 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s * %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 741 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 232 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"pow(%s , %s)", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 747 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 233 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"floor( %s )", (yystack_[1].value.expression));  }
#line 753 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 234 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"floor( %s /double(%s))", (yystack_[3].value.expression),(yystack_[1].value.expression));  }
#line 759 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 235 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"min(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 765 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 236 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"max(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 771 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 239 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression), "%f",(yystack_[0].value.RealVal));}
#line 777 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 240 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%d",(yystack_[0].value.IntVal));}
#line 783 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 241 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yystack_[0].value.name)->c_str();
		if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yystack_[0].value.name)]].colorDom !=0 )s <<".card()";
		sprintf((yylhs.value.expression), "%s ",(s.str()).c_str());
	}
	else if(Reader.MyLha.LhaRealConstant.find(*(yystack_[0].value.name))!=Reader.MyLha.LhaRealConstant.end())
	{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yystack_[0].value.name)];
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}
	
	else{cout<<"'"<<*(yystack_[0].value.name)<<"' is not a place label or a defined constant"<<endl;YYABORT;}}
#line 800 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 253 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[3].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yystack_[3].value.name)->c_str()<< ".mult";
	 s << (yystack_[1].value.expression);
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yystack_[3].value.name)<<"' is not a place label "<<endl;YYABORT;}}
#line 812 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 260 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"( %s )", (yystack_[1].value.expression));       }
#line 818 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 261 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"-%s",(yystack_[0].value.expression));}
#line 824 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 262 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s /double(%s)", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 830 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 263 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s + %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 836 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 264 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s - %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 842 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 265 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s * %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 848 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 266 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"pow(%s , %s)", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 854 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 267 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"floor( %s )", (yystack_[1].value.expression));  }
#line 860 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 268 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"min(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 866 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 269 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"max(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 872 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 271 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression), "%f",(yystack_[0].value.RealVal));}
#line 878 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 272 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%d",(yystack_[0].value.IntVal));}
#line 884 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 36:
#line 273 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<<(yystack_[0].value.name)->c_str();
		if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yystack_[0].value.name)]].colorDom !=0 )s <<".card()";
		sprintf((yylhs.value.expression), "%s ",(s.str()).c_str());
	}
	else{ if(Reader.MyLha.LhaRealConstant.find(*(yystack_[0].value.name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yystack_[0].value.name)];
			sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
		}
		else {if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
			{
				std::ostringstream s; s<<"Vars->"<< (yystack_[0].value.name)->c_str();
				sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
			}
			else {cout<<"'"<<*(yystack_[0].value.name)<<"' is not a place label, a lha variable or a defined constant"<<endl;YYABORT;}
		}
	}
}
#line 908 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 37:
#line 292 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.PlaceIndex.find(*(yystack_[3].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s;
	 s<<" Marking.P->_PL_"<< (yystack_[3].value.name)->c_str()<< ".mult";
	 s << (yystack_[1].value.expression);
		sprintf((yylhs.value.expression), "%s",(s.str()).c_str());
	}else{cout<<"'"<<*(yystack_[3].value.name)<<"' is not a place label "<<endl;YYABORT;}}
#line 920 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 38:
#line 299 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"( %s )", (yystack_[1].value.expression));       }
#line 926 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 39:
#line 300 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"-%s",(yystack_[0].value.expression));}
#line 932 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 40:
#line 301 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s /double(%s)", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 938 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 41:
#line 302 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s + %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 944 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 42:
#line 303 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s - %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 950 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 43:
#line 304 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s * %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 956 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 44:
#line 305 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"pow(%s , %s)", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 962 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 45:
#line 306 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"floor( %s )", (yystack_[1].value.expression));  }
#line 968 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 46:
#line 307 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"min(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 974 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 47:
#line 308 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"max(%s , %s)", (yystack_[3].value.expression), (yystack_[1].value.expression));  }
#line 980 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 48:
#line 310 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"[%s]", (yystack_[1].value.name)->c_str()); }
#line 986 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 49:
#line 311 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"[%s]%s", (yystack_[2].value.name)->c_str(), (yystack_[0].value.expression)); }
#line 992 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 52:
#line 315 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.NbVar=0;}
#line 998 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 53:
#line 316 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.NbLoc=0;}
#line 1004 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 54:
#line 317 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.NbVar=0;Reader.MyLha.NbLoc=0;}
#line 1010 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 57:
#line 323 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.LhaRealConstant.find(*(yystack_[3].value.name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yystack_[3].value.name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yystack_[1].value.expression);
		if (Reader.P.constants.count(*(yystack_[3].value.name))>0)st = Reader.P.constants[*(yystack_[3].value.name)];
		
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaIntConstant[*(yystack_[3].value.name)]=LhaEvaluate.IntResult;Reader.MyLha.LhaRealConstant[*(yystack_[3].value.name)]=LhaEvaluate.RealResult;}
}
#line 1023 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 58:
#line 332 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.LhaRealConstant.find(*(yystack_[3].value.name))!=Reader.MyLha.LhaRealConstant.end())
	{cout<<"Constant "<<*(yystack_[3].value.name)<<" already defined."<<endl; YYABORT;}
	else {string st=(yystack_[1].value.expression);
		if (Reader.P.constants.count(*(yystack_[3].value.name))>0)st = Reader.P.constants[*(yystack_[3].value.name)];
		LhaEvaluate.parse(st);
		Reader.MyLha.LhaRealConstant[*(yystack_[3].value.name)]=LhaEvaluate.RealResult;}
}
#line 1035 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 59:
#line 342 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.NbVar=(yystack_[1].value.IntVal);}
#line 1041 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 60:
#line 344 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.NbLoc=(yystack_[1].value.IntVal);}
#line 1047 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 63:
#line 349 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.NbVar==0)Reader.MyLha.NbVar = Reader.MyLha.Vars.label.size();
	if(Reader.MyLha.Vars.label.size()!=Reader.MyLha.NbVar){
		std::cout<<"Variable label missing or redeclared, please check your variables list"<<std::endl;
		YYABORT;
	}

	FuncFlowVector.resize(Reader.MyLha.NbVar);
	FuncUpdateVector.resize(Reader.MyLha.NbVar);
    FuncUpdateVectorIndex.resize(Reader.MyLha.NbVar);
	CoeffsVector.resize(Reader.MyLha.NbVar);

	for(const auto &it : Reader.MyLha.TransitionIndex)
		PetriTransitions.insert(it.first);
	
	

}
#line 1070 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 64:
#line 368 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.Vars.label.push_back(*(yystack_[0].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
    Reader.MyLha.Vars.isTraced.push_back(true);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
}
#line 1083 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 65:
#line 376 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	Reader.MyLha.Vars.label.push_back(*(yystack_[0].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(DISCRETE_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
    Reader.MyLha.Vars.isTraced.push_back(true);
    //Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;
	
}
#line 1098 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 66:
#line 386 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {

	Reader.MyLha.Vars.label.push_back(*(yystack_[3].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(INT_INDEXED_DISC_ARRAY);
	Reader.MyLha.Vars.colorDomain.push_back((yystack_[1].value.IntVal));
    Reader.MyLha.Vars.isTraced.push_back(true);
	//Reader.MyLha.VarIndex[*$1]=Reader.MyLha.VarLabel.size()-1;

}
#line 1113 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 67:
#line 397 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.Vars.label.push_back(*(yystack_[0].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(CONTINIOUS_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
    Reader.MyLha.Vars.isTraced.push_back(true);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
#line 1126 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 68:
#line 405 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.Vars.label.push_back(*(yystack_[0].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(DISCRETE_VARIABLE);
	Reader.MyLha.Vars.colorDomain.push_back(UNCOLORED_DOMAIN);
    Reader.MyLha.Vars.isTraced.push_back(true);
	//Reader.MyLha.VarIndex[*$3]=Reader.MyLha.VarLabel.size()-1;
}
#line 1139 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 69:
#line 413 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    Reader.MyLha.Vars.label.push_back(*(yystack_[3].value.name));
	Reader.MyLha.Vars.initialValue.push_back(0.0);
	Reader.MyLha.Vars.type.push_back(INT_INDEXED_DISC_ARRAY);
	Reader.MyLha.Vars.colorDomain.push_back((yystack_[1].value.IntVal));
    Reader.MyLha.Vars.isTraced.push_back(true);

}
#line 1152 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 70:
#line 422 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.NbLoc ==0)Reader.MyLha.NbLoc = Reader.MyLha.LocIndex.size();
	if(Reader.MyLha.LocIndex.size()!=Reader.MyLha.NbLoc){
	std::cout<<"Location label missing or redeclared, please check your locations list"<<std::endl;
	YYABORT;
	}
    Reader.MyLha.FuncLocProperty=vector<string>(Reader.MyLha.NbLoc,"");
    Reader.MyLha.FuncFlow=vector<vector<string> >(Reader.MyLha.NbLoc,vector<string>(Reader.MyLha.NbVar,""));
}
#line 1166 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 71:
#line 432 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.LocLabel.push_back(*(yystack_[0].value.name));
	Reader.MyLha.LocIndex[*(yystack_[0].value.name)]=Reader.MyLha.LocLabel.size()-1;
}
#line 1175 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 72:
#line 436 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {Reader.MyLha.LocLabel.push_back(*(yystack_[0].value.name));
	Reader.MyLha.LocIndex[*(yystack_[0].value.name)]=Reader.MyLha.LocLabel.size()-1;
}
#line 1183 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 76:
#line 446 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	if(Reader.MyLha.LocIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yystack_[0].value.name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
#line 1196 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 77:
#line 454 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.LocIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.InitLoc.insert(Reader.MyLha.LocIndex[*(yystack_[0].value.name)]);
	else cout<<"Unknown location"<<endl;
}
#line 1205 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 79:
#line 461 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	if(Reader.MyLha.LocIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yystack_[0].value.name)]);
	else cout<<"Unknown location"<<endl;
	
	
}
#line 1218 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 80:
#line 469 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.LocIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.LocIndex.end())
	Reader.MyLha.FinalLoc.insert(Reader.MyLha.LocIndex[*(yystack_[0].value.name)]);
	else {cout<<"Unknown location"<<endl;YYABORT;}
}
#line 1227 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 83:
#line 483 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	for(size_t l=0; l<Reader.MyLha.FuncLocProperty.size();l++)
	if(Reader.MyLha.FuncLocProperty[l]=="")
	{cout<<"Some locations are not definded. Please define all the declared locations."<<endl;
		YYABORT;}
	
	Reader.MyLha.Out_S_Edges.resize(Reader.MyLha.NbLoc);
	Reader.MyLha.Out_A_Edges.resize(Reader.MyLha.NbLoc);
}
#line 1241 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 86:
#line 497 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    auto loc = Reader.MyLha.LocIndex.find(*(yystack_[8].value.name));
	if(loc !=Reader.MyLha.LocIndex.end()){
		Reader.MyLha.FuncLocProperty[loc->second]= (yystack_[6].value.expression);
		Reader.MyLha.FuncFlow[loc->second] = FuncFlowVector;
        FuncFlowVector=vector<string>(Reader.MyLha.NbVar,"");
	}
	else {cout<<"Unknown location"<<endl;YYABORT;}
	
}
#line 1256 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 87:
#line 510 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    auto loc = Reader.MyLha.LocIndex.find(*(yystack_[4].value.name));
	if(loc != Reader.MyLha.LocIndex.end()){
		Reader.MyLha.FuncLocProperty[loc->second]= (yystack_[2].value.expression);
		Reader.MyLha.FuncFlow[loc->second] = FuncFlowVector;
	}
	else {cout<<"Unknown location"<<endl;YYABORT;}
	
	
}
#line 1271 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 90:
#line 523 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    if(Reader.MyLha.Vars.find(*(yystack_[2].value.name))!=Reader.MyLha.Vars.label.size())
	FuncFlowVector[Reader.MyLha.Vars.find(*(yystack_[2].value.name))]=(yystack_[0].value.expression);
	else{ cout<<"'"<<*(yystack_[2].value.name)<<"' is not an Lha variable"<<endl;
		YYABORT;}
}
#line 1282 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 91:
#line 530 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"true");}
#line 1288 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 92:
#line 531 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"false");}
#line 1294 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 93:
#line 532 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s", (yystack_[0].value.expression));}
#line 1300 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 94:
#line 533 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s && %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1306 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 95:
#line 534 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s || %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1312 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 96:
#line 535 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"( %s )", (yystack_[1].value.expression));}
#line 1318 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 97:
#line 536 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"! %s", (yystack_[0].value.expression));}
#line 1324 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 98:
#line 538 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s == %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1330 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 99:
#line 539 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s <= %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1336 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 100:
#line 540 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s >= %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1342 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 101:
#line 541 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s < %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1348 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 102:
#line 542 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s > %s", (yystack_[2].value.expression), (yystack_[0].value.expression));}
#line 1354 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 103:
#line 547 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
}
#line 1362 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 106:
#line 554 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	if(Reader.MyLha.LocIndex.find(*(yystack_[11].value.name))!=Reader.MyLha.LocIndex.end())
	if(Reader.MyLha.LocIndex.find(*(yystack_[9].value.name))!=Reader.MyLha.LocIndex.end())
	{ int ne=Reader.MyLha.Edge.size();
		Reader.MyLha.AnEdge.Index=ne;
		Reader.MyLha.AnEdge.Source=Reader.MyLha.LocIndex[*(yystack_[11].value.name)];
		Reader.MyLha.AnEdge.Target=Reader.MyLha.LocIndex[*(yystack_[9].value.name)];
		Reader.MyLha.Edge.push_back(Reader.MyLha.AnEdge);
		Reader.MyLha.EdgeActions.push_back(SubSet);
		if(SubSet.size()>0) Reader.MyLha.Out_S_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
		else Reader.MyLha.Out_A_Edges[Reader.MyLha.AnEdge.Source].insert(ne);
		SubSet.erase(SubSet.begin(),SubSet.end());
		Reader.MyLha.ConstraintsCoeffs.push_back(CoeffsMatrix);
        Reader.MyLha.ConstraintsConstants.push_back(CST);
		Reader.MyLha.ConstraintsRelOp.push_back(comp);
		Reader.MyLha.unTimeEdgeConstraints.push_back("true");
		vector<string> vs;comp=vs;CST=vs;
		vector <vector <string> > ms;CoeffsMatrix=ms;
		
	}
	else {cout<<*(yystack_[9].value.name)<<" is not a location label"<<endl;YYABORT;}
	else  {cout<<*(yystack_[11].value.name)<<" is not a location label"<<endl;YYABORT;}
}
#line 1391 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 108:
#line 580 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {SubSet=PetriTransitions;}
#line 1397 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 109:
#line 581 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {set<string> temp=PetriTransitions;
	for(set<string>::iterator it=SubSet.begin();it!=SubSet.end();it++)
	temp.erase((*it));
	SubSet=temp;}
#line 1406 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 112:
#line 589 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.TransitionIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yystack_[0].value.name));
	else {cout<<*(yystack_[0].value.name)<<" is not a Petri-net transition "<<endl;YYABORT;}
}
#line 1415 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 113:
#line 593 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {if(Reader.MyLha.TransitionIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.TransitionIndex.end())
	SubSet.insert(*(yystack_[0].value.name));
	else {cout<<*(yystack_[0].value.name)<<" is not a Petri-net transition "<<endl;YYABORT;}}
#line 1423 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 114:
#line 598 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {}
#line 1429 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 115:
#line 599 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {}
#line 1435 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 117:
#line 603 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("==");
	CST.push_back((yystack_[0].value.expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
#line 1444 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 118:
#line 608 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back("<=");
	CST.push_back((yystack_[0].value.expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
#line 1453 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 119:
#line 613 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {CoeffsMatrix.push_back(CoeffsVector);
	comp.push_back(">=");
	CST.push_back((yystack_[0].value.expression));
	vector<string> vs(Reader.MyLha.NbVar,"");CoeffsVector=vs;}
#line 1462 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 123:
#line 623 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]="1";}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1470 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 124:
#line 627 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"("<<(yystack_[3].value.expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1479 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 125:
#line 632 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yystack_[2].value.IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1488 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 126:
#line 637 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<(yystack_[2].value.RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1497 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 127:
#line 642 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yystack_[2].value.name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<Reader.MyLha.LhaRealConstant[*(yystack_[2].value.name)];
			CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yystack_[2].value.name))!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"Marking.P->_PL_"<<(yystack_[2].value.name)->c_str()<<" ";
				CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();
			}
			else
			{
				cout<<*(yystack_[2].value.name)<<" is not Petri-net Place or a defined constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}
}
#line 1522 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 128:
#line 663 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]="-1";}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1530 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 129:
#line 667 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-("<<(yystack_[3].value.expression)<<")";
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1539 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 130:
#line 672 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yystack_[2].value.IntVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1548 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 131:
#line 677 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{std::ostringstream s; s<<"-"<<(yystack_[2].value.RealVal);
		CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 1557 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 132:
#line 682 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yystack_[2].value.name))!=Reader.MyLha.LhaRealConstant.end())
		{std::ostringstream s; s<<"-"<<Reader.MyLha.LhaRealConstant[*(yystack_[2].value.name)];
			CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yystack_[2].value.name))!=Reader.MyLha.PlaceIndex.end())
			{std::ostringstream s; s<<"-Marking.P->_PL_"<<(yystack_[2].value.name)->c_str()<<" ";
				CoeffsVector[Reader.MyLha.Vars.find(*(yystack_[0].value.name))]=s.str();
			}
			else
			{
				cout<<*(yystack_[2].value.name)<<" is not Petri-net Place or a defined constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}
}
#line 1582 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 133:
#line 704 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);
    Reader.MyLha.FuncEdgeUpdatesIndex.push_back(FuncUpdateVectorIndex);
    FuncUpdateVector=vector<string>(Reader.MyLha.NbVar,"");
    FuncUpdateVectorIndex=vector<string>(Reader.MyLha.NbVar,"");
}
#line 1593 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 134:
#line 710 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    Reader.MyLha.FuncEdgeUpdates.push_back(FuncUpdateVector);
    Reader.MyLha.FuncEdgeUpdatesIndex.push_back(FuncUpdateVectorIndex);
}
#line 1602 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 137:
#line 718 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if(Reader.MyLha.Vars.find(*(yystack_[2].value.name))!=Reader.MyLha.Vars.label.size())
    {FuncUpdateVector[Reader.MyLha.Vars.find(*(yystack_[2].value.name))]= (yystack_[0].value.expression);}
	else{cout<<*(yystack_[2].value.name)<<" is not  variable label"<<endl;YYABORT;}
}
#line 1612 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 138:
#line 723 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    size_t varin = Reader.MyLha.Vars.find(*(yystack_[5].value.name));
	if(varin != Reader.MyLha.Vars.label.size()){
        FuncUpdateVector[varin]= (yystack_[0].value.expression);
        FuncUpdateVectorIndex[varin]= (yystack_[3].value.expression);
        //cout << "var:" << *$1 << "\tindex:" << $3 << "\tupdate:" << $6<< endl;
    }else{cout<<*(yystack_[5].value.name)<<" is not  variable label"<<endl;YYABORT;}
}
#line 1625 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 141:
#line 737 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if((yystack_[1].value.TOPHASL) != NULL){
		Reader.MyLha.HASLname.push_back(*(yystack_[3].value.name));
		Reader.MyLha.HASLtop.push_back((yystack_[1].value.TOPHASL));
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,*(yystack_[3].value.name));
		}
	}
}
#line 1641 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 142:
#line 748 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	if((yystack_[1].value.TOPHASL) != NULL){
		Reader.MyLha.HASLname.push_back("");
		Reader.MyLha.HASLtop.push_back((yystack_[1].value.TOPHASL));
	}else{
		for(vector<string>::iterator it = Reader.MyLha.HASLname.begin(); it <Reader.MyLha.HASLname.end() ; it++){
			if( it->find("$_$") == 0)
				it->replace(0,3,"");
		}
	}
}
#line 1657 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 143:
#line 761 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {(yylhs.value.RealVal)=(yystack_[0].value.RealVal);}
#line 1663 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 144:
#line 762 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {(yylhs.value.RealVal)=(double)(yystack_[0].value.IntVal);}
#line 1669 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 145:
#line 763 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.LhaRealConstant.find(*(yystack_[0].value.name))!=Reader.MyLha.LhaRealConstant.end())
			(yylhs.value.RealVal) = Reader.MyLha.LhaRealConstant[*(yystack_[0].value.name)];
		else { if(Reader.MyLha.LhaIntConstant.find(*(yystack_[0].value.name))!=Reader.MyLha.LhaIntConstant.end())
			(yylhs.value.RealVal) = (double)Reader.MyLha.LhaIntConstant[*(yystack_[0].value.name)];
		else {
			cout<<*(yystack_[0].value.name)<<" is not a definded constant "<<endl;
			YYABORT;
		}}}
#line 1682 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 146:
#line 773 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.Algebraic.push_back((yystack_[1].value.expression));
	(yylhs.value.TOPHASL) = new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1);
}
#line 1691 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 147:
#line 777 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop(PROBABILITY);
}
#line 1699 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 148:
#line 780 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    (yylhs.value.TOPHASL) = new HaslFormulasTop(EXISTS);
}
#line 1707 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 149:
#line 783 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    (yylhs.value.TOPHASL) = new HaslFormulasTop(NOTALLS);
}
#line 1715 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 150:
#line 786 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop((yystack_[3].value.RealVal),(yystack_[1].value.RealVal));
}
#line 1723 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 151:
#line 789 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	for(double bucket = (yystack_[3].value.RealVal) ; bucket < (yystack_[1].value.RealVal) ; bucket+= (yystack_[5].value.RealVal)){
		std::ostringstream algPDF;
		algPDF << "(("<<(yystack_[7].value.expression)<<" >= "<<bucket<<"&& "<<(yystack_[7].value.expression)<<"<"<<bucket+(yystack_[5].value.RealVal)<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algPDF.str());
		Reader.MyLha.HASLtop.push_back(
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1));
		Reader.MyLha.HASLtop.back()->TypeOp = PDF_PART;
		std::ostringstream s; s<<"$_$: Value in ["<< bucket<< " , "<<bucket+(yystack_[5].value.RealVal)<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yylhs.value.TOPHASL) = NULL;
}
#line 1743 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 152:
#line 804 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	
	for(double bucket = (yystack_[3].value.RealVal) ; bucket < (yystack_[1].value.RealVal) ; bucket+= (yystack_[5].value.RealVal)){
		std::ostringstream algCDF;
		algCDF << "(("<<(yystack_[7].value.expression)<<" <= "<<bucket<<") ? 1:0)";
		
		Reader.MyLha.Algebraic.push_back(algCDF.str());
		Reader.MyLha.HASLtop.push_back(
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1));
		Reader.MyLha.HASLtop.back()->TypeOp = CDF_PART;
		std::ostringstream s; s<<"$_$: Value in [-infinity , "<< bucket<<"]";
		Reader.MyLha.HASLname.push_back(s.str());
	}
	(yylhs.value.TOPHASL) = NULL;
}
#line 1763 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 153:
#line 819 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	Reader.MyLha.Algebraic.push_back((yystack_[1].value.expression));
	char tmp[5000];
	sprintf(tmp,"(%s * %s)", (yystack_[1].value.expression),(yystack_[1].value.expression));
	Reader.MyLha.Algebraic.push_back(tmp);
	(yylhs.value.TOPHASL) = new HaslFormulasTop(HASL_MINUS,
		new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-1),
		new HaslFormulasTop(HASL_TIME,
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-2),
			new HaslFormulasTop((size_t)Reader.MyLha.Algebraic.size()-2)));
}
#line 1779 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 154:
#line 830 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = (yystack_[1].value.TOPHASL);
}
#line 1787 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 155:
#line 833 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop(HASL_PLUS, (yystack_[2].value.TOPHASL),(yystack_[0].value.TOPHASL));
}
#line 1795 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 156:
#line 836 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop(HASL_MINUS, (yystack_[2].value.TOPHASL),(yystack_[0].value.TOPHASL));
}
#line 1803 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 157:
#line 839 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop(HASL_TIME, (yystack_[2].value.TOPHASL), (yystack_[0].value.TOPHASL));
}
#line 1811 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 158:
#line 842 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop(HASL_DIV, (yystack_[2].value.TOPHASL),(yystack_[0].value.TOPHASL));
}
#line 1819 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 159:
#line 845 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop((double)(yystack_[0].value.IntVal),0.0,1.0);
}
#line 1827 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 160:
#line 848 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
	(yylhs.value.TOPHASL) = new HaslFormulasTop((double)(yystack_[0].value.RealVal),0.0,1.0);
}
#line 1835 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 161:
#line 852 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {string ss=(yystack_[0].value.expression);
	sprintf((yylhs.value.expression),"LhaFunc[%d]", Reader.MyLha.LhaFunction[ss]);
}
#line 1843 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 162:
#line 855 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"min(%s,%s)", (yystack_[3].value.expression),(yystack_[1].value.expression));}
#line 1849 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 163:
#line 856 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"max(%s,%s)", (yystack_[3].value.expression),(yystack_[1].value.expression));}
#line 1855 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 164:
#line 857 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"-%s", (yystack_[0].value.expression));}
#line 1861 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 165:
#line 858 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"floor(%s)", (yystack_[1].value.expression));}
#line 1867 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 166:
#line 859 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"(%s)", (yystack_[1].value.expression));}
#line 1873 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 167:
#line 860 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"pow(%s , %s)", (yystack_[2].value.expression),(yystack_[0].value.expression));}
#line 1879 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 168:
#line 861 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"(%s + %s)", (yystack_[2].value.expression),(yystack_[0].value.expression));}
#line 1885 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 169:
#line 862 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"(%s - %s)", (yystack_[2].value.expression),(yystack_[0].value.expression));}
#line 1891 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 170:
#line 863 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"(%s * %s)", (yystack_[2].value.expression),(yystack_[0].value.expression));}
#line 1897 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 171:
#line 864 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"(%s / %s)", (yystack_[2].value.expression),(yystack_[0].value.expression));}
#line 1903 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 172:
#line 866 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {std::ostringstream s; s<<(yystack_[1].value.expression);
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Last");
	string ss="Last("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf((yylhs.value.expression),"%s", ss.c_str());
}
#line 1918 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 173:
#line 876 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {std::ostringstream s; s<<(yystack_[1].value.expression);
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Min");
	string ss="Min("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf((yylhs.value.expression),"%s", ss.c_str());
}
#line 1933 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 174:
#line 886 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {std::ostringstream s; s<<(yystack_[1].value.expression);
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Max");
	string ss="Max("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf((yylhs.value.expression),"%s", ss.c_str());
}
#line 1948 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 175:
#line 896 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {std::ostringstream s; s<<(yystack_[1].value.expression);
	if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
	{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
	Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
	Reader.MyLha.LhaFuncType.push_back("Integral");
	string ss="Integral("; ss.append(s.str()); ss.append(")");
	if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
	{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
	sprintf((yylhs.value.expression),"%s", ss.c_str());
}
#line 1963 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 176:
#line 906 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {std::ostringstream s; s<<(yystack_[1].value.expression);
		if(Reader.MyLha.LinearForm.find(s.str())==Reader.MyLha.LinearForm.end())
		{int i=Reader.MyLha.LinearForm.size();Reader.MyLha.LinearForm[s.str()]=i;}
		Reader.MyLha.LhaFuncArg.push_back(Reader.MyLha.LinearForm[s.str()]);
		Reader.MyLha.LhaFuncType.push_back("Mean");
		string ss="Mean("; ss.append(s.str()); ss.append(")");
		if(Reader.MyLha.LhaFunction.find(ss)==Reader.MyLha.LhaFunction.end())
		{int i=Reader.MyLha.LhaFunction.size();Reader.MyLha.LhaFunction[ss]=i;}
		sprintf((yylhs.value.expression),"%s", ss.c_str());
}
#line 1978 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 177:
#line 917 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s", (yystack_[0].value.expression));  }
#line 1984 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 178:
#line 918 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s - %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 1990 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 179:
#line 919 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {sprintf((yylhs.value.expression),"%s + %s", (yystack_[2].value.expression), (yystack_[0].value.expression));  }
#line 1996 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 180:
#line 922 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"Vars->%s", (yystack_[0].value.name)->c_str());}
	else if(Reader.MyLha.PlaceIndex.find(*(yystack_[0].value.name))!=Reader.MyLha.PlaceIndex.end())
	{std::ostringstream s; s<<" Marking.P->_PL_"<< (yystack_[0].value.name)->c_str();
			if(Reader.MyLha.MyGspn->placeStruct[Reader.MyLha.PlaceIndex[*(yystack_[0].value.name)]].colorDom !=0 )s <<".card()";
		sprintf((yylhs.value.expression), "%s ",(s.str()).c_str());
	} else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable or a place name"<<endl;YYABORT;}
}
#line 2009 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 181:
#line 930 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    {
    if(Reader.MyLha.Vars.find(*(yystack_[3].value.name))!=Reader.MyLha.Vars.label.size()){
        sprintf((yylhs.value.expression),"Vars->%s[%s]", (yystack_[3].value.name)->c_str(), (yystack_[1].value.expression));
	} else {cout<<*(yystack_[3].value.name)<<" is not a Lha array variable "<<endl;YYABORT;}
}
#line 2019 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 182:
#line 938 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"(%s) * Vars->%s", (yystack_[3].value.expression), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2028 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 183:
#line 943 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"%d * Vars->%s", (yystack_[2].value.IntVal), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2037 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 184:
#line 948 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"%f * Vars->%s", (yystack_[2].value.RealVal), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2046 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 185:
#line 954 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { sprintf((yylhs.value.expression),"%i ", (yystack_[0].value.IntVal));
}
#line 2053 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 186:
#line 957 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { sprintf((yylhs.value.expression),"%f ", (yystack_[0].value.RealVal));}
#line 2059 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 187:
#line 960 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yystack_[2].value.name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yylhs.value.expression),"%f * Vars->%s", Reader.MyLha.LhaRealConstant[*(yystack_[2].value.name)],(yystack_[0].value.name)->c_str());
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yystack_[2].value.name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yylhs.value.expression),"Marking.P->_PL_%s * Vars->%s", (yystack_[2].value.name)->c_str() ,(yystack_[0].value.name)->c_str());
			}
			else
			{
				cout<<*(yystack_[2].value.name)<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}
}
#line 2082 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 188:
#line 979 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"-Vars->%s", (yystack_[0].value.name)->c_str());}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2090 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 189:
#line 983 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"-(%s) * Vars->%s", (yystack_[3].value.expression), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[1].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2099 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 190:
#line 988 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"-%d * Vars->%s", (yystack_[2].value.IntVal), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2108 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 191:
#line 993 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{sprintf((yylhs.value.expression),"-%f * Vars->%s", (yystack_[2].value.RealVal), (yystack_[0].value.name)->c_str());
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}}
#line 2117 "Lha-parser.cc" // lalr1.cc:847
    break;

  case 192:
#line 998 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:847
    { if(Reader.MyLha.Vars.find(*(yystack_[0].value.name))!=Reader.MyLha.Vars.label.size())
	{if(Reader.MyLha.LhaRealConstant.find(*(yystack_[2].value.name))!=Reader.MyLha.LhaRealConstant.end())
		{sprintf((yylhs.value.expression),"-%f * Vars->%s", Reader.MyLha.LhaRealConstant[*(yystack_[2].value.name)],(yystack_[0].value.name)->c_str());
		}
		else
		{
			if(Reader.MyLha.PlaceIndex.find(*(yystack_[2].value.name))!=Reader.MyLha.PlaceIndex.end())
			{sprintf((yylhs.value.expression),"-Marking.P->_PL_%s * Vars->%s", (yystack_[2].value.name)->c_str() ,(yystack_[0].value.name)->c_str());
			}
			else
			{
				cout<<*(yystack_[2].value.name)<<" is not Petri-net Place or a definded constant "<<endl;
				YYABORT;
			}
		}
	}
	else {cout<<*(yystack_[0].value.name)<<" is not a Lha variable"<<endl;YYABORT;}
}
#line 2140 "Lha-parser.cc" // lalr1.cc:847
    break;


#line 2144 "Lha-parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
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
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Lha_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Lha_parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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
         yyla.  (However, yyla is currently not documented for users.)
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
            // Stay within bounds of both yycheck and yytname.
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

    char const* yyformat = YY_NULLPTR;
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


  const short int Lha_parser::yypact_ninf_ = -261;

  const signed char Lha_parser::yytable_ninf_ = -1;

  const short int
  Lha_parser::yypact_[] =
  {
       6,    36,  -261,  -261,   115,    13,    47,  -261,    59,    68,
      76,    98,   105,  -261,  -261,   146,   -22,   322,    73,   114,
    -261,   101,   137,   115,   165,   155,   155,   174,   222,   228,
     155,   155,  -261,   223,   239,    90,   210,   219,   135,   261,
     262,   119,   250,   101,   229,   241,  -261,  -261,  -261,  -261,
     115,   115,   115,   115,   297,  -261,   155,   155,   286,   290,
     295,   305,   308,   314,   329,   355,   399,  -261,   405,   328,
     360,   365,   311,   316,   307,   335,   381,   382,  -261,   344,
     351,  -261,  -261,   403,   404,   347,   386,   101,  -261,  -261,
    -261,  -261,  -261,  -261,   148,   148,  -261,   410,   496,   155,
     155,   155,   200,   200,   200,   200,   200,  -261,   155,   155,
     155,   155,   155,  -261,   417,  -261,  -261,   133,   133,   446,
     453,   396,   411,  -261,  -261,   469,   471,     3,   492,  -261,
    -261,   422,   321,   327,    12,   467,   494,   233,   197,    19,
    -261,   244,   255,   263,   566,   468,   468,   496,   496,  -261,
     516,  -261,  -261,  -261,   527,   528,  -261,    -3,  -261,     4,
     542,   568,   233,   267,  -261,   534,     5,  -261,     9,  -261,
     155,   155,   267,   562,   576,   587,   569,  -261,  -261,   233,
     233,   582,   595,   596,   433,   509,   590,   591,   233,  -261,
     200,   200,  -261,  -261,  -261,  -261,  -261,   133,   133,   618,
     626,   630,   628,   632,     7,  -261,   627,   575,   568,     8,
     629,  -261,   267,   267,   633,   634,   635,   103,   636,    29,
     639,   638,   640,   438,   445,   301,  -261,  -261,  -261,   645,
     450,   535,   233,   233,   233,   609,   233,   233,   233,   233,
     233,   646,   647,   648,   461,  -261,  -261,   631,   644,  -261,
    -261,  -261,  -261,   649,   650,  -261,   651,   652,  -261,  -261,
     287,   120,    -8,   267,   267,   267,  -261,   267,   267,   267,
     267,   654,  -261,   657,  -261,  -261,  -261,  -261,  -261,  -261,
     653,   641,  -261,   473,   346,   352,   659,   623,   623,   535,
     535,  -261,  -261,  -261,  -261,   637,   133,   133,   225,  -261,
     655,  -261,   224,   577,   656,  -261,   478,   371,   387,   642,
      -8,    -8,  -261,   658,   660,   645,  -261,  -261,   233,   233,
    -261,   661,   662,   663,   225,   225,  -261,  -261,   594,   476,
    -261,   664,  -261,  -261,  -261,   267,   267,   267,  -261,   670,
    -261,   484,   489,  -261,  -261,  -261,   394,    72,  -261,   233,
     233,   233,   233,   233,   667,   671,   225,   225,   668,   552,
     556,   563,   669,  -261,  -261,  -261,   571,   571,   571,   571,
     571,   666,  -261,  -261,   665,   672,  -261,  -261,  -261,  -261,
     675,   121,  -261,    14,   233,   666,   673,  -261,   674,   676,
     677,  -261,   571,  -261,   678,   604,  -261,    10,   303,  -261,
    -261,   684,  -261,   679,   680,   681,   233,  -261,   358,   682,
     683,   428,  -261,  -261,   685,   688,   689,   501,   686,   687,
     690,   233,    22,   303,   233,   233,   233,   306,   306,  -261,
    -261,  -261,   691,   692,   693,   694,   512,  -261,   695,   696,
    -261,   571,   571,   571,  -261,  -261,   697,  -261,  -261,  -261,
     698,    42,    11,  -261,   699,  -261,   700,   267,   248,   695,
    -261,  -261,  -261,   586,   701,  -261,  -261,   248,   248,   702,
     704,   705,   599,  -261,   706,   645,   517,   546,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   709,  -261,   524,
     357,   362,   703,   703,   546,   546,  -261,   599,  -261,  -261,
     248,   248,   529,   540,  -261,  -261
  };

  const unsigned char
  Lha_parser::yydefact_[] =
  {
      54,     0,   160,   159,     0,     0,     0,   147,     0,     0,
       0,     0,     0,   148,   149,     0,     0,     0,    53,    52,
       3,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,    51,    50,   140,   142,
       0,     0,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    73,    74,     0,     0,     0,     0,     0,    56,     5,
      61,    62,   158,   157,   155,   156,   141,     0,   164,     0,
       0,     0,     0,     0,     0,     0,     0,   146,     0,     0,
       0,     0,     0,   153,     0,    60,    59,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     4,
     166,     0,     0,     0,   180,   186,   185,     0,     0,     0,
     177,     0,     0,     0,     0,   171,   170,   168,   169,   167,
       0,   145,   143,   144,     0,     0,    76,     0,    79,     0,
       0,     0,     0,     0,    64,     0,     0,    71,     0,   165,
       0,     0,     0,     0,     0,     0,    22,    20,    21,     0,
       0,     0,     0,     0,     0,   188,     0,     0,     0,   173,
       0,     0,   174,   172,   175,   176,   150,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,   104,     0,
       7,     6,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,   187,   184,   183,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   178,     0,     0,    77,
      75,    80,    78,     0,     0,    85,     0,     0,   105,    58,
       0,     0,    11,     0,     0,     0,    57,     0,     0,     0,
       0,     0,    67,     0,    63,    72,    70,   162,   163,   181,
       0,     0,    24,     0,     0,     0,     0,    26,    29,    27,
      28,    30,   192,   191,   190,     0,     0,     0,     0,    83,
       0,   103,     7,     0,     0,    10,     0,     0,     0,    14,
      12,    13,    15,     0,    68,    48,    23,    31,     0,     0,
     182,     0,     0,     0,     0,     0,    91,    92,     0,     0,
      93,     0,     9,     8,    16,     0,     0,     0,    66,     0,
      49,     0,     0,   189,   151,   152,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    96,    98,   100,    99,   101,
     102,     0,    87,    94,    95,     0,    17,    18,    19,    69,
       0,     0,    88,     0,     0,     0,     0,   107,   108,     0,
       0,   110,    90,    89,     0,     0,   112,     0,     0,    86,
     109,     0,   111,   123,     0,     0,     0,   116,     0,     0,
     114,     0,   120,   113,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     126,   125,     0,     0,     0,     0,     0,   134,     0,     0,
     115,   117,   119,   118,   122,   121,     0,   132,   131,   130,
       0,     0,     0,   135,     0,   124,     0,     0,     0,     0,
     133,   106,   129,     0,    36,    34,    35,     0,     0,     0,
       0,     0,   137,   136,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,    40,    43,    41,    42,    44,   138,    37,    45,
       0,     0,     0,     0,    46,    47
  };

  const short int
  Lha_parser::yypgoto_[] =
  {
    -261,  -261,  -261,  -152,  -137,  -260,  -258,  -261,   707,  -261,
     710,   708,   711,   712,  -261,   714,  -261,  -261,   713,  -261,
     715,  -261,  -261,   613,  -261,   490,  -261,   317,  -234,  -261,
     620,   493,  -261,  -261,   312,  -261,   294,  -261,  -261,  -217,
    -261,  -261,   259,   -17,  -261,  -117,    75,   -23,  -261,   140,
      71
  };

  const short int
  Lha_parser::yydefgoto_[] =
  {
      -1,    15,    16,   217,   328,   472,   281,    17,    41,    42,
      18,    19,    43,    44,   166,    45,   168,    35,    36,   157,
      37,   159,    78,    79,   204,   205,   381,   382,   329,   330,
      80,   207,   208,   390,   391,   397,   409,   410,   411,   412,
     439,   452,   453,    20,    21,   154,    22,    66,    67,   139,
     140
  };

  const unsigned short int
  Lha_parser::yytable_[] =
  {
     184,   155,   304,    68,    48,   199,   164,    72,    73,     1,
       2,     3,   201,   219,   259,     4,   203,   221,   401,   459,
     225,   267,    25,   172,   270,   209,    89,   387,   388,   189,
      33,    34,   272,    97,    98,   437,   236,   237,   238,   239,
     240,   173,   230,   231,     5,     6,     7,     8,   165,   190,
     191,   244,    23,   457,     9,    10,    26,   340,   458,   200,
     261,   262,    11,    12,    13,    14,   202,   220,    27,   254,
     129,   222,   402,   460,   273,   389,   131,   132,   133,    24,
     247,   248,   365,   438,    28,   145,   146,   147,   148,   149,
     347,   348,    29,   356,   357,   283,   284,   285,    54,   287,
     288,   289,   290,   291,     1,     2,     3,    30,   303,   266,
       4,   306,   307,   308,    31,   309,   310,   311,   312,     2,
       3,     9,   373,   374,     4,    92,    93,    94,    95,   385,
     305,   386,   267,   268,   269,   270,   151,   152,   153,     5,
       6,     7,     8,    49,    76,    77,    32,   223,   224,   267,
     268,   269,   270,     5,     6,     7,     8,    11,    12,    13,
      14,    83,    84,    10,    56,    50,    51,    52,    53,    39,
      40,    11,    12,    13,    14,    55,    50,    51,    69,   322,
     323,   341,   342,   359,   360,   361,    57,   346,    58,    59,
      60,    61,    62,    50,    51,    52,    53,    63,    64,    65,
     185,   186,   187,   134,   135,   136,   188,   476,   477,   137,
     444,   445,   366,   367,   368,   369,   370,   487,   489,   490,
     491,   492,   493,   494,   495,   496,   497,    70,   176,   177,
     178,   138,   315,    71,   324,   260,   176,   177,   178,    74,
     502,   503,   179,   141,   142,   143,   144,   392,   325,   326,
     327,   464,   465,   466,   192,    75,   180,   467,   181,   182,
     183,   245,   246,    34,   180,   193,   181,   182,   183,   417,
     210,    33,   211,   194,   190,   191,   212,    85,    86,   468,
      40,   469,   470,   471,   436,   190,   191,   441,   442,   443,
     302,    39,   211,   190,   191,    99,   212,    38,   213,   100,
     214,   215,   216,    96,   101,   463,   403,   404,   405,   403,
     404,   405,   406,   279,   102,   406,   407,   103,   213,   117,
     214,   215,   216,   104,   118,    50,    51,    52,    53,   170,
     267,   268,   269,   270,   408,   171,   114,   408,   105,   108,
     109,   110,   111,   112,   108,   109,   110,   111,   112,   108,
     109,   110,   111,   112,   318,   108,   109,   110,   111,   112,
     319,   418,   419,   420,   106,   500,   115,   421,   119,    38,
     501,   116,    39,    40,   236,   237,   238,   239,   240,   336,
     236,   237,   238,   239,   240,   481,   482,   483,   484,   485,
     481,   482,   483,   484,   485,   337,   120,   121,   122,    77,
     267,   268,   269,   270,   282,    76,   125,   126,   127,   107,
     349,   350,   351,   352,   353,   113,   267,   268,   269,   270,
     130,   150,   236,   237,   238,   239,   240,   108,   109,   110,
     111,   112,   169,   108,   109,   110,   111,   112,   108,   109,
     110,   111,   112,   235,   424,   425,   426,   128,   277,   156,
     108,   109,   110,   111,   112,   278,   158,   160,   427,   428,
     282,   236,   237,   238,   239,   240,   108,   109,   110,   111,
     112,   295,   161,   108,   109,   110,   111,   112,   236,   237,
     238,   239,   240,   317,   354,   162,   355,   163,   334,   236,
     237,   238,   239,   240,   363,   167,   174,   356,   357,   364,
     112,   236,   237,   238,   239,   240,   335,   267,   268,   269,
     270,   432,   236,   237,   238,   239,   240,   236,   237,   238,
     239,   240,   450,   175,   108,   109,   196,   488,   112,   236,
     237,   238,   239,   240,   499,   197,   198,   218,   241,   504,
     236,   237,   238,   239,   240,   481,   482,   483,   484,   485,
     505,   203,   481,   482,   483,   484,   485,   481,   482,   483,
     484,   485,   376,   236,   237,   226,   377,   240,   481,   482,
     483,   484,   485,   378,   481,   482,   195,   206,   485,   227,
     229,   267,   268,   269,   270,   267,   268,   269,   270,   332,
     228,   232,   267,   268,   269,   270,   190,   191,   474,   236,
     237,   238,   239,   240,   233,   234,   267,   268,   269,   270,
     349,   350,   351,   352,   353,   267,   268,   269,   270,   242,
     243,   249,   236,   237,   238,   239,   240,   481,   482,   483,
     484,   485,   250,   251,   252,   253,   256,   257,   286,   296,
     260,   275,   263,   264,   265,   274,   276,   271,   280,   292,
     293,   294,   297,   316,   300,   240,   299,   298,   301,   313,
     314,   315,   320,   331,   343,   389,   321,   358,   333,   380,
     338,   339,   344,   345,   270,   362,   371,   372,   375,   396,
     383,   379,   384,   394,   399,   398,   356,   413,   429,   395,
     422,   430,   431,   124,   255,   447,   448,   449,   451,   123,
     455,   258,   393,   462,   423,   461,   454,   400,   414,   415,
     416,   478,   475,   479,   480,   433,   434,   440,   473,   435,
     446,   498,   486,     0,     0,     0,    46,   456,     0,    47,
       0,     0,     0,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      82,    81,    87,     0,     0,     0,     0,    91,    90
  };

  const short int
  Lha_parser::yycheck_[] =
  {
     137,   118,   260,    26,    21,     8,     3,    30,    31,     3,
       4,     5,     8,     8,     6,     9,     9,     8,     8,     8,
     172,    29,     9,    11,    32,   162,    43,    13,    14,    10,
      52,    53,     3,    56,    57,    13,    28,    29,    30,    31,
      32,    29,   179,   180,    38,    39,    40,    41,    45,    30,
      31,   188,    16,    11,    48,    49,     9,   315,    16,    62,
     212,   213,    56,    57,    58,    59,    62,    62,     9,    62,
      87,    62,    62,    62,    45,    61,    99,   100,   101,     4,
     197,   198,    10,    61,    16,   108,   109,   110,   111,   112,
     324,   325,    16,    21,    22,   232,   233,   234,    23,   236,
     237,   238,   239,   240,     3,     4,     5,     9,   260,     6,
       9,   263,   264,   265,     9,   267,   268,   269,   270,     4,
       5,    48,   356,   357,     9,    50,    51,    52,    53,     8,
      10,    10,    29,    30,    31,    32,     3,     4,     5,    38,
      39,    40,    41,     6,    54,    55,     0,   170,   171,    29,
      30,    31,    32,    38,    39,    40,    41,    56,    57,    58,
      59,    26,    27,    49,     9,    28,    29,    30,    31,    50,
      51,    56,    57,    58,    59,    10,    28,    29,     4,   296,
     297,   318,   319,   335,   336,   337,    31,   324,    33,    34,
      35,    36,    37,    28,    29,    30,    31,    42,    43,    44,
       3,     4,     5,     3,     4,     5,     9,   467,   468,     9,
     427,   428,   349,   350,   351,   352,   353,   475,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     5,     3,     4,
       5,    31,     8,     5,     9,    11,     3,     4,     5,    16,
     500,   501,     9,   103,   104,   105,   106,   384,    23,    24,
      25,     3,     4,     5,    10,    16,    31,     9,    33,    34,
      35,   190,   191,    53,    31,    10,    33,    34,    35,   406,
       3,    52,     5,    10,    30,    31,     9,    16,    16,    31,
      51,    33,    34,    35,   421,    30,    31,   424,   425,   426,
       3,    50,     5,    30,    31,     9,     9,    47,    31,     9,
      33,    34,    35,     6,     9,   457,     3,     4,     5,     3,
       4,     5,     9,    12,     9,     9,    13,     9,    31,     8,
      33,    34,    35,     9,     8,    28,    29,    30,    31,     8,
      29,    30,    31,    32,    31,     8,     8,    31,     9,    28,
      29,    30,    31,    32,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,     8,    28,    29,    30,    31,    32,
       8,     3,     4,     5,     9,     8,     6,     9,    61,    47,
       8,     6,    50,    51,    28,    29,    30,    31,    32,     8,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,     8,    61,    16,    16,    55,
      29,    30,    31,    32,    10,    54,     3,     3,    61,    10,
      16,    17,    18,    19,    20,    10,    29,    30,    31,    32,
      10,     4,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    10,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,    16,    17,    18,    61,    10,     3,
      28,    29,    30,    31,    32,    10,     3,    61,    30,    31,
      10,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    10,    61,    28,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    10,     8,    16,    10,    16,    10,    28,
      29,    30,    31,    32,    10,     3,    29,    21,    22,    10,
      32,    28,    29,    30,    31,    32,    28,    29,    30,    31,
      32,    10,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    10,    29,    28,    29,    10,    10,    32,    28,
      29,    30,    31,    32,    10,     8,     8,     3,    29,    10,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      10,     9,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,    10,    28,    29,     3,    10,    32,    28,    29,
      30,    31,    32,    10,    28,    29,    10,     9,    32,     3,
      11,    29,    30,    31,    32,    29,    30,    31,    32,    12,
       3,     9,    29,    30,    31,    32,    30,    31,    12,    28,
      29,    30,    31,    32,     9,     9,    29,    30,    31,    32,
      16,    17,    18,    19,    20,    29,    30,    31,    32,    29,
      29,     3,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,     6,     3,     6,     3,     9,    62,    29,     8,
      11,     3,     9,     9,     9,     6,     6,    11,     3,     3,
       3,     3,     8,    12,     3,    32,     6,     8,     6,     5,
       3,     8,     3,     8,     3,    61,    29,     3,    12,     3,
      12,    11,    10,    10,    32,     5,     9,     6,    10,     3,
       8,    12,     7,    10,     6,     8,    21,     3,     3,    15,
       8,     3,     3,    80,   204,     3,     3,     3,     3,    79,
       3,   208,   385,     3,    21,     6,    10,   395,    29,    29,
      29,     9,    11,     9,     9,    29,    29,   423,   459,    29,
      29,    12,    16,    -1,    -1,    -1,    18,    29,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      37,    36,    41,    -1,    -1,    -1,    -1,    45,    44
  };

  const unsigned char
  Lha_parser::yystos_[] =
  {
       0,     3,     4,     5,     9,    38,    39,    40,    41,    48,
      49,    56,    57,    58,    59,    64,    65,    70,    73,    74,
     106,   107,   109,    16,   109,     9,     9,     9,    16,    16,
       9,     9,     0,    52,    53,    80,    81,    83,    47,    50,
      51,    71,    72,    75,    76,    78,    74,    73,   106,     6,
      28,    29,    30,    31,   109,    10,     9,    31,    33,    34,
      35,    36,    37,    42,    43,    44,   110,   111,   110,     4,
       5,     5,   110,   110,    16,    16,    54,    55,    85,    86,
      93,    83,    81,    26,    27,    16,    16,    75,    71,   106,
      78,    76,   109,   109,   109,   109,     6,   110,   110,     9,
       9,     9,     9,     9,     9,     9,     9,    10,    28,    29,
      30,    31,    32,    10,     8,     6,     6,     8,     8,    61,
      61,    16,    16,    93,    86,     3,     3,    61,    61,   106,
      10,   110,   110,   110,     3,     4,     5,     9,    31,   112,
     113,   112,   112,   112,   112,   110,   110,   110,   110,   110,
       4,     3,     4,     5,   108,   108,     3,    82,     3,    84,
      61,    61,    16,    16,     3,    45,    77,     3,    79,    10,
       8,     8,    11,    29,    29,    29,     3,     4,     5,     9,
      31,    33,    34,    35,    67,     3,     4,     5,     9,    10,
      30,    31,    10,    10,    10,    10,    10,     8,     8,     8,
      62,     8,    62,     9,    87,    88,     9,    94,    95,    67,
       3,     5,     9,    31,    33,    34,    35,    66,     3,     8,
      62,     8,    62,   110,   110,    66,     3,     3,     3,    11,
      67,    67,     9,     9,     9,    10,    28,    29,    30,    31,
      32,    29,    29,    29,    67,   113,   113,   108,   108,     3,
       6,     3,     6,     3,    62,    88,     9,    62,    94,     6,
      11,    66,    66,     9,     9,     9,     6,    29,    30,    31,
      32,    11,     3,    45,     6,     3,     6,    10,    10,    12,
       3,    69,    10,    67,    67,    67,    29,    67,    67,    67,
      67,    67,     3,     3,     3,    10,     8,     8,     8,     6,
       3,     6,     3,    66,    69,    10,    66,    66,    66,    66,
      66,    66,    66,     5,     3,     8,    12,    10,     8,     8,
       3,    29,   108,   108,     9,    23,    24,    25,    67,    91,
      92,     8,    12,    12,    10,    28,     8,     8,    12,    11,
      69,    67,    67,     3,    10,    10,    67,    91,    91,    16,
      17,    18,    19,    20,     8,    10,    21,    22,     3,    66,
      66,    66,     5,    10,    10,    10,    67,    67,    67,    67,
      67,     9,     6,    91,    91,    10,    10,    10,    10,    12,
       3,    89,    90,     8,     7,     8,    10,    13,    14,    61,
      96,    97,    67,    90,    10,    15,     3,    98,     8,     6,
      97,     8,    62,     3,     4,     5,     9,    13,    31,    99,
     100,   101,   102,     3,    29,    29,    29,    67,     3,     4,
       5,     9,     8,    21,    16,    17,    18,    30,    31,     3,
       3,     3,    10,    29,    29,    29,    67,    13,    61,   103,
      99,    67,    67,    67,   102,   102,    29,     3,     3,     3,
      10,     3,   104,   105,    10,     3,    29,    11,    16,     8,
      62,     6,     3,    66,     3,     4,     5,     9,    31,    33,
      34,    35,    68,   105,    12,    11,    68,    68,     9,     9,
       9,    28,    29,    30,    31,    32,    16,    69,    10,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    12,    10,
       8,     8,    68,    68,    10,    10
  };

  const unsigned char
  Lha_parser::yyr1_[] =
  {
       0,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    75,    75,    76,    77,    77,    77,    77,    77,    77,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      90,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    94,    94,    95,    96,    96,    96,
      96,    97,    98,    98,    99,    99,    99,   100,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   112,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113
  };

  const unsigned char
  Lha_parser::yyr2_[] =
  {
       0,     2,     3,     1,     4,     3,     1,     1,     4,     4,
       3,     2,     3,     3,     3,     3,     4,     6,     6,     6,
       1,     1,     1,     4,     3,     2,     3,     3,     3,     3,
       3,     4,     6,     6,     1,     1,     1,     4,     3,     2,
       3,     3,     3,     3,     3,     4,     6,     6,     2,     3,
       2,     2,     1,     1,     0,     1,     2,     6,     6,     4,
       4,     2,     2,     6,     1,     2,     5,     3,     4,     7,
       6,     1,     3,     2,     2,     6,     1,     3,     6,     1,
       3,     2,     2,     6,     1,     2,    10,     6,     1,     3,
       3,     1,     1,     1,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     6,     1,     2,    14,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     5,     3,     3,     3,     2,     6,
       4,     4,     4,     3,     1,     1,     3,     3,     6,     1,
       2,     4,     2,     1,     1,     1,     4,     1,     1,     1,
       6,    10,    10,     4,     3,     3,     3,     3,     3,     1,
       1,     1,     6,     6,     2,     4,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     1,     3,     3,
       1,     4,     5,     3,     3,     1,     1,     3,     2,     6,
       4,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
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
  "EXIST_TOK", "NOTALL_TOK", "NEG", "'{'", "'}'", "$accept", "LHA",
  "declarations", "IntMarkingFormula", "RealMarkingFormula",
  "RealVarMarkingFormula", "ColorClassList", "Sizes", "Constants",
  "Constant", "NbVariables", "NbLocations", "Lists", "VariablesList",
  "VLabels", "LocationsList", "LLabels", "InitFinal", "init", "iLLabels",
  "final", "fLLabels", "definitions", "LocationsDef", "LOCATIONS",
  "LOCATION", "FLOWS", "FLOW", "LogExpr", "CompExpr", "EdgesDef", "EDGES",
  "EDGE", "ACTIONS", "SetOfActions", "Actions", "CONSTRAINTS",
  "CONSTRAINT", "LinearExp", "term", "UPDATES", "Updates", "Update",
  "HaslExps", "HaslExp", "rorival", "TopHaslExp", "AlgExpr", "LhaFunc",
  "LinForm", "VarTerm", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Lha_parser::yyrline_[] =
  {
       0,   186,   186,   187,   189,   190,   197,   198,   213,   220,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     239,   240,   241,   253,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   271,   272,   273,   292,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   310,   311,
     313,   314,   315,   316,   317,   319,   320,   322,   331,   342,
     344,   346,   347,   349,   368,   376,   386,   397,   405,   413,
     422,   432,   436,   441,   442,   444,   446,   454,   459,   461,
     469,   478,   479,   483,   493,   494,   496,   507,   521,   522,
     523,   530,   531,   532,   533,   534,   535,   536,   538,   539,
     540,   541,   542,   547,   551,   552,   554,   579,   580,   581,
     585,   587,   589,   593,   598,   599,   600,   602,   607,   612,
     618,   619,   620,   622,   626,   631,   636,   641,   662,   666,
     671,   676,   681,   704,   710,   715,   716,   718,   723,   735,
     735,   737,   748,   761,   762,   763,   773,   777,   780,   783,
     786,   789,   804,   819,   830,   833,   836,   839,   842,   845,
     848,   852,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   866,   876,   886,   896,   906,   917,   918,   919,
     921,   930,   937,   942,   947,   953,   956,   959,   978,   982,
     987,   992,   997
  };

  // Print the state stack on the debug stream.
  void
  Lha_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Lha_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
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
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
    };
    const unsigned int user_token_number_max_ = 315;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // lha
#line 2942 "Lha-parser.cc" // lalr1.cc:1155
#line 1021 "../../../../src/ModelGenerator/LhaParser/Lha-parser.yy" // lalr1.cc:1156


void
lha::Lha_parser::error (const lha::Lha_parser::location_type& l,
const std::string& m)
{
	Reader.error (l, m);
}
