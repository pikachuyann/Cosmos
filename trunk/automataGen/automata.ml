open Type

type varFormula = Test

type transType = 
  Synch of string list * stateFormula
| Autonomous of ((int*cmp*floatExpr) list)

type automata = {
  nbLoc: int;
  nbVar: int;
  invariant : (int*stateFormula) list;
  flows : (int*((int*floatExpr) list)) list;
  init : int;
  final : int list;
  trans : (int *transType *int) list;
}

let automata_of_formula = function
  | Until(s1,s2) ->
    {
      nbLoc = 2;
      nbVar = 1;
      invariant = [(0,And(s1,Not(s2)));(1,s2)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),0);
	     (0,Synch(["ALL"],True),1)];
    }
  | BoundedUntil(s1,(fexpr1,fexpr2),s2) when fexpr1 <> fexpr2 ->
    {
      nbLoc = 4;
      nbVar = 1;
      invariant = [(0,And(s1,Not(s2)));(1,And(s1,Not(s2)));(2,s2)];
      flows = [(0,[(0,Float(1.0))]) ; (1,[(0,Float(1.0))])];
      init =0;
      final=[2];
      trans=[(0,Synch(["ALL"],True),0);
	     (0,Autonomous([(0,EQ,fexpr1)]),1);
	     (1,Synch(["ALL"],True),1);
	     (1,Synch(["ALL"],True),2);
	     (1,Autonomous([(0,EQ,fexpr2)]),3);
	    ];
    }
  | BoundedUntil(s1,(fexpr,_),s2) ->
    {
      nbLoc = 3;
      nbVar = 1;
      invariant = [(0,s1);(1,s2);(2,Not(s2))];
      flows = [(0,[(0,Float(1.0))])];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),0);
	     (0,Autonomous([(0,EQ,fexpr)]),1);
	     (0,Autonomous([(0,EQ,fexpr)]),2);
	    ];
    }
  | Next(sf) ->
     {
      nbLoc = 2;
      nbVar = 1;
      invariant = [(1,sf)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),1) ];
    }

  | _ -> failwith "Not yet implemented"


let rec flowlist invt i c trlist pllist = match trlist,pllist with
    [],[] when i=0 -> []
  | [],[] -> flowlist invt (i-1) c trlist pllist
  | t::q,_ -> (c,MultF(FloatName(t),Float(invt))) :: (flowlist invt i (c+1) q trlist)
  | [],t::q -> flowlist invt i (c+1) [] q
  

let automata_of_pltrlist pllist trlist trans loop stepn =
  {
    let invT = loop /. (float stepn) in
    nbLoc = 2+stepn;
    nbVar = 1+ stepn*((List.length pllist)+(List.length trlist));
    invariant = [];
    flows = [(0,[(0,Float(1.0))])] :: (List.map);
    init =0;
    final=[1];
    trans=[(0,Synch(["ALL"],True),0);
	   (0,Synch(["ALL"],True),1)];
  }
