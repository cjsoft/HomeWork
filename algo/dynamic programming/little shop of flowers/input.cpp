#include "input.h"
#include <bits/stdc++.h>


using namespace std;

void input(int arr[MXN][MXN], int &f, int &v) {
    scanf("%d %d", &f, &v);
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= v; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
}

