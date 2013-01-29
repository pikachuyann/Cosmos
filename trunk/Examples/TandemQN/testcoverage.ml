#use "../testTeamCity.ml";;

test_coverage "tqn" 0.1752 "--width 0.01 --njob 12 --level 0.99" 100;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 12 --level 0.95" 100;;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 12 --level 0.9 --batch 100" 100;;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 12 --level 0.5 --batch 100" 100;;


test_coverage "tqn" 0.1752 "--max-run  150000 --njob 12 --level 0.99" 100;
test_coverage "tqn" 0.1752 "--max-run  150000 --njob 12 --level 0.95" 100;;
test_coverage "tqn" 0.1752 "--max-run  150000 --njob 12 --level 0.9 --batch 100" 100;;
test_coverage "tqn" 0.1752 "--max-run  150000 --njob 12 --level 0.5 --batch 100" 100;;
