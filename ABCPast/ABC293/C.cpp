#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <stack>
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

int dx[] = {1, 0}, dy[] = {0,1};
int main()
{   
    int H,W;
    cin >> H >> W;
    vector<int> v;
    vector<vector<int>> a(H,vector<int>(W));
    rep(i,H) rep(j,W) cin >> a[i][j];
    v.insert(v.end(), H-1 , 0); 
    v.insert(v.end(), W-1 , 1);
    int cnt = 0;
    do {
        bool ok =true;
        set<int> aset = {a[0][0]};
        int x = 0;
        int y = 0;
        for (int d : v){
            x += dx[d];
            y += dy[d];
            if (aset.contains(a[x][y])){
                ok = false;
                break;
            } 
            aset.insert(a[x][y]);
        }
        if (ok) cnt++;
    }while (next_permutation(v.begin(),v.end()));
    cout << cnt << endl;
}