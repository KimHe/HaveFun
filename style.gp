set term epslatex color standalone font 14 header '\usepackage{xcolor,amsmath} \input{../../defs}'
# dl 1.5
set style line 1 lt 1 lc rgb "black" lw 3
set style line 2 lt 2 lc rgb "red" lw 3
set style line 3 lt 5 lc rgb "dark-blue" lw 6 dt 2
set style line 4 lt 2 lc rgb "orange" lw 6 dt 3
set style line 5 lt 3 lc rgb "dark-green" lw 3
set style line 6 lt 3 lc rgb "yellow" lw 3

set style line 10 lt 1 lc rgb "black" lw 6

set style line 11 lt 1 pt 5 lc rgb "black" lw 4.5
set style line 12 lt 2 pt 7 lc rgb "red" lw 4.5
set style line 13 lt 8 pt 9 lc rgb "dark-blue" lw 4.5
set style line 14 lt 8 pt 13 lc rgb "dark-orange" lw 4.5

set pointsize 2.5
set bars 2

set border lw 2.5

set size 0.75,1.4
set origin 0,0

set size ratio 0.6 0.75

set lmargin 4.5
set rmargin 0.5

set tmargin 1.5
set bmargin 3

set format "$%g$"

