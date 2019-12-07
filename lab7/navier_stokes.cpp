#include "main.h"

void navier_stokes(double Q_we)
{

    unsigned n_x = 200;
    unsigned n_y = 90;
    unsigned i_1 = 50;
    unsigned j_1 = 55;

    double rho = 1.0;
    double mi = 1.0;
    unsigned IT_MAX = 20000;
    double d = 0.01;


    Matrix Psi;
    for(unsigned i=0; i <= n_x; i ++)
    {
        Psi.push_back(Array(n_y+1));
    }
    fill_matrix_with(Psi, 0);

    Matrix Ksi;
    for(unsigned i=0; i <= n_x; i ++)
    {
        Ksi.push_back(Array(n_y+1));
    }
    fill_matrix_with(Ksi, 0);


    std::ofstream file_psi;
    file_psi.open("n_s_Psi_" + std::to_string(Q_we) + ".dat");

    std::ofstream file_ksi;
    file_ksi.open("n_s_Ksi_" + std::to_string(Q_we) + ".dat");



    Array y;
    for(unsigned j = 0; j <= n_y; j++)
    {
        y.push_back(j*d);
    }

        double Q_wy = Q_we * (pow(y[n_y], 3) - pow(y[j_1], 3) - 3*pow(y[n_y], 2)*y[j_1] + 3*pow(y[j_1],2)*y[n_y]) / (pow(y[n_y], 3));

    /// Poczatek
    bool on_border;
    double gamma;
    unsigned j_2 = j_1 + 2;
    unsigned omega;

    update_Psi(Psi, n_x, n_y, i_1, j_1, y, Q_we, Q_wy, mi);
    for(unsigned it = 1 ; it < IT_MAX; it++)
    {
        if(it < 2000)
        {
            omega = 0;
        }
        else
        {
            omega = 1;
        }
        for(unsigned i=1 ; i <= n_x - 1; i ++)
        {
            for(unsigned j = 0; j <= n_y - 1; j++)
            {
                on_border = (i==0) || (j==0) || (i==n_x) || (j==n_y) || (i<=i_1 && j==j_1) || (i==i_1 && j<=j_1); 
                if(!on_border)
                {
                    Psi[i][j] = 0.25*(Psi[i+1][j] + Psi[i-1][j] + Psi[i][j+1] + Psi[i][j-1] - d*d*Ksi[i][j]);
                    Ksi[i][j] = 0.25 * (Ksi[i+1][j] + Ksi[i-1][j] +Ksi[i][j+1] + Ksi[i][j-1]) - omega*rho/(16*mi) * ((Psi[i][j+1] - Psi[i][j-1])*(Ksi[i+1][j] - Ksi[i-1][j])  -  (Psi[i+1][j] - Psi[i-1][j])*(Ksi[i][j+1] - Ksi[i][j-1])); 
                }
            }
        }
        update_Ksi(Ksi, d, Psi, n_x, n_y, i_1, j_1, y, Q_we, Q_wy, mi);
        gamma = 0;
        for(unsigned i = 1; i <= n_x-1; i  ++)
        {
            gamma += (Psi[i_1][j_2] + Psi[i-1][j_2] + Psi[i][j_2+1] + Psi[i][j_2-1] - 4*Psi[i][j_2] - d*d*Ksi[i][j_2]);
        }
        std::cout << "it: " << it << " gamma:" << gamma << std::endl;
    }

    for(unsigned i = 0; i <= n_x; i++)
    {
        for(unsigned j = 0; j <= n_y; j++)
        {
            file_psi << d*i << " " << d*j << " " << Psi[i][j] << std::endl;
            file_ksi << d*i << " " << d*j << " " << Ksi[i][j] << std::endl;
        }
    }

    /// Koniec

        file_psi.close();
        file_ksi.close();

}

void update_Psi(Matrix& Psi, unsigned n_x, unsigned n_y, unsigned i_1, unsigned j_1, Array& y, double Q_we, double Q_wy, double mi)
{
    // Brzeg A
    for (unsigned j = j_1; j <= n_y; j ++)
    {
        Psi[0][j] = Q_we /(2*mi) * (y[j]*y[j]*y[j]/3 - y[j]*y[j]/2 * (y[j_1] + y[n_y]) + y[j]*y[j_1]*y[n_y]);
    }

    // Brzeg C
    for (unsigned j = 0; j <= n_y; j ++)
    {
        Psi[n_x][j] = Q_wy /(2*mi) * (y[j]*y[j]*y[j]/3 - y[j]*y[j]/2 * y[n_y]) + Q_we *y[j_1]*y[j_1] * (-y[j_1] + 3*y[n_y]) / (12*mi)  ;
    }

    // Brzeg B
    for(unsigned i = 1; i <= n_x-1; i++ )
    {
        Psi[i][n_y] = Psi[0][n_y];
    }

    // Brzeg D
    for(unsigned i = i_1; i <= n_x - 1; i ++)
    {
        Psi[i][0] = Psi[0][j_1];
    }

    // Brzeg E
    for(unsigned j = 1; j <= j_1; j ++)
    {
        Psi[i_1][j] = Psi[0][j_1];
    }

    // Brzeg F
    for(unsigned i = 1; i <= i_1; i ++)
    {
        Psi[i][j_1] = Psi[0][j_1];
    }
}

void update_Ksi(Matrix& Ksi, double d, Matrix& Psi, unsigned n_x, unsigned n_y, unsigned i_1, unsigned j_1, Array& y, double Q_we, double Q_wy, double mi)
{
    // Brzeg A
    for (unsigned j = j_1; j <= n_y; j ++)
    {
        Ksi[0][j] = Q_we /(2*mi) * (y[j]*2 - y[j_1] - y[n_y]);
    }

    // Brzeg C
    for (unsigned j = 0; j <= n_y; j ++)
    {
        Ksi[n_x][j] = Q_wy /(2*mi) * (2*y[j] - y[n_y]);
    }

    // Brzeg B
    for(unsigned i = 1; i <= n_x-1; i++ )
    {
        Ksi[i][n_y] = 2/(d*d) * (Psi[i][n_y - 1] - Psi[i][n_y]);
    }

    // Brzeg D
    for(unsigned i = i_1; i <= n_x - 1; i ++)
    {
        Ksi[i][0] = 2/(d*d) * (Psi[i][1] - Psi[i][0]);
    }

    // Brzeg E
    for(unsigned j = 1; j <= j_1; j ++)
    {
        Ksi[i_1][j] = 2/(d*d) * (Psi[i_1 + 1][j] - Psi[i_1][j]);
    }

    // Brzeg F
    for(unsigned i = 1; i <= i_1; i ++)
    {
        Ksi[i][j_1] = 2/(d*d) * (Psi[i][j_1 + 1] - Psi[i][j_1]);
    }

    // Wierzcholek E/F
    Ksi[i_1][j_1] = 0.5*(Ksi[i_1-1][j_1] + Ksi[i_1][j_1 - 1]);

}