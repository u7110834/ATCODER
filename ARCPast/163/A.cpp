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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string s; cin >> s;
        vector<string> dp(N+1,s);
        dp[0] = "";
        dp[1] = {s[0]};
        for (int i = 2; i <= N; i++){
            for (int j = 0; j < i; j++){
                if (j == 0 && i == N) continue;
                string cur = dp[j];
                if (dp[j] == s) continue;
                else {
                    string next = s.substr(j, i-j);
                    if (cur < next){
                        if (dp[i] == s) dp[i] = next;
                        else chmin(dp[i],next);
                    }
                }
            }
        }
        if (dp[N] != s) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}