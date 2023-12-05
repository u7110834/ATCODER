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

ll dp[101][101][101];
int main()
{   
    memset(dp,0,sizeof(dp));
    const ll modint = 998244353;
    // sum % numofA = 0
    //dp use or not use
    // dp[1...100][N = 1...100][i], where i = 0... N-1, = num of pairs % modint
    // dp[1...100][N][i][num] = 
    // use : dp[k-1][N][{i+N-A,j}] not use: (non if k = N) dp[k-1][N][i]
    
    int N; cin >> N;
    vector<int> a(N+1);
    rep1(i,N) cin >> a[i];
    
    // initialize dp 
    // pick just one number
    for (int i = 1; i <= N; i++) dp[i][1][0] = i;
    for (int k = 2; k <= N; k++){ 
        for (int n = 2; n <= N; n++){
            ll amodn = a[k] % n;
            for (int rem = 0; rem < n; rem++){
                // use  
                ll last_rem = (rem+n-amodn) % n;
                dp[k][n][rem] = dp[k-1][n][last_rem];
                // not use 
                dp[k][n][rem] = (dp[k][n][rem] % modint + dp[k-1][n][rem] % modint) % modint; 
            }
        }
    }

    ll ans = 0;
    for (int n = 1; n <= N; n++){
        ans = (ans % modint + dp[N][n][0] % modint) % modint;

    }

    cout << ans -1 << endl;
}