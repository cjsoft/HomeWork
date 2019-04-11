#include <bits/stdc++.h>
#include "input.h"
using namespace std;
typedef pair<int, int> PII;
int arr[MXN][MXN];
int dp[MXN][MXN];
PII revfinder[MXN][MXN];
int f, v;

void work() {
    dp[1][1] = arr[1][1];
    for (int j = 2; j <= v; ++j) {
        for (int i = 1; i <= j; ++i) {
            if (checkmax(dp[i][j], dp[i - 1][j - 1] + arr[i][j])) {
                revfinder[i][j] = make_pair(i - 1, j - 1);
            }
            if (checkmax(dp[i][j], dp[i - 1][j])) {
                revfinder[i][j] = make_pair(i - 1, j);
            }
            if (checkmax(dp[i][j], dp[i][j - 1])) {
                revfinder[i][j] = make_pair(i, j - 1);
            }
        }
    }
}

int main() {
    input(arr, f, v);
    work();
    printf("%d\n", dp[f][v]);
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= v; ++j) {
            printf("%4d", dp[i][j]);
        }
        putchar('\n');
    }
}
