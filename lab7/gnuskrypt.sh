set term jpeg

# 3D

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set zlabel "wartosc"

set logscale z


set title "Rownania Naviera-Stokesa"
set out "n_s_Psi_-1000.000000.jpeg"
plot "n_s_Psi_-1000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle

set title "Rownania Naviera-Stokesa"
set out "n_s_Ksi_-1000.000000.jpeg"
plot "n_s_Ksi_-1000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle


set title "Rownania Naviera-Stokesa"
set out "n_s_Psi_-4000.000000.jpeg"
plot "n_s_Psi_-4000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle

set title "Rownania Naviera-Stokesa"
set out "n_s_Ksi_-4000.000000.jpeg"
plot "n_s_Ksi_-4000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle


set title "Rownania Naviera-Stokesa"
set out "n_s_Psi_4000.000000.jpeg"
plot "n_s_Psi_4000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle

set title "Rownania Naviera-Stokesa"
set out "n_s_Ksi_4000.000000.jpeg"
plot "n_s_Ksi_4000.000000.dat" u 1:2:3 w p pt 5 ps 4 palette notitle
