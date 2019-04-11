#include <bits/stdc++.h>

#define MXN 100007

using namespace std;

unsigned long long cnt, cpnt;

int arr[MXN];

inline void init() {
    cnt = 0;
    cpnt = 0;
}
int cmp(int a, int b) {
    cpnt++;
    if (a < b) return -1;
    if (a == b) return 0;
    if (a > b) return 1;
}

void swp(int &a, int &b) {
    swap(a, b);
    ++cnt;
}

void store(int &a, int b) {
    a = b;
    ++cnt;
}

#ifdef QSORT
int partition(int seq[], int l, int r, int p) {
   swp(seq[r], seq[p]);
   int tl = l, tr = r;
   p = r;
   while (tl < tr) {
       while (tl < tr && cmp(seq[tl], seq[p]) == -1) ++tl;
       while (tl < tr && cmp(seq[tr], seq[p]) != -1) --tr;
       swp(seq[tl], seq[tr]);
   }
   swp(seq[r], seq[tl]);
   return tl;
}
void customSort(int seq[], int l, int r) { // 每次选择区间右端点作为参照
    if (l >= r) return;
    int m = partition(seq, l, r, r);
    customSort(seq, l, m - 1);
    customSort(seq, m + 1, r);
}
#endif

#ifdef MSORT
void merge(int seq[], int l, int m, int r)
{
    static int p = 1, tmparr[MXN] = { 0 };
    int pl = l, pr = m;
    int ql = m + 1, qr = r;

    while (pl <= pr || ql <= qr) {
        if ((ql > qr) || (pl <= pr && cmp(seq[pl], seq[ql]) != 1)) 
            store(tmparr[p++], seq[pl++]);
            /* tmparr[p++] = seq[pl++]; */
        else
            store(tmparr[p++], seq[ql++]);
            /* tmparr[p++] = seq[ql++]; */
    }
    while (l <= r)
        store(seq[r--], tmparr[--p]);
        /* seq[r--] = tmparr[--p]; */
}

void customSort(int seq[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    customSort(arr, l, m);
    customSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
#endif

#ifdef ISORT

void customSort(int seq[], int l, int r) {
    int tmp;
    for (int i = l, j; i <= r; ++i) {
        if (cmp(seq[i], seq[i - 1] == -1)) {
            store(tmp, seq[i]);
            /* tmp = seq[i]; */
            for (j = i; j > l && cmp(seq[j - 1], tmp) == 1; --j)
                store(seq[j], seq[j - 1]);
                /* seq[j] = seq[j - 1]; */
            store(seq[j], tmp);
            /* seq[j] = tmp; */
        }
    }
}

#endif

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    customSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
    printf("%14llu %14llu", cnt, cpnt);
    return 0;
}
