open Xml
open PetriNet
open StochasticPetriNet
open Type
open SimulinkType
open Lexing

let modelStoch = true


let detfun s =
  if modelStoch then 
    let n = 100 in
    StochasticPetriNet.Erl (Int n,DivF (Float (float n),s))
  else StochasticPetriNet.Det s



let ssid_count = ref (-1)
let fresh_ssid () =
  let f= !ssid_count in
  incr ssid_count; f

let getSSID al = 
  let i = int_of_string (List.assoc "SSID" al)  in
  ssid_count := max !ssid_count (i+1); 
  i

let rec findprop f = function
  | [] -> None
  | t::q -> (match f t with None -> findprop f q | x-> x)

let getName cl = findprop (function 
  | Element ("P",["Name","labelString"],[PCData(l)])  -> Some l 
  | _ -> None) cl

let getScope cl = findprop (function 
  | Element ("P",["Name","scope"],[PCData(l)])  -> Some l 
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

let getScript cl = findprop (function 
  | Element ("eml",_,cl2) -> findprop (function 
      | Element ("P",["Name","script"],[PCData(l)])  -> Some l 
      | _ -> None) cl2
  | _ -> None) cl
  
let rec exp_data = function
   | Element ("data",alist,clist) when getScope clist = Some "LOCAL_DATA" ->
     let name = List.assoc "name" alist in
     Some ((getSSID alist),name)
    | _-> None

let print_position outx lexbuf =
  let pos = lexbuf.Lexing.lex_curr_p in
  Printf.fprintf outx "%s:%d:%d" pos.pos_fname
    pos.pos_lnum (pos.pos_cnum - pos.pos_bol + 1)

let parse_regexp = Str.regexp "function \\([A-Za-z0-9_]+\\)[ ]*=[ ]*\\([A-Za-z0-9_]+[(][A-Za-z0-9_,]*[)]\\)\n\\([^̂†]*\\)\nend"
let reg_comm = Str.regexp "%"
let reg_type1 = Str.regexp "[(]"
let reg_type2 = Str.regexp "[,]"
  
let parse_fun scr =
  assert (Str.string_match parse_regexp scr 0);
  let var = Str.matched_group 1 scr
  and name = Str.matched_group 2 scr
  and body = Str.matched_group 3 scr in
  let name2 = name 
    |> Str.global_replace reg_type1 "(double "
    |> Str.global_replace reg_type2 ", double " in
  let body2 = Str.global_replace reg_comm "//" body in
  (name,Printf.sprintf "double %s{\n\tdouble %s;\n%s\n\treturn %s;\n}" name2 var body2 var)
  
(*parse_fun "function dT  = modulateRefrRetro(t,t0)\n toto\ntata \nend";;*)
    
let rec exp_mod (sl,tl,scriptl) = function
    | Element (name,alist,clist) ->
       begin match name with
       | "Children" -> List.fold_left exp_mod (sl,tl,scriptl) clist
       | "state" -> begin match getScript clist with
	   None -> (((getSSID alist),(getName clist))::sl,tl,scriptl)
	   | Some scr -> let fn,fb = parse_fun scr in (sl,tl,((Some fn),fb)::scriptl)
       end 
       | "transition" -> (match getdst clist with Some dst ->
	 (sl,((getSSID alist),(getName clist),(getsrc clist),dst)::tl,scriptl) | _ -> failwith "Ill formed transition")
       | "data" -> begin try  (sl,tl,(None,List.assoc "name" alist)::scriptl); with
	   | Not_found -> (sl,tl,scriptl)
       end

       | x -> Printf.fprintf stderr "Dont know what to do with %s, ignore\n" x; (sl,tl,scriptl)
       end
    | PCData (s) -> output_string stderr s; (sl,tl,scriptl)

let eval_trans sl (ssid,name,src,dst) = match name with
    None -> (ssid,src,empty_trans_label,dst)
  | Some s -> let lexbuf = Lexing.from_string s in
	      try     
		let label = ParserSimulEdge.main LexerSimulEdge.token lexbuf in
		let label2 = {label with write = List.sort_uniq compare label.write;
			     nameT = src |>> (fun x -> List.assoc x sl) } in
		(ssid,src,label2,dst)
    with 
      Parsing.Parse_error ->
	Printf.fprintf stderr "%a: Parsing error: unexpected token:'%s' in %s\n"
	  print_position lexbuf (Lexing.lexeme lexbuf) s;
	(ssid,src,empty_trans_label,dst)

let module_of_simul al cl = 
  let ssid = getSSID al in
  let name = getName cl in
  let childs = List.find (function Element ("Children",_,_)->true | _-> false) cl in
  let sl,tl,scriptl = exp_mod ([],[],[]) childs in
  let modu = ssid,name,sl,(List.map (eval_trans sl) tl),scriptl in 
  (*print_module modu;*)
  modu

let post_name sl s t =
  match List.assoc s sl with
    None -> Printf.sprintf "%i_Pre" t
  | Some(sn) -> Printf.sprintf "%i_Pre_%s" t sn

let expand_trans l=
  List.map (fun (ssidmod,name,sl,tl,scrl) ->
    let (nsl,ntl) = List.fold_left (fun (sl2,tl2) (ssid,src,label,dst) -> 
      match (label.trigger,label.write,src) with 
      | (Delay(_),(_::_),_) -> (* wait and synch loop *)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	(ssid,src,{empty_trans_label with trigger=label.trigger; nameT=(src |>> (fun x ->List.assoc x sl))  },news)::
	  (newt,Some(news),{label with trigger=Imm},dst)::tl2)
      | (RAction(sn),_,Some src2) when src2=dst->  (* self loop with read *)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	(ssid,src,{empty_trans_label with trigger=label.trigger; nameT=Some sn },news)::
	  (newt,Some(news),{label with trigger=Imm},dst)::tl2)
      | (_,_,None) when label.update <> [] -> (* Initial transition with update*)
	let news = fresh_ssid ()
	and newsn = post_name sl dst ssid in
	let newt = fresh_ssid () in
	((news,Some newsn)::sl2,
	 (ssid,None,empty_trans_label,news)::
	   (newt,Some(news),{label  with nameT=Some "init"},dst)::tl2)
      | _ -> (sl2,(ssid,src,label,dst)::tl2)) (sl,[]) tl in
    (ssidmod,name,nsl,ntl,scrl)) l
	      

