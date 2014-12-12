open Type 

type expType = IntT | BoolT | DoubleT

let (mapType:expType StringMap.t ref) = ref StringMap.empty
(*
let add_int s = 
  (*Printf.printf "add int var %s\n" s;*)
  mapType := StringMap.add s IntT !mapType
let add_bool s = mapType := StringMap.add s BoolT !mapType
let add_double s = mapType := StringMap.add s DoubleT !mapType
let add_copy s1 s2 = try let t = StringMap.find s1 !mapType in
		     mapType := StringMap.add s2 t !mapType
  with Not_found -> ()
*)
let add_int s = ()
let add_double s = ()
let add_bool s = ()
let add_copy s1 s2 = ()


let find_action sl =
  List.fold_left (fun set (so,_,_,_) ->
    match so with None -> set
      | Some a -> StringSet.add a set) StringSet.empty sl

type constdef = (string*(intExpr option)) list * (string*(floatExpr option)) list

type prism_module = {
  name:string;
  varlist:(string * (intExpr*intExpr) * intExpr) list;
  actionlist: (string option * (stateFormula) * floatExpr * ((string*intExpr) list)) list;
  actionset: StringSet.t
}

type moduledef = Full of prism_module | Renaming of string*string*(string*string) list

type prism_file = moduledef list
