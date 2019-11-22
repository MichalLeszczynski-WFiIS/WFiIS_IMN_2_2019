#include "main.h"

double rho(double x, double y, double x_max, double y_max)
{
    return rho_1(x, y, x_max, y_max) + rho_2(x, y, x_max, y_max);
}

double rho_1(double x, double y, double x_max, double y_max)
{
    return exp(-pow((x - 0.35*x_max)/(0.1*x_max),2) - pow((y - 0.5*y_max)/(0.1*y_max),2));
}

double rho_2(double x, double y, double x_max, double y_max)
{
    return -1.0*exp(-pow((x - 0.65*x_max)/(0.1*x_max),2) - pow((y - 0.5*y_max)/(0.1*y_max),2));
}

void fill_array_with(Array& A, double val)
{
    for(unsigned i = 0; i < A.size(); i++)
    {
        A[i] = val;
    }
}

void fill_matrix_with(Matrix& A, double val)
{
    for(unsigned i = 0; i < A.size(); i++)
    {
        for(unsigned j = 0; j < A[0].size(); j++)
        {
            A[i][j] = val;
        }
    }
}