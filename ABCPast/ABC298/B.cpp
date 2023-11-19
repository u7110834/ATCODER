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
    int N;
    cin >> N;
    int A[N][N],B[N][N];
    int op = 4;

    rep(i,N) rep(j,N){
        cin >> A[i][j];
    }
    rep(i,N) rep(j,N){
        cin >> B[i][j];
    }
    bool can = false;
    while(op--){
        int newA[N][N];
        rep(i,N) rep(j,N){
            newA[i][j] = A[N-1-j][i];
        }
        bool ok = true;
        rep(i,N)rep(j,N){
            if (newA[i][j] && newA[i][j] != B[i][j]){
                ok = false;
            }
        }
        if (ok){
            can = true;
            break;
        }

        rep(i,N) rep(j,N){
            A[i][j] = newA[i][j];
        }
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}