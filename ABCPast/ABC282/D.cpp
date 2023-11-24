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
    // Check if original g is biparte
    // false if there exists a cycle with
    // odd vertices
    int N,M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<bool> seen(N,0);
    vector<bool> isblack(N,0); 
    rep(i,M) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // bfs
    bool bip = true;
    int connected_components = 0;
    vector<int> bs_in_component;
    vector<int> total_in_component;
    rep(i,N){
        if (seen[i]) continue;

        queue<int> que;
        que.push(i);

        isblack[i] = true;
        seen[i] = true;
        int bcnt = 1;
        bool black = true;
        int total = 1;

        while(!que.empty()){
            int v = que.front();
            black = !isblack[v];
            que.pop();
            for (int next_v: g[v]){
                if (seen[next_v]){
                    if (isblack[next_v] != black){
                        bip = false;
                        break;
                    } else continue;
                } else {
                    seen[next_v] = true;
                    isblack[next_v] = black;
                    if (black) bcnt++;
                    total++;
                    que.push(next_v);
                }
            }
        }
        if (!bip) break;
        connected_components++;
        bs_in_component.push_back(bcnt);
        total_in_component.push_back(total);
    }
    if(!bip) {
        cout << 0 << endl;
        return 0;
    }
    lint ans = 0;
    lint ans2 = 0;
    //cout << connected_components << endl;
    rep(i,connected_components){
        // within component;
        int b = bs_in_component[i];
        int t = total_in_component[i];
        ans += (lint) b*(t-b);
        // inter component
        ans2 += (lint) t*(N-t);
    }
    cout << ans + ans2/2 - M << endl;
}