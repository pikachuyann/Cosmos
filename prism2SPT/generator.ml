open Type
open PetriNet
open StochasticPetriNet
open Lexer
open Lexing
open Pnmlparser

let print_position outx lexbuf =
  let pos = lexbuf.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)

let rec acc_var k = function 
  | [] -> raise Not_found
  | (t,a,_)::_ when t=k -> a  
  | _::q -> acc_var k q

let rec flatten_guard = function
  | True -> [[]]
  | False -> []
  | And (e1,e2) ->
    let l=flatten_guard e1 in
    List.fold_left (fun acc l1 ->
      acc@(List.map (fun x->x@l1) (flatten_guard e2))) [] l
  | Or (e1,e2) -> (flatten_guard e1)@(flatten_guard e2)
  | IntAtom ((IntName v),NEQ,j) -> [[(v,SL,j)];[(v,SG,j)]]
  | IntAtom ((IntName v),cmp,j) -> [[(v,cmp,j)]] 
  | Not e -> flatten_guard (neg_bool e)
  | e-> printH_stateFormula stderr e;
    failwith "Not yet supported guard shape"

let rec convert_guard modu net trname ((r1,r2) as rset) = function
  | [] -> rset
  | (v,GE,j)::q when sgz j -> Net.add_inArc net v trname (simp_int j);
    convert_guard modu net trname ((StringMap.add v j r1),r2) q
  | (_,GE,_)::q -> convert_guard modu net trname rset q
  | (v,SL,j)::q -> 
    let _,bo = acc_var v modu.varlist in (match bo with
	Int b ->if gez (Minus(bo,j)) then Net.add_inhibArc net v trname (simp_int j)
      | _ -> Net.add_inhibArc net v trname (simp_int j););
    convert_guard modu net trname rset q
  | (v,EQ,j)::q -> convert_guard modu net trname 
    (r1, (StringMap.add v (Int 0) r2))
    ((v,GE,j)::(v,SL,incr_int j)::q)
  | (v,LE,j)::q -> convert_guard modu net trname rset 
    ((v,SL,incr_int j)::q)
  | (v,SG,j)::q -> convert_guard modu net trname rset 
    ((v,GE,incr_int j)::q)
  | (_,NEQ,_)::q -> failwith " Should not occur with flatten guard"

let convert_update net trname eqmap varmap = function
  | v,(Plus((IntName v2),j)) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = simp_int (Plus(StringMap.find v varmap,j)) in
    Net.add_outArc net trname v j2;
    StringMap.remove v varmap
  | v,(Plus((IntName v2),j)) when v=v2 -> Net.add_outArc net trname v j; varmap
  | v,(Minus((IntName v2),j)) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = simp_int (Minus(StringMap.find v varmap,j)) in
    if sgz j2 then Net.add_outArc net trname v j2;
    StringMap.remove v varmap
  
  | v,(Int j) when StringMap.mem v eqmap -> 
    let j2 = simp_int (Minus(Int j,StringMap.find v eqmap)) in
    if sgz j2 then Net.add_outArc net trname v j2;
    (try StringMap.remove v varmap with Not_found -> varmap);

  | v,j when (StringMap.mem v eqmap) -> 
    let j2 = StringMap.find v eqmap in
    if j2= Int 0 then Net.add_outArc net trname v j
    else Net.add_outArc net trname v (Minus(j,j2));
    StringMap.remove v varmap

  | v,j when StringMap.mem v varmap ->
    printH_int_expr stderr j;
    failwith (Printf.sprintf "Cannot export %s-> %s" trname v);
   
  | v,j ->
    Net.add_inArc net v trname (IntName (v));
    Net.add_outArc net trname v j; 
    varmap
    

let gen_acc iinit modu net (st,g,f,u) =
  let i = ref iinit in
  let flatguardlist = flatten_guard g in
  List.iter (fun flatguard ->
  let trname = Printf.sprintf "a%i%s" !i (match st with None -> "" | Some s-> s) in 
  Data.add (trname,Exp f) net.Net.transition;  

  let (invar1,invar2) = 
    convert_guard modu net trname (StringMap.empty,StringMap.empty) flatguard in 
  let remaining = List.fold_left (convert_update net trname invar2) invar1 u in
  StringMap.iter (fun v value -> Net.add_outArc net trname v value) remaining;
  incr i;
  ) flatguardlist;
  !i

  (*let diff = StringMap.diff (get_out u) invar in
  StringMap.iter (fun v _ -> 
     Net.add_inArc net v trname (IntName (v)) ) diff;

  List.iter (fun (v,jexp) -> Net.add_outArc net trname v jexp) u*)


