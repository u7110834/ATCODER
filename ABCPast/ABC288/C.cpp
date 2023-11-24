#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

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
    //頂点数が X の連結成分について考えると、適当な全域木を取ることにより 
    // 最大X−1 本は残すことができます
    // Find connected components
    int N, M;
    cin >> N >> M;
    dsu d(N);
    rep(i,M){
        int A,B;
        cin >> A >> B;
        A--; B--;
        d.merge(A,B);
    }
    auto gs = d.groups();
    //int gsum = gs.size();
    int ans = M;
    for (auto g : gs){
        ans -= g.size()-1;
    }
    cout << ans << endl;
}