#include <bits/stdc++.h>
#ifndef MXCSZ
 #define MXCSZ 1000007
#endif
#ifndef MXVSZ
 #define MXVSZ 7
#endif
#ifndef MXTYPE
 #define MXTYPE 20
#endif
#ifndef K
 #define K 20
#endif
using namespace std;

int n, veclength;
struct inputcase {

    vector<double> vec;
    int type;
} arr[MXCSZ];
struct sortcase {
    double distance;
    int type;
    bool operator<(const sortcase &b) const {
        return distance < b.distance;
    }
} sarr[MXCSZ];
double getdis(const vector<double> &a, const vector<double> &b) {
    double tmp = 0;
    for (int i = 0; i < veclength; ++i) {
        tmp += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(tmp);
}
int appeartime[MXTYPE];
int main() {
    scanf("%d %d", &n, &veclength);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < veclength; ++j) {
            double tmp;
            scanf("%lf", &tmp);
            arr[i].vec.push_back(tmp);
        }
        scanf("%d", &arr[i].type);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        memset(sarr, 0, sizeof(sarr));
        vector<double> tsc;
        for (int j = 0; j < veclength; ++j) {
            double tmp;
            scanf("%lf", &tmp);
            tsc.push_back(tmp);
        }
        for (int j = 0; j < n; ++j) {
            sarr[j].distance = getdis(arr[j].vec, tsc);
            sarr[j].type = arr[j].type;
        }
        memset(appeartime, 0, sizeof(appeartime));
        for (int j = 0; j < K; ++j) {
            appeartime[sarr[j].type]++;
        }
        int mxp = 0;
        for (int j = 1; j < MXTYPE; ++j) {
            if (appeartime[j] > appeartime[mxp]) {
                mxp = j;
            }
        }
        printf("%d\n", mxp);
    }
    return 0;
}
