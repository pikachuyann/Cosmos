#!/usr/local/bin/ocaml
#load "unix.cma";;

if Array.length Sys.argv >1 then
  Unix.putenv "COSMOS" Sys.argv.(1);;

#use "testTeamCity.ml";;


print_endline ("Cosmos Path set to:"^ (!cosmos_path));;

let log = (Unix.getcwd ())^"/cosmos_test_log";;

init_log log;;

let benchlist = [
  "TandemQN", None;
  "pi",None;
  "testDistribution",None;
  "Workflow-Net",None;
  "QueueMM1", None;
  "signallingCascade", None;
  "DataBase" , None;
  "RareEventUnbounded", None;
  "RareEventUnbounded", Some("test2.ml");
  "TandemCosy", Some("testPrism.ml");
  "SharedMemory" , None;
  "RareEventU", None;
  "DNAWalker", None;
	 
 ];;

List.iter (fun (s,n) -> 
  let cmd = Printf.sprintf "cd %s && ocaml %s bash %s" s (
    match n with None->"test.ml" | Some c ->c) log in
  ignore (Sys.command cmd)) benchlist;;

let (succ,failure) = read_log log in
Printf.printf "Test finished: %i success and %i failure\n" (List.length succ)
  (List.length failure);
if List.length failure >0 then (
  Printf.printf "The following test failed:\n";
  List.iter print_endline failure
)

(*

	(cd TandemQN && ocaml test.ml $(INTC))
	(cd pi && ocaml test.ml $(INTC))
	(cd testDistribution && ocaml test.ml $(INTC))
	(cd Workflow-Net && ocaml test.ml $(INTC))
	(cd QueueMM1 && ocaml test.ml $(INTC))
	(cd signallingCascade && ocaml test.ml $(INTC))
	(cd DataBase && ocaml test.ml $(INTC))
	(cd RareEventUnbounded && ocaml test.ml $(INTC))
#	(cd RareEventUnbounded && ocaml test2.ml $(INTC))
#	(cd TandemCosy && ocaml testPrism.ml $(INTC))
	(cd SharedMemory && ocaml test.ml $(INTC))
	(cd RareEventU && ocaml test.ml $(INTC))
	(cd DNAWalker && ocaml test.ml $(INTC))
*)
