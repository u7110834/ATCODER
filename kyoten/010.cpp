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
    vector<int> c1(N,0), c2(N,0),c1_sum(N+1,0),c2_sum(N+1,0);
    rep(i,N){
        int c;
        cin >> c;
        int p;
        cin >> p;
        if (c == 1){
            c1[i] = p;
        } else c2[i] = p;
    }
    rep1(i,N){
        c1_sum[i] = c1_sum[i-1] + c1[i-1];
        c2_sum[i] = c2_sum[i-1] + c2[i-1];
    }
    
    int Q;
    cin >> Q;
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        cout << c1_sum[r]-c1_sum[l-1] << " ";
        cout << c2_sum[r] -c2_sum[l-1] << endl;
    }
}