%{
  open Type
%}

%token <int> INT
%token <float> FLOAT
%token <string> NAME INTNAME BOOLNAME DOUBLENAME
%token <string> STRING
%token LPAR RPAR
%token PLUS MINUS MULT DIV
%token LSQBRAK RSQBRAK
%token LBRAK RBRAK
%token EOL
%token SEMICOLON COLON PRIME COMMA
%token AND OR
%token NOT
%token BOOL TRUE FALSE
%token CONST
%token EQ SG SL GE LE
%token CTMC MODULE ENDMODULE INIT ENDINIT REWARDS ENDREWARDS FORMULA 
%token ARROW
%token EOF
%token INTKW DOUBLEKW
%token LABEL
%token SEND AFTER
%token EXP

%left OR
%left AND
%left NOT
%left EQ SG SL GE LE
%left PLUS MINUS
%left MULT DIV
%left LPAR RPAR

%start main
%type <Type.simulink_trans_label> main

%%

main:
  action EOF { $1 }
 | AFTER LPAR floatexpr COMMA NAME RPAR action { if $7.trigger <> Imm then failwith "two trigger for this transition";
					    {$7 with trigger = Delay ($3) }}; 

action:
  pre { {empty_trans_label with trigger = $1 } }
 | pre LBRAK post RBRAK { {$3 with trigger = $1} };

pre:
  NAME { RAction($1)} 
| { Imm };

post:
  NAME SEMICOLON post { {$3 with write = ($1)::($3.write) }; }
 | NAME EQ expr SEMICOLON post { {$5 with update = (Printf.sprintf "%s=%s" $1 $3)::($5.update) } }
 | SEND LPAR NAME COMMA NAME RPAR SEMICOLON post {  {$8 with write = ($3::($8.write)) } }
 | {empty_trans_label};
  

expr:
  NAME {$1}
 | INT {Printf.sprintf "%i" $1}
 | FLOAT {Printf.sprintf "%f" $1}
 | expr PLUS expr {Printf.sprintf "%s+%s" $1 $3}
 | expr MULT expr {Printf.sprintf "%s*%s" $1 $3}
 | expr MINUS expr {Printf.sprintf "%s-%s" $1 $3}
 | LPAR expr RPAR { Printf.sprintf "(%s)" $2}
 | NAME LPAR expr RPAR { Printf.sprintf "%s(%s)" $1 $3}
 | NAME LPAR expr COMMA expr RPAR { Printf.sprintf "%s(%s,%s)" $1 $3 $5};
 | NAME LPAR expr COMMA expr COMMA expr RPAR { Printf.sprintf "%s(%s,%s,%s)" $1 $3 $5 $7};


floatexpr:
  INT {Float (float $1)}
| FLOAT {Float($1)}
| LPAR floatexpr RPAR {$2 }
| floatexpr MULT floatexpr {MultF($1,$3)}
| floatexpr PLUS floatexpr {PlusF($1,$3)}
| MINUS floatexpr {MinusF(Float 0.0,$2)}
| floatexpr MINUS floatexpr {MinusF($1,$3)}
| floatexpr DIV floatexpr {DivF($1,$3)}
| NAME {FloatName($1)}
| EXP LPAR floatexpr RPAR {ExpF($3)};
