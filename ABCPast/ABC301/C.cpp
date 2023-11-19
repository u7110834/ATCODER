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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};


int main()
{   
    set<char> letters = {'a','t','c','o','d','e','r'};
    vector<int> lcnt(26,0);

    string s;
    string t;
    cin >> s >> t;
    int atcount = 0;
    for (char c : s){
        if (c == '@'){ 
            atcount++;
            continue;
        }
        int ind  = c - 'a';
        lcnt[ind]++; 
    }
    for (char c : t){
        if (c == '@'){ 
            atcount++;
            continue;
        }
        int ind  = c - 'a';
        lcnt[ind]--; 
    }
    bool ok = true;
    int diff_cnt = 0;
    for (char c = 'a'; c <= 'z'; c++){
        int ind  = c-'a';
        if (letters.contains(c)){
            diff_cnt += abs(lcnt[ind]);
        } else {
            if (lcnt[ind] != 0){
                ok = false;
                break;
            }
        }
    }
    if (diff_cnt > atcount) ok =false;
    else if ((atcount-diff_cnt) %2 != 0) ok = false;
    cout << (ok? "Yes" : "No") << endl;
}