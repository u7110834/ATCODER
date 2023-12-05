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
    int N; cin >> N;
    set<int> even,odd;
    rep(i,N){
        int a;
        cin >> a;
        if (a % 2 == 1) even.insert(a);
        else odd.insert(a);
    }

    if (even.size() < 2 && odd.size() < 2) {
        cout << -1 << endl;
        return 0;
    }

    int mx = 0;
    if (even.size() >= 2){
        int e = 0;
        auto emax = even.rbegin();
        e += *emax;
        emax++;
        e += *emax;
        chmax(mx,e);
    }
    if (odd.size() >= 2){
        int o = 0;
        auto omax = odd.rbegin();
        o += *omax;
        omax++;
        o += *omax;
        chmax(mx,o);
    }
    cout << mx << endl;


}