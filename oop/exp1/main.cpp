#include "matrix.h"
#define TOSTR(a)           TOSTR_(a)
#define TOSTR_(a)          #a
#define CMB(a,b,c)         a##b##c
#define PROMPT_INPUT(a)    CMB(请为_,a,_输入元素:) // 中文直接连接会出错,原因不明
#define PROMPT_A1PA2       "A1+A2 ="
#define PROMPT_A1SA2       "A1-A2 ="

using namespace std;

int main() {
    /* 声明并分配空间 */
    matrix A1, A2, A3;
    AllocMatrixMemory(A1);
    AllocMatrixMemory(A2);
    AllocMatrixMemory(A3);

    /* 输入元素 */
    cout << TOSTR(PROMPT_INPUT(A1)) << endl;
    Input(A1);

    cout << TOSTR(PROMPT_INPUT(A2)) << endl;
    Input(A2);

    /* 计算并输出 */
    Add(A3, A1, A2);
    cout << PROMPT_A1PA2 << endl;
    Output(A3);

    Subtract(A3, A1, A2);
    cout << PROMPT_A1SA2 << endl;
    Output(A3);

    /* 释放空间 */
    delete A1;
    delete A2;
    delete A3;
}
