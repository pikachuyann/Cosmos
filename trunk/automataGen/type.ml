type formula =
  Until of stateFormula*stateFormula
| BoundedUntil of stateFormula*floatExpr*floatExpr*stateFormula
| Future of floatExpr*stateFormula
and stateFormula = True | False | Not of stateFormula 
		   | And of stateFormula*stateFormula | Or of stateFormula*stateFormula
		   | IntAtom of intExpr*cmp*intExpr | RealAtom of floatExpr*cmp*floatExpr 
and cmp = EQ | SG | SL | GE | LE
and intExpr = IntName of string | Int of int 
	      | Plus of intExpr*intExpr | Minus of intExpr*intExpr
	      | Mult of intExpr*intExpr
and floatExpr = FloatName of string | Float of float | Infty;;



let rec print_formula = function
  |Until(sf1,sf2) -> 
    print_sf sf1;
    print_string " U ";
    print_sf sf2
  |BoundedUntil(sf1,fexpr1,fexpr2,sf2) ->
    print_sf sf1;
    print_string " U[";
    print_float_expr fexpr1;
    print_string ";";
    print_float_expr fexpr2;
    print_string "]";
    print_sf sf2
  | Future(fexpr,sf) ->
    print_string "F ";
    print_float_expr fexpr;
    print_string " ";
    print_sf sf

and print_sf = function
  | True -> print_string "TRUE"
  | False -> print_string "TRUE"
  | Not(sf) -> print_string "!(";
    print_sf sf;
    print_string ")"
  | And(sf1,sf2) ->
    print_string "(";
    print_sf sf1;
    print_string " & ";
    print_sf sf2;
    print_string ")"
  | Or(sf1,sf2) ->
    print_string "(";
    print_sf sf1;
    print_string " | ";
    print_sf sf2;
    print_string ")"
  | IntAtom(iexpr1,cmp,iexpr2) -> 
    print_int_expr iexpr1;
    print_cmp cmp;
    print_int_expr iexpr2;
  | RealAtom(fexpr1,cmp,fexpr2) -> 
    print_float_expr fexpr1;
    print_cmp cmp;
    print_float_expr fexpr2

and print_cmp = function
  | EQ -> print_string "="
  | SG -> print_string ">"
  | SL -> print_string "<"
  | GE -> print_string ">="
  | LE -> print_string "<="

and print_int_expr = function
  | IntName(s) -> print_string s;
  | Int(i) -> print_int i;
  | Plus(e1,e2) -> print_string "(";
    print_int_expr e1;
    print_string "+";
    print_int_expr e2;
    print_string ")"
  | Minus(e1,e2) -> print_string "(";
    print_int_expr e1;
    print_string "-";
    print_int_expr e2;
    print_string ")"
  | Mult(e1,e2) -> print_string "(";
    print_int_expr e1;
    print_string "*";
    print_int_expr e2;
    print_string ")"

and print_float_expr = function
  | Float(x) -> print_float x;
  | _ ->  print_string "notyet implemented"
  
