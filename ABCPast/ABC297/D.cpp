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
    ll a,b;
    cin >> a >> b;
    ll cnt = 0;
    while (a != b){
        //cout << b << endl;
        if (a > b){
            if (a%b == 0){
                cnt += a/b-1LL;
                break;
            }
            cnt += a/b;
            a = (ll) a%b;
            
        } else {
            if (b%a == 0){
                cnt += b/a-1LL;
                break;
            }
            cnt += b/a;
            b = (ll) b%a;
            //cout << cnt << endl;
        }
    }
    cout << cnt << endl;
}