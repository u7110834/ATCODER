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
    int H, W;
    cin >> H >> W;
    vector<string> S(H),T(H);
    rep(i,H) cin >> S[i];
    rep(i,H) cin >> T[i];

    vector<string> St(W),Tt(W);//transpose
    rep(i,W)rep(j,H) {
        St[i] += S[j][i];
        Tt[i] += T[j][i];
    }
    sort(Tt.begin(),Tt.end());
    bool ok = false;
    do{
        bool same = true;
        rep(i,W){
            if (St[i] != Tt[i]){
                same = false;
            }
        }
        if (same) {
            ok = true;
            break;
        }
    } while (next_permutation(Tt.begin(),Tt.end()));

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}