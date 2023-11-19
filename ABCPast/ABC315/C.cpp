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
    int N;
    cin >> N;
    vector<int> mxtaste(N,0);
    vector<vector<int>> tastes(N,vector<int>(2,0));

    rep(i,N){
        int f,s;
        cin >> f >> s;
        f--;
        chmax(mxtaste[f],s);
        tastes[f].push_back(s);
        sort(tastes[f].begin(),tastes[f].end());
        tastes[f].erase(tastes[f].begin());
    }

    int mx_ave = 0;

    for (auto ts : tastes){
        chmax(mx_ave,(ts[0]/2+ts[1]));
    }
    
    sort(mxtaste.rbegin(),mxtaste.rend());
    chmax(mx_ave,mxtaste[0]+mxtaste[1]);
    cout << mx_ave << endl;
}