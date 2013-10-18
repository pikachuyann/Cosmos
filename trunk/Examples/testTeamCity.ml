open Str
open Printf
#load "unix.cma"
#load "str.cma"

exception CmdFail of int


let teamCity = ref true

let _ = if (Array.length Sys.argv) >1 then teamCity := false

let cosmos_path = "../../bin/Cosmos"

let cosmos_options = ("--level 0.9999"^ ( 
  try
    let _ = Sys.getenv "COV" in
    " --gppflags \"--coverage -Wno-return-type\" --gppcmd clang++"
  with Not_found -> ""));;

(*" --gppflags --coverage --gppcmd clang++" 
 let _ = Sys.getenv "COV" in " --gppflags --coverage --gppcmd clang++"
*)

let pe () = print_char (char_of_int 0x1b)
let print_color s c =
  pe ();
  printf "[1;%im%s" c s;
  pe ();
  print_string "[0m"

let dots = regexp ":\\(\t\\)?"
let confintdel = regexp "\\[\\| , \\|\\]"

type haslr =
{
  mutable mean: float;
  mutable stdDev: float;
  mutable confInterval: float*float;
}

let print_haslr f sep (s,h) =
  Printf.fprintf f "%s%s%f%s%f%s%f%s%f%s" s sep h.mean sep h.stdDev sep (fst h.confInterval) sep (snd h.confInterval) sep

let dummy_haslr = {
  mean =0.;
  stdDev =0.;
  confInterval = 0.,0.
}

let rec check_result l = function
  | [] -> true
  | (lab,v)::q -> try 
		    let h = List.assoc lab l in
		    if v > (fst h.confInterval) & (snd h.confInterval) > v then check_result l q
		    else false
    with x -> false

let rec print_readable l =  function
  | [] -> ""
  | (lab,v)::q -> try 
		    let h = List.assoc lab l in
		    if v > (fst h.confInterval) & (snd h.confInterval) > v then (
		      Printf.sprintf  "%s: Value %e is inside confidence interval [%e,%e]\n%s" lab v (fst h.confInterval) (snd h.confInterval) (print_readable l q)
		    ) else (
		      Printf.sprintf "%s: Value %e is outside confidence interval [%e,%e]\n%s" lab v (fst h.confInterval) (snd h.confInterval) (print_readable l q)
		  )
    with _ -> print_readable l q

