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

struct Node{
    bool seen = false;
    set<pair<int,int>> adjacent;
};

bool isConnected(int a, int b, map<int, Node> G){
    Node A = G[a];
    G[a].seen = true;
    Node B = G[b];
    set<pair<int,int>> adj = A.adjacent;
    for (pair<int,int> p : adj){
        if (G[p.first].seen == false){
            G[p.first].seen == true;
            if (find(G[p.first].adjacent.begin(),G[p.first].adjacent.end(),b) !=G[p.first].adjacent.end()){
            
            return true;
        } else{
            return isConnected(p.first, b, G);
        }
        } else {continue;}
        
    }
    return false;
}

void remove_edge(int a, int b,map<int, Node>  &G){
    auto adj = G[a].adjacent;
    for (auto it = adj.begin(); it != adj.end(); it++){
        if ((*it).first == b){adj.erase(it);}
    }
    auto adj_b = G[a].adjacent;
    for (auto it = adj_b.begin(); it != adj_b.end(); it++){
        if ((*it).first == b){adj_b.erase(it);}
    }
}
int main()
{   
    int N, M , K;
    cin >> N >> M >> K;
    map<int, Node> G;
    for (int i = 0; i < M; i++){
        int A,B,w;
        cin >> A >> B >> w;
        G[A].adjacent.insert({B,w});
        G[B].adjacent.insert({A,w});
    }
        bool connect = true;
        for (int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++){
                if (!isConnected(i,j,G)) {connect = false; break;}
            } 
        }
    cout << connect << endl;
}