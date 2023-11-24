#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
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
    int N,Q;
    cin >> N >> Q;
    set<int> uncalled;
    set<int> called;
    rep(i,N)uncalled.insert(i+1);

    while(Q--){
        int q;
        cin >> q;
        if (q == 1){
            auto it = uncalled.begin();
            //cout << *it << endl;
            called.insert(*it);
            uncalled.erase(it);
        } else if (q == 2){
            int x;
            cin >> x;
            called.erase(x);
        } else{
            auto it = called.begin();
            cout << *it << endl;
        }
    }
}