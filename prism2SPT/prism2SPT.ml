open Type
open Generator
open Pnmlparser

type format = Prism | Pnml | Dot | Marcie

let input = ref stdin
let output = ref "out"
let inname = ref "stdin"
let typeFormat = ref Prism

let suffix_of_filename s =
  let fa = String.rindex s '.'+1 in
  (String.sub s 0  (fa -1)),(
  String.sub s fa (String.length s - fa))

let nbarg = ref 0

let _ = 
  Arg.parse []
    (function s -> incr nbarg; match !nbarg with
      1 -> inname:= s;
	( let o,suf = suffix_of_filename s in 
	  output := o;
	  match suf with
	  "sm" | "pm" -> typeFormat := Prism
	| "pnml" -> typeFormat := Pnml
	| _-> failwith "Unsupported file format"
	)
    | 2 -> output := s
    | _ -> failwith "Do not know what to do with extra arguments.") 
    "usage"
  
let _ =
  match !typeFormat with
    Prism ->
      print_endline ("Opening "^ !inname);
      input := open_in !inname;
      let (cdef,net) = read_prism !input !inname in
      print_endline "Finish parsing";
      StochasticPetriNet.print_spt_dot ((!output)^".dot") net [] [];
      StochasticPetriNet.print_spt ((!output)^".grml") net cdef;
      print_endline "Finish exporting";
  | Pnml ->
    let xmlf = tree_of_pnml !inname in
    let net = PetriNet.Net.create () in
    net_of_tree net xmlf;
    StochasticPetriNet.print_spt_dot ((!output)^".dot") net [] [];
    StochasticPetriNet.print_spt ((!output)^".grml") net ([],[]);
    print_endline "Finish exporting";
  | _ -> failwith "Format not yet supported";;

if Array.length Sys.argv =2 then
  ignore (Sys.command (Printf.sprintf "dot -Tpdf %s.dot -o %s.pdf" !output !output))
