set term jpeg

set xlabel "czas" # etykieta osi OX
set ylabel "wartosc" # etykieta osi OY

set title "Metoda Picarda"
set out "picard.jpeg"
plot "picard.dat" u 1:2 w l lw 1 t 'zarazeni', "" u 1:3 w l lw 1 t 'zdrowi'

set title "Iteracja Newtona"
set out "newton.jpeg"
plot "newton.dat" u 1:2 w l lw 1 t 'zarazeni', "" u 1:3 w l lw 1 t 'zdrowi'

set title "Niejawna RK2"
set out "nrk2.jpeg"
plot "nrk2.dat" u 1:2 w l lw 1 t 'zarazeni', "" u 1:3 w l lw 1 t 'zdrowi'
