#!/usr/bin/ocaml
#load "unix.cma";;
open Printf

let epsilon = 1e-10;;
let p= 0.3;;

let nparraljob = 12;;
let joblist = [
  2 , 10 , 10.0 , 1 ;
  3 , 10 , 10.0 , 1 ;
  4 , 10 , 10.0 , 1 ;
  5 , 10 , 10.0 , 1 ;
  6 , 10 , 10.0 , 1 ;
];;

let lauchsim (n,l,h,m) =
  ignore (Sys.command (sprintf "ocaml ruine.ml %i %i %f %f %i %e" n l p h m epsilon));;



List.iter lauchsim joblist;;


