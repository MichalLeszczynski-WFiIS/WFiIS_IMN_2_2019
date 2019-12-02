#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
// #include "mgmres.c"

typedef std::vector<double> Array;
typedef std::vector<int> IArray;
typedef std::vector<std::vector<double>> Matrix;

template<typename T>
void fill_array_with(std::vector<T>& A, T val);

double rho(double x, double y, double x_max, double y_max);
double rho_1(double x, double y, double x_max, double y_max);
double rho_2(double x, double y, double x_max, double y_max);

void algebr_poisson(unsigned n_x, unsigned n_y, double V_1, double V_2, double V_3, double V_4, bool rho_is_zero, double e_1, double e_2);
