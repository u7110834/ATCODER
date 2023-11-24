// check if a graph is bipartite
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

// Check if g is biparte using bfs, O(E+V)
bool isbipartite_nondirected(vector<vector<int>> g,int N, int M){
    vector<bool> seen(N,0);
    vector<bool> isblack(N,0); 
    // bfs
    bool bip = true;

    // need not be connected
    for (int i = 0; i < N; i++){
        if (seen[i]) continue;

        queue<int> que;
        que.push(i);

        isblack[i] = true;
        seen[i] = true;
        bool black = true;

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
                    que.push(next_v);
                }
            }
        }
        if (!bip) break;
    }
    return bip;
}