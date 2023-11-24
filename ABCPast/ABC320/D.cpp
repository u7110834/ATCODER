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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    // graph
    int N, M;
    cin >> N >> M;
    vector<bool> seen(N,0);
    map<int, pair<ll,ll>> coord;
    vector<vector<tuple<int,ll,ll>>> g(N);
    rep(i,M){
        int a,b;
        ll x,y;
        cin >> a >> b >> x >> y;
        a--; b--;
        g[a].push_back({b,x,y});
        g[b].push_back({a,-x,-y});
    }
    // dfs
    coord[0] = {0,0};
    stack<int> st;
    st.push(0);
    seen[0] = true;
    while(!st.empty()){
        int v = st.top();
        ll old_x = coord[v].first;
        ll old_y = coord[v].second;
        st.pop();
        seen[v] = true;
        for (auto tup : g[v]){
            int next_v = get<0>(tup);
            if (seen[next_v]) continue;
            ll dx = get<1>(tup);
            ll dy = get<2>(tup);
            coord[next_v] = make_pair(old_x + dx,old_y+dy);
            seen[next_v] = true;
            st.push(next_v);
        }
    }
    rep(i,N){
        if (!seen[i]) cout << "undecidable" << endl;
        else cout << coord[i].first << " " << coord[i].second << endl;
    }
}