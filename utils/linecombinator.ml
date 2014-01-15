open Str
(*#load "str.cma"*)

let newpath = regexp "New Path"
let blank = regexp "\\( \\|\t\\)+"
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
  let compare ((t1,_,_):t) ((t2,_,_):t) = 
    if t1 = t2 then 1
    else compare t1 t2

  let output f ((te,i,q):t) =
    output_string f (string_of_float te);
    Data.output f q; 
    output_string f ("\t"^(string_of_int i)^"\n")
end

module EventSet = Set.Make(TimeEvent)


let rec readEvent f s i =
  try (
    let line = input_line f in match split blank line with
      | [] -> failwith "empty line"
      | [s1;s2] when s1="New" && s2 = "Path" ->
	  readEvent f s (i+1)
      | te::q -> (
	try let ts = float_of_string te in
	    readEvent f (EventSet.add (ts,i,Data.data_of_stringList q) s) i
	with
	    Failure "float_of_string" -> failwith ("line do not start with a timestamp: \""^line^"\"")
      )
  ) with
      End_of_file -> s,i

let fillvect evect step d i j =
  for k =i to j do
    let (_,nbcount,d1) = evect.(k) in
    evect.(k) <- ((float k)*.step, nbcount+1 ,Data.merge d1 d);
  done


let readAndSample evect step f dl=
  let index = ref 0
  and dlast = ref dl in 
   try while true do 
    let line = input_line f in match split blank line with
      | [] -> failwith "strange line"
      | [s1;s2] when s1="New" && s2 = "Path" ->
	fillvect evect step !dlast !index (Array.length evect -1);
	dlast := Data.empty !dlast;
	index := 0;
      | te::q -> (
	try let ts = float_of_string te in
	    let bucket = int_of_float (ts /. step) in
	    let d2 = Data.data_of_stringList q in
	    fillvect evect step !dlast !index (bucket-1);
	    index := bucket;
	    dlast := d2;
	with
	  Failure "float_of_string" -> failwith "strange line"
	| Invalid_argument _-> ())
     done with
       End_of_file -> ()

let find_max_time f =
  let maxt = ref 0.0
  and np = ref 0
  and ne = ref 0
  and template = ref None in
  try while true do 
      let line = input_line f in match split blank line with
	| [] -> ()
	| [s1;s2] when s1="New" && s2 = "Path" -> incr np
	| te::q -> (
	  try let ts = float_of_string te in
	      incr ne;
	      maxt := max !maxt ts;
	      match !template with
	      | None -> template := Some(Data.empty (Data.data_of_stringList q));
	      | _ -> ()
	  with
	    Failure "float_of_string" -> ())
    done; (!maxt,!np,!ne,!template)
  with
      End_of_file -> (!maxt,!np,!ne,!template)

let update_data td d i =
  td.(i-1)<-d;
  let nd = Array.fold_left Data.merge (Data.empty td.(0)) td in
  Data.mult (1.0 /. (float (Array.length td))) nd


let rec uniformize tl ((time,path,data):EventSet.elt) set1 =
  EventSet.add (time, path ,(update_data tl data path)) set1

let main2 s1 s2  =
  let initfile = open_in s1 in
  let intermediatefile = open_out s2 in
  let (maxtime,np,ne,templateo) = find_max_time initfile in
  let step = maxtime/. 1000. in
  let template = (match templateo with None -> failwith "Empty file" | Some(x) ->x) in
  Printf.printf "Max time: %f\t number of paths: %i\t number of events: %i\n" maxtime np ne;
  seek_in initfile 0;
  let fl = input_line initfile in 
  output_string intermediatefile (fl^"\n");
  if ne > 10000 then
    let evect = Array.create (int_of_float (1.+.maxtime/.step)) (0.0,0,template) in
    readAndSample evect step initfile template;
    Array.iteri (fun i (t,n,d) -> evect.(i) <- (t,1,Data.mult (1.0 /. (float n)) d)) evect;
    Array.iter (TimeEvent.output intermediatefile) evect
  else 
    let es = EventSet.empty in
    let esfull,maxi = readEvent initfile es 0 in
    let tabledata = Array.create maxi (Data.empty template) in
    EventSet.iter (function (t,p,d) when t=0.0 -> tabledata.(p-1)<- d | _ ->()) esfull;
    let esunif = EventSet.fold (uniformize tabledata) esfull EventSet.empty in
    EventSet.iter (TimeEvent.output intermediatefile) esunif;;

main2 Sys.argv.(1) Sys.argv.(2);;


