#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
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

struct Node{
    bool infected = false;
    bool seen = false;
    vector<int> adjascent;
};

void dfs(map<int, Node> &G, int v){
    G[v].seen = true;
    if(G[v].infected == true){
        for (int next_v: G[v].adjascent){
            G[next_v].infected = true;
            if (!G[next_v].seen) dfs(G,next_v);
    }
    }
}

int main()
{   
    int N, D;
    cin >> N >> D;
    vector<int> x(N),y(N);
    map<int,Node> g;
    rep(i,N){
        cin >> x[i] >> y[i];
        Node node;
        g.insert({i, node});
    }
    rep(i,N){
        for (int j = i+1; j < N ; j++){
            double dist = sqrt((x[i] - x[j])*(x[i] - x[j])+(y[i] - y[j])*(y[i] - y[j]));
            if (dist <= D){
                g[i].adjascent.push_back(j);
                g[j].adjascent.push_back(i);
            }
        }
    }
    g[0].infected = true;
    int v = 0;
    dfs(g,v);
    for (auto it = g.begin(); it != g.end(); it++){
        //cout << (*it).first << endl;
        if ((*it).second.infected) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}