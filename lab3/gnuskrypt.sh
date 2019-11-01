set term jpeg

set xlabel "argument" # etykieta osi OX
set ylabel "wartosc" # etykieta osi OY

set title "rk2 x(t)"
set out "rk2-x_t.jpeg"
plot "rk2-0.01.dat" u 1:3 w l lw 1 t 'TOL=1e-2', "rk2-1e-05.dat" u 1:3 w l lw 1 t 'TOL = 1e-5'

set title "rk2 v(t)"
set out "rk2-v_t.jpeg"
plot "rk2-0.01.dat" u 1:4 w l lw 1 t 'TOL=1e-2', "rk2-1e-05.dat" u 1:4 w l lw 1 t 'TOL = 1e-5'

set title "rk2 dt(t)"
set out "rk2-dt_t.jpeg"
plot "rk2-0.01.dat" u 1:2 w l lw 1 t 'TOL=1e-2', "rk2-1e-05.dat" u 1:2 w l lw 1 t 'TOL = 1e-5'

set title "rk2 v(x)"
set out "rk2-v_x.jpeg"
plot "rk2-0.01.dat" u 3:4 w l lw 1 t 'TOL=1e-2', "rk2-1e-05.dat" u 3:4 w l lw 1 t 'TOL = 1e-5'

set title "trapez x(t)"
set out "trapez-x_t.jpeg"
plot "trapez-0.01.dat" u 1:3 w l lw 1 t 'TOL=1e-2', "trapez-1e-05.dat" u 1:3 w l lw 1 t 'TOL = 1e-5'

set title "trapez v(t)"
set out "trapez-v_t.jpeg"
plot "trapez-0.01.dat" u 1:4 w l lw 1 t 'TOL=1e-2', "trapez-1e-05.dat" u 1:4 w l lw 1 t 'TOL = 1e-5'

set title "trapez dt(t)"
set out "trapez-dt_t.jpeg"
plot "trapez-0.01.dat" u 1:2 w l lw 1 t 'TOL=1e-2', "trapez-1e-05.dat" u 1:2 w l lw 1 t 'TOL = 1e-5'

set title "trapez v(x)"
set out "trapez-v_x.jpeg"
plot "trapez-0.01.dat" u 3:4 w l lw 1 t 'TOL=1e-2', "trapez-1e-05.dat" u 3:4 w l lw 1 t 'TOL = 1e-5'
