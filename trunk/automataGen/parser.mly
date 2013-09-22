%{
  open Type

%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME
%token TRUE FALSE
%token LPAR RPAR
%token PLUS MINUS MULT DIV
%token LSQBRAK RSQBRAK
%token EOL
%token SEMICOLON
%token UNTIL
%token EVENTUALLY
%token FUTURE
%token AND OR
%token NOT
%token EQ SG SL GE LE

%left OR
%left AND
%left NOT
%left EQ SG SL GE LE
%left PLUS MINUS
%left MULT
%left LPAR RPAR

%start main
%type <Type.formula> main

%%

main:
  expr EOL {$1}
;

expr:
  stateCondition UNTIL stateCondition {Until($1,$3) }
 | stateCondition UNTIL LE floatexpr stateCondition {BoundedUntil($1,Float(0.0),$4,$5)}
 | stateCondition UNTIL SL floatexpr stateCondition {BoundedUntil($1,Float(0.0),$4,$5)}
 | stateCondition UNTIL EQ floatexpr stateCondition {BoundedUntil($1,$4,$4,$5)}
 | stateCondition UNTIL SG floatexpr stateCondition {BoundedUntil($1,$4,Infty,$5)}
 | stateCondition UNTIL GE floatexpr stateCondition {BoundedUntil($1,$4,Infty,$5)}
 | stateCondition UNTIL LSQBRAK floatexpr SEMICOLON floatexpr RSQBRAK stateCondition
     {BoundedUntil($1,$4,$6,$8)}
 | EVENTUALLY stateCondition {Until(True,$2) }
 | EVENTUALLY LE floatexpr stateCondition {BoundedUntil(True,Float(0.0),$3,$4) }
 | EVENTUALLY SL floatexpr stateCondition {BoundedUntil(True,Float(0.0),$3,$4)}
 | EVENTUALLY EQ floatexpr stateCondition {BoundedUntil(True,$3,$3,$4)}
 | EVENTUALLY SG floatexpr stateCondition {BoundedUntil(True,$3,Infty,$4)}
 | EVENTUALLY GE floatexpr stateCondition {BoundedUntil(True,$3,Infty,$4)}
 | EVENTUALLY LSQBRAK floatexpr SEMICOLON floatexpr RSQBRAK stateCondition
     {BoundedUntil(True,$3,$5,$7)}
 | FUTURE floatexpr stateCondition {Future($2,$3)}
;

stateCondition:
  TRUE    {True}
 | FALSE   {False}
 | stateCondition AND stateCondition {And($1,$3)}
 | stateCondition OR stateCondition {Or($1,$3)}
 | NOT stateCondition {Not($2)}
 | LPAR stateCondition RPAR {$2}
 | intexpr cmp intexpr  { IntAtom($1,$2,$3) }
;

cmp:
  EQ {EQ}
 | SG {SG}
 | SL {SL}
 | GE {GE}
 | LE {LE}
;
  
intexpr:
  INT {Int($1)}
 | NAME {IntName($1)}
 | LPAR intexpr RPAR {$2}
 | intexpr PLUS intexpr {Plus($1,$3)}
 | intexpr MULT intexpr {Mult($1,$3)}
 | intexpr MINUS intexpr {Minus($1,$3)}
;

floatexpr:
  FLOAT  {Float($1)}
 | INT {Float(float_of_int $1)}
;
