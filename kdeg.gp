load '../style.gp'
set out "kdeg.tex"

set macros
set format "$%g$"
set format y "$10^{%L}$"

set log

# y axis
set ylabel 'prod.~velocity, $v_{non}/v_{ch}$' offset 2.2
set ytics offset 0.7

# x axis
set xlabel 'degradation rate, $k_\mathrm{deg}$ (s$^{-1}$)' offset 0,0.2
set key at 3,0.1

f=1

plot [:20] [:5] \
	'data/kdeg_E100.dat' u ($1):($2/$4) w l ls 2 lw 4 dt 2 title '$[\E_i] = 100$~nM',\
	'data/kdeg_E50.dat' u ($1):($2/$4) w l ls 1 lw 2 title '$[\E_i] = 50$~nM', \
	f w l lt 1 lw 2.5 dt 3 lc rgb 'black' notitle


