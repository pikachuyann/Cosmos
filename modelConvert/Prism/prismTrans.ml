open Type
open PrismType
open PetriNet
open StochasticPetriNet
open Lexing

let print_position outx lexbuf =
  let pos = lexbuf.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)

let rec acc_var k = function 
  | [] -> raise Not_found
  | IntK(t,a,_)::_ when t=k -> a  
  | _::q -> acc_var k q


let rec convert_guard modu net trname ((r1,r2) as rset) = function
  | [] -> rset
  | (v,GE,j)::q when sgz j -> Net.add_inArc net v trname (eval j);
    convert_guard modu net trname ((StringMap.add v j r1),r2) q
  | (_,GE,_)::q -> convert_guard modu net trname rset q
  | (v,SL,j)::q -> 
    let _,bo = acc_var v modu.varlist in (match bo with
	Int b ->if gez (Minus(bo,j)) then Net.add_inhibArc net v trname (eval j)
      | _ -> Net.add_inhibArc net v trname (eval j););
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
  | v,BoolUp(j) when (StringMap.mem v varmap) ->
    Net.add_outArc net trname v (CastBool j);
    StringMap.remove v varmap
  | v,BoolUp(j) -> Net.add_outArc net trname v (CastBool j); varmap
                                                             
  | v,IntUp(Plus((IntName v2),j)) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = eval (Plus(StringMap.find v varmap,j)) in
    Net.add_outArc net trname v j2;
    StringMap.remove v varmap

  | v,IntUp(Plus((IntName v2),j)) when v=v2 -> Net.add_outArc net trname v j; varmap
  | v,IntUp(Minus((IntName v2),j)) when v=v2 && (StringMap.mem v varmap) -> 
    let j2 = eval (Minus(StringMap.find v varmap,j)) in
    if sgz j2 then Net.add_outArc net trname v j2;
    StringMap.remove v varmap
  
  | v,IntUp(Int j) when StringMap.mem v eqmap ->
     let j2 = eval (Minus(Int j,StringMap.find v eqmap)) in
    if sgz j2 then Net.add_outArc net trname v j2;
    (try StringMap.remove v varmap with Not_found -> varmap);

  | v,IntUp(j) when (StringMap.mem v eqmap) -> 
    let j2 = StringMap.find v eqmap in
    if j2= Int 0 then Net.add_outArc net trname v j
    else Net.add_outArc net trname v (Minus(j,j2));
    StringMap.remove v varmap

  | v,IntUp(j) when StringMap.mem v varmap ->
    printH_expr stderr j;
    failwith (Printf.sprintf "Cannot export %s-> %s" trname v);
   
  | v,IntUp(j) ->
    Net.add_inArc net v trname (IntName (v));
    Net.add_outArc net trname v j; 
    varmap

let gen_acc iinit modu net (st,g, taillist) =
  let i = ref iinit in
  List.iter (fun (f,u) ->
      List.iter (fun flatguard ->
          let trname = Printf.sprintf "a%i%s" !i (match st with None -> "" | Some s-> s) in 
          Data.add (trname,(Exp f,Float 1.0,Float 1.0)) net.Net.transition;
      
          let (invar1,invar2) = 
            convert_guard modu net trname (StringMap.empty,StringMap.empty) (Guard.to_list flatguard) in 
          let remaining = List.fold_left (convert_update net trname invar2) invar1 u in
          StringMap.iter (fun v value -> Net.add_outArc net trname v value) remaining;
          incr i;
        ) g
    ) taillist;
  !i

  (*let diff = StringMap.diff (get_out u) invar in
  StringMap.iter (fun v _ -> 
     Net.add_inArc net v trname (IntName (v)) ) diff;

  List.iter (fun (v,jexp) -> Net.add_outArc net trname v jexp) u*)


let net_of_prism modu (li,lf) =
  print_endline "Building net";
  let net = Net.create () in
  net.Net.def <- Some {
		     intconst=li ;
		     floatconst=lf;
		     clock=[];
		     printer=fun _ ()->()} ;
  List.iter (function 
  | IntK(n,(a,b),i) -> Data.add (n,(i,Some b)) net.Net.place
  | BoolK(n,(a,b),i) -> Data.add (n,(i,Some b)) net.Net.place
  | ClockK _ -> ()) modu.varlist;
  print_endline "Building transitions";
  ignore (List.fold_left 
	    (fun i ac ->
	      gen_acc i modu net ac)
	    1 modu.actionlist);
  print_endline "Finish net";
  net

