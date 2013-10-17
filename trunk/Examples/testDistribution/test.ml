#use "../testTeamCity.ml";;

test_cosmos "lognormal" "testlognormal.grml" "testdistrib.grml" "" (1. /. 1.4);;

test_cosmos "geometric" "testgeometric.grml" "testdistrib.grml" "" (0.7 /. 0.98);;

test_cosmos "uniform" "testuniform.grml" "testdistrib.grml" "" (1.0);;

test_cosmos "exponential" "testexponential.grml" "testdistrib.grml" "" (0.5);;

test_cosmos "deterministic" "testdeterministic.grml" "testdistrib.grml" "" (2.0);;

test_cosmos "triangle" "testtriangle.grml" "testdistrib.grml" "" (8.0 /. 3.);;

test_cosmos "erlang" "testerlang.grml" "testdistrib.grml" "" (5.0/.0.7);;

test_cosmos "gamma" "testgamma.grml" "testdistrib.grml" "" (5.0*.0.7);;

test_cosmos "discrete uniform" "testdiscreteuniform.grml" "testdistrib.grml" "" (8.0);;

