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
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    string s;
    cin >> s;
    int f = stoi(s.substr(0,2));
    int se = stoi(s.substr(2,2));
    bool YYMM = false;
    bool MMYY = false;
    if (1 <= se && se <= 12) YYMM = true;
    if (1 <= f && f <= 12) MMYY = true;

    if (YYMM && MMYY) cout << "AMBIGUOUS" << endl;
    else if (YYMM) cout << "YYMM" << endl;
    else if (MMYY) cout << "MMYY" << endl;
    else cout << "NA" << endl;
}