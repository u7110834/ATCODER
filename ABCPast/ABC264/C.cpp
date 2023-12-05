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
    int H1,W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1,vector<int>(W1));
    rep(i,H1)rep(j,W1) cin >> A[i][j];
    
    int H2,W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2,vector<int>(W2));
    rep(i,H2)rep(j,W2) cin >> B[i][j];
    
    // 1 if to be removed and 0 otherwise
    vector<bool> r_rem(H1), c_rem(W1);
    rep(i,H1) {
        if (i < H2) r_rem[i] = 0;
        else r_rem[i] = 1;
    } 
    rep(i,W1){
        if (i < W2) c_rem[i] = 0;
        else c_rem[i] = 1;
    }

    do {
        auto c_rem_copy = c_rem;
        do {
            bool ok = true;
            int bi = 0;
            for (int i = 0; i < H1; i++){
                if (r_rem[i]) continue;
                int bj = 0;
                for (int j = 0; j < W1; j++){
                    if (!c_rem_copy[j]){
                        if (B[bi][bj] != A[i][j]){
                            ok = false;
                            break;
                        }
                        bj++;
                    } 
                }
                bi++;
                if (ok == false) break;
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        } while (next_permutation(all(c_rem_copy)));
    } while(next_permutation(all(r_rem)));

    cout << "No" << endl;
}