open Str
(*#load "str.cma"*)

let newpath = regexp "New Path"
let blank = regexp " \\|\t"
let floatnum = regexp "[0-9]*\\([.][0-9]*\\)?";;

module Data = struct
  type elt = Floatv of float | Strv of string
  type t = elt list

  let rec merge d1 d2 = match d1,d2 with
      [],[] -> []
    | (Floatv t1)::q1,(Floatv t2)::q2 -> 
      ((Floatv (t1+.t2)) :: merge q1 q2)
    | (_::q1),(_::q2) -> (Strv("###")::merge q1 q2)
    | _ -> failwith "incoherent data"
      
  let mult k = List.map (function 
  Floatv f -> Floatv (k*.f) | _ -> Strv("###")) 
    
  let empty = mult 0.0 
  let output f d =
    List.iter (function 
      | Floatv(fv) -> output_string f ("\t"^(string_of_float fv)) 
      | Strv(sv) -> output_string f ("\t"^sv)
    ) d
    
  let dataElem_of_string d =
    try Floatv (float_of_string d) 
    with Failure "float_of_string" -> Strv (d)

  let data_of_stringList =
    List.map dataElem_of_string
end 


module TimeEvent = struct
  type t = float*int*(Data.t)
  let compare ((t1,_,_):t) ((t2,_,_):t) = compare t1 t2

  let output f ((te,i,q):t) =
    output_string f (string_of_float te);
    Data.output f q; 
    output_string f ("\t"^(string_of_int i)^"\n")
end

module EventSet = Set.Make(TimeEvent)


let rec readEvent f s i =
  try (
    let line = input_line f in match split blank line with
      | [] -> failwith "strange line"
      | [s1;s2] when s1="New" & s2 = "Path" ->
	  readEvent f s (i+1)
      | te::q -> (
	try let ts = float_of_string te in
	    readEvent f (EventSet.add (ts,i,Data.data_of_stringList q) s) i
	with
	    Failure "float_of_string" -> failwith "strange line"
      )
  ) with
      End_of_file -> s,i

(*
let rec readAndSample evect step f i =
   try (
    let line = input_line f in match split blank line with
      | [] -> failwith "strange line"
      | [s1;s2] when s1="New" & s2 = "Path" ->
	  readAndSample evect step f (i+1)
      | te::q -> (
	try let ts = float_of_string te in
	    readEvent f (EventSet.add (ts,i,List.map dataElem_of_string q) s) i
	with
	    Failure "float_of_string" -> failwith "strange line"
      )
  ) with
      End_of_file -> s,i
*)
let update_data td d i =
  td.(i-1)<-d;
  let nd = Array.fold_left Data.merge (Data.empty td.(0)) td in
  Data.mult (1.0 /. (float (Array.length td))) nd


let rec uniformize tl ((time,path,data):EventSet.elt) set1 =
  EventSet.add (time, path ,(update_data tl data path)) set1

let main s1 s2 =
  let initfile = open_in s1 in
  let intermediatefile = open_out s2 in
  let fl = input_line initfile in 
  output_string intermediatefile (fl^"\n");
  let es = EventSet.empty in
  let esfull,maxi = readEvent initfile es 0 in
  let (_,_,datatemplate) = (EventSet.min_elt esfull) in
  let tabledata = Array.create maxi (Data.empty datatemplate) in
  let esunif = EventSet.fold (uniformize tabledata) esfull EventSet.empty in
  EventSet.iter (TimeEvent.output intermediatefile) esunif;;
      
main Sys.argv.(1) Sys.argv.(2);;


