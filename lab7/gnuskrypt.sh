#!/usr/bin/gnuplot -c 
set terminal png font arial 12 size 640,380            # ustawia format wyjscia

set xlabel "ix"
set ylabel "jy"

set palette defined ( 0 '#D73027',\
    	    	      1 '#F46D43',\
		      2 '#FDAE61',\
		      3 '#FEE090',\
		      4 '#E0F3F8',\
		      5 '#ABD9E9',\
		      6 '#74ADD1',\
		      7 '#4575B4' )

set palette negative

set pm3d map

set cntrparam levels 30
set title "u Q=-1000"
set output "ua-1000.png" 
splot "n_s_-1000.000000.dat" u 1:2:($5!=0?$5:1/0) w pm3d t ""

set cntrparam levels 30
set title "v Q=-1000"
set output "va-1000.png" 
splot "n_s_-1000.000000.dat" u 1:2:($6!=0?$6:1/0) w pm3d t ""


set contour
unset surface
set view map
set cntrparam levels 15
unset key


set title "Psi Q=-1000"
set output "psi-1000.png" 
splot "n_s_-1000.000000.dat" u 1:2:($3!=0?$3:1/0) w l lw 2 palette t ""

set cntrparam levels 30
set title "Ksi Q=-1000"
set output "ksi-1000.png" 
splot "n_s_-1000.000000.dat" u 1:2:($4!=0?$4:1/0) w l lw 2 palette t ""



# 
set palette negative

set pm3d map

set cntrparam levels 30
set title "u Q=-4000"
set output "ua-4000.png" 
splot "n_s_-4000.000000.dat" u 1:2:($5!=0?$5:1/0) w pm3d t ""

set cntrparam levels 30
set title "v Q=-4000"
set output "va-4000.png" 
splot "n_s_-4000.000000.dat" u 1:2:($6!=0?$6:1/0) w pm3d t ""


set contour
unset surface
set view map
set cntrparam levels 15
unset key


set title "Psi Q=-4000"
set output "psi-4000.png" 
splot "n_s_-4000.000000.dat" u 1:2:($3!=0?$3:1/0) w l lw 2 palette t ""

set cntrparam levels 30
set title "Ksi Q=-4000"
set output "ksi-4000.png" 
splot "n_s_-4000.000000.dat" u 1:2:($4!=0?$4:1/0) w l lw 2 palette t ""
# 
set palette negative

set pm3d map

set cntrparam levels 30
set title "u Q=4000"
set output "ua4000.png" 
splot "n_s_4000.000000.dat" u 1:2:($5!=0?$5:1/0) w pm3d t ""

set cntrparam levels 30
set title "v Q=4000"
set output "va4000.png" 
splot "n_s_4000.000000.dat" u 1:2:($6!=0?$6:1/0) w pm3d t ""


set contour
unset surface
set view map
set cntrparam levels 15
unset key


set title "Psi Q=4000"
set output "psi4000.png" 
splot "n_s_4000.000000.dat" u 1:2:($3!=0?$3:1/0) w l lw 2 palette t ""

set cntrparam levels 30
set title "Ksi Q=4000"
set output "ksi4000.png" 
splot "n_s_4000.000000.dat" u 1:2:($4!=0?$4:1/0) w l lw 2 palette t ""
