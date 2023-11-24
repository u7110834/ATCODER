#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

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
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,M;
    cin >> N >> M;
    map<int,set<int>> g;
    dsu d(N);
    rep(i,M){
        int u,v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        d.merge(u-1,v-1);
    }
    if (N != M+1 || d.groups().size() != 1) {
        cout << "No" << endl;
        return 0;
    }
    set<int> ends;
    int cnt2 = 0; // N-2
    rep1(i,N){
        if (g[i].size() == 1) ends.insert(i);
        else if (g[i].size() == 2) cnt2++; 
    }
    if (ends.size() != 2 || cnt2 != N-2){
        //cout << ends.size() << endl;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    // vector<bool> seen(N,0);
    // int cur = *ends.begin();
    // int oldcur = cur;
    // seen[cur] = 1;
    // ends.erase(cur);
    // cur = *g[cur].begin();
    // int seencnt = 2;

    // while(true){
    //     // look at next element
    //     if (cur == *ends.begin()) break;
    //     for (int i : g[cur]){
    //         if (i != oldcur) {
    //             oldcur = cur;
    //             cur = i;
    //         } 
    //     }
    //     if (seen[cur]) {break;}
    //     seen[cur] = true;
    //     seencnt++;
    // }
    // if (seencnt == N){
    //     cout << "Yes" << endl;
    // } else{
    //     cout << "No" << endl;
    // }
}