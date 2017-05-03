
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

let computeBound _ = ()
           
let print_dot ?mdp:(print_miniedge=true) f g =
  let open Printf in
  let o = open_out f in
  output_string o "digraph G {\n";
  let n = Array.length g.states in
  for i =0 to n-1 do
    fprintf o "\t\"%s\";\n" g.states.(i)
  done;
    
  for i =0 to n-1 do
    List.iter (fun e ->
        let st,lab = if print_miniedge && List.length e.distr > 1 then (
                   let miniedgelabel = (g.states.(i)^"L"^e.label) in
                   fprintf o "node [shape=point];\n";
                   fprintf o "\t\"%s\" -> \"%s\" [ label = \"%s\" ];\n"
                           g.states.(i) miniedgelabel e.label;
                   miniedgelabel,"")
                 else g.states.(i),e.label in
        List.iter (fun me ->
            fprintf o "\t\"%s\" -> \"%s\" [ label = \"%s\" ];\n"
                    st g.states.(me.target) (if lab <> "" then lab else string_of_float me.prob) ) e.distr
      )
              g.transitions.(i);
  done;
  output_string o "}\n";
  close_out o
