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
    int N,P,Q,R,S;
    cin >> N >> P >> Q >> R >> S;
    int len = Q-P+1;
    int A[N];
    int f[len];
    int s[len];
    rep(i,N){
        int a;
        cin >> a;
        A[i] = a;
        if (P-1 <= i && i <= Q-1){
            f[i-(P-1)] = a;
        }
        if (R-1 <= i && i <= S-1){
            s[i-(R-1)] = a;
        }
    }

    rep(i,N){
        if (P-1 <= i && i <= Q-1){
            cout << s[i-(P-1)] << " ";
        } else if (R-1 <= i && i <= S-1){
            cout << f[i-(R-1)] << " ";
        } else cout << A[i] << " ";
    }
    cout << endl;
}