
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
                | DivF of floatExpr*floatExpr;;

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

type constdef = (string*(intExpr option)) list * (string*(floatExpr option)) list

type prism_module = {
  name:string;
  varlist:(string * (intExpr*intExpr) * intExpr) list;
  actionlist: (string option * ((string*cmp*intExpr) list) * floatExpr * ((string*intExpr) list)) list;
  actionset: StringSet.t
}

type prism_file = prism_module list


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


let print_token f = function 
  | Int 0 -> ()
  | Int 1 -> output_string f "•" 
  | Int 2 -> output_string f "••"
  | Int 3 -> output_string f "•••"
  | i -> printH_int_expr f i
