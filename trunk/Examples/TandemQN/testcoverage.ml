#use "../testTeamCity.ml";;

let njob =2;;

test_coverage njob "tqn" ["Overflow",0.1752] "--width 0.01 --level 0.99" 100;
test_coverage njob "tqn" ["Overflow",0.1752] "--width 0.01 --level 0.95" 100;;
test_coverage njob "tqn" ["Overflow",0.1752] "--width 0.01 --level 0.9 --batch 100" 100;;
test_coverage njob "tqn" ["Overflow",0.1752] "--width 0.01 --level 0.5 --batch 100" 100;;


test_coverage njob "tqn" ["Overflow",0.1752] "--max-run  150000 --level 0.99" 100;
test_coverage njob "tqn" ["Overflow",0.1752] "--max-run  150000 --level 0.95" 100;;
test_coverage njob "tqn" ["Overflow",0.1752] "--max-run  150000 --level 0.9 --batch 100" 100;;
test_coverage njob "tqn" ["Overflow",0.1752] "--max-run  150000 --level 0.5 --batch 100" 100;;
