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

int dx[] = {1,0, -1, 0, -1, 1,1, -1};
int dy[] = {0,1,  0, -1, 1 ,1,-1, -1};
int main()
{   
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i,N) cin >> A[i];
    ll ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            // check all directions 
            for (int k = 0; k < 8; k++){
                string sum;
                for (int l = 0; l < N; l++){
                    int x = i+ l*dx[k];
                    int y = j + l*dy[k];
                    x = (x+N) % N;
                    y = (y+N) % N;
                    sum += A[x][y];
                }
                chmax (ans, stoll(sum));
            }
        }
    }
    cout << ans << endl;
}