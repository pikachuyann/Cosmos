open Xml
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
  try while true do
      begin try
	      let e = Parser.parseCmd Lexer.token lexbuf in
	      begin match e with
		  ParseInt(ei) -> Printf.fprintf stdout "#%a#%a#" printH_expr ei 
		    StochPTPrinter.print_expr ei
		| XMLInt(xi) ->
		  let ei = 
		    xi
		|> Xml.parse_string
		|> GrMLParser.parse_Grml_expr (Int 0) in
		  begin match ei with
		      None -> ()
		    | Some e -> let e2 = eval e in
				Printf.fprintf stdout "#%a#%a#" printH_expr e2 
				  StochPTPrinter.print_expr e2
		  end
		| _ -> raise End_of_file
	      end
	with 
	  | SyntaxError msg ->
	    Printf.printf "%a: %s\n" print_position lexbuf msg;
	  | Parsing.Parse_error ->
	    Printf.printf "%a: Parsing error: unexpected token:'%s'\n"
	      print_position lexbuf (lexeme lexbuf);
      end;
      print_newline();
    done;
  with
      _ ->exit 0;;

allInt:=true;;

parse_expr stdin "stdin"
