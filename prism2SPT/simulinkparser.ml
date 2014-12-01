open Xml
open PetriNet
open StochasticPetriNet
open Type
open Lexing

let rec findprop f = function
  | [] -> None
  | t::q -> (match f t with None -> findprop f q | x-> x)

let getSSID al = int_of_string (List.assoc "SSID" al) 
let getName cl = findprop (function 
  | Element ("P",["Name","labelString"],[PCData(l)])  -> Some l 
  | _ -> None) cl

let getdst cl = findprop (function 
  | Element ("dst",_,cl2) -> findprop (function 
    | Element ("P",["Name","SSID"],[PCData(l)])  -> Some (int_of_string l) 
    | _ -> None) cl2
  | _ -> None) cl

let getsrc cl = findprop (function 
  | Element ("src",_,cl2) -> findprop (function 
    | Element ("P",["Name","SSID"],[PCData(l)])  -> Some (int_of_string l) 
    | _ -> None) cl2
  | _ -> None) cl

let rec exp_mod (sl,tl) = function
    | Element (name,alist,clist) ->
       begin match name with
       | "Children" -> List.fold_left exp_mod (sl,tl) clist
       | "state" -> (((getSSID alist),(getName clist))::sl,tl)
       | "transition" -> (match getdst clist with Some dst ->
	 (sl,((getSSID alist),(getName clist),(getsrc clist),dst)::tl) | _ -> failwith "Ill formed transition")

       | x -> Printf.printf "Dont know wat to do with %s, ignore\n" x; (sl,tl)
       end
    | PCData (s) -> print_endline s; (sl,tl)

let print_module (ssid,name,sl,tl) =
  Printf.printf "module: %i -> " ssid;
  (match name with
    Some s -> print_endline s
  | None -> print_newline ());
  Printf.printf "\tstate list: [";
  List.iter (function (x,(Some y))-> Printf.printf " %i->%s, " x y | (x,(None))-> Printf.printf " %i, " x) sl;
  Printf.printf "]\n";
  Printf.printf "\ttransition list: [\n";
  List.iter (print_trans_simulink sl stdout) tl;
  Printf.printf "\t]\n"


let print_position outx lexbuf =
  let pos = lexbuf.Lexing.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)

let eval_trans (ssid,name,src,dst) = match name with
    None -> (ssid,src,empty_trans_label,dst)
  | Some s -> let lexbuf = Lexing.from_string s in
	      try	
		let label = ParserSimulEdge.main LexerSimulEdge.token lexbuf in
		(ssid,src,label,dst)
    with 
      Parsing.Parse_error ->
	Printf.fprintf stdout "%a: Parsing error: unexpected token:'%s' in %s\n"
	  print_position lexbuf (Lexing.lexeme lexbuf) s;
	(ssid,src,empty_trans_label,dst)

let module_of_simul al cl = 
  let ssid = getSSID al in
  let name = getName cl in
  let childs = List.find (function Element ("Children",_,_)->true | _-> false) cl in
  let sl,tl = exp_mod ([],[]) childs in
  let modu = ssid,name,sl,(List.map eval_trans tl) in 
  (*print_module modu;*)
  modu



let print_modu f (ssid,name,sl,tl) =
  Printf.fprintf f "\tsubgraph cluster%i {\n" ssid;
  match name with None -> Printf.fprintf f "\t%i[shape=rectangle]\n" ssid
  | Some n2 -> Printf.fprintf f "\t%s[shape=rectangle]\n" n2;
  List.iter (fun (x,y) ->
    Printf.fprintf f "\t%i [shape=circle,label=\"%a\"];\n" x print_option y) sl; 
  List.iter (fun (ssid,src,label,dst) ->
    match src with None -> () | Some src2 ->
    Printf.fprintf f "\t%i -> %i[shape=circle,label=\"%a\"];\n" src2 dst print_label_simulink label) tl;
  output_string f "}\n"
    

let print_simulink_dot fpath ml =
  let f = open_out fpath in
  output_string f "digraph G {\n";
  
(*  output_string f "\tsubgraph place {\n";
  output_string f "\t\tgraph [shape=circle];\n";
  output_string f "\t\tnode [shape=circle,fixedsize=true];\n";*)
  
  List.iter (print_modu f) ml;

  output_string f "}\n"; 
  close_out f;;

let rec prism_of_stateflow level ml = function
    | Element (name,alist,clist) ->
       begin match name with
       | "xml" | "ModelInformation" | "Model" | "Stateflow" | "machine" | "chart" | "Children" ->
					 print_endline name;
					 List.fold_left (prism_of_stateflow level) ml clist
       | "P" -> ml
       | "state" -> if level=1 then (module_of_simul alist clist)::ml
	 else List.fold_left (prism_of_stateflow (level+1)) ml clist
       | "transition" -> ml
       | "target" -> ml
       | "subviewS" -> ml
       | "data" -> ml
       | "event" -> ml
       | x -> Printf.printf "Dont know wat to do with %s, ignore\n" x; ml
       end
    | PCData (s) -> print_endline s; ml

let rec prism_of_tree ml = function
  | Element (name,alist,clist) as t->
    begin match name with
    | "xml" | "ModelInformation" | "Model" | "P" ->
      List.fold_left prism_of_tree ml clist
       | "Stateflow" -> prism_of_stateflow 0 ml t
       | _ -> ml
       end
    | PCData (s) -> ml

