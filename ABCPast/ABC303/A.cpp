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
    string s,t;
    cin >> s >> t;
    bool yes = true;
    for (int i = 0; i<s.size();i++){
        char ss = s[i];
        char tt = t[i];
        bool ok = false;
        set<char> cs;
        cs.insert({ss,tt});
        if (cs.size() == 1) ok = true;
        if (cs.contains('1') && cs.contains('l')) ok = true;
        if (cs.contains('0') && cs.contains('o')) ok = true;
        if (ok == false){
            yes = false;
            break;
        }
    }
    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;
}