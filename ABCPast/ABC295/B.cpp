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
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int R,C;
    cin >> R >> C;
    string ans[R];
    rep(i,R){
        cin >> ans[i];
    }
    rep(i,R)rep(j,C){
        if (ans[i][j] <= '9' && ans[i][j] > '0'){
            int b = ans[i][j] - '0';
            ans[i][j] = '.';
            rep(k,R) rep(l,C){
                if (abs(k-i) + abs(l-j) <= b){
                    if (ans[k][l] =='#'){
                        ans[k][l] = '.';
                    }
                }
            }
        }

    }

    rep(i,R){
        cout << ans[i] << endl;
    }
}