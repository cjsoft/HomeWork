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
    for (int i = 2; i <= v; ++i) { // 初始化边界条件
        if (dp[1][i - 1] < arr[1][i]) {
            dp[1][i] = arr[1][i];
            revfinder[1][i] = make_pair(0, i - 1);
        } else {
            dp[1][i] = dp[1][i - 1];
            revfinder[1][i] = make_pair(1, i - 1);
        }
    }
    for (int j = 2; j <= v; ++j) {  // 状态转移，记下转移来源
        for (int i = 2; i <= j; ++i) {
            if (checkmax(dp[i][j], dp[i - 1][j - 1] + arr[i][j])) {
                revfinder[i][j] = make_pair(i - 1, j - 1);
            }
            if (checkmax(dp[i][j], dp[i][j - 1])) {
                revfinder[i][j] = make_pair(i, j - 1);
            }
        }
    }
}
void output() { // 方案输出
    PII tmp = make_pair(f, v);
    while (tmp.first && tmp.second) {
        PII rtmp = revfinder[tmp.first][tmp.second];
        if (rtmp.first == tmp.first - 1 && rtmp.second == tmp.second - 1) {
            printf("Put flower %d in vase %d.\n", tmp.first, tmp.second);
        }
        tmp = rtmp;
    }
}
int main() {
    input(arr, f, v);               // 读入数据
    work();
    printf("%d\n", dp[f][v]);       // 结果
    for (int i = 1; i <= f; ++i) {  // 输出最后的dp数组
        for (int j = 1; j <= v; ++j) {
            printf("%4d ", dp[i][j]);
        }
        putchar('\n');
    }
    output();                       // 输出方案
}
