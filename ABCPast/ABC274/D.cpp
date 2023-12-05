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

int mxN = 1010;
int mxG = 10010;
int main()
{   
    // Given A_i, if i is even then move horizontally
    // otherwise move vertically
    int N,x,y;
    cin >> N >> x >> y;
    vector<int> A(mxN);
    rep1(i,N) cin >> A[i];
    vector<vector<bool>> dpH(mxN, vector<bool>(2*mxG,0));
    vector<vector<bool>> dpV(mxN, vector<bool>(2*mxG,0));
    // (i,j) = dpH[10000]+dpV[10000];
    dpH[0][10000] = 1;
    dpV[0][10000] = 1;
    dpH[1][10000+A[1]] = 1;
    dpV[1][10000] = 1;
    for (int i = 2; i <= N; i++){
        if (i % 2 == 1){ // if i is odd then horizontal
            for (int j = 0; j < 2*mxG; j++){
                if (j-A[i] >= 0 && dpH[i-1][j-A[i]]) dpH[i][j] = 1;
                if (j+A[i] < 2*mxG && dpH[i-1][j+A[i]]) dpH[i][j] = 1;
                dpV[i][j] = dpV[i-1][j];
            }  
                      
        } else {
            for (int j = 0; j < 2*mxG; j++){
                if (j-A[i] >= 0 && dpV[i-1][j-A[i]]) dpV[i][j] = 1;
                if (j+A[i] < 2*mxG && dpV[i-1][j+A[i]]) dpV[i][j] = 1;
                dpH[i][j] = dpH[i-1][j];
            }
        }
    }
    cout << ((dpH[N][x+10000] && dpV[N][y+10000])? "Yes" : "No") << endl;
}