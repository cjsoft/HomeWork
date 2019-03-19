#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    public:
        int lines, rows;
        int **a;
    Matrix();
    Matrix(int lines, int rows);
    Matrix(const Matrix &b);

    ~Matrix();

    int input();
    int output();

    Matrix add(Matrix b);
    Matrix subtract(Matrix b);

    Matrix &operator=(const Matrix &b);
};


#include "matrix.cpp"
#endif
