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

map<string, int> mp = {{"tourist", 3858},
{"ksun48", 3679},
{"Benq", 3658},
{"Um_nik", 3648},
{"apiad", 3638},
{"Stonefeang", 3630},
{"ecnerwala", 3613},
{"mnbvmar", 3555},
{"newbiedmy", 3516},
{"semiexp", 3481},
};

int main()
{   
    string s;
    cin >> s;
    cout << mp.at(s) << endl;
}