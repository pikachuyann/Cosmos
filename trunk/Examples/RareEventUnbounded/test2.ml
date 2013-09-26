#use "../testTeamCity.ml";;

test_cosmos "generateProbVect" "tandemReduit.grml" "tandemRElha.grml" "--prism" 4.2234e-31;;

test_cosmos_grml "tandemRE" 3.79e-31  "-r --max-run 5000"
