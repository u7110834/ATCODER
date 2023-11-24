#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

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
    int n  = 4;
    dsu d(n); // O(n)

    //三角形
    d.merge(0,1);
    d.merge(1,2);
    d.merge(2,0); 

    // if 0 and 3 belong to the same connected component
    cout << d.same(0,3) << endl; 
    
    cout << d.leader(1) << endl; // 1's parent
    cout << d.size(1) << endl; // size of connected component 1 belongs
    cout << d.size(3) << endl; // size of connected component 3 belongs
    vector<vector<int>> gs = d.groups();
    cout << gs.size() << endl;
}