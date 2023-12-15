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
    int N,X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    vector<ll> sum(N,0), minB(N);

    rep(i,N) {
        cin >> A[i] >> B[i];
        sum[i] += (ll) A[i] + (ll) B[i];
        if (i != 0) sum[i] += (ll) sum[i-1];
    }
    
    minB[0] = B[0];  
    for (int i = 1; i < N; i++) {
        if (B[i] < minB[i-1]){
            minB[i] = B[i];
        } else minB[i] = minB[i-1];
    }
    // min elem of the first i Bs.
    ll ans = 1LL << 62;
    rep(i,N){
        ll total = 0;
        total += sum[i];
        int rem = X-i-1;
        total += (ll) rem*minB[i];
        chmin(ans,total);
    }
    cout << ans << endl;
}