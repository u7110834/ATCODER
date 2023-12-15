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
    map<int,multiset<int>> mp;
    rep(i,N) {
        int f,s;
        cin >> f >> s;
        mp[f].insert(s);
    }
    vector<int> mxt;
    for (auto it : mp){
        int mx = *it.second.rbegin();
        mxt.push_back(mx);
    }
    sort(all(mxt), greater<int>());
    int ans = 0;
    if (mxt.size() > 1) {
        chmax(ans, mxt[0] + mxt[1]);
    }
    for (auto it:mp){
        if (it.second.size() > 1){
            auto ite = it.second.rbegin();
            int sum = 0;
            sum += *ite;
            ite++;
            sum += *ite/2;
            chmax(ans,sum);
        }
    }
    cout << ans << endl;
}