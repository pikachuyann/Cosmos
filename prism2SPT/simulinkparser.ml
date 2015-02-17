open Xml
open PetriNet
open StochasticPetriNet
open Type
open SimulinkType
open Lexing

let ligthSim = true
let modelStoch = true
let useerlang = true
let aggressive_syn = false


(* Distribution to attribute to Deterministic Delays*)
let detfun s =
  if modelStoch then 
    let n = 200 in
    StochasticPetriNet.Erl (Int n,Div (Float (float n),s))
  else StochasticPetriNet.Det s

(* Handling of SSID*)
let ssid_count = ref (-1)
let fresh_ssid () =
  let f= !ssid_count in
  incr ssid_count; f

(* Function to fetch various attribute in XML tree*)
let getSSID al = 
  let i = int_of_string (List.assoc "SSID" al)  in
  ssid_count := max !ssid_count (i+1); 
  i

let rec findprop f = function
  | [] -> None
  | t::q -> (match f t with None -> findprop f q | x-> x)

let findpropName s cl = 
  findprop (function 
  | Element ("P",["Name",x],[PCData(l)]) when x=s -> Some l 
  | _ -> None) cl

let getName = findpropName "labelString"
let getScope = findpropName "scope"
let getDescription = findpropName "description"
let getType = findpropName "type"

let getPriority cl = findpropName "executionOrder" cl
  |>> (fun x -> Some (int_of_string x))

let getdst cl = findprop (function 
  | Element ("dst",_,cl2) -> 
    findpropName "SSID" cl2 |>>> int_of_string
  | _ -> None) cl

let getsrc cl = findprop (function 
  | Element ("src",_,cl2) -> 
    findpropName "SSID" cl2 |>>> int_of_string
  | _ -> None) cl

let getScript cl = findprop (function 
  | Element ("eml",_,cl2) -> findpropName "script" cl2
  | _ -> None) cl
  
let rec exp_data = function
   | Element ("data",alist,clist) when getScope clist = Some "LOCAL_DATA" ->
     let name = List.assoc "name" alist
     and datatype = findpropName "dataType" clist |>>| "double" in
     Some ((getSSID alist),(datatype^" "^name))
    | _-> None

(* position for error reporting in the parser of edge*)
let print_position outx lexbuf =
  let pos = lexbuf.Lexing.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)


let regexp = "f[^̂†]*\\)\nend"
let parse_regexp = Str.regexp 
  "function[ ]*\\([A-Za-z0-9_]+\\)[ ]*=[ ]*\\([A-Za-z0-9_]+\\)\\([(][A-Za-z0-9_, ]*[)]\\)[ ]*\n\\([^§]*\\)\nend";;


let reg_comm = Str.regexp "%"
let reg_type1 = Str.regexp "[(]"
let reg_type2 = Str.regexp "[,]"
  
(* transform matlab function into C function *)
let parse_fun comm scr =
  if not (Str.string_match parse_regexp scr 0) then failwith ("Fail to parse:"^scr);
  let var = Str.matched_group 1 scr
  and name = Str.matched_group 2 scr
  and arg = Str.matched_group 3 scr
  and body = Str.matched_group 4 scr in
  let arg2 = if arg= "()" then "()" else arg
    |> Str.global_replace reg_type1 "(double "
    |> Str.global_replace reg_type2 ", double " in
  let body2 = Str.global_replace reg_comm "//" body in
  match comm with 
    Some s when String.sub s 0 6 = "Cosmos" -> 
      let s2 = String.sub s 7 (String.length s -7) in
      (name,s2)
  | Some s when String.sub s 0 9 = "Prototype" -> 
    let s2 = String.sub s 9 (String.length s -9) in
    (name,s2)
  | Some s when String.sub s 0 9 = "Cfunction" -> 
    let s2 = String.sub s 9 (String.length s -9) in
    (name,s2)
  | _ ->  (name,Printf.sprintf "double %s%s{\n//%s\n\tdouble %s;\n%s\n\treturn %s;\n}" name arg2 (string_of_option "" comm) var body2 var)
  

