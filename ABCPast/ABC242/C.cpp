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

int d[] = {-1,0,1}; 
int main()
{   
    int N;
    cin >> N;
    ll ans = 0;
    ll mod = 998244353;
    vector dp(N, vector<ll>(9));
    for (int i = 0; i < 9; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i < N; i++){
        for (int j = 0; j < 9; j++){
            ll sum = 0;
            for (int diff : d){
                int olj = j + diff;
                if (olj >= 0 && olj < 9){
                    sum = (sum + dp[i-1][olj]) % mod;
                }
            }
            dp[i][j] = sum;
        }
    }
    for (int i = 0; i < 9; i++){
        ans = (ans + dp[N-1][i]) % mod;
    }
    cout << ans << endl;
}