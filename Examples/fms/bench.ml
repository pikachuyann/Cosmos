#use "../testTeamCity.ml";;

let joblist5 = [
  "S1_5_10", "Policy1Fail.grml" , "rho2_10.grml" ;
  "S1_5_50", "Policy1Fail.grml" , "rho2_50.grml" ;
  "S1_5_100", "Policy1Fail.grml" , "rho2_100.grml" ;
  "S1_5_400", "Policy1Fail.grml" , "rho2_400.grml" ;
  "S1_5_1600", "Policy1Fail.grml" , "rho2_1600.grml" ;   
  "S1_5_6400", "Policy1Fail.grml" , "rho2_6400.grml" ;
  "S1_5_25600", "Policy1Fail.grml" , "rho2_25600.grml" ;
  "S1_5_102400", "Policy1Fail.grml" , "rho2_102400.grml";
  "S2_5_10", "Policy2Fail.grml" , "rho2_10.grml" ;
  "S2_5_50", "Policy2Fail.grml" , "rho2_50.grml" ;
  "S2_5_100", "Policy2Fail.grml" , "rho2_100.grml" ;
  "S2_5_400", "Policy2Fail.grml" , "rho2_400.grml" ;
  "S2_5_400", "Policy2Fail.grml" , "rho2_1600.grml" ;   
  "S2_5_6400", "Policy2Fail.grml" , "rho2_6400.grml" ;
  "S2_5_25600", "Policy2Fail.grml" , "rho2_25600.grml" ;
  "S2_5_102400", "Policy2Fail.grml" , "rho2_102400.grml"]

let joblist6 = [
  "S1_6_100", "Policy1.grml" , "rho3_100.grml" ;
  "S1_6_200", "Policy1.grml" , "rho3_200.grml" ;
  "S1_6_400", "Policy1.grml" , "rho3_400.grml" ;
  "S1_6_800", "Policy1.grml" , "rho3_800.grml" ;
  "S1_6_1600", "Policy1.grml" , "rho3_1600.grml" ;
  "S1_6_6400", "Policy1.grml" , "rho3_6400.grml" ;
  "S1_6_25600", "Policy1.grml" , "rho3_25600.grml" ;
  "S1_6_102400", "Policy1.grml" , "rho3_102400.grml";
  "S2_6_100", "Policy2.grml" , "rho3_100.grml" ;
  "S2_6_200", "Policy2.grml" , "rho3_200.grml" ;
  "S2_6_400", "Policy2.grml" , "rho3_400.grml" ;
  "S2_6_800", "Policy2.grml" , "rho3_800.grml" ;
  "S2_6_1600", "Policy2.grml" , "rho3_1600.grml" ;
  "S2_6_6400", "Policy2.grml" , "rho3_6400.grml" ;
  "S2_6_25600", "Policy2.grml" , "rho3_25600.grml" ;
  "S2_6_102400", "Policy2.grml" , "rho3_102400.grml";
  "S1_6_100", "Policy1Fail.grml" , "rho3_100.grml" ;
  "S1_6_200", "Policy1Fail.grml" , "rho3_200.grml" ;
  "S1_6_400", "Policy1Fail.grml" , "rho3_400.grml" ;
  "S1_6_800", "Policy1Fail.grml" , "rho3_800.grml" ;
  "S1_6_1600", "Policy1Fail.grml" , "rho3_1600.grml" ;
  "S1_6_6400", "Policy1Fail.grml" , "rho3_6400.grml" ;
  "S1_6_25600", "Policy1Fail.grml" , "rho3_25600.grml" ;
  "S1_6_102400", "Policy1Fail.grml" , "rho3_102400.grml";
  "S2_6_100", "Policy2Fail.grml" , "rho3_100.grml" ;
  "S2_6_200", "Policy2Fail.grml" , "rho3_200.grml" ;
  "S2_6_400", "Policy2Fail.grml" , "rho3_400.grml" ;
  "S2_6_800", "Policy2Fail.grml" , "rho3_800.grml" ;
  "S2_6_1600", "Policy2Fail.grml" , "rho3_1600.grml" ;
  "S2_6_6400", "Policy2Fail.grml" , "rho3_6400.grml" ;
  "S2_6_25600", "Policy2Fail.grml" , "rho3_25600.grml" ;
  "S2_6_102400", "Policy2Fail.grml" , "rho3_102400.grml"];;

let lt = [ 10 ; 25 ; (*50;*) 100 ; (*200;*) 400; (*800;*) 1600; (*6400;*) 12800; (*25600;*) 102400 ]
let lp = [ "Policy1.grml"; "Policy2.grml" ]
let prop = "rho1.grml"
let commonopt = "--width 0.01 --batch 100 -v 2 --njob 8 "

let iterexp name p prop opt =
  List.iter (fun i ->
    execSavedCosmos ~prefix:false (
      (Printf.sprintf "%s_%s_%i" name p i),p,prop,
      (Printf.sprintf "%s --const 'T=%i'" opt i ))
  ) lt


let _ = List.iter (fun p ->
  iterexp "Table1" p "rho1.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0'") )
  lp

let _ = List.iter (fun p ->
  iterexp "Table2" p "rho2.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0'") )
  lp

(* phi2(sym) *)
let _ = List.iter (fun p ->
  iterexp "Table3phi2Sym" p "rho2.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0,mu1=0.476190476190476164,mu2=0.476190476190476164'") ) lp

(* phi2(Asym) S2 *)
let _ =
  iterexp "Table3phi2ASym" "Policy2.grml" "rho2.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym3_5" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=3,l2=5,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym3_4" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=3,l2=4,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym3_3" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym2_3" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=2,l2=3,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym1_3" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=1,l2=3,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym1_4" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=1,l2=4,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

(* phi2(Asym) S1 *)
let _ =
  iterexp "Table3phi2ASym1_5" "Policy1.grml" "rho2.grml" (commonopt^" --const 'l1=1,l2=5,failerate=0,mu1=0.714285714285714302,mu2=0.357142857142857151'")

let _ = List.iter (fun p ->
  iterexp "Table4(fault)" p "rho2.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0.016'") )
  lp

let _ = List.iter (fun p ->
  iterexp "Table5(fault)" p "rho3.grml" (commonopt^" --const 'l1=3,l2=3,failerate=0.016'") )
  lp
