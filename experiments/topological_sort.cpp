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

    
/*
O(V+E)
L ← トポロジカルソートした結果を蓄積する空リスト
S ← 入力辺を持たないすべてのノードの集合/Stack/queue

while S が空ではない do
    S からノード n を削除する
    L に n を追加する
    for each n の出力辺 e とその先のノード m do
        辺 e をグラフから削除する
        if m がその他の入力辺を持っていなければ then
            m を S に追加する

if グラフに辺が残っている then
    閉路があり DAG でないので中断
--------------------------------------------------
Output will depends on the order in which we look at 
the elements of S
*/
vector<int> topological_sort(map<int,vector<int>> &G, vector<int> &indegree,int V,int E){
    vector<int> ans;
    int rem_E = E; // remaining number of edges
    // Store all verteces with 0 in-degree in a queue
    queue<int> que;
    for (int i = 0; i < V; i++){
        if (indegree[i] == 0){
            que.push(i);
        }
    }

    while (que.empty() == false){
        int v = que.front();

        // remove v
        que.pop();

        // look at the verteces directed by v
        for (int i = 0; i < G[v].size(); i++){
            int u = G[v][i];

            // remove edge v -> by reducing the degree of u by 1
            indegree[u] -= 1; 
            
            // if u no longer has an indegree push to que
            if (indegree[u] == 0) que.push(u);

        }

        ans.push_back(v);
        rem_E--;
    }
    if (rem_E != 0) { return vector<int>(0);} // contains DAG
    else return ans;
}

int main()
{   
    // A directed graph can be sorted topologically 
    // if it is acyclic, i.e. it does not contain 
    // a cycle
    // AOJ topological sort
    int V,E;
    cin >> V >> E;
    map<int, vector<int>> g;

    // number of points directed to v;
    vector<int> indegree(V); 
    rep(i, E){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }

    auto ans = topological_sort(g,indegree,V,E);
    for (auto v : ans){
        cout << v << endl;
    }

}