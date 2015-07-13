set terminal png size 600,800

set output "gnuresult.png"

set pointsize 0.1

plot 'preplot.dat' using 2:3 with points pt 5 