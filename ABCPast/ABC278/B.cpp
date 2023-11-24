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
    int H,M;
    cin >> H >> M;
    vector<bool> miss(24*60);
    for (int h = 0 ; h <= 23; h++) 
    for(int w = 0; w <= 59; w++){

        bool ok = true;
        int B = h%10;
        int C = w/10;

        int newH = h - B + C;
        int newW = w%10 + B*10;

        if (newH > 23 || newW > 59) ok = false;
        miss[h*60+w]=ok;
    }
    for (int i = H*60+M; i < 1440; i++){
        if (miss[i]){
            cout << i /60 << " " << i %60 << endl;
            return 0;
        }
    }
    for (int i = 0; i < H*M; i++){
        if (miss[i]){
            cout << i /60 << " " << i %60 << endl;
            return 0;
        }
    }

}