#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
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

long long factorial(int N){
    return (N == 1 || N == 0)? 1LL : factorial(N-1)*N;
}

int main()
{   
    int total = factorial(9);
    int c[3][3];
    rep(i,3) rep(j,3) cin >> c[i][j];
    
    vector<int> ord(9);
    iota(ord.begin(), ord.end(), 0);
    do{
        int i =1;
    } while(next_permutation(ord.begin(),ord.end()));
    
}