set term jpeg

# 3D

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set zlabel "wartosc"

set logscale z

set title "Metoda algebraiczna"
set out "POTENCJAL_50_1.000000_1.000000rho_0.jpeg"
plot "POTENCJAL_50_1.000000_1.000000rho_0.dat" u 2:3:4 w p pt 7 ps 1 palette notitle

set title "Metoda algebraiczna"
set out "POTENCJAL_100_1.000000_1.000000rho_0.jpeg"
plot "POTENCJAL_100_1.000000_1.000000rho_0.dat" u 2:3:4 w p pt 7 ps 1 palette notitle

set title "Metoda algebraiczna"
set out "POTENCJAL_200_1.000000_1.000000rho_0.jpeg"
plot "POTENCJAL_200_1.000000_1.000000rho_0.dat" u 2:3:4 w p pt 7 ps 1 palette notitle



set title "Metoda algebraiczna"
set out "POTENCJAL_100_1.000000_1.000000rho_1.jpeg"
plot "POTENCJAL_100_1.000000_1.000000rho_1.dat" u 2:3:4 w p pt 7 ps 1 palette notitle

set title "Metoda algebraiczna"
set out "POTENCJAL_100_1.000000_10.000000rho_1.jpeg"
plot "POTENCJAL_100_1.000000_10.000000rho_1.dat" u 2:3:4 w p pt 7 ps 1 palette notitle

set title "Metoda algebraiczna"
set out "POTENCJAL_100_1.000000_2.000000rho_1.jpeg"
plot "POTENCJAL_100_1.000000_2.000000rho_1.dat" u 2:3:4 w p pt 7 ps 1 palette notitle
