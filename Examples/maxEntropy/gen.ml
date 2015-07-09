#directory "../../utils"

#use "mlcall.ml";;


let timeConflict name nbstate nbcomp polysize =
  let model = open_out (name^".prism") in
  Printf.fprintf model 
"pta

const int n = %i;
const int wt = 3;

module c1
	state1: [1..n] init 1;
	x1: clock;

	invariant
		  ( state1<n => x1<1) 
		& ( state1=n => x1 < wt)
	endinvariant

	[] state1<n & x1<1 -> 1.0 : (state1'=state1+1);
	[] state1<n & x1<1 -> 1.0 : (state1'=1);
	[] state1=n & x1<wt -> 1.0 : (state1'=1)&(x1'=0);
endmodule\n" nbstate;
  for i = 2 to nbcomp do
    Printf.fprintf model "module c%i = c1 [state1=state%i,x1=x%i ] endmodule\n" i i i;
  done;
  close_out model;
  let prop = open_out (name^".lha") in
  Printf.fprintf prop
"VariablesList = {time,DISC countT} ;
LocationsList = {l0, l1,l2};

timeReach=AVG(Last(time));
stepReach=AVG(Last(countT));

InitialLocations={l0};
FinalLocations={l2};
Locations={
(l0, TRUE, (time:1));
(l1, s_%i_ =0 , (time:1 ));
(l2, s_%i_ >0);
};
Edges={
((l0,l0),ALL,time<= 0 ,#);
((l0,l1),#,time=0 ,{time=0});
((l1,l1),ALL,#,{countT = countT+1 });
((l1,l2),ALL,#,#);
};" nbstate nbstate;
  close_out prop;
  ignore (Sys.command (Printf.sprintf "sage script_tocosmos.sage %s.prism %s.grml %i" name name polysize ));
  execSavedCosmos ~prefix:false (name,name^".grml",name^".lha"," --njob 2 --max-run 20000 --batch 1000");
  ignore (Sys.command (Printf.sprintf "sage script_tocosmos.sage %s.prism %s.grml 1 -isotropic" name name));
  execSavedCosmos ~prefix:false (name^"_iso",name^".grml",name^".lha"," --njob 2 --max-run 20000 --batch 1000");;
  
(*
 First Table *)
timeConflict "first3_1_3" 3 1 3;;
timeConflict "first4_1_4" 4 1 4;;
timeConflict "first5_1_5" 5 1 5;;
timeConflict "first6_1_6" 6 1 6;;
timeConflict "first7_1_7" 7 1 7;;
timeConflict "first8_1_8" 8 1 8;;
timeConflict "first9_1_9" 9 1 9;;
timeConflict "first10_1_10" 10 1 10;;
timeConflict "first11_1_11" 11 1 11;;
timeConflict "first12_1_12" 12 1 12;;
timeConflict "first13_1_13" 13 1 13;;

(*
(* Second Table *)
timeConflict "second3_2_3" 3 2 3;;
*)
