#use "../testTeamCity.ml";;

invoke_cosmos  "-s" "tandem_agr.gspn" "tandem_agr.lha";;

test_cosmos_gspn "tandem" 3.687633e-14 "-b 1 --set-Horizon 100 --max-run 5000 --batch 5000";;
test_cosmos_gspn "tandem" 3.687633e-14 "-b 2 --set-Horizon 100 --max-run 5000 --batch 5000";;
test_cosmos_gspn "tandem" 3.687633e-14 "-b 3 --set-Horizon 100 --max-run 5000 --batch 5000";;
