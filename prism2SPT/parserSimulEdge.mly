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
 | AFTER LPAR expr COMMA NAME RPAR action { if $7.trigger <> Imm then failwith "two trigger for this transition";
					    {$7 with trigger = Delay $3 }}; 

action:
  pre { {empty_trans_label with trigger = $1 } }
 | pre LBRAK post RBRAK { {$3 with trigger = $1} };

pre:
  NAME { RAction($1)} 
| { Imm };

post:
  NAME SEMICOLON post { {$3 with write = ($1)::($3.write) }; }
 | NAME EQ expr SEMICOLON post { {$5 with update = (Printf.sprintf "%s=%s" $1 $3)::($5.write) } }
 | SEND LPAR NAME COMMA NAME RPAR SEMICOLON post {  {$8 with write = ($3::($8.write)) } }
 | {empty_trans_label};
  

expr:
  NAME {$1}
 | expr PLUS expr {Printf.sprintf "%s+%s" $1 $3}
 | expr MULT expr {Printf.sprintf "%s*%s" $1 $3}
 | expr MINUS expr {Printf.sprintf "%s-%s" $1 $3}
 | NAME LPAR expr RPAR { Printf.sprintf "%s(%s)" $1 $3}
 | NAME LPAR expr COMMA expr RPAR { Printf.sprintf "%s(%s,%s)" $1 $3 $5};
 | NAME LPAR expr COMMA expr COMMA expr RPAR { Printf.sprintf "%s(%s,%s,%s)" $1 $3 $5 $7};