let net_of_prism modu =
  let net = Net.create () in
  List.iter (fun (n,(a,b),i) -> Data.add (n,i) net.Net.place) modu.varlist;
  ignore (List.fold_left 
	    (fun i ac ->
	      gen_acc i modu net ac)
	    1 modu.actionlist);
  net

let print_rename f =
  List.iter (fun (x,y) -> Printf.fprintf f " %s->%s " x y) 

let rec rename_int_expr rn e = 
  let rnr = rename_int_expr rn in match e with
    | IntName(s) -> IntName (rn s);
    | Int(i) -> Int(i)
    | Plus(e1,e2) -> Plus(rnr e1,rnr e2)
    | Minus(e1,e2) -> Minus(rnr e1,rnr e2)
    | Mult(e1,e2) -> Mult(rnr e1,rnr e2)
let rec rename_float_expr rn e =
  let rnr = rename_float_expr rn in match e with
    | FloatName(x) -> FloatName(rn x)
    | Float(x) -> Float(x)
    | CastInt(x) -> CastInt(rename_int_expr rn x) 
    | ExpF(x) -> ExpF(rnr x) 
    | PlusF(e1,e2) -> PlusF(rnr e1,rnr e2)
    | MinusF(e1,e2) -> MinusF(rnr e1,rnr e2)
    | MultF(e1,e2) -> MultF(rnr e1,rnr e2)
    | DivF(e1,e2) -> DivF(rnr e1,rnr e2)
let rename_op rn = function None -> None | Some a -> Some (rn a)
let rec rename_bool_expr rn e = 
  let rnr = rename_bool_expr rn in match e with
  | True -> True
  | False -> False
  | Not(e1) -> Not (rnr e1) 
  | And(e1,e2) -> And(rnr e1,rnr e2)
  | Or(e1,e2) -> Or(rnr e1,rnr e2)
  | IntAtom(ie,c,ie2) -> IntAtom(rename_int_expr rn ie,c,rename_int_expr rn ie2)

let rec rename_module l1 = function
  | [] -> l1
  | (nn,on,rl)::q -> 
    let rn a = try (List.assoc a rl) with Not_found -> a
(*output_string stderr (a^" not foud"); print_rename stderr rl; raise Not_found*)  in
    let template = List.find (fun m -> m.name = on) l1 in
    let nvarl = List.map (fun (a,b,c) -> (rn a),b,c ) template.varlist in
    let nactionl = List.map (fun (a,b,c,d) -> 
      (rename_op rn a),
      (rename_bool_expr rn b),
      (rename_float_expr rn c),
      (List.map (fun (s,ie) -> (rn s),(rename_int_expr rn ie)) d)) template.actionlist in
    let nm = {
      name=nn;
      varlist=nvarl;
      actionlist=nactionl;
      actionset=find_action nactionl
    } in
    rename_module (nm::l1) q

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
	  else (s1,And(g1,g2),MultF(r1,r2),u1@u2) :: ls2) ls1 m2.actionlist)
	(List.filter (fun (s,_,_,_) -> filt s) m2.actionlist)
	m1.actionlist in       
      {
	name = Printf.sprintf "(%s||%s)" m1.name m2.name;
	varlist=varlist;
	actionlist= synchtrans;
	actionset= union m1.actionset m2.actionset
      }

let read_prism s name =
  let lexbuf = Lexing.from_channel s in
  lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = name };
  try
    let cdef,prismml = Parser.main Lexer.token lexbuf in
    let (fullmod,renammod) = List.fold_left (fun (l1,l2) m -> match m with 
	Full fm -> (fm::l1),l2 | Renaming (rm1,rm2,rm3) -> l1,((rm1,rm2,rm3)::l2) ) ([],[]) prismml in
    let prismm2 = rename_module fullmod renammod in
    let prismmodule = List.fold_left compose_module 
      (List.hd prismm2) (List.tl prismm2) in
    (cdef,net_of_prism prismmodule)
  with 
  | SyntaxError msg ->
    Printf.fprintf stderr "%a: %s\n" print_position lexbuf msg;
    failwith "Fail to parse Prism file format"
  | Parsing.Parse_error ->
    Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s'\n"
      print_position lexbuf (lexeme lexbuf);
    failwith "Fail to parse Prism file format"
  
