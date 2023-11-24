#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
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
    vector<int> A(N), B(M),C;
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    C.insert(C.end(), A.begin(),A.end()); 
    C.insert(C.end(),B.begin(),B.end());

    sort(C.begin(),C.end());
    // binary search
    rep(i,N){
        auto it = lower_bound(C.begin(),C.end(),A[i]);
        cout << distance(C.begin(),it) +1 << " ";
    }
    cout << endl;
    rep(i,M){
        auto it = lower_bound(C.begin(),C.end(),B[i]);
        cout << distance(C.begin(),it) +1 << " ";
    }

    // cout << endl;
    // vector<int> idx(N+M);
    // iota(idx.begin(),idx.end(),0);
    // auto comp = [&](int i, int j){
    //     return C[i] < C[j];
    // };
    // sort(idx.begin(),idx.end(),comp);
    // rep(i,N){
    //     auto it = lower_bound(idx.begin(),idx.end(),i);
    //     cout << distance(idx.begin(), it)+1 << " "; // need to be sorted
    // }
    // cout << endl;

    // rep(i,M){
    //     auto it = lower_bound(idx.begin(),idx.end(),i+N);
    //     cout << distance(idx.begin(), it)+1 << " ";
    // }
    // cout << endl;
}