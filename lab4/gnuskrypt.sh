set term jpeg

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY

set title "Relaksacja globalna"
set out "glob_rel_s.jpeg"
plot "glob_rel_s_omega_0.600000.dat" u 1:2 w l lw 1 t 'omega=0.6',"glob_rel_s_omega_1.000000.dat" u 1:2 w l lw 1 t 'omega=1.0'

set title "Relaksacja lokalna"
set out "loc_rel_s.jpeg"
plot "loc_rel_s_omega_1.400000.dat" u 1:2 w l lw 1 t 'omega=1.4',"loc_rel_s_omega_1.000000.dat" u 1:2 w l lw 1 t 'omega=1.0'

# 3D

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set zlabel "wartosc"

set logscale z

set title "Relaksacja globalna"
set out "glob_rel_v_0.600000.jpeg"
splot "glob_rel_v_omega_0.600000.dat" u 1:2:3 w l lw 1 t 'V'

set title "Relaksacja globalna"
set out "glob_rel_v_1.000000.jpeg"
splot "glob_rel_v_omega_1.000000.dat" u 1:2:3 w l lw 1 t 'V'

set title "Relaksacja globalna"
set out "glob_rel_err_0.600000.jpeg"
splot "glob_rel_err_omega_0.600000.dat" u 1:2:3 w l lw 1 t 'Error'

set title "Relaksacja globalna"
set out "glob_rel_err_1.000000.jpeg"
splot "glob_rel_err_omega_1.000000.dat" u 1:2:3 w l lw 1 t 'Error'
