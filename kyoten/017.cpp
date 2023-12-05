#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

/* accelration */
// 高速バイナリ生成
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    long double T,L,X,Y;
    int Q;
    cin >> T >> L >> X >> Y;
    cin >> Q;
    while(Q--){
        long double E;
        cin >> E;
        long double y,z; // current position;
        y = L*sin(-2*M_PI*E/T)/2;
        z = L*cos(M_PI - 2*M_PI*E/T)/2 + L/2;
        // horizontal distance
        long double h_dist = sqrt(X*X+(Y-y)*(Y-y));
        long double v_dist = z;
        if (h_dist == 0) cout << (long double) 0 << endl;
        else printf("%.12Lf\n", (long double) 360 * atan(v_dist / h_dist) / (2 * M_PI));
    }
}