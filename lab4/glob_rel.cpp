#include "main.h"

void glob_rel(double d, double omega, unsigned n_x, unsigned n_y, double epsilon)
{
    double V_1 = 10;
    // double V_2 = 0;

    std::ofstream file_s;
    file_s.open("glob_rel_s_omega_" + std::to_string(omega) + ".dat");

    std::ofstream file_v;
    file_v.open("glob_rel_v_omega_" + std::to_string(omega) + ".dat");

    std::ofstream file_e;
    file_e.open("glob_rel_err_omega_" + std::to_string(omega) + ".dat");
    // Tablica gestosci
    Matrix rho_tab;
    for(unsigned i=0; i < n_x+1; i ++)
    {
        rho_tab.push_back(Array(n_y+1));
    }
    for(unsigned i=0; i <= n_x-1; i++)
        {
            for(unsigned j=0; j <= n_y-1; j++)
            {
            rho_tab[i][j] = rho(d*i, d*j, d*n_x, d*n_y);
            }
        }

    Matrix V_s;
    for(unsigned i=0; i < n_x+1; i ++)
    {
        V_s.push_back(Array(n_y+1));
    }
    fill_matrix_with(V_s, 0);
    // Warunki brzegowe
    for(unsigned i=0; i < n_x+1; i ++)
    {
        V_s[i][0] = V_1;
    }

    Matrix V_n;
    for(unsigned i=0; i < n_x+1; i ++)
    {
        V_n.push_back(Array(n_y+1));
    }
    fill_matrix_with(V_n, 0);

    for(unsigned i=0; i < n_x+1; i ++)
    {
        V_n[i][0] = V_1;
    }

    Array S = {};
    S.push_back(0);

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
                V_n[i][j] = 0.25*(V_s[i+1][j] + V_s[i-1][j] + V_s[i][j+1] + V_s[i][j-1] + d*d*rho_tab[i][j]/epsilon);
            }   
        }

        // 2nd step
        for(unsigned j = 0; j <= n_y ; j++)
        {
            V_n[0][j] = V_n[1][j];
        }

        for(unsigned j = 0; j <= n_y ; j++)
        {
            V_n[n_x][j] = V_n[n_x-1][j];
        }

        // 3rd step
        for(unsigned i = 0; i <= n_x ; i++)
        {
            for(unsigned j = 0; j <= n_y ; j++)
            {
                V_s[i][j] = (1-omega) * V_s[i][j] + omega * V_n[i][j]; //omega_g E (0,1]
            }   
        }

        sum = 0;
        for(unsigned i=0; i <= n_x-1; i++)
        {
            for(unsigned j=0; j <= n_y-1; j++)
            {
                sum += d*d*
                (
                    0.5*pow(((V_n[i+1][j]-V_n[i][j])/d),2)
                    + 
                    0.5*pow(((V_n[i][j+1]-V_n[i][j])/d),2) 
                    -
                    rho_tab[i][j]
                    *
                    V_n[i][j]
                );
            }
        }
        S.push_back(sum);
        file_s << it << " \t" << sum << std::endl;
        if(it > 0)
        {
            if(fabs(S[it]/S[it-1] - 1.0 ) < TOL ) break; // ?????????
        }        
        it++;
    }


    for(unsigned i=0; i <= n_x; i++)
        {
            for(unsigned j=0; j <= n_y; j++)
            {
                file_v << d*i << " " << d*j << " " << V_s[i][j] << std::endl;
            }
        }

    // error
    double error;
    for(unsigned i=1; i < n_x; i++)
        {
            for(unsigned j=1; j < n_y; j++)
            {
                error = ((V_n[i+1][j] - 2* V_n[i][j] + V_n[i-1][j]) / (d*d) + (V_n[i][j+1] - 2* V_n[i][j] + V_n[i][j-1]) / (d*d) )+ rho_tab[i][j]/epsilon;
                file_e << d*i << " " << d*j << " " << error << std::endl;
            }
        }

    file_s.close();
    file_v.close();
    file_e.close();


}