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

int num_swaps2(vector<int> x, int n) {
    int rtn = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (x[i] > x[j]) rtn++;
        }
    }
    return rtn;
  
}


int main()
{   
    // dp
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W)),B(H,vector<int>(W));
    rep(i,H) rep(j,W){
        cin >> A[i][j];
    }

    rep(i,H) rep(j,W){
        cin >> B[i][j];
    }

    vector<int> row(H);
    iota(all(row),0);
    int ans = 10000;
    bool found = false;
    do {
        int hswaps = num_swaps2(row,H);
        vector<int> col(W);
        iota(all(col),0);
        do {
            vector<vector<int>> C(H,vector<int>(W));
            bool ok = true;
            rep(i, H) rep(j, W) {
                C[i][j] = A[row[i]][col[j]];
                if (C[i][j] != B[i][j]){
                    ok = false; break;
                }
            }
            if (ok){
                found = true;
                int cswaps = num_swaps2(col,W);
                chmin(ans,hswaps + cswaps);
            }

        } while (next_permutation(all(col)));
    } while(next_permutation(all(row)));
    if (found) cout << ans << endl;
    else cout << -1 << endl;
}