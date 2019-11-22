set term jpeg

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set logscale x 
set title "Relaksacja globalna"
set out "glob_rel_s.jpeg"
plot "glob_rel_s_omega_0.600000.dat" u 1:2 w l lw 1 t 'omega=0.6',"glob_rel_s_omega_1.000000.dat" u 1:2 w l lw 1 t 'omega=1.0'

set title "Relaksacja lokalna"
set out "loc_rel_s.jpeg"
plot "loc_rel_s_omega_1.400000.dat" u 1:2 w l lw 1 t 'omega=1.4',"loc_rel_s_omega_1.000000.dat" u 1:2 w l lw 1 t 'omega=1.8',"loc_rel_s_omega_1.800000.dat" u 1:2 w l lw 1 t 'omega=1.8',"loc_rel_s_omega_1.900000.dat" u 1:2 w l lw 1 t 'omega=1.9'

# 3D
unset logscale x
set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set zlabel "wartosc"

set logscale z
# set pm3d map

set title "Relaksacja globalna"
set out "glob_rel_v_0.600000.jpeg"
plot "glob_rel_v_omega_0.600000.dat" u 1:2:3 w p pt 7 palette t 'V'

set title "Relaksacja globalna"
set out "glob_rel_v_1.000000.jpeg"
plot "glob_rel_v_omega_1.000000.dat" u 1:2:3 w p pt 7 palette t 'V'

set title "Relaksacja globalna"
set out "glob_rel_err_0.600000.jpeg"
plot "glob_rel_err_omega_0.600000.dat" u 1:2:3 w p pt 7 palette t 'Error'

set title "Relaksacja globalna"
set out "glob_rel_err_1.000000.jpeg"
plot "glob_rel_err_omega_1.000000.dat" u 1:2:3 w p pt 7 palette t 'Error'
