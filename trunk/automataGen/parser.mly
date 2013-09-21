%{
  open Type

%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME
%token TRUE FALSE
%token LPAR RPAR
%token LSQBRAK RSQBRAK
%token EOL
%token UNTIL
%token EVENTUALLY
%token NOT
%token EQ SG SL GE LE


%start main
%type <Type.formula> main

%%

main:
  expr EOL {$1}
;

expr:
  stateCondition UNTIL stateCondition {Until($1,$3) }
 | stateCondition UNTIL cmp floatexpr stateCondition {BoundedUntil($1,$3,$4,$5)}
 | EVENTUALLY stateCondition {Until(True,$2) }
 | EVENTUALLY cmp floatexpr stateCondition {BoundedUntil(True,$2,$3,$4) }
;

stateCondition:
  TRUE    {True}
 | FALSE   {False}
 | NOT stateCondition {Not($2)}
 | LPAR stateCondition RPAR {$2}
 | LPAR intexpr cmp intexpr RPAR { IntAtom($2,$3,$4) }
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
;

floatexpr:
  FLOAT  {Float($1)}
 | INT {Float(float_of_int $1)}
;
