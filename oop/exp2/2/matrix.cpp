#include "matrix.h"
#ifndef NULL
#define NULL 0
#endif


#include <cstring>
#include <iostream>

Matrix::Matrix() {
    lines = 0   ;
    rows  = 0   ;
    a     = NULL;
}

Matrix::Matrix(int lines, int rows) : lines(lines), rows(rows) {
    a   = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memset(a[i], 0, sizeof(int) * rows);
    }
}

Matrix::Matrix(const Matrix &b) {
    lines = b.lines;
    rows  = b.rows ;
    a     = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memcpy(a[i], b.a[i], sizeof(int) * rows);
    }
}

Matrix::~Matrix() {
    if (a) {
        for (int i = 0; i < lines; i++) {
            if (a[i]) {
                delete[] a[i];
            }
        }
        delete[] a;
    }
}

int Matrix::input() {
    using std::cin;
    if (a == NULL) return -1;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < rows; j++) {
            if (a[i] == NULL) return -1;
            cin >> a[i][j];
        }
    }
    return 0;
}

int Matrix::output() {
    using std::cout;
    using std::endl;
    if (a == NULL) return -1;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            if (j > 0) cout << '\t';
            if (a[i] == NULL) return -1;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}

Matrix Matrix::add(Matrix b) {
    Matrix rtn(lines, rows);
    if (lines != b.lines || rows != b.rows) {
        rtn.lines = -1;
        rtn.rows  = -1;
        return rtn;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < rows; j++) {
            rtn.a[i][j] = a[i][j] + b.a[i][j];
        }
    }
    return rtn;
}

Matrix Matrix::subtract(Matrix b) {
    Matrix rtn(lines, rows);
    if (lines != b.lines || rows != b.rows) {
        rtn.lines = -1;
        rtn.rows  = -1;
        return rtn;
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < rows; j++) {
            rtn.a[i][j] = a[i][j] - b.a[i][j];
        }
    }
    return rtn;
}

Matrix &Matrix::operator=(const Matrix &b) {
    if (this == &b) {
        return (*this);
    }
    if (a) {
        for (int i = 0; i < lines; i++) {
            if (a[i]) {
                delete[] a[i];
            }
        }
        delete[] a;
    }
    lines = b.lines;
    rows  = b.rows ;
    a     = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memcpy(a[i], b.a[i], sizeof(int) * rows);
    }
    return (*this);
}

int &Matrix::get(int rn, int cn) {
    return this->a[rn][cn];
}

int Matrix::getlines() const {
    return lines;
}

int Matrix::getrows() const {
    return rows;
}
