#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

typedef std::vector<double> Array;
typedef std::vector<std::vector<double>> Matrix;

void fill_array_with(Array& A, double val);
void fill_matrix_with(Matrix& A, double val);

void navier_stokes(double Q_we);

void update_Psi(Matrix& Psi, unsigned n_x, unsigned n_y, unsigned i_1, unsigned j_1, Array& y, double Q_we, double Q_wy, double mi);
void update_Ksi(Matrix& Ksi, double d, Matrix& Psi, unsigned n_x, unsigned n_y, unsigned i_1, unsigned j_1, Array& y, double Q_we, double Q_wy, double mi);

