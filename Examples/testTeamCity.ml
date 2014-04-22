#directory "../utils";;
#directory "../../utils";;
#use "mlcall.ml"

let addo = " --level 0.9999 --gppflags '-O0 -Wno-return-type'"

let teamCity = ref true

let _ = if (Array.length Sys.argv) >1 then teamCity := false


let test_cosmosTeamCity testname model prop opt v = 
  try
    printf "##teamcity[testStarted name='%s' captureStandardOutput='<true>']\n" testname;
    flush stdout;
    let result = exec_cosmos model prop opt true in
    print_endline (print_readable result.haslResult v);
    if check_result result.haslResult v
    then 
      printf "##teamcity[testFinished name='%s' message='inside confidence interval']\n" testname
    else (
      printf "##teamcity[testFailed name='%s' message='outside confidence interval']\n" testname;
      printf "##teamcity[testFinished name='%s']\n" testname
    )
  with CmdFail(ret) ->
    printf "##teamcity[testFailed name='%s' message='Test %s fail: Cosmos return value:%i']\n" testname testname ret;
    printf "##teamcity[testFinished name='%s']\n" testname
  | x ->
    printf "##teamcity[testFailed name='%s' message='Test %s fail due to exception:%s']\n" testname testname (Printexc.to_string x);
    printf "##teamcity[testFinished name='%s']\n" testname

let test_cosmosBash testname model prop opt v =
  print_color (sprintf "testStarted: %s \n" testname) 33;
  flush stdout;
  try let result = exec_cosmos model prop opt true in
       if check_result result.haslResult v
       then 
	 print_color (sprintf "testFinished: %s\n%s" testname (print_readable result.haslResult v)) 32
       else 
	 print_color (sprintf "testFailed: %s\n%s" testname (print_readable result.haslResult v)) 31

  with CmdFail(ret) ->
    print_color (sprintf "testFailed: %s Test %s fail: Cosmos return value:%i\n" testname testname ret) 31
    | x ->
      print_color (sprintf "testFailed: %s Test %s fail due to exception:%s\n" testname testname (Printexc.to_string x)) 31
 

let test_cosmos t m p o v =
  if !teamCity then test_cosmosTeamCity t m p (o^addo) v
  else  test_cosmosBash t m p (o^addo) v


let test_cosmos_gspn n v o =
  test_cosmos n (n^".gspn") (n^".lha") o v

let test_cosmos_grml n v o =
  test_cosmos n (n^".grml") (n^"lha.grml") o v
