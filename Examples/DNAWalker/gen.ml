let automataGenPath = "automataGen"

let print_tr f name id rate =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"distribution\">
      <attribute name=\"type\">
        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
          %f
        </attribute></attribute>
      </attribute>
    </attribute>
  </node>\n" !id name rate;
  incr id;;

let print_pl f name id tok =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"place\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"marking\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </node>\n" !id name tok;
  incr id;;

let print_arc f id source target valuation inhib =
  let arctype = if inhib then "inhibitorarc" else "arc" in
  Printf.fprintf f "  <arc id=\"%i\" arcType=\"%s\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </arc>\n" !id arctype source target valuation; 
  incr id;;

let gen_const f li lr =
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
    <attribute name=\"intConsts\">\n";
  List.iter (fun (n,v) -> 
     Printf.fprintf f "      <attribute name=\"intConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %i
        </attribute></attribute>
      </attribute>\n" n v) li;
  
  Printf.fprintf f "    </attribute>
    <attribute name=\"realConsts\">\n";
  List.iter (fun (n,v) -> 
    Printf.fprintf f "      <attribute name=\"realConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %f
        </attribute></attribute>
      </attribute>\n" n v) lr;
    Printf.fprintf f
      "     </attribute>
    </attribute>
  </attribute>\n"

type anchorT = Init | Final | Norm

let dist (x1,y1) (x2,y2) =
  sqrt ((x1 -.x2)*.(x1 -.x2) +. (y1 -.y2)*.(y1 -.y2))

let generate_spn fpath li ks ksi =
  let f = open_out fpath in
  let nm = 1+List.length li  in
  let lr = [("ks",ks); ("ksi",ksi)] in
  gen_const f [] lr;

  List.iter (fun (n,t,_,_) ->print_pl f ("a"^(string_of_int n)) (ref n) 
    (if t=Init then 1 else 0)) li;
  List.iter (fun (n,t,i,_) ->print_pl f ("s"^(string_of_int n)) (ref (n+nm)) i) li;

  List.iter (fun (n1,t1,i1,p1) ->
    List.iter (fun (n2,t2,i2,p2) -> 
      let r = (match t1 with 
	  Init -> ksi
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
      if r3 <> 0.0 then print_tr f (Printf.sprintf "t%i_%i" n1 n2) (ref (2*nm+ n1*nm+n2)) r3) li) li;
      
    List.iter (fun (n1,t1,i1,p1) ->
      List.iter (fun (n2,t2,i2,p2) -> 
	let b = (match dist p1 p2 with
	  | x when x< 0.1 -> false
	  | x when x< 3.87 -> true
	  | _->false ) in
	if b then begin
	  print_arc f (ref (2*nm+ 2*nm*nm+ 3*(n1*nm+n2))) 
	    n1 (2*nm+ n1*nm+n2) 1 false;
	  print_arc f (ref (2*nm+ 2*nm*nm+ 3*(n1*nm+n2)+1)) 
	    (nm+n2) (2*nm+ n1*nm+n2) 1 false;
	  print_arc f (ref (2*nm+ 2*nm*nm+ 3*(n1*nm+n2)+2)) 
	    (2*nm+ n1*nm+n2)  (n2) 1 false;
	end ) li ) li;

  Printf.fprintf f "</model>";
  close_out f;;

let sq2 = (sqrt 2.0)/.2.0;;
let sq3 = (sqrt 3.0)/.2.0;;

generate_spn "test.grml" [ (1,Init,0,(0.0,0.0)); 
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
			 (12,Final,1,(4.0*.sq3,-.5.0));] 0.009 0.003;; 

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
