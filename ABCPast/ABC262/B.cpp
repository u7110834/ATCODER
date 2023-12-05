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
    vector<vector<bool>> mp(100, vector<bool>(100,0));
    
    while (M--){
        int u,v;
        cin >> u >> v;
        u--;v--;
        mp[u][v] = true;
    }

    int ans = 0;
    for (int i = 0; i < 100; i++){
        for (int j = i+1; j < 100; j++){
            if (mp[i][j]){
                for (int k = j+1; k < 100; k++){
                    if (mp[i][k] && mp[j][k]) ans++;
                }
            }
        }
    }
    
    cout << ans << endl;
}