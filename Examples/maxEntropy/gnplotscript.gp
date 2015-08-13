set terminal png size 600,800


set style line 1 lt 1 lw 4 lc rgb '#A0A0A0'


set output "gnuresult.png"

set pointsize 0.1

set tic font ",22"

set xtic 1
set ytic 1

plot 'preplot.dat' using 2:3 notitle with points pt 5 lc rgb '#A0A0A0'