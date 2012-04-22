open Str
#load "Str.cma"

let dots = regexp ":\t"
let confintdel = regexp "\\[| , |\\]"

type result = { mutable mean : float;
		mutable stdDev : float;
		mutable confInt: float*float;
	      }

let dummyresult = {
  mean= 0. ;
  stdDev = 0. ;
  confInt = 0. , 0.
}


let parse_result f =
  let fs = open_in f in
  let result = dummyresult in
  (try while true do
      let str = input_line fs in
      let ls = split dots str in
      match ls with
	| "Estimated Value" :: v :: [] -> result.mean <- (float_of_string v)
	| "Standard Deviation" :: v :: [] -> result.stdDev <- (float_of_string v)
	| "Confidence interval" :: v :: [] -> (match split confintdel v with
	    | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b) 
	    | _ -> ())
	| _ -> ();
    done
   with
       End_of_file -> ());
  result;;