(* Parse a simulink automaton recursively *)				   
let rec exp_mod (sl,tl,scriptl) = function
    | Element (name,alist,clist) ->
       begin match name with
       | "Children" -> List.fold_left exp_mod (sl,tl,scriptl) clist
       | "state" -> begin match getScript clist with
	   None -> (((getSSID alist),(getName clist))::sl,tl,scriptl)
	   | Some scr -> 
	     let comm = getDescription clist in
	     let fn,fb = parse_fun comm scr in (sl,tl,((Some fn),fb)::scriptl)
       end 
       | "transition" -> (match getdst clist with Some dst ->
	 (sl,((getSSID alist),(getName clist),(getsrc clist),dst)::tl,scriptl) | _ -> failwith "Ill formed transition")
       | "data" -> begin try 
			   let name = List.assoc "name" alist
			   and datatype = findpropName "dataType" clist |>>| "double" in
			   Printf.fprintf stdout "new var data:%s with type: %s\n" name datatype;
			   (sl,tl,(None,datatype^" "^name)::scriptl); 
	 with
	 | Not_found -> (sl,tl,scriptl)
       end

       | x -> Printf.fprintf stderr "Dont know what to do with %s, ignore\n" x; (sl,tl,scriptl)
       end
    | PCData (s) -> output_string stderr s; (sl,tl,scriptl)

(*Parse edge of automaton use the grammar define in ParserSimulEdge.mly  *)
let eval_trans sl priority (ssid,name,src,dst) = match name with
    None -> (ssid,src,empty_trans_label,dst)
  | Some s -> let lexbuf = Lexing.from_string s in
	      try     
		let label = ParserSimulEdge.main LexerSimulEdge.token lexbuf in
		let label2 = {label with write = List.sort_uniq compare label.write;
			     nameT = src |>> (fun x -> List.assoc x sl);
			     priority = priority |>>> float |>>| 1.0 } in
		(ssid,src,label2,dst)
    with 
      Parsing.Parse_error ->
	Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s' in %s\n"
	  print_position lexbuf (Lexing.lexeme lexbuf) s;
	(ssid,src,empty_trans_label,dst)

(* Parse a simulink automaton*) 
let module_of_simul al cl = 
  let ssid = getSSID al in
  let name = getName cl in
  let priority = getPriority cl in
  let childs = List.find (function Element ("Children",_,_)->true | _-> false) cl in
  let sl,tl,scriptl = exp_mod ([],[],[]) childs in
  let modu = ssid,name,sl,(List.map (eval_trans sl priority) tl),scriptl,priority in 
  (*print_module modu;*)
  modu

(* Generate human readable name*)
let post_name sl s t =
  match List.assoc s sl with
    None -> Printf.sprintf "%i_Pre" t
  | Some(sn) -> Printf.sprintf "%i_Pre_%s" t sn

let exist_delay s l =
  List.exists (fun (ssid,src,label,dst) -> match (src,label.trigger) with 
  Some (src2), Delay(_) -> src2 = s
  |_ -> false) l

(*
  Add intermediate state to some transition to implement simulink semantic
*)
let expand_trans l =
  List.map (fun (ssidmod,name,sl,tl,scrl,p) ->
    let (nsl,ntl) = List.fold_left (fun (sl2,tl2) (ssid,src,label,dst) -> 
      match (label.trigger,label.write,src) with 
      | (Delay(_),(_::_),_) -> (* wait and synch loop *)
	(* This is necessary to make delay transition independant, therefor they do not synchronize
	   with anything thus cannot be disabled by synchronization.
	   use only when write list is not empty*)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	(ssid,src,{empty_trans_label with trigger=label.trigger; priority =label.priority; nameT=(src |>> (fun x ->List.assoc x sl))  },news)::
	  (newt,Some(news),{label with trigger=Imm},dst)::tl2)
      | (RAction(sn),_,Some src2) when src2=dst && exist_delay src2 tl->  (* self loop with read *)
	(* This case is used to reset delay transition waiting on this state,
	   without this delay transition are note disabled by a selfloop read action*)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	(ssid,src,{empty_trans_label with trigger=label.trigger; priority =label.priority; nameT=Some sn },news)::
	  (newt,Some(news),{label with trigger=Imm},dst)::tl2)
      | (_,_,None) when label.update <> [] -> (* Initial transition with update *)
	(* Initial transition are not real transition thus a new state and a new transition
	   is introduce to implement updates*)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	 (ssid,None,{empty_trans_label with priority =label.priority},news)::
	   (newt,Some(news),{label  with nameT=Some "init"},dst)::tl2)
      | _ -> (sl2,(ssid,src,label,dst)::tl2)) (sl,[]) tl in
    (ssidmod,name,nsl,ntl,scrl,p)) l
	      
