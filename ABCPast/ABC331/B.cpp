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
    int N, S,M,L;
    cin >> N >> S >> M >>L;
    // check which is max;
    int ans = (1 << 31)-1;
    for (int i = 0; i <= 100/6+1;i++){
        for (int j = 0; j <= 100/8+1; j++){
            for (int k = 0; k <= 100/12 +1; k++){
                if (i*6+j*8+k*12 >= N){
                    int sum = i*S+j*M+k*L;
                    chmin(ans,sum);
                }
            } 
        }
    }
    cout << ans << endl;
}