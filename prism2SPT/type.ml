
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

module StringOrdered = struct type t=string let compare=compare end
module StringSet = Set.Make(StringOrdered)

type prism_module = {
  name:string;
  varlist:(string * (int*int) * int) list;
  actionlist: (string option * ((string*cmp*int) list) * floatExpr * ((string*intExpr) list)) list;
  actionset: StringSet.t
}

type prism_file = prism_module list

let rec printH_int_expr = function
  | IntName(s) -> print_string s;
  | Int(i) -> print_int i;
  | Plus(e1,e2) -> print_string "(";
    printH_int_expr e1;
    print_string "+";
    printH_int_expr e2;
    print_string ")"
  | Minus(e1,e2) -> print_string "(";
    printH_int_expr e1;
    print_string "-";
    printH_int_expr e2;
    print_string ")"
  | Mult(e1,e2) -> print_string "(";
    printH_int_expr e1;
    print_string "*";
    printH_int_expr e2;
    print_string ")"

and printH_float_expr = function
  | FloatName(x) -> print_string x;
  | Float(x) -> print_float x;
  | CastInt(x) -> printH_int_expr x;
  | PlusF(e1,e2) -> print_string "(";
    printH_float_expr e1;
    print_string "+";
    printH_float_expr e2;
    print_string ")"
  | MinusF(e1,e2) -> print_string "(";
    printH_float_expr e1;
    print_string "-";
    printH_float_expr e2;
    print_string ")"
  | MultF(e1,e2) -> print_string "(";
    printH_float_expr e1;
    print_string "*";
    printH_float_expr e2;
    print_string ")"
  | DivF(e1,e2) -> print_string "(";
    printH_float_expr e1;
    print_string "/";
    printH_float_expr e2;
    print_string ")"
