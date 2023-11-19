

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
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long


int main()
{   
    int N, M;
    cin >> N >> M;
    string s;
    string t;
    cin >> s >> t;
    map<char, set<char>> mp;
    for (int i = M-1; i >= 0; i--){
        if (mp.find(t[i]) == mp.end()){
                mp.insert({t[i],{}});
            }
        auto it = mp.find(t[i]);
        if (i == M-1){
            for (int j = 0; j < M ;j++);
            mp.insert({t[i],{}});
        }
    }
    bool ok  = 1;
    if (s[0] != t[0]){
        ok = false;
    }
    //cout << mp.at('C').size() << endl;
    for (int i = 0; i < N-1; i++){
        //cout << (!mp.at(s[i]).contains(s[i+1])) << endl;
        if (mp.find(s[i]) == mp.end() || !mp.at(s[i]).contains(s[i+1])) ok = false;
    } 
    cout << (ok? "Yes": "No") << endl;
}