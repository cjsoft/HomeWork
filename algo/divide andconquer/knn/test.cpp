#include <bits/stdc++.h>

using namespace std;

int sarr[107];

int partition(int l, int r) {
    int tl = l, tr = r;
    int p = r;
    while (tl < tr) {
        while (tl < tr && sarr[tl] < sarr[p]) ++tl;
        while (tl < tr && !(sarr[tr] < sarr[p])) --tr;
        swap(sarr[tl], sarr[tr]);
    }
    swap(sarr[tl], sarr[p]);
    return tl;
}
void cutK(int l, int r, int k) {
    if (r - l + 1 <= k) return;
    int m = partition(l, r);
    if (m - l + 1 == k) return;
    if (m - l + 1 < k) {
        cutK(m + 1, r, k - (m - l + 1));
    } else {
        cutK(l, m - 1, k);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", sarr + i);
    }
    int m;
    while (1) {
        scanf("%d", &m);
        cutK(0, n - 1, m);
        for (int i = 0; i < n; ++i) {
            printf("%d ", sarr[i]);
        }
        putchar('\n');
    }
    return 0;
}
