#include "main.h"

void loc_rel(double d, double omega, unsigned n_x, unsigned n_y, double epsilon)
{
    double V_1 = 10;
    // double V_2 = 0;

    std::ofstream file;
    file.open("loc_rel_s_omega_" + std::to_string(omega) + ".dat");

    Matrix V;
    for(unsigned i=0; i < n_x+1; i ++)
    {
        V.push_back(Array(n_y+1));
    }
    fill_matrix_with(V, 0);
    fill_array_with(V[0], V_1);

    Array S = {};
    S.push_back(1);

    double TOL = 1e-8;
    double sum;

    unsigned it = 0;
    while(true)
    {

        // 1st step
        for(unsigned i = 1; i <= n_x - 1; i++)
        {
            for(unsigned j = 1; j <= n_y - 1; j++)
            {
                V[i][j] = (1-omega)*V[i][j] + omega/4*(V[i+1][j] + V[i-1][j] + V[i][j-1] + d*d/epsilon*rho_1(d*i, d*j, d*n_x, d*n_y));
            }   
        }

        // 2nd step
        for(unsigned j = 1; j <= n_y - 1; j++)
        {
            V[0][j] = V[1][j];
        }

        for(unsigned j = 1; j <= n_y - 1; j++)
        {
            V[n_x][j] = V[n_x-1][j];
        }

        sum = 0.0;
        for(unsigned i=0; i <= n_x-1; i++)
        {
            for(unsigned j=0; j <= n_y-1; j++)
            {
                sum += d*d*(0.5*pow(((V[i+1][j]-V[i][j])/d),2) + 0.5*pow(((V[i][j+1]-V[i][j])/d),2) - rho_1(d*i, d*j, d*n_x, d*n_y)*V[i][j]);
            }
        }
        S.push_back(sum);
        file << it << " \t" << sum << std::endl;
        if(it > 0)
        {
            if(fabs(S[it]/S[it-1] - 1.0 ) < TOL) break; // ?????????
        }
        it++;
    }
    file.close();
}