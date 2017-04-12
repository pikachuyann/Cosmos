open Type
open PetriNet
open StochasticPetriNet

let _ = Random.self_init ()

let mdpstrat = ref ""
let detstrat = ref false

module Prio = struct
    type t = float*float*float*Net.transitionkey Data.key
    let compare (t1,p1,w1,_) (t2,p2,w2,_) =
      if t1<t2 then -1
      else if t1>t2 then 1
      else if p1<p2 then -1
      else if p2>p1 then 1
      else if w1<w2 then -1
      else if w1>w2 then 1
      else 0
  end

module EQueue = Set.Make(Prio)
	     	
let sample_distr ev = function
  | Imm -> 0.0
(*  | Det(x) -> ev x
  | Unif(Type.Float x,Type.Float y) -> x +. Random.float (y-.x)		*)
  | Exp(x) -> -. log(Random.float 1.0)/. (ev x)
  | _ -> failwith "Unable to sample from distribution"


let eval_or_die_mark net m e =
  eval_or_die ~iname:(fun x -> Some x
			       |>>> Data.index net.Net.place
			       |>>> Data.unsafe_rev
			       |>>> (fun x -> m.(x))
			       |>>> fst) e

let finalResultExpr net m tr fa =
  if eval_or_die_mark net m tr then Some true
  else if eval_or_die_mark net m fa then Some false
  else None
		
  		  
module SptOp = struct
    type placetype = placetypeSPT
    type valuationtype = valuationtypeSPT
    type transitiontype = transitiontypeSPT
    type declarationtype = declarationSPT
    type result = bool
			     
    let eval net (m:placetype array) e =
      let rep = Type.replace_expr (fun s ->
	try
	  let p = Data.index net.Net.place s in
	  Some (fst m.(Data.unsafe_rev p))
	with Not_found ->
	  match net.Net.def |>> (fun x -> List.assoc s x.intconst) with
	  | Some v -> Some v
	  | None -> failwith (s^ "neither an intconst or a place name")
				  ) e in
      Type.eval ~iname:(fun s -> net.Net.def |>> (fun x -> List.assoc s x.intconst)) rep 

    let eval_marking net m (p,q) =
      (eval net m p),q
		
    let print_marking f (p,_) =
      Type.printH_expr f p
		
    let compare net m (pt,_) v =
      match eval net m (Type.Minus(pt,v)) with
	Type.Int(x) -> x
      | e -> Type.printH_expr stdout e; 
	     failwith "Cannot evaluate"
    let compare_marking (p1,_) (p2,_) = match (p1),(p2) with
      | x,y when x=y -> 0
      | (Type.Int(x),(Type.Int(y))) -> x-y
      | e1,e2 -> Printf.fprintf stdout "Cannot compare %a and %a\n" Type.printH_expr e1 Type.printH_expr e2;
	 failwith "Cannot evaluate"
       
    let add net m (pt,o) v =
      (eval net m (Type.Plus(pt,v)) ,o)
    let minus net m (pt,o) v =
      (eval net m (Type.Minus(pt,v)) ,o)

    let sample net m t =
      let intdef = net.Net.def |>>> (fun x -> x.intconst) |>>| [] in
      let floatdef = net.Net.def |>>> (fun x -> x.floatconst) |>>| [] in
      let intrpl = fun s -> try List.assoc s intdef with _ -> (
		 try let index = Data.index net.Net.place s in
		     Some (fst @@ m.(Data.unsafe_rev index)) with _ -> None) 					     
      in
      let floatrpl = fun s -> try List.assoc s floatdef with _ -> None in
      let eval x = Type.eval_or_die ~iname:intrpl ~fname:floatrpl x in
      
      let (d,p,w) = snd @@ Data.acca net.Net.transition t in
      let time = sample_distr eval d in
      let weight = sample_distr eval (Exp (w)) in
      match p with
	Type.Float(f) -> time,f,weight,t
      |_ -> failwith "Cannot evaluate"
	
    let choose net m en =
      let heap = List.fold_left (fun h t ->
				 EQueue.add (sample net m t) h) EQueue.empty en in
      let (_,_,_,t) = EQueue.min_elt heap in t

                                               (*let finalResult net m = None *)
                                               
    let finalResult net m =
      finalResultExpr net m (IntAtom(IntName("NB"),EQ,Int(1000)))
		      (disjunction [ 
			   (IntAtom(IntName("Q1"),EQ,Int(10)));
			   (IntAtom(IntName("Q2"),EQ,Int(10)));
			   (IntAtom(IntName("Q3"),EQ,Int(10)));
		      ])

