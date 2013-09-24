open Str
open Printf
#load "str.cma"

let cosmos_path = "../../bin/Cosmos"

let cosmos_options = ("--level 0.9999"^ ( 
  try
    let _ = Sys.getenv "COV" in
    " --gppflags \"--coverage -Wno-return-type\" --gppcmd clang++"
  with Not_found -> ""));;

(*" --gppflags --coverage --gppcmd clang++" 
 let _ = Sys.getenv "COV" in " --gppflags --coverage --gppcmd clang++"
*)


let dots = regexp ":\t"
let confintdel = regexp "\\[\\| , \\|\\]"

type result = { mutable mean : float;
		mutable conflevel : float;
                mutable stdDev : float;
                mutable confInt: float*float;
		mutable simtime: float;
		mutable systime: float;
		mutable nbRun: int;
		mutable nbSuccRun: int;
		mutable modelName: string;
		mutable propName: string;
		mutable batch: int;
		mutable nbJob:int;
              }

let print_result f sep rf =
  let ps ()= output_string f sep in
  let pf fl = output_string f (string_of_float fl) in
  let pi i = output_string f (string_of_int i) in
  Printf.fprintf f "%s%s%s%s" rf.modelName sep rf.propName sep;
  pi rf.nbRun; ps ();
  pi rf.nbSuccRun; ps ();
  pi rf.nbJob; ps ();
  pi rf.batch; ps ();
  pf rf.mean; ps ();
  pf rf.stdDev; ps ();
  pf (fst rf.confInt); ps ();
  pf (snd rf.confInt); ps ();
  pf rf.simtime; ps ();
  pf rf.systime;
  output_string f "\n";;

let dummyresult = {
  mean= 0. ;
  conflevel= 0.;
  stdDev = 0. ;
  confInt = 0. , 0.;
  simtime = 0.;
  systime = 0. ;
  nbRun = 0;
  nbSuccRun = 0;
  modelName = "dummyModel.grml";
  propName ="dummyProp.grml";
  batch = 0;
  nbJob = 0;
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
	| "Confidence level" :: v :: [] -> result.conflevel <- (float_of_string v)
        | "Confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)
        | "Binomiale confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> result.confInt <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)

	| "Time for simulation" :: v :: [] ->
	  let v2 = String.sub v 0 (String.length v -1) in
	  result.simtime <- (float_of_string v2)
	| "Total CPU time" :: v :: [] -> result.systime <- (float_of_string v)
	| "Total paths" :: v:: [] -> result.nbRun <- (int_of_string v)
	| "Accepted paths" :: v :: [] -> result.nbSuccRun <- (int_of_string v)
        | _ -> ()
    done
   with
       End_of_file -> close_in fs);
  result;;

let exec_cosmos model prop batch nbjob opt printcmd =
  let cmd = sprintf "%s %s %s --njob %i --batch %i -v 0 %s" cosmos_path model prop nbjob batch opt in
  if printcmd then print_endline cmd;
  ignore (Sys.command cmd);
  let result = parse_result "Result.res" in
  result.modelName <- model;
  result.propName <- prop;
  result.batch <- batch;
  result.nbJob <- nbjob;
  result;;

let call_cosmos opt =
   let cmd = sprintf "%s -v 0 %s %s" cosmos_path cosmos_options opt in
  print_endline cmd;
  Sys.command cmd

let call_cosmos_silent opt =
   let cmd = sprintf "%s -v 0 %s %s" cosmos_path cosmos_options opt in
  Sys.command cmd

let invoke_cosmos opt gspn lha  =
  call_cosmos (opt^" "^gspn^" "^lha)

let invoke_cosmos_silent opt gspn lha  =
  call_cosmos_silent (opt^" "^gspn^" "^lha)

let test_result n v =
  let result = parse_result "Result.res" in
  printf "result: %e\nconfint: [%e,%e]\n" result.mean (fst result.confInt) (snd result.confInt);
  if v > (fst result.confInt) & (snd result.confInt) > v
  then printf "##teamcity[testFinished name='%s' message='expected result %e is in confidence interval |[%e,%e|]']\n" n v (fst result.confInt) (snd result.confInt)
  else printf "##teamcity[testFailed name='%s' message='Test %s fail: expected result %e is outside confidence interval |[%e,%e|]']\n" n n v (fst result.confInt) (snd result.confInt)

let test_cosmos testname opt v = 
   printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" testname;
  flush stdout;
  let ret = call_cosmos opt in
  if ret <> 0 then printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" testname testname ret
  else test_result testname v;;

let test_cosmos_gspn n v o =
  test_cosmos n (o^" "^n^".gspn"^" "^n^".lha") v

let test_cosmos_grml n v o =
  test_cosmos n (o^" -g "^n^".grml"^" "^n^"lha.grml") v
 
let test_cosmos_prism n v o =
  test_cosmos n (o^" -g --prism "^n^".grml"^" "^n^"lha.grml > Result.res") v

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
