#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
        int lines, rows;
        int **a;
public:
    Matrix();
    Matrix(int lines, int rows);
    Matrix(const Matrix &b);

    ~Matrix();

    int input();
    int output();

    int &get(int rn, int cn);
    int getlines() const;
    int getrows() const;

    Matrix add(Matrix b);
    Matrix subtract(Matrix b);

    Matrix &operator=(const Matrix &b);
};


#include "matrix.cpp"
#endif
