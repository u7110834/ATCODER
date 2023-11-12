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

// solution using queue to implement dfs
int main(){
    int n;
    cin >> n;
    map<int, vector<int>> graph;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> que;
    que.push(1);
    set<int> S; // set of seen vertices
    S.insert(1);
    while(!que.empty()){
        int v=que.front();
        que.pop(); // remove the first element, i.e. v;
        for (int i: graph[v]){
            if (!S.count(i)){ // if not seen
                que.push(i); // insert i at the end
                S.insert(i); // have seen i
            }
        }
    }
    // print out the largest value that was seen.
    cout << *S.rbegin() << endl; 
}