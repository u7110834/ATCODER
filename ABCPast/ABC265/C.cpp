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

int main()
{   
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i,H) cin >> G[i];
    vector<vector<bool>> seen(H, vector<bool>(W,0));
    int x = 0;
    int y = 0;
    bool cyclic = true;
    do {
        seen[x][y] = true;
        char c = G[x][y];
        if (c == 'U'){
            if (x-1 == -1){
                cyclic = false;
                break;
            }
            x--;
        } else if (c == 'D'){
            if (x+1 == H){
                cyclic = false;
                break;
            }
            x++;
        } else if (c == 'L'){
            if (y-1 == -1){
                cyclic = false;
                break;
            }
            y--;
        }else if (c == 'R'){
            if (y+1 == W){
                cyclic = false;
                break;
            }
            y++;
        }
    } while(!seen[x][y]);
    
    if (cyclic) cout << -1 << endl;
    else cout << x+1 << " " << y+1 << endl;
}