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
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N;
    cin >> N;
    string s;
    map<char,int> count;
    cin >> s;
    //bool cont = false;
    //bool current;
    int len = 1;
    for (int  i =0 ; i <N;i++){
        if (s[i] != s[i+1]){
            count[s[i]] =max(count[s[i]],len); 
            len = 1;
        } else {
            len++;
            count[s[i]] =max(count[s[i]],len); 
        }
    }
    int ans = 0;
    for (auto it : count){
        int cn = it.second;
        ans += cn;
    }
    cout << ans << endl;
}