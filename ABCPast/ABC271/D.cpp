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
    int N,S;
    cin >> N >> S;
    vector<int> a(N+1), b(N+1);
    rep1(i,N) cin >> a[i] >> b[i];
    vector<vector<pair<bool,bool>>> dp(N+1,vector<pair<bool,bool>>(S+1,{0,0}));
    // x true if yes, y true if H
    dp[0][0] = {1,0};
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= S; j++){
            if (j - a[i] >= 0) {
                if (dp[i-1][j-a[i]].first) {
                    dp[i][j].first = true;
                    dp[i][j].second= true;
                }
            }
            if (j - b[i] >= 0) {
                if (dp[i-1][j-b[i]].first) dp[i][j].first = true;
            }
        }
    }
    if (!dp[N][S].first) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        // Find HT
        string ans;
        int curS = S;
        for (int i = N; i > 0; i--){
            bool isH = dp[i][curS].second;
            ans += (isH? 'H':'T');
            curS -= (isH? a[i]: b[i]);

        }
        reverse(all(ans));
        cout << ans << endl;
    }
    
}