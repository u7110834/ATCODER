#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

/* accelration */
// 高速バイナリ生成
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

auto putline = [](string s = "========"){
    cout << s << endl;
};

int xs[] = {1,-1,1,-1};
int ys[] = {1,1,-1,-1};
int main()
{   
    int N;
    cin >> N;
    ll M;
    cin >> M;
    set<pair<int,int>> pairs;
    // Should avoid binary search
    for (ll i = 0;; i++){
        ll isq = i*i;
        ll jsq = M-i*i;
        if (jsq < isq) break;
        // Use this instead
        ll j = sqrt(jsq);
        if (j*j == jsq){
            pairs.emplace(i,j);
            pairs.emplace(j,i);
        }
    }
    vector<vector<vector<pair<int,int>>>> g(N,vector<vector<pair<int,int>>>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (auto p : pairs){
                for (int s = 0; s < 4; s++){
                    int dx  = xs[s]*p.first;
                    int dy = ys[s]*p.second;
                    int newx = i+dx;
                    int newy = j+dy;
                    if (newx < N && 0 <= newx && newy < N && 0 <= newy){
                        g[i][j].emplace_back(newx,newy);
                    }
                }
            }
        }
    }
    //bfs
    vector<vector<int>> cnt(N,vector<int>(N));
    vector<vector<int>> finished(N,vector<int>(N,0));
    queue<pair<int,int>> que;
    que.push({0,0});
    finished[0][0] = 1;
    cnt[0][0] = 0;

    while(!que.empty()){
        pair<int,int> f = que.front();
        int x = f.first;
        int y = f.second;
        que.pop();
        int d_cur = cnt[x][y];
        int d_next = d_cur + 1;
        for (pair<int,int> ad : g[x][y]){
            int xnew = ad.first;
            int ynew = ad.second;
            if (finished[xnew][ynew]) continue;
            cnt[xnew][ynew] = d_next;
            finished[xnew][ynew] = 1;
            que.push({xnew,ynew});
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j <N; j++){
            if (!finished[i][j]) cout << -1 << " ";
            else cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
}