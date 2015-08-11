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



(* EXP2 *)

gen_faillure_repair "exp2" 4 11 2 6

