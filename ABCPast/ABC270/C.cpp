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

bool Gcontains(vector<vector<int>> &g, int root, int target,vector<int> &ans,vector<bool> &seen){
    seen[root] = true;
    if (root == target) {
        ans.push_back(root);
        return true;
    }
    for (int next : g[root]){
        if (seen[next]) continue;
        seen[next] = true;
        if (Gcontains(g,next,target,ans,seen)){
            ans.push_back(root);
            return true;
        }
    }
    return false;
}


int main()
{   
    int N,X,Y;
    cin >> N >> X >> Y;
    X--;Y--;
    vector<vector<int>> g(N);
    rep(i,N-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // dfs
    vector<bool> seen(N,0);
    vector<int> ans;
    Gcontains(g,X,Y,ans,seen);
    reverse(all(ans));
    rep(i, ans.size()){
        cout << ans[i]+1 << " "; 
    }
    cout << endl;
}