let print_modu f (ssid,name,sl,tl,scrl) =
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
    | Element (name,alist,clist) as t ->
       begin match name with
       | "xml" | "ModelInformation" | "Model" | "Stateflow" | "machine" | "chart" | "Children" ->
					 List.fold_left (prism_of_stateflow level) ml clist
       | "P" -> ml
       | "state" -> if level=1 then (module_of_simul alist clist)::ml
	 else List.fold_left (prism_of_stateflow (level+1)) ml clist
       | "transition" -> ml
       | "target" -> ml
       | "subviewS" -> ml
       | "instance" -> ml
       | "data" -> begin match exp_data t with None -> ml | Some (ssid,var) ->
	 (ssid,None,[],[],[None,var])::ml
	 end
       | "event" -> ml
       | x -> Printf.fprintf stderr "Dont know wat to do with %s, ignore\n" x; ml
       end
    | PCData (s) -> output_string stderr s; ml

let rec prism_of_tree ml = function
  | Element (name,alist,clist) as t->
    begin match name with
    | "xml" | "ModelInformation" | "Model" | "P" ->
      List.fold_left prism_of_tree ml clist
       | "Stateflow" -> prism_of_stateflow 0 ml t
       | _ -> ml
       end
    | PCData (s) -> ml

let flatten_module (ssid,name,sl,tl,scrl) =
  let inaction,_ = interface_of_modu tl in
  let tl2 = List.fold_left (fun nt2 (ss,_) ->
    StringSet.fold (fun sa tl3 ->
      if not (List.exists (fun (_,src,lab,_) ->
	match (src,lab.trigger) with 
	  ((Some x),(RAction y)) when x=ss && y = sa -> true 
	| ((Some x),(Imm)) when x=ss -> true
	| _-> false
      ) tl) 
      then ((fresh_ssid ()),Some ss,{empty_trans_label with trigger = RAction(sa) },ss)::tl3 
      else tl3) inaction nt2) tl sl in 
  (ssid,name,sl,tl2,scrl)
  
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

let incr_trans l (ssid,src,lab,dst) =
  match src with
  | None -> l
  | Some src2 ->
    (ssid,[(0,src2)],lab,[(0,dst)])::l
  
let incr_state (ssid,name,sl,tl,scrl) =
  if sl=[] then { ssid=ssid;
	       name=name;
	       stateL=[];
	       ivect=[||];
	       transL=[];
	       scriptL=scrl;
	       interfaceR=StringSet.empty;
	       interfaceW=StringSet.empty;
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
	     }
(*	     (ssid,name,sl,ivect,List.fold_left incr_trans [] tl,scrl)*)
  end


let dec_trans n (ssid,srcl,lab,dstl) =
  (ssid, (List.map (fun (x,y) -> (x+n,y)) srcl), lab ,(List.map (fun (x,y) -> (x+n,y)) dstl))


