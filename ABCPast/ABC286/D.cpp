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
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    // dp
    int N,X;
    cin >> N >> X;
    vector<int> A(N),B(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    bool dp[N+1][X+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++){ // coin type
        int c = A[i]; // coin price
        for (int p = 0; p <= X; p++){ // price <= X
            for (int cnum = 0; cnum <= B[i]; cnum++) { // coin num
                if (p - c*cnum >= 0){
                    if (dp[i][p-c*cnum]) {
                        dp[i+1][p] = 1;
                        continue;
                    }
                }
            }
        }
    }
    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
} 