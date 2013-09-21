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
      nbVar = 0;
      invariant = [(0,s1);(1,s2)];
      flows = [];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),0);
	     (0,Synch(["ALL"],True),1)];
    }
  | BoundedUntil(s1,cmp,fexpr,s2) ->
    {
      nbLoc = 3;
      nbVar = 1;
      invariant = [(0,s1);(1,s2)];
      flows = [(0,[(0,Float(1.0))])];
      init =0;
      final=[1];
      trans=[(0,Synch(["ALL"],True),0);
	     (0,Synch(["ALL"],True),1);
	     (0,Autonomous([(0,EQ,fexpr)]),2)
	    ];
    }


