
let (|>) x f = f x 
let (|>>) x f = match x with 
    Some y -> f y
  | None -> None

let rec print_list f c = function
  | [] -> ()
  | [t] -> f t;
  | t::q -> f t; c (); print_list f c q

type stateFormula = True | False | Not of stateFormula 
                    | And of stateFormula*stateFormula
		    | Or of stateFormula*stateFormula
                    | IntAtom of intExpr*cmp*intExpr  

and cmp = EQ | SG | SL | GE | LE | NEQ
and intExpr = IntName of string | Int of int 
              | Plus of intExpr*intExpr | Minus of intExpr*intExpr
              | Mult of intExpr*intExpr
and floatExpr = FloatName of string | Float of float
                | CastInt of intExpr
                | MultF of floatExpr*floatExpr
                | PlusF of floatExpr*floatExpr 
                | MinusF of floatExpr*floatExpr
                | DivF of floatExpr*floatExpr
		| ExpF of floatExpr;;


let neg_cmp = function 
  | EQ -> NEQ  
  | SG -> LE
  | SL -> GE
  | GE -> SL
  | LE -> SG
  | NEQ-> EQ

let rec neg_bool = function
  | True -> False
  | False -> True
  | Not e -> e
  | IntAtom (ie1,cmp,ie2) -> IntAtom (ie1,neg_cmp cmp,ie2)
  | And (e1,e2) -> Or (neg_bool e1,neg_bool e2)
  | Or (e1,e2) -> And (neg_bool e1,neg_bool e2)

let rec simp_int = function
  | Plus(e1,e2) as x -> (match (simp_int e1),(simp_int e2) with
      Int y,Int z -> Int (y+z) | _ -> x)
  | Minus(e1,e2) as x -> (match (simp_int e1),(simp_int e2) with
      Int y,Int z -> Int (y-z) | _ -> x)
  | Mult(e1,e2) as x -> (match (simp_int e1),(simp_int e2) with
      Int y,Int z -> Int (y*z) | _ -> x) 
  | x -> x

let gez x = match simp_int x with
  | Int y when y>=0 -> true
  | _ -> false
let sgz x = match simp_int x with
  | Int y when y>0 -> true
  | _ -> false

let incr_int z = simp_int (Plus(z,Int 1))


module StringOrdered = struct type t=string let compare=compare end
module StringSet = Set.Make(StringOrdered)
module StringMap = Map.Make(StringOrdered)
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


let printH_cmp f = function 
  | EQ -> output_string f "="  
  | SG -> output_string f ">" 
  | SL -> output_string f "<" 
  | GE -> output_string f ">=" 
  | LE -> output_string f "<=" 
  | NEQ-> output_string f "!=" 

let rec printH_int_expr f = function
  | IntName(s) -> output_string f s;
  | Int(i) -> Printf.fprintf f "%i" i;
  | Plus(e1,e2) -> Printf.fprintf f "(%a+%a)" 
    printH_int_expr e1 
    printH_int_expr e2
  | Minus(e1,e2) -> Printf.fprintf f "(%a-%a)" 
    printH_int_expr e1 
    printH_int_expr e2
  | Mult(e1,e2) -> Printf.fprintf f "(%a*%a)" 
    printH_int_expr e1 
    printH_int_expr e2

and printH_float_expr f = function
  | FloatName(x) -> output_string f x;
  | Float(x) -> Printf.fprintf f "%f" x;
  | CastInt(x) -> printH_int_expr f x;
  | PlusF(e1,e2) -> Printf.fprintf f "(%a+%a)" 
    printH_float_expr e1 
    printH_float_expr e2
  | MinusF(e1,e2) -> Printf.fprintf f "(%a-%a)" 
    printH_float_expr e1 
    printH_float_expr e2
  | MultF(e1,e2) -> Printf.fprintf f "(%a*%a)" 
    printH_float_expr e1 
    printH_float_expr e2
  | DivF(e1,e2) -> Printf.fprintf f "(%a/%a)" 
    printH_float_expr e1 
    printH_float_expr e2
  | ExpF(x) -> Printf.fprintf f "exp(%a)" printH_float_expr x

let rec printH_stateFormula f = function 
  | True -> output_string f " true " 
  | False -> output_string f " false "
  | Not e-> Printf.fprintf f "(!%a)" printH_stateFormula e
  | And (e1,e2) -> Printf.fprintf f "(%a & %a)" 
    printH_stateFormula e1
    printH_stateFormula e2
  | Or (e1,e2) -> Printf.fprintf f "(%a | %a)" 
    printH_stateFormula e1
    printH_stateFormula e2
  | IntAtom (e1,c,e2) -> Printf.fprintf f "(%a %a %a)" 
    printH_int_expr e1
    printH_cmp c
    printH_int_expr e2  

let print_token f = function 
  | Int 0 -> ()
  | Int 1 -> output_string f "•" 
  | Int 2 -> output_string f "••"
  | Int 3 -> output_string f "•••"
  | i -> printH_int_expr f i;;

let rec eval_name data fe= 
  let enf = eval_name data in match fe with
    | FloatName(x) -> begin try let v = List.assoc x data in Float (v) with Not_found -> fe end
    | Float(x) -> fe
    | CastInt(x) -> fe
    | PlusF(e1,e2) -> PlusF(enf e1,enf e2)
    | MinusF(e1,e2) ->  MinusF(enf e1,enf e2)
    | MultF(e1,e2) ->  MultF(enf e1,enf e2)
    | DivF(e1,e2) -> DivF(enf e1,enf e2)
    | ExpF(x) -> ExpF(enf x)

type triggerT = Imm | Delay of floatExpr | RAction of string


type simulink_trans_label = {
  trigger: triggerT;
  write:  string list;
  update: string list;
}

let empty_trans_label = {
  trigger = Imm;
  write = [];
  update = [];
}

let rec print_list f =function
  | [] -> ()
  | [t] -> Printf.fprintf f "%s" t
  | t::q -> Printf.fprintf f "%s,%a" t print_list q

let print_option f so  =
  match so with None -> () | Some s -> Printf.fprintf f "%s" s


let print_option2 def f so  =
  match so with None -> output_string f def | Some s -> Printf.fprintf f "%s" s


let stateasso s l =
  try (match List.assoc s l with
    Some n -> n
  | None -> string_of_int s)
  with Not_found -> ""

let stateasso2 s2 l =
  match s2 with None -> "" | Some s ->
  try (match List.assoc s l with
    Some n -> n
  | None -> string_of_int s)
  with Not_found -> ""

let print_label_simulink f trans = match trans.trigger with
    Imm -> Printf.fprintf f "#,![%a],{%a}" print_list trans.write print_list trans.update
  | Delay(s) -> Printf.fprintf f "wait(%a),![%a],{%a}" printH_float_expr s print_list trans.write print_list trans.update
  | RAction(s) -> Printf.fprintf f "?%s,![%a],{%a}" s print_list trans.write print_list trans.update

let print_trans_simulink sl f (ssid,src,trans,dst) =
  Printf.fprintf f "\t%s --(%a)->%s\n" (stateasso2 src sl) print_label_simulink trans (stateasso dst sl);;
