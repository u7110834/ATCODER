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
    int N,D,P;
    cin >> N >> D >> P;
    vector<int> f;
    rep(i,N) {
        int fare;
        cin >> fare;
        f.push_back(fare);
    }
    if (N%D != 0) f.insert(f.end(), D-N%D, 0);
    sort(f.rbegin(),f.rend());
    int len = f.size();
    lint ans = 0;
    int no_ticket = 0;
    for (int i = 0; i < len/D; i++){
        lint psum = 0;
        for (int j = i*D; j < i*D+D; j++){
            psum += f[j];
        }
        if (psum <= P){
            break;
        } else {
            ans += P;
            no_ticket += D;
        }
    }
    for (int i = no_ticket; i < len; i++){
        ans += f[i];
    }
    cout << ans << endl;
}