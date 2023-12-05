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
    cin >> N;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    vector<int> rcnt(N), ccnt(N);
    rep(i,N) {
        rcnt[i] = count(S[i].begin(),S[i].end(),'o');
    }
    rep(i,N){
        int c = 0;
        rep(j,N) {
            c += S[j][i] == 'o';
        }
        ccnt[i] = c;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++){
        ll cnt = 0;
        for (int j = 0; j < N; j++){
            if (S[i][j] == 'o'){
                cnt += (ll) (rcnt[i] - 1)*(ccnt[j] - 1);
            }
        }
        ans += (ll) cnt;
    }
    cout << ans << endl;
}