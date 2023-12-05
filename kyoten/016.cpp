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
    int A,B,C;
    cin >> A >> B >> C;

    constexpr int mx = 10000;

    int ans = 10000;
    for (int i = 0; i < mx; i++){
        for (int j = 0; j < mx-i; j++){
            ll sum = 0;
            sum += (ll) i*A;
            sum += (ll) j*B;
            if (sum > N) break;
            if ((N-sum)%C == 0){
                int total = i+j+(N-sum)/C;
                chmin(ans,total);
            } 
        }
    }
    cout << ans << endl;
}