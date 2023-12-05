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
    vector<vector<int>> snuke(100001, vector<int>(2,-1)); // t, x, a;
    rep(i,N){
        int t,x,a;
        cin >> t >> x >> a;
        snuke[t][0] = x;
        snuke[t][1] = a;
    }
    vector<vector<ll>> dp(100001, vector<ll>(5,-1));
    dp[0][0] = 0; // if -1 then cannot get there;
    vector<int> dx = {-1, 0 , 1};
    for (int i = 1; i <= 100000; i++){
        for (int j = 0; j < 5; j++){
            ll now = -1;
            // left or right or not move;
            
            for (int k : dx){
                int prev_x = j - k;
                if (prev_x >= 0 && prev_x < 5 && dp[i-1][prev_x] != -1){
                    ll compare = dp[i-1][prev_x];
                    if (snuke[i][0] == j){
                        compare += (ll) snuke[i][1];
                    }
                    chmax(now, compare);
                }
                
            }
            dp[i][j] = now;
        }
    }

    cout << *(max_element(all(dp[100000]))) << endl;
}