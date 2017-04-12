open Simulinkparser
open Printf
open PetriNet
open StochasticPetriNet
open Type

module OrderedBlocks =
  struct
    type t = Simulinkparser.block
    let compare x y = compare x.blockid y.blockid
end
module BlockSet = Set.Make(OrderedBlocks)

module OrderedLinks =
  struct
    type t = Simulinkparser.simulinkLink
    let compare x y = compare x y
end
module LinksSet = Set.Make(OrderedLinks)

let skInfinitesimalLatency = ["Integrator"];;
let skNoInputs = ["Constant"];;
let skConditional = ["Switch"];;

let topologicSort (lB,lL) =
  let e = ref (LinksSet.of_list lL) in
  let l = ref [] and s = ref BlockSet.empty in
    let c = Hashtbl.create (List.length lB) in
     let rec initiaC = function
       [] -> ()
       | t::q -> Hashtbl.add c t.blockid 0; initiaC q
     and countEdges = function
       [] -> ()
       | t::q -> Hashtbl.replace c t.toblock (1 + Hashtbl.find c t.toblock); countEdges q;
     and initiaS = function
       [] -> ()
       | t::q -> let incoming = Hashtbl.find c t.blockid in
                   if (incoming = 0) then s := BlockSet.add t !s;
                   initiaS q;
     and findblock id = function
       [] -> failwith "Un lien fait n'importe quoi"
       | t::q when t.blockid = id -> t
       | t::q -> findblock id q
     and processblock block =
       l := block::!l;
       s := BlockSet.remove block !s;
       let outgoingedges = ref (LinksSet.filter (fun x -> x.fromblock = block.blockid) !e) and
           incomingedges = ref (LinksSet.filter (fun x -> x.toblock = block.blockid) !e) and
           dealwithedgeout edge = begin
             e := LinksSet.remove edge !e;
             Hashtbl.replace c edge.toblock ( (Hashtbl.find c edge.toblock - 1) );
             if (Hashtbl.find c edge.toblock = 0) then
               if (not (List.exists (fun x -> x.blockid=edge.toblock) !l)) then
                 s := BlockSet.add (findblock edge.toblock lB) !s;
             edge
           end and 
           dealwithedgeinc edge = begin (* Nettoyage pour les blocs infinitésimaux/… *)
             e := LinksSet.remove edge !e;
             edge
           end in
             outgoingedges := LinksSet.map dealwithedgeout !outgoingedges;
             incomingedges := LinksSet.map dealwithedgeinc !incomingedges;
     and infinitesimalLatencies = function
       [] -> ()
       | t::q when List.exists (fun x -> x=t.blocktype) skInfinitesimalLatency -> processblock t; infinitesimalLatencies q;
       | t::q -> infinitesimalLatencies q;
     and noInputs = function
       [] -> ()
       | t::q when List.exists (fun x -> x=t.blocktype) skNoInputs -> processblock t; noInputs q;
       | t::q -> noInputs q;
     and findLatencies = function
       [] -> []
       | t::q when List.exists (fun (x,y) -> x="LATENCY") t.values -> (float_of_string (List.assoc "LATENCY" t.values),t)::(findLatencies q)
(*       | t::q when List.exists (fun (x,y) -> x="DelayLength") t.values -> (float_of_string (List.assoc "DelayLength" t.values),t)::(findLatencies q)
       | t::q when List.exists (fun (x,y) -> x="DelayTime") t.values -> (float_of_string (List.assoc "DelayTime" t.values),t)::(findLatencies q) *)
       | t::q when t.blocktype="UnitDelay" -> (1.0,t)::(findLatencies q)
       | t::q -> findLatencies q
     and processLatencied = function
       [] -> ()
       | (l,t)::q when l = 0.0 -> processLatencied q
       | (l,t)::q -> processblock t; processLatencied q
     in
       initiaC lB;
       countEdges lL;
       initiaS lB;
       noInputs lB;
       let latenciedBlocks = ref (findLatencies lB) in
         latenciedBlocks := List.sort (compare) !latenciedBlocks;
         processLatencied !latenciedBlocks;
         infinitesimalLatencies lB;
         while (not (BlockSet.is_empty !s)) do
           let vertex = BlockSet.choose !s in
             processblock vertex
         done;
         if (LinksSet.is_empty !e) then (List.rev !l, lL) else failwith "Cannot simulate this Simulink model"
;;

let rec findSrc (b,p) = function
  [] -> Printf.eprintf "[WARNING:] Couldn't find a source port linked to port %i of block %i" p b; (0,0)
  | l::q when l.toblock=b && l.toport=p -> (l.fromblock,l.fromport)
  | l::q -> findSrc (b,p) q;;

let rec getBlockById bid = function
  [] -> Printf.eprintf "[FATAL:] Couldn't find block number %i" bid; exit 0;
  | b::q when b.blockid=bid -> b
  | b::q -> getBlockById bid q;;

