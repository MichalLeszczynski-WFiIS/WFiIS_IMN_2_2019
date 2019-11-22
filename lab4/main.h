#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

typedef std::vector<double> Array;
typedef std::vector<std::vector<double>> Matrix;

double rho(double x, double y, double x_max, double y_max);
double rho_1(double x, double y, double x_max, double y_max);
double rho_2(double x, double y, double x_max, double y_max);
void fill_array_with(Array& A, double val);
void fill_matrix_with(Matrix& A, double val);
void glob_rel(double d, double omega, unsigned n_x, unsigned n_y, double epsilon);
void loc_rel(double d, double omega, unsigned n_x, unsigned n_y, double epsilon);


