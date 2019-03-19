#ifndef MATRIX_H
#define MATRIX_H


typedef int* matrix;
inline int &AccessMatrix(matrix m, int rn, int cn);
void AllocMatrixMemory(matrix &p);
int Input(matrix m);
int Output(matrix m);
int Add(matrix dest, matrix a, matrix b);
int Subtract(matrix dest, matrix a, matrix b);

#include "matrix.cpp"
#endif
