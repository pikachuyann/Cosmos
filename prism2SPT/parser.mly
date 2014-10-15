%{

%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME
%token TRUE FALSE
%token LPAR RPAR
%token PLUS MINUS MULT DIV
%token LSQBRAK RSQBRAK
%token EOL
%token SEMICOLON COLON PRIME
%token AND OR
%token NOT
%token EQ SG SL GE LE
%token RANGE
%token CTMC MODULE ENDMODULE INIT
%token ARROW
%token EOF

%left OR
%left AND
%left NOT
%left EQ SG SL GE LE
%left PLUS MINUS
%left MULT
%left LPAR RPAR

%start main
%type <string * (string * (int*int) * int) list * ((string*string*int) list * float * (string*int) list) list > main

%%

main:
  CTMC moduleexp EOF {$2};

moduleexp:
  MODULE NAME varlist actionlist ENDMODULE {($2,$3,$4)};

varlist:
  NAME COLON LSQBRAK INT RANGE INT RSQBRAK INIT INT SEMICOLON 
  {[ $1,($4,$6),$9]}
| NAME COLON LSQBRAK INT RANGE INT RSQBRAK INIT INT SEMICOLON varlist 
      { ($1,($4,$6),$9)::$11 };


actionlist:
  LSQBRAK RSQBRAK guard ARROW FLOAT COLON update SEMICOLON 
  {[$3,$5,$7]}
| LSQBRAK RSQBRAK guard ARROW FLOAT COLON update SEMICOLON actionlist 
  {($3,$5,$7):: $9}
| LSQBRAK NAME RSQBRAK guard ARROW FLOAT COLON update SEMICOLON 
  {[$4,$6,$8]}
| LSQBRAK NAME RSQBRAK guard ARROW FLOAT COLON update SEMICOLON actionlist 
  {($4,$6,$8):: $10}
;

guard:
  atom { [$1] }
| atom AND guard {$1::$3}
;

atom:
  NAME EQ INT {$1,"=",$3}
| NAME NOT EQ INT {$1,"!=",$4}
| NAME SG INT {$1,">",$3}
| NAME SL INT {$1,"<",$3}
| NAME GE INT {$1,">=",$3}
| NAME LE INT {$1,"<=",$3};

update:
  LPAR upatom RPAR { [$2] }
| LPAR upatom RPAR AND update {$2::$5}
;

upatom:
  NAME PRIME EQ INT {$1,$4}
;
