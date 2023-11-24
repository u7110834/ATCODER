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
    int N,K;
    cin >> N >> K;
    set<int> A;
    rep(i,N) {
        int a;
        cin >> a;
        A.insert(a);
    }
    auto it = A.begin();
    //int mx = 0;
    for (int i = 0 ; i < K ; i++){
        if (it == A.end()){
            cout << i << endl;
            return 0;
        } else if (*it == i){
            it++;
        } else{
            cout << i << endl;
            return 0;
        }
    }
    cout << K << endl;
}