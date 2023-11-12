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

vector<int> v;
int main()
{   
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        v.push_back(a); 
    }
    for (int i = 0; i < M;i++){
        int b;
        cin >> b;
        v.push_back(b+1);
    }
    sort(v.begin(),v.end());
    cout << v[M-1] << endl;
    
}