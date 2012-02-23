#!/usr/bin/ocaml
#load "unix.cma";;
open Printf

let nparraljob = 12;;
let joblist = [
  50, 5, 0.25 , 100 , 1 , 2;
  50, 5, 0.25 , 100 , 1 , 3;
  50, 5, 0.25 , 100 , 1 , 4;
  50, 5, 0.25 , 100 , 1 , 5;
  50, 5, 0.25 , 100 , 1 , 6;
];;

let lauchsim (n,r,mu,h,m,k) =
  ignore (Sys.command (sprintf "ocaml tandem.ml %i %i %f %i %i %i" n r mu h m k));
  printf "Finish tandem.ml %i %i %f %i %i %i\n" n r mu h m k;;



List.iter lauchsim joblist;;


