open Str
open Printf
(*#load "Str.cma"*)

let dots = regexp ":\t"
let confintdel = regexp "\\[\\| , \\|\\]"

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
	| "Confidence interval" :: v :: [] -> 
	  (match split confintdel v with
	    | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b) 
	    | _ -> printf "Fail to parse confidence interval %s\n" v)
	| _ -> ();
    done
   with
       End_of_file -> close_in fs);
  result;;

let test_result n v =
  let result = parse_result "Result.res" in
  printf "result: %f\nconfint: [%f,%f]\n" result.mean (fst result.confInt) (snd result.confInt);
  if v > (fst result.confInt) & (snd result.confInt) > v 
  then printf "##teamcity[testFinished name='%s' message='expected result %f is in confidence interval |[%f,%f|]']\n" n v (fst result.confInt) (snd result.confInt) 
  else printf "##teamcity[testFailed name='%s' message='Test %s fail: expected result %f is outside confidence interval |[%f,%f|]']\n" n n v (fst result.confInt) (snd result.confInt) 

let test_cosmos_gspn n v o =
  printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" n;
  flush stdout;
  let ret = Sys.command (sprintf "../../bin/Cosmos %s %s.gspn %s.lha" o n n) in
  if ret <> 0 then printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" n n ret
  else test_result n v
