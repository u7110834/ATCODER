#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
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

// DFS using stack
int main()
{   
    int n, m;
    // vertices labelled 0,1,...,N-1
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n,-1);

    stack<int> st;

    dist[0] = 0;
    st.push(0);

    while(!st.empty()){
        // vertex to check
        int v = st.top();
        st.pop();

        for (int next_v : g[v]){
            if (dist[next_v] != -1){// if checked
                continue;
            }

            dist[next_v] = dist[v]+1;
            st.push(next_v);
        }
    }
}