#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MXN 262147
using namespace std;
struct comp {
    double R, I;
    comp() { R = I = 0.; }
    comp(double a, double b) { R = a; I = b; }
    comp operator+(comp b) { return comp(R + b.R, I + b.I); }
    comp operator-(comp b) { return comp(R - b.R, I - b.I); }
    comp operator*(comp b) { return comp(R * b.R - I * b.I, R * b.I + I * b.R); }
};
void fft(comp buffer[], int l, int flag) {
    const double pi = acos(-1);
    static int bitrev[MXN];
    int n = (1 << l);
    bitrev[0] = 0;
    for (int i = 1; i < n; ++i) bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for (int i = 1; i < n; ++i) if (i < bitrev[i]) swap(buffer[i], buffer[bitrev[i]]);
    for (int i = 1; i < n; i <<= 1) {
        comp wn(cos(pi / i), flag * sin(pi / i));
        for (int j = 0; j < n; j += i << 1) {
            comp w(1, 0);
            for (int k = 0; k < i; ++k, w = w * wn) {
                comp x = buffer[j + k], y = w * buffer[j + k + i];
                buffer[j + k] = x + y; buffer[j + k + i] = x - y;
            }
        }
    }
    if (flag < 0) for (int i = 0; i < n; ++i) buffer[i].R /= n;
}
char in1[MXN], in2[MXN];
int l1, l2;
int ans[MXN];
comp a[MXN], b[MXN];

int main() {
    scanf("%s", in1); scanf("%s", in2);
    l1 = strlen(in1); l2 = strlen(in2);
    for (int i = l1 - 1; i >= 0; --i) a[l1 - 1 - i].R = in1[i] - '0';
    for (int i = l2 - 1; i >= 0; --i) b[l2 - 1 - i].R = in2[i] - '0';
    int l = 0, n = 1;
    for (; n < l1 + l2 - 1; ++l, n <<= 1);
    fft(a, l, 1); fft(b, l, 1);
    for (int i = 0; i < n; ++i) a[i] = a[i] * b[i];
    fft(a, l, -1);
    for (int i = 0; i < l1 + l2 - 1; ++i) ans[i] = int(a[i].R + 0.5);
    int len = l1 + l2 - 1;
    for (int i = 0; i < len; ++i) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (ans[len]) {
        ans[len + 1] += ans[len] / 10;
        ans[len++] %= 10;
    }
    for (int i = len - 1; i >= 0; --i) putchar(ans[i] + '0');
    putchar('\n');
    return 0;
}
