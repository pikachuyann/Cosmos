type formula =
  Until of stateFormula*stateFormula
| BoundedUntil of stateFormula*cmp*floatExpr*stateFormula
and stateFormula =
  True | False | Not of stateFormula | IntAtom of intExpr*cmp*intExpr | RealAtom of floatExpr*cmp*floatExpr 
and cmp = EQ | SG | SL | GE |LE
and intExpr = IntName of string | Int of int
and floatExpr = FloatName of string | Float of float;;



let rec print_formula = function
  |Until(sf1,sf2) -> 
    print_sf sf1;
    print_string " U ";
    print_sf sf2
  |BoundedUntil(sf1,cmp,fexpr,sf2) ->
    print_sf sf1;
    print_string " U";
    print_cmp cmp;
    print_float_expr fexpr;
    print_string " ";
    print_sf sf2

and print_sf = function
  | True -> print_string "TRUE"
  | False -> print_string "FALSE"
  | Not(sf) -> print_string "!(";
    print_sf sf;
    print_string ")"
  | IntAtom(iexpr1,cmp,iexpr2) -> 
    print_int_expr iexpr1;
    print_cmp cmp;
    print_int_expr iexpr2;
  | RealAtom(fexpr1,cmp,fexpr2) -> 
    print_float_expr fexpr1;
    print_cmp cmp;
    print_float_expr fexpr2

and print_varForm _ =
  failwith "Not yet implemented"

and print_cmp = function
  | EQ -> print_string "="
  | SG -> print_string ">"
  | SL -> print_string "<"
  | GE -> print_string ">="
  | LE -> print_string "<="

and print_int_expr = function
  | IntName(s) -> print_string s;
  | Int(i) -> print_int i;

and print_float_expr = function
  | Float(x) -> print_float x;
  | _ ->  print_string "notyet implemented"
  
