let automataGenPath = "automataGen"

let print_tr f name id rate =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"distribution\">
      <attribute name=\"type\">
        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"name\">
          %s
        </attribute></attribute>
      </attribute>
    </attribute>
  </node>\n" !id name rate;
  incr id;;

let print_pl f name id tok =
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"place\">
    <attribute name=\"name\">%s</attribute>
    <attribute name=\"marking\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </node>\n" !id name tok;
  incr id;;

let print_arc f id source target valuation =
  Printf.fprintf f "<arc id=\"%i\" arcType=\"arc\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        %i
      </attribute></attribute>
    </attribute>
  </arc>\n" !id source target valuation; 
  incr id;;

let generate_spn fpath n lambda rho r=
  let f = open_out fpath in
  let countid = ref 0 in
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
      <attribute name=\"intConsts\">
        <attribute name=\"intConst\">
          <attribute name=\"name\">r</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %i
          </attribute></attribute>
        </attribute>
      </attribute>
      <attribute name=\"realConsts\">
        <attribute name=\"realConst\">
          <attribute name=\"name\">lambda</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %f
          </attribute></attribute>
        </attribute>
        <attribute name=\"realConst\">
          <attribute name=\"name\">rho</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %f
          </attribute></attribute>
        </attribute>
      </attribute>
    </attribute>
  </attribute>\n" r lambda rho;


  for i =1 to n do
    print_pl f ("RE_Queue"^(string_of_int i)) countid (if i=1 then 1 else 0);
  done;

  print_tr f "Arrive" countid "lambda";

  for i =1 to n do
    print_tr f ("Serve"^(string_of_int i)) countid "rho";
  done;

  for i =0 to n-1 do
    print_arc f countid (n+i) i 1;
    print_arc f countid i (n+i+1) 1;
  done;
  Printf.fprintf f "</model>";
  close_out f;;


let generate_reduce_spn fpath n lambda rho r =
  let f = open_out fpath in
  let countid = ref 0 in
  Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
      <attribute name=\"intConsts\">
        <attribute name=\"intConst\">
          <attribute name=\"name\">r</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %i
          </attribute></attribute>
        </attribute>
      </attribute>
      <attribute name=\"realConsts\">
        <attribute name=\"realConst\">
          <attribute name=\"name\">lambda</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %f
          </attribute></attribute>
        </attribute>
        <attribute name=\"realConst\">
          <attribute name=\"name\">rho</attribute>
          <attribute name=\"expr\"><attribute name=\"numValue\">
              %f
          </attribute></attribute>
        </attribute>
      </attribute>
    </attribute>
  </attribute>\n" r lambda rho;


  for i =1 to n do
    print_pl f ("RE_Queue"^(string_of_int i)) countid (if i=1 then 1 else 0);
  done;

  print_tr f "Arrive" countid "lambda";

  for i =1 to n do
    print_tr f ("Serve"^(string_of_int i)) countid "rho";
  done;

  for i =2 to n do
    print_pl f ("AQueue"^(string_of_int i)) countid r;
  done;

  for i =0 to n-1 do
    print_arc f countid (n+i) i 1;(*post*)
    print_arc f countid i (n+i+1) 1;(*pre*)
    if i>=1 then (
    print_arc f countid (2*n+i) (n+i) 1; (*pre*)
    print_arc f countid (n+i+1) (2*n+i) 1; (*post*)
    )
  done;
  Printf.fprintf f "</model>";
  close_out f;;


let rec gen_queue n =
  if n = 1 then "RE_Queue1"
  else (gen_queue (n-1))^"+RE_Queue"^(string_of_int n);;

