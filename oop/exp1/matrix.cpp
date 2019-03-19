#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "matrix.h"


#include <cstring>
#include <iostream>

int &AccessMatrix(matrix m, int rn, int cn) {
    return m[5 * rn + cn];
}

void AllocMatrixMemory(matrix &p) {
    p = new int[20];
    memset(p, 0, sizeof(int) * 20);
}

int Output(matrix m) {
    using std::cout;
    using std::endl;
    if (m == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (j > 0) {
                cout << "\t";
            }
            cout << AccessMatrix(m, i, j);
        }
        cout << endl;
    }
    return 0;
}

int Input(matrix m) {
    using std::cin;
    if (m == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> AccessMatrix(m, i, j);
        }
    }
    return 0;
}


int Add(matrix dest, matrix a, matrix b) {
    if (dest == NULL || a == NULL || b == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            AccessMatrix(dest, i, j) = AccessMatrix(a, i, j) + AccessMatrix(b, i, j);
        }
    }
    return 0;
}

int Subtract(matrix dest, matrix a, matrix b) {
    if (dest == NULL || a == NULL || b == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            AccessMatrix(dest, i, j) = AccessMatrix(a, i, j) - AccessMatrix(b, i, j);
        }
    }
    return 0;
}
#endif
