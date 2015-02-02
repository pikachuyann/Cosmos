
let value_of_line l =
  try
    let eq = String.index l '=' in
    let semicolon = String.index l ';' in
    let v = float_of_string (String.sub l (eq+1) (semicolon-eq-1)) in
    Some ((String.trim (String.sub l 0 eq) ),v)
  with
    _-> None;;

let data_of_file fpath =
  if fpath = "" then []
  else begin
    let li = ref [] in
    let f = open_in fpath in
    try while true do 
	let l = input_line f in
	match value_of_line l with
	  None -> ()
	| Some x -> li:= x:: !li
      done;
	!li
    with End_of_file -> 
      close_in f;
      !li
  end

(*let data = try data_of_file "const.m" with _-> []*)

let func= [
"double power(double x,double y){return pow(x,y);}\n";
"double min(double x,double y){return fmin(x,y);}\n";
"double max(double x,double y){return fmax(x,y);}\n";
"void magicReset(){}";
]