(*    let finalResult net m =
      finalResultExpr net m (IntAtom(IntName("NbStep"),EQ,Int(1000)))
                      (disjunction [
                           (IntAtom(IntName("Tank"),EQ,Int(0)));
			   (IntAtom(IntName("Tank"),EQ,Int(20)));
                      ])*)
      
(*      let tank = Data.index net.Net.place "Tank" in
      let nbstep = Data.index net.Net.place "NbStep" in
      let tankm,_ = m.(Data.unsafe_rev tank) in
      let nbstepm,_ = m.(Data.unsafe_rev nbstep) in
      match (Type.eval_or_die tankm),(Type.eval_or_die nbstepm) with
	0,_ -> Some false
      | 20,_ -> Some false
      | _,1000 -> Some true
      | _ -> None*)
end

		 
module MdpOp = struct
    
    include SptOp
	      
    module SemanticSPT = SemanticPT.NetWithMarking(SptOp)
					      
    module MarkingMap = Map.Make(struct
				    type t = int array
				    let compare (x:t) (y:t) =
				      Pervasives.compare x y 
				  end)
    let intarray_of_marking m =
      let t = Array.map (fun (x,_) -> eval_or_die x) m in
      (try t.(7) <-0; with
        Invalid_argument s -> raise (Invalid_argument (s ^":"^ __FILE__ ^":"^ string_of_int @@__LINE__))
      );                                               
      t

    let print_intarray f x =
      Printf.fprintf f "(%a)" (fun f t ->
			       t |> Array.iter (fun te ->
						Printf.fprintf f "%i, " te)
			      ) x
		
    let print_traj f x =
      Printf.fprintf f "[%a]" (fun f l ->
	l |> List.iter (print_intarray f) ) x

    let print_state net q =
      print_string "{";
      EQueue.iter (fun (t,_,_,x) ->
	    Printf.printf "%s:%f, "
		      (Data.acca net.Net.transition x |> fst)
		      t) q;
      print_string "}"
		   
    let print_trlist net q =
      print_string "{";
      List.iter (fun (t,x) ->
	    Printf.printf "%s:%f, "
		      (Data.acca net.Net.transition t |> fst)
		      x) q;
      print_string "}"

    let print_mdp_state s =
      MarkingMap.iter (fun x v ->
		       print_string "(";
		       Array.iter (Printf.printf "%i, ") x;
		       Printf.printf ") -> %f\n" v) s 
		
    let findMark ms m =
      let m2 = intarray_of_marking m in
      (*print_string "search:";print_intarray stdout m2;*)
      if MarkingMap.mem m2 ms then
	MarkingMap.find m2 ms
      (*|< (fun _ ->print_string "->")
      |< print_float*)		
      else (0,0)

    type mdp_strategy = {
	mutable state: (int*int) MarkingMap.t;
	mutable currenttraj: int array list;
      }
	     
    let incrMark mdps b m =
      let m2 = m in
      if MarkingMap.mem m2 mdps.state then
	let (vt,vf) = MarkingMap.find m2 mdps.state in
	let v2 = if b then (vt+1,vf) else (vt,vf+1) in
	mdps.state <-
	  MarkingMap.remove m2 mdps.state
	  |> MarkingMap.add m2 v2
      else
	let v = if b then (1,0) else (0,1) in
	mdps.state <- MarkingMap.add m2 v mdps.state
	
		   
    let static =
      {
	state= MarkingMap.empty ;
	currenttraj=[]
      }

    let read_strat () =
      if !mdpstrat <> "" then begin
	  try
	    print_endline ("Opening strategy file:"^ !mdpstrat);
	    let stfile = open_in !mdpstrat in
	    static.state <- input_value stfile;
	    close_in stfile;
	  with
	  | _ -> (print_endline ("Fail to open file:"^ !mdpstrat));
	end
		   
    let sigmoid x min =

       Exp (Float (x -.min +.1.0))
      (*let pi2 = 2.0*.atan(1.0) in
      Exp (Float( 1.0 +. pi2 *. atan( x/.pi2)))
       *)
      (*Exp(Float 1.0)*)
	   
    let mdp_choose net m en =
      (*print_mdp_state static.state;
      print_traj stdout static.currenttraj;*)
      let score_list = en 
		       |> List.map (fun tr ->  tr,(SemanticSPT.fire net m tr))
		       |> List.map (fun (tr,m) -> (tr,findMark static.state m))
                       |> List.map (fun (tr,(i,j)) -> (tr,(float (i-j)/.(float (i+j))) ))
      in
      let min = List.fold_left (fun x (_,y) -> min x y) 0.0 score_list in
      (*print_trlist net score_list;*)
      score_list
      |> (fun x -> if !detstrat then List.map (fun (tr,t) -> (-.t ,0.0,0.0,tr)) x
		   else List.map (fun (tr,t) -> (sample_distr (Type.eval_or_die) (sigmoid t min),0.0,0.0,tr)) x)
      (*|> List.map (fun (tr,t) -> (-.t ,0.0,0.0,tr))*)
	
      |> List.fold_left (fun x y -> EQueue.add y x) EQueue.empty
      (*|< print_state net*)
      |> EQueue.min_elt
      |> (fun (_,_,_,t) -> t)
      |< (fun tr ->let m2 = (SemanticSPT.fire net m tr) in
		   static.currenttraj <- (intarray_of_marking m2) :: static.currenttraj)
    (*|< (fun x -> print_endline ("-> "^(Data.acca net.Net.transition x |> fst)))*)


    let mdp_choose2 net m en =
      let tankplace = Data.index net.Net.place "Tank" |> Data.unsafe_rev in
      let goref = Data.index net.Net.transition "goRefill" in
      let gowait = Data.index net.Net.transition "goWait" in
      let idle = Data.index net.Net.transition "idle" in
      if (m.(tankplace) |> fst |> (fun x -> Type.eval_or_die x)) < 10 then
	if List.mem goref en then goref
	else idle
      else if List.mem gowait en then gowait
      else idle
	     
    let choose net m en =
      let choice = List.fold_left (
			   fun l x -> x
				    |> Data.acca net.Net.transition
				    |> (fun (_,(y,_,_)) ->y)
				    |> (function Player1 -> x::l | _ -> l)) [] en in
      if List.length choice = 0 then 
	let heap = List.fold_left (fun h t ->
				   EQueue.add (sample net m t) h) EQueue.empty en in
	let (_,_,_,t) = EQueue.min_elt heap in t
      else 
	mdp_choose net m choice
      
                   
    let finalResult net m =
      let res = SptOp.finalResult net m in
      res |>>> (fun b -> (*Printf.printf "\nEND ---> %b\n" b;*)
		List.iter (incrMark static b) static.currenttraj;
		static.currenttraj <- [];
	       (*print_mdp_state static.state;*)
	       ) |>>| ();
      res

