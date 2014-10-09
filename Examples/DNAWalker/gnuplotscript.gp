set terminal png font 'arial,12' size 2000, 800
set grid lt 4 lc rgb '#909090'
set style fill solid 0.2 noborder
set output 'pdfcdfout.png'
plot for [i=1:9] 'test.dat' using 1:3*i-1:3*i+1 w filledcu ls 1 lc i notitle, for [i=1:9] '' using 1:3*i title columnheader with lines lc i lw 1
set output
exit
