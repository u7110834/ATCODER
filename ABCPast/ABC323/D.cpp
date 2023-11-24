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
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main()
{   
    int N;
    cin >> N;
    map<int, vector<int>> types;
    rep(i,N){
        long long s,c;
        cin >> s >> c;
        int type = s;
        int p = 0;
        
        while (type % 2 == 0){
            p++;
            type /= 2;
        }
        if(types.find(type) == types.end()){
            types[type] = vector<int>(64,0);
        }

        while (c != 0){
            c += types[type][p];
            types[type][p] = c%2;
            p++;
            c /= 2;
        }
    }
    lint ans  = 0;
    for (auto it : types) {
        vector<int> bits = it.second;
        ans += count(bits.begin(),bits.end(),1);
    }
    cout << ans << endl;
}