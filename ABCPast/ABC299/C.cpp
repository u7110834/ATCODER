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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N;
    string s;
    cin >> N;
    cin >> s;
    s = "-"+s+"-";
    vector<int> minus;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '-'){
            minus.push_back(i);
        }
    }
    int mxint = 0;
    if (minus.size() == 2){cout << -1 << endl; return 0;}
    for (int i =0; i < minus.size()-1;i++){
        mxint = max(mxint , minus[i+1] - minus[i] -1);
    }
    if (mxint > 0) cout << mxint << endl;
    else cout << -1 << endl;
    
}