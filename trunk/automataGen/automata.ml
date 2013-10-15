open Type

type haslformulaAlg = Last of floatExpr
and haslformulaTop = Avg of haslformulaAlg | Prob

let rec print_haslTop = function
  | Prob -> print_string "PROB";
  | Avg(halg) -> print_string "AVG(";
    print_haslAlg halg;
    print_string ")"

and print_haslAlg = function
  | Last(x) -> print_string "Last(";
    print_float_expr x;
    print_string ")"
and print_HASL (n,f) =
  print_string n;
  print_string "=";
  print_haslTop f;
  print_endline ";"


type transType = 
  Synch of string list * stateFormula
| Autonomous of ((int*cmp*floatExpr) list)

type automata = {
  haslForm: (string*haslformulaTop) list;
  nbLoc: int;
  nbContVar: int;
  nbDiscVar:int;
  invariant : (int*stateFormula) list;
  flows : (int*((int*floatExpr) list)) list;
  init : int;
  final : int list;
  trans : (int *transType*(((int*floatExpr) list))*(((int*floatExpr) list) )*int) list;
}

let automata_of_formula = function
  | Until(s1,s2) ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 2;
      nbContVar = 1;
      nbDiscVar = 0;
      invariant = [(0,And(s1,Not(s2)));(1,s2)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],[],0);
	     (0,Synch(["ALL"],True),[],[],1)];
    }
  | BoundedUntil(s1,(fexpr1,fexpr2),s2) when fexpr1 <> fexpr2 ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 4;
      nbContVar = 1;
      nbDiscVar = 0;
      invariant = [(0,And(s1,Not(s2)));(1,And(s1,Not(s2)));(2,s2)];
      flows = [(0,[(0,Float(1.0))]) ; (1,[(0,Float(1.0))])];
      init =0;
      final=[2];
      trans=[(0,Synch(["ALL"],True),[],[],0);
	     (0,Autonomous([(0,EQ,fexpr1)]),[],[],1);
	     (1,Synch(["ALL"],True),[],[],1);
	     (1,Synch(["ALL"],True),[],[],2);
	     (1,Autonomous([(0,EQ,fexpr2)]),[],[],3);
	    ];
    }
  | BoundedUntil(s1,(fexpr,_),s2) ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 3;
      nbContVar = 1;
      nbDiscVar = 0;
      invariant = [(0,s1);(1,s2);(2,Not(s2))];
      flows = [(0,[(0,Float(1.0))])];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],[],0);
	     (0,Autonomous([(0,EQ,fexpr)]),[],[],1);
	     (0,Autonomous([(0,EQ,fexpr)]),[],[],2);
	    ];
    }
  | Next(sf) ->
     {
       haslForm = ["Probability",Prob];
      nbLoc = 2;
      nbContVar = 1;
      nbDiscVar = 0;
      invariant = [(1,sf)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],[],1) ];
    }

  | _ -> failwith "Not yet implemented"



let insertLH h l s =
  if (Hashtbl.mem h s) then l
  else (
    Hashtbl.add h s ();
    s::l
  )
  

let rec explore_and_synch h a1 a2 qt = function
  | [] -> qt
  | (s1,s2)::q -> 
    let l1 = List.filter (fun (i,_,_,_,_) -> i=s1) a1.trans
    and l2 = List.filter (fun (i,_,_,_,_) -> i=s2) a2.trans in
    let (lp,qt2) = List.fold_left (fun q2 t1 -> List.fold_left (fun q3 t2 -> sychtrans h a1 a2 q3 t1 t2) q2 l2) (q,qt) l1 in explore_and_synch h a1 a2 qt2 lp

and sychtrans h a1 a2 (lp,lt) (s1,tt1,_,_,sp1) (s2,tt2,_,_,sp2) =
  match tt1,tt2 with
    Synch(_),Autonomous(_)-> (lp,lt) 
  | Autonomous(_),Synch(_)-> (lp,lt) 
  | Synch(label1,guard1),Synch(label2,guard2) ->
    
    (insertLH h lp (sp1,sp2),lt)

  | Autonomous(guard1),Autonomous(guard2) ->
    (insertLH h lp (sp1,sp2),lt)

let and_automaton a1 a2 =
  let hash_state = Hashtbl.create a1.nbLoc in ()
  



  
let rec flowlist = function
  | -1 -> []
  | i -> (i,[(0,Float(1.0))]) :: flowlist (i-1)

let rec savelist i = function
  | [] -> []
  | t::q -> (i,CastInt(IntName(t))) :: (savelist (i+1) q)

let rec translist pllist timeint j = function
  | -1 -> []
  | i -> (0, Autonomous([0,EQ,Float((float i) *. (1.0+.timeint))]),[(0,PlusF(ContinuousVar(0),Float(1.0)))],(savelist (i*List.length pllist) pllist),j)
    :: (translist pllist timeint 0 (i-1))

let rec hasllist l time i = function
  | [] -> l
  | t::q -> ((t^"_"^(string_of_int (i+1))),Avg(Last(DiscreteVar(i)))) ::
    (hasllist l time (i+1) q)

let rec hasllistTop l stept pllist = function
  | -1 -> l
  | i ->  let time = string_of_float (stept*.(float (i+1))) in
	  let callrec = hasllist l time ((i)*List.length pllist) pllist  in
	  hasllistTop callrec stept pllist (i-1) 
	  


let automata_of_pltrlist pllist trlist trans loop stepn =
    let invT = loop /. (float stepn) in
    {
      haslForm = hasllistTop [] invT pllist stepn;
      nbLoc = 2;
      nbContVar = 1;
      nbDiscVar = (1+stepn)*((List.length pllist)+(List.length trlist));
      invariant = [];
      flows = flowlist stepn;
      init =0;
      final=[1];
      trans=  (0,Synch(["ALL"],True),[],[],0) ::(translist pllist invT 1 stepn);
    }
