
SYSTEM REQUIREMENTS:
____________________

1) Boost C++ libraries:
  http://www.boost.org/users/download/

If you want to use the llvm version, you need:
2) <<LLVM source code>> and <<LLVM-GCC 4.2 Front End Source Code>>:
  http://llvm.org/releases/download.html

3) Operating systems: LINUX, MAC


COMPILING:
__________

1) gunzip the zipped archive:
	gunzip cosmos.tar.gz 
	tar -xvf cosmos.tar
2) Move to cosmos directory:
   cd cosmos

3) -To compile the GCC version:
	make -f MakefileGPP

   -To compile the llvm version:
	make -f MakefileLLVM

Use:
____

Assume that you are in cosmos directory and you want to run it on the polling system example situated in Examples/PollingSystem/

I) Run with default statistical parameters (confidence interval width=0.001, confidence interval level=0.99, batch size =1000, maximum numeber of paths=100 000 000)

bin/CosmosLLVM Examples/PollingSystem/ps (cosmos llvm version)
or
bin/CosmosGPP Examples/PollingSystem/ps (cosmos GCC version)

'ps'  is the name of the Petri net (ps.gspn) and Hasl (ps.lha) textual description files.

II) bin/CosmosLLVM or  bin/CosmosGPP 

type help to see available commands.

NB:
You can also add 'cosmos/bin/' to your PATH environment variable.
In this case you can call CosmosLLVM (or CosmosGPP) from any directory.
This option is only available for Linux systems.

