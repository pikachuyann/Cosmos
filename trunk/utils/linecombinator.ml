open Str
(*#load "str.cma"*)

let newpath = regexp "New Path"
let blank = regexp " \\|\t"
let floatnum = regexp "[0-9]*\\([.][0-9]*\\)?";;

type dataElem = Floatv of float | Strv of string

let dataElem_of_string d =
  try Floatv (float_of_string d) with Failure "float_of_string" -> Strv (d)

module TimeEvent = struct
  type t = float*int*(dataElem list)
  let compare (t1,_,_) (t2,_,_) = compare t1 t2
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
	    readEvent f (EventSet.add (ts,i,List.map dataElem_of_string q) s) i
	with
	    Failure "float_of_string" -> failwith "strange line"
      )
  ) with
      End_of_file -> s,i

let write_event f (te,i,q) =
  output_string f (string_of_float te);
  List.iter (function Floatv(fv) -> output_string f ("\t"^(string_of_float fv)) 
		| Strv(sv) -> output_string f ("\t"^sv)) q;
  output_string f ("\t"^(string_of_int i)^"\n")

let rec mergedata d1 d2 = match d1,d2 with
     [],[] -> []
    | (Floatv t1)::q1,(Floatv t2)::q2 -> 
      ((Floatv (t1+.t2)) :: mergedata q1 q2)
    | (_::q1),(_::q2) -> (Strv("###")::mergedata q1 q2)
    | _ -> failwith "incoherent data"

let multdata k = List.map (function 
  Floatv f -> Floatv (k*.f) | _ -> Strv("###")) 

let emptydata = multdata 0.0 

let update_data td d i =
  td.(i-1)<-d;
  let nd = Array.fold_left mergedata (emptydata td.(0)) td in
  multdata (1.0 /. (float (Array.length td))) nd


let rec uniformize tl ((time,path,data):EventSet.elt) set1 =
  EventSet.add (time, path ,(update_data tl data path)) set1


let initfile = open_in Sys.argv.(1)
let intermediatefile = open_out (Sys.argv.(1)^"intermediate")

let main () =
  let fl = input_line initfile in 
  output_string intermediatefile (fl^"\n");
  let es = EventSet.empty in
  let esfull,maxi = readEvent initfile es 0 in
  let (_,_,datatemplate) = (EventSet.min_elt esfull) in
  let tabledata = Array.create maxi (emptydata datatemplate) in
  let esunif = EventSet.fold (uniformize tabledata) esfull EventSet.empty in
  EventSet.iter (write_event intermediatefile) esunif;;
      

main ();;


