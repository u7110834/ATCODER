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
    string s;
    cin >> s;

    vector<int> cw, aw;

    for (int i = 0; i < N; i++){
        int w; cin >> w;
        if (s[i]- '0'){
            aw.push_back(w);
        } else cw.push_back(w);
    }

    sort(all(aw)); sort(all(cw));

    int mxcor = 0;
    for (int i = 0; i < cw.size(); i++){
        for (int d = -1; d <= 1; d++){
            int X = cw[i]+d;
            int num = 0;
            int ccor = lower_bound(all(cw), X) - cw.begin();
            num += ccor;

            int acore = aw.end() - lower_bound(all(aw),X);
            num += acore;
            chmax(mxcor, num);
        }

    }

    for (int i = 0; i < aw.size(); i++){
        for (int d = -1; d <= 1; d++){
            int X = aw[i]+d;
            int num = 0;
            int ccor = lower_bound(all(cw), X) - cw.begin();
            num += ccor;

            int acore = aw.end() - lower_bound(all(aw),X);
            num += acore;
            chmax(mxcor, num);
        }
    }
    cout << mxcor << endl;
}