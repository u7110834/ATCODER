#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
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
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,K,D;
    cin >> N >> K >> D;

    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector<int> mod_a(N);
    rep(i,N) mod_a[i] = a[i]%D;
    
    lint dp[N+1][D][K+1];
    memset(dp,-1LL,sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++){
        for (int m = 0; m < D; m++){
            for (int k = 0; k <= K; k++){
                if (k == 0){
                    if (m == 0) dp[i][m][k] = 0; 
                    else dp[i][m][k] = -1;
                    continue;
                }
                lint use_i,not_use_i;
                int prev_mod;
                if (m-mod_a[i-1] < 0) prev_mod = D+(m-mod_a[i-1]);
                else prev_mod = m-mod_a[i-1];

                if (dp[i-1][prev_mod][k-1] == -1) use_i = -1;
                else use_i = dp[i-1][prev_mod][k-1] + a[i-1];
                not_use_i = dp[i-1][m][k];

                dp[i][m][k] = max(use_i,not_use_i);
            }
        }
    }
    if (dp[N][0][K] == -1) cout << -1 << endl;
    else cout << dp[N][0][K] << endl;
}