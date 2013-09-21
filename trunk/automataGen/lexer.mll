{
  open Parser
  exception Eof
}
rule token = parse
    [' ' '\t']    {token lexbuf}
    | ['\n']      {EOL}
    | ['0'-'9']+ as lxm  {INT(int_of_string lxm)}
    | ['0'-'9']+['.']['0'-'9']+ as lxm  {FLOAT(float_of_string lxm)}
    | "TRUE" | "True" | "true"  {TRUE} 
    | "FALSE" | "False" | "false"  {FALSE} 
    | '(' {LPAR}
    | ')' {RPAR}
    | '[' {LSQBRAK}
    | ']' {RSQBRAK}
    | 'U' {UNTIL}
    | 'E' {EVENTUALLY}
    | '!' {NOT}
    | '=' {EQ}
    | '<' {SL}
    | '>' {SG}
    | "<=" {LE}
    | ">=" {GE}
    | eof  {raise Eof}
    | ['a'-'z' 'A'-'Z'] ['a'-'z' 'A'-'Z' '_' '0'-'9']* as lxm {NAME(lxm)}
