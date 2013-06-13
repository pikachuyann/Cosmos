set terminal pngcairo font "arial,10" fontscale 1.0 size 1000, 700 
set output 'dataout3.png'

set grid lc rgb "black"

set style fill solid 0.2 noborder

plot 'bench.dat' \
      using 1:4 title 'cpu time'