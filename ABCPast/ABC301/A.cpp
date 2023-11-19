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
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};


int main()
{   
    int N;
    cin >> N;
    string s;
    cin >> s;
    int t = 0;
    int a = 0;
    for (char c: s){
        if (c=='T') t++;
        else a++;
    }
    if (t > a) cout << "T" << endl;
    else if (t < a) cout << "A" << endl;
    else {
        int tt = 0;
        int aa = 0;
        for (char c: s){
            if (c=='T') tt++;
            else aa++;
            if (tt == s.size()/2){
                cout << "T" << endl;
                break;
            } else if (aa == s.size()/2){
                cout << "A" << endl;
                break;
            }
        }
        
    }
}