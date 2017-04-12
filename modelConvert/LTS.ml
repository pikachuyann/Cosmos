
type edge = {
    label : string;
    target : int;
    prob : float;
  }

type t = {
    states : string array;
    transitions : edge list array; 
    init : int;
  }

open Printf
           
let print_dot f g =
  let o = open_out f in
  output_string o "digraph G {\n";
  let n = Array.length g.states in
  for i =0 to n-1 do
    List.iter (fun e ->
        fprintf o "\t\"%s\" -> \"%s\" [ label = \"%s(%f)\" ];\n"
                g.states.(i) g.states.(e.target) e.label e.prob)
              g.transitions.(i);
  done;
  output_string o "}\n";
  close_out o
