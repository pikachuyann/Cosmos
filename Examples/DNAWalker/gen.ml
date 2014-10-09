#directory "../../utils"
#use "StochasticPetriNet.ml"

type anchorT = Init | Final | Norm

let dist (x1,y1) (x2,y2) =
  sqrt ((x1 -.x2)*.(x1 -.x2) +. (y1 -.y2)*.(y1 -.y2))

let generate_spn fpath li ks ksi failure=
  let (net:spt) = Net.create () in

  List.iter (fun (n,t,i,_) ->
    Data.add (("a"^(string_of_int n)),(if t=Init then 1 else 0)) net.Net.place;
    Data.add (("s"^(string_of_int n)),(if t=Init then 0 else 1) ) net.Net.place;
    if i=0 && t <> Init then begin
      Data.add (("b"^(string_of_int n)),1) net.Net.place;
      Data.add ("tb"^(string_of_int n) ,(Imm failure)) net.Net.transition;
      Data.add ("tAb"^(string_of_int n) ,(Imm (1.0-.failure))) net.Net.transition;
      Net.add_arc net ("b"^(string_of_int n)) ("tb"^(string_of_int n)) 1;
      Net.add_arc net ("b"^(string_of_int n)) ("tAb"^(string_of_int n)) 1;
      Net.add_arc net ("s"^(string_of_int n)) ("tAb"^(string_of_int n)) 1;
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
	Net.add_arc net tl ("a"^(string_of_int n2)) 1
      ) li ) li;
    print_spt fpath net;;

let sq2 = (sqrt 2.0)/.2.0;;
let sq3 = (sqrt 3.0)/.2.0;;

generate_spn "track12Block1.grml" [ (1,Init,0,(0.0,0.0)); 
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

generate_spn "track12Block2.grml" [ (1,Init,0,(0.0,0.0)); 
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

let l1 =1 and r1=0 and l2=1 and r2 = 0 in
generate_spn "track28.grml" [ 
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




#use "../testTeamCity.ml";;
(*
let generate n n2 r mu rho = 
  Printf.printf "Generate n=%i n2=%i r=%i mu=%f" n n2 r mu;
  for i =1 to n do Printf.printf " rho%i=%f" i (rho i) done;
  print_newline ();
  generate_spn "tandem.grml" n n2 mu rho r false;
  generate_spn "tandemDTMC.grml" n n2 mu rho r true;
  generate_marcie "tandem.andl" n mu rho r n2;
  generate_csl "tandem.csl" n n2;
  generate_reduce_spn "tandemRE.grml" n mu rho r;
  generate_lha "tandem.lha" n n2;
  generate_lumping_fun "lumpingfun.cpp" n;
  generate_prism "tandem.sm" n mu rho r n2;;

let level = ref 0.99;;

let simule n n2 r mu rho batch =
  generate n n2 r mu rho;
  Printf.printf "Simulate n=%i n2=%i r=%i" n n2 r;
  print_newline ();
  (*execSavedCosmos ~prefix:false ("ReduceModel","tandemRE.grml","tandem.lha"," --prism --prism-path /Applications/prism-4.0.2-osx64/bin/prism");*)
  Sys.command "/usr/bin/time -v prism -v tandem.sm prismtandem.csl > prismout";
  Sys.command ("ocaml traduittable.ml prismout muFile "^(string_of_int n));
  execSavedCosmos ~prefix:false ("ImportantSampling","tandem.grml","tandem.lha",Printf.sprintf " -r --normalize-IS --width 0 --max-run %i --level %f" batch !level );;



(*
simule 1 50 5;;
simule 2 50 5;;
simule 3 50 5;;
simule 4 50 5;;
simule 5 50 5;;
simule 6 50 5;;
simule 7 50 5;;
simule 8 50 5;;
simule 9 50 5;;
simule 10 50 5;;
*)
(*
assert (Array.length Sys.argv>3);;
let n = int_of_string Sys.argv.(1);;
let n2 = int_of_string Sys.argv.(2);;
let r = int_of_string Sys.argv.(3);;
assert(n>=1);;
*)
(*
generate n n2 r 0.05 (fun _-> 0.45);;

simule n n2 r 0.01 (fun _-> 0.11);;
*)
*)
