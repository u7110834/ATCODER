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
    int N, M;
    cin >> N >> M;

    vector<set<int>> sets(M);

    rep(i,M) {
        int c;
        cin >> c;
        rep(j,c){
            int a;
            cin >> a;
            sets[i].insert(a);
        }
    }
    int cnt = 0;
    for (int i = 0; i < (1 << M); i++){
        set<int> total;
        for (int j = 0; j < M; j++){
            if (i & 1 << j){
                total.insert(sets[j].begin(), sets[j].end());
            }
        }
        bool ok = 1;
        for (int k = 1; k <= N; k++){
            if (!total.contains(k)){
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }

    cout << cnt << endl;
}