(*    let consolidate_strat () =
      let n = MarkingMap.cardinal static.state in
      let (mm,sum,var,mM) = MarkingMap.fold (fun _ v (mm,s,va,mM) -> (min v mm,s+.v,s*.s+.va,max v mM))
                                            static.state (max_float,0.0,0.0,min_float) in
      let stdev = sqrt @@ (var -. sum) /. (float n) in
      Printf.printf "min sum max: %f,%f,%f,%f " mm (sum/. (float n)) stdev mM;
      static.state <- MarkingMap.fold (fun m v state ->
          if v < mm +. stdev || v > mM -. stdev then
            MarkingMap.add m v state
          else state) static.state MarkingMap.empty;
      let n2 = MarkingMap.cardinal static.state in
      Printf.printf "Compression: %f\n" ((float n2) /. (float n))
 *)  
        
    let print_state_mdp () =
      if !mdpstrat <> "" then begin
	try
	  let fo = open_out !mdpstrat in
	  output_value fo static.state;
	  close_out fo;
          (*print_mdp_state static.state*)
	with _ -> print_endline "fail to save strategy";
	end;
		      
		   
end					 

module SemanticSPT = SemanticPT.NetWithMarking(MdpOp)


(*open PrismType	      
let conj =
  add_bool "x";
  add_int "y";
  add_bool "z";
  parse_bool "(x )&(x| z)&(y+1>2.0)"
  |>>> form_dij
  |>>> disjunction
  |>>| (Bool false)
  |< printH_expr stdout
 *) 