let generate_marcie marciepath n lambda rho r n2 =
  let f = open_out marciepath in
  Printf.fprintf f "spn [Tandem%i]\n{\nconstants:
  int N = %i;
  int N2 =%i;
  double lambda = %f;
  double rho = %f;\n" n n n2 lambda rho;
  Printf.fprintf f "places:\n  RE_Queue1 = 1;
  AQueues = %i;\n" (n2-1);
  for i = 2 to n do
    Printf.fprintf f "  RE_Queue%i = 0;\n" i;
  done;
  Printf.fprintf f "transitions:\n  Arrive : : [AQueues -1] & [RE_Queue1 +1] : lambda;\n";
  for i = 1 to (n-1) do
    Printf.fprintf f "  Serve%i : : [RE_Queue%i -1] & [RE_Queue%i +1] : rho;\n" i i (i+1);
  done;
  Printf.fprintf f "  Serve%i : : [RE_Queue%i -1] & [AQueues+1] : rho;\n}\n" n n;
  close_out f;;
  
let generate_csl cslpath n n2 =
  let f = open_out cslpath in
  let queues = gen_queue n in
  (*Printf.fprintf f "const int n=%i;\n" n2;*)
  Printf.fprintf f "P=?[[ %s >0 ] U [ %s = %i ]]\n" queues queues n2;
  close_out f;;

let generate_lha lhapath n n2=
  let queues = gen_queue n in
  let f = open_out lhapath in
  Printf.fprintf f "VariablesList = {vc0};
LocationsList = {l0,l1,l2};
Probability=PROB;
LikelyhoodProb = AVG(Last(vc0));
InitialLocations = { l0 };
FinalLocations = {l1};
Locations = {
(l0,((%s)>0 & (%s)<%i));
(l1,(%s)=%i);
(l2,(%s)=0);
};
Edges = {
((l0,l0),ALL,#,#);
((l0,l1),ALL,#,{vc0=1});
((l0,l2),ALL,#,{vc0=0});
};" queues queues n2 queues n2 queues;
  close_out f;;

let generate_lumping_fun lumppath n =
  let f = open_out lumppath in
  Printf.fprintf f "#include \"markingImpl.hpp\"
void SPN::print_state(const vector<int> &vect){
}
bool SPN::precondition(const abstractMarking &Marking){return true;}

void SPN::lumpingFun(const abstractMarking &Marking,vector<int> &vect){\n";
  for i =1 to n do 
    Printf.fprintf f 
      "\tvect[%i] = Marking.P->_PL_RE_Queue%i;\n" (i-1) i;
  done;
  Printf.fprintf f
    "\tint reste =0;
    for (int i=vect.size()-1; i>0; i--) {
        if(vect[i]>r){
            reste += vect[i]-r ;
            vect[i]=r;
        } else if(vect[i]+reste>r){
            reste -= (r - vect[i]);
            vect[i]=r;
        } else {
            vect[i] += reste;
            reste =0;
        }
    }
    vect[0] += reste;
}";
  close_out f;;

#use "../testTeamCity.ml";;

let generate n n2 r = 
  Printf.printf "Generate n=%i n2=%i r=%i" n n2 r;
  print_newline ();
  generate_spn "tandem.grml" n 0.1 0.45 r;
  generate_marcie "tandem.andl" n 0.1 0.45 r n2;
  generate_csl "tandem.csl" n n2;
  generate_reduce_spn "tandemRE.grml" n 0.1 0.45 r;
  generate_lha "tandem.lha" n n2;
  generate_lumping_fun "lumpingfun.cpp" n;;

let simule n n2 r =
  generate n n2 r;
  Printf.printf "Simulate n=%i n2=%i r=%i" n n2 r;
  print_newline ();
  execSavedCosmos ~prefix:false ("ReduceModel","tandemRE.grml","tandem.lha"," --prism --prism-path /Applications/prism-4.0.2-osx64/bin/prism");
  execSavedCosmos ~prefix:false ("ImportantSampling","tandem.grml","tandem.lha"," -r --max-run 100000");;


(*
simule 1 50 5;;
simule 2 50 5;;
simule 3 50 5;;
simule 4 50 5;;
simule 5 50 5;;
simule 6 50 5;;
simule 7 50 5;;
simule 8 50 5;;
simule 9 50 5;;
simule 10 50 5;;
*)

assert (Array.length Sys.argv>3);;
let n = int_of_string Sys.argv.(1);;
let n2 = int_of_string Sys.argv.(2);;
let r = int_of_string Sys.argv.(3);;
assert(n>=1);;

generate n n2 r;;
