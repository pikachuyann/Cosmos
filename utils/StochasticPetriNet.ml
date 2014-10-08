#use "PetriNet.ml"

let print_tr f name id rate =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"distribution\">
      <attribute name=\"type\">
        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
          %f
        </attribute></attribute>
      </attribute>
    </attribute>
  </node>\n" id name rate
  

let print_pl f name id tok =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"place\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"marking\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </node>\n" id name tok


let print_arc f id source target valuation inhib =
  let arctype = if inhib then "inhibitorarc" else "arc" in
  Printf.fprintf f "  <arc id=\"%i\" arcType=\"%s\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </arc>\n" id arctype source target valuation 

let gen_const f li lr =
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
    <attribute name=\"intConsts\">\n";
  List.iter (fun (n,v) -> 
     Printf.fprintf f "      <attribute name=\"intConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %i
        </attribute></attribute>
      </attribute>\n" n v) li;
  
  Printf.fprintf f "    </attribute>
    <attribute name=\"realConsts\">\n";
  List.iter (fun (n,v) -> 
    Printf.fprintf f "      <attribute name=\"realConst\">
        <attribute name=\"name\">%s</attribute>
        <attribute name=\"expr\"><attribute name=\"numValue\">
            %f
        </attribute></attribute>
      </attribute>\n" n v) lr;
    Printf.fprintf f
      "     </attribute>
    </attribute>
  </attribute>\n"

type spt = (int,float) Net.t;;

let print_spt fpath net =
  let f = open_out fpath in
  
  gen_const f [] [];
  let np = Data.fold (fun i (s,m) ->print_pl f s i m; i+1) 0 net.Net.place in
  let nt = Data.fold (fun i (s,r) ->print_tr f s i r; i+1) np net.Net.transition in
  let nia = Data.fold (fun i (_,(v,p,t)) ->print_arc f i p (t+np) v false; i+1) nt net.Net.inArc in
  let _ = Data.fold (fun i (_,(v,t,p)) ->print_arc f i (t+np) p v false; i+1) nia net.Net.outArc in
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

