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
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    string s;
    cin >> s;
    int N = s.size();
    // on or off dp
    vector dp(300010, vector<ll>(2));
    // init
    dp[1][0] = (ll) ((s[0] == 'a')? X : Y);
    dp[1][1] = Z+min(Y,X);
    for (int i = 2; i <= N; i++){ // off if 0
        dp[i][0] = min(dp[i-1][1] + Z + min(X,Y), dp[i-1][0] + ((s[i-1] == 'a')? X : Y) );
        dp[i][1] = min(dp[i-1][0] + Z + min(X,Y), dp[i-1][1] + ((s[i-1] == 'A')? X : Y) );
    }

    cout << min(dp[N][0],dp[N][1]) << endl;
}