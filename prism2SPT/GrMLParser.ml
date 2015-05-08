open Xml
open PetriNet
open StochasticPetriNet
open Type

let tree_of_pnml s =
     parse_file s

let rec find_child s e1 = function
    Element (s,_,[PCData e2])-> Some e2
  | Element (_,_,cl) -> List.fold_left (find_child s) e1 cl
  | PCData _ -> e1 

let find_child_list s xl =
    List.fold_left (find_child s) None xl

let find_at s l = try Some (List.assoc s l) with Not_found -> None
let find_id l = find_at "id" l
let find_type l = find_at "nodeType" l

let rec find_name_rec s e = function
    Element (x,_,cl) when s=x-> find_child_list "name" cl
  | Element (_,_,cl) -> List.fold_left (find_name_rec s) e cl
  | PCData _ -> e

let find_name s t = find_name_rec s None t

let idmap = ref StringMap.empty

let rec net_of_tree n = function
  | Element (name,alist,clist) as t -> begin
    print_endline name; 
    begin match name with
      "xml" | "model" ->
	print_endline name;
	List.iter (net_of_tree n) clist
	     
       |  "node" when find_type alist = Some "transition" ->
	 (match ((find_name "name" t),(find_id alist)) with
	 (Some name,Some id) -> begin
	   print_endline name;
	   idmap := StringMap.add id name !idmap;
	   Data.add (id,(StochasticPetriNet.Exp (Float 1.0),(Float 1.0),(Float 1.0))) n.Net.transition
	 end
         | _-> ()
       )

       |  "node" when find_type alist = Some "place" ->
	 ( match ((find_name "name" t),(find_name "marking" t),(find_id alist)) with
         | (Some name,Some im,Some id) ->  begin
	   idmap := StringMap.add id name !idmap;
	   print_endline name;
	   Data.add (name,Int (int_of_string im)) n.Net.place;
	 end
         | (Some name,None,Some id) -> begin
	   idmap := StringMap.add id name !idmap;
	   Data.add (name,Int 0) n.Net.place;
	 end
         | (None,None,Some _) -> 	 Printf.printf "new node";
	 | _ ->()

       )
       |  "arc" -> ( match ((find_id alist),(find_at "source" alist),(find_at "target" alist),(find_name "inscription" t)) with
         | (_,Some source,Some target,Some v) -> Net.add_arc n source target (Int (int_of_string v))
	 | (_,Some source,Some target,_) -> Printf.printf " (%s)->(%s)" source target ;
	   StochPTPrinter.print_spt_marcie "test.andl" n ;
	   Net.add_arc n source target (Int 1)
	 | _-> ()
    )

       | x-> Printf.printf "Dont know what to do with %s, ignore\n" x;
    end
end
    | _ ->()

