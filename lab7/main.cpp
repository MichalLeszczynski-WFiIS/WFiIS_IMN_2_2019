#include "main.h"


int main()
{
    double Q;

    Q = -1000;
    navier_stokes(Q);

    Q = -4000;
    navier_stokes(Q);
    
    Q = 4000;
    navier_stokes(Q);

}

