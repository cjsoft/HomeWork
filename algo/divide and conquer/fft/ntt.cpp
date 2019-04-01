#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 998244353
#define PROOT 3
#define MXN 262147
using namespace std;
typedef long long ll;
ll qpow(ll x, int y) {
    ll rtn = 1;
    for (; y; y >>= 1) {
        if (y & 1) rtn = rtn * x % MOD;
        x = x * x % MOD;
    }
    return rtn;
}

void ntt(ll buffer[], int l, int flag) {
    static int bitrev[MXN];
    bitrev[0] = 0;
    int n = 1 << l;
    for (int i = 1; i < n; ++i) bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for (int i = 1; i < n; ++i) if (i < bitrev[i]) swap(buffer[i], buffer[bitrev[i]]);
    for (int i = 1; i < n; i <<= 1) {
        ll wn = (flag > 0) ? qpow(PROOT, (MOD - 1) / 2 / i) : qpow(PROOT, MOD - 1 - (MOD - 1) / 2 / i);
        for (int j = 0; j < n; j += i << 1) {
            ll w = 1;
            for (int k = 0; k < i; ++k, w = w * wn % MOD) {
                ll x = buffer[j + k], y = w * buffer[j + k + i] % MOD;
                buffer[j + k] = (x + y) % MOD; buffer[j + k + i] = (x - y + MOD) % MOD;
            }
        }
    }
    ll inv = qpow(n, MOD - 2);
    if (flag < 0) for (int i = 0; i < n; ++i) buffer[i] = buffer[i] * inv % MOD;
}
ll a[MXN], b[MXN];
int l1, l2, ans[MXN];
char i1[MXN], i2[MXN];
int main() {
    scanf("%s%s", i1, i2);
    l1 = strlen(i1); l2 = strlen(i2);
    for (int i = l1 - 1; i >= 0; --i) a[l1 - 1 - i] = i1[i] - '0';
    for (int i = l2 - 1; i >= 0; --i) b[l2 - 1 - i] = i2[i] - '0';
    int l = 0, s = 1;
    for (; s < l1 + l2 - 1; s <<= 1, ++l);
    ntt(a, l, 1);
    ntt(b, l, 1);
    for (int i = 0; i < s; ++i) a[i] = a[i] * b[i] % MOD;
    ntt(a, l, -1);
    int len = l1 + l2 - 1;
    for (int i = 0; i < len; ++i) {
        ans[i] = a[i];
    }
    for (int i = 0; i < len; ++i) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (ans[len]) {
        ans[len + 1] = ans[len] / 10;
        ans[len++] %= 10;
    }
    for (int i = len - 1; i >= 0; --i) putchar(ans[i] + '0');
    putchar('\n');
}
