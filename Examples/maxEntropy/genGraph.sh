


#sage script_tocosmos.sage $1 $1.grml 20 -unif fldsjflds

#Cosmos $1.grml --loop "#400000" --trace-place "x_1,x_2,x_3" --output-trace $1.dat 0.0 --max-run 1 --gppflags "-O0"
grep 'tt_' $1.dat > preplot.dat
grep 'tt_0_0\|tt_0_2\|tt_1_0\|tt_1_2\|tt_2_0\|tt_2_2\|tt_3_1' $1.dat > preplota.dat
grep 'tt_0_1\|tt_1_1\|tt_2_1\|tt_3_0' $1.dat > preplotb.dat
#linecombinator $1H.dat preplot.dat
gnuplot gnplotscript.gp
mv gnuresult.png $1.png
#Cosmos Iso_$1.grml --loop "#400000" --trace-place "x_1,x_2,x_3" --output-trace Iso_$1.dat 0.0 --max-run 1 --gppflags "-O0"
grep 'tt_' Iso_$1.dat > preplot.dat
grep 'tt_0_0\|tt_0_2\|tt_1_0\|tt_1_2\|tt_2_0\|tt_2_2\|tt_3_1' Iso_$1.dat > preplota.dat
grep 'tt_0_1\|tt_1_1\|tt_2_1\|tt_3_0' Iso_$1.dat > preplotb.dat
#linecombinator Iso_$1H.dat preplot.dat
gnuplot gnplotscript.gp
mv gnuresult.png Iso_$1.png
