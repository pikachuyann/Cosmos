open Type

type format = Prism | Pnml | Dot | Marcie | Simulink | Pdf | GrML

let input = ref stdin
let output = ref "out"
let inname = ref "stdin"
let typeFormat = ref Prism
let outputFormat = ref [GrML;Dot;Marcie]
let const_file = ref ""
let verbose = ref 1

let suffix_of_filename s =
  let fa = String.rindex s '.'+1 in
  (String.sub s 0  (fa -1)),(
  String.sub s fa (String.length s - fa))

let nbarg = ref 0

let _ = 
  Arg.parse ["--light",Arg.Set SimulinkType.lightSim,"light simulator";
	     "--pdf",Arg.Unit (fun () -> outputFormat:= Pdf:: !outputFormat),"Output as PDF";
	     "--prism",Arg.Unit (fun () -> outputFormat:= Prism:: !outputFormat),"Output in Prism File Format";
	     "--stoch",Arg.Set SimulinkType.modelStoch,"Use probabilistic delay";
	     "--no-erlang",Arg.Clear SimulinkType.useerlang,"Replace erlang distribution by exponentials";
	     "--erlang-step",Arg.Set_int SimulinkTrans.erlangstep,"Number of erlang step for stochastic model";
	     "-v",Arg.Set_int verbose,"Set verbose level default 1";
	    ]
    (function s -> incr nbarg; match !nbarg with
      1 -> inname:= s;
	( let o,suf = suffix_of_filename s in 
	  output := o;
	  match suf with
	  "sm" | "pm" -> typeFormat := Prism
	| "pnml" -> typeFormat := Pnml
	| "slx" -> 
	  typeFormat := Simulink;
	  const_file := "const.m"
	| _-> failwith "Unsupported file format"
	)
    | 2 -> output := s
    | _ -> failwith "Do not know what to do with extra arguments.") 
    "usage";;
  
(*if Array.length Sys.argv <>2 then
  outputFormat := (List.filter (fun x -> x<>Pdf && x <> Dot) !outputFormat);;
*)

let _ =
  if !verbose>1 then begin
    Printf.printf "Verbose level: %i\n" !verbose;
    Printf.printf "Light Sim: %b\n" !SimulinkType.lightSim;
    Printf.printf "Stochastic transition: %b\n" !SimulinkType.modelStoch;
    Printf.printf "Use Erlang: %b\n" !SimulinkType.useerlang;
  end;

logout := open_out (!output^".log");;

let _ =
  print_endline ("Opening "^ !inname);
  begin match !typeFormat with
  | Prism -> 
    
    if 0=Sys.command (Printf.sprintf "prism %s -exportprism %s.expanded  -nobuild > /dev/null" !inname !inname)
    then inname := !inname ^ ".expanded";
    input := open_in !inname;
    Generator.read_prism !input !inname
  | Pnml ->
    IFNDEF HASXML THEN
      failwith "XML library required to read PNML" 
      ELSE 
  let xmlf = Pnmlparser.tree_of_pnml !inname in
  let net = PetriNet.Net.create () in
  Pnmlparser.net_of_tree net xmlf;
  net
    ENDIF
  | Simulink -> 
    IFNDEF HAS_XML THEN
      failwith "XML library required to read Simulink file" 
      ELSE IFNDEF HAS_ZIP THEN
      failwith "ZIP library required to read Simulink file" 
      ELSE
      begin 
	Zip.open_in !inname
	|> (fun z -> Zip.find_entry z "simulink/blockdiagram.xml"
	       |> Zip.read_entry z)
	|> Xml.parse_string 
	|> (Simulinkparser.modulist_of_tree [])
	|> SimulinkTrans.expand_trans
	|> List.map SimulinkTrans.flatten_module
	(*|> List.map Simulinkparser.flatten_state_ssid*)
	|< List.iter (SimulinkType.print_module !logout)
	|> List.map SimulinkTrans.incr_state
	|> SimulinkTrans.find_combinaison
	|< (fun x -> if List.mem Prism !outputFormat then
	    x |> SimulinkTrans.print_prism_module ((!output)^".sm") !const_file)
	|> List.map SimulinkTrans.prune_unread2
      	|> (fun x -> List.fold_left SimulinkTrans.combine_modu2 (List.hd x) (List.tl x))
	|> SimulinkTrans.expand_trans2
    (*|> (fun x->Simulinkparser.print_simulink_dot2 ((!output)^".dot") [x])*)
    (*|< Simulinkparser.prune*) 
	|> SimulinkTrans.stochNet_of_modu !const_file
	|> (fun x-> if !SimulinkType.useerlang then x else StochasticPetriNet.remove_erlang x)
      end
      ENDIF
      ENDIF   
  | _ -> failwith "Output format not yet supported" end
	      |> (fun net -> 
		print_endline "Finish parsing, start writing";
		List.iter (function 
	        | Dot ->
		  StochasticPetriNet.print_spt_dot ((!output)^".dot") net [] []
		| Pdf -> 
		  StochasticPetriNet.print_spt_dot ((!output)^".dot") net [] [];
		  ignore @@ Sys.command (Printf.sprintf "dot -Tpdf %s.dot -o %s.pdf" !output !output)
		| GrML ->
		  StochasticPetriNet.print_spt ((!output)^".grml") net
		| Marcie -> 
		  StochasticPetriNet.print_spt_marcie ((!output)^".andl") net
		| Prism when !typeFormat = Simulink -> ()
		| _ -> print_endline "Output format not supported"
		) !outputFormat;
		print_endline "Finish writing.";
	      );;
