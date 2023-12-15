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
    vector<int> h(3), w(3);
    rep(i,3) cin >> h[i];
    rep(i,3) cin >> w[i];

    ll ans = 0;
    
    rep1(i, 30){
        vector<int> grid(9);
        grid[0] = i;
        rep1(j,30){
            grid[1] = j;
            rep1(k,30){
                grid[3] = k;
                rep1(l,30){
                    grid[4] = l;
                    if (h[0] - i - j < 1) {
                        continue;
                    } else {
                        grid[2] = h[0] - i - j; 
                    }
                    if (h[1] - k - l < 1) {
                        continue;
                    } else {
                        grid[5] = h[1] - k - l;
                    }

                    if (w[2] - grid[2] - grid[5] < 1) {
                        continue;
                    } else {
                        grid[8] = w[2] - grid[2] - grid[5];
                    }


                    if (w[0] - i - k < 1) {
                        continue;
                    } else {
                        grid[6] = w[0] - i - k;
                    }
                    if (w[1] - j - l < 1) {
                        continue;
                    } else {
                        grid[7] = w[1] - j - l;
                    }
                    if (h[2] - grid[6] - grid[7] != grid[8]) {
                        continue;
                    }
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}