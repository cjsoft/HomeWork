#ifndef INPUT_H
#define INPUT_H
const int MXN = 107;
void input(int[MXN][MXN], int&, int &);
template <typename T>
bool checkmax(T &a, T b);
template <typename T>
bool checkmin(T &a, T b);
template <typename T>
bool checkmax(T &a, T b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool checkmin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
#include "input.cpp"
#endif
