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
    int N,M;
    cin >> N >> M;
    vector<set<int>> ball(M);
    rep(i,M){
        int k; cin >> k;
        rep(j,k){
            int x;
            cin >> x; x--;
            ball[i].insert(x);
        }
    }
    bool yes = true;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            bool ok = false;
            for (int k = 0; k < M; k++){
                if (ball[k].contains(i) && ball[k].contains(j)){
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                yes = false; break;}
        }
    }
    cout << (yes? "Yes" : "No") << endl;
}