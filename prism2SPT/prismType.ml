open Type 

type expType = IntT | BoolT | DoubleT | IntVar | BoolVar

let (mapType:expType StringMap.t ref) = ref StringMap.empty

let add_int s = 
  (*Printf.printf "add int var %s\n" s;*)
  mapType := StringMap.add s IntT !mapType
let add_bool s = mapType := StringMap.add s BoolT !mapType
let add_double s = mapType := StringMap.add s DoubleT !mapType
let add_var s t = mapType := StringMap.add s t !mapType
let add_copy s1 s2 = try let t = StringMap.find s1 !mapType in
		     mapType := StringMap.add s2 t !mapType
  with Not_found -> ()

let find_action sl =
  List.fold_left (fun set (so,_,_,_) ->
    match so with None -> set
      | Some a -> StringSet.add a set) StringSet.empty sl

type constdef = (string*(int expr' option)) list * (string*(float expr' option)) list

type update = IntUp of int expr' | BoolUp of  bool expr'

type prism_module = {
  name:string;
  varlist:(string * (int expr'*int expr') * int expr') list;
  actionlist: (string option * bool expr' * float expr' * ((string*update) list)) list;
  actionset: StringSet.t
}

type moduledef = Full of prism_module | Renaming of string*string*(string*string) list

type prism_file = moduledef list
