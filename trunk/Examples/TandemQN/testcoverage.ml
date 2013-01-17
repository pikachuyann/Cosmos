#use "../testTeamCity.ml";;

test_coverage "tqn" 0.1752 "--width 0.01 --njob 11 --level 0.99" 50000;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 11 --level 0.95" 50000;;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 11 --level 0.9 --batch 100" 50000;;
test_coverage "tqn" 0.1752 "--width 0.01 --njob 11 --level 0.5 --batch 100" 50000;;
