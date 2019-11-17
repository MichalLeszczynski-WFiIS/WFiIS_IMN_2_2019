#include "main.h"

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