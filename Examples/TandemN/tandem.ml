
let n = int_of_string Sys.argv.(1);;

assert(n>=1);;

let f = open_out "tandem.grml";;

let lambda = 0.1;;
let rho = 0.45;;

let countid = ref 0;;

Printf.fprintf f "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<model formalismUrl=\"http://formalisms.cosyverif.org/sptgd-net.fml\" xmlns=\"http://cosyverif.org/ns/model\">
  <attribute name=\"declaration\"><attribute name=\"constants\">
      <attribute name=\"intConsts\">
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
  </attribute>\n" lambda rho;;

for i =1 to n do
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"place\">
    <attribute name=\"name\">Queue%i</attribute>
    <attribute name=\"marking\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        0
      </attribute></attribute>
    </attribute>
  </node>\n" !countid i;
  incr countid;
done;;

Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">Arrive</attribute>
    <attribute name=\"distribution\">
      <attribute name=\"type\">
        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"name\">
          lambda
        </attribute></attribute>
      </attribute>
    </attribute>
  </node>\n" !countid;;
incr countid;;

for i =1 to n do
  Printf.fprintf f "  <node id=\"%i\" nodeType=\"transition\">
    <attribute name=\"name\">Serve%i</attribute>
    <attribute name=\"distribution\">
      <attribute name=\"type\">
        EXPONENTIAL
      </attribute>
      <attribute name=\"param\">
        <attribute name=\"number\">0</attribute>
        <attribute name=\"expr\"><attribute name=\"name\">
          rho
        </attribute></attribute>
      </attribute>
    </attribute>
  </node>\n" !countid i; 
  incr countid;
done;;

for i =0 to n-1 do
  Printf.fprintf f "<arc id=\"%i\" arcType=\"arc\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        1
      </attribute></attribute>
    </attribute>
  </arc>\n" !countid (n+i) i; 
  incr countid;
done;;

for i =0 to n-1 do
  Printf.fprintf f "<arc id=\"%i\" arcType=\"arc\" source=\"%i\" target=\"%i\">
    <attribute name=\"valuation\">
      <attribute name=\"expr\"><attribute name=\"numValue\">
        1
      </attribute></attribute>
    </attribute>
  </arc>\n" !countid i (n+i+1); 
  incr countid;
done;;


Printf.fprintf f "</model>";;
