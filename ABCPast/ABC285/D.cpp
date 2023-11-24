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
    // directed graph
    int N;
    cin >> N;
    map<string, vector<string>> g;
    map<string, int> indeg; 

    rep(i,N){
        string s,t;
        cin >> s >> t;
        if (!indeg.contains(s)){
            indeg[s] = 0;
        }
        indeg[t]++;
        g[s].push_back(t);
    }

    // condition 2
    // if is acyclic then no
    stack<string> st;
    for (auto it : indeg){
        if (it.second == 0){
            st.push(it.first);
        }
    }
    while (!st.empty()){
        string v = st.top();
        st.pop();
        for (string u : g[v]){
            indeg[u]--;
            if (indeg[u] == 0) st.push(u);
            N--;
        }
    }
    if (N == 0) cout << "Yes" << endl;
    else cout << "No" << endl; 
}