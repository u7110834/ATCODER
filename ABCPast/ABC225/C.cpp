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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Pint pair<int,int>

const ll infl = 1 << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N, M; cin >> N >> M;
    vector mat(N, vector<int>(M));
    rep(i,N) rep(j, M) cin >> mat[i][j];
    bool ok = true;
    if ((mat[0][0]-1) % 7 > 7-M) ok = false;
    for (int i = 0; i < N; i++){
        for (int j = 1; j < M; j++){
            if (mat[i][j] != mat[i][j-1] + 1){
                ok = false;
            }
        }
    }

    for (int j = 0; j < M; j++){
        for (int i = 1; i < N; i++){
            if (mat[i][j] != mat[i-1][j] + 7){
                ok = false;
            }
        }
    }
    cout << (ok? "Yes" : "No") << endl;
}