{
  open Parser
}
rule token = parse
    [' ' '\t' '\n' '\r']    {token lexbuf}
  | ['/']['/'][^'\n']*['\n']    {token lexbuf}
    | ['0'-'9']+ as lxm  { INT(int_of_string lxm)}
    | ['0'-'9']*['.']?['0'-'9']+(['e' 'E']['-' '+']?['0'-'9']+)? as lxm  {FLOAT(float_of_string lxm)}
    | "TRUE" | "True" | "true"  {TRUE} 
    | "FALSE" | "False" | "false"  {FALSE} 
    | "ctmc" | "dtmc" {CTMC}
    | "int" {INTKW}
    | "double" {DOUBLEKW}
    | "const" {CONST}
    | "module" {MODULE}
    | "endmodule" {ENDMODULE}
    | "init" {INIT}
    | ".." {RANGE}
    | "'" {PRIME}
    | '(' {LPAR}
    | ')' {RPAR}
    | '+' {PLUS}
    | '-' {MINUS}
    | '*' {MULT}
    | '/' {DIV}
    | '[' {LSQBRAK}
    | ']' {RSQBRAK}
    | ';' {SEMICOLON}
    | '!' {NOT}
    | '&' {AND}
    | '|' {OR}
    | '=' {EQ}
    | '<' {SL}
    | '>' {SG}
    | "<=" {LE}
    | ">=" {GE}
    | "->" {ARROW}
    | ":" {COLON}
    | eof  {EOF}
    | ['a'-'z' 'A'-'Z'] ['a'-'z' 'A'-'Z' '_' '0'-'9']* as lxm {NAME(lxm)}
