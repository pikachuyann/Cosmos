#use "../testTeamCity.ml";;

test_cosmos "lognormal" "testlognormal.grml" "testdistrib.lha" "" 
  ["MeanVal",(1. /. 1.4) ; "VarVal",(1. /. (1.4 *. 1.4))];;

test_cosmos "geometric" "testgeometric.grml" "testdistrib.lha" "" 
  ["MeanVal",(0.7 /. 0.98) ; "VarVal",(0.7 *. 0.7 *. 0.02 /. (0.98 *. 0.98))];;

test_cosmos "uniform" "testuniform.grml" "testdistrib.lha" "" 
  ["MeanVal",(1.0)];;

test_cosmos "exponential" "testexponential.grml" "testdistrib.lha" "" 
  ["MeanVal",(0.5); "VarVal",(1. /. 4.)];;

test_cosmos "deterministic" "testdeterministic.grml" "testdistrib.lha" "" 
  ["MeanVal",(2.0)];;

test_cosmos "triangle" "testtriangle.grml" "testdistrib.lha" "" 
  ["MeanVal",(8.0 /. 3.)];;
(*;"VarVal", (1.0+.9.0+.16.-. 3.0 -. 4.0 -. 12.0)/.18.0 *)

test_cosmos "erlang" "testerlang.grml" "testdistrib.lha" "" 
  ["MeanVal",(5.0/.0.7)];;

test_cosmos "gamma" "testgamma.grml" "testdistrib.lha" "" 
  ["MeanVal",(5.0*.0.7)];;

test_cosmos "discrete uniform" "testdiscreteuniform.grml" "testdistrib.lha" "" 
  ["MeanVal",(8.0)];;

test_cosmos "age memory" "testagememory.grml" "testagememory.lha" "--max-run 10000"
  ["MeanVal",(12.0)];;

test_cosmos "normal" "testnormal.grml" "testdistrib.lha" "--max-run 10000"
["MeanVal",(10.0); "VarVal",(2.0*.2.0)];;
