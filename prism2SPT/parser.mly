%{
  open Type

  let find_action sl =
    List.fold_left (fun set (so,_,_,_) ->
    match so with None -> set
      | Some a -> StringSet.add a set) StringSet.empty sl

%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME
%token <string> STRING
%token LPAR RPAR
%token PLUS MINUS MULT DIV
%token LSQBRAK RSQBRAK
%token EOL
%token SEMICOLON COLON PRIME
%token AND OR
%token NOT
%token TRUE
%token CONST
%token EQ SG SL GE LE
%token RANGE
%token CTMC MODULE ENDMODULE INIT REWARDS ENDREWARDS
%token ARROW
%token EOF
%token INTKW DOUBLEKW
%token LABEL

%left OR
%left AND
%left NOT
%left EQ SG SL GE LE
%left PLUS MINUS
%left MULT DIV
%left LPAR RPAR

%start main
%type <Type.constdef*Type.prism_file> main
%type <intExpr> intexpr
%type <floatExpr> floatexpr

%%

main:
  CTMC defmod rewards labels EOF {($2)};

defmod:
  definition defmod { let (defl,modl) = $2 in (($1 defl),modl) }
  | modulelist defmod { let (defl,modl) = $2 in (defl,$1::modl) }
  | { (([],[]),[]) }
;

definition:
  CONST INTKW NAME EQ intexpr SEMICOLON { function (intl,doubll) -> 
						 ($3,Some $5)::intl , doubll }
  | CONST DOUBLEKW NAME EQ floatexpr SEMICOLON { function  (intl,doubll) ->
							intl, ($3,Some $5)::doubll }
  | CONST INTKW NAME SEMICOLON  { function  (intl,doubll) ->
					   ($3,None)::intl , doubll  }
  | CONST DOUBLEKW NAME SEMICOLON { function  (intl,doubll) ->
					       intl, ($3,None)::doubll }
;

modulelist:
  MODULE NAME varlist actionlist ENDMODULE {
    { name=$2;
      varlist=$3;
      actionlist=$4;
      actionset = find_action $4
    }
  }
;

varlist:
 NAME COLON LSQBRAK intexpr RANGE intexpr RSQBRAK INIT intexpr SEMICOLON varlist 
      { ($1,($4,$6),$9)::$11 }
| NAME COLON LSQBRAK intexpr RANGE intexpr RSQBRAK SEMICOLON varlist 
      { ($1,($4,$6),$4)::$9 }
| {[]}
;

actionlist:
  headaction guard ARROW tailaction SEMICOLON actionlist
  { List.fold_left (fun l (r,u) -> ($1,$2,r,u)::l) $6 $4}
| {[]}
;

headaction:
  LSQBRAK RSQBRAK {None}
| LSQBRAK NAME RSQBRAK {Some $2}
;

tailaction:
 update {[Float(1.0),$1]}
| floatexpr COLON update {[$1,$3]}
| floatexpr COLON update PLUS tailaction {($1,$3)::$5}
; 

floatexpr:
  INT {Float (float $1)}
| FLOAT {Float($1)}
| LPAR floatexpr RPAR {$2 }
| floatexpr MULT floatexpr {MultF($1,$3)}
| floatexpr PLUS floatexpr {PlusF($1,$3)}
| floatexpr MINUS floatexpr {MinusF($1,$3)}
| floatexpr DIV floatexpr {DivF($1,$3)}
| NAME {FloatName($1)}


guard:
TRUE   {[]}
| atom { [$1] }
| atom AND guard {$1::$3}
;

atom:
 NAME cmp intexpr {$1,$2,$3}

cmp:
  EQ {EQ}
 | SG {SG}
 | SL {SL}
 | GE {GE}
 | LE {LE}
 | NOT EQ {NEQ}
;


update:
  TRUE { [] } 
| LPAR upatom RPAR { [$2] }
| LPAR upatom RPAR AND update {$2::$5}
;

upatom:
  NAME PRIME EQ intexpr {$1,$4}
;

rewards:
  REWARDS STRING actionrewardlist ENDREWARDS rewards {()}
| {()}

actionrewardlist:
LSQBRAK NAME RSQBRAK stateCondition COLON floatexpr SEMICOLON 
  {()}
|  stateCondition COLON floatexpr SEMICOLON 
  {()}
| {()}

stateCondition:
TRUE {True}
| stateCondition AND stateCondition {And($1,$3)}
| stateCondition OR stateCondition {Or($1,$3)}
| NOT stateCondition {Not($2)}
| LPAR stateCondition RPAR {$2}
| intexpr cmp intexpr  { IntAtom($1,$2,$3) }
;

intexpr:
  INT {Int($1)}
 | NAME {IntName($1)}
 | LPAR intexpr RPAR {$2}
 | intexpr PLUS intexpr {Plus($1,$3)}
 | intexpr MULT intexpr {Mult($1,$3)}
 | intexpr MINUS intexpr {Minus($1,$3)}
;



labels:
  LABEL STRING EQ stateCondition SEMICOLON labels{()}
| {()}
