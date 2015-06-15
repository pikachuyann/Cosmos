open Type
open PrismType
open PetriNet
open Lexer
open Lexing


let print_position outx lexbuf =
  let pos = lexbuf.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1);;

let parse_expr s name =
  let lexbuf = Lexing.from_channel s in
  lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = name };
  try
    let e = Parser.intexpr Lexer.token lexbuf in
    StochPTPrinter.print_expr stdout (eval e) 
  with 
  | SyntaxError msg ->
    Printf.fprintf stderr "%a: %s\n" print_position lexbuf msg;
    failwith "Fail to parse Prism file format"
  | Parsing.Parse_error ->
    Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s'\n"
      print_position lexbuf (lexeme lexbuf);
    failwith "Fail to parse Prism file format";;

allInt:=true;;

parse_expr stdin "stdin"
