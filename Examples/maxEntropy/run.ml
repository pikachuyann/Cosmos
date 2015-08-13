#directory "../../utils"

#use "mlcall.ml";;


(*script for experiment*)

let gen_diff_to_reach name n b timeC wt npoly = 
  let f = open_out (name^"_C.prism") in
    Printf.fprintf f "pta
    const int n = %i;
    const int B = %i;
    const int timeC = %i;
    const int wt = %i;

    module c1
        state1: [1..n] init 1;
        x: clock;

        invariant
                  ( state1<n => x<B) 
                & ( state1=n => x < wt)
        endinvariant

        [a] state1<n-1 & x<B -> 1.0 : (state1'=state1+1);
        [b] state1=n-1 & x<timeC -> 1.0 : (state1'=n);
        [c] state1=n-1 & x>timeC & x<B  -> 1.0 : (state1'=1)&(x'=0);    
        [d] state1<n & x<B -> 1.0 : (state1'=1);
        [e] state1=n & x<wt -> 1.0 : (state1'=1)&(x'=0);
endmodule" n b timeC wt;
    close_out f;
    let cmd = Printf.sprintf "sage script_tocosmos.sage %s_C.prism %s_C.grml %i" name name npoly in
    print_endline cmd;
    assert (0=Sys.command cmd);

    let cmd2 = Printf.sprintf "python script_lha_alzen.py %i 1000 %i %i > %s_A.lha" n wt b name in
    print_endline cmd2;
    assert (0=Sys.command cmd2)

let gen_faillure_repair name n b minRep npoly =
  let f = open_out (name^"_C.prism") in
  Printf.fprintf f  "pta
    const int n = %i;
    const int B = %i;
    const int minRep = %i;

    module c1
        state1: [1..n+1] init 1;
        x: clock;
        y: clock;

        invariant
              ( x<B)
        endinvariant

        [a] state1<n & x<B & y>minRep-> 1.0 : (state1'=state1+1)&(y'=0);
        [b] state1<n+1 & state1>1 & x<B  -> 1.0 : (state1'=state1-1);
        [b] state1=1 & x<B  -> 1.0 : (state1'=1);
        [c] state1=n & x<B -> 1.0 : (state1'=n+1)&(x'=0)&(y'=0);
        [c] state1=n+1 & x<B -> 1.0 : (state1'=n+1)&(x'=0)&(y'=0);
        [b] state1=n+1 & x<B  -> 1.0 : (state1'=1);
endmodule" n b minRep;
  close_out f;
  let cmd = Printf.sprintf "sage script_tocosmos.sage %s_C.prism %s_C.grml %i" name name npoly in
  print_endline cmd;
  assert (0=Sys.command cmd)


let gen_faillure_repairB name c1 c2 dline =
  let f = open_out (name^"_B.lha") in
  Printf.fprintf f  "NOTDETERMINISTIC
const int c1 =%i;
const int c2 = %i;
const int Dline =%i;

VariablesList = {DISC countT, t1,t2};
LocationsList = {li,l1,l2,lf, li2,l12,l22,lf2};

reach=PROB;
reachCond=PROB(lf);

InitialLocations={li,li2};
FinalLocations={lf2};
Locations={
(li, TRUE, (t1:1,t2:1));
(l1, TRUE, (t1:1,t2:1));
(l2, TRUE, (t1:1,t2:1));
(lf, TRUE, (t1:1,t2:1));

(li2, TRUE, (t1:1,t2:1));
(l12, TRUE, (t1:1,t2:1));
(l22, TRUE, (t1:1,t2:1));
(lf2, TRUE, (t1:1,t2:1));
};

Edges={
((li,li),ALL\\{t_a,t_b,t_c},countT <=Dline ,#);
((l1,l1),ALL\\{t_a,t_b,t_c},countT <=Dline & t1<=c2 ,#);
((l2,l2),ALL\\{t_a,t_b,t_c},countT <=Dline & t1<=c2 ,#);
((lf,lf),ALL\\{t_a,t_b,t_c},countT <=Dline ,#);

((li,li),{t_a,t_b,t_c}, # ,{countT = countT+1});
((li,l1),{t_a}, # ,{countT = countT+1,t1=0});
((l1,l1),{t_a,t_b,t_c}, t1<=c2 ,{countT = countT+1});
((l1,l2),{t_c}, t1>=c1& t1<=c2 ,{countT = countT+1,t2=0});
((l2,l2),{t_a,t_b,t_c}, t1<=c2 ,{countT = countT+1});
((l2,lf),{t_a}, t2>=c1&t1<=c2 ,{countT = countT+1});
((lf,lf),{t_a,t_b,t_c}, # ,{countT = countT+1});


((li2,li2),ALL\\{t_a,t_b,t_c},countT <=Dline ,#);
((l12,l12),ALL\\{t_a,t_b,t_c},countT <=Dline & t1<=c2 ,#);
((l22,l22),ALL\\{t_a,t_b,t_c},countT <=Dline & t1<=c2 ,#);
((lf2,lf2),ALL\\{t_a,t_b,t_c},countT <=Dline ,#);

((li2,li2),{t_a,t_b,t_c}, # ,{countT = countT+1});
((li2,l12),{t_a}, # ,{countT = countT+1,t1=0});
((l12,l12),{t_a,t_b,t_c}, t1<=c2 ,{countT = countT+1});
((l12,l22),{t_c}, t1>=c1& t1<=c2 ,{countT = countT+1});
((l22,l22),{t_a,t_b,t_c}, t1<=c2 ,{countT = countT+1});
((l22,lf2),{t_a}, t1>=2*c1&t1<=c2 ,{countT = countT+1});
((lf2,lf2),{t_a,t_b,t_c}, # ,{countT = countT+1});
};
" c1 c2 dline;
  close_out f

let run1 n b timeC wt npoly =
  let name = "exp1_"^string_of_int n in
    gen_diff_to_reach name n b timeC wt npoly;
    execSavedCosmos ~prefix:false (name,name^"_C.grml",name^"_A.lha"," --njob 2 --max-run 10000 --batch 1000 --width 0");
    execSavedCosmos ~prefix:false ("Iso_"^name,"Iso_"^name^"_C.grml",name^"_A.lha"," --njob 2 --max-run 10000 --batch 1000 --width 0")

(* EXP1 *)

let exp1 () =
    run1 6 20 10 1000 6;
    run1 7 20 10 1000 7;
    run1 8 20 10 1000 8;
    run1 9 20 10 1000 9;
    run1 10 20 10 1000 10;;

(*exp1 ()*)

let run2 n b minRep npoly c1 c2 dline =
  let name = "exp2_"^string_of_int n in
  gen_faillure_repair name n b minRep npoly;
  gen_faillure_repairB name c1 c2 dline;
  execSavedCosmos ~prefix:false (name,name^"_C.grml",name^"_B.lha"," --njob 2 --max-run 50000 --batch 1000 --width 0");
  execSavedCosmos ~prefix:false ("Iso_"^name,"Iso_"^name^"_C.grml",name^"_B.lha"," --njob 2 --max-run 50000 --batch 1000 --width 0");;


(* EXP2 *)

run2 2 8 1 6 9 20 100;;
run2 3 8 1 6 9 20 100;;
run2 4 8 1 6 9 20 100;;
run2 5 8 1 6 9 20 100;;

