open Simulinkparser

module OrderedBlocks =
  struct
    type t = Simulinkparser.block
    let compare x y = compare x.blockid y.blockid
end
module BlockSet = Set.Make(OrderedBlocks)

module OrderedLinks =
  struct
    type t = Simulinkparser.simulinkLink
    let compare x y = compare x y
end
module LinksSet = Set.Make(OrderedLinks)

let topologicSort (lB,lL) =
  let e = ref (LinksSet.of_list lL) in
  let l = ref [] and s = ref BlockSet.empty in
    let c = Hashtbl.create (List.length lB) in
     let rec initiaC = function
       [] -> ()
       | t::q -> Hashtbl.add c t.blockid 0; initiaC q
     and countEdges = function
       [] -> ()
       | t::q -> Hashtbl.replace c t.toblock (1 + Hashtbl.find c t.toblock); countEdges q;
     and initiaS = function
       [] -> ()
       | t::q -> let incoming = Hashtbl.find c t.blockid in
                   if (incoming == 0) then s := BlockSet.add t !s;
                   initiaS q;
     and findblock id = function
       [] -> failwith "Un lien fait n'importe quoi"
       | t::q when t.blockid == id -> t
       | t::q -> findblock id q
     and processblock block =
       l := block::!l;
       s := BlockSet.remove block !s;
       let incomingedges = ref (LinksSet.filter (fun x -> x.fromblock == block.blockid) !e) and
           dealwithedge edge = begin
             e := LinksSet.remove edge !e;
             Hashtbl.replace c edge.toblock ( (Hashtbl.find c edge.toblock - 1) );
             if (Hashtbl.find c edge.toblock == 0) then s := BlockSet.add (findblock edge.toblock lB) !s;
             edge
           end in
             incomingedges := LinksSet.map dealwithedge !incomingedges;
             print_int (LinksSet.cardinal !e);
     in
       initiaC lB;
       countEdges lL;
       initiaS lB;
       while (not (BlockSet.is_empty !s)) do
         let vertex = BlockSet.choose !s in
           processblock vertex
       done;
       if (LinksSet.is_empty !e) then !l else failwith "Cannot simulate this Simulink model"
;;


