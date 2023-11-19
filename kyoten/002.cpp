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
    int H, W;
    cin >> H >> W;
    int A[H][W];
    rep(i,H) rep(j,W){
        cin >> A[i][j];
    }
    int hsum[H],vsum[W];
    rep(i,H){
        int sum = 0;
        rep(j,W){
            sum += A[i][j];
        }
        hsum[i] = sum;
        
    }
    rep(j,W){
        int sum = 0;
        rep(i,H){
            sum += A[i][j];
        }
        vsum[j] = sum;
    }
    rep(i,H) {
        rep(j,W){
        cout << hsum[i] + vsum[j] - A[i][j];
        if (j != W-1) cout << " ";
        }
        cout << endl;
    }
}