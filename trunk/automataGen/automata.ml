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
  nbVar: int;
  invariant : (int*stateFormula) list;
  flows : (int*((int*floatExpr) list)) list;
  init : int;
  final : int list;
  trans : (int *transType*(((int*floatExpr) list) )*int) list;
}

let automata_of_formula = function
  | Until(s1,s2) ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 2;
      nbVar = 1;
      invariant = [(0,And(s1,Not(s2)));(1,s2)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],0);
	     (0,Synch(["ALL"],True),[],1)];
    }
  | BoundedUntil(s1,(fexpr1,fexpr2),s2) when fexpr1 <> fexpr2 ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 4;
      nbVar = 1;
      invariant = [(0,And(s1,Not(s2)));(1,And(s1,Not(s2)));(2,s2)];
      flows = [(0,[(0,Float(1.0))]) ; (1,[(0,Float(1.0))])];
      init =0;
      final=[2];
      trans=[(0,Synch(["ALL"],True),[],0);
	     (0,Autonomous([(0,EQ,fexpr1)]),[],1);
	     (1,Synch(["ALL"],True),[],1);
	     (1,Synch(["ALL"],True),[],2);
	     (1,Autonomous([(0,EQ,fexpr2)]),[],3);
	    ];
    }
  | BoundedUntil(s1,(fexpr,_),s2) ->
    {
      haslForm = ["Probability",Prob];
      nbLoc = 3;
      nbVar = 1;
      invariant = [(0,s1);(1,s2);(2,Not(s2))];
      flows = [(0,[(0,Float(1.0))])];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],0);
	     (0,Autonomous([(0,EQ,fexpr)]),[],1);
	     (0,Autonomous([(0,EQ,fexpr)]),[],2);
	    ];
    }
  | Next(sf) ->
     {
       haslForm = ["Probability",Prob];
      nbLoc = 2;
      nbVar = 1;
      invariant = [(1,sf)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),[],1) ];
    }

  | _ -> failwith "Not yet implemented"
  
let rec flowlist = function
  | -1 -> []
  | i -> (i,[(0,Float(1.0))]) :: flowlist (i-1)

let rec savelist i = function
  | [] -> [(0,PlusF(FloatName("v0"),Float(1.0)))]
  | t::q -> (i+1,CastInt(IntName(t))) :: (savelist (i+1) q)

let rec translist pllist timeint j = function
  | -1 -> []
  | i -> (0, Autonomous([0,EQ,Float((float i) *. (1.0+.timeint))]),(savelist (i*List.length pllist) pllist),j)
    :: (translist pllist timeint 0 (i-1))

let rec hasllist l time i = function
  | [] -> l
  | t::q -> ((t^"_"^(string_of_int (i+1))),Avg(Last(FloatName("v"^(string_of_int (i+1)))))) ::
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
      nbVar = 1+ (1+stepn)*((List.length pllist)+(List.length trlist));
      invariant = [];
      flows = flowlist stepn;
      init =0;
      final=[1];
      trans=  (0,Synch(["ALL"],True),[],0) ::(translist pllist invT 1 stepn);
    }
