#include "matrix.h"


#include <cstring>
#include <iostream>

int &AccessMatrix(matrix m, int rn, int cn) {
    return m[rn][cn];
}

void AllocMatrixMemory(matrix &p) {
    p = new int[4][5];
    memset(p, 0, sizeof(int) * 20);     // 分配并清空内存
}

int Output(matrix m) {
    using std::cout;
    using std::endl;
    if (m == NULL) return -1;           // 如果没有分配内存，则失败
    for (int i = 0; i < 4; i++) {       // 输出循环
        for (int j = 0; j < 5; j++) {
            if (j > 0) {
                cout << "\t";
            }
            cout << m[i][j];
        }
        cout << endl;
    }
    return 0;
}

int Input(matrix m) {
    using std::cin;
    if (m == NULL) return -1;           // 输入，原理同输出
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }
    return 0;
}


int Add(matrix dest, matrix a, matrix b) {  // +
    if (dest == NULL || a == NULL || b == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            dest[i][j] = a[i][j] + b[i][j];
        }
    }
    return 0;
}

int Subtract(matrix dest, matrix a, matrix b) { // -
    if (dest == NULL || a == NULL || b == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            dest[i][j] = a[i][j] - b[i][j];
        }
    }
    return 0;
}
