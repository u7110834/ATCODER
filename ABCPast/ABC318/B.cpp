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

int main()
{   
  int N;
  cin >> N;
  bool grid[100][100] = {};
  memset(grid,0,sizeof(grid));
  for (int i = 0; i < N; i++){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    for (int j = A; j < B; j++){
        for (int k = C; k <D; k++){
            grid[j][k] = {true};
        }
    }
  }  
  int sum = 0;
  for (int i = 0; i < 100 ; i++){
    for (int j = 0; j < 100 ; j++){
        if (grid[i][j]){
            sum++;
        }
    }
  }
  cout << sum << endl;
}