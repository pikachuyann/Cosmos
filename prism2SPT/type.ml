
let (|>) x f = f x 
let (|>>) x f = match x with 
    Some y -> f y
  | None -> None
let (|<>|) f (x,y) = f x y

let rec string_of_list sep f = function
  | [] -> ""
  | [t] -> f t
  | t::q -> Printf.sprintf "%s%s%s" (f t) sep (string_of_list sep f q)

let print_list sep f l =
  output_string f (string_of_list sep (fun x ->x) l)

let rec selectL fb = function
  | [] -> raise Not_found
  | t::q when fb t -> (t,q)
  | t::q -> let t2,q2 = selectL fb q in
	    (t2,t::q2)

let print_option2 def f so  =
  match so with None -> output_string f def | Some s -> Printf.fprintf f "%s" s

let string_of_option def so  =
  match so with None -> def | Some s -> s


let print_option f so  = print_option2 "" f so

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
		| ExpF of floatExpr
		| FunCall of string*(floatExpr list) ;;

let rec iterFloat f y = 
  let ri = iterFloat f in match y with
    | FloatName(x) -> f y;
    | Float(x) -> f y;
    | CastInt(x) -> f y;
    | PlusF(e1,e2) -> PlusF(ri e1,ri e2) |> f
    | MinusF(e1,e2) -> MinusF(ri e1,ri e2) |> f
    | MultF(e1,e2) -> MultF(ri e1,ri e2) |> f
    | DivF(e1,e2) -> DivF(ri e1,ri e2) |> f
    | ExpF(x) -> ExpF(ri x) |> f 
    | FunCall(fu,l) -> FunCall(fu,List.map ri l) |> f
	       
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
let add_multi e t =
  try let i = StringMap.find e t in
      StringMap.remove e t 
  |> StringMap.add e (i+1) with
    Not_found -> StringMap.add e 1 t
let add_set t s =
  StringSet.fold add_multi t s

let print_set sep f s=
  ignore (StringSet.fold (fun x c -> if c then output_string f sep;
    output_string f x;true) s false)

let print_multi sep f s=
  ignore (StringMap.fold (fun x y c -> if c then output_string f sep;
    Printf.fprintf f "%s:%i" x y;true) s false)

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
  | FunCall(fu,[]) ->  Printf.fprintf f "%s()" fu;
  | FunCall(fu,t::q) ->  Printf.fprintf f "%s(%a" fu printH_float_expr t;
    List.iter (fun x-> Printf.fprintf f ",%a" printH_float_expr x) q;
    output_string f ")"

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
  | i -> printH_int_expr f i
