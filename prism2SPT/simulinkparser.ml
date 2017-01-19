open Xml
open Type
open Lexing

type block = { blocktype: string; blockid: string; name: string; values: (string * string) list }
type blockDefault = (string * (string * string) list) (* C'est blocktype et values seulement *)
type blockPort = int * int
type simulinkLink = { fromblock: int; fromport: int; toblock: int; toport: int }
type simulinkModel = block list * blockDefault list * simulinkLink list
type simulinkPModel = block list * simulinkLink list

let rec printValues f = function
	(c,v)::q -> Printf.fprintf f "\t%s -> %s\n" c v; printValues f q
	| [] -> ();;
let printBlock f b = Printf.fprintf f "%s: %s (%s)\n%a" b.name b.blocktype b.blockid printValues b.values;;
let printBlocklist f lB = List.iter (printBlock f) lB;;
let printParDef f (t,v) = Printf.fprintf f "%s:\n%a" t printValues v;;  
let printBlockParDeflist f lP = List.iter (printParDef f) lP;;
let printLink f link = Printf.fprintf f "[ %i (port %i) -> %i (port %i) ]\n" link.fromblock link.fromport link.toblock link.toport;;
let printLinks f lL = List.iter (printLink f) lL;;

let verbose = 0;;

let printModel f ((lB, lP, lL):simulinkModel) =
  printBlocklist f lB;
  printBlockParDeflist f lP;
  printLinks f lL

let printPModel f ((lB,lL):simulinkPModel) =
  printBlocklist f lB;
  printLinks f lL

(* Handling of SSID*)
let ssid_count = ref (-1)
let getSSID al = 
  let i = int_of_string (List.assoc "SSID" al)  in
  ssid_count := max !ssid_count (i+1); 
  i

let fresh_ssid () =
  let f= !ssid_count in
  incr ssid_count; f

(* Function to fetch various attribute in XML tree*)
let rec findprop f = function
  | [] -> None
  | te::q -> match te with
    | Element ("props",_,cl2) -> begin match findprop f cl2 with
      None -> (match f te with None -> findprop f q | x-> x)
      | x -> x
    end
    | t -> (match f t with None -> findprop f q | x-> x)

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

(* Build block parameters defaults *)
let parseblockParams liste = function
    | Element  ("P",["Name",x],[PCData(l)]) -> (x,l)::liste;
    | _ -> failwith "wtf is this parameter ???";;

let rec blockparams_of_simulink ((lB, lP, lL) as ml)  = function
    | Element (name,alist,clist) (* as t *) -> 
        begin match name with
        | "BlockParameterDefaults" -> List.fold_left blockparams_of_simulink ml clist
        | "Block" -> let blockType = List.assoc "BlockType" alist
		     and blockParams = List.fold_left parseblockParams [] clist in
                (lB, (blockType, blockParams)::lP, lL)
        | _ -> Printf.fprintf stderr "In BlockParameterDefaults, %s should not exist\n" name; ml
        end
    | PCData (s) -> output_string stderr s; ml
;;

let extract_src s = s;;
let extract_dst s = s;; (* Vérifier si c'est le bon type de in/out *)

let extractLink (s,d) =
  let regexpIn = Str.regexp "\\([0-9]+\\)#out:\\([0-9]+\\)" and
      regexpOut = Str.regexp "\\([0-9]+\\)#in:\\([0-9]+\\)" in
	assert (Str.string_match regexpIn s 0);
        let inId = int_of_string (Str.matched_group 1 s) and
            inPort = int_of_string (Str.matched_group 2 s) in
        assert (Str.string_match regexpOut d 0);
        let outId = int_of_string (Str.matched_group 1 d) and
            outPort = int_of_string (Str.matched_group 2 d) in
        ({ fromblock = inId;
	   fromport = inPort;
	   toblock = outId;
	   toport = outPort });;

let line_of_simulink lL clist =
    let src = extract_src (findpropName "Src" clist) and dst = extract_dst (findpropName "Dst" clist) in
        match (src,dst) with
        | Some s, Some d -> (extractLink (s,d))::lL
        | _ -> failwith "A link without source or destination shouldn't exist";;

(* Build block lists *)
let rec blocklist_of_simulink ((lB, lP, lL):simulinkModel) = function
    | Element (name,alist,clist) (* as t *) ->
        begin match name with
        | "System" -> List.fold_left blocklist_of_simulink (lB, lP, lL) clist
        | "Line" -> (lB, lP, line_of_simulink lL clist)
        | "Block" -> let blockType = List.assoc "BlockType" alist and blockName = List.assoc "Name" alist
                     and blockID = List.assoc "SID" alist and blockParams = List.fold_left parseblockParams [] clist in
                     ({ blocktype = blockType;
			blockid = blockID;
			name = blockName;
			values = blockParams
		      }::lB, lP, lL);
        | _ when verbose>4 -> Printf.fprintf stderr "Couldn't find meaning of %s in System\n" name; (lB, lP, lL)
        | _ -> (lB, lP, lL)
        end
    | PCData (s) -> output_string stderr s; (lB, lP, lL)
;;

let rec blocklist_of_tree ml = function (* ml = (lB, lP, lL) *)
  | Element (name,alist,clist) as t->
    begin match name with
      | "xml" | "ModelInformation" | "Model" | "P" -> List.fold_left blocklist_of_tree ml clist
      | "BlockParameterDefaults" -> blockparams_of_simulink ml t
      | "System" -> blocklist_of_simulink ml t
      | _ when verbose>4 -> Printf.fprintf stderr "I don't know how to process %s : ignored\n" name; ml
      | _ -> ml
    end
    | PCData (s) -> ml

(* *)
let pushDefaults ((lB, lP, lL):simulinkModel) =
  let blockDef bloc =
    let listDefaults = List.assoc bloc.blocktype lP in
    let pred (paramName,_) =
      List.for_all (function (x,_) when x=paramName ->
					false | _ -> true) bloc.values in
    { blocktype = bloc.blocktype;
      blockid = bloc.blockid;
      name = bloc.name;
      values = ((List.filter pred listDefaults)@bloc.values)
     }
  in
  ((List.map blockDef lB), lL);;

let position_parse_regexp = Str.regexp "\\[\\([0-9]+\\)[ ,]*\\([0-9]+\\)[ ,]*\\([0-9]+\\)[ ,]*\\([0-9]+\\)\\]"
  
let getchar i = char_of_int ((int_of_char('A') + i - 1))
let printLaTeX f ((lB,lL):simulinkPModel) =
  let printBlock bloc =
    let btype = bloc.blocktype and bid = bloc.blockid and bval = bloc.values in
      let position = List.assoc "Position" bval in
        assert (Str.string_match position_parse_regexp position 0);
        let (x,y,w,h) = (int_of_string@@ Str.matched_group 1 position,
                         int_of_string@@ Str.matched_group 2 position,
                         int_of_string@@ Str.matched_group 3 position,
                         int_of_string@@ Str.matched_group 4 position) in
          Printf.fprintf f "\\node[sk%s,draw] at (%imm,%imm) (b%s) {};\n" btype x y bid
  and printLink link =
    Printf.fprintf f "\\path[->] (b%i.out%c) edge (b%i.in%c);\n"
		   link.fromblock (getchar link.fromport)
		   link.toblock (getchar link.toport)
  in
  List.iter printBlock lB;
  List.iter printLink lL
