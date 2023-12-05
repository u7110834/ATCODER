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
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    ll D;
    cin >> D;
    int mx_x = 2e6;
    // assume x <= y;
    ll mn = 1LL << 60;
    rep1(x, mx_x){
        ll x_sq= (ll) x*x;
        ll rem = D - x_sq;
        if (rem <= 0){
            chmin(mn, abs(rem));
            break;
        }
        int hi = 2e6;
        int lo = 0;
        while (hi - lo > 1){
            int mid = (hi+lo)/2;
            ll midsq = (ll) mid*mid;
            //cout << midsq << endl;
            if (midsq <= rem){
                lo = mid;
            } else {
                hi = mid;
            }
        }
        //cout << x << endl;
        // cout << hi*hi << endl;
        // cout << lo*lo << endl;
        chmin(mn, abs(D - (ll) hi*hi - (ll) x_sq));
        chmin(mn, abs(D - (ll) lo*lo - (ll) x_sq));
    }
    cout << mn << endl;
}