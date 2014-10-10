#directory "../../utils"
#use "StochasticPetriNet.ml"
#use "mlcall.ml";;

type anchorT = Init | Final | Norm

let foldi f c t =
  let acc = ref c in
  for i = 0 to Array.length t-1 do
    acc:=f !acc i t.(i);
  done;
  !acc;;

let dist (x1,y1) (x2,y2) =
  sqrt ((x1 -.x2)*.(x1 -.x2) +. (y1 -.y2)*.(y1 -.y2))


let generate_lha fpath safe obj final =
  let f = open_out fpath in
  Printf.fprintf f "
NbVariables = 4;
NbLocations = 6;
VariablesList = { vc0, DISC vd0 , DISC vd1, DISC vd2};
LocationsList = {li,lfc,lf,lnf1,ldl,lnf2};
FinishCorrect=AVG(Last(vd0));
Finish=AVG(Last(vd1));
DeadLock=AVG(Last(vd2));
InitialLocations = { li };
FinalLocations = {lfc,lf,ldl,lnf2};
Locations = {
(li,(%s),(vc0:1.));
(lfc,(%s));
(lf,(%s ));
(lnf1,TRUE,(vc0:1.));
(ldl,TRUE);
(lnf2,TRUE);
};
Edges = {
((li,li),ALL,#,#);
((li,lfc),ALL,#,{vd0=1,vd1=1});
((li,lf),ALL,#,{vd1=1});
((li,lnf1),#,vc0=12000,#);
((lnf1,lnf2),ALL,#,#);
((lnf1,ldl),#,vc0=1000000000,{vd2=1});
};" safe obj final ;
  close_out f;;



let generate_spn fpath li ks ksi failure=
  print_endline ("Generate "^fpath);
  let (net:spt) = Net.create () in

  (*let cluster = Array.make (List.length li) [] in*)

  List.iter (fun (n,t,i,_) ->
    Data.add (("a"^(string_of_int n)),(if t=Init then 1 else 0)) net.Net.place;
    Data.add (("s"^(string_of_int n)),(if t=Init then 0 else 1) ) net.Net.place;
    (*cluster.(n-1) <- ("a"^(string_of_int n))
      :: ("s"^(string_of_int n)) :: cluster.(n-1);*) 
    if i=0 && t <> Init then begin
      Data.add (("b"^(string_of_int n)),1) net.Net.place;
      Data.add ("tb"^(string_of_int n) ,(Imm failure)) net.Net.transition;
      Data.add ("tAb"^(string_of_int n) ,(Imm (1.0-.failure))) net.Net.transition;
      Net.add_arc net ("b"^(string_of_int n)) ("tb"^(string_of_int n)) 1;
      Net.add_arc net ("b"^(string_of_int n)) ("tAb"^(string_of_int n)) 1;
      Net.add_arc net ("s"^(string_of_int n)) ("tAb"^(string_of_int n)) 1;
      (*cluster.(n-1) <- ("b"^(string_of_int n)) 
      :: ("tb"^(string_of_int n))
      :: ("tAb"^(string_of_int n))
      :: cluster.(n-1);*) 
    end
  ) li;

  List.iter (fun (n1,t1,i1,p1) ->
    List.iter (fun (n2,t2,i2,p2) -> 
      let r = (match t1 with 
	  Init -> ksi
	| Final -> 0.0
	| _ -> ks) in
      let r2 = (match dist p1 p2 with
	| x when x< 0.1 -> 0.0
	| x when x< 1.5 -> r
	| x when x< 2.5 -> r/.50.0
	| x when x< 3.87 -> r/.100.0
	| _->0.0 ) in
      let r3 = (match t2 with 
	  Final -> r2 /. 10.
	| _ -> r2) in
      if r3 <> 0.0 then
	let tl = Printf.sprintf "t%i_%i" n1 n2 in
	Data.add (tl,(Exp r3)) net.Net.transition;
	Net.add_arc net ("a"^(string_of_int n1)) tl 1;
	Net.add_arc net ("s"^(string_of_int n2)) tl 1;
	Net.add_arc net tl ("a"^(string_of_int n2)) 1;
	(*cluster.(n1-1) <- tl :: cluster.(n1-1);*) 
      ) li ) li;

  List.iter (fun (n1,t1,i1,p1) ->
    if t1=Final then 
      let tl = Printf.sprintf "tloop%i" n1 in 
      Data.add (tl,(Exp 1.0)) net.Net.transition;
      Net.add_arc net ("a"^(string_of_int n1)) tl 1;
      Net.add_arc net tl ("a"^(string_of_int n1)) 1;
  ) li;  

  (*let lc = foldi (fun acc i l -> (i+1,l)::acc) [] cluster in*)

    print_spt (fpath^".grml") net;
    print_spt_marcie (fpath^".andl") net;
    print_spt_dot (fpath^".dot") net [];
    ignore (Sys.command (Printf.sprintf "dot -Tpdf %s.dot -o %s.pdf" fpath fpath));
    execSavedCosmos ~prefix:false (fpath,fpath^".grml",fpath^".lha","");;

let sq2 = (sqrt 2.0)/.2.0;;
let sq3 = (sqrt 3.0)/.2.0;;

(*
generate_lha "control.lha" "a8=0" "a8>0" "FALSE";
generate_spn "control" [
  (1,Init,0,(0.0,0.0)); 
  (2,Norm,1,(0.0,-1.0)); 
  (3,Norm,1,(0.0,-2.0));
  (4,Norm,1,(0.0,-3.0));
  (5,Norm,1,(0.0,-.4.0));
  (6,Norm,1,(0.0,-.5.0)); 
  (7,Norm,1,(0.0,-.6.0));
  (8,Final,1,(0.0,-.7.0))]
0.009 0.003 0.3;; 

generate_lha "controlMissing1.lha" "a8=0" "a8>0" "FALSE";
generate_spn "controlMissing1" [
  (1,Init,0,(0.0,0.0)); 
  (2,Norm,1,(0.0,-1.0)); 
  (3,Norm,1,(0.0,-2.0));
  (5,Norm,1,(0.0,-.4.0));
  (6,Norm,1,(0.0,-.5.0)); 
  (7,Norm,1,(0.0,-.6.0));
  (8,Final,1,(0.0,-.7.0))]
0.009 0.003 0.3;; 

generate_lha "controlMissing2.lha" "a8=0" "a8>0" "FALSE";
generate_spn "controlMissing2" [
  (1,Init,0,(0.0,0.0)); 
  (2,Norm,1,(0.0,-1.0)); 
  (3,Norm,1,(0.0,-2.0));
  (6,Norm,1,(0.0,-.5.0)); 
  (7,Norm,1,(0.0,-.6.0));
  (8,Final,1,(0.0,-.7.0))]
0.009 0.003 0.3;; 

generate_lha "controlMissing7.lha" "a8=0" "a8>0" "FALSE";
generate_spn "controlMissing7" [
  (1,Init,0,(0.0,0.0)); 
  (2,Norm,1,(0.0,-1.0)); 
  (3,Norm,1,(0.0,-2.0));
  (4,Norm,1,(0.0,-3.0));
  (5,Norm,1,(0.0,-.4.0));
  (6,Norm,1,(0.0,-.5.0)); 
  (8,Final,1,(0.0,-.7.0))]
0.009 0.003 0.3;; 

generate_lha "track12Block1.lha" "a8=0 & a12=0" "a12>0" "a8>0";
generate_spn "track12Block1" [ (1,Init,0,(0.0,0.0)); 
			 (2,Norm,1,(0.0,-1.0)); 
			 (3,Norm,1,(0.0,-2.0));
			 (4,Norm,1,(0.0,-3.0));
			 (5,Norm,0,(-.1.0*.sq3,-.3.5));
			 (6,Norm,1,(-.2.0*.sq3,-.4.0)); 
			 (7,Norm,1,(-.3.0*.sq3,-.4.5));
			 (8,Final,1,(-.4.0*.sq3,-.5.0));
			 (9,Norm,1,(1.0*.sq3,-.3.5));
			 (10,Norm,1,(2.0*.sq3,-.4.0));
			 (11,Norm,1,(3.0*.sq3,-.4.5));
			 (12,Final,1,(4.0*.sq3,-.5.0));] 0.009 0.003 0.3;; 

generate_lha "track12Block2.lha" "a8=0 & a12=0" "a12>0" "a8>0";
generate_spn "track12Block2" [ (1,Init,0,(0.0,0.0)); 
			 (2,Norm,1,(0.0,-1.0)); 
			 (3,Norm,1,(0.0,-2.0));
			 (4,Norm,1,(0.0,-3.0));
			 (5,Norm,0,(-.1.0*.sq3,-.3.5));
			 (6,Norm,0,(-.2.0*.sq3,-.4.0)); 
			 (7,Norm,1,(-.3.0*.sq3,-.4.5));
			 (8,Final,1,(-.4.0*.sq3,-.5.0));
			 (9,Norm,1,(1.0*.sq3,-.3.5));
			 (10,Norm,1,(2.0*.sq3,-.4.0));
			 (11,Norm,1,(3.0*.sq3,-.4.5));
			 (12,Final,1,(4.0*.sq3,-.5.0));] 0.009 0.003 0.3;; 


generate_lha "track12BlockBoth.lha" "a8=0 & a12=0" "a12>0" "a8>0";
generate_spn "track12BlockBoth" [ (1,Init,0,(0.0,0.0)); 
			 (2,Norm,1,(0.0,-1.0)); 
			 (3,Norm,1,(0.0,-2.0));
			 (4,Norm,1,(0.0,-3.0));
			 (5,Norm,0,(-.1.0*.sq3,-.3.5));
			 (6,Norm,1,(-.2.0*.sq3,-.4.0)); 
			 (7,Norm,1,(-.3.0*.sq3,-.4.5));
			 (8,Final,1,(-.4.0*.sq3,-.5.0));
			 (9,Norm,0,(1.0*.sq3,-.3.5));
			 (10,Norm,1,(2.0*.sq3,-.4.0));
			 (11,Norm,1,(3.0*.sq3,-.4.5));
			 (12,Final,1,(4.0*.sq3,-.5.0));] 0.009 0.003 0.3;; 


let gen28 f l1 r1 l2 r2 =
generate_spn f [ 
  (1,Init,0,(0.0,0.0)); 
  (2,Norm,1,(0.0,-1.0)); 
  (3,Norm,1,(0.0,-2.0));
  (4,Norm,1,(0.0,-3.0));
  (5,Norm,l1,(-.1.0*.sq3,-.3.5));
  (6,Norm,l1,(-.2.0*.sq3,-.4.0)); 
  (7,Norm,1,(-.3.0*.sq3,-.4.5));
  (8,Norm,1,(-.4.0*.sq3,-.5.0));
  (9,Norm,r1,(1.0*.sq3,-.3.5));
  (10,Norm,r1,(2.0*.sq3,-.4.0));
  (11,Norm,1,(3.0*.sq3,-.4.5));
  (12,Norm,1,(4.0*.sq3,-.5.0));
  
  (13,Norm,1,(-.4.0*.sq3,-6.0));
  (14,Norm,1,(-.4.0*.sq3,-7.0));
  (15,Norm,l2,(-.5.0*.sq3,-.7.5));
  (16,Norm,l2,(-.6.0*.sq3,-.8.0)); 
  (17,Final,1,(-.7.0*.sq3,-.8.5));
  (18,Norm,r2,(-.3.0*.sq3,-.7.5));
  (19,Norm,r2,(-.2.0*.sq3,-.8.0));
  (20,Final,1,(-.1.0*.sq3,-.8.5));

  (21,Norm,1,(4.0*.sq3,-6.0));
  (22,Norm,1,(4.0*.sq3,-7.0));
  (23,Norm,l2,(3.0*.sq3,-.7.5));
  (24,Norm,l2,(2.0*.sq3,-.8.0)); 
  (25,Final,1,(1.0*.sq3,-.8.5));
  (26,Norm,r2,(5.0*.sq3,-.7.5));
  (27,Norm,r2,(6.0*.sq3,-.8.0));
  (28,Final,1,(7.0*.sq3,-.8.5));

] 0.009 0.003 0.3;; 


generate_lha "track28LL.lha" "a17=0 & a20=0 & a25=0 & a28=0" 
 "a17>0" "a20>0 | a25>0 | a28>0";;
gen28 "track28LL" 1 0 1 0;;

generate_lha "track28LR.lha" "a17=0 & a20=0 & a25=0 & a28=0" 
  "a20>0" "a17>0 | a25 >0 & a28>0";;
gen28 "track28LR" 1 0 0 1;;

generate_lha "track28RL.lha" "a17=0 & a20=0 & a25=0 & a28=0" 
  "a25>0" "a20>0 | a17 >0 & a28>0";;
gen28 "track28RL" 0 1 1 0;;

generate_lha "track28RR.lha" "a17=0 & a20=0 & a25=0 & a28=0" 
  "a28>0" "a20>0 | a25 >0 & a17>0";;
gen28 "track28RR" 0 1 0 1;;
*)

let gen_xor f x y =
  if x <> y then 
    generate_lha (f^".lha") "a7=0 & a17=0" "a17>0" "a7>0"
  else  
    generate_lha (f^".lha") "a7=0 & a17=0" "a7>0" "a17>0";

  let  xi = if x then 1 else 0
  and nxi = if x then 0 else 1
  and  yi = if y then 1 else 0
  and nyi = if y then 0 else 1 in
  generate_spn f
    [ (1 ,Init,0  ,(  0.0,  0.0)); 
      (2 ,Norm,nxi ,(-.1.0,  0.5)); 
      (3 ,Norm,nxi ,(-.2.0,  1.0));
      (4 ,Norm,nyi ,(-.2.0,  2.0));
      (5 ,Norm,nyi ,(-.1.0,  2.5));
      (6 ,Norm,1   ,(  0.0,  3.0)); 
      (7 ,Final,1  ,(  1.0,  2.5));
      (8 ,Norm,1   ,(  2.0,  2.0));
      (9 ,Norm,1   ,(  3.0,  1.5));
      (10,Norm,yi  ,(  3.0,  0.5));
      (11,Norm,yi  ,(  3.0,-.0.5));
      (12,Norm,xi  ,(  2.0,-.1.0));
      (13,Norm,xi  ,(  1.0,-.0.5));
      (14,Norm,nyi ,(  2.0,-.2.0));
      (15,Norm,nyi ,(  1.0,-.2.5));
      (16,Norm,1   ,(  0.0,-.3.0));
      (17,Final,1  ,(-.1.0,-.2.5));
      (18,Norm,1   ,(-.2.0,-.2.0));
      (19,Norm,1   ,(-.3.0,-.1.5));
      (20,Norm,yi  ,(-.3.0,-.0.5));
      (21,Norm,yi  ,(-.3.0,  0.5));
] 0.009 0.003 0.3;;

gen_xor "ringLL" true true;;
