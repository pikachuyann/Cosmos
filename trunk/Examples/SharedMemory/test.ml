#use "../testTeamCity.ml";;

test_cosmos "shared memory" "--max-run 1000 sms_Unif.gspn --transient 100 --loop 100" 149.93
