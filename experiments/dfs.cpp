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
    vector<int> adjacent;
};

void print(map<int, Node> const &G){
    for (auto &it : G){
        cout << it.first << " : ";
        for (int ad : it.second.adjacent){
            cout << ad << " ";
        }
        cout << endl;
    }
}

void dfs(int &max_h, map<int, Node> &G, int v){
    G[v].seen = true;
    max_h = max(max_h,v);
    for (int next_v: G[v].adjacent){
        if (G[next_v].seen) continue;
        dfs(max_h,G,next_v);
    }
}

int main()
{   
    int N;
    cin >> N;
    map<int, Node> G;
    for (int i = 0; i < N; i++){
        int A,B;
        cin >> A >> B;
        G[A].adjacent.push_back(B);
        G[B].adjacent.push_back(A);
    }
    putline;
    print(G);
    int max_h = 0;
    int v  = 1;
    dfs(max_h, G, v);
    cout << max_h << endl;
}