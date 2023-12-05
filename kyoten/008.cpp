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

constexpr ll mod = 1000000007;
int main()
{   
    int N;
    cin >> N;
    
    string s;
    cin >> s;

    ll dp[N+1][7+1];
    memset(dp,0LL,sizeof(dp));

    string want = "atcoder";

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++){
        dp[i][0] = 1;
        char c = s[i-1];
        for (int j = 1; j <= 7; j++){
            dp[i][j] = dp[i-1][j];
            if (c ==  want[j-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            }
        }
    }
    cout << dp[N][7] << endl;
}