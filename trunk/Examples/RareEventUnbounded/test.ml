#use "../testTeamCity.ml";;

test_cosmos_grml "tandem" 0.0089 "--max-run 20000";;
test_cosmos "formula" "tandem.grml --formula \"E<100 (Queue2 = 4)\" --max-run 20000 " 0.063742;;
