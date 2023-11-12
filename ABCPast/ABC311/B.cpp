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
    int N,D;
    cin >> N >> D;
    string s[N];
    int sum[D];
    memset(sum,0,sizeof(sum));
    rep(i,N) cin >> s[i];
    rep(i,N) rep(j,D){
        if (s[i][j] == 'o'){
            sum[j]++;
        }
    }
    int ans = 0;
    bool prev =false;
    int current = 0;
    rep(j,D){
        int num = sum[j];
        if (num == N){
            if (prev == false){
                prev =true;
                current = 1;
                chmax(ans,current);
            }
            else{current++;chmax(ans,current);}
        } else {
            prev =false;
            chmax(ans,current);
            current = 0;
        }
    }
    cout << ans << endl;
}