let comb_trans l (ssidt,srcl,lab,dstl) (ssidt2,srcl2,lab2,dstl2) =
  match (lab2.trigger,lab.trigger) with
    (RAction st,_) when List.exists (fun x -> x=st) lab.write ->
      let lab3= {
	nameT = Some st;
	trigger=lab.trigger;
		  write = List.sort_uniq compare (lab.write @ lab2.write)
		    |> List.filter (fun x -> x<>st );
		update = lab.update @ lab2.update} in
      (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | (_,RAction st) when List.exists (fun x -> x=st) lab2.write ->
    let lab3= { 
      nameT = Some st;
      trigger=lab2.trigger;
		write = List.sort_uniq compare (lab.write @ lab2.write)
		  |> List.filter (fun x -> x<>st )
		;
		update = lab.update @ lab2.update} in
    (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  |_-> l


let combine_modu m1 m2 =
(*(ssid,name,sl,ivect,tl,scrl) (ssid2,name2,sl2,ivect2,tl2,scrl2) =*)
  let n = Array.length m1.ivect in
  let ivect3 = Array.append m1.ivect m2.ivect in
  let tl3 = List.map (dec_trans n) m2.transL in
  let inter = StringSet.union (StringSet.inter m1.interfaceR m2.interfaceW)
    (StringSet.inter m2.interfaceR m1.interfaceW) in
  let tlunchanged = List.filter (fun (_,_,lab,_) -> 
     ((match lab.trigger with RAction s when StringSet.mem s inter->false |_->true)
	 && (List.for_all (fun x -> not (StringSet.mem x inter)) lab.write))) m1.transL
  and tlunchanged2 = List.filter (fun (_,_,lab,_) -> 
     ((match lab.trigger with RAction s when StringSet.mem s inter->false |_->true)
      && (List.for_all (fun x -> not (StringSet.mem x inter)) lab.write))) tl3 in
  let tl4 = 
    List.fold_left (fun l t1 ->
      List.fold_left (fun l2 t2 -> comb_trans l2 t1 t2) l tl3) (tlunchanged@tlunchanged2) m1.transL 
in
  let rm,wm = interface_of_modu tl4 in
  let newname = match (m1.name,m2.name) with 
      None,None -> None
    | Some a,None -> Some a
    | None, Some a -> Some a
    | Some a,Some b -> Some (Printf.sprintf "( %s | %s )" a b) in
  let mod3 = {ssid= fresh_ssid ();
	      name= newname;
	      stateL= m1.stateL @ m2.stateL;
	      ivect=ivect3;
	      transL=tl4;
	      scriptL= m1.scriptL @ m2.scriptL;
	      interfaceR= rm;
	      interfaceW=wm} in
  Printf.fprintf !logout "Build %a\n" print_option newname;
  Printf.fprintf !logout "Interface combinaison: [ %a ]\n" (print_set ", ") inter;
  print_module2 !logout mod3;
  (*print_simulink_dot2 newname mod3;*)
   mod3

let find_read x ml =
  List.find (fun m ->
    StringSet.mem x m.interfaceR) ml
let find_write x ml =
  List.find (fun m ->
    StringSet.mem x m.interfaceW) ml

let rec find_combinaison l = 
  output_string !logout "Enter find_combinaison\n";
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
    try let fstread,(frm,fwm) =
	  StringMap.filter (fun x xn->try xn=1 && StringMap.find x out1 =1 with Not_found -> false) in1 
  |> StringMap.mapi (fun x _ -> (find_read x ml,find_write x ml))
  |> StringMap.filter (
    fun x (rm,wm) -> StringSet.union (StringSet.inter rm.interfaceR wm.interfaceW) (StringSet.inter rm.interfaceW wm.interfaceR) 
    |> StringSet.for_all (fun x -> (StringMap.find x in1) =1 && (StringMap.find x out1)=1))
  |> StringMap.choose in
	      (combine_modu frm fwm) :: (List.filter (fun x -> x<> frm && x<>fwm) ml)
  |> find_combinaison
	  with Not_found -> output_string !logout "No combinaison\n"; ml
    

let prune_unread m =
  let tl2 = List.filter (fun (_,_,lab,_) -> match lab.trigger with
    RAction _-> false
  | _ -> true) m.transL in
  {m with transL=tl2}

let prune_unread2 m =
  let tl2 = List.filter (fun (_,src,lab,dst) -> match lab.trigger with
    RAction _-> not (src = dst && lab.write=[] && lab.update=[])
  | _ -> true) m.transL in
  {m with transL=tl2}

(*
let comb_trans2 l (ssidt,srcl,lab,dstl) (ssidt2,srcl2,lab2,dstl2) =
  match (lab2.trigger,lab.trigger) with
    (RAction st,_) when List.exists (fun x -> x=st) lab.write ->
      let lab3= {
	nameT = Some st;
	trigger=lab.trigger;
	write = List.sort_uniq compare (lab.write @ lab2.write);
	update = lab.update @ lab2.update} in
      (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | (_,RAction st) when List.exists (fun x -> x=st) lab2.write ->
    let lab3= { 
      nameT = Some st;
      trigger=lab2.trigger;
      write = List.sort_uniq compare (lab.write @ lab2.write);
      update = lab.update @ lab2.update} in
    (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  | (RAction st,RAction st2) when st=st2 ->
    let lab3= { 
      nameT = Some st;
      trigger=lab2.trigger;
      write = List.sort_uniq compare (lab.write @ lab2.write);
      update = lab.update @ lab2.update} in
    (fresh_ssid (),srcl@srcl2,lab3 ,dstl@dstl2 ) ::l
  |_-> l
*)

let combine_modu2 m1 m2 =
(*(ssid,name,sl,ivect,tl,scrl) (ssid2,name2,sl2,ivect2,tl2,scrl2) =*)
  let n = Array.length m1.ivect in
  let ivect3 = Array.append m1.ivect m2.ivect in
  let tl3 = List.map (dec_trans n) m2.transL in
  let tl4 = m1.transL @ tl3 in
  let rm,wm = interface_of_modu tl4 in
  let newname = match (m1.name,m2.name) with 
      None,None -> None
    | Some a,None -> Some a
    | None, Some a -> Some a
    | Some a,Some b -> Some (Printf.sprintf "( %s | %s )" a b) in
  let mod3 = {ssid= fresh_ssid ();
	      name= newname;
	      stateL= m1.stateL @ m2.stateL;
	      ivect=ivect3;
	      transL=tl4;
	      scriptL= m1.scriptL @ m2.scriptL;
	      interfaceR=rm;
	      interfaceW=wm} in
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

let trans_of_int i lab =
  let label = (match lab.nameT with 
      None -> string_of_list "_" (fun x->x) lab.write
    | Some n -> n) in 
  let lab2 = (match lab.trigger with
      Imm -> "I" | Delay _ -> "D" | RAction s -> "R"^s) in
  Printf.sprintf "%s%i_%s" lab2 i label

let place_of_int ivect i =
  match ivect.(i) with
    _,None -> Printf.sprintf "pl%i" i
  | _,Some(n) -> Printf.sprintf "%s" n

let print_magic f sl tl scrl=
  output_string f "  <attribute name=\"externalDeclaration\">";
  output_string f "#define temporalCount(msec) 0\n";
  output_string f "const string print_magic(int v){\n";
  output_string f "\tswitch(v){\n";
  List.iter (fun (ssid,n) -> match n with 
    Some n2 -> Printf.fprintf f "\t\tcase %i: return \"%s\";\n" ssid n2
  | None -> ()) sl;
  Printf.fprintf f "\t\tdefault: return std::to_string(v);\n\t}\n}\n";
  List.iter (function (None,x) when x<>"ctime" -> Printf.fprintf f "double %s=0;\n" x | _-> ()) scrl;
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
  output_string f "\tdefault: break;\n\t}\n}\n";
  output_string f "  </attribute>"

let stochNet_of_modu m =
  let fund = fun f () -> print_magic f m.stateL m.transL m.scriptL in
  let net = Net.create () in 

  StringSet.union m.interfaceR m.interfaceW
  |< Printf.fprintf !logout "Interface [ %a ]\n" (print_set ",")
  |< StringSet.iter (fun x -> Data.add (("SIG_"^x),Int 0) net.Net.place)
  |< StringSet.iter (fun x -> Data.add (("EMPTY_"^x),StochasticPetriNet.Imm ((Float 1.0),(Int 3))) net.Net.transition)
  |> StringSet.iter (fun x -> Net.add_inArc net ("SIG_"^x) ("EMPTY_"^x) (Int 1));

  let varlist = List.fold_left (fun tl -> (function (None,x) when x<>"ctime" -> x::tl | _-> tl)) [] m.scriptL in
  net.Net.def <- Some ([],(List.map (fun (x,y) -> (x,Some (Float(y)))) DataFile.data),varlist,fund);
  Array.iteri (fun n (x,n2) -> Data.add ((place_of_int m.ivect n),Int x) net.Net.place) m.ivect;
  List.iter (fun (ssidt,src,lab,dst) -> 
    try 
    begin match lab.trigger with
      Imm -> Data.add ((trans_of_int ssidt lab),StochasticPetriNet.Imm ((Float 1.0),(Int 2))) net.Net.transition
    | Delay s-> Data.add ((trans_of_int ssidt lab),detfun s) net.Net.transition
    | RAction s -> Data.add ((trans_of_int ssidt lab),StochasticPetriNet.Imm ((Float 1.0),(Int 4))) net.Net.transition;
      Net.add_inArc net ("SIG_"^s) (trans_of_int ssidt lab) (Int 1);
      Net.add_outArc net (trans_of_int ssidt lab) ("SIG_"^s) (Int 1);
    end;
    List.iter (fun x -> Net.add_outArc net (trans_of_int ssidt lab) ("SIG_"^x) (Int 1)) lab.write;
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

