#ifndef MATRIX_H
#define MATRIX_H


typedef int (*matrix)[5];                           // 类型定义
inline int &AccessMatrix(matrix m, int rn, int cn); // 访问矩阵m中第rn行第cn列的元素（并没有使用这个函数，因为可以直接用m[rn][cn]的方式实现相同的效果）
void AllocMatrixMemory(matrix &p);                  // 为矩阵m分配空间
int Input(matrix m);                                // 从控制台中输入元素到m中
int Output(matrix m);                               // 打印矩阵m到控制台
int Add(matrix dest, matrix a, matrix b);           // 将a+b的结果存入矩阵dest
int Subtract(matrix dest, matrix a, matrix b);      // 将a-b的结果存入矩阵dest

#endif
