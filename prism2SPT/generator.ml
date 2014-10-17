open Type
open PetriNet
open StochasticPetriNet
open Lexer
open Lexing

let print_position outx lexbuf =
  let pos = lexbuf.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)

let rec acc_var k = function 
  | [] -> raise Not_found
  | (t,a,_)::_ when t=k -> a  
  | _::q -> acc_var k q

let get_in g =
  List.fold_left (fun s (v,_,_) -> StringSet.add v s) StringSet.empty g
let get_out u =
  List.fold_left (fun s (v,_) -> StringSet.add v s) StringSet.empty u

let gen_acc i modu net (st,g,f,u) =
  let trname = Printf.sprintf "a%i%s" i (match st with None -> "" | Some s-> s) in 
  Data.add (trname,Exp f) net.Net.transition;  
  List.iter (fun (v,_,j) -> 
    if j>0 then Net.add_inArc net v trname (Int j);
    let _,b = acc_var v modu.varlist in 
    if b-j>0 then Net.add_inhibArc net v trname (Int (j+1)) ) g;
  let invar = get_in g
  and outvar = get_out u in
  let diff = StringSet.diff outvar invar in
  StringSet.iter (fun v -> 
     Net.add_inArc net v trname (IntName (v)) ) diff;

  List.iter (fun (v,jexp) -> Net.add_outArc net trname v jexp) u
    
let net_of_prism modu =
  let net = Net.create () in
  List.iter (fun (n,(a,b),i) -> Data.add (n,i) net.Net.place) modu.varlist;
  ignore (List.fold_left 
	    (fun i ac ->
	      gen_acc i modu net ac;
	      i+1)
	    1 modu.actionlist);
  net


let compose_module m1 m2 = 
  let open StringSet in
      let common = inter m1.actionset m2.actionset in 
      let varlist = m1.varlist @ m2.varlist in
      let filt = function 
	| None -> true 
	| Some s-> not (mem s common) in
      let synchtrans = List.fold_left (fun ls1 (s1,g1,r1,u1) ->
	if filt s1 then (s1,g1,r1,u1)::ls1
	else List.fold_left (fun ls2 (s2,g2,r2,u2) -> 
	  if s1<>s2 then ls2
	  else (s1,g1@g2,MultF(r1,r2),u1@u2) :: ls2) ls1 m2.actionlist)
	(List.filter (fun (s,_,_,_) -> filt s) m2.actionlist)
	m1.actionlist in 
      
      {
	name = Printf.sprintf "(%s||%s)" m1.name m2.name;
	varlist=varlist;
	actionlist= synchtrans;
	actionset= union m1.actionset m2.actionset
      }


let _ =
  let input = ref stdin in
  let output = ref "out" in
  let inname = ref "stdin" in
  if Array.length Sys.argv >1 then (
    inname := Sys.argv.(1);
    input := open_in !inname;
    if Array.length Sys.argv >2 then output := Sys.argv.(2)
    else output:=String.sub !inname 0 (String.rindex !inname '.'); 
  );
  let lexbuf = Lexing.from_channel !input  in
  lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = !inname };
  try
    let cdef,prismml = Parser.main Lexer.token lexbuf in
    let prismmodule = List.fold_left compose_module 
      (List.hd prismml) (List.tl prismml) in
    let net = net_of_prism prismmodule in
    print_endline "Finish parsing";
    print_spt_dot ((!output)^".dot") net [] [];
    print_spt ((!output)^".grml") net (List.map (fun (s,ao) ->
      match ao with None -> s,1.0 | Some f -> s,f) cdef);
    print_endline "Finish exporting"
  with 
    | SyntaxError msg ->
      Printf.fprintf stderr "%a: %s\n" print_position lexbuf msg      
    | Parsing.Parse_error ->
      Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s'\n"
	print_position lexbuf (lexeme lexbuf)
      
