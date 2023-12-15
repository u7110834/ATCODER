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
    // dp
    ll mod = 998244353;
    int N,M,K; cin >> N >> M >> K;
    ll dp[55][2505];
    // dp[n][k],
    memset(dp,0,sizeof(dp));
    for (int k = 1; k <= M; k++){
        dp[1][k] = 1;
    }
    for (int n = 2; n <= N; n++){
        for (int k = 1; k <= K; k++){
            // dp[n][k] = sum [n-1][k-a] for 1<=a<= M with k - a >= 1
            for (int a = 1; a <= min(M,k-1); a++){
                dp[n][k] = (dp[n][k] + dp[n-1][k-a]) % mod;
            }
        }
    }


    ll ans = 0;
    for (int i = N; i <= K; i++){
        ans = (ans + dp[N][i]) % mod;
    }
    cout << ans << endl;
}