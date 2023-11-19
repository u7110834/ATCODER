#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <stack>
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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int dx[] = { 1,0,-1,0,1,1,-1,-1 }; int dy[] = { 0,1,0,-1,1,-1,1,-1 };

// DFS using stack
int main(){   
    int H, W;
    // vertices labelled 0,1,...,N-1
    cin >> H >> W;
    vector<string> s(H);
    vector<vector<bool>> seen(H,vector<bool>(W,0));
    rep(i,H) cin >> s[i];
    int ans  = 0;
    for(int i = 0; i < H;i++){
        for (int j  = 0; j < W; j++){
            if (s[i][j] == '.' || seen[i][j]) continue;
            // else there is a sensor that hasn't been seen.
            queue<pair<int,int>> que;
            que.push({i,j});
            seen[i][j] = 1;
            // bfs 
            while(!que.empty()){
                pair<int,int> p = que.front();que.pop();
                int x = p.first, y = p.second;
                for (int d = 0; d< 8; d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if (nx < H && nx >= 0 && ny < W && ny >= 0 ){
                        if (s[nx][ny] == '#' && !seen[nx][ny]){
                            que.push({nx,ny});
                            seen[nx][ny] = 1;

                        }
                    }
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
}