(* Print a simulink automaton for dot *)
let print_modu f (ssid,name,sl,tl,scrl,p) =
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

(* Walk the tree and build a list of module*)
let rec modulist_of_stateflow ml = function
    | Element (name,alist,clist) as t ->
       begin match name with
       | "xml" | "ModelInformation" | "Model" | "Stateflow" | "machine" | "chart" | "Children" ->
					 List.fold_left modulist_of_stateflow ml clist
       | "P" -> ml
       | "state" -> begin match  getType clist with
	 None -> ml
	 | Some t when t= "OR_STATE" -> List.fold_left modulist_of_stateflow ml clist
	 | Some t when t= "AND_STATE" -> (module_of_simul alist clist)::ml
	 | Some t when t= "FUNC_STATE" -> begin
	   match getScript clist with
	     None -> ml
	   | Some scr -> 
	     let comm = getDescription clist in
	     let fn,fb = parse_fun comm scr in
	     let modu = (getSSID alist),(Some fn),[],[],[((Some fn),fb)],None in
	     modu::ml
	 end
	 | Some t -> Printf.fprintf stderr "Dont know wat to do with %s, ignore\n" t; ml
       end
       | "transition" -> ml
       | "target" -> ml
       | "subviewS" -> ml
       | "instance" -> ml
       | "data" -> begin match exp_data t with None -> ml | Some (ssid,var) ->
	 (ssid,None,[],[],[None,var],None)::ml
	 end
       | "event" -> begin
	 let name = findpropName "name" clist |>>| "__NO_NAME"
	 and ssid = getSSID alist 
	 and scope = findpropName "scope" clist in
	 Printf.fprintf !logout "New event: %s : %i : %a\n" name ssid print_option scope;
	 (*match scope with
	   Some "OUTPUT_EVENT" -> 
	     (ssid,Some ("Output_sig_"^name),[ssid,Some "q0"],
	      [ssid,Some ssid,{empty_trans_label with trigger = RAction name},ssid],[],None)::ml
	 |_ ->*) ml
       end
       | x -> Printf.fprintf stderr "Dont know wat to do with %s, ignore\n" x; ml
       end
    | PCData (s) -> output_string stderr s; ml

let rec modulist_of_tree ml = function
  | Element (name,alist,clist) as t->
    begin match name with
    | "xml" | "ModelInformation" | "Model" | "P" ->
      List.fold_left modulist_of_tree ml clist
       | "Stateflow" -> modulist_of_stateflow ml t
       | _ -> ml
       end
    | PCData (s) -> ml

(* Add self loop such that if a module may read a signal it can read it from any state*)
let flatten_module (ssid,name,sl,tl,scrl,p) =
  let inaction,_ = interface_of_modu tl in
  let tl2 = sl
    |> List.fold_left (fun nt2 (ss,_) -> (*Itere over state*)
      nt2 |> StringSet.fold (fun sa tl3 ->  (* Iter over signal name*)
	if not (tl |> List.exists (fun (_,src,lab,_) -> (* iter over transition*)
	  match (src,lab.trigger) with 
	    ((Some x),(RAction y)) when x=ss && y = sa -> true 
	  | ((Some x),(Imm)) when x=ss -> true
	  | _-> false
	)) 
	then (* There is no transition from state src that read signal ss or that are immediate. Add selfloop*)
	  ((fresh_ssid ()),Some ss,{empty_trans_label with trigger = RAction(sa) },ss)::tl3 
	else (* Nothing to do *) 
	  tl3
      ) inaction) tl in 
  (ssid,name,sl,tl2,scrl,p)
    
(* Look for the initial transition to determinate initial state *)
let init_state (ssid,name,sl,tl,scrl) =
  try
    let (_,_,_,init) =  
      List.find (function (_,None,_,_) -> true | _ -> false) tl in
    init
  with Not_found -> ( match sl with
    [init,_] -> init
  | _ -> begin
    match name with Some s -> failwith ("No init state in "^s)
    |None -> failwith ("No init state in "^string_of_int ssid)
  end)

(* 
   - Replace type for state from an id to an array of one id
in order to compose state in transitions. 
   - Remove initial transition
*)
let incr_trans l (ssid,src,lab,dst) =
  match src with
  | None -> l
  | Some src2 ->
    (ssid,[(0,src2)],lab,[(0,dst)])::l
  

