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

let rec convert_guard modu net trname ((r1,r2) as rset) = function
  | [] -> rset
  | (v,GE,j)::q when j>0 -> Net.add_inArc net v trname (Int j);
    convert_guard modu net trname ((StringMap.add v j r1),r2) q
  | (_,GE,_)::q -> convert_guard modu net trname rset q
  | (v,SL,j)::q -> 
    let _,bo = acc_var v modu.varlist in (match bo with
	Int b ->if b-j>=0 then Net.add_inhibArc net v trname (Int j)
      | _ -> Net.add_inhibArc net v trname (Int j););
    convert_guard modu net trname rset q
  | (v,EQ,j)::q -> convert_guard modu net trname 
    (r1, (StringMap.add v 0 r2))
    ((v,GE,j)::(v,SL,j+1)::q)
  | (v,LE,j)::q -> convert_guard modu net trname rset 
    ((v,SL,j+1)::q)
  | (v,SG,j)::q -> convert_guard modu net trname rset 
    ((v,GE,j+1)::q)
  | (_,NEQ,_)::q -> failwith " != not yet implemented for guard"

let convert_update net trname eqmap varmap = function
  | v,(Plus((IntName v2),j)) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = StringMap.find v varmap in
    Net.add_outArc net trname v (Plus((Int j2),j));
    StringMap.remove v varmap
  | v,(Plus((IntName v2),j)) when v=v2 -> Net.add_outArc net trname v j; varmap
  | v,(Minus((IntName v2),(Int j)) ) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = StringMap.find v varmap in
    if j2>j then Net.add_outArc net trname v (Int (j2-j))
    else if j2<j then failwith "ungarded transition";
    StringMap.remove v varmap
  
  | v,(Int j) when StringMap.mem v eqmap -> 
    let j2 = StringMap.find v eqmap in
    if j-j2> 0 then Net.add_outArc net trname v (Int (j-j2));
    (try StringMap.remove v varmap with Not_found -> varmap);

  | v,j when (StringMap.mem v eqmap) -> 
    let j2 = StringMap.find v eqmap in
    if j2= 0 then Net.add_outArc net trname v j
    else Net.add_outArc net trname v (Minus(j,Int j2));
    StringMap.remove v varmap

  | v,j when StringMap.mem v varmap ->
    printH_int_expr stderr j;
    failwith (Printf.sprintf "Cannot export %s-> %s" trname v);
   
  | v,j ->
    Net.add_inArc net v trname (IntName (v));
    Net.add_outArc net trname v j; 
    varmap
    

let gen_acc i modu net (st,g,f,u) =
  let trname = Printf.sprintf "a%i%s" i (match st with None -> "" | Some s-> s) in 
  Data.add (trname,Exp f) net.Net.transition;  

  let (invar1,invar2) = 
    convert_guard modu net trname (StringMap.empty,StringMap.empty) g in
  let remaining = List.fold_left (convert_update net trname invar2) invar1 u in
  StringMap.iter (fun v value -> Net.add_outArc net trname v (Int value)) remaining 

  (*let diff = StringMap.diff (get_out u) invar in
  StringMap.iter (fun v _ -> 
     Net.add_inArc net v trname (IntName (v)) ) diff;

  List.iter (fun (v,jexp) -> Net.add_outArc net trname v jexp) u*)


    
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
    print_spt ((!output)^".grml") net cdef;
    print_endline "Finish exporting";
    if Array.length Sys.argv =2 then
      ignore (Sys.command (Printf.sprintf "dot -Tpdf %s.dot -o %s.pdf" !output !output))
  with 
    | SyntaxError msg ->
      Printf.fprintf stderr "%a: %s\n" print_position lexbuf msg      
    | Parsing.Parse_error ->
      Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s'\n"
	print_position lexbuf (lexeme lexbuf)
      
