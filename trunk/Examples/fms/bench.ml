#use "../testTeamCity.ml";;

let joblist1 = [
  "S1_1_20", "Policy1.grml" , "rho1_20.grml" ;
  "S1_1_50", "Policy1.grml" , "rho1_50.grml" ;
  "S1_1_100", "Policy1.grml" , "rho1_100.grml" ;
  "S1_1_400", "Policy1.grml" , "rho1_400.grml" ;
  "S1_1_6400", "Policy1.grml" , "rho1_6400.grml" ;
  "S1_1_25600", "Policy1.grml" , "rho1_25600.grml" ;
  "S1_1_102400", "Policy1.grml" , "rho1_102400.grml";
  "S2_1_20", "Policy2.grml" , "rho1_20.grml" ;
  "S2_1_50", "Policy2.grml" , "rho1_50.grml" ;
  "S2_1_100", "Policy2.grml" , "rho1_100.grml" ;
  "S2_1_400", "Policy2.grml" , "rho1_400.grml" ;
  "S2_1_6400", "Policy2.grml" , "rho1_6400.grml" ;
  "S2_1_25600", "Policy2.grml" , "rho1_25600.grml" ;
  "S2_1_102400", "Policy2.grml" , "rho1_102400.grml"]

let joblist2 = [
  "S1_2_10", "Policy1.grml" , "rho2_10.grml" ;
  "S1_2_50", "Policy1.grml" , "rho2_50.grml" ;
  "S1_2_100", "Policy1.grml" , "rho2_100.grml" ;
  "S1_2_400", "Policy1.grml" , "rho2_400.grml" ;
  "S1_2_6400", "Policy1.grml" , "rho2_6400.grml" ;
  "S1_2_25600", "Policy1.grml" , "rho2_25600.grml" ;
  "S1_2_102400", "Policy1.grml" , "rho2_102400.grml";
  "S2_2_10", "Policy2.grml" , "rho2_10.grml" ;
  "S2_2_50", "Policy2.grml" , "rho2_50.grml" ;
  "S2_2_100", "Policy2.grml" , "rho2_100.grml" ;
  "S2_2_400", "Policy2.grml" , "rho2_400.grml" ;
  "S2_2_6400", "Policy2.grml" , "rho2_6400.grml" ;
  "S2_2_25600", "Policy2.grml" , "rho2_25600.grml" ;
  "S2_2_102400", "Policy2.grml" , "rho2_102400.grml"]

let joblist3 = [
  "S1_3_10", "Policy1Geo.grml" , "rho2_10.grml" ;
  "S1_3_50", "Policy1Geo.grml" , "rho2_50.grml" ;
  "S1_3_100", "Policy1Geo.grml" , "rho2_100.grml" ;
  "S1_3_400", "Policy1Geo.grml" , "rho2_400.grml" ;
  "S1_3_6400", "Policy1Geo.grml" , "rho2_6400.grml" ;
  "S1_3_25600", "Policy1Geo.grml" , "rho2_25600.grml" ;
  "S1_3_102400", "Policy1Geo.grml" , "rho2_102400.grml";
  "S2_3_10", "Policy2Geo.grml" , "rho2_10.grml" ;
  "S2_3_50", "Policy2Geo.grml" , "rho2_50.grml" ;
  "S2_3_100", "Policy2Geo.grml" , "rho2_100.grml" ;
  "S2_3_400", "Policy2Geo.grml" , "rho2_400.grml" ;
  "S2_3_6400", "Policy2Geo.grml" , "rho2_6400.grml" ;
  "S2_3_25600", "Policy2Geo.grml" , "rho2_25600.grml" ;
  "S2_3_102400", "Policy2Geo.grml" , "rho2_102400.grml"]


