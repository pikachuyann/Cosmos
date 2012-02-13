#!/usr/bin/ocaml
#load "unix.cma";;
open Printf

let nparraljob = 12;;
let joblist = [
  100, 10, 0.50 , 200 , 1 ;
  100, 10, 0.50 , 103 , 1 ;
];;

let lauchsim (n,r,mu,h,m) =
  ignore (Sys.command (sprintf "./tandem.ml %i %i %f %i %i" n r mu h m));
  printf "Finish tandem.ml %i %i %f %i %i\n" n r mu h m;;



List.iter lauchsim joblist;;


