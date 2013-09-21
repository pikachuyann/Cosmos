open Type
open Automata
open Printf

let rec write_linConstr = function
  | [] -> ()
  | (i,c,fexpr)::q ->
    printf "v%i" i;
    print_cmp c;
    print_float_expr fexpr;
    if List.length q >0 then printf "&";
    write_linConstr q

let rec write_flow = function
  | [] -> ()
  | (i,fexpr)::q ->
    printf "v%i'=" i;
    print_float_expr fexpr;
    if List.length q >0 then printf ",";
    write_flow q


let writeAutomata a =
  printf "NbVariables = %i;\n" a.nbVar;
  printf "NbLocations = %i;\n" a.nbLoc;
  
  printf "VariablesList = {";
  for i = 0 to a.nbVar-1 do
    if i>0 then printf ",";
    printf "v%i" i;
  done;
  printf "}\n";
  
  printf "LocationsList = {";
  for i = 0 to a.nbLoc-1 do
    if i>0 then printf ",";
    printf "l%i" i;
  done;
  printf "}\n";
  
  printf "PROB()\n";

  printf "InitialLocations = { l%i }\n" a.init;

  printf "FinalLocations = {";
  List.iter (fun x ->printf "l%i," x) a.final;
  printf "}\n";

  printf "Locations = {";
  for i = 0 to a.nbLoc do
    printf "(l%i," i;
    begin 
      try print_sf (List.assoc i a.invariant)
      with Not_found -> printf "TRUE"; 
    end;
    try let lflows = List.assoc i a.flows in 
	if lflows <> [] then
	  write_flow lflows;
    with Not_found -> ();
    printf ");\n"
  done;
  printf "}\n";

  printf "Edges = {";
  List.iter (fun (l1,tt,l2) -> 
    printf "((l%i,l%i)," l1 l2;
    (match tt with
      Synch(_,sf) -> printf "ALL,";
	print_sf sf;
    | Autonomous(lconstr) -> printf "#,";
       write_linConstr lconstr;
    );
    printf ");\n"
  ) a.trans;
  printf "}\n";
