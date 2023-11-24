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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);
    rep(i,M){
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // dfs to find connected components
    int ans = 0;
    vector<int> seen(N);
    queue<int> qu;
    rep(i,N){
        if (seen[i]) continue;
        seen[i] = true;
        qu.push(i);
        while (!qu.empty()){
            //cout << count(seen.begin(),seen.end(),1) << endl;
            int v = qu.front();
            qu.pop();
            for (int& next_v : g[v]){
                if (seen[next_v]) continue;
                seen[next_v] = true; //important
                qu.push(next_v);
            }   
        }  
        ans++;
    }  
    cout << ans << endl;
}