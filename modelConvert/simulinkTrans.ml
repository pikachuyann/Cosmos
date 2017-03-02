open Simulinkparser
open Printf

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

let skInfinitesimalLatency = ["Integrator"];;

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
                   if (incoming = 0) then s := BlockSet.add t !s;
                   initiaS q;
     and findblock id = function
       [] -> failwith "Un lien fait n'importe quoi"
       | t::q when t.blockid = id -> t
       | t::q -> findblock id q
     and processblock block =
       l := block::!l;
       s := BlockSet.remove block !s;
       let outgoingedges = ref (LinksSet.filter (fun x -> x.fromblock = block.blockid) !e) and
           incomingedges = ref (LinksSet.filter (fun x -> x.toblock = block.blockid) !e) and
           dealwithedgeout edge = begin
             e := LinksSet.remove edge !e;
             Hashtbl.replace c edge.toblock ( (Hashtbl.find c edge.toblock - 1) );
             if (Hashtbl.find c edge.toblock = 0) then s := BlockSet.add (findblock edge.toblock lB) !s;
             edge
           end and 
           dealwithedgeinc edge = begin (* Nettoyage pour les blocs infinitésimaux/… *)
             e := LinksSet.remove edge !e;
             edge
           end in
             outgoingedges := LinksSet.map dealwithedgeout !outgoingedges;
             incomingedges := LinksSet.map dealwithedgeinc !incomingedges;
     and infinitesimalLatencies = function
       [] -> ()
       | t::q when List.exists (fun x -> x=t.blocktype) skInfinitesimalLatency -> processblock t; infinitesimalLatencies q;
       | t::q -> infinitesimalLatencies q;
     and findLatencies = function
       [] -> []
       | t::q when List.exists (fun (x,y) -> x="DelayLength") t.values -> (float_of_string (List.assoc "DelayLength" t.values),t)::(findLatencies q)
       | t::q when List.exists (fun (x,y) -> x="DelayTime") t.values -> (float_of_string (List.assoc "DelayTime" t.values),t)::(findLatencies q)
       | t::q when t.blocktype="UnitDelay" -> (1.0,t)::(findLatencies q)
       | t::q -> findLatencies q
     and processLatencied = function
       [] -> ()
       | (l,t)::q when l = 0.0 -> processLatencied q
       | (l,t)::q -> processblock t; processLatencied q
     in
       initiaC lB;
       countEdges lL;
       initiaS lB;
       let latenciedBlocks = ref (findLatencies lB) in
         latenciedBlocks := List.sort (compare) !latenciedBlocks;
         processLatencied !latenciedBlocks;
         infinitesimalLatencies lB;
         while (not (BlockSet.is_empty !s)) do
           let vertex = BlockSet.choose !s in
             processblock vertex
         done;
         if (LinksSet.is_empty !e) then (List.rev !l, lL) else failwith "Cannot simulate this Simulink model"
;;

let generateCode (lB,lL) =
  let skCpp = open_out "SKModel.cpp" and
      mkImp = open_out "markingImpl.hpp" and
      skHpp = open_out "SKModel.hpp" in
  (* Impression des headers *)
  Printf.fprintf mkImp "#ifndef _MarkingImpl_HPP\n#define _MarkingImpl_HPP\n";
  Printf.fprintf mkImp "using namespace std;\n#include <string.h>\n";
  Printf.fprintf mkImp "#include \"marking.hpp\"\n#include \"markingTemplate.hpp\n";
  (* abstractBindingImpl *)
  Printf.fprintf mkImp "\nclass abstractBindingImpl {\npublic:\n};\n";
  (* abstractBindingIteratorImpl *)
  Printf.fprintf mkImp "\nclass abstractBindingIteratorImpl {\npublic:\n";
  Printf.fprintf mkImp "\tvoid reset(abstractMarkingImpl& m){};\n";
  Printf.fprintf mkImp "\tbool next(size_t& t, abstractMarkingimpl& m){ return false; };\n";
  Printf.fprintf mkImp "\tsize_t getIndex(){ return 0; };\n";
  Printf.fprintf mkImp "\tabstractBinding getBinding(){ return abstractBinding(); };\n};\n";
  (* abstractMarkingImpl *)
  Printf.fprintf mkImp "\nclass abstractMarkingImpl {\npublic:";
  let outputs_parse_regexp = Str.regexp "\\[\\([0-9]+\\), \\([0-9]+\\)\\]" in
  let rec genSignalNames = function
    [] -> ()
    | t::q -> begin
      Printf.fprintf mkImp "\n\t// Block %i - type %s (named %s) :" t.blockid t.blocktype t.name;
      try
        let numOfPorts = List.assoc "Ports" t.values in
          let didmatch = Str.string_match outputs_parse_regexp numOfPorts 0 in
            if didmatch then begin
              let nb = int_of_string@@ Str.matched_group 2 numOfPorts in
                for i = 1 to nb do
                  Printf.fprintf mkImp "\n\tfloat[] _BLOCK%i_OUT%i;" t.blockid i
                done
              end
           else Printf.fprintf mkImp "No Output."
       with Not_found -> begin print_string t.blocktype; failwith "No Ports ?" end
      end; genSignalNames q;
  in genSignalNames lB;
  Printf.fprintf mkImp "\n};\n";
  (* Footers *)
  Printf.fprintf mkImp "\n#endif";
(lB,lL);;

let testOutput (lB,lL) = Simulinkparser.printLaTeX stdout (lB,lL);;
