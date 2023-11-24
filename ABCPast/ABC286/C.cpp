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
    lint N,A,B;
    cin >> N >> A >> B;
    string s;
    cin >> s;
    lint mn = (1LL << 63)-1;
    //cout << mn << endl;
    for (int i = 0; i < N; i++){
        //A
        lint sum = 0;
        sum += (lint) A*i;
        string scopy = s;
        scopy = s.substr(i,N-i) + s.substr(0,i);
        int check = N/2;
        int okcnt = 0;
        for (int j = 0; j < check; j++){
            if (scopy[j] == scopy[N-1-j]) okcnt++;
        }
        sum += (lint) B*(check-okcnt);
        chmin(mn,sum);
    }
    cout << mn << endl;
} 