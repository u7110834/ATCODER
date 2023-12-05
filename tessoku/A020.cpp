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
    int N;
    cin >> N;
    vector<int> p(N), A(N);
    rep(i,N) cin >> p[i] >> A[i];
    
    int dp[N][N]; // left right
    memset(dp,0,sizeof(dp));
    dp[0][N-1] = 0; // initial condition 
    for (int l = 0; l < N; l++){
        for (int r = N-1; r >= 0; r--){
            if (r < l) break;
            if (l > 0) {
                dp[l][r] = dp[l-1][r];
                if (l+1 <= p[l-1] && p[l-1] <= r+1) dp[l][r]+= A[l-1];
            }
            if (r < N-1) {
                int another = dp[l][r+1];
                if (l+1 <= p[r+1] && p[r+1] <= r+1) another += A[r+1];
                chmax(dp[l][r], another);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        chmax(ans, dp[i][i]);
    }
    cout << ans << endl;
}