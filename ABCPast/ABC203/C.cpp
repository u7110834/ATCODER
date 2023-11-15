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

lint A[200010],B[200010]; // Use map instead
int main()
{   
    int N,K;
    cin >> N >> K;
    rep(i,N) {
        cin >> A[i] >> B[i];
    }
    lint cur = K;
    lint ans = 0;
    lint position = 0;

    rep(i,N){
        lint now  = cur-(A[i]-position);
        if (now < 0){
            ans += cur; 
            break;
        } else {
            ans += A[i]-position;
            position = A[i];
            cur = now;
            cur += B[i];
        }
    }
    cout << ans << endl;
}