let bkwdGraph (lB,lL) b =
  let kB = ref [] and kL = ref [] in
    let addB = function
    | b when List.exists (fun x -> x=b) !kB -> false
    | b -> kB := b::!kB; true
    and addL = function
    | l when List.exists (fun x -> x=l) !kL -> false
    | l -> kL := l::!kL; true
    and noOutput = function _ -> ()
    in
      let rec auxBkwd = function
      | t when List.exists (fun x -> x=t.blocktype) skNoInputs -> noOutput(addB t)
      | t when List.exists (fun (x,y) -> x="LATENCY") t.values -> noOutput(addB t)
      | t when List.exists (fun x -> x=t.blocktype) skInfinitesimalLatency -> noOutput(addB t) 
      | t -> let isNew = addB t in if isNew then defileLinks t.blockid lL
      and defileLinks bid = function
      | [] -> ()
      | l::q when l.toblock=bid -> let isNew = addL l in if isNew then begin auxBkwd (getBlockById l.fromblock lB); defileLinks bid q end;
      | l::q -> defileLinks bid q
      in
        (* defileLinks b.blockid lL; *)
        auxBkwd b;
        topologicSort (!kB,!kL);;

let generateCode lS (lB,lL) =
  let skCpp = open_out "SKModel.cpp" and
      mkImp = open_out "markingImpl.hpp" and
      skHpp = open_out "SKModel.hpp" in

  let startTime = Simulinkparser.extfloat_of_string (List.assoc "StartTime" lS) and stopTime = Simulinkparser.extfloat_of_string (List.assoc "StopTime" lS) and fixedStep = Simulinkparser.extfloat_of_string (List.assoc "FixedStep" lS) in
    let baseStep = match fixedStep with
    | Auto -> begin match stopTime with
      | Auto -> failwith "stopTime = auto : pas de sens"
      | Infty -> failwith "stopTime = infty et fixedStep = auto ? Ah, le cas est arrivé. Il faut une valeur par défaut."
      | Finite stop -> begin match startTime with
        | Finite start -> (stop -. start) /. 50.
        | _ -> failwith "startTime a une tête étrange." end; end;
    | Infty -> failwith "fixedStep = infty : cela n'a pas de sens"
    | Finite step -> step
    in

  (* Impression des headers *)
  Printf.fprintf mkImp "#ifndef _MarkingImpl_HPP\n#define _MarkingImpl_HPP\n";
  Printf.fprintf mkImp "using namespace std;\n#include <string.h>\n";
  Printf.fprintf mkImp "#include \"marking.hpp\"\n#include \"markingTemplate.hpp\"\n";
  Printf.fprintf skCpp "#include \"marking.hpp\"\n#include \"markingImpl.hpp\"\n";
  Printf.fprintf skCpp "#include \"SKTime.hpp\"\n";
  Printf.fprintf skHpp "#include \"SKTime.hpp\"\n";
  Printf.fprintf mkImp "#include \"SKTime.hpp\"\n";
  (*  Définition deSKTransition *)
  Printf.fprintf skHpp "class SKTransition {\n";
  Printf.fprintf skHpp "public:\n";
  Printf.fprintf skHpp "\tsize_t Id;\n";
  Printf.fprintf skHpp "\tstd::string label;\n";
  Printf.fprintf skHpp "\tDistributionType DistTypeIndex;\n";
  Printf.fprintf skHpp "\n\tstd::array<abstractBinding, 1> bindingList;\n";
  Printf.fprintf skHpp "};\n";
  (* abstractBindingImpl *)
  Printf.fprintf mkImp "\nclass abstractBindingImpl {\npublic:\n};\n";
  (* abstractBindingIteratorImpl *)
  Printf.fprintf mkImp "\nclass abstractBindingIteratorImpl {\npublic:\n";
  Printf.fprintf mkImp "\tvoid reset(abstractMarkingImpl& m){};\n";
  Printf.fprintf mkImp "\tbool next(size_t& t, abstractMarkingImpl& m){ return false; };\n";
  Printf.fprintf mkImp "\tsize_t getIndex(){ return 0; };\n";
  Printf.fprintf mkImp "\tabstractBinding getBinding(){ return abstractBinding(); };\n};\n";
  (* abstractMarking def dans le Cpp *)
  Printf.fprintf skCpp "\nabstractMarking::abstractMarking() {\n";
  Printf.fprintf skCpp "\tP = new abstractMarkingImpl;\n";
  Printf.fprintf skCpp "\tresetToInitMarking();\n";
  Printf.fprintf skCpp "}\n";

  Printf.fprintf skCpp "\nabstractMarking::abstractMarking(const abstractMarking& m) {\n";
  Printf.fprintf skCpp "\tP = new abstractMarkingImpl;\n";
  Printf.fprintf skCpp "\t*this = m;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "\nabstractMarking& abstractMarking::operator = (const abstractMarking& m) {\n";
  Printf.fprintf skCpp "\t*P = *(m.P);\n";
  Printf.fprintf skCpp "\treturn *this;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "\nabstractMarking::~abstractMarking() {\n";
  Printf.fprintf skCpp "\tdelete(P);\n";
  Printf.fprintf skCpp "}\n";

  Printf.fprintf skCpp "\nvoid abstractMarking::swap(abstractMarking& m) {\n";
  Printf.fprintf skCpp "\tabstractMarkingImpl* tmp = m.P;\n";
  Printf.fprintf skCpp "\tm.P = P;\n";
  Printf.fprintf skCpp "\tP = tmp;\n";
  Printf.fprintf skCpp "}\n";

  (* Création des chaînes de caractères pour les fonctions d'impression *)
  let printHeaderTmp = Buffer.create 16 in
  let printTmp = Buffer.create 16 in
  let printSedCmdTmp = Buffer.create 16 in
  let generateNewEntries = Buffer.create 16 in
  let generateVectors = Buffer.create 16 in

  (* abstractMarkingImpl + SKMarking.P->*)
  Printf.fprintf skHpp "class SKMarking {\n";
  Printf.fprintf skHpp "public:\n";
  Printf.fprintf skHpp "\tvoid printHeader(ostream&);\n";
  Printf.fprintf skHpp "\tvoid print(ostream&, float);\n";
  Printf.fprintf skHpp "\tvoid printSedCmd(ostream&);\n";
  Printf.fprintf skHpp "\n";
  
  Printf.fprintf mkImp "\nclass abstractMarkingImpl {\npublic:";
  Printf.fprintf mkImp "\n\tsize_t lastPrintEntry;";
  Printf.fprintf mkImp "\n\tsize_t lastEntry;";
  Printf.fprintf mkImp "\n\tsize_t totalEntries;";
  Printf.fprintf mkImp "\n\tsize_t countDown;";
  Printf.fprintf mkImp "\n\tSKTime currentLookup;";
  Printf.fprintf mkImp "\n\tvector<SKTime> _TIME;";
  Printf.fprintf skHpp "\n\tvector<SKTime> _TIME;";
  let outputs_parse_regexp = Str.regexp "\\[\\([0-9]+\\), \\([0-9]+\\)\\]" in
  let rec listAllParams = function
    [] -> ()
    | (a,b)::q -> Printf.eprintf "%s => %s\n" a b; listAllParams q
  in
  let rec genSignalNames = function
    [] -> ()
    | t::q -> begin
      Printf.fprintf mkImp "\n\t// Block %i - type %s (named %s) :" t.blockid t.blocktype t.name;
      try
        let numOfPorts = List.assoc "Ports" t.values in
          try let didmatch = Str.string_match outputs_parse_regexp numOfPorts 0 in
            if didmatch then begin
              try let nb = int_of_string@@ Str.matched_group 2 numOfPorts in
                for i = 1 to nb do
                  Printf.fprintf mkImp "\n\tvector<double> _BLOCK%i_OUT%i;" t.blockid i;
                  Printf.fprintf skHpp "\n\tvector<double> _BLOCK%i_OUT%i;" t.blockid i;
                  Printf.bprintf printHeaderTmp "\n\ts << setw(5) << \"B%iO%i\";" t.blockid i;
                  Printf.bprintf printTmp "\n\ts << setw(1) << P->_BLOCK%i_OUT%i[(P->lastPrintEntry)] << \" \";" t.blockid i;
                  Printf.bprintf printSedCmdTmp "\n\ts << \"-e 's/\\\\$B%iO%i\\\\$/\" << P->_BLOCK%i_OUT%i[(P->lastPrintEntry)] << \"/g' \";" t.blockid i t.blockid i;
                  Printf.bprintf generateNewEntries "\n\tMarking.P->_BLOCK%i_OUT%i.push_back(0.0);" t.blockid i;
                  Printf.bprintf generateVectors "\n\tP->_BLOCK%i_OUT%i = {0.0,0.0,0.0,0.0,0.0};" t.blockid i;
                done
              with Not_found ->  begin Printf.eprintf "[WARNING:] Wrong port format for block %i (type %s) : %s\n" t.blockid t.blocktype numOfPorts; end;
             end
             else Printf.fprintf mkImp "No Output."
         with Not_found -> begin Printf.eprintf "[WARNING:] Wrong port format for block %i (type %s) : %s\n" t.blockid t.blocktype numOfPorts; end;
       with Not_found -> begin Printf.eprintf "[WARNING:] Couldn't find port numbers for block %i (type %s)\n" t.blockid t.blocktype; listAllParams t.values end;
      end; genSignalNames q;
  in genSignalNames lB;
  let rec genCBStateNames = function
    [] -> ()
    | b::q when List.exists (fun x -> x=b.blocktype) skConditional -> begin
      Printf.fprintf mkImp "\n\tvector<size_t> _STATE%i" b.blockid;
      Printf.fprintf skHpp "\n\tvector<size_t> _STATE%i" b.blockid;
      Printf.bprintf generateNewEntries "\n\tMarking.P->_STATE%i.push_back(0);" b.blockid;
      Printf.bprintf generateVectors "\n\tMarking.P->_STATE%i = {0,0,0,0,0};" b.blockid;
      end; genCBStateNames q;
    | b::q -> genCBStateNames q
  in genCBStateNames lB; (* Conditional Block StateNames *)
  Printf.fprintf mkImp "\n};\n";
  Printf.fprintf skHpp "\n};\n";
  (* Footers *)
  Printf.fprintf mkImp "\n#endif";
  (* SKModel *)
  Printf.fprintf skHpp "template <class EQT>\nclass SKModel {\n";
  Printf.fprintf skHpp "public:\n";
  Printf.fprintf skHpp "\tabstractMarking Marking;\n";
  Printf.fprintf skHpp "\tstd::vector<SKTransition> Transition;\n";
  Printf.fprintf skHpp "\n\tsize_t lastTransition;\n";
  Printf.fprintf skHpp "\tsize_t lastTransitionTime;\n";
  Printf.fprintf skHpp "\n\tSKModel();\n";
  Printf.fprintf skHpp "\n\tvoid reset();\n";
  Printf.fprintf skHpp "\n\tvoid initialEventsQueue(EQT&, timeGen&);";
  Printf.fprintf skHpp "\n\tvoid generateEvent(double ctime,Event& E,size_t Id,timeGen& TG);";
  Printf.fprintf skHpp "\n\tvoid fire(size_t, const abstractBinding&, double);";
  Printf.fprintf skHpp "\n\tvoid update(double, size_t, const abstractBinding&, EQT&, timeGen&);";
  Printf.fprintf skHpp "\n\nprivate:\n";
  Printf.fprintf skHpp "\tvoid initialiseIntegrators(int);\n";
  Printf.fprintf skHpp "\tSKTime estimateIntegrators(int,SKTime);\n";
  Printf.fprintf skHpp "\tvoid executeIntegrators(int);\n";
  Printf.fprintf skHpp "\tint findLatencyIndex(double);\n";
  Printf.fprintf skHpp "\tdouble linearInterpolation(SKTime, SKTime, double, double, SKTime);";
  let rec genBlockFunNames = function
    [] -> ()
    | t::q when t.blocktype = "Integrator" -> genBlockFunNames q
    | t::q -> Printf.fprintf skHpp "\n\tvoid executeBlock%i(int);" t.blockid; genBlockFunNames q
  in genBlockFunNames lB;
  Printf.fprintf skHpp "\n};\n";

  (* Printing functions *)
  Printf.fprintf skCpp "\nvoid abstractMarking::printHeader(ostream& s) const{";
  Buffer.output_buffer skCpp printHeaderTmp;
  Printf.fprintf skCpp "\n}\n";

  Printf.fprintf skCpp "\nvoid abstractMarking::print(ostream& s,double eTime) const{";
  Buffer.output_buffer skCpp printTmp;
  Printf.fprintf skCpp "\n}\n";

  Printf.fprintf skCpp "\nvoid abstractMarking::printSedCmd(ostream& s) const{";
  Buffer.output_buffer skCpp printSedCmdTmp;
  Printf.fprintf skCpp "\n}\n";

  (* Reset abstractMarking *)
  Printf.fprintf skCpp "\nvoid abstractMarking::resetToInitMarking() {\n";
  Printf.fprintf skCpp "\tP->lastEntry = 0;\n";
  Printf.fprintf skCpp "\tP->lastPrintEntry = 0;\n";
  Printf.fprintf skCpp "\tP->countDown = 0;\n";
  Printf.fprintf skCpp "\tP->currentLookup = 0.0;\n";
  Printf.fprintf skCpp "\tP->_TIME = {0.0,0.0,0.0,0.0,0.0};";
  Buffer.output_buffer skCpp generateVectors;
  Printf.fprintf skCpp "\n}\n";

  (* Commandes liées à l'abstractBinding *)
  Printf.fprintf skCpp "\nbool abstractBinding::next() {\n";
  Printf.fprintf skCpp "\tidcount++;\n";
  Printf.fprintf skCpp "\treturn false;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "\nabstractBinding::abstractBinding() {\n";
  Printf.fprintf skCpp "\tidcount=0;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "\nabstractBinding::abstractBinding(const abstractBinding& m) {\n";
  Printf.fprintf skCpp "\tidcount=m.idcount;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "abstractBinding::~abstractBinding() { }\n";
  Printf.fprintf skCpp "abstractBinding& abstractBinding::operator = (const abstractBinding& m) {\n";
  Printf.fprintf skCpp "\tidcount = m.idcount;\n";
  Printf.fprintf skCpp "\treturn *this;\n";
  Printf.fprintf skCpp "}\n";
  Printf.fprintf skCpp "void abstractBinding::print() const{ }\n";
  Printf.fprintf skCpp "int abstractBinding::id() const { return idcount; }\n";
  Printf.fprintf skCpp "int abstractBinding::idTotal() const { return 0; }\n";

  Printf.fprintf skCpp "\ntemplate<class EQT>\nSKModel<EQT>::SKModel() {\n";
  Printf.fprintf skCpp "\tTransition.push_back(SKTransition());\n";
  Printf.fprintf skCpp "}\n";

  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::initialEventsQueue(EQT& EQ, timeGen& tg) {\n";
  Printf.fprintf skCpp "\tEvent E;\n";
  Printf.fprintf skCpp "\tgenerateEvent(0.0, E, 0, tg);\n";
  Printf.fprintf skCpp "\tEQ.insert(E);\n";
  Printf.fprintf skCpp "}\n";

  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::generateEvent(double ctime, Event& E,size_t Id, timeGen& tg) {\n";
  Printf.fprintf skCpp "\tdouble t = ctime;\n";
  Printf.fprintf skCpp "\n\tE.transition = Id;\n";
  Printf.fprintf skCpp "\tE.time = t;\n";
  Printf.fprintf skCpp "\tE.priority = 1;\n";
  Printf.fprintf skCpp "\tE.weight = 1;\n";
  Printf.fprintf skCpp "};\n";

  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::reset() {\n";
  Printf.fprintf skCpp "\tMarking.resetToInitMarking();\n";
  Printf.fprintf skCpp "};\n";

  (* Gestion des latences *)
  Printf.fprintf skCpp "\ntemplate <class EQT>\nint SKModel<EQT>::findLatencyIndex(double latency) {\n";
  Printf.fprintf skCpp "\tSKTime currTime = Marking.P->currentLookup;\n";
  Printf.fprintf skCpp "\twhile (Marking.P->countDown > 0 && Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) {\n";
  Printf.fprintf skCpp "\t\tMarking.P->countDown--;\n";
  Printf.fprintf skCpp "\t}\n";
  Printf.fprintf skCpp "\tif (Marking.P->_TIME[Marking.P->countDown] > (currTime - latency)) { return -1;\n";
  Printf.fprintf skCpp "\t} else { return Marking.P->countDown; }\n";
  Printf.fprintf skCpp "}\n";

  (* Initialisation des blocs Intégrateurs *)
  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::initialiseIntegrators(int idx) {";
  let rec genInitIntegrators = function
    [] -> ()
    | b::q when b.blocktype="Integrator" -> let cstValue = float_of_string (List.assoc "InitialCondition" b.values) in
        Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[Marking.P->lastEntry] = %f;" b.blockid 1 cstValue; genInitIntegrators q;
    | b::q -> genInitIntegrators q
  in genInitIntegrators lB;
  Printf.fprintf skCpp "\n};\n";

  (* Implémentation des intégrales : Euler *) (* INTEGRATORS *)
  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::executeIntegrators(int idx) {\n";
  Printf.fprintf skCpp "\testimateIntegrators(idx,(Marking.P->_TIME[idx] - Marking.P->_TIME[idx-1]).getDouble());\n";
  Printf.fprintf skCpp "};\n";
  Printf.fprintf skCpp "\ntemplate<class EQT>\nSKTime SKModel<EQT>::estimateIntegrators(int idx,SKTime stepSK) {\n";
  Printf.fprintf skCpp "\tdouble step = stepSK.getDouble();\n";
  Printf.fprintf skCpp "\tint idxtampon = Marking.P->lastEntry+1;\n";
  Printf.fprintf skCpp "\tSKTime t0 = Marking.P->_TIME[idx-1];\n";
  Printf.fprintf skCpp "\tMarking.P->_TIME[idxtampon+0] = Marking.P->_TIME[idx-1];\n";
  let rec genEulerIntegrators = function
    [] -> Printf.fprintf skCpp "\treturn stepSK;\n";
    | b::q when b.blocktype="Integrator" -> let (ba,ia) = findSrc (b.blockid,1) lL in
      Printf.fprintf skCpp "\tMarking.P->_BLOCK%i_OUT%i[idx] = Marking.P->_BLOCK%i_OUT%i[idx-1] + step * Marking.P->_BLOCK%i_OUT%i[idx];\n" b.blockid 1 b.blockid 1 ba ia;
      genEulerIntegrators q;
    | b::q -> genEulerIntegrators q
  in
  let rec genRK4Integrators step lI = function
    | [] when step<3 -> genRK4Entries step lI; Printf.fprintf skCpp "\tSKTime t%i = " (step+1);
      begin match step with
      | 0 -> Printf.fprintf skCpp "t0.getDouble() * step/2.;";
      | 1 -> Printf.fprintf skCpp "t0.getDouble() * step/2.;";
      | 2 -> Printf.fprintf skCpp "t0.getDouble() * step;"
      | _ -> () end;
      Printf.fprintf skCpp "\n\tMarking.P->currentLookup = t%i;" (step+1);
      Printf.fprintf skCpp "\n\tMarking.P->countDown = Marking.P->lastEntry;";
      Printf.fprintf skCpp "\n\tMarking.P->_TIME[idxtampon+%i] = t%i;\n" (step+1) (step+1);
      genRK4Integrators (step+1) [] lB
    | [] when step=3 -> genRK4Entries step lI; genRK4Values lI;
    | [] -> () (* Terminé *)
    | b::q when b.blocktype="Integrator" -> begin
      let (ba,ia) = findSrc (b.blockid,1) lL in
      Printf.fprintf skCpp "\tdouble k%i_b%i = " step b.blockid;
      begin match step with
      0 -> Printf.fprintf skCpp "Marking.P->_BLOCK%i_OUT%i[idx-1];" b.blockid 1; (* ba ia; *)
      | step -> Printf.fprintf skCpp "Marking.P->_BLOCK%i_OUT%i[idxtampon+%i];" ba ia (step-1);
      end; Printf.fprintf skCpp "\n\tdouble y%i_b%i = " step b.blockid;
      begin match step with
      0 -> Printf.fprintf skCpp "k%i_b%i;" step b.blockid
      | 1 -> Printf.fprintf skCpp "y0_b%i + step/2. * k1_b%i;" b.blockid b.blockid
      | 2 -> Printf.fprintf skCpp "y0_b%i + step/2. * k2_b%i;" b.blockid b.blockid
      | 3 -> Printf.fprintf skCpp "y0_b%i + step * k3_b%i;" b.blockid b.blockid
      | _ -> () (* ToDo *)
      end; Printf.fprintf skCpp "\n"; genRK4Integrators step (b::lI) q
      end
    | b::q -> genRK4Integrators step lI q
  and genRK4Entries step = function
    | [] -> ()
    | b::q -> let (ba,ia) = findSrc (b.blockid,1) lL in
                let inb = getBlockById ba lB in
                  let (bB,bL) = bkwdGraph (lB,lL) inb in genRK4Bkwd step bB; genRK4Entries step q;
  and genRK4Bkwd step = function
    | [] -> ()
    | b::q when b.blocktype="Integrator" -> Printf.fprintf skCpp "\tMarking.P->_BLOCK%i_OUT%i[idxtampon+%i] = y%i_b%i;\n" b.blockid 1 step step b.blockid; genRK4Bkwd step q;
    | b::q -> Printf.fprintf skCpp "\texecuteBlock%i(idxtampon+%i);\n" b.blockid step; genRK4Bkwd step q;
  and genRK4Values = function
    | [] -> Printf.fprintf skCpp "\treturn stepSK;\n";
    | b::q -> begin
      let (ba,ia) = findSrc (b.blockid,1) lL in
      Printf.fprintf skCpp "\tdouble k4_b%i = Marking.P->_BLOCK%i_OUT%i[idxtampon+3];\n" b.blockid ba ia;
      Printf.fprintf skCpp "\tMarking.P->_BLOCK%i_OUT%i[idx] = y0_b%i + step/6. * (k1_b%i + 2.*k2_b%i + 2.*k3_b%i + k4_b%i);\n" b.blockid 1 b.blockid b.blockid b.blockid b.blockid b.blockid;
      end; genRK4Values q;
  in genRK4Integrators 0 [] lB;

  (* to avoid ocaml errors : *)
  Printf.fprintf skCpp "/* \n";
  genEulerIntegrators []; (* genRK4Integrators 0 [] []; *)
  Printf.fprintf skCpp "*/ \n";
  (* end *)
  Printf.fprintf skCpp "};\n";

  (* Fonctions nécessaires pour l'exécution des blocs *)
  Printf.fprintf skCpp "\ntemplate<class EQT>\ndouble SKModel<EQT>::linearInterpolation(SKTime sktA, SKTime sktB, double vA, double vB, SKTime time) {";
  Printf.fprintf skCpp "\n\tdouble tA = sktA.getDouble(); double tB = sktB.getDouble(); double t = time.getDouble();";
  Printf.fprintf skCpp "\n\treturn (vB - vA)/(tB - tA) * (t - tA) + vA;";
  Printf.fprintf skCpp "\n};\n";

  (* Génération des fonctions d'éxécution des blocs simples *)
  let rec genBlockFunctions = function
    [] -> ()
    | b::q when b.blocktype="Integrator" -> genBlockFunctions q
    | b::q when b.blocktype="Display" -> genBlockFunctions q
    | b::q -> begin
        Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::executeBlock%i(int idx) {" b.blockid;
        begin match b.blocktype with
        | "Sum" -> let currInpt = ref 0 and signs = List.assoc "Inputs" b.values in
                   let signSize = String.length signs in
                   Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[idx] =" b.blockid 1;
                   let rec buildSum = function
                     | i when i > signSize -> ()
                     | i when (i = signSize) -> ()
                     | i -> begin match signs.[i] with
                            | '+' -> currInpt:=!currInpt+1; let (ba,ia)=findSrc(b.blockid,!currInpt) lL in
                                     Printf.fprintf skCpp " + Marking.P->_BLOCK%i_OUT%i[idx]" ba ia
                            | '-' -> currInpt:=!currInpt+1; let (ba,ia)=findSrc(b.blockid,!currInpt) lL in
                                     Printf.fprintf skCpp " - Marking.P->_BLOCK%i_OUT%i[idx]" ba ia
                            | _ -> ()
                            end; buildSum (i+1)
                   in buildSum 0;
                   Printf.fprintf skCpp ";"
(* let (ba,ia) = findSrc (b.blockid,1) lL and (bb,ib) = findSrc (b.blockid,2) lL in
            Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[idx] = Marking.P->_BLOCK%i_OUT%i[idx] + Marking.P->_BLOCK%i_OUT%i[idx];" b.blockid 1 ba ia bb ib; *)
        | "Constant" -> let cstValue = float_of_string (List.assoc "Value" b.values) in
            Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[idx] = %f;" b.blockid 1 cstValue;
        | "Delay" -> genLatencyFunction b
        | "UnitDelay" -> genLatencyFunction b
        | "Scope" -> () (* do nothing *)
        | "Sin" -> begin
          let amplitude = float_of_string (List.assoc "Amplitude" b.values)
          and frequency = float_of_string (List.assoc "Frequency" b.values)
          and phase = float_of_string (List.assoc "Phase" b.values)
          and bias = float_of_string (List.assoc "Bias" b.values) in
          Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[idx] = %f * sin(%f * Marking.P->_TIME[idx].getDouble() + %f) + %f;" b.blockid 1 amplitude frequency phase bias;
          end
        | "TransportDelay" -> begin
          let latency = float_of_string (List.assoc "LATENCY" b.values)
          and (ba,ia) = findSrc(b.blockid,1) lL
          and initValue = float_of_string (List.assoc "InitialOutput" b.values) in
          Printf.fprintf skCpp "\n\tint latidx = findLatencyIndex(%f);" latency;
          Printf.fprintf skCpp "\n\tif (latidx > -1) {";
          Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = linearInterpolation( Marking.P->_TIME[latidx], Marking.P->_TIME[latidx+1], Marking.P->_BLOCK%i_OUT%i[latidx], Marking.P->_BLOCK%i_OUT%i[latidx+1], Marking.P->_TIME[idx] - %f);" b.blockid 1 ba ia ba ia latency;
          Printf.fprintf skCpp "\n\t} else {";
          Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = %f;" b.blockid 1 initValue;
          Printf.fprintf skCpp "\n\t}";
          end
        | "Gain" -> let gain = float_of_string (List.assoc "Gain" b.values) and (ba,ia) = findSrc(b.blockid,1) lL in
          Printf.fprintf skCpp "\n\tMarking.P->_BLOCK%i_OUT%i[idx] = %f * Marking.P->_BLOCK%i_OUT%i[idx];" b.blockid 1 gain ba ia;
        | "Switch" -> let (ba,ia) = findSrc(b.blockid,1) lL and (bb,ib) = findSrc(b.blockid,2) lL in
          Printf.fprintf skCpp "\n\tMarking.P->_STATE%i[idx] = Marking.P->_STATE%i[Marking.P->lastEntry];" b.blockid b.blockid;
          Printf.fprintf skCpp "\n\tif (Marking.P->_STATE%i[idx] == 0) {" b.blockid;
          Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = Marking.P->_BLOCK%i_OUT%i[idx];" b.blockid 1 bb ib;
          Printf.fprintf skCpp "\n\t} else {";
          Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = Marking.P->_BLOCK%i_OUT%i[idx];" b.blockid 1 ba ia;
          Printf.fprintf skCpp "\n\t}"
        | _ -> begin
          Printf.fprintf skCpp "\nfprintf(stderr,\"Could not execute block %i of type %s !\");" b.blockid b.blocktype;
          Printf.eprintf "[WARNING:] Found unimplemented block %s.\n" b.blocktype;
          end
        end;
        Printf.fprintf skCpp "\n};\n"; genBlockFunctions q
      end
  and genLatencyFunction b =
    let latency = float_of_string (List.assoc "LATENCY" b.values) and (ba,ia) = findSrc (b.blockid,1) lL and initValue = float_of_string (List.assoc "InitialCondition" b.values) in
      Printf.fprintf skCpp "\n\tint latidx = findLatencyIndex(%f);" latency;
      Printf.fprintf skCpp "\n\tif (latidx > -1) {";
      Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = Marking.P->_BLOCK%i_OUT%i[latidx];" b.blockid 1 ba ia;
      Printf.fprintf skCpp "\n\t} else {";
      Printf.fprintf skCpp "\n\t\tMarking.P->_BLOCK%i_OUT%i[idx] = %f;" b.blockid 1 initValue;
      Printf.fprintf skCpp "\n\t}";
  in genBlockFunctions lB;

  (* Génération de la fonction fire *)
  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::fire(size_t tr,const abstractBinding&, double ctime) {\n";
  Printf.fprintf skCpp "\tMarking.P->countDown = Marking.P->lastEntry;\n";
  Printf.fprintf skCpp "\tMarking.P->lastPrintEntry = Marking.P->lastEntry;\n";
  Printf.fprintf skCpp "\tMarking.P->_TIME[Marking.P->lastEntry] = ctime;\n";
  Printf.fprintf skCpp "\tMarking.P->currentLookup = Marking.P->_TIME[Marking.P->lastEntry];";
  let rec genSignalChanges tabs currMode = function (* Génère les lignes de code mettant à jour les valeurs des blocs; currMode=1 s'il faut s'occuper de calculer le nouveau step *)
    [] -> ()
    | b::q when b.blocktype="Display" -> genSignalChanges tabs currMode q
    | b::q when b.blocktype="Integrator" -> 
       begin match currMode with
       0 -> begin
           Printf.fprintf skCpp "\n%sif (Marking.P->lastEntry==0) { initialiseIntegrators(0); }" tabs; 
           Printf.fprintf skCpp "\n%selse { executeIntegrators(Marking.P->lastEntry); }" tabs;
         end; genSignalChanges tabs 2 q;
       | 1 -> Printf.fprintf skCpp "\n%sstep = estimateIntegrators(Marking.P->lastEntry,step);" tabs; genSignalChanges tabs 3 q;
       | _ -> genSignalChanges tabs currMode q;
       end;
    | b::q when List.exists (fun x -> x=b.blocktype) skConditional ->
      begin match currMode with
      | 0 -> Printf.fprintf skCpp "\n%scheckState%i(Marking.P->lastEntry);\n%sexecuteBlock%i(Marking.P->lastEntry);" tabs b.blockid tabs b.blockid;
      | 2 -> Printf.fprintf skCpp "\n%scheckState%i(Marking.P->lastEntry);\n%sexecuteBlock%i(Marking.P->lastEntry);" tabs b.blockid tabs b.blockid;
      | 1 -> Printf.fprintf skCpp "\n%sfindStateChange%i();" tabs b.blockid;
      | 3 -> Printf.fprintf skCpp "\n%sfindStateChange%i();" tabs b.blockid;
      | _ -> ()
      end; genSignalChanges tabs currMode q
    | b::q -> Printf.fprintf skCpp "\n%sexecuteBlock%i(Marking.P->lastEntry);" tabs b.blockid; genSignalChanges tabs currMode q
  in genSignalChanges "\t" 0 lB;
  Printf.fprintf skCpp "\n};\n";

  (* Mise à jour de la queue d'évènements *)
  let endTcond = match stopTime with
  | Infty -> "false"
  | Auto -> "false"
  | Finite value -> "t < "^(string_of_float value) and 
  endTvalue = match stopTime with 
  | Finite value -> string_of_float value
  | _ -> "NaN" in

  Printf.fprintf skCpp "\ntemplate<class EQT>\nvoid SKModel<EQT>::update(double ctime, size_t tr, const abstractBinding& b, EQT &EQ, timeGen &TG) {\n";
  Printf.fprintf skCpp "\tEQ.remove(tr, b.id());\n";
  Printf.fprintf skCpp "\tMarking.P->lastEntry = Marking.P->lastEntry + 1;\n";
  Printf.fprintf skCpp "\tMarking.P->_TIME.push_back(0.0);";
  Buffer.output_buffer skCpp generateNewEntries;
  Printf.fprintf skCpp "\n\tSKTime t = ctime;\n";
  Printf.fprintf skCpp "\tSKTime step = %f;\n" baseStep;
  Printf.fprintf skCpp "\tSKTime oldStep = 0.0;\n";
  Printf.fprintf skCpp "\tif (%s) {\n" endTcond;
  Printf.fprintf skCpp "\t\tEvent E;\n";
  Printf.fprintf skCpp "\t\twhile (oldStep != step) {\n";
  Printf.fprintf skCpp "\t\t\toldStep = step;\n";
  Printf.fprintf skCpp "\t\t\tt = step + ctime;\n";
  Printf.fprintf skCpp "\t\t\tif (%s) {" endTcond;
  Printf.fprintf skCpp "\n\t\t\t\tMarking.P->countDown = Marking.P->lastEntry;";
  Printf.fprintf skCpp "\n\t\t\t\tMarking.P->_TIME[Marking.P->lastEntry] = t;";
  genSignalChanges "\t\t\t\t" 1 lB;
  Printf.fprintf skCpp "\n\t\t\t} else {\n";
  Printf.fprintf skCpp "\t\t\t\tstep = %s - ctime;\n" endTvalue;
  Printf.fprintf skCpp "\n\t\t\t}\n";
  Printf.fprintf skCpp "\t\t}\n";
  Printf.fprintf skCpp "\tgenerateEvent(t.getDouble(), E, 0, TG);\n";
  Printf.fprintf skCpp "\tEQ.insert(E);\n";
  Printf.fprintf skCpp "\t} else { EQ.reset(); }\n";
  Printf.fprintf skCpp "};\n";

  (* Dernière ligne : *)
  Printf.fprintf skCpp "template class SKModel<EventsQueue<std::vector<SKTransition>>>;\n";
(lB,lL);;

let generateGSPN (lB, lL) =
  let net = Net.create () in
  net.Net.def <- Some ({ intconst=[]; floatconst=[]; clock=[]; printer= (fun out () ->
      output_string out "\t<attribute name=\"externalMainFile\">main.cpp</attribute>")});
  let outputs_parse_regexp = Str.regexp "\\[\\([0-9]+\\), \\([0-9]+\\)\\]" in
    let rec generatePlaces = function
      [] -> ()
      | t::q -> begin
        try
          let numOfPorts = List.assoc "Ports" t.values in
            try let didmatch = Str.string_match outputs_parse_regexp numOfPorts 0 in
              if didmatch then begin
                try let nb = int_of_string@@ Str.matched_group 2 numOfPorts in
                  for i = 1 to nb do
                    Data.add (("B"^(string_of_int t.blockid)^"O"^(string_of_int i)),(Int 0, Some (Int 0))) net.Net.place;
                  done
                 with Not_found -> begin Printf.eprintf "[WARNING:] Wrong port format for block %i (type %s) : %s\n" t.blockid t.blocktype numOfPorts; end
                end
            with Not_found -> begin Printf.eprintf "[WARNING:] Wrong port format for block %i (type %s) : %s\n" t.blockid t.blocktype numOfPorts; end
         with Not_found -> begin Printf.eprintf "[WARNING:] Couldn't find port numbers for block %i (type %s)\n" t.blockid t.blocktype; end
      end; generatePlaces q;
    in generatePlaces lB;
    Data.add ("SimulinkTransition", (Imm, Float 1.0, Float 1.0)) net.Net.transition;
    StochPTPrinter.print_spt ("SKModel.grml") net;
(lB,lL);;

let testOutput (lB,lL) = Simulinkparser.printLaTeX stdout (lB,lL);;
