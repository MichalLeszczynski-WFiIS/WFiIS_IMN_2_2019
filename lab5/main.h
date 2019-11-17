#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

typedef std::vector<double> Array;
typedef std::vector<std::vector<double>> Matrix;

void fill_array_with(Array& A, double val);
void fill_matrix_with(Matrix& A, double val);
void wielo_rel(Matrix& V, double d, unsigned k, unsigned n_x, unsigned n_y);


