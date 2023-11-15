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

vector<int> Acnt(100010,0),B(100010,0),Ccnt(100010,0);
int main()
{   
    int N;
    cin >> N;
    for (int i = 0; i < N ; i++){
        int a;
        cin >> a;
        Acnt[a]++;
    }
    for (int i = 0; i < N; i++){
        int b;
        cin >> b;
        B[i+1] = b;
    }
    for (int i = 0; i < N; i++){
        int c;
        cin >> c;
        Ccnt[B[c]]++;
    }

    lint sum = 0;
    for(int i = 1 ; i <= N; i++){
        sum += (lint) Ccnt[i]* Acnt[i];
    }
    cout << sum << endl;
}