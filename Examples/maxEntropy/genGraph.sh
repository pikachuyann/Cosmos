


sage script_tocosmos.sage $1 $1.grml 20 -unif fldsjflds

Cosmos $1.grml --loop "#400000" --trace-place "x_1,x_2,x_3" --output-trace $1.dat 0.0 --max-run 1 --gppflags "-O0"
linecombinator $1.dat preplot.dat
gnuplot gnplotscript.gp
mv gnuresult.png $1.png
Cosmos Iso_$1.grml --loop "#400000" --trace-place "x_1,x_2,x_3" --output-trace Iso_$1.dat 0.0 --max-run 1 --gppflags "-O0"
linecombinator Iso_$1.dat preplot.dat
gnuplot gnplotscript.gp
mv gnuresult.png Iso_$1.png
