open Type

type format = Prism | Pnml | Dot | Marcie | Simulink | Pdf | GrML | CLess

let input = ref stdin
let output = ref "out"
let inname = ref "stdin"
let typeFormat = ref Prism
let outputFormat = ref [Dot;Marcie]
let const_file = ref ""
let verbose = ref 1
let inHibitor = ref true
let traceSize = ref 0
let simule = ref 0
let statespace = ref false
		    
let suffix_of_filename s =
  let fa = String.rindex s '.'+1 in
  (String.sub s 0  (fa -1)),(
  String.sub s fa (String.length s - fa))

let nbarg = ref 0

	       
let _ = 
  Arg.parse ["--light",Arg.Set SimulinkType.lightSim,"light simulator";
	     "--pdf",Arg.Unit (fun () -> outputFormat:= Pdf:: !outputFormat),"Output as PDF";
	     "--prism",Arg.Unit (fun () -> outputFormat:= Prism:: !outputFormat),"Output in Prism File Format";
	     "--pnml",Arg.Unit (fun () -> outputFormat:= Pnml:: !outputFormat),"Output in Pnml File Format";
	     "--grml",Arg.Unit (fun () -> outputFormat:= GrML:: !outputFormat),"Output in Pnml File Format";
	     "--andl",Arg.Unit (fun () -> outputFormat:= Marcie:: !outputFormat),"Output in Marcie File Format";
	     "--stoch",Arg.Set SimulinkType.modelStoch,"Use probabilistic delay";
	     "--trace",Arg.Set_int traceSize, "Generate a trace of the model";
	     "--simule",Arg.Set_int simule, "Simulate trajectories";
	     "--state-space", Arg.Set statespace, "Compute state space of the model";
	     "--no-erlang",Arg.Clear SimulinkType.useerlang,"Replace erlang distribution by exponentials";
	     "--no-imm",Arg.Set SimulinkType.doremoveImm,"Remove Instantaneous transition in prims model";
	     "--no-inhib",Arg.Clear inHibitor,"Remove inhibitor arcs";
	     "--erlang-step",Arg.Set_int SimulinkTrans.erlangstep,"Number of erlang step for stochastic model";
	     "-v",Arg.Set_int verbose,"Set verbose level default 1";
	     "--add-reward",Arg.Set SimulinkType.add_reward, "Add reward transition to each non immediate transition";
	    ]
    (function s -> incr nbarg; match !nbarg with
      1 -> inname:= s;
	( let o,suf = suffix_of_filename s in 
	  output := o;
	  match suf with
	    "sm" | "pm" | "nm" | "prism" -> typeFormat := Prism
	    | "c" -> typeFormat := CLess
	| "pnml" -> typeFormat := Pnml
	| "slx" -> 
	  typeFormat := Simulink;
	  const_file := "const.m"
	| "gml" | "grml" -> typeFormat := GrML
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
    let s = Printf.sprintf "./prism %s -exportprism %s.expanded  -nobuild > /dev/null" !inname !inname in
    Printf.printf "Using prism to expand file :%s\n" s;
    if( Sys.command s = 0) then
      inname := !inname ^ ".expanded"
    else Printf.printf "Fail to start prism to expand the file\n";
    input := open_in !inname;
    Generator.read_prism !input !inname
  | Pnml ->
     (*IFNDEF HAS_XML THEN
      failwith "XML library required to read PNML" 
      ELSE*)
      let xmlf = Pnmlparser.tree_of_pnml !inname in
	  let net = PetriNet.Net.create () in
	  let open StochasticPetriNet in
	  net.PetriNet.Net.def <- Some {intconst=[]; floatconst=[]; clock=[]; printer = (fun _ _ -> ()); };
	  Pnmlparser.net_of_tree net xmlf;
	  net
  (* ENDIF *)
  | GrML ->
  (*  IFNDEF HAS_XML THEN
      failwith "XML library required to read GrML" 
      ELSE *)
  let xmlf = GrMLParser.tree_of_pnml !inname in
      let net = PetriNet.Net.create () in
       let open StochasticPetriNet in
       net.PetriNet.Net.def <- (Some {
				 intconst=[];
				 floatconst=[];
				 clock=[];
				 printer = (fun _ _ -> ())
			       });
      GrMLParser.net_of_tree net xmlf;
  net
  (* ENDIF *)
  | Simulink -> 
   (* IFNDEF HAS_XML THEN
      failwith "XML library required to read Simulink file" 
      ELSE IFNDEF HAS_ZIP THEN
      failwith "ZIP library required to read Simulink file" 
      ELSE*)
      begin 
	Zip.open_in !inname
	|> (fun z -> (
	    try Zip.find_entry z "simulink/stateflow.xml"
	    with Not_found -> Zip.find_entry z "simulink/blockdiagram.xml")
		     |> Zip.read_entry z)
	|> Xml.parse_string
	|> Simulinkparser.modulist_of_tree []
	|> SimulinkTrans.expand_trans
	|> List.map SimulinkTrans.flatten_module
	(*|> List.map SimulinkTrans.flatten_state_ssid*)

	|< List.iter (SimulinkType.print_module !logout)
	|> List.map SimulinkTrans.incr_state
	|> SimulinkTrans.find_combinaison
	|< (fun x -> if List.mem Prism !outputFormat then
	    x 
	       |> (fun x -> if !SimulinkType.doremoveImm then 
		   List.map SimulinkTrans.removeImm x else x)
	       |> SimulinkTrans.print_prism_module ((!output)^".sm") !const_file)
	|> List.map SimulinkTrans.prune_unread2
      	|> (fun x -> List.fold_left SimulinkTrans.combine_modu2 (List.hd x) (List.tl x))
	|> SimulinkTrans.expand_trans2
    (*|> (fun x->Simulinkparser.print_simulink_dot2 ((!output)^".dot") [x])*)
    (*|< Simulinkparser.prune*) 
	|> SimulinkTrans.stochNet_of_modu !const_file
      end
     (* ENDIF
      ENDIF *)
  | CLess -> 
     let ast = try
	 Cless.expr_list_of_file !inname
	 |< (fun x ->ignore (List.fold_left Cless2PT.sanity StringMap.empty x))
       with
       | Cless_ast.Parse_error(l,m) as x -> Cless.print_location Format.std_formatter l;
					    print_endline m;
					    raise x
       | Cless2PT.Type_error(l,m) as x -> Cless.print_location Format.std_formatter l;
				 print_endline m;
				 raise x;
     in
	     let net = PetriNet.Net.create () in
	     let pstart = PetriNet.Net.add_place net ("PSTA") (Int(1),Some (Int(1))) in
	     let pend = PetriNet.Net.add_place net ("PEND") (Int(0),Some (Int(1))) in
     ignore(Cless2PT.build_spt_list net StringMap.empty pstart pend ast);
     net
  | _ -> failwith "Input format not yet supported" end
  |< (fun _-> print_endline "Finish parsing, start transformation")
  |> (fun x-> if !SimulinkType.useerlang then x else StochasticPetriNet.remove_erlang x)
  (*|> (fun x-> if !add_reward then StochasticPetriNet.add_reward_struct x; x)*)
  |< (fun net -> if !statespace then let n = List.length (Simulation.SemanticSPT.state_space net) in
				   Printf.printf  "State-space size:%i\n" n)
  |< (fun net -> if !simule<> 0 then let open Simulation.SemanticSPT in
				     Printf.printf "Simulate %n trajectories:\n" !simule;
				     let nbsucc =
				       simulate net !simule
				       |> List.filter (function Some true -> true |_-> false)
				       |> List.length in
				     Printf.printf "Result: %f\n" ((float nbsucc) /. (float !simule)))
  |< (fun net -> if !traceSize <> 0 then let open Simulation.SemanticSPT in
     try
	print_endline "Trace:";
	let m0 = init net in	  
	print_marking net stdout m0;
	print_newline ();
	(*let en = enabled net m0 in
	List.iter (fun t -> print_endline (fst (PetriNet.Data.acca net.PetriNet.Net.transition t))) en;*)
	let l,result = trace  net m0 !traceSize in
	List.iter (fun (en,t,m) ->
		   let pt x = (fst (PetriNet.Data.acca net.PetriNet.Net.transition x)) in
		   print_string "{";
		   List.iter (fun x -> Printf.printf "%s, " (pt x)) en;
		   print_string "}->";
		   print_endline (pt t);
		   print_marking net stdout m;
		   print_newline ()) l;
	match result with
	  None -> print_endline "Unfinished trajectory"
	| Some(true) -> print_endline "Accepting trajectory"
	| Some(false) -> print_endline "Rejecting trajectory"
      with
	Illegal_fire(tr,(pm,_),v) ->
	let tn,_ = PetriNet.Data.acca net.PetriNet.Net.transition tr in
	Printf.printf "tr:%s m:%a v:%a\n" tn printH_expr pm printH_expr v)
  |> (fun x -> if !inHibitor then x else StochasticPetriNet.remove_inhibitor x)
  |> (fun net -> 
      print_endline "Finish transformation, start writing";
      List.iter (function 
      | Dot ->
	StochPTPrinter.print_spt_dot ((!output)^".dot") net [] []
      | Pdf -> 
	StochPTPrinter.print_spt_dot ((!output)^".dot") net [] [];
	ignore @@ Sys.command (Printf.sprintf "dot -Tpdf %s.dot -o %s.pdf" !output !output)
      | GrML ->
	StochPTPrinter.print_spt ((!output)^".grml") net
      | Pnml ->
	 net
	 |> StochPTPrinter.print_pnml ((!output)^".pnml")
      | Marcie -> 
	StochPTPrinter.print_spt_marcie ((!output)^".andl") net
      | Prism when !typeFormat = Simulink -> ()
      | _ -> print_endline "Output format not supported"
      ) !outputFormat;
      print_endline "Finish writing.";
    );;
