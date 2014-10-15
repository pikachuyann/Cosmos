type prism_module = {
  name:string;
  varlist:(string * (int*int) * int) list;
  actionlist:((string*string*int) list * float * (string*int) list) list
}

(*
string * (string * (int*int) * int) list * ((string*string*int) list * float * (string*int) list) list
*)
