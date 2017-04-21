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

module Guard = struct                           
  type sing = string * Type.cmp * int Type.expr'
  type conj = (Type.cmp * int Type.expr') list StringMap.t
  type t = conj list
                
  let fold f s c =
    StringMap.fold (fun v vl s2 ->
        List.fold_left (fun s3 (cmp,expr) ->
            f s3 (v,cmp,expr)
          ) s2 vl 
      ) c s
                   
  let map f c =
    StringMap.fold (fun v vl nsm ->
        let nv = ref v in
        let nl = List.map (fun (cmp,expr) ->
                     let v2,cmp2,expr2 = f (v,cmp,expr) in
                     nv := v2;(cmp2,expr2)) vl in
        StringMap.add !nv nl nsm
      ) c StringMap.empty
                  
  let to_list g =
    fold (fun l x -> x::l) [] g
                    
  let iter f g =
    fold (fun () a -> f a) () g
                    
  let print f g =
    g |> print_list2 (fun _ conj ->
             Printf.fprintf f "( ";
             ignore @@ fold (fun b (v,cmp,expr) ->
                         Printf.fprintf f "%s %s %a %a " (if b then "" else "&") v printH_cmp cmp printH_expr expr; false) true conj;
             Printf.fprintf f " )";
           ) " | " f

  let simplify_conj c =
    try
      StringMap.map (fun l ->
          List.sort_uniq (fun (cmp1,v1) (cmp2,v2) -> if cmp1 = cmp2 then compare v1 v2 else
                                                       compare cmp1 cmp2) l
          |> (function
              | [] -> []
              | x :: [] -> x :: []
              | (EQ, Int i1) :: (EQ, Int i2)::_ when i1 !=i2 -> raise Not_found
              | (EQ, Int i1) :: (SG, Int i2)::_ when i1 <= i2 -> raise Not_found
              | (EQ, Int i1) :: (SG, Int i2)::q -> (EQ, Int i1)::q
              | (EQ, Int i1) :: (SL, Int i2)::_ when i1 >= i2 -> raise Not_found
              | (EQ, Int i1) :: (SL, Int i2)::q -> (EQ, Int i1)::q
              | (EQ, Int i1) :: (GE, Int i2)::_ when i1 < i2 -> raise Not_found
              | (EQ, Int i1) :: (GE, Int i2)::q -> (EQ, Int i1)::q
              | (EQ, Int i1) :: (LE, Int i2)::_ when i1 > i2 -> raise Not_found
              | (EQ, Int i1) :: (LE, Int i2)::q -> (EQ, Int i1)::q

              | x -> print_endline "strange guard"; x
             )
        ) c
    |> fun x -> Some x 
    with Not_found -> None      

  let simplify g =
    List.fold_left (fun acc c -> match simplify_conj c with
                                   Some c2 -> c2::acc
                                 | None -> acc) [] g
                     
  let conj g1 g2 =
    List.fold_left (fun acc c1 ->
        acc@( List.map (fun c2->
                  c2 |> StringMap.union (fun v b1 b2 -> Some (b1@b2)) c1
                ) g2
              |> simplify )
      ) [] g1
                   
  let rec flatten x =
    let nb (v,cmp,i) = StringMap.singleton v [cmp,i] in 
    match x with
    | Bool true -> [ StringMap.empty ]
    | Bool false -> []
    | And (e1,e2) ->
       let l= flatten e1 
                and l2 = flatten e2 in
       conj l l2
    | Or (e1,e2) -> (flatten e1)@(flatten e2)
    | IntAtom ((IntName v),NEQ,j) -> [nb (v,SL,j);nb (v,SG,j)]
    | IntAtom ((IntName v),cmp,j) -> [nb (v,cmp,j)]  
    | FloatAtom ((CastInt (IntName v)),SL,j) -> [nb (v,SL,Ceil j)]
    | FloatAtom ((CastInt (IntName v)),LE,j) -> [nb (v,LE,Ceil j)]
    | FloatAtom ((CastInt (IntName v)),SG,j) -> [nb (v,SG,Floor j)]
    | FloatAtom ((CastInt (IntName v)),GE,j) -> [nb (v,GE,Floor j)]
                                                           
    | BoolName v -> [nb (v,SG,Int 0)]
    | Not (BoolName v) -> [nb (v,EQ,Int 0)]
    | Not e -> flatten (neg_bool e)
    | e-> printH_expr stderr e;
          failwith "Not yet supported guard shape"
                   
end
                            
type prism_module = {
  name:string;
  varlist: varKind list;
  actionlist: (string option * Guard.t * float expr' * ((string*update) list)) list;
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
    Printf.fprintf f "\t[%s] %a -> %a : " (sto |>>| "") Guard.print guard printH_expr prob; 
    
    ignore @@ List.fold_left (fun b (s,u) ->
      if b then Printf.fprintf f " & ";
      Printf.fprintf f "(%s'=%a)" s print_update u;
      true
    ) false update;
    Printf.fprintf f ";\n";
    ) m.actionlist;
  
  Printf.fprintf f "endmodule\n"
                            
