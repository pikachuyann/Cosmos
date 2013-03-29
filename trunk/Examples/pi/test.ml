#use "../testTeamCity.ml";;

test_cosmos_grml "pi" 3.1415 "--max-run 5000"

let _ =
	printf "##teamcity[testStarted name='Test Interactive' captureStandardOutput='<true>']\n";
	let b = Sys.command "echo \"help\nfire toto\nfire Sampy\nfire Sampx\nstep\n\nstep\nstop\n\" |  Cosmos pi.gspn pi.lha -i --gppcmd clang++ --gppflags \"--coverage\" 2>&1 | grep Isucc -q" in
	if b=0 then printf "##teamcity[testFinished name='Test Interactive' message='Test sucessfull']\n"
  else printf "##teamcity[testFailed name='Test Interactive' message='Test fail']\n"