type result = {
  mutable haslResult : (string*haslr) list;
  mutable conflevel : float;
  mutable simtime: float;
  mutable systime: float;
  mutable nbRun: int;
  mutable nbSuccRun: int;
  mutable modelName: string;
  mutable propName: string;
  mutable batch: int;
  mutable nbJob:int;
  mutable date: string;
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
  List.iter (print_haslr f sep) rf.haslResult;
  pf rf.simtime; ps ();
  pf rf.systime; ps ();
  output_string f rf.date;
  output_string f "\n";;

let dummyresult = {
  haslResult=[];
  conflevel= 0.;
  simtime = 0.;
  systime = 0. ;
  nbRun = 0;
  nbSuccRun = 0;
  modelName = "dummyModel.grml";
  propName ="dummyProp.grml";
  batch = 0;
  nbJob = 0;
  date = "dummyDate";
}

let parse_result f =
  let fs = open_in f in
  let result = dummyresult in
  (try while true do
      let str = input_line fs in
      let ls = split_delim dots str in
      match ls with
        | "Prism Result" :: v :: [] -> let x = float_of_string v in
				       (snd (List.hd result.haslResult)).mean <- x;
				       (snd (List.hd result.haslResult)).confInterval <- (x-.0.0001 , x+. 0.0001)
        | "Estimated value" :: v :: [] -> (snd (List.hd result.haslResult)).mean <- (float_of_string v)
        | "Standard deviation" :: v :: [] -> (snd (List.hd result.haslResult)).stdDev <- (float_of_string v)
	| "Confidence level" :: v :: [] -> result.conflevel <- (float_of_string v)
        | "Confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> (snd (List.hd result.haslResult)).confInterval <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)
        | "Binomiale confidence interval" :: v :: [] ->
          (match split confintdel v with
            | a::b::_ -> (snd (List.hd result.haslResult)).confInterval <- (float_of_string a , float_of_string b)
            | _ -> printf "Fail to parse confidence interval %s\n" v)

	| "Time for simulation" :: v :: [] ->
	  let v2 = String.sub v 0 (String.length v -1) in
	  result.simtime <- (float_of_string v2)
	| "Total CPU time" :: v :: [] -> result.systime <- (float_of_string v)
	| "Total paths" :: v :: [] -> result.nbRun <- (int_of_string v)
	| "Accepted paths" :: v :: [] -> result.nbSuccRun <- (int_of_string v)
        | s1 :: [""] -> print_endline s1;
	  result.haslResult <- (s1,{dummy_haslr with mean=0.0}):: result.haslResult 
	| _ -> ()
    done
   with
       End_of_file -> close_in fs);
  result;;

let string_date () =
  let tm = Unix.localtime (Unix.gettimeofday ()) in
  Printf.sprintf "%i/%i/%i %i:%i:%i" tm.Unix.tm_mday tm.Unix.tm_mon 
    tm.Unix.tm_year tm.Unix.tm_hour tm.Unix.tm_min tm.Unix.tm_sec

let exec_cosmos model prop batch nbjob opt printcmd =
  let cmd = sprintf "%s %s %s --njob %i --batch %i -v 0 %s" cosmos_path model prop nbjob batch opt in
  if printcmd then print_endline cmd;
  let retcode =  Sys.command cmd in
  if retcode <> 0 then raise (CmdFail(retcode));
  let result = parse_result "Result.res" in
  result.modelName <- model;
  result.propName <- prop;
  result.batch <- batch;
  result.nbJob <- nbjob;
  result.date <- string_date ();
  result

let test_cosmosTeamCity testname model prop opt v = 
   printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" testname;
  flush stdout;
  try let result = exec_cosmos model prop 1000 1 opt true in
      if check_result result.haslResult v
      then 
	printf "##teamcity[testFinished name='%s' message='\n%s'" testname (print_readable result.haslResult v)
      else 
	printf "##teamcity[testFailed name='%s' message='\n%s'" testname (print_readable result.haslResult v)

  with CmdFail(ret) ->
    printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" testname testname ret
  | _ ->
    printf "##teamcity[testFailed name='%s' message='Test %s fail for unknown reason']\n" testname testname

let test_cosmosBash testname model prop opt v =
  print_color (sprintf "testStarted: %s \n" testname) 33;
  flush stdout;
  try let result = exec_cosmos model prop 1000 1 opt true in
       if check_result result.haslResult v
       then 
	 print_color (sprintf "testFinished: %s\n%s" testname (print_readable result.haslResult v)) 32
       else 
	 print_color (sprintf "testFailed: %s\n%s" testname (print_readable result.haslResult v)) 31

  with CmdFail(ret) ->
    print_color (sprintf "testFailed: %s Test %s fail: Cosmos return value:%i\n" testname testname ret) 31
  | _ ->
    print_color (sprintf "testFailed: %s Test %s fail for unknown reason\n" testname testname) 31
   

let test_cosmos t m p o v =
  if !teamCity then test_cosmosTeamCity t m p o v
  else  test_cosmosBash t m p o v

let test_cosmosBash testname model prop opt v =
  print_color (sprintf "testStarted: %s \n" testname) 33;
  flush stdout;
  try let result = exec_cosmos model prop 1000 1 opt true in
      printf "result: %e\nconfint: [%e,%e]\n" result.mean (fst result.confInt) (snd result.confInt);
      if v > (fst result.confInt) & (snd result.confInt) > v
      then print_color (sprintf "testFinished: %s expected result %e is in confidence interval |[%e,%e|]\n" testname v (fst result.confInt) (snd result.confInt)) 32
      else print_color (sprintf "testFailed: %s Test %s fail: expected result %e is outside confidence interval |[%e,%e|]\n" testname testname v (fst result.confInt) (snd result.confInt)) 31

  with CmdFail(ret) ->
    print_color (sprintf "testFailed: %s Test %s fail: Cosmos return value:%i\n" testname testname ret) 31

let test_cosmos t m p o v =
  if !teamCity then test_cosmosTeamCity t m p o v
  else  test_cosmosBash t m p o v

let test_cosmos_gspn n v o =
  test_cosmos n (n^".gspn") (n^".lha") o v

let test_cosmos_grml n v o =
  test_cosmos n (n^".grml") (n^"lha.grml") o v
 
let test_coverage name v o n =
  let _ = exec_cosmos (name^".gspn") (name^".lha") 10 1 (" --tmp-status 2 --max-run 10") false  in
  print_endline ("Cosmos "^o^" -v 0 --tmp-status 3 "^name^".gspn "^name^".lha");
  let succ = ref 0 in
  for i = 1 to n do
    let result = exec_cosmos (name^".gspn") (name^".lha") 1000 1 (o^" -v 0 --tmp-status 3") false in
    if check_result result.haslResult v then (
      incr succ;
      print_string "+";
    ) else print_string "-";
    flush stdout;
  done;
  printf "Coverage:\t%f\n" ((float !succ)/.(float n))



(*test_cosmos_gspn Sys.argv.(1) (float_of_string Sys.argv.(2)) Sys.argv.(3)*)
