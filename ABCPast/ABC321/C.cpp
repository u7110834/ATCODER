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
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    // bit search
    // 9876543210 -> 1
    // 9876543210> 2*10^9, so overflow
    // need to use ll
    // 2^10 -1 ways

    int K;
    cin >> K;
    vector<ll> ans;
    for (int i = 1; i < 1<<10; i++){
        ll num = 0;
        ll pow = 1;
        for (int j = 0; j < 10; j++){
            if (i & 1 << j) {
                num += pow*j;
                pow *=10;
            }
        }
        if (num != 0) ans.push_back(num);
    }
    sort(ans.begin(),ans.end());
    //sort(ans.begin(),ans.end());
    cout << ans[K-1] << endl; // exclude 0
}