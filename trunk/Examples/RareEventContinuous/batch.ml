#!/usr/bin/ocaml
#load "unix.cma";;
open Printf

let epsilon = 1e-10;;

let nparraljob = 12;;
let joblist = [
  50, 5, 0.25 , 100 , 1 , 7;
  50, 5, 0.25 , 100 , 1 , 8;
  50, 5, 0.25 , 100 , 2 , 2;
  50, 5, 0.25 , 100 , 2 , 3;
  50, 5, 0.25 , 100 , 2 , 4;
  50, 5, 0.25 , 100 , 2 , 5;
  50, 5, 0.25 , 100 , 2 , 6;
  50, 5, 0.25 , 100 , 2 , 7;
  50, 5, 0.25 , 100 , 2 , 8;
  50, 5, 0.25 , 100 , 2 , 9;
];;

let lauchsim (n,r,mu,h,m,k) =
  ignore (Sys.command (sprintf "ocaml tandem.ml %i %i %f %i %i %i %e" n r mu h m k epsilon));
  printf "Finish tandem.ml %i %i %f %i %i %i %e\n" n r mu h m k epsilon;;



List.iter lauchsim joblist;;


