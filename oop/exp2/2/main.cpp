#include "matrix.h"
#include <iostream>
#define PROMPT_LINES_INPUT "请输入行数:"
#define PROMPT_ROWS_INPUT  "请输入列数:"
#define TOSTR(a)           TOSTR_(a)
#define TOSTR_(a)          #a
#define CMB(a,b,c)         a##b##c
#define PROMPT_INPUT(a)    CMB(请为_,a,_输入元素:) // 中文直接连接会出错,原因不明
#define PROMPT_A1PA2       "A1+A2 ="
#define PROMPT_A1SA2       "A1-A2 ="
using namespace std;
int lines, rows;
int main() {
    /* 输入行数和列数 */
    cout << PROMPT_LINES_INPUT;
    cin  >> lines;
    cout << PROMPT_ROWS_INPUT;
    cin  >> rows;

    /* 声明变量 */
    Matrix A1(lines, rows), A2(lines, rows), A3;

    /* 输入元素 */
    cout << TOSTR(PROMPT_INPUT(A1)) << endl;
    A1.input();
    cout << TOSTR(PROMPT_INPUT(A2)) << endl;
    A2.input();

    /* 计算 */
    A3 = A1.add(A2);
    cout << PROMPT_A1PA2 << endl;
    A3.output();

    A3 = A1.subtract(A2);
    cout << PROMPT_A1SA2 << endl;
    A3.output();

    /* 声明并分配空间 */
    Matrix *pA1, *pA2, *pA3;
    pA1 = new Matrix(lines, rows);
    pA2 = new Matrix(lines, rows);
    pA3 = new Matrix(lines, rows);
    
    /* 输入元素 */
    cout << TOSTR(PROMPT_INPUT(A1)) << endl;
    pA1->input();

    cout << TOSTR(PROMPT_INPUT(A2)) << endl;
    pA2->input();

    /* 计算 */
    *pA3 = pA1->add(*pA2);
    cout << PROMPT_A1PA2 << endl;
    pA3->output();

    *pA3 = pA1->subtract(*pA2);
    cout << PROMPT_A1SA2 << endl;
    pA3->output();

    /* 释放空间 */
    delete pA1;
    delete pA2;
    delete pA3;

    return 0;
}


