open Automata

let _ =
  try
    let lexbuf = Lexing.from_channel stdin in
    while true do
      try
	let result = Parser.main Lexer.token lexbuf in
	print_string "%Initial formula:";
	Type.print_formula result;
	print_newline ();
	let a = Automata.automata_of_formula result in
	Writer.writeAutomata a;
	print_newline ();
      with Parsing.Parse_error -> print_endline "Fail to parse!"
    done
  with Lexer.Eof ->
    exit 0
