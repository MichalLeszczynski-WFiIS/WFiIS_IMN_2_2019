#include "main.h"

int main()
{

    unsigned n_x, n_y;

    double e_1, e_2;

    double V_1, V_2, V_3, V_4;

    bool rho_is_zero;

// pkt. 5
    n_x = n_y = 4;
    e_1 = e_2 = 1;
    V_1 = V_3 = 10;
    V_2 = V_4 = -10;
    rho_is_zero = true;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

    n_x = n_y = 50;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

    n_x = n_y = 100;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

    n_x = n_y = 200;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

// pkt. 6

    n_x = n_y = 100;
    V_1 = V_2 = V_3 = V_4 = 0;
    rho_is_zero = false;
    e_1 = e_2 = 1;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

    e_1 = 1;
    e_2 = 2;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);

    e_1 = 1;
    e_2 = 10;

    algebr_poisson(n_x, n_y, V_1, V_2, V_3, V_4, rho_is_zero, e_1, e_2);


}