let rename_guard rn g =
  let g2 = List.map (fun dij ->
      Guard.map (fun (v,cmp,expr) ->
          (rn v), cmp, (rename_expr rn expr)) dij) g in
  g2
    
let rec rename_module l1 = function
  | [] -> l1
  | (nn,on,rl)::q -> 
    let rn a = try (List.assoc a rl) with Not_found -> a
(*output_string stderr (a^" not foud"); print_rename stderr rl; raise Not_found*)  in
    let template = List.find (fun m -> m.name = on) l1 in
    let nvarl = List.map (function  
      | IntK(a,b,c) -> IntK((rn a),b,c) 
      | BoolK(a,b,c) -> BoolK((rn a),b,c)
      | ClockK(a) -> ClockK((rn a)) ) template.varlist in
    let nactionl = List.map (fun (a,b, taillist) ->
      (rename_op rn a),
      (rename_guard rn b),
      List.map (fun (c,d) ->
          (rename_expr rn c),
          (List.map (function (s,IntUp(ie)) -> (rn s),IntUp(rename_expr rn ie) 
                            | (s,BoolUp(ie)) -> (rn s),BoolUp(rename_expr rn ie) ) d)
                     ) taillist ) template.actionlist in
    let nm = {
      name=nn;
      varlist=nvarl;
      actionlist=nactionl;
      actionset=find_action nactionl
    } in
    rename_module (nm::l1) q

let clean_module m =
  m.actionlist
  |> List.map (fun (s,g,r,u) ->
         u
         |> List.filter (function (v,IntUp (IntName w)) when v=w -> false
                             | (v,BoolUp (BoolName w)) when v=w -> false
                                  | _ -> true)
         |> (fun v -> s,g,r,v)
       )
  |> (fun al ->
    { m with actionlist=al})
                   
                  
let compose_module m1 m2 = 
  let open StringSet in
      let common = inter m1.actionset m2.actionset in 
      let varlist = m1.varlist @ m2.varlist in
      let filt = function 
	| None -> true 
	| Some s-> not (mem s common) in
      let synchtrans =
        List.fold_left (fun ls1 (s1,g1,r1,u1) ->
	    if filt s1 then (s1,g1,r1,u1)::ls1
	    else List.fold_left (fun ls2 (s2,g2,r2,u2) -> 
	             if s1<>s2 then ls2
	             else (s1,(Guard.conj g1 g2),eval (Mult(r1,r2)),u1@u2) :: ls2) ls1 m2.actionlist)
	               (List.filter (fun (s,_,_,_) -> filt s) m2.actionlist)
	               m1.actionlist
        |> List.filter (fun (_,g,_,_) -> g<>[])
      in       
      let nm = {
	name = Printf.sprintf "(%s||%s)" m1.name m2.name;
	varlist=varlist;
	actionlist= synchtrans;
	actionset= union m1.actionset m2.actionset
        } in
      print_prism !logout nm;
      nm 

let read_prism s name =
  let lexbuf = Lexing.from_channel s in
  lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = name };
  try
    Preparser.main Prelexer.token lexbuf;
    print_endline "Finish first pass";
    Lexing.flush_input lexbuf;
    lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_lnum = 1 };
    seek_in s 0;
    let cdef,prismml,kind = ParserPrism.main LexerPrism.token lexbuf in
    let (fullmod,renammod) = List.fold_left (fun (l1,l2) m -> match m with 
	Full fm -> (clean_module fm::l1),l2 | Renaming (rm1,rm2,rm3) -> l1,((rm1,rm2,rm3)::l2) ) ([],[]) prismml in
    let prismm2 = rename_module fullmod renammod in
    List.iter (print_prism !logout) prismm2;
    let prismmodule = List.fold_left compose_module
                                     (List.hd prismm2) (List.tl prismm2) in
    print_prism !logout prismmodule;
    (net_of_prism prismmodule cdef)
  with 
  | LexerPrism.SyntaxError msg ->
    Printf.fprintf stderr "%a: %s\n" print_position lexbuf msg;
    failwith "Fail to parse Prism file format"
  | Parsing.Parse_error ->
    Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s'\n"
      print_position lexbuf (lexeme lexbuf);
    failwith "Fail to parse Prism file format"

