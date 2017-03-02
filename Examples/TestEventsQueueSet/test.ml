#use "../testTeamCity.ml";;


Cosmos -g moded_CoSimulation.grml propCollision.lha --width 0.01 --use-setdomain-impl --njob 8 --batch 20 --max-run 10000000 --const EnvBehaviour=1 --const TypeGeneration=2 --const Ncases=1000 --const Vmax=5 --const VminInit=3 --const Ncases=1000 --const Nveh=20

test_cosmos "TestEventQueueSet" "moded_CoSimulation.grml" "propCollision.lha" "--max-run 20000 --use-setdomain-impl --batch 0 --const EnvBehaviour=1 --const TypeGeneration=2 --const Ncases=1000 --const Vm\
ax=5 --const VminInit=3 --const Ncases=1000 --const Nveh=20"
  []