let uni_ssid = ref 0

(* 
   Replace type for state from an id to an array of one id
in order to compose state in state. 
*)
let flatten_state_ssid (ssid,name,sl,tl,scrl,p) =
  let i2,sl2,sl3 = List.fold_left (fun (i,l2,l3) (j,n) ->
    ((i+1),(i,n)::l2,(j,i)::l3)) (!uni_ssid,[],[]) sl in
  uni_ssid := i2;
  let tl2 = List.map (fun (ssid,src,lab,dst) ->
    (ssid,src |>>> (fun x -> List.assoc x sl3),lab,List.assoc dst sl3)) tl in
  (ssid,name,sl2,tl2,scrl,p)

(* Transform state from interger to an array of integer to allows composition *)
let incr_state (ssid,name,sl,tl,scrl,p) =
  if sl=[] then { ssid=ssid;
	       name=name;
	       stateL=[];
	       ivect=[||];
	       transL=[];
	       scriptL=scrl;
	       interfaceR=StringSet.empty;
	       interfaceW=StringSet.empty;
	       priority = p;
	     }
  else begin let init = init_state (ssid,name,sl,tl,scrl) in
	     let ivect = Array.make 1 (init,name) in
	     let tl2 = List.fold_left incr_trans [] tl in
	     (*Printf.printf "\t%s\n" (stateasso init sl);*)
	     let (r,w) = interface_of_modu tl2 in
	     { ssid=ssid;
	       name=name;
	       stateL=sl;
	       ivect=ivect;
	       transL=tl2;
	       scriptL=scrl;
	       interfaceR=r;
	       interfaceW=w;
	       priority=p;
	     }
(*	     (ssid,name,sl,ivect,List.fold_left incr_trans [] tl,scrl)*)
  end


let dec_trans n (ssid,srcl,lab,dstl) =
  (ssid, (List.map (fun (x,y) -> (x+n,y)) srcl), lab ,(List.map (fun (x,y) -> (x+n,y)) dstl))

let comb_name_trans n1 n2 = match n1,n2 with 
      None,None -> None
    | Some a,None -> Some a
    | None, Some a -> Some a
    | Some a,Some b -> Some (Printf.sprintf "%s_%s" a b)

(* Combine 2 transitions *)
let comb_trans (ssidt,srcl,lab,dstl) (ssidt2,srcl2,lab2,dstl2) =
  match (lab2.trigger,lab.trigger) with
    (RAction st,_) when List.exists (fun x -> x=st) lab.write ->
      let lab3= {
	nameT = comb_name_trans (Some st) (comb_name_trans lab.nameT lab2.nameT);
	trigger= lab.trigger;
	priority= lab.priority;
	write = List.sort_uniq compare (lab.write @ lab2.write)
		    |> List.filter (fun x -> x<>st);
	update = lab.update @ lab2.update} in
      Some (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 )
  | (_,RAction st) when List.exists (fun x -> x=st) lab2.write ->
    let lab3= { 
      nameT = comb_name_trans (Some st) (comb_name_trans lab.nameT lab2.nameT);
      trigger= lab2.trigger;
      priority= lab2.priority;
      write = List.sort_uniq compare (lab.write @ lab2.write)
		  |> List.filter (fun x -> x<>st )
      ;
      update = lab.update @ lab2.update} in
    Some (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 )
  |_-> None

let combname n1 n2 = match (n1,n2) with 
      None,None -> None
    | Some a,None -> Some a
    | None, Some a -> Some a
    | Some a,Some b -> Some (Printf.sprintf "( %s | %s )" a b)

let is_changed inter (_,_,lab,_) =
  match lab.trigger with 
  | RAction s when StringSet.mem s inter->true 
  |_-> List.exists (fun x -> (StringSet.mem x inter)) lab.write

let rec combine_trans_list inter l = function
  | [] -> l
  | [_] -> l
  | t1::lt -> 
    let lchanged2,lunchanged2 =
      lt |> List.fold_left (fun (lchanged,lunchanged) t2 ->
	match comb_trans t1 t2 with
	  None -> (lchanged,lunchanged)
	| Some t -> if is_changed inter t
	  then t::lchanged,lunchanged
	  else lchanged,t::lunchanged) (lt,l) in
    combine_trans_list inter lunchanged2 lchanged2

