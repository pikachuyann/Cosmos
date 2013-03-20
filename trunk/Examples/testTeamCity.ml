open Str
open Printf
#load "str.cma"

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
        | "Prism Result" :: v :: [] -> let x = float_of_string v in
				       result.mean <- x;
				       result.confInt <- (x-.0.0001 , x+. 0.0001)
        | "Estimated value" :: v :: [] -> result.mean <- (float_of_string v)
        | "Standard deviation" :: v :: [] -> result.stdDev <- (float_of_string v)
        | "Confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)
        | "Binomiale confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)
        | _ -> ()
    done
   with
       End_of_file -> close_in fs);
  result;;

let invoke_cosmos opt gspn lha  =
  let cmd = sprintf "../../bin/Cosmos --level 0.9999 -v 0 %s %s %s" opt gspn lha in
  print_endline cmd;
  Sys.command cmd

let invoke_cosmos_silent opt gspn lha  =
  let cmd = sprintf "../../bin/Cosmos --level 0.9999 -v 0 %s %s %s" opt gspn lha in
  Sys.command cmd

let invoke_cosmos_prism opt gspn lha =
  let cmd = sprintf "../../bin/Cosmos -v 0 -s %s %s %s > Result.res" opt gspn lha in
  print_endline cmd;
  Sys.command cmd


let test_result n v =
  let result = parse_result "Result.res" in
  printf "result: %e\nconfint: [%e,%e]\n" result.mean (fst result.confInt) (snd result.confInt);
  if v > (fst result.confInt) & (snd result.confInt) > v
  then printf "##teamcity[testFinished name='%s' message='expected result %e is in confidence interval |[%e,%e|]']\n" n v (fst result.confInt) (snd result.confInt)
  else printf "##teamcity[testFailed name='%s' message='Test %s fail: expected result %e is outside confidence interval |[%e,%e|]']\n" n n v (fst result.confInt) (snd result.confInt)

let test_cosmos_gspn n v o =
  printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" n;
  flush stdout;
  let ret = invoke_cosmos o (n^".gspn") (n^".lha") in
  if ret <> 0 then printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" n n ret
  else test_result n v;;

let test_cosmos_grml n v o =
  printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" n;
  flush stdout;
  let ret = invoke_cosmos (o^" -g") (n^".grml") (n^"lha.grml")  in
  if ret <> 0 then printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" n n ret
  else test_result n v;;

let test_cosmos_prism n v o =
  printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" n;
  flush stdout;
  let ret = invoke_cosmos_prism (o^" -g") (n^".grml") (n^"lha.grml")  in
  if ret <> 0 then printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" n n ret
  else test_result n v;;

let test_coverage name v o n =
  let _ = invoke_cosmos_silent (" --tmp-status 2 --max-run 10 --batch 10 ") (name^".gspn") (name^".lha")  in
  print_endline ("Cosmos "^o^" -v 0 --tmp-status 3 "^name^".gspn "^name^".lha");
  let succ = ref 0 in
  for i = 1 to n do
    let _ = invoke_cosmos_silent (o^" -v 0 --tmp-status 3") (name^".gspn") (name^".lha") in
    let result = parse_result "Result.res" in
    if v > (fst result.confInt) & (snd result.confInt) > v then (
      incr succ;
      print_string "+";
    ) else print_string "-";
    flush stdout;
  done;
  printf "Coverage:\t%f\n" ((float !succ)/.(float n))



(*test_cosmos_gspn Sys.argv.(1) (float_of_string Sys.argv.(2)) Sys.argv.(3)*)
