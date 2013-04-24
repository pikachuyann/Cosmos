#use "../testTeamCity.ml";;

let joblist = [
  "S1_20", "Policy1.grml" , "rho1_20.grml" ;
  "S1_50", "Policy1.grml" , "rho1_50.grml" ;
  "S1_100", "Policy1.grml" , "rho1_100.grml" ;
  "S1_400", "Policy1.grml" , "rho1_400.grml" ;
  "S1_6400", "Policy1.grml" , "rho1_6400.grml" ;
  "S1_25600", "Policy1.grml" , "rho1_25600.grml" ;
  "S1_102400", "Policy1.grml" , "rho1_102400.grml";
  "S2_20", "Policy2.grml" , "rho1_20.grml" ;
  "S2_50", "Policy2.grml" , "rho1_50.grml" ;
  "S2_100", "Policy2.grml" , "rho1_100.grml" ;
  "S2_400", "Policy2.grml" , "rho1_400.grml" ;
  "S2_6400", "Policy2.grml" , "rho1_6400.grml" ;
  "S2_25600", "Policy2.grml" , "rho1_25600.grml" ;
  "S2_102400", "Policy2.grml" , "rho1_102400.grml"]


let execCosmos (name,model,prop) =
  let cmd = sprintf "%s -v 0 %s %s --width 0.001 --level 0.99" cosmos_path model prop in
  print_endline cmd;
  Sys.command cmd;
  Sys.command (sprintf "cp Result.res %s.res" name);

List.iter execCosmos joblist
