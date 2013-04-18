
SYSTEM REQUIREMENTS:
____________________

1) Boost C++ libraries:
  http://www.boost.org/users/download/

2) Operating systems: LINUX, MAC


COMPILING:
__________

1) gunzip the zipped archive:
	gunzip cosmos.tar.gz 
	tar -xvf cosmos.tar
2) Move to cosmos directory:
   cd cosmos

3) -To compile on mac type:
	make -f Makefile

   -To compile on linux type:
	make -f Makefile_linux

Use:
____

Assume that you are in cosmos directory and you want to run it on the polling system example situated in Examples/PollingSystem/

I) Run with default statistical parameters (confidence interval width=0.001, confidence interval level=0.99, batch size =1000, maximum nueber of paths=2 000 000)

bin/Cosmos Examples/PollingSystem/ps.gspn Examples/PollingSystem/ps.lha

'ps'  is the name of the Petri net (ps.gspn) and Hasl (ps.lha) textual description files.

use the option '-h' to see available commands.


