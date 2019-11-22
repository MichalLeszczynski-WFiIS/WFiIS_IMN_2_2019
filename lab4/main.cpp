#include "main.h"


int main()
{

    unsigned n_x = 150;
    unsigned n_y = 100;

    double d = 0.1;

    double epsilon = 1.0;

    Array global_omegas;
    global_omegas.push_back(0.6);
    global_omegas.push_back(1.0);
    for(auto omega : global_omegas)
    {
        glob_rel(d, omega, n_x, n_y, epsilon);
    }

    Array local_omegas;
    local_omegas.push_back(1.0);
    local_omegas.push_back(1.4);
    local_omegas.push_back(1.8);
    local_omegas.push_back(1.9);

    for(auto omega : local_omegas)
    {
        loc_rel(d, omega, n_x, n_y, epsilon);
    }

}