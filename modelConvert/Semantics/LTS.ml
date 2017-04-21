
type miniedge = {
    target : int;
    prob : float;
  }

type edge = {
    label : string;
    distr : miniedge list;
  }
                  
type t = {
    states : string array;
    transitions : edge list array; 
    init : int;
  }

open Printf
           
let print_dot ?mdp:(print_miniedge=true) f g =
  let o = open_out f in
  output_string o "digraph G {\n";
  let n = Array.length g.states in
  for i =0 to n-1 do
    fprintf o "\t\"%s\";\n" g.states.(i)
  done;
    
  for i =0 to n-1 do
    List.iter (fun e ->
        let st = if print_miniedge then (
                   let miniedgelabel = (g.states.(i)^e.label) in
                   fprintf o "node [shape=point];\n";
                   fprintf o "\t\"%s\" -> \"%s\" [ label = \"%s\" ];\n"
                           g.states.(i) miniedgelabel e.label;
                   miniedgelabel)
                 else g.states.(i) in
        List.iter (fun me ->
            fprintf o "\t\"%s\" -> \"%s\" [ label = \"%f\" ];\n"
                    st g.states.(me.target) me.prob) e.distr
      )
              g.transitions.(i);
  done;
  output_string o "}\n";
  close_out o
