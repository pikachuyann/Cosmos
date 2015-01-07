%{
  open Type
  open PrismType
%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME INTNAME BOOLNAME DOUBLENAME
%token <string> STRING
%token LPAR RPAR
%token PLUS MINUS MULT DIV
%token LSQBRAK RSQBRAK
%token EOL
%token SEMICOLON COLON PRIME COMMA
%token AND OR
%token NOT
%token BOOL TRUE FALSE
%token CONST
%token EQ SG SL GE LE
%token RANGE 
%token CTMC MODULE ENDMODULE INIT ENDINIT REWARDS ENDREWARDS FORMULA 
%token ARROW
%token EOF
%token INTKW DOUBLEKW
%token LABEL
%token FLOOR CEIL

%left OR
%left AND
%left NOT
%left EQ SG SL GE LE
%left PLUS MINUS
%left MULT DIV
%left LPAR RPAR

%start main
%type <PrismType.constdef*PrismType.prism_file> main
%type <intExpr> intexpr
%type <floatExpr> floatexpr

%%

main:
  CTMC defmod initrew labels EOF {($2)};

defmod:
  definition defmod { let (defi1,defd1) = $1 and ((defi2,defd2),modl) = $2 in 
		      ((defi1@defi2,defd1@defd2)  ,modl) }
  | modulelist defmod { let (defl,modl) = $2 in (defl,$1::modl) }
  | { (([],[]),[]) }
;

definition:
  CONST INTKW NAME EQ intexpr SEMICOLON { add_int $3; [($3,Some $5)] , [] }
  | CONST NAME EQ intexpr SEMICOLON     { add_int $2; [($2,Some $4)] , [] }
  | CONST DOUBLEKW NAME EQ floatexpr SEMICOLON { add_double $3; [], [($3,Some $5)] }
  | CONST INTKW NAME SEMICOLON  {         add_int $3; [($3,None)]    , []  }
  | CONST DOUBLEKW NAME SEMICOLON {       add_int $3; [], [($3,None)] }
;

modulelist:
  MODULE NAME varlist actionlist ENDMODULE {
    Full { name=$2;
      varlist=$3;
      actionlist=$4;
      actionset = find_action $4
    }
  }
  | MODULE NAME EQ NAME LSQBRAK renamelist RSQBRAK ENDMODULE {
    Renaming ($2,$4,$6)
  }
;

renamelist:
  NAME EQ NAME {[($1,$3)]}
  | NAME EQ NAME COMMA renamelist {($1,$3)::$5}
;

varlist:
  NAME COLON rangevar INIT TRUE SEMICOLON varlist 
  { ($1,$3,Int 1)::$7 }  
  | NAME COLON rangevar INIT FALSE SEMICOLON varlist 
      { ($1,$3,Int 0)::$7 }  
  | NAME COLON rangevar INIT intexpr SEMICOLON varlist 
      { ($1,$3,(simp_int $5))::$7 }
  | NAME COLON rangevar SEMICOLON varlist 
      { ($1,$3,(fst $3))::$5 }
| {[]}
;

rangevar:
  LSQBRAK intexpr RANGE intexpr RSQBRAK { ($2,$4) }
| BOOL { (Int 0,Int 1) }
;

actionlist:
  headaction stateCondition ARROW tailaction SEMICOLON actionlist
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
  NAME PRIME EQ intexpr {$1,simp_int $4}
| NAME PRIME EQ TRUE {$1,Int 1}
| NAME PRIME EQ FALSE {$1,Int 0}
;

initrew: 
  INIT TRUE ENDINIT initrew {()}
| REWARDS STRING actionrewardlist ENDREWARDS initrew {()}
| {()};


actionrewardlist:
LSQBRAK NAME RSQBRAK stateCondition COLON floatexpr SEMICOLON 
  {()}
| LSQBRAK RSQBRAK stateCondition COLON floatexpr SEMICOLON 
  {()}
|  stateCondition COLON floatexpr SEMICOLON 
  {()}
| {()};

stateCondition:
TRUE {True}
| FALSE {False}
| NAME { IntAtom(IntName $1,EQ,Int 1) }
| stateCondition AND stateCondition {And($1,$3)}
| stateCondition OR stateCondition {Or($1,$3)}
| NOT stateCondition {Not($2)}
| LPAR stateCondition RPAR {$2}
| NAME cmp intexpr  { IntAtom(IntName $1,$2,simp_int $3) }
;

intexpr:
  INT {Int($1)}
 | NAME {IntName($1)}
 | LPAR intexpr RPAR {$2}
 | intexpr PLUS intexpr {Plus($1,$3)}
 | intexpr MULT intexpr {Mult($1,$3)}
 | intexpr MINUS intexpr {Minus($1,$3)}
 | NOT intexpr {Minus(Int 1,$2)}
 | FLOOR LPAR floatexpr RPAR {Floor($3)}
 | CEIL LPAR floatexpr RPAR {Ceil($3)}
;



labels:
  LABEL STRING EQ stateCondition SEMICOLON labels{()}
| {()}
