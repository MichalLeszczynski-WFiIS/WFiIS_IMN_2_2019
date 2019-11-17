set term jpeg

set xlabel "it" # etykieta osi OX
set ylabel "S(it)" # etykieta osi OY

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_s.jpeg"
plot "wielo_rel_s_k_16.dat" u 1:2 w l lw 1 t 'k=16',"wielo_rel_s_k_8.dat" u 1:2 w l lw 1 t 'k=8',"wielo_rel_s_k_4.dat" u 1:2 w l lw 1 t 'k=4',"wielo_rel_s_k_2.dat" u 1:2 w l lw 1 t 'k=2',"wielo_rel_s_k_1.dat" u 1:2 w l lw 1 t 'k=1'

# 3D

set xlabel "x" # etykieta osi OX
set ylabel "y" # etykieta osi OY
set zlabel "wartosc"

set logscale z

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_v_k_16.jpeg"
splot "wielo_rel_v_k_16.dat" u 1:2:3 w l lw 1 t 'V'

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_v_k_8.jpeg"
splot "wielo_rel_v_k_8.dat" u 1:2:3 w l lw 1 t 'V'

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_v_k_4.jpeg"
splot "wielo_rel_v_k_4.dat" u 1:2:3 w l lw 1 t 'V'

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_v_k_2.jpeg"
splot "wielo_rel_v_k_2.dat" u 1:2:3 w d lw 1 t 'V'

set title "Relaksacja wielosiatkowa"
set out "wielo_rel_v_k_1.jpeg"
splot "wielo_rel_v_k_1.dat" u 1:2:3 w d lw 1 t 'V'
