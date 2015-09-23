#use "../testTeamCity.ml";;

test_cosmos_gspn "tqn" ["Overflow",0.1752; "maxVal",5.401088487352618] "--max-run 5000  --HASL-formula 'maxVal=AVG(Max(x1));'" 
