#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

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

constexpr int mx = 2010;
vector<vector<set<pair<int,int>>>> g(mx,vector<set<pair<int,int>>>(mx));
vector<vector<bool>> isblack(mx,vector<bool>(mx));
int dx[] = {-1,-1,0,0,1,1,};
int dy[] = {-1,0,-1,1,0,1};
vector<vector<bool>> seen(mx,vector<bool>(mx,0));
int main()
{   
    int N;
    cin >> N;
    rep(i,N){
        int x,y;
        cin >> x >> y;
        x+=1005;
        y+=1005;
        isblack[x][y] = true;
        // check
        rep(j,6){
            int newx = x+dx[j];
            int newy = y+dy[j];
            if (isblack[newx][newy]){
                g[x][y].insert({newx,newy});
                g[newx][newy].insert({x,y});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < mx; i++){
        for (int j = 0; j < mx; j++){
            if (!isblack[i][j] || seen[i][j]) continue;
            // else 
            ans++;
            stack<pair<int,int>> st;
            st.push({i,j});
            seen[i][j] = 1;
            while (!st.empty()){
                auto t = st.top();
                st.pop();
                for (auto next: g[t.first][t.second]){
                    if (seen[next.first][next.second]) continue;
                    seen[next.first][next.second] = true;
                    st.push(next);
                }
            }
        }
    }

    cout << ans << endl;
}