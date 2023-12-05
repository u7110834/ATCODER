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
vector<int> A(100010), B(100010), dp(100010);
int main()
{   
    int N;
    cin >> N;

    for (int i = 1; i < N; i++){
        cin >> A[i];
    }

    for (int i = 2; i < N; i++){
        cin >> B[i];
    }
    dp[0] = 0;
    for (int i = 1; i < N; i++){
        dp[i] = dp[i-1] + A[i];
        if (i-2 >= 0) {
            chmin(dp[i],dp[i-2] + B[i]);
        }
                
    }
    vector<int> ans = {N};
    for (int i = N-1; i > 0;){
        if (i-1 >= 0 && dp[i] == dp[i-1] + A[i]){
            ans.push_back(i);
            i--;
        } else if (i >= 2 && dp[i] == dp[i-2] + B[i]){
            ans.push_back(i-1);
            i -= 2;
        }
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for (int p : ans){
        cout << p << " ";
    }
    cout << endl;

    
}