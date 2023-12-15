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
    int N;
    cin >> N;
    vector<string> sl(N),tl(N);
    for (int i = 0; i < N; i++){
        string s,t;
        cin >> s >> t;
        sl[i] = s;
        tl[i] = t;
    }
    for (int i = 0; i < N; i++){
        string s = sl[i];
        string t = tl[i];
        bool syes= false;
        bool tyes = false;
        for (int j = 0; j < N; j++){
            if (j == i) continue;
            if (s == sl[j] || s == tl[j]) syes = true;
            if (t == tl[j] || t == sl[j]) tyes = true;
        }
        if (syes && tyes){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}