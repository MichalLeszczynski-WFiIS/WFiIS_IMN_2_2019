#include "main.h"

void wielo_rel(Matrix& V, double d, unsigned k, unsigned n_x, unsigned n_y)
{


    std::ofstream file_s;
    file_s.open("wielo_rel_s_k_" + std::to_string(k) + ".dat");

    std::ofstream file_v;
    file_v.open("wielo_rel_v_k_" + std::to_string(k) + ".dat");

    Array S = {};
    S.push_back(1e-8);

    double TOL = 1e-8;
    double sum;

    unsigned it = 0;
    while(true)
    {

        for(unsigned i = k; i <= n_x - 1; i += k)
        {
            for(unsigned j = k; j <= n_y - 1; j += k)
            {
                V[i][j] = 0.25*(V[i+k][j] + V[i-k][j] + V[i][j+k] + V[i][j-k]);
            }   
        }

        sum = 0;
        for(unsigned i=0; i <=n_x-1; i+=k)
        {
            for(unsigned j=0; j <= n_y-1; j+=k)
            {
                sum += (k*d)*(k*d)/2*(pow(((V[i+k][j]-V[i][j])/(d*2*k) + (V[i+k][j+k]-V[i][j+k])/(d*2*k)),2) + pow(((V[i][j+k]-V[i][j])/(d*2*k) + (V[i+k][j+k]-V[i+k][j])/(d*2*k)),2));
            }
        }
        S.push_back(sum);
        file_s << it << " \t" << sum << std::endl;
        if(it > 0)
        {
            if(fabs(S[it]/S[it-1] - 1.0 ) < TOL) break;
        }        
        it++;
    }


    for(unsigned i=0; i <= n_x; i+=k)
        {
            for(unsigned j=0; j <= n_y; j+=k)
            {
                file_v << d*i << " " << d*j << " " << V[i][j] << std::endl;
            }
        }


    file_s.close();
    file_v.close();

    // Zageszczenie siatki
    if(k != 1)
    {
        for(unsigned i=0; i < n_x; i+=k)
        {
            for(unsigned j=0; j < n_y; j+=k)
            {
                V[i + k/2][j+k/2] = 0.25 * (V[i][j] + V[i+k][j] + V[i][j+k] + V[i+k][j+k]);
                V[i+k][j+k/2] = 0.5 * (V[i+k][j] + V[i+k][j+k]);
                V[i+k/2][j+k] = 0.5 * (V[i][j+k] + V[i+k][j+k]);
                V[i+k/2][j] = 0.5 * (V[i][j] + V[i+k][j]);
                V[i][j+k/2] = 0.5 * (V[i][j] + V[i][j+k]);
            }
        }
    }
}