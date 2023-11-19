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
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};


// Graph
int main()
{   
    int N, M;
    cin >> N >> M;
    vector<string> s(N);
    rep(i,N) cin >> s[i];
    
    bool can = false;
    sort(s.begin(),s.end());
    do{ 
        bool yes = true;
        rep(i,N-1){
            string s1 = s[i];
            string s2 = s[i+1];
            int cnt= 0;
            rep(j,M){
                if (s1[j] != s2[j]) cnt++;
            }
            if (cnt != 1){
                yes = false;
                break;
            }
        }
        if (yes) {can = true; break;}
    } while (next_permutation(s.begin(),s.end()));
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}