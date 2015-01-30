
let (|>>) x f = match x with 
    Some y -> f y
  | None -> None

let (|>>>) x f = match x with 
    Some y -> Some (f y)
  | None -> None

let (|>>|) x v = match x with
    Some y -> y
  | None -> v

let (|<) x f = let () = f x in x
let (|<>|) f (x,y) = f x y

let logout = ref stdout

let rec string_of_list sep f = function
  | [] -> ""
  | [t] -> f t
  | t::q -> Printf.sprintf "%s%s%s" (f t) sep @@ string_of_list sep f q

let print_list f sep file l =
  output_string file (string_of_list sep f l)

let rec selectL fb = function
  | [] -> raise Not_found
  | t::q when fb t -> (t,q)
  | t::q -> let t2,q2 = selectL fb q in
	    (t2,t::q2)

let print_option2 def f so  =
  match so with None -> output_string f def | Some s -> Printf.fprintf f "%s" s

let string_of_option def so  =
  match so with None -> def | Some s -> s

let print_option f so  = print_option2 "" f so

type cmp = EQ | SG | SL | GE | LE | NEQ

type _ expr' =
  | Bool  : bool -> bool expr'
  | Int   : int -> int expr'
  | Float : float -> float expr'
  | Not : bool expr' -> bool expr'
  | And : bool expr' * bool expr' -> bool expr'
  | Or  : bool expr' * bool expr' -> bool expr'
  | IntAtom : int expr' * cmp * int expr' -> bool expr'
  | Plus : 'a expr' * 'a expr' -> 'a expr'
  | Minus : 'a expr' * 'a expr' -> 'a expr'
  | Mult  : 'a expr' * 'a expr' -> 'a expr'
  | Floor : float expr' -> int expr'
  | Ceil  : float expr' -> int expr'
  | CastInt : int expr' -> float expr'
  | CastBool: bool expr' -> int expr'
  | IntName : string -> int expr'
  | FloatName : string -> float expr'
  | BoolName : string -> bool expr'
  | Div : float expr' *  float expr' -> float expr'
  | Exp : float expr' -> float expr'
  | FunCall : string*(('a expr') list) -> 'a expr'
  | If : (bool expr' * 'a expr' * 'a expr') -> 'a expr'

let rec iterFloat f y = 
  let ri = iterFloat f in match y with
    | FloatName(x) -> f y;
    | Float(x) -> f y;
    | CastInt(x) -> f y;
    | Plus(e1,e2) -> Plus(ri e1,ri e2) |> f
    | Minus(e1,e2) -> Minus(ri e1,ri e2) |> f
    | Mult(e1,e2) -> Mult(ri e1,ri e2) |> f
    | Div(e1,e2) -> Div(ri e1,ri e2) |> f
    | Exp(x) -> Exp(ri x) |> f 
    | FunCall(fu,l) -> FunCall(fu,List.map ri l) |> f
    | If(c,e1,e2) -> If(c,ri e1,ri e2) |> f
	       
let neg_cmp = function 
  | EQ -> NEQ  
  | SG -> LE
  | SL -> GE
  | GE -> SL
  | LE -> SG
  | NEQ-> EQ

let rec neg_bool = function
  | Bool x -> Bool (not x)
  | BoolName x -> Not (BoolName x)
  | Not e -> e
  | IntAtom (ie1,cmp,ie2) -> IntAtom (ie1,neg_cmp cmp,ie2)
  | And (e1,e2) -> Or (neg_bool e1,neg_bool e2)
  | Mult (e1,e2) -> Or (neg_bool e1,neg_bool e2)
  | Or (e1,e2) -> And (neg_bool e1,neg_bool e2)
  | Plus (e1,e2) -> And (neg_bool e1,neg_bool e2)
  | Minus (e1,e2) -> Or (neg_bool e1,e2)
  | FunCall (e,l) -> Not (FunCall (e,l))
  | If(c,e1,e2) -> If(c,neg_bool e1,neg_bool e2)

let rec eval : type a . a expr' -> a expr' = fun x -> 
  match x with
  | Plus(e1,e2) -> (match (eval e1),(eval e2) with
      Int y,Int z -> Int (y+z) 
    | Float y,Float z -> Float (y+.z)
    | Bool y,Bool z -> Bool (y || z)
    | _ -> x)
  | And(e1,e2) -> (match (eval e1),(eval e2) with
    | Bool y,z -> if y then z else Bool false
    | y,Bool z -> if z then y else Bool false
    | _ -> x) 
  | Or(e1,e2) -> (match (eval e1),(eval e2) with
    | Bool y,z -> if not y then z else Bool true
    | y,Bool z -> if not z then y else Bool true
    | _ -> x) 
  | Mult(e1,e2) -> (match (eval e1),(eval e2) with
    Int y,Int z -> Int (y*z) 
    | Float y,Float z -> Float (y*.z)
    | Float y,z -> if y=1.0 then z else (if y=0.0 then Float 0.0 else Mult (Float y,z))
    | z,Float y -> if y=1.0 then z else (if y=0.0 then Float 0.0 else Mult (Float y,z))
    | Int y,z -> if y=1 then z else (if y=0 then Int 0 else Mult (Int y,z))
    | z,Int y -> if y=1 then z else (if y=0 then Int 0 else Mult (Int y,z))

    | Bool y,Bool z -> Bool (y && z)
    | _ -> x)
  | Minus(e1,e2) -> (match (eval e1),(eval e2) with
      Int y,Int z -> Int (y-z) 
    | Float y,Float z -> Float (y-.z) 
    | _ -> x)
  | x -> x

let simp_int : int expr' -> int expr' = eval


let print_rename f =
  List.iter (fun (x,y) -> Printf.fprintf f " %s->%s " x y) 

let rename_op rn = function None -> None | Some a -> Some (rn a)

let rec rename_expr: type a. (string ->string) -> a expr' -> a expr' = fun rn e -> let rnr: type a. a expr' -> a expr' = fun x -> rename_expr rn x in match e with
    | IntName(s) -> IntName (rn s);
    | Int(i) -> Int(i)
    | Plus(e1,e2) -> Plus(rnr e1,rnr e2)
    | Minus(e1,e2) -> Minus(rnr e1,rnr e2)
    | Mult(e1,e2) -> Mult(rnr e1,rnr e2)
    | Div(e1,e2) -> Div(rnr e1,rnr e2)
    | Exp(e) -> Exp(rnr e)
    | Ceil(e) -> Ceil(rnr e)
    | Floor(e) -> Floor(rnr e)
    | Bool x -> Bool x
    | BoolName(x) -> BoolName(rn x) 
    | Not(e1) -> Not (rnr e1) 
    | And(e1,e2) -> And(rnr e1,rnr e2)
    | Or(e1,e2) -> Or(rnr e1,rnr e2)
    | IntAtom(ie,c,ie2) -> IntAtom(rnr ie,c,rnr ie2)
    | Float(f) -> Float(f)
    | FloatName(x) -> FloatName(rn x) 
    | CastInt(x) -> CastInt (rnr x)
    | CastBool(x) -> CastBool (rnr x)
    | FunCall(x,fl) -> FunCall(x,List.map rnr fl) 
    | If(c,e1,e2) -> If(rnr c,rnr e1, rnr e2)

let gez x = match eval x with
  | Int y when y>=0 -> true
  | _ -> false
let sgz x = match eval x with
  | Int y when y>0 -> true
  | _ -> false

let incr_int z = eval (Plus(z,Int 1))

module MultiSet (Ot:Map.OrderedType) = struct
  include Map.Make(Ot)
  let add_multi e t =
    try let i = find e t in
	remove e t 
	|> add e (i+1) 
    with
      Not_found -> add e 1 t
end

module StringSet = Set.Make(String)
module StringMap = MultiSet(String)

module IntSQ = struct 
  type t = int * int 
  let compare = compare 
end

module IntSQMulti = MultiSet(IntSQ)

let add_set t s =
  StringSet.fold StringMap.add_multi t s

let print_set sep f s=
  ignore (StringSet.fold (fun x c -> if c then output_string f sep;
    output_string f x;true) s false)

let print_multi sep f s=
  ignore (StringMap.fold (fun x y c -> if c then output_string f sep;
    Printf.fprintf f "%s:%i" x y;true) s false)

let printH_cmp f = function 
  | EQ -> output_string f "="  
  | SG -> output_string f ">" 
  | SL -> output_string f "<" 
  | GE -> output_string f ">=" 
  | LE -> output_string f "<=" 
  | NEQ-> output_string f "!=" 

let rec printH_expr: type a. out_channel -> a expr' -> unit = fun f x -> match x with
  | Int(i) -> Printf.fprintf f "%i" i
  | Float(i) -> Printf.fprintf f "%f" i
  | Bool(i) -> Printf.fprintf f "%B" i
  | IntName(s) -> output_string f s
  | FloatName(s) -> output_string f s
  | BoolName(s) -> output_string f s
  | Plus(e1,e2) -> Printf.fprintf f "(%a+%a)" 
    printH_expr e1 
    printH_expr e2
  | Minus(e1,e2) -> Printf.fprintf f "(%a-%a)" 
    printH_expr e1 
    printH_expr e2
  | Mult(e1,e2) -> Printf.fprintf f "(%a*%a)" 
    printH_expr e1 
    printH_expr e2
  | Ceil(e) -> Printf.fprintf f "ceil(%a)" 
    printH_expr e
  | Floor(e) -> Printf.fprintf f "floor(%a)" 
    printH_expr e 
  | Not e-> Printf.fprintf f "(!%a)" printH_expr e
  | And (e1,e2) -> Printf.fprintf f "(%a & %a)" 
    printH_expr e1
    printH_expr e2
  | Or (e1,e2) -> Printf.fprintf f "(%a | %a)" 
    printH_expr e1
    printH_expr e2
  | IntAtom (e1,c,e2) -> Printf.fprintf f "(%a %a %a)" 
    printH_expr e1
    printH_cmp c
    printH_expr e2  
  | CastInt(x) -> printH_expr f x
  | CastBool(x) -> printH_expr f x
  | Div(e1,e2) -> Printf.fprintf f "(%a/%a)" 
    printH_expr e1 
    printH_expr e2
  | Exp(x) -> Printf.fprintf f "exp(%a)" printH_expr x
  | FunCall(fu,[]) ->  Printf.fprintf f "%s()" fu;
  | FunCall(fu,t::q) ->  Printf.fprintf f "%s(%a" fu printH_expr t;
    List.iter (fun x-> Printf.fprintf f ",%a" printH_expr x) q;
    output_string f ")"
  | If (c,e1,e2) -> Printf.fprintf f "(%a ? %a : %a)" 
    printH_expr c
    printH_expr e1 
    printH_expr e2

let printH_int_expr f (x: int expr')= printH_expr f x
let printH_float_expr f (x: float expr')= printH_expr f x
let printH_stateFormula f (x: bool expr')= printH_expr f x

let print_token f = function 
  | Int 0 -> ()
  | Int 1 -> output_string f "•" 
  | Int 2 -> output_string f "••"
  | Int 3 -> output_string f "••\n•"
  | Int 4 -> output_string f "••\n••"
  | Int 5 -> output_string f "•••\n••"
  | i -> printH_int_expr f i
