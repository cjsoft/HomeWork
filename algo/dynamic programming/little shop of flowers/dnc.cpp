#include "input.h"
#include <bits/stdc++.h>
#define IMIN INT_MIN
using namespace std;

int arr[MXN][MXN], f, v;

int dnc(int fl, int fr, int vl, int vr) {
    if (fl > fr) return 0;
    if (fr - fl > vr - vl || vr < vl) {
        return IMIN;
    }
    if (fr - fl == vr - vl) {
        int rtn = 0;
        for (int i = fl, j = vl; i <= fr; ++i, ++j)
            rtn += arr[i][j];
        return rtn;
    }
    int m = (vl + vr) / 2;
    int rtn = IMIN;
    for (int i = 0; i <= fr - fl + 1; ++i) {
        int tl = dnc(fl, fl + i - 1, vl, m);
        if (tl == IMIN) continue;
        int tr = dnc(fl + i, fr, m + 1, vr);
        if (tr == IMIN) continue;
        checkmax(rtn, tl + tr);
    }
    return rtn;
}

int main() {
    input(arr, f, v);
    printf("%d\n", dnc(1, f, 1, v));
}