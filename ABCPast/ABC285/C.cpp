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
    string s;
    cin >> s;
    int N = s.size();
    //reverse(s.begin(),s.end());
    lint ans = 0;
    lint total = 26;
    vector<lint> sum(N,1);
    for (int i = 1; i < N; i++){
        sum[i] = total;
        total *=26;
    }
    // go back;
    for (int i = N; i >= 1; i--){
        char c = s[N-i];
        int num = c-'A'+1;
        ans += (lint) sum[i-1]*num;
    }
    cout << ans << endl;
}