let ssid_count = ref (-1)

let fresh_ssid () =
  let f= ! ssid_count in
  decr ssid_count; f

let interface_of_modu tl =
  List.fold_left (fun s (_,_,lab,_) -> match lab.trigger with
    RAction a -> StringSet.add a s | _ -> s) StringSet.empty tl

let flatten_module (ssid,name,sl,tl) =
  let inaction = interface_of_modu tl in
  let tl2 = List.fold_left (fun nt2 (ss,_) ->
    StringSet.fold (fun sa tl3 ->
      if List.exists (fun (_,src,lab,_) ->
	match (src,lab.trigger) with ((Some x),(RAction y)) when x=ss && y = sa -> true | _-> false
      ) tl 
      then ((fresh_ssid ()),Some ss,{empty_trans_label with trigger = RAction(sa) },ss)::tl3 
      else tl3) inaction nt2) tl sl in 
  (ssid,name,sl,tl2)
  
let init_state (ssid,name,sl,tl) =
  try
    let (_,_,_,init) =  
      List.find (function (_,None,_,_) -> true | _ -> false) tl in
    init
  with Not_found -> ( match sl with
    [init,_] -> init
  | _ -> failwith "No init state")

let incr_trans l (ssid,src,lab,dst) =
  match src with
  | None -> l
  | Some src2 ->
    (ssid,[(0,src2)],lab,[(0,dst)])::l
  
let incr_state (ssid,name,sl,tl) =
  let init = init_state (ssid,name,sl,tl) in
  let ivect = Array.make 1 (init,name) in
  Printf.printf "\t%s\n" (stateasso init sl);
  (ssid,name,sl,ivect,List.fold_left incr_trans [] tl)


let print_modu2 f (ssid,name,sl,ivect,tl) =
  Printf.fprintf f "\tsubgraph cluster%i {\n" ssid;
  Array.iteri (fun n (x,n2) ->
    Printf.fprintf f "\tpl%i_%i [shape=circle,label=\"%a\"];\n" ssid n print_option n2) ivect;
    List.iter (fun (ssidt,src,lab,dst) ->Printf.fprintf f "\t%i [shape=rect,fixedsize=true,height=0.2,style=filled,fillcolor=black,xlabel=\"%a\",label=\"\"];\n" ssidt print_label_simulink lab;
      List.iter (fun (i,s) ->
	Printf.fprintf f "\tpl%i_%i -> %i [label=\"%s\"];\n" ssid i ssidt (stateasso s sl)) src;
      List.iter (fun (i,s) ->
	Printf.fprintf f "\t%i -> pl%i_%i [label=\"%s\"];\n" ssidt ssid i (stateasso s sl)) dst
    ) tl;
  output_string f "}\n"
    

let print_simulink_dot2 fpath ml =
  let f = open_out fpath in
  output_string f "digraph G {\n";
(*  output_string f "\tsubgraph place {\n";
  output_string f "\t\tgraph [shape=circle];\n";
  output_string f "\t\tnode [shape=circle,fixedsize=true];\n";*)
  List.iter (print_modu2 f) ml;
  output_string f "}\n"; 
  close_out f;;

let dec_trans n (ssid,srcl,lab,dstl) =
  (ssid, (List.map (fun (x,y) -> (x+n,y)) srcl), lab ,(List.map (fun (x,y) -> (x+n,y)) dstl))


let comb_trans l (ssidt,srcl,lab,dstl) (ssidt2,srcl2,lab2,dstl2) =
  match lab2.trigger with
    RAction st when List.exists (fun x -> x=st) lab.write ->
      let lab3= { trigger=lab.trigger;
		  write = lab.write @ lab2.write;
		update = lab.update @ lab2.update} in
      (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | _-> begin match lab.trigger with
    RAction st when List.exists (fun x -> x=st) lab2.write ->
      let lab3= { trigger=lab2.trigger;
		  write = lab.write @ lab2.write;
		update = lab.update @ lab2.update} in
      (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
    |_-> l
  end

let combine_modu (ssid,name,sl,ivect,tl) (ssid2,name2,sl2,ivect2,tl2) =
  let n = Array.length ivect in
  let ivect3 = Array.append ivect ivect2 in
  let tl3 = List.map (dec_trans n) tl2 in
  let inaction1 = interface_of_modu tl 
  and inaction2 = interface_of_modu tl2 in
  let tlunchanged = List.filter (fun (_,_,lab,_) -> 
    not (List.exists (fun x -> StringSet.mem x inaction2) lab.write)) tl
  and tlunchanged2 = List.filter (fun (_,_,lab,_) -> 
    not (List.exists (fun x -> StringSet.mem x inaction1) lab.write)) tl3 in
  let tl4 = List.fold_left (fun l t1 ->
    List.fold_left (fun l2 t2 -> comb_trans l2 t1 t2) l tl3) (tlunchanged@tlunchanged2) tl in 
  (ssid,name,sl,ivect3,tl4)
    
let prune_unread (ssid,name,sl,ivect,tl) =
  let tl2 = List.filter (fun (_,_,lab,_) -> match lab.trigger with
    RAction _-> false
  | _ -> true) tl in
  (ssid,name,sl,ivect,tl2) 
