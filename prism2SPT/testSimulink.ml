open Type

type format = Simulink | Prism | Pnml | Dot | Marcie | Stateflow | Pdf | GrML | CLess

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
  Arg.parse ["--light",Arg.Set StateflowType.lightSim,"light simulator";
             "--pdf",Arg.Unit (fun () -> outputFormat:= Pdf:: !outputFormat),"Output as PDF";
             "--prism",Arg.Unit (fun () -> outputFormat:= Prism:: !outputFormat),"Output in Prism File Format";
             "--pnml",Arg.Unit (fun () -> outputFormat:= Pnml:: !outputFormat),"Output in Pnml File Format";
             "--grml",Arg.Unit (fun () -> outputFormat:= GrML:: !outputFormat),"Output in Pnml File Format";
             "--andl",Arg.Unit (fun () -> outputFormat:= Marcie:: !outputFormat),"Output in Marcie File Format";
             "--stoch",Arg.Set StateflowType.modelStoch,"Use probabilistic delay";
             "--trace",Arg.Set_int traceSize, "Generate a trace of the model";
             "--simule",Arg.Set_int simule, "Simulate trajectories";
             "--state-space", Arg.Set statespace, "Compute state space of the model";
             "--no-erlang",Arg.Clear StateflowType.useerlang,"Replace erlang distribution by exponentials";
             "--no-imm",Arg.Set StateflowType.doremoveImm,"Remove Instantaneous transition in prims model";
             "--no-inhib",Arg.Clear inHibitor,"Remove inhibitor arcs";
             "--erlang-step",Arg.Set_int StateflowTrans.erlangstep,"Number of erlang step for stochastic model";
             "-v",Arg.Set_int verbose,"Set verbose level default 1";
             "--add-reward",Arg.Set StateflowType.add_reward, "Add reward transition to each non immediate transition";
             "--mdp-strat", Arg.Set_string Simulation.mdpstrat, "MDP strategy load/save file";
             "--mdp-det-strat", Arg.Set Simulation.detstrat, "Use deterministic strategy"
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
          typeFormat := Stateflow;
          const_file := "const.m"
        | "gml" | "grml" -> typeFormat := GrML
        | _-> failwith "Unsupported file format"
        )
    | 2 -> output := s
    | _ -> failwith "Do not know what to do with extra arguments.")
    "usage";;

let _ =
	Zip.open_in !inname
	|> (fun z -> (
	try Zip.find_entry z "simulink/blockdiagram.xml"
	with Not_found -> Zip.find_entry z "simulink/stateflow.xml")
	|> Zip.read_entry z)
	|> Xml.parse_string
	|> Simulinkparser.blocklist_of_tree ([],[],[])
        |> Simulinkparser.pushDefaults
        |> SimulinkTrans.topologicSort
(*	|> Simulinkparser.printLaTeX stdout *)


