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

    map<int,int> Qnum;
    rep(i,N){
        int D;
        cin >> D;
        Qnum[D]++;
    }

    int M;
    cin >> M;
    map<int,int> Tnum;
    rep(i,M){
        int T;
        cin >> T;
        Tnum[T]++;
    }
    bool ok = true;
    for (auto it = Tnum.begin(); it != Tnum.end(); it++){
        int q = (*it).first;
        int num = (*it).second;
        if (Qnum.find(q) == Qnum.end()){
            ok = false;
            break;
        } else if (num > Qnum[q]){
            ok = false;
            break;
        }
    }
    cout << (ok? "YES" : "NO") << endl;
}