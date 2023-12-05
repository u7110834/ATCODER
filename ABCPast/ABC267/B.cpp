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
    string s;
    cin >> s;
    vector<bool> standing(10);
    rep(i,10) standing[i] = (s[i] == '1');
    if (standing[0]) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> cs(7);
    cs[0] = standing[6];
    cs[1] = standing[3];
    cs[2] = standing[7] + standing[1];
    cs[3] = standing[0] + standing[4];
    cs[4] = standing[8] + standing[2];
    cs[5] = standing[5];
    cs[6] = standing[9];

    bool yes = false;
    for (int i = 1; i <= 5; i++){
        if (cs[i] == 0){
            int ok = 0;
            for (int j = 0; j < i; j++){
                if (cs[j] >= 1) {
                    ok++;
                    break;
                }
            }
            for (int j = i+1; j <= 6; j++){
                if (cs[j] >= 1) {
                    ok++;
                    break;
                }
            }
            if (ok == 2) {
                yes = true;
                break;
            }
        }
    }

    cout << (yes? "Yes" : "No") << endl;
}