let combine_modu ?aggrSyn:(aggrSyn=false)  m1 m2 =
(*(ssid,name,sl,ivect,tl,scrl) (ssid2,name2,sl2,ivect2,tl2,scrl2) =*)
  let n = Array.length m1.ivect in
  let ivect3 = Array.append m1.ivect m2.ivect in (* Concatenate state vector*)
  let tl3 = List.map (dec_trans n) m2.transL in  (* Shift state in transition from m2 *)
  (* Compute the set of action on which to synchronize *)
  let inter = StringSet.union (StringSet.inter m1.interfaceR m2.interfaceW)
    (StringSet.inter m2.interfaceR m1.interfaceW) in 
  (* Transition in m1 unchanged by synchronization *)
  let tlchanged,tlunchanged = List.partition (is_changed inter) m1.transL 
  (* Transition in m2 unchanged by synchronization *)
  and tlchanged2,tlunchanged2 = List.partition (is_changed inter) tl3 in
  let tl4 = combine_trans_list inter (tlunchanged@tlunchanged2)  (tlchanged@tlchanged2) in
  let rm,wm = interface_of_modu tl4 in
  let newname = combname m1.name m2.name in
  let mod3 = {ssid= fresh_ssid ();
	      name= newname;
	      stateL= m1.stateL @ m2.stateL;
	      ivect=ivect3;
	      transL=tl4;
	      scriptL= m1.scriptL @ m2.scriptL;
	      interfaceR= rm;
	      interfaceW=wm;
	      priority= None
	     } in
  Printf.fprintf !logout "Build %a\n" print_option newname;
  Printf.fprintf !logout "Interface combinaison: [ %a ]\n" (print_set ", ") inter;
  print_module2 !logout mod3;
  (*print_simulink_dot2 newname mod3;*)
   mod3

