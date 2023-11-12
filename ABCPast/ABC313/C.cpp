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
    int N;
    cin >> N;
    lint A[N];
    lint sum = 0;
    for (int i = 0;  i < N; i++) {
        int a;
        cin >> a;
        A[i] =a;
        sum += a;
    }
    lint mean  =  sum/N;
    lint above= 0;
    lint below = 0;
    for (int i = 0;  i < N; i++) {
        lint a = A[i];
        if (a > mean){
            above+= a-mean-1;}
        else {below += mean-a;}
    }
    lint ans = max(above,below);
    cout << ans << endl;
    return 0;
}