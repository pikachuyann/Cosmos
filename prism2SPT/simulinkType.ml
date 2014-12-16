open Type

let rec eval_name data fe= 
  let ifun = function
   | FloatName(x) -> begin try let v = List.assoc x data in Float (v) with Not_found -> FloatName(x) end
   | x -> x
  in iterFloat ifun fe

type triggerT = Imm | Delay of floatExpr | RAction of string

type simulink_trans_label = {
  trigger: triggerT;
  write:  string list;
  update: string list;
  nameT: string option
}

let empty_trans_label = {
  nameT = None;
  trigger = Imm;
  write = [];
  update = [];
}



let stateasso s l =
  try (match List.assoc s l with
    Some n -> n
  | None -> string_of_int s)
  with Not_found -> ""

let stateasso2 s2 l =
  match s2 with None -> "" | Some s ->
  try (match List.assoc s l with
    Some n -> n
  | None -> string_of_int s)
  with Not_found -> ""

let print_label_simulink f trans = match trans.trigger with
    Imm -> Printf.fprintf f "#,![%a],{%a}" (print_list ",") trans.write (print_list ",") trans.update
  | Delay(s) -> Printf.fprintf f "wait(%a),![%a],{%a}" printH_float_expr s (print_list ",") trans.write (print_list ",") trans.update
  | RAction(s) -> Printf.fprintf f "?%s,![%a],{%a}" s (print_list ",") trans.write (print_list ",") trans.update


let interface_of_modu tl =
  let read = List.fold_left (fun r (_,_,lab,_) -> match lab.trigger with
    RAction a -> StringSet.add a r | _ -> r) StringSet.empty tl
  and write = List.fold_left (fun w (_,_,lab,_) -> StringSet.union w (StringSet.of_list lab.write)
  ) StringSet.empty tl in
  (read,write)

let print_trans_simulink sl f (ssid,src,trans,dst) =
  Printf.fprintf f "\t%s --(%a)->%s\n" (stateasso2 src sl) print_label_simulink trans (stateasso dst sl);;

let print_module f (ssid,name,sl,tl,_) =
  let actionr,actionw = interface_of_modu tl in
  let readlist = StringSet.fold (fun x y -> x::y) actionr [] 
  and writelist = StringSet.fold (fun x y -> x::y) actionw [] in 
  Printf.fprintf f "module: %i -> %a\n" ssid print_option name;
  Printf.fprintf f "Interface:\n\tRead[ %a ]\n\tWrite[ %a ]\n" (print_list ",") readlist (print_list ",") writelist;
  Printf.fprintf f "state list: [";
  List.iter (function (x,(Some y))-> Printf.fprintf f" %i->%s, " x y | (x,(None))-> Printf.fprintf f " %i, " x) sl;
  Printf.fprintf f "]\n";
  Printf.fprintf f "\ttransition list: [\n";
  List.iter (print_trans_simulink sl !logout) tl;
  Printf.fprintf f "\t]\n"

type simulink_module = {
  ssid : int;
  name : string option;
  stateL : (int * string option) list;
  ivect: (int*(string option)) array;
  transL : (int* ((int*int) list) *simulink_trans_label* ((int*int) list)) list;
  scriptL : (string option * string )  list;
  interfaceR : StringSet.t;
  interfaceW : StringSet.t;
}

let print_state_sim sl (x,y) =
  Printf.sprintf "%i:%s" x (stateasso y sl)

let print_trans_simulink2 sl f (ssid,src,trans,dst) =
  Printf.fprintf f "\t[%s] --(%a)->%s\n" (string_of_list ", " (print_state_sim sl) src) print_label_simulink trans (string_of_list ", " (print_state_sim sl) src);;

let print_module2 f m =
  let actionr,actionw = interface_of_modu m.transL in
  let readlist = StringSet.fold (fun x y -> x::y) actionr [] 
  and writelist = StringSet.fold (fun x y -> x::y) actionw [] in 
  Printf.fprintf f "module: %i -> %a\n" m.ssid print_option m.name;
  Printf.fprintf f "Interface:\n\tRead[ %a ]\n\tWrite[ %a ]\n" (print_list ",") readlist (print_list ",") writelist;
  Printf.fprintf f "state list: [";
  List.iter (function (x,(Some y))-> Printf.fprintf f " %i->%s, " x y | (x,(None))-> Printf.fprintf f " %i, " x) m.stateL;
  Printf.fprintf f "]\n";
  Printf.fprintf f "\ttransition list: [\n";
  List.iter (print_trans_simulink2 m.stateL f) m.transL;
  Printf.fprintf f "\t]\n"



let print_modu2 f m = 
  (*(ssid,name,sl,ivect,tl,scrl) =*)
  Printf.fprintf f "\tsubgraph cluster%i {\n" m.ssid;
  Array.iteri (fun n (x,n2) ->
    Printf.fprintf f "\tpl%i_%i [shape=circle,label=\"%a\"];\n" m.ssid n print_option n2) m.ivect;
    List.iter (fun (ssidt,src,lab,dst) ->Printf.fprintf f "\t%i [shape=rect,fixedsize=true,height=0.2,style=filled,fillcolor=black,xlabel=\"%a\",label=\"\"];\n" ssidt print_label_simulink lab;
      List.iter (fun (i,s) ->
	Printf.fprintf f "\tpl%i_%i -> %i [label=\"%s\"];\n" m.ssid i ssidt (stateasso s m.stateL)) src;
      List.iter (fun (i,s) ->
	Printf.fprintf f "\t%i -> pl%i_%i [label=\"%s\"];\n" ssidt m.ssid i (stateasso s m.stateL)) dst
    ) m.transL;
  output_string f "}\n"

let print_simulink_dot2 fpath ml =
  let f = open_out fpath in
  output_string f "digraph G {\n";
(*  output_string f "\tsubgraph place {\n";
  output_string f "\t\tgraph [shape=circle];\n";
  output_string f "\t\tnode [shape=circle,fixedsize=true];\n";*)
   (print_modu2 f) ml;
  output_string f "}\n"; 
  close_out f;;
