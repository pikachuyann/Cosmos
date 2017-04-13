open Type 

type expType = IntT | BoolT | DoubleT | IntVar | BoolVar | FunT | Clock

let allInt = ref false
let allReal = ref false

let (mapType:expType StringMap.t ref) = ref 
  (StringMap.empty
      |> StringMap.add "min" FunT
      |> StringMap.add "max" FunT)

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

let print_update f = function
  | IntUp i -> printH_expr f i
  | BoolUp b -> printH_expr f b                       
                                                   
type varKind = IntK of string * (int expr'*int expr') * int expr'
	       | BoolK of string * (int expr'*int expr') * int expr'
	       | ClockK of string 
  
type prism_module = {
  name:string;
  varlist: varKind list;
  actionlist: (string option * bool expr' * float expr' * ((string*update) list)) list;
  actionset: StringSet.t
}

type moduledef = Full of prism_module | Renaming of string*string*(string*string) list

type prism_file = moduledef list

let print_prism f m =
  Printf.fprintf f "module %s\n" m.name;

  List.iter (function
   | IntK(s,(l,m),init) ->
      Printf.fprintf f "\t%s: [%a..%a] init %a;\n" s printH_expr l printH_expr m printH_expr init;
   | _ -> failwith "unsupported"
            ) m.varlist;

  List.iter (fun (sto,guard,prob,update) -> 
    Printf.fprintf f "\t[%s] %a -> %a : " (sto |>>| "") printH_expr guard printH_expr prob; 
    
    ignore @@ List.fold_left (fun b (s,u) ->
      if b then Printf.fprintf f " & ";
      Printf.fprintf f "(%s'=%a)" s print_update u;
      true
    ) false update;
    Printf.fprintf f ";\n";
    ) m.actionlist;
  
  Printf.fprintf f "endmodule\n"
                            
