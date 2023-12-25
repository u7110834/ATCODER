#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <cctype>
// #include <cstring>
// #include <numeric>      // std::iota
// #include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

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
    int H,W; cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++){
        cin >> grid[i];
    }
    // right or down
    // 
    vector dp(H,vector<int>(W,-1));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (grid[i][j] == '#') continue;
            if (i != 0){
                if (dp[i-1][j] != -1) {
                    chmax(dp[i][j], dp[i-1][j] + 1);
                }
            } 
            if (j != 0){
                if (dp[i][j-1] != -1) {
                    chmax(dp[i][j], dp[i][j-1] + 1);
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < H; i++){
        chmax(ans, *max_element(all(dp[i])));
    }

    rep(i,H) {
        rep(j,W){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}
