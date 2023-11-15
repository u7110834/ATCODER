#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    #include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, a + b);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0); // (0,1,2,3,...) indices
    auto f = [&](int i, int j) { // & to access all values
        auto [ai, aj] = ab[i]; // another notation for pair
        auto [bi, bj] = ab[j]; 
        return (long long)ai * bj > (long long)aj * bi;
    }; 
    stable_sort(p.begin(), p.end(), f); // preserves order of i if same
}