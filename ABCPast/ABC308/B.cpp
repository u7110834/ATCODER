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
    int N,M;
    cin >> N >> M;
    vector<string> C(N);
    rep(i,N) cin >> C[i];
    vector<string> D(M);
    vector<int> P(M);
    map<string,int> mp;
    rep(i,M){
        cin >> D[i];
    }
    int P0;
    cin >> P0;
    rep(i,M) cin >> P[i];
    rep(i,M) mp.insert({D[i],P[i]});
    int sum;
    rep(i,N){
        if (mp.find(C[i]) == mp.end()){
            sum += P0;
        } else{
            sum += mp.at(C[i]);
        }
    }
    cout << sum << endl;
}