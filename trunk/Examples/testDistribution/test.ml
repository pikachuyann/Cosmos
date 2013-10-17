#use "../testTeamCity.ml";;

test_cosmos "lognormal" "testlognormal.grml" "testdistrib.lha" "" ["MeanVal",(1. /. 1.4)];;

test_cosmos "geometric" "testgeometric.grml" "testdistrib.lha" "" ["MeanVal",(0.7 /. 0.98)];;

test_cosmos "uniform" "testuniform.grml" "testdistrib.lha" "" ["MeanVal",(1.0)];;

test_cosmos "exponential" "testexponential.grml" "testdistrib.lha" "" ["MeanVal",(0.5)];;

test_cosmos "deterministic" "testdeterministic.grml" "testdistrib.lha" "" ["MeanVal",(2.0)];;

test_cosmos "triangle" "testtriangle.grml" "testdistrib.lha" "" ["MeanVal",(8.0 /. 3.)];;

test_cosmos "erlang" "testerlang.grml" "testdistrib.lha" "" ["MeanVal",(5.0/.0.7)];;

test_cosmos "gamma" "testgamma.grml" "testdistrib.lha" "" ["MeanVal",(5.0*.0.7)];;

test_cosmos "discrete uniform" "testdiscreteuniform.grml" "testdistrib.lha" "" ["MeanVal",(8.0)];;

