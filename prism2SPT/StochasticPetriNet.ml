(*
#mod_use "type.ml"
#mod_use "PetriNet.ml"
*)

open Type
open PetriNet

type distr = 
  Exp of float expr' 
| Imm 
| Unif of (float expr' *float expr')
| Norm of (float expr' *float expr')
| Det of float expr' 
| Erl of (int expr'*float expr');;

type position = (float*float) option;;

type spt = 
  (int Type.expr',  (* Initial Marking type*)
   distr*float Type.expr' * float Type.expr' , (* Label of transitions type *)
   int Type.expr' , (* valuation of arcs *)
   ((string*(int Type.expr') option) list)
   * ((string*(float Type.expr') option) list)
   * (string list)
   * (out_channel->unit->unit) (* Initialization *)
  ) Net.t;;


open Net

(* Print as a prism CTMC model*)
let print_prism_module fpath net =
  let f = open_out fpath in
  
  Printf.fprintf f "ctmc\nconst double imm=100000;\n";
 
  Printf.fprintf f "module m1\n";

  Data.iter (fun (n,x) ->
    Printf.fprintf f "\t%s: [%i..%i] init %a;\n" n 0 2 printH_expr x;
  ) net.place;

  Data.iteri  (fun i (n,x) ->
    begin match x with 
      (Imm,w,_) -> Printf.fprintf f "\t[] ";
    | _ -> Printf.fprintf f "\t[step] ";
    end;
    let prims = Data.fold (fun b (_,(s,p,t)) -> if t=i then
      begin
	if b then Printf.fprintf f " & ";
	  Printf.fprintf f "(%s>=%a)" (Data.acca net.place p |> fst) printH_expr s;
	true
      end
      else b
    ) false net.inArc in
    ignore @@ Data.fold (fun b (_,(s,p,t)) -> if t =i then
      begin
	if b then Printf.fprintf f " & ";
	Printf.fprintf f "(%s<%a)" (Data.acca net.place p |> fst) printH_expr s;
	true
      end
      else b
    ) prims net.inhibArc;
     
    begin match x with
      (Imm,w,_) -> Printf.fprintf f " -> imm*%a : " printH_expr w ;
    | (Exp(s),w,_) -> Printf.fprintf f " -> %a : " printH_expr s;
    |_ -> failwith "Prism does not support distribution shape"
    end;

    let update = Data.create () in

    Data.iteri (fun ip _ ->
      Data.iter (fun (_,(s,t,p)) -> if t=i && p=ip then Data.add (p,s) update)
      net.outArc;
      Data.iter (fun (_,(s,p,t)) -> if t=i && p=ip then 
	  try let iup = Data.index update p in
	      let v2 = eval (Minus((Data.acca update iup |> snd),s)) in
	      Data.updatea iup v2 update
	  with Data.Empty | Not_found -> Data.add (p,eval (Minus((Int 0),s)) ) update)
      net.inArc;

      ) net.place;

    ignore @@ Data.fold (fun b (p,v) -> begin
      if b then Printf.fprintf f " & ";
      let pname = (Data.acca net.place p |> fst) in
      Printf.fprintf f "(%s'=%a)" pname printH_expr (Plus((IntName pname),v));
      true
    end
    ) false update;
    Printf.fprintf f ";\n";
  ) net.transition;
  Printf.fprintf f "endmodule\n" ;
  Printf.fprintf f "rewards \"steps\"
\t[step] true : 1;
endrewards";
  close_out f


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
      Net.add_inArc net2 ("P"^y^"ErCont") y n;
      Net.add_inhibArc net2 ("P"^y^"ErCont")  (y^"ErStep") n;
      Net.add_outArc net2 (y^"ErStep") ("P"^y^"ErCont") (Int 1);
      let it = Data.index net.Net.transition y in
      Data.iter (fun ((),(v,p,t)) -> if t = it then begin
	let pn,_ = Data.acca net.Net.place p in
	let emptyn = (y^"ErEmptyIn"^pn) in
        Data.add (emptyn,(Imm,we,Plus(pr,(Float 4.0)))) net2.Net.transition;
        Net.add_inArc net2 ("P"^y^"ErCont") emptyn (Int 1);
	Net.add_outArc net2 (y^"ErStep") pn v;
       	Net.add_inArc net2 pn (y^"ErStep") v;
	Net.add_inhibArc net2 pn emptyn v;
      end) net.Net.inArc;
      Data.iter (fun ((),(v,p,t)) -> if t = it then begin
	let pn,_ = Data.acca net.Net.place p in
	let emptyn = (y^"ErEmptyInhib"^pn) in
	Data.add (emptyn,(Imm,we,Plus(pr,(Float 4.0)))) net2.Net.transition;
        Net.add_inArc net2 ("P"^y^"ErCont") emptyn (Int 1);
	Net.add_inhibArc net2 pn (y^"ErStep") v;
	Net.add_inArc net2 pn emptyn v;
	Net.add_outArc net2 emptyn pn v;
      end) net.Net.inhibArc;
  | _ ->() ) net.Net.transition;

  let transn2 = Data.map net2.Net.transition (fun (z,we,pr) -> match z with
      Erl(n,lamb) -> (Imm,we,pr)
    | _ -> (z,we,pr)) in
  {net2 with Net.transition= transn2}

let add_reward_struct (net:spt) =
  Data.iter (fun (y,(z,we,pr)) -> if z <> Imm then begin 
    Data.add (("P"^y^"_RewardStr"),(Int 0)) net.Net.place;
    Data.add (("Tr_"^y^"RewardStr"),(Unif(FloatName (y^"min"),FloatName (y^"max")),Float 1.0,Float 1.0)) net.Net.transition;
    Net.add_outArc net y ("P"^y^"_RewardStr") (Int 1);
    Net.add_inArc net ("P"^y^"_RewardStr") ("Tr_"^y^"RewardStr") (Int 1);
  end
  )
    net.Net.transition
