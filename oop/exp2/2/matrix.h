/*
 * 具体解释请看matrix.cpp
 */
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
        int lines, rows;
        int **a;
public:
    Matrix();
    Matrix(int lines, int rows);    // 构造函数
    Matrix(const Matrix &b);        // 拷贝构造函数

    ~Matrix();                      // 析构函数

    int input();
    int output();                   // 输入输出

    int &get(int rn, int cn);       // 行列元素的getter
    int getlines() const;           // 行数getter
    int getrows() const;            // 列数getter

    Matrix add(Matrix b);           // 矩阵相加相减（java like）
    Matrix subtract(Matrix b);

    Matrix &operator=(const Matrix &b); // 赋值重载
};


#endif
