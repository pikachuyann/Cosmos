open PetriNet
       
module type OP = sig
    type placetype
    type valuationtype
    type transitiontype
    type declarationtype
    type result

    val print_marking: out_channel -> placetype -> unit 
    val compare_marking: placetype -> placetype -> int
    val compare : (string, placetype, Net.placekey) Data.t -> placetype array -> placetype -> valuationtype -> int
    val add :  (string, placetype, Net.placekey) Data.t -> placetype array -> placetype -> valuationtype -> placetype
    val minus :  (string, placetype, Net.placekey) Data.t -> placetype array -> placetype -> valuationtype -> placetype
    val choose : ( placetype , transitiontype, valuationtype , declarationtype) Net.t -> placetype array -> Net.transitionkey Data.key list -> Net.transitionkey Data.key
    val finalResult : ( placetype , transitiontype, valuationtype , declarationtype) Net.t -> placetype array -> result option
  end

module type NETWITHMARKING = sig
    type placetype
    type valuationtype
    type transitiontype
    type declarationtype
    type result
	   
    exception Illegal_fire of Net.transitionkey Data.key * placetype * valuationtype
    type t = (placetype, transitiontype,valuationtype, declarationtype) Net.t 
    type marking = placetype array 
			   
    val init: t -> marking
    val get: marking -> Net.placekey Data.key -> placetype
    val enabled: t -> marking -> Net.transitionkey Data.key list
    val fire: t -> marking -> Net.transitionkey Data.key -> marking
    val state_space: t -> marking list
    val print_marking: t -> out_channel -> marking -> unit
    val trace: t -> marking -> int -> (Net.transitionkey Data.key list * Net.transitionkey Data.key * marking) list * result option
    val simulate: t -> int -> result option list 
end


		   
module NetWithMarking(Op:OP) : (NETWITHMARKING with type placetype = Op.placetype
						and type valuationtype = Op.valuationtype
						and type transitiontype = Op.transitiontype
						and type declarationtype = Op.declarationtype
						and type marking = Op.placetype array
						and type result = Op.result
						and type t = (Op.placetype, Op.transitiontype ,Op.valuationtype, Op.declarationtype) Net.t ) =
struct
  type placetype = Op.placetype
  type valuationtype = Op.valuationtype
  type transitiontype = Op.transitiontype
  type declarationtype = Op.declarationtype
  exception Illegal_fire of PetriNet.Net.transitionkey Data.key * placetype * valuationtype
  type t = (placetype, transitiontype ,valuationtype, declarationtype) Net.t 
  type marking = placetype array
  type result = Op.result

  let print_marking net f ma =
    Array.iteri (fun i p ->
		 let pn,_ = PetriNet.Data.acca net.Net.place (PetriNet.Data.unsafe i) in
		 Printf.fprintf f "%s:%a, " pn Op.print_marking p) ma 
			   
  let init net =
    Array.init (Data.size net.Net.place) (fun i -> snd (Data.acca net.Net.place (Data.unsafe i)))

  let get m p =
    m.(Data.unsafe_rev p)
	       
  let enabled net m =
    let tr = Array.make (Data.size net.Net.transition) true in
    Data.iter (fun ((),(v,p,t)) ->
	       if Op.compare net.Net.place m (get m p) v <0 then tr.(Data.unsafe_rev t) <- false) net.Net.inArc;
    Data.iter (fun ((),(v,p,t)) ->
	       if Op.compare net.Net.place m (get m p) v >=0 then tr.(Data.unsafe_rev t) <- false) net.Net.inhibArc;
    let l = ref [] in
    Array.iteri (fun i b -> if b then l:= (Data.unsafe i):: !l) tr;
    (!l : Net.transitionkey Data.key list)
      
  let fire net m tr =
    let m2 = Array.copy m in
    Data.iter (fun ((),(v,p,t)) ->
	       if t=tr then 
		 (*Printf.printf "%a-(%a)->%a " (Net.print_place net) p Type.printH_expr (Obj.magic v) (Net.print_transition net) t;*)
		 let index = Data.unsafe_rev p in
		 if Op.compare net.Net.place m m.(index) v >= 0 then m2.(index) <- Op.minus net.Net.place m m2.(index) v
		 else raise (Illegal_fire(t,m.(index),v))) net.Net.inArc;
    Data.iter (fun ((),(v,t,p)) ->
	       if t=tr then 
		 (*Printf.printf "%a-(%a)->%a " (Net.print_transition net) t Type.printH_expr (Obj.magic v) (Net.print_place net) p;*)
		 let index = Data.unsafe_rev p in
		 m2.(index) <- Op.add net.Net.place m m2.(index) v) net.Net.outArc;
    m2

  module OrderedMarking = struct
       type t = marking
       let compare t1 t2 =
	 let v = ref 0 in
	 Array.iteri (fun i y -> if !v = 0 then v := Op.compare_marking y t2.(i)) t1;
	 !v
    end
  module MarkingSet = Set.Make(OrderedMarking)

  let rec explore net s1 s2 =
    if MarkingSet.is_empty s1 then (s1,s2)
    else let m = MarkingSet.choose s1 in
	 let en = enabled net m in
	 List.fold_left (fun (s12,s22) t ->
	     let m2 = fire net m t in
             if MarkingSet.exists (fun x -> x=m2) s22 then (s12,s22)
	     else explore net (MarkingSet.add m2 s12) s22)
                        ((MarkingSet.remove m s1),(MarkingSet.add m s2)) en   
    
  let state_space net =
    let mset1 = MarkingSet.singleton (init net) in
    let mset2 = MarkingSet.empty in
    MarkingSet.fold (fun x l -> x::l) (snd @@ explore net mset1 mset2) []

  let rec trace net m n =
    let fr = Op.finalResult net m in
    if n<>0 && fr=None then 
      let en = enabled net m in
      if List.length en > 0 then
	let t = Op.choose net m en in
	let m1 = fire net m t in
	let tr,finish = trace net m1 (n-1) in
	((en,t,m1) :: tr,finish)
      else ([],fr)
    else ([],fr)

  let rec simulate net n =
    Type.list_create n (fun _ ->
                  let m0 = init net in
                  snd @@ trace net m0 (-1))
end

  

