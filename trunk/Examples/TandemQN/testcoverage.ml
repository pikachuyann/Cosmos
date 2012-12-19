#use "../testTeamCity.ml";;

test_coverage "tqn" 0.1752 "--max-run 150000 --njob 11 --level 0.99" 5000 ;;
test_coverage "tqn" 0.1752 "--max-run 150000 --njob 11 --level 0.95" 5000 ;;
test_coverage "tqn" 0.1752 "--max-run 150000 --njob 11 --level 0.90" 5000 ;;
