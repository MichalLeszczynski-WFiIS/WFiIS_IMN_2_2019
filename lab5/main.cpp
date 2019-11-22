#include "main.h"


int main()
{
    unsigned max_k = 16;

    unsigned n_x = 128/16;
    unsigned n_y = 128/16;

    double d = 0.2;

    double x_max = d*n_x*max_k;
    double y_max = d*n_y*max_k;

    std::vector<unsigned> ks;
    ks.push_back(16);
    ks.push_back(8);
    ks.push_back(4);
    ks.push_back(2);
    ks.push_back(1);

    // Inicjalizacja macierzy
    Matrix V;
    for(unsigned i=0; i < max_k*(n_x+1); i ++)
    {
        V.push_back(Array(max_k*(n_y+1)));
    }
    fill_matrix_with(V, 0);

    // Warunki brzegowe
    for(unsigned j = 0; j <= max_k*(n_y); j ++)
    {
        V[0][j] = sin(M_PI * d*j / y_max);
        V[n_x*max_k][j] = sin(M_PI * d*j / y_max);
    }
    for(unsigned i = 0; i <= max_k*(n_x); i ++)
    {
        V[i][n_y*max_k] = -1.0 * sin(2*M_PI * d*i / x_max);
        V[i][0] = sin(2*M_PI * d*i / x_max);
    }

    for(auto k : ks)
    {
        wielo_rel(V, d, k, n_x, n_y);
    }

}