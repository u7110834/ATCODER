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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main() {
  int H, W;
  cin >> H >> W;
  string C[H];
  rep(i,H) cin >> C[i];
  int dx[] = {-1,1};
  int dy[] = {-1,1};
  int N = min(H,W);
  for (int s = 1; s <= N; s++){
    if (2*s+1 > N){
        if (s == N) cout << 0 << endl;
        else cout << 0 << " "; 
        continue;}
    int cnt = 0;
    for (int i = s; i < H-s; i++){
        for(int j = s; j < W-s; j++){
            // centre = (i,j);
            bool ok = true;
            if (C[i][j] != '#'){ok = false;}
            int endcnt = 0;
            for (int ddx : dx) for (int ddy: dy){
                for (int l = 1; l <= s; l++){
                    if (C[i+ddx*l][j+ddy*l] != '#') ok = false;
                }
                if (i+ddx*s+ddx > H-1 || i+ddx*s+ddx < 0 || j+ddy*s+ddy > W-1 || j+ddy*s+ddy < 0) endcnt++;
                else if (C[i+ddx*s+ddx][j+ddy*s+ddy] =='.') endcnt++;
            }
            if (ok && endcnt >= 1) cnt++;

        }
    }
    cout << cnt << " ";
  }
}