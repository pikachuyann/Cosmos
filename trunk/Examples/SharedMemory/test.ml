#use "../testTeamCity.ml";;

test_cosmos "shared memory" "sms_Unif.gspn" "--transient 100 --loop 100" "--max-run 1000" 149.93
