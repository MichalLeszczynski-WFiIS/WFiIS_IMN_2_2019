#include "main.h"
#include "mgmres.h"

template<typename T>
void fill_array_with(std::vector<T>& A, T val)
{
    for(unsigned i = 0; i < A.size(); i++)
    {
        A[i] = val;
    }
}

void algebr_poisson(unsigned n_x, unsigned n_y, double V_1, double V_2, double V_3, double V_4, bool rho_is_zero, double e_1, double e_2)
{

    double d = 0.1;

    double x_max = d*n_x;
    double y_max = d*n_y;


    unsigned N = (n_x+1)*(n_y+1);

    double* a = new double[5*N];
    int* ja = new int[5*N];
    int* ia = new int[N+1];

    for(int i=0; i < N+1; i++)
    {
        ia[i] = -1;
    }    

    double* b = new double[N];
    double* V = new double[N];

    int i, j;

    Array e(N + n_x + 1);
    for(unsigned l=0; l < N + n_x + 1; l ++)
    {
        j = floor(l/(n_x - 1));
        i = l - j*(n_x+1);

        e[l] = i<=n_x/2 ? e_1 : e_2;
    }

    int k = -1;

    int brzeg;
    double vb;
    double x,y;
    int nz_num;

    for(unsigned l=0; l < N; l++) 
    {   


        j = floor(l/(n_x - 1));
        i = l - j*(n_x+1);


        brzeg = 0;
        vb = 0.;

        if(i==0) 
        {
            brzeg=1;
            vb=V_1;
        }

        if(j == n_y)
        {
            brzeg=1;
            vb=V_2;
        }

        if(i==n_x)
        {
            brzeg=1;
            vb=V_3;
        }

        if(j==0)
        {
            brzeg=1;
            vb=V_4;
        }

        x = i*d;
        y = j*d;

        b[l]= rho_is_zero ? 0 : -1.0*rho(x, y, x_max, y_max);

        if(brzeg==1)
        {
            b[l] = vb;
        }

        ia[l] = -1;

        if(l-n_x-1 >=0 && brzeg==0)
        {
            k++;
            if(ia[l]<0) {ia[l]=k;}
            a[k]= e[l] / (d*d);
            ja[k] = l - n_x - 1;
        }

        if(l-1 >=0 && brzeg==0)
        {
            k++;
            if(ia[l]<0) {ia[l]=k;}
            a[k]= e[l] / (d*d);
            ja[k] = l - 1;
        }

        k++;
        if(ia[l]<0) {ia[l]=k;}
        if(brzeg==0)
        {a[k]=-(2*e[l]+e[l+1]+e[l+n_x+1])/(d*d);}
        else
        {a[k]=1;}
        ja[k] = l;

        if(l<N && brzeg==0)
        {
            k++;
            a[k]= e[l+1] /(d*d);
            ja[k]=l+1;
        }       

        if(l<N-n_x-1 && brzeg==0)
        {
            k++;
            a[k] = e[l+n_x+1]/(d*d);
            ja[k] = l+n_x +1;
        } 
    }

    nz_num=k+1;
    ia[N]=nz_num;

    std::ofstream file_a;
    file_a.open("macierz_a_" + std::to_string(n_x) + "_" + std::to_string(e_1) + "_" + std::to_string(e_2) + ".dat");

    std::ofstream file_b;
    file_b.open("wektor_B_" + std::to_string(n_x) + "_" + std::to_string(e_1) + "_" + std::to_string(e_2) + ".dat");

    for(unsigned l=0; l < N; l++) 
    {

        j = floor(l/(n_x - 1));
        i = l - j*(n_x+1);

        file_a << l << " " << i << " " << j << " " << a[l] << std::endl;
        file_b << l << " " << i << " " << j << " " << b[l] << std::endl;
    }

    file_a.close();
    file_b.close();





    int itrmax= 500;
    int mr= 500;
    double tolabs= 10e-8;
    double tolrel= 10e-8;

    pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, itrmax, mr, tolabs, tolrel);


    delete[] a;
    delete[] ia;
    delete[] ja;
    delete[] b;
    delete[] V;

}
