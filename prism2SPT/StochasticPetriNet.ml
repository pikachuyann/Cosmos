open Type
open PetriNet

type distr = Exp of floatExpr | Imm of floatExpr | Det of floatExpr;;


let rec print_int_expr f = function 
  | IntName(n) -> Printf.fprintf f "<attribute name=\"name\">%s</attribute>" n
  | Int(fl) -> Printf.fprintf f "<attribute name=\"numValue\">%i</attribute>" fl    
  | Mult(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"*\">
  %a
  %a
</attribute></attribute>" print_int_expr fe1 print_int_expr fe2
  | Plus(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"+\">
  %a
  %a
</attribute></attribute>" print_int_expr fe1 print_int_expr fe2
  | Minus(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"minus\">
  %a
  %a
</attribute></attribute>" print_int_expr fe1 print_int_expr fe2
 
let rec print_float_expr f = function 
  | FloatName(n) -> Printf.fprintf f "<attribute name=\"name\">%s</attribute>" n
  | Float(fl) -> Printf.fprintf f "<attribute name=\"numValue\">%f</attribute>" fl    
  | CastInt(ie) -> print_int_expr f ie
  | ExpF(fe1) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"exp\">
  %a
</attribute></attribute>" print_float_expr fe1
  | MultF(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"*\">
  %a
  %a
</attribute></attribute>" print_float_expr fe1 print_float_expr fe2
  | PlusF(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"+\">
  %a
  %a
</attribute></attribute>" print_float_expr fe1 print_float_expr fe2
  | MinusF(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"minus\">
  %a
  %a
</attribute></attribute>" print_float_expr fe1 print_float_expr fe2
  | DivF(fe1,fe2) -> Printf.fprintf f "
<attribute name=\"function\"><attribute name=\"/\">
  %a
  %a
</attribute></attribute>" print_float_expr fe1 print_float_expr fe2


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
    </attribute>" print_float_expr r
    | Imm p -> Printf.fprintf f "        DETERMINISTIC
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
          0
        </attribute></attribute>
      </attribute>
    </attribute>
    <attribute name=\"weight\"><attribute name=\"expr\">
      %a
    </attribute></attribute>" print_float_expr p
     | Det p -> Printf.fprintf f "        DETERMINISTIC
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\">
          %a
        </attribute>
      </attribute>
    </attribute>" print_float_expr p
  end

let print_tr f name id rate =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">%s</attribute>
%a
  </node>\n" id name print_distr rate
  
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
 
let gen_const f li lr =
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
    <attribute name=\"intConsts\">\n";
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
    </attribute>
  </attribute>\n"

type 'a spt = (int* 'a,distr ,intExpr ) Net.t;;

let print_spt fpath net (lci,lcd) =
  let f = open_out fpath in
  
  gen_const f 
    (List.map (fun (s,ao) ->
      match ao with None -> s,Int 1 | Some f -> s,f) lci) 
    (List.map (fun (s,ao) ->
      match ao with None -> s,Float 1.0 | Some f -> s,f) lcd);
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

let print_arc_marcie net t =
  let l1 = Data.fold (fun l (_,(v,t2,p)) ->
    if t<>t2 then l else 
      (Printf.sprintf "[%s + %i]" (fst (Data.acca net.Net.place p)) v) ::l)
    [] net.Net.outArc in
  let l2 = Data.fold (fun l (_,(v,p,t2)) ->
    if t<>t2 then l else 
      (Printf.sprintf "[%s - %i]" (fst (Data.acca net.Net.place p)) v) ::l)
    l1 net.Net.inArc in
  
  inline_ls " & " l2;;
  
let float_of_floatexp = function
  | Float f -> f
  | _ -> failwith "Fail to export to marcie"

let print_spt_marcie fpath net =
  let f = open_out fpath in
  output_string f "gspn [generated_cosmos] {\n";
  
  output_string f "places:\n";
  Data.iter (fun (s,m) ->Printf.fprintf f "\t%s = %i;\n" s m) net.Net.place;

  output_string f "\ntransitions:\n";
  output_string f "\tstochastic:\n";
  Data.iter (fun (s,distr) -> match distr with
      Exp r -> Printf.fprintf f "\t%s : : %s : %f ;\n" s 
    (print_arc_marcie net (Data.index net.Net.transition s)) (float_of_floatexp r)
    | _ -> ()   
  ) net.Net.transition;
  output_string f "\timmediate:\n";
  Data.iter (fun (s,distr) -> match distr with
      Imm r -> Printf.fprintf f "\t%s : : %s : %f ;\n" s 
    (print_arc_marcie net (Data.index net.Net.transition s)) (float_of_floatexp r)
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


