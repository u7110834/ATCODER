#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

// include <atcoder/all>
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

int main()
{   
    int N;
    cin >> N;
    vector<pair<int,int>> win(N);
    rep(i,N){
        string s;
        cin >> s;
        win[i] = {i,count(s.begin(),s.end(),'o')};
    }
    auto cmp = [](pair<int,int> a, pair<int,int> b){
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    };
    
    sort(win.begin(),win.end(),cmp);
    vector<int> ans(N);
    for (int i = 0 ; i < N; i++) cout << win[i].first+1 << " \n"[i == N-1];
}