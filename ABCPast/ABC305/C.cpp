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
    int H,W;
    int x = 0;
    int y = 0;
    cin >> H >> W;
    string S[H];
    for (int i = 0 ; i < H; i++){
        cin >> S[i];
    }
    int hn[H];
    int wn[W];

    memset(hn,0,sizeof(hn));
    memset(wn,0,sizeof(wn));
    for (int i = 0 ; i < H; i++){
        string s = S[i];
        hn[i] = count(s.begin(),s.end(),'#');
    }
    for (int i = 0 ; i < W; i++){
        int cnt = 0;
        for (int j = 0 ; j < H; j++){
            if (S[j][i] == '#') cnt++;
        }
        wn[i] = cnt;
    }
    int hmax = *max_element(hn,hn+H);
    int wmax = *max_element(wn,wn+W);
    for (int i = 0 ; i < H; i++){
        if (hn[i] == hmax-1) x = i;
    }
    for (int i = 0 ; i < W; i++){
        if (wn[i] == wmax-1) y = i;
    }
    
    cout << x+1 << " " << y+1 << endl;
}