let joblist4 = [
  "S1Sym_4_10", "Policy1sym.grml" , "rho2_10.grml" ;
  "S1Sym_4_50", "Policy1sym.grml" , "rho2_50.grml" ;
  "S1Sym_4_100", "Policy1sym.grml" , "rho2_100.grml" ;
  "S1Sym_4_400", "Policy1sym.grml" , "rho2_400.grml" ;
  "S1Sym_4_6400", "Policy1sym.grml" , "rho2_6400.grml" ;
  "S1Sym_4_25600", "Policy1sym.grml" , "rho2_25600.grml" ;
  "S1Sym_4_102400", "Policy1sym.grml" , "rho2_102400.grml";
  "S2Sym_4_10", "Policy2sym.grml" , "rho2_10.grml" ;
  "S2Sym_4_50", "Policy2sym.grml" , "rho2_50.grml" ;
  "S2Sym_4_100", "Policy2sym.grml" , "rho2_100.grml" ;
  "S2Sym_4_400", "Policy2sym.grml" , "rho2_400.grml" ;
  "S2Sym_4_6400", "Policy2sym.grml" , "rho2_6400.grml" ;
  "S2Sym_4_25600", "Policy2sym.grml" , "rho2_25600.grml" ;
  "S2Sym_4_102400", "Policy2sym.grml" , "rho2_102400.grml";
  "S2ASym_4_10", "Policy2Asym.grml" , "rho2_10.grml" ;
  "S2ASym_4_50", "Policy2Asym.grml" , "rho2_50.grml" ;
  "S2ASym_4_100", "Policy2Asym.grml" , "rho2_100.grml" ;
  "S2ASym_4_400", "Policy2Asym.grml" , "rho2_400.grml" ;
  "S2ASym_4_6400", "Policy2Asym.grml" , "rho2_6400.grml" ;
  "S2ASym_4_25600", "Policy2Asym.grml" , "rho2_25600.grml" ;
  "S2ASym_4_102400", "Policy2Asym.grml" , "rho2_102400.grml"]

let joblist45 = [
  "S1ASym3_3_4_10", "Policy1Asym3_3.grml" , "rho2_10.grml" ;
  "S1ASym3_3_4_50", "Policy1Asym3_3.grml" , "rho2_50.grml" ;
  "S1ASym3_3_4_100", "Policy1Asym3_3.grml" , "rho2_100.grml" ;
  "S1ASym3_3_4_400", "Policy1Asym3_3.grml" , "rho2_400.grml" ;
  "S1ASym3_3_4_6400", "Policy1Asym3_3.grml" , "rho2_6400.grml" ;
  "S1ASym3_3_4_25600", "Policy1Asym3_3.grml" , "rho2_25600.grml" ;
  "S1ASym3_3_4_102400", "Policy1Asym3_3.grml" , "rho2_102400.grml";

  "S1ASym1_3_4_10", "Policy1Asym1_3.grml" , "rho2_10.grml" ;
  "S1ASym1_3_4_50", "Policy1Asym1_3.grml" , "rho2_50.grml" ;
  "S1ASym1_3_4_100", "Policy1Asym1_3.grml" , "rho2_100.grml" ;
  "S1ASym1_3_4_400", "Policy1Asym1_3.grml" , "rho2_400.grml" ;
  "S1ASym1_3_4_6400", "Policy1Asym1_3.grml" , "rho2_6400.grml" ;
  "S1ASym1_3_4_25600", "Policy1Asym1_3.grml" , "rho2_25600.grml" ;
  "S1ASym1_3_4_102400", "Policy1Asym1_3.grml" , "rho2_102400.grml";
  
  "S1ASym2_3_4_10", "Policy1Asym2_3.grml" , "rho2_10.grml" ;
  "S1ASym2_3_4_50", "Policy1Asym2_3.grml" , "rho2_50.grml" ;
  "S1ASym2_3_4_100", "Policy1Asym2_3.grml" , "rho2_100.grml" ;
  "S1ASym2_3_4_400", "Policy1Asym2_3.grml" , "rho2_400.grml" ;
  "S1ASym2_3_4_6400", "Policy1Asym2_3.grml" , "rho2_6400.grml" ;
  "S1ASym2_3_4_25600", "Policy1Asym2_3.grml" , "rho2_25600.grml" ;
  "S1ASym2_3_4_102400", "Policy1Asym2_3.grml" , "rho2_102400.grml";

  "S1ASym1_4_4_10", "Policy1Asym1_4.grml" , "rho2_10.grml" ;
  "S1ASym1_4_4_50", "Policy1Asym1_4.grml" , "rho2_50.grml" ;
  "S1ASym1_4_4_100", "Policy1Asym1_4.grml" , "rho2_100.grml" ;
  "S1ASym1_4_4_400", "Policy1Asym1_4.grml" , "rho2_400.grml" ;
  "S1ASym1_4_4_6400", "Policy1Asym1_4.grml" , "rho2_6400.grml" ;
  "S1ASym1_4_4_25600", "Policy1Asym1_4.grml" , "rho2_25600.grml" ;
  "S1ASym1_4_4_102400", "Policy1Asym1_4.grml" , "rho2_102400.grml"]


let execCosmos (name,model,prop) =
  let cmd = sprintf "%s -v 0 %s %s --width 0.001 --level 0.99" cosmos_path model prop in
  print_endline cmd;
  Sys.command cmd;
  Sys.command (sprintf "cp Result.res %s.res" name);
  ();;

List.iter execCosmos joblist45

