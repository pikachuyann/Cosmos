#use "../testTeamCity.ml";;

test_coverage "tqn" 0.1752 "--max-run 150000 --njob 2 --level 0.99" 500 ;;
test_coverage "tqn" 0.1752 "--max-run 150000 --njob 2 --level 0.95" 500 ;;
test_coverage "tqn" 0.1752 "--max-run 150000 --njob 2 --level 0.90" 500 ;;
