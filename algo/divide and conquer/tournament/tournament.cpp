#include <bits/stdc++.h>
#define MXN 107
using namespace std;

int n, days;
int arr[MXN * 3];
int vs[MXN][MXN];
void work(int n) {
    days = (n & 1) ? n : n - 1;
    for (int i = 0; i < days; ++i) {
        arr[i] = arr[i + days] = arr[i + days * 2] = i + 1;
    }
    for (int i = 0; i < days; ++i) {
        for (int j = 1; j <= days / 2; ++j) {
            vs[i][arr[days + i - j]] = arr[days + i + j];
            vs[i][arr[days + i + j]] = arr[days + i - j];
        }
    }
    if ((n & 1) == 0) {
        for (int i = 0; i < days; ++i) {
            vs[i][i + 1] = n;
            vs[i][n] = i + 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    work(n);
    printf("Player : ");
    for (int i = 1; i <= n; ++i) {
        printf("%4d", i);
    }
    putchar('\n');
    for (int i = 0; i < days; ++i) {
        printf("Day #%2d: ", i + 1);
        for (int j = 1; j <= n; ++j) {
            printf("%4d", vs[i][j]);
        }
        putchar('\n');
    }
}
