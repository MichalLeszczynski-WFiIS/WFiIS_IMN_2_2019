set term jpeg

set xlabel "iteracje" # etykieta osi OX
set ylabel "wartosc" # etykieta osi OY

set title "Metoda jawna Eulera"
set out "euler.jpeg"
plot "euler_0-01.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "euler_0-1.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "euler_1-0.dat" u 1:2 w l lw 5 t 'dt = 1.0s', "euler_definition.dat" u 1:2 w p pt 7 ps 0.2 t 'dokladne'

set title "Metoda jawna Eulera - blad"
set out "euler_err.jpeg"
plot "euler_0-01_err.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "euler_0-1_err.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "euler_1-0_err.dat" u 1:2 w l lw 5 t 'dt = 1.0s'

set title "Metoda RK2"
set out "rk2.jpeg"
plot "rk2_0-01.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk2_0-1.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "rk2_1-0.dat" u 1:2 w l lw 5 t 'dt = 1.0s', "rk2_definition.dat" u 1:2 w p pt 7 ps 0.2 t 'dokladne'

set title "Metoda RK2 - blad"
set out "rk2_err.jpeg"
plot "rk2_0-01_err.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk2_0-1_err.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "rk2_1-0_err.dat" u 1:2 w l lw 5 t 'dt = 1.0s'

set title "Metoda RK2 - blad - 2"
set out "rk2_err_2.jpeg"
plot "rk2_0-01_err.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk2_0-1_err.dat" u 1:2 w l lw 1 t 'dt = 0.1s'

set title "Metoda RK4"
set out "rk4.jpeg"
plot "rk4_0-01.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk4_0-1.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "rk4_1-0.dat" u 1:2 w l lw 5 t 'dt = 1.0s', "rk4_definition.dat" u 1:2 w p pt 7 ps 0.2 t 'dokladne'

set title "Metoda RK4 - blad"
set out "rk4_err.jpeg"
plot "rk4_0-01_err.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk4_0-1_err.dat" u 1:2 w l lw 1 t 'dt = 0.1s', "rk4_1-0_err.dat" u 1:2 w l lw 5 t 'dt = 1.0s'

set title "Metoda RK4 - blad - 2"
set out "rk4_err_2.jpeg"
plot "rk4_0-01_err.dat" u 1:2 w l lw 1 t 'dt = 0.01s', "rk4_0-1_err.dat" u 1:2 w l lw 1 t 'dt = 0.1s'

set title "RLC omega = 0.5 omega_0"
set out "rlc_50.jpeg"
plot "rlc_50-0.dat" u 1:2 w l lw 1 t 'Q(t)', "" u 1:3 w l lw 1 t 'I(t)'

set title "RLC omega = 0.5 omega_0"
set out "rlc_50-q.jpeg"
plot "rlc_50-0.dat" u 1:2 w l lw 1 t 'Q(t)'

set title "RLC omega = 0.8 omega_0"
set out "rlc_80.jpeg"
plot "rlc_80-0.dat" u 1:2 w l lw 1 t 'Q(t)', "" u 1:3 w l lw 1 t 'I(t)'

set title "RLC omega = 0.8 omega_0"
set out "rlc_80-q.jpeg"
plot "rlc_80-0.dat" u 1:2 w l lw 1 t 'Q(t)'

set title "RLC omega = 1.0 omega_0"
set out "rlc_100.jpeg"
plot "rlc_100-0.dat" u 1:2 w l lw 1 t 'Q(t)', "" u 1:3 w l lw 1 t 'I(t)'

set title "RLC omega = 1.0 omega_0"
set out "rlc_100-q.jpeg"
plot "rlc_100-0.dat" u 1:2 w l lw 1 t 'Q(t)'

set title "RLC omega = 1.2 omega_0"
set out "rlc_120.jpeg"
plot "rlc_120-0.dat" u 1:2 w l lw 1 t 'Q(t)', "" u 1:3 w l lw 1 t 'I(t)'

set title "RLC omega = 1.2 omega_0"
set out "rlc_120-q.jpeg"
plot "rlc_120-0.dat" u 1:2 w l lw 1 t 'Q(t)'