(*
let comb_trans2 l (ssidt,srcl,lab,dstl) (ssidt2,srcl2,lab2,dstl2) =
  match (lab2.trigger,lab.trigger) with
    (RAction st,_) when List.exists (fun x -> x=st) lab.write ->
      let lab3= {
	nameT = Some st;
	trigger = lab.trigger;
	priority = lab.priority; 
	write = List.sort_uniq compare (lab.write @ lab2.write);
	update = lab.update @ lab2.update} in
      (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | (_,RAction st) when List.exists (fun x -> x=st) lab2.write ->
    let lab3= { 
      nameT = Some st;
      trigger=lab2.trigger;
      priority = lab2.priority;
      write = List.sort_uniq compare (lab.write @ lab2.write);
      update = lab.update @ lab2.update} in
    (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | (RAction st,RAction st2) when st=st2 ->
    let lab3= { 
      nameT = Some st;
      trigger=lab2.trigger;
      priority=lab2.priority;
      write = List.sort_uniq compare (lab.write @ lab2.write);
      update = lab.update @ lab2.update} in
    (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  |_-> l
*)


let find_read x ml =
  List.find (fun m ->
    StringSet.mem x m.interfaceR) ml
let find_write x ml =
  List.find (fun m ->
    StringSet.mem x m.interfaceW) ml

let markmode m = m.transL |>
  List.fold_left (fun (x,y) (_,_,lab,_) -> match (lab.trigger,lab.write) with
    RAction(_),(_::_) -> (x+1,y+1) |_ -> (x,y+1)) (0,0)
    |> fun (x,y) -> (float x)/.(float y) 

(* Find module that compose well together, that is they only
   sychronize throught action shared by no other module
*)
let rec find_combinaison l =
  output_string !logout "Enter find_combinaison\n";
  Printf.fprintf !logout "Module list: [ %a ]\n" (print_list (fun x->x.name |>>| "()" ) ", ") l;
  match l with
  | [] -> []
  | [t] -> [t]
  | ml when List.exists (fun x -> StringSet.is_empty x.interfaceR && StringSet.is_empty x.interfaceW) ml ->
    let m,ol = selectL (fun x -> StringSet.is_empty x.interfaceR && StringSet.is_empty x.interfaceW) ml in
    (combine_modu m (List.hd ol)) :: (List.tl ol)
  |> find_combinaison
  | ml -> 
    let (in1,out1) = List.fold_left (fun (ii,oi) m ->
      ((add_set m.interfaceR ii),(add_set m.interfaceW oi))) (StringMap.empty,StringMap.empty) ml in 
    Printf.fprintf !logout "Read Set: [ %a ]\nWrite Set [ %a ]\n" (print_multi ", ") in1 (print_multi ", ") out1;
    try 
      let fstread,(frm,fwm) =
	StringMap.filter (fun x xn->try xn=1 && StringMap.find x out1 =1 with Not_found -> false) in1 
  |> StringMap.mapi (fun x _ -> (find_read x ml,find_write x ml))
  |> StringMap.filter (
    fun x (rm,wm) -> StringSet.union (StringSet.inter rm.interfaceR wm.interfaceW) (StringSet.inter rm.interfaceW wm.interfaceR) 
			  |> StringSet.for_all (fun x -> (StringMap.find x in1) =1 && (StringMap.find x out1)=1))
  |> StringMap.choose in
	      (combine_modu frm fwm) :: (List.filter (fun x -> x<> frm && x<>fwm) ml)
  |> find_combinaison
    with Not_found -> 
      if aggressive_syn then ( match ml with 
      | [] -> []
      | [t] -> [t]
      | m1::m2::q -> output_string !logout "Aggressive combinaison\n";
	(combine_modu ~aggrSyn:true m1 m2)::q |> find_combinaison
      ) else (output_string !logout "No combinaison\n"; ml)	

let prune_unread m =
  let tl2 = List.filter (fun (_,_,lab,_) -> match lab.trigger with
    RAction _-> false
  | _ -> true) m.transL in
  {m with transL=tl2}

 (* Remove selfloop on read *)
let prune_unread2 m =
  let tl2 = List.filter (fun (_,src,lab,dst) -> match lab.trigger with
    RAction _-> not (src = dst && lab.write=[] && lab.update=[])
  | _ -> true) m.transL in
  {m with transL=tl2}

let combine_modu2 m1 m2 =
(*(ssid,name,sl,ivect,tl,scrl) (ssid2,name2,sl2,ivect2,tl2,scrl2) =*)
  let n = Array.length m1.ivect in
  let ivect3 = Array.append m1.ivect m2.ivect in
  let tl3 = List.map (dec_trans n) m2.transL in
  let tl4 = m1.transL @ tl3 in
  let rm,wm = interface_of_modu tl4 in
  let newname = combname m1.name m2.name in
  let mod3 = {ssid= fresh_ssid ();
	      name= newname;
	      stateL= m1.stateL @ m2.stateL;
	      ivect=ivect3;
	      transL=tl4;
	      scriptL= m1.scriptL @ m2.scriptL;
	      interfaceR=rm;
	      interfaceW=wm;
	      priority=None;
} in
  (*let newname = Printf.sprintf "co%i_%i.dot" m1.ssid m2.ssid in
  Printf.fprintf stdout "Combine %s -> %a,%a\n" newname print_option m1.name print_option m2.name;
  print_simulink_dot2 newname mod3;*)
   mod3

let expand_trans2 m =
  let (nsl,ntl) = List.fold_left (fun (sl2,tl2) (ssid,src,label,dst) -> 
    match (label.trigger,src) with 
    | RAction s , [(x,y)]->  (* read *)
      let news = fresh_ssid ()
      and newsn = Printf.sprintf "PostRead_%s" s in
      let newt = fresh_ssid () in
      ((news,Some newsn)::sl2,
       (ssid,src,{empty_trans_label with trigger=label.trigger},[x,news])::
	 (newt,[x,news],{label with trigger=Imm},dst)::tl2)
    | _ -> (sl2,(ssid,src,label,dst)::tl2)) (m.stateL,[]) m.transL in
  {
    m with stateL=nsl;
      transL =ntl
  }

let prune m =
  let open IntSQMulti in 
  m.transL
	  |> List.fold_left (fun tab (trid,read,label,write) -> 
	    read |> List.fold_left (fun tab2 st -> add_multi st tab2) tab) empty
	  |> filter (fun _ i -> i=1)
	  |< iter (fun (x,y) _->Printf.printf "%i_%s\n" x @@ stateasso y m.stateL)
	  |> (fun sl -> List.filter (fun (trid,read,label,write) -> 
	    match (read,label.trigger) with
	      ([x],Imm) when mem x sl -> true
	    | _ -> false) m.transL)
	  |> List.iter (fun tr -> print_trans_simulink2 m.stateL stdout tr) 


let trans_of_int i lab =
  let label = (match lab.nameT with 
      None -> string_of_list "_" (fun x->x) lab.write
    | Some n -> n) in 
  let lab2 = (match lab.trigger with
      Imm -> "I" | Delay _ -> "D" | RAction s -> "R"^s | ImmWC _ -> "C") in
  Printf.sprintf "%s%i_%s" lab2 i label

let place_of_int ivect i =
  match ivect.(i) with
    _,None -> Printf.sprintf "pl%i" i
  | _,Some(n) -> Printf.sprintf "%s" n

(* Print magic file for Cosmos*) 
let print_magic f sl tl scrl=
  output_string f "  <attribute name=\"externalDeclaration\">";
  output_string f "#define temporalCount(msec) 0\n";
  (*List.iter (fun (x,y) -> match y with None ->()
  | Some s ->  Printf.fprintf f "#define %s %i\n" s x) sl;*)
  output_string f "#include \"markingImpl.hpp\"\n";
  List.iter (fun (x,y) -> match y with
   Some s when s="DataAvailable" -> Printf.fprintf f "#define DATA_AVAILABLE %i\n"  x | _->() ) sl;
  output_string f "const string print_magic(int v){\n";
  output_string f "\tswitch(v){\n";
  List.iter (fun (ssid,n) -> match n with 
    Some n2 -> Printf.fprintf f "\t\tcase %i: return \"%s\";\n" ssid n2
  | None -> ()) sl;
  Printf.fprintf f "\t\tdefault: return std::to_string(v);\n\t}\n}\n";
  List.iter (function (None,x) when x<>"double ctime" -> Printf.fprintf f "%s=0;\n" x | _-> ()) scrl;
  List.iter (fun x -> Printf.fprintf f "%s\n" x) DataFile.func;
  List.iter (function (Some a,x) -> Printf.fprintf f "%s\n" x | _->() ) scrl;
  Printf.fprintf f "void magicUpdate(int t,double ctime){
  switch(t){\n";
  List.iter (fun (ss,_,lab,_) ->
    if lab.update <> [] then begin
      Printf.fprintf f "\tcase TR_%s_RT:\n" (trans_of_int ss lab);
      List.iter (fun x -> Printf.fprintf f "\t\t%s;\n" x) lab.update; 
      output_string f "\tbreak;\n"
    end) tl;
  output_string f "\tdefault: break; \n\t}\n}\n";
  Printf.fprintf f "bool magicConditional(int t){
  switch(t){\n";
  List.iter (fun (ss,_,lab,_) -> begin match lab.trigger with
    ImmWC c -> 
      Printf.fprintf f "\tcase TR_%s_RT:\n" (trans_of_int ss lab);
      Printf.fprintf f "\t\treturn %s;\n" c; 
  | _ -> ();
  end) tl;
  output_string f "\tdefault: return true; \n\t}\n}\n";
  if ligthSim then output_string f "void abstractMarking::moveSerialState(){ P->_PL_SerialPort = DATA_AVAILABLE;};\n";
  output_string f "  </attribute>"

(* Print as a prism CTMC model*)
let print_prism_module fpath cf ml =
  let m = List.hd ml in
  let f = open_out fpath in
  
  Printf.fprintf f "ctmc\nconst double imm=100;\n";
  List.iter (fun (x,y) -> Printf.fprintf f "const double %s=%f;\n" x (y/.1000.)) (DataFile.data_of_file cf);
  (*List.iter (fun (x,y) -> match y with None -> () | Some s -> Printf.fprintf f "const int S_%s=%i;\n" s x) (m.stateL);*)

  Printf.fprintf f "module m1\n";

  let st_name = Array.make (Array.length m.ivect) IntSet.empty in

  List.iter (fun (ssidt,src,lab,dst) -> 
    List.iter (fun (i,s) -> st_name.(i) <- IntSet.add s st_name.(i)) src;
    List.iter (fun (i,s) -> st_name.(i) <- IntSet.add s st_name.(i)) dst;
  ) m.transL;

  Array.iteri (fun n (x,n2) -> begin
    Printf.fprintf f "\t%s: [%i..%i] init %i;\n" (place_of_int m.ivect n) (IntSet.min_elt st_name.(n)) (IntSet.max_elt st_name.(n)) x;
    IntSet.iter (fun x -> Printf.fprintf f "\t//%i -> %s;\n" x (stateasso x m.stateL)) st_name.(n)
  end) m.ivect;
  List.iter (fun (ssidt,src,lab,dst) -> 
    Printf.fprintf f "\t[%s] " (trans_of_int ssidt lab); 
    ignore @@ List.fold_left (fun b (i,s) ->
      begin
	if b then Printf.fprintf f " & ";
	Printf.fprintf f "(%s=%i)" (place_of_int m.ivect i) s;
	true
      end
    ) false src;
    
    begin match lab.trigger with
      Imm -> Printf.fprintf f " -> imm : ";
    | Delay s-> Printf.fprintf f " -> 1/(%a) : " printH_expr s;
    | RAction s  -> Printf.fprintf f " -> imm : ";
    | ImmWC s  -> Printf.fprintf f " -> imm : ";
    end;

    ignore @@ List.fold_left (fun b (i,s) ->
      if b then Printf.fprintf f " & ";
      Printf.fprintf f "(%s'=%i)" (place_of_int m.ivect i) s;
      true
    ) false dst;
    Printf.fprintf f ";\n";
  ) m.transL;
  Printf.fprintf f "endmodule\n" ;
  close_out f

let strip_type s=
  let i = String.rindex s ' ' in
  String.sub s (i+1) (String.length s-i-1) 

(* Convertion to SPT *)
let stochNet_of_modu cf m =
  let fund = fun f () -> print_magic f m.stateL m.transL m.scriptL in
  let net = Net.create () in 

  StringSet.union m.interfaceR m.interfaceW
  |< Printf.fprintf !logout "Interface [ %a ]\n" (print_set ",")
  |< StringSet.iter (fun x -> Data.add (("SIG_"^x),Int 0) net.Net.place)
  |< StringSet.iter (fun x -> Data.add (("EMPTY_"^x),(StochasticPetriNet.Imm,Float 1.0,Float 3.0)) net.Net.transition)
  |> StringSet.iter (fun x -> Net.add_inArc net ("SIG_"^x) ("EMPTY_"^x) (Int 1));

  let varlist = 
    m.scriptL |>
    List.fold_left (fun tl -> 
    (function (None,x) when x<>"double ctime" -> (strip_type x)::tl | _-> tl)
  ) [] in
  net.Net.def <- Some ([],(List.map (fun (x,y) -> (x,Some (Float(y)))) (DataFile.data_of_file cf)),varlist,fund);
  Array.iteri (fun n (x,n2) -> Data.add ((place_of_int m.ivect n),Int x) net.Net.place) m.ivect;
  List.iter (fun (ssidt,src,lab,dst) -> 
    try 
    begin match lab.trigger with
      ImmWC _ | Imm -> Data.add ((trans_of_int ssidt lab),(StochasticPetriNet.Imm,Float 1.0,Float (2.0-.0.01*.lab.priority))) 
	net.Net.transition
    | Delay s-> Data.add ((trans_of_int ssidt lab),(detfun s,Float 1.0,Float (1.0-.0.01*.lab.priority))) net.Net.transition
    | RAction s -> Data.add ((trans_of_int ssidt lab),(StochasticPetriNet.Imm,Float 1.0,Float (4.0-.0.01*.lab.priority)))
      net.Net.transition;
      Net.add_inArc net ("SIG_"^s) (trans_of_int ssidt lab) (Int 1);
      Net.add_outArc net (trans_of_int ssidt lab) ("SIG_"^s) (Int 1);
    end;
    List.iter (fun x -> 
      Net.add_inhibArc net ("SIG_"^x) (trans_of_int ssidt lab) (Int 1);
      Net.add_outArc net (trans_of_int ssidt lab) ("SIG_"^x) (Int 1)
    ) lab.write;
    List.iter (fun (i,s) ->
       begin
	Net.add_inArc net (place_of_int m.ivect i) (trans_of_int ssidt lab) (Int s);
	Net.add_inhibArc net (place_of_int m.ivect i) (trans_of_int ssidt lab) (Int (s+1));
      end
    ) src;
    List.iter (fun (i,s) ->
      Net.add_outArc net (trans_of_int ssidt lab) (place_of_int m.ivect i) (Int s)) dst
    with Not_found -> print_endline "Not_found uncatch";
  ) m.transL;
  net
