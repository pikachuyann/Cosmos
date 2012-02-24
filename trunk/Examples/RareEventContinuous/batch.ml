#!/usr/bin/ocaml
#load "unix.cma";;
open Printf

let epsilon = "0.00000000001";;

let nparraljob = 12;;
let joblist = [
  50, 5, 0.25 , 100 , 1 , 2;
  50, 5, 0.25 , 100 , 1 , 3;
  50, 5, 0.25 , 100 , 1 , 4;
  50, 5, 0.25 , 100 , 1 , 5;
  50, 5, 0.25 , 100 , 1 , 6;
];;

let lauchsim (n,r,mu,h,m,k) =
  ignore (Sys.command (sprintf "ocaml tandem.ml %i %i %f %i %i %i %s" n r mu h m k epsilon));
  printf "Finish tandem.ml %i %i %f %i %i %i %s\n" n r mu h m k epsilon;;



List.iter lauchsim joblist;;


