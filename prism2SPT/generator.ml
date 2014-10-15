open PetriNet
open StochasticPetriNet

let rec acc_var k = function 
  | [] -> raise Not_found
  | (t,a,_)::_ when t=k -> a  
  | _::q -> acc_var k q

let net_of_prism (_,var,action) =
  let open Data in
      let open Net in
	  let net = create () in
	  List.iter (fun (n,(a,b),i) -> add (n,i) net.place) var;
	  ignore (List.fold_left 
	    (fun i (g,f,u) ->
	      let trname = "a"^(string_of_int i) in 
	      add (trname,Exp f) net.transition;
	      List.iter (fun (v,_,j) -> 
		if j>0 then add_inArc net v trname j;
		let _,b = acc_var v var in 
		if b-j>0 then add_inhibArc net v trname (j+1) ) g;
	      List.iter (fun (v,j) -> 
		(*let jin = List.fold_left (fun j1 (v2,_,j2) -> if v=v2 then j2 else j1) 0 g in  		*)
		if j>0 then add_outArc net trname v (j)) u;
	      
	      i+1)
	    1 action);
 
  net



let _ =
  let input = ref stdin in
  let output = ref "out" in
  if Array.length Sys.argv >1 then (
    let s = Sys.argv.(1) in
    input := open_in s;
    output := String.sub s 0 (String.rindex s '.'); 
  );
  let lexbuf = Lexing.from_channel !input  in
  let prismmodule = Parser.main Lexer.token lexbuf in
  let net = net_of_prism prismmodule in
  print_endline "Finish parsing";
  print_spt_dot ((!output)^".dot") net [] [];
  print_spt ((!output)^".grml") net
    


(*
 let a =  Automata.automata_of_pltrlist ["Queue1";"Queue2"] [] 0.0 10.0 (int_of_string (Sys.argv.(2))) in
    Writer.writeAutomata a;
	print_newline ();
*)
