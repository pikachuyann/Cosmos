
module type DATA =
sig
  exception Empty
  type 'a key
  type ('a, 'b, 'k) t
  val create : unit -> ('a, 'b, 'k) t
  val acca : ('a, 'b, 'k) t -> 'k key -> 'a * 'b
  val index : ('a, 'b, 'k) t -> 'a -> 'k key
  val acc : ('a, 'b, 'k) t -> 'a -> 'b
  val updatea : 'k key -> 'b -> ('a, 'b, 'k) t -> unit
  val add : 'a * 'b -> ('a, 'b, 'k) t -> unit
  val foldi : ('a -> 'k key -> 'b * 'c -> 'a) -> 'a -> ('b, 'c, 'k) t -> 'a
  val fold : ('a -> 'b * 'c -> 'a) -> 'a -> ('b, 'c, 'k) t -> 'a
  val iteri : ( 'k key -> 'a * 'b -> unit ) -> ('a, 'b, 'k) t -> unit
  val iter : ( 'a * 'b -> unit ) -> ('a, 'b, 'k) t -> unit
  val map :  ('a, 'b, 'k) t -> ('b -> 'c) -> ('a, 'c, 'k) t
  val adds : ('a, 'b, 'k) t -> ('a, 'b, 'l) t -> unit
  val size : ('a, 'b, 'k) t -> int
  val sample : ('a, 'b, 'k) t -> 'a * 'b
  val copy : ('a, 'b, 'k) t -> ('a, 'b, 'l) t
end

module Data:DATA = 
struct
  exception Empty
  type ('a,'b, 'k) t = { 
    mutable table:('a * 'b) array option;
    mutable hash: ('a,int) Hashtbl.t;
    mutable size:int
  }
  type 'k key= int

  let create () = {table = None; hash = Hashtbl.create 10; size=0}
  let acca t i = match t.table with
      None -> raise Empty
    | Some(t) -> t.(i)
  let index t s = Hashtbl.find t.hash s
  let acc t s = 
    index t s
    |> acca t
    |> snd

  let updatea i v t =
    match t.table with
      None -> raise Empty
    | Some(ti) ->
      let a,_ = ti.(i) in
      ti.(i) <- (a,v) 
      
  let rec add (a,b) t = match t.table with
      None -> t.table <- Some(Array.make 10 (a,b));
        t.size <- 1;
	Hashtbl.add t.hash a 0;
    | Some(t1) when Array.length t1 > t.size ->
      t1.(t.size) <- (a,b);
      Hashtbl.add t.hash a t.size;
      t.size <- t.size +1
    | Some(t1) -> 
      let t2 = Array.make (2*t.size) t1.(0) in
      Array.blit t1 0 t2 0 t.size;
      t.table <- Some(t2);
      add (a,b) t

  let foldi f e t = match t.table with
      None -> e
    | Some t1 -> let buff = ref e in
                 for i = 0 to t.size-1 do
		   (* Here we cannot used t.(i) in case f reschedules the table*)
                   buff := f !buff i (acca t i); 
                 done;
                 !buff

  let fold f e t = foldi (fun b _ a -> f b a) e t
  let iteri f t = foldi (fun _ i a -> f i a) () t
  let iter f t = foldi (fun _ _ a -> f a) () t

  let adds t1 t2 =
    iter (fun x -> add x t1) t2

  let map t1 f =
    let t2 = create () in
    iter (fun (x,y) -> add (x,f y) t2) t1;
    t2

  let copy t1 = map t1 (fun x -> x)

  let size t = t.size
  let sample d = match d.table with
      Some(t) -> t.(0)
    | None -> raise Empty
end


module type NET = sig
    exception InvalidPlaceName of string
    exception InvalidTransitionName of string
    type placekey
    type transitionkey
    type inArcKey
    type outArcKey
    type inhibArcKey
    type ('a, 'b, 'c, 'd) t = {
      mutable def : 'd option;
      place : (string, 'a, placekey) Data.t;
      transition : (string, 'b , transitionkey) Data.t;
      inArc    : (unit, 'c * (placekey Data.key)* (transitionkey Data.key),inArcKey) Data.t;
      inhibArc : (unit, 'c * (placekey Data.key)* (transitionkey Data.key),outArcKey) Data.t;
      outArc   : (unit, 'c * (transitionkey Data.key)* (placekey Data.key),inhibArcKey) Data.t;
    }
    val create : unit -> ('a, 'b, 'c, 'd) t
    val add_inArc : ('a, 'b, 'c, 'd) t -> string -> string -> 'c -> unit
    val add_outArc : ('a, 'b, 'c, 'd) t -> string -> string -> 'c -> unit
    val add_inhibArc : ('a, 'b, 'c, 'd) t -> string -> string -> 'c -> unit
    val add_arc : ('a, 'b, 'c, 'd) t -> string -> string -> 'c -> unit
      
    val merge :
      ('a, 'b, 'c, 'd) t ->
      ('a, 'b, 'c, 'e) t ->
      (string * string) list ->
      (string * string) list ->
      ('d option -> 'e option -> 'f option) ->
      ('a -> 'a -> 'a) -> ('b -> 'b -> 'b) -> ('a, 'b, 'c, 'f) t
 end

module Net:NET =
struct
  exception InvalidPlaceName of string
  exception InvalidTransitionName of string
  type placekey = unit 
  type transitionkey = unit 
  type inArcKey = unit 
  type outArcKey = unit 
  type inhibArcKey = unit 

  type ('a, 'b, 'c, 'd) t = {
    mutable def : 'd option;
    place : (string, 'a, placekey) Data.t;
    transition : (string, 'b , transitionkey) Data.t;
    inArc    : (unit, 'c * (placekey Data.key)* (transitionkey Data.key),inArcKey) Data.t;
    inhibArc : (unit, 'c * (placekey Data.key)* (transitionkey Data.key),outArcKey) Data.t;
    outArc   : (unit, 'c * (transitionkey Data.key)* (placekey Data.key),inhibArcKey) Data.t;
  }

  let create () = {
    def = None;
    place = Data.create ();
    transition = Data.create ();
    inArc = Data.create ();
    inhibArc = Data.create ();
    outArc = Data.create ();
  }

  let add_inArc net s1 s2 v =
    let i1 = try Data.index net.place s1 with Not_found -> raise @@ InvalidPlaceName(s1)  
    and i2 = try Data.index net.transition s2 with Not_found -> raise @@ InvalidTransitionName(s2) in
    Data.add ((),(v,i1,i2)) net.inArc
      
  let add_outArc net s1 s2 v =
    let i1 = try Data.index net.transition s1 with Not_found -> raise @@ InvalidTransitionName(s1)
    and i2 = try Data.index net.place s2 with Not_found -> raise @@ InvalidPlaceName(s2) in
    Data.add ((),(v,i1,i2)) net.outArc

  let add_inhibArc net s1 s2 v =
    let i1 = try Data.index net.place s1 with Not_found -> raise @@ InvalidPlaceName(s1)  
    and i2 = try Data.index net.transition s2 with Not_found -> raise @@ InvalidTransitionName(s2) in
    Data.add ((),(v,i1,i2)) net.inhibArc
  
  let add_arc net s1 s2 v =
    try add_inArc net s1 s2 v with
	_ -> add_outArc net s1 s2 v

  let merge net1 net2 pequiv tequiv fdef fplace ftrans =
    let net3 = create () in
    net3.def <- fdef net1.def net2.def;
    (* Copy place *)
    Data.iter (fun (np,vp) ->
      if not @@ List.exists (fun (p1,_) -> p1=np) pequiv then Data.add (np,vp) net3.place) net1.place;
    Data.iter (fun (np,vp) ->
      if not @@ List.exists (fun (_,p2) -> p2=np) pequiv then Data.add (np,vp) net3.place) net2.place;
    Data.iter (fun (np,vp) ->
      try 
	let np2 = List.assoc np pequiv in
	Data.add (np,fplace vp (Data.acc net2.place np2)) net3.place;
      with Not_found -> ()
    ) net1.place;
	
    (* Copy transition *)
    Data.iter (fun (nt,vt) ->
      if not @@ List.exists (fun (t1,_) -> t1=nt) tequiv then Data.add (nt,vt) net3.transition) net1.transition;
    Data.iter (fun (nt,vt) ->
      if not @@ List.exists (fun (_,t2) -> t2=nt) tequiv then Data.add (nt,vt) net3.transition) net2.transition;
    Data.iter (fun (nt,vt) ->
      try 
	let nt2 = List.assoc nt tequiv in
	Data.add (nt,ftrans vt (Data.acc net2.transition nt2)) net3.transition;
      with Not_found -> ()
    ) net1.transition;

    Data.iter (fun (_,(v,p,t)) ->
      let pn,_ = Data.acca net1.place p
      and tn,_ = Data.acca net1.transition t in
      Data.add ((),(v,Data.index net3.place pn, Data.index net3.transition tn)) net3.inArc) net1.inArc;

    Data.iter (fun (_,(v,p,t)) ->
      let pn,_ = Data.acca net2.place p
      and tn,_ = Data.acca net2.transition t in
      Data.add ((),(v,Data.index net3.place pn, Data.index net3.transition tn)) net3.inArc) net2.inArc;


    net3

end



(*
let t = Data.create ();;

Data.add ("test","toto") t;;
t;;
Data.index t "test";;
Data.index t "tessdft";;
*)
(*
type pt = (int,unit,unit,unit) Net.t;;
type spt = (int,float,unit,unit) Net.t;;

let (testpt:spt) = Net.create ();;

Data.add ("p1",1) testpt.Net.place;;
Data.add ("t1",1.0) testpt.Net.transition;;

Net.add_arc testpt "t1" "p1" ();;

testpt.Net.place;;

Data.acc testpt.Net.place "p1";;
Data.size testpt.Net.outArc;;
Data.index testpt.Net.place "p1";;
*)



