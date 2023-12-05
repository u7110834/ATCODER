#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
#include <bitset>
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

long long euclidean_gcd(long long a, long long b){
    if (b == 0) return a;
    else {
        ll mn = min (a,b);
        ll mx = max(a,b);
        return euclidean_gcd(mn,mx % mn);
    }
}

int main()
{  
    ll a,b;
    cin >> a >> b;
    const ll mod = 1000000007;
    a = a % mod;
    ll ans = 1;
    for (int i = 31; i >= 0; i--){
        if (b & 1 << i){
            int p = i;
            ll ex = a;
            while (p--){
                ex = (ex*ex) % mod;
            }
            ans = (ans * ex)  % mod;
        }
    }

    cout << ans << endl;

    
}
    