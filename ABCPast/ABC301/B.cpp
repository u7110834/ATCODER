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
    vector<int> v;
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N){
        cin >> a[i];
    }
    v.push_back(a[0]);
    rep(i,N-1){
        int ai = a[i]; 
        int b = a[i+1];
        if (abs(ai-b) == 1) {
            v.push_back(b);
        } else if (ai < b){
            int diff = b-ai;
            rep1(j,diff){
                v.push_back(ai+j);
            }
        } else {
            int diff = ai-b;
            rep1(j,diff){
                v.push_back(ai-j);
            }
        }
    }
    for (int i = 0; i < v.size(); i++){
        if (i != v.size()-1) cout << v[i] << " ";
        else cout << v[i] << endl;
    }
}