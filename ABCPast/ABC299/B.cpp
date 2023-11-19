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
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,T;
    cin >> N >> T;
    vector<int> C(N);
    vector<int> R(N);
    bool containsT = 0;
    rep(i,N) {
        cin >> C[i];
        if (C[i] == T) containsT = 1;
    }
    if (!containsT) T = C[0];
    rep(i,N){
        cin >> R[i];
    }
    int mx =0;
    int mxind = 0;
    rep(i,N){
        if (T==C[i]){
            if (R[i] > mx){
                mx = R[i];
                mxind = i;
            }
        }
    }
    cout << mxind+1 << endl;


}