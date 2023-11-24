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
    int N;
    string s;
    cin >> N;
    cin >> s;

    vector<int> dcnt(10,0);

    for (char c : s){
        dcnt[c-'0']++;
    }

    ll ans = 0;
    ll mxsq = 1e7;
    for (ll i = 0; i < mxsq; i++){
        ll sq = i*i;
        string sqstr = to_string(sq);

        if (sqstr.size() > N) continue;

        vector<int> req(10,0);
        for (char c : sqstr){
            req[c-'0']++;
        }

        req[0] += N-sqstr.size(); 

        bool ok = true;
        for (int i = 0; i < 10 ; i++){
            if (req[i] != dcnt[i]) {
                ok =false;
                break;
            }
        }

        if (ok) ans++;
    }
    cout << ans << endl;
}