open Type
open PetriNet

type distr = 
  Exp of float expr' 
| Imm 
| Det of float expr' 
| Erl of (int expr'*float expr');;

let print_cmpGrML f = function
  | EQ -> output_string f "equal"  
  | NEQ-> output_string f "notEqual" 


let rec print_expr: type a. out_channel -> a expr' -> unit = fun f x -> match x with
  | IntName(n) -> Printf.fprintf f "<attribute name=\"name\">%s</attribute>" n
  | Int(fl) -> Printf.fprintf f "<attribute name=\"numValue\">%i</attribute>" fl    
  | FloatName(n) -> Printf.fprintf f "<attribute name=\"name\">%s</attribute>" n
  | Float(fl) -> Printf.fprintf f "<attribute name=\"numValue\">%f</attribute>" fl
  | BoolName(n) -> Printf.fprintf f "<attribute name=\"name\">%s</attribute>" n
  | Bool(fl) -> Printf.fprintf f "<attribute name=\"boolValue\">%B</attribute>" fl
  | Not(fe) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"not\">
  %a
</attribute></attribute>" print_expr fe
| And(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"and\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
| Or(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"or\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
  | Mult(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"*\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
  | Plus(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"+\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
  | Minus(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"minus\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
  | Ceil(fe) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"ceil\">
  %a
</attribute></attribute>" print_expr fe
  | Floor(fe) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"floor\">
  %a
</attribute></attribute>" print_expr fe
  | CastInt(ie) -> print_expr f ie
  | Exp(fe1) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"exp\">
  %a
</attribute></attribute>" print_expr fe1
  | Div(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"/\">
  %a
  %a
</attribute></attribute>" print_expr fe1 print_expr fe2
  | FunCall(s,l) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"%s\">\n  " s;
    List.iter (fun x ->print_expr f x;output_string f "\n  ";) l;
    output_string f "</attribute></attribute>"
  | IntAtom(rhs,cmp,lhs) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"%a\">
  %a
  %a
</attribute></attribute>" print_cmpGrML cmp print_expr rhs print_expr lhs
  

let print_int_expr f (x: int expr') = print_expr f x
let print_float_expr f (x: float expr') = print_expr f x

let print_distr f d = 
  output_string f "    <attribute name=\"distribution\">
      <attribute name=\"type\">\n";
  begin match d with
      Exp r -> Printf.fprintf f "        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\">%a</attribute>
      </attribute>
    </attribute>" print_expr r
  | Erl (i,r) -> Printf.fprintf f "        ERLANG
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\">%a</attribute>
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">1</attribute>
        <attribute name=\"expr\">%a</attribute>
      </attribute>
    </attribute>" print_expr i print_expr r
    | Imm -> Printf.fprintf f "        DETERMINISTIC
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
          0
        </attribute></attribute>
      </attribute>
    </attribute>"
    | Det p -> Printf.fprintf f "        DETERMINISTIC
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\">
          %a
        </attribute>
      </attribute>
    </attribute>" print_expr p
  end

let print_tr f name id (rate,weight,prio) =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">%s</attribute>
%a
      <attribute name=\"priority\"><attribute name=\"expr\">
        %a
      </attribute></attribute>
      <attribute name=\"weight\"><attribute name=\"expr\">
        %a
      </attribute></attribute>
  </node>\n" id name print_distr rate print_float_expr prio print_float_expr weight
  
let print_pl f name id tok =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"place\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"marking\"><attribute name=\"expr\">
      %a
    </attribute></attribute>
  </node>\n" id name print_int_expr tok

let print_arc f id source target valuation inhib =
  let arctype = if inhib then "inhibitorarc" else "arc" in
  Printf.fprintf f "  <arc id=\"%i\" arcType=\"%s\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\"><attribute name=\"expr\">
        %a
    </attribute></attribute>
  </arc>\n" id arctype source target print_int_expr valuation
 
let gen_const f li lr le fund =
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
%a
  <attribute name=\"declaration\"><attribute name=\"constants\">
    <attribute name=\"intConsts\">\n" fund ();
  List.iter (fun (n,v) -> 
     Printf.fprintf f "      <attribute name=\"intConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %a
        </attribute></attribute>
      </attribute>\n" n printH_int_expr v) li;
  
  Printf.fprintf f "    </attribute>
    <attribute name=\"realConsts\">\n";
  List.iter (fun (n,v) -> 
    Printf.fprintf f "      <attribute name=\"realConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %a
        </attribute></attribute>
      </attribute>\n" n printH_float_expr v) lr;
    Printf.fprintf f
      "     </attribute>
    <attribute name=\"extConsts\">\n";
  List.iter (fun (n) -> 
     Printf.fprintf f "      <attribute name=\"extConst\">
        <attribute name=\"name\">%s</attribute>
      </attribute>\n" n) le;
  
  Printf.fprintf f "    </attribute>
    </attribute>
  </attribute>\n"

type spt = (int Type.expr',distr*float Type.expr' * float Type.expr' ,int Type.expr' , ((string*(int Type.expr') option) list)* ((string*(float Type.expr') option) list)* (string list)*(out_channel->unit->unit) ) Net.t;;

let print_spt fpath (net:spt)  =
  let f = open_out fpath in
  let (lci,lcd,lce,fund) = begin match net.Net.def with None -> [],[],[],(fun _ ()->()) | Some x ->x end in
  gen_const f 
    (List.map (fun (s,ao) ->
      match ao with None -> s,(Int 1) | Some fl -> s,fl) lci) 
    (List.map (fun (s,ao) ->
      match ao with None -> s,(Float 1.0) | Some fl -> s,fl) lcd) lce fund;
  let np = Data.fold (fun i (s,m) ->print_pl f s i m; i+1) 0 net.Net.place in
  let nt = Data.fold (fun i (s,r) ->print_tr f s i r; i+1) np net.Net.transition in
  let nia = Data.fold (fun i (_,(v,p,t)) ->print_arc f i p (t+np) v false; i+1) nt net.Net.inArc in
  let nio = Data.fold (fun i (_,(v,t,p)) ->print_arc f i (t+np) p v false; i+1) nia net.Net.outArc in
  let _ = Data.fold (fun i (_,(v,p,t)) ->print_arc f i p (t+np) v true; i+1) nio net.Net.inhibArc in
  ();
(*
  for i =1 to n do
    print_pl f ("RE_Queue"^(string_of_int i)) countid (if i=1 then 1 else 0);
  done;

  print_tr f "Arrive" countid "lambda";

  for i =1 to n do
    print_tr f ("Serve"^(string_of_int i)) countid ("rho"^(string_of_int i));
  done;
  
  if genDTMC then for i =1 to n do
      print_tr f ("AServe"^(string_of_int i)) countid ("rho"^(string_of_int i));
    done;

  for i =0 to n-1 do
    print_arc f countid (n+i) i 1 false;
    print_arc f countid i (n+i+1) 1 false;
  done;
  
  if genDTMC then for i =0 to n-1 do
      print_arc f countid i (2*n+i+1) 1 true;
    done;*)
  Printf.fprintf f "</model>";
  close_out f;;

let rec inline_ls d = function
  | [] -> ""
  | [s] -> s
  | t::q -> t^d^(inline_ls d q);;

let print_arc_marcie net f t =
  let fq = Data.fold (fun first (_,(v,t2,p)) ->
    if t<>t2 then first else begin 
      if not first then Printf.fprintf f " & ";
      Printf.fprintf f "[%s + %a]" (fst (Data.acca net.Net.place p)) printH_int_expr v;
      false
    end)
    true net.Net.outArc in
  ignore (Data.fold (fun first (_,(v,p,t2)) ->
    if t<>t2 then first else begin
      if not first then Printf.fprintf f " & ";
      Printf.fprintf f "[%s - %a]" (fst (Data.acca net.Net.place p)) printH_int_expr v;
      false
    end)
	    fq net.Net.inArc)
	
    
let float_of_floatexp = function
  | Float f -> f
  | _ -> failwith "Fail to export to marcie"

let print_spt_marcie fpath net =
  let f = open_out fpath in
  output_string f "gspn [generated_cosmos] {\n";
  
  output_string f "places:\n";
  Data.iter (fun (s,m) ->Printf.fprintf f "\t%s = %a;\n" s printH_int_expr m) net.Net.place;

  output_string f "\ntransitions:\n";
  output_string f "\tstochastic:\n";
  Data.iter (fun (s,(distr,_,_)) -> match distr with
      Exp r -> Printf.fprintf f "\t%s : : %a : %f ;\n" s 
    (print_arc_marcie net) (Data.index net.Net.transition s) (float_of_floatexp r)
    | _ -> ()   
  ) net.Net.transition;
  output_string f "\timmediate:\n";
  Data.iter (fun (s,(distr,r,_)) -> match distr with
      Imm -> Printf.fprintf f "\t%s : : %a : %f ;\n" s 
    (print_arc_marcie net) (Data.index net.Net.transition s) (float_of_floatexp r)
    | _ -> ()   
  ) net.Net.transition;


  output_string f "}\n";
  close_out f;;

let print_arc_dot f s1 s2 v =
  if v<>Int 1 then
    Printf.fprintf f "\t%s -> %s [label=\"%a\"];\n" s1 s2 printH_int_expr v
  else Printf.fprintf f "\t%s -> %s;\n" s1 s2;;

let print_inhib_arc_dot f s1 s2 v =
  if v<>Int 1 then
    Printf.fprintf f "\t%s -> %s [arrowhead=odot,label=\"%a\"];\n" s1 s2 printH_int_expr v
  else Printf.fprintf f "\t%s -> %s [arrowhead=odot];\n" s1 s2;;


let print_spt_dot fpath net cl p =
  let f = open_out fpath in
  output_string f "digraph G {\n";
  
(*  output_string f "\tsubgraph place {\n";
  output_string f "\t\tgraph [shape=circle];\n";
  output_string f "\t\tnode [shape=circle,fixedsize=true];\n";*)
  Data.iter (fun (s,m) ->
    let pos = (try let x,y = List.assoc s p in
		   Printf.sprintf ",pos=\"%f,%f!\"" (2.0*.x) (2.0*.y)
      with Not_found -> "") in
	
    Printf.fprintf f "\t%s [shape=circle,xlabel=\"%s\",label=\"%a\"%s];\n" s s 
      print_token m
      pos
  ) net.Net.place;
  (*output_string f "\t}\n\tsubgraph transition {\n";
  output_string f "\t\tnode [shape=rect,fixedsize=true,height=0.2,style=filled,fillcolor=black];\n";*)
  Data.iter (fun (s,m) ->Printf.fprintf f "\t%s [shape=rect,fixedsize=true,height=0.2,style=filled,fillcolor=black,xlabel=\"%s\",label=\"\"];\n" s s) net.Net.transition;
  (*output_string f "\t}\n";*)
  Data.iter (fun (_,(v,p,t)) ->
    print_arc_dot f (fst (Data.acca net.Net.place p)) 
      (fst (Data.acca net.Net.transition t)) v) net.Net.inArc;
  Data.iter (fun (_,(v,p,t)) ->
    print_inhib_arc_dot f (fst (Data.acca net.Net.place p)) 
      (fst (Data.acca net.Net.transition t)) v) net.Net.inhibArc;
  Data.iter (fun (_,(v,t,p)) ->
    print_arc_dot f (fst (Data.acca net.Net.transition t))
      (fst (Data.acca net.Net.place p)) v) net.Net.outArc;

  List.iter (fun (s,l) ->
    Printf.fprintf f "\tsubgraph \"test%i\" {\n\trank=%i; " s s;
    List.iter (fun s2 -> Printf.fprintf f " %s;" s2) l; 
    output_string f "}\n";) cl;
  output_string f "}\n";
  close_out f;;

open Net

let remove_erlang (net:spt) =
  let net2 = {net with Net.def = net.Net.def; 
    transition = Data.copy net.transition;
    inArc = Data.copy net.inArc;
    outArc = Data.copy net.outArc;
    inhibArc = Data.copy net.inhibArc} in
  Data.iter (fun (y,(z,we,pr)) -> match z with
    Erl(n,lamb) ->
      Data.add (("P"^y^"ErCont"), Int 0) net2.Net.place;
      Data.add ((y^"ErStep"),(Exp lamb,we,pr)) net2.Net.transition;
      Data.add ((y^"ErEmpty"),(Imm,we,pr)) net2.Net.transition;
      Net.add_inArc net2 ("P"^y^"ErCont") y n;
      Net.add_outArc net2 (y^"ErStep") ("P"^y^"ErCont") (Int 1);
      Net.add_inArc net2 ("P"^y^"ErCont") (y^"ErEmpty") (IntName ("P"^y^"ErCont"));
      let it = Data.index net.Net.transition y in
      Data.iter (fun ((),(v,p,t)) -> if t = it then begin
	let pn,_ = Data.acca net.Net.place p in
	Net.add_inArc net2 pn (y^"ErStep") v;
	Net.add_inhibArc net2 pn (y^"ErEmpty") v;
	Net.add_outArc net2 (y^"ErStep") pn v;
      end) net.Net.inArc;
      Data.iter (fun ((),(v,p,t)) -> if t = it then begin
	let pn,_ = Data.acca net.Net.place p in
	Net.add_inhibArc net2 pn (y^"ErStep") v;
	Net.add_inArc net2 pn (y^"ErEmpty") v;
	Net.add_outArc net2 (y^"ErEmpty") pn v;
      end) net.Net.inhibArc;
  | _ ->() ) net.Net.transition;

  let transn2 = Data.map net2.Net.transition (fun (z,we,pr) -> match z with
      Erl(n,lamb) -> (Imm,we,pr)
    | _ -> (z,we,pr)) in
  {net2 with Net.transition= transn2}

