open Simulinkparser

module OrderedBlocks =
  struct
    type t = block
    let compare x y = compare x.blockid y.blockid
end
module BlockSet = Set.Make(OrderedBlocks)

module OrderedLinks =
  struct
    type t = simulinkLink
    let compare x y = compare x y
end
module LinksSet = Set.Make(OrderedLinks)

let topologicSort (lB,lL) =
  let v = ref (LinksSet.of_list lL) in
  let l = ref [] and s = ref BlockSet.empty in
    let c = Hashtbl.create (List.length lB) in
     ()
;;


