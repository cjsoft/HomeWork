#include "matrix.h"
#ifndef NULL
#define NULL 0
#endif


#include <cstring>
#include <iostream>

Matrix::Matrix() {                                                  // 初始化，啥都没有
    lines = 0   ;
    rows  = 0   ;
    a     = NULL;
}

Matrix::Matrix(int lines, int rows) : lines(lines), rows(rows) {    // 初始化，分配空间，两级结构
    a   = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memset(a[i], 0, sizeof(int) * rows);
    }
}

Matrix::Matrix(const Matrix &b) {                                   // 拷贝构造，分配空间
    lines = b.lines;
    rows  = b.rows ;
    a     = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memcpy(a[i], b.a[i], sizeof(int) * rows);
    }
}

Matrix::~Matrix() {                                                 // 析构，先释放每一行，再释放行索引
    if (a) {
        for (int i = 0; i < lines; i++) {
            if (a[i]) {
                delete[] a[i];
            }
        }
        delete[] a;
    }
}

int Matrix::input() {                                               // 输入
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

int Matrix::output() {                                              // 输出
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

Matrix Matrix::add(Matrix b) {                                      // 相加，如果形状不等，返回非法矩阵
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

Matrix Matrix::subtract(Matrix b) {                                 // 相减，同上
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

Matrix &Matrix::operator=(const Matrix &b) {                        // 赋值运算符
    if (this == &b) {                                               // 自赋值检查
        return (*this);
    }
    if (a) {                                                        // 释放旧元素
        for (int i = 0; i < lines; i++) {
            if (a[i]) {
                delete[] a[i];
            }
        }
        delete[] a;
    }
    lines = b.lines;                                                // 同化，并分配新内存
    rows  = b.rows ;
    a     = new int* [lines];
    for (int i = 0; i < lines; i++) {
        a[i] = new int[rows];
        memcpy(a[i], b.a[i], sizeof(int) * rows);                   // 拷贝数据过去
    }
    return (*this);
}

int &Matrix::get(int rn, int cn) {                                  // 用于外部访问的getter
    return this->a[rn][cn];
}

int Matrix::getlines() const {                                      // lines的getter
    return lines;
}

int Matrix::getrows() const {                                       // rows的getter
    return rows;
}
