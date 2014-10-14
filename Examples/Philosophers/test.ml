#use "../testTeamCity.ml";;

test_cosmos "Philosopher color" "philo.grml" "--loop 1000"  "--max-run 20000 --const N=8"
  [("Throughput_takeLeft",0.0132773335) ; 
  ("Throughput_takeRight", 0.0052773335) ;
  ("Throughput_backToThink", 0.0052773335);
  ("MeanToken_Think", 0.0238291302177);
  ("MeanToken_Wait" , 7.96561444752);
  ("MeanToken_Eat" , 0.0105564222604);
  ("MeanToken_Fork" , 0.0132727079572);
]
