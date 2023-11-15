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
    int N, X;
    cin >> N >> X;
    vector<int> A(N-1);
    rep(i,N-1) cin >> A[i];
    sort(A.begin(),A.end());
    int current = 0;
    for (int i = 0; i< N-2; i++){
        current+=A[i];
    }
    int mn = A[0];
    int mx =  A[N-2];
    int req =  X-current;
    if (req <= 0){cout << 0 << endl;}
    else if (req+A[0] < mn || req+A[0] > mx) cout << -1 << endl;
    else cout << req+A[0] << endl;
}