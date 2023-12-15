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
    int N,X;
    cin >> N >> X;
    vector<int> a(N+1), b(N+1);
    rep1(i,N) cin >> a[i] >> b[i];
    vector<vector<bool>> dp(N+1,vector<bool>(20010,0));
    dp[0][0+10005] = 1;
    const int xbound = 10000;
    for (int i = 1; i <= N; i++){
        for (int j = -xbound; j <= xbound; j++){
            dp[i][j+10005] = dp[i-1][j-a[i]+10005] || dp[i-1][j-b[i]+10005];
        }
    }
    cout << (dp[N][X+10005]? "Yes" : "No") << endl;

}