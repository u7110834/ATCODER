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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(all(A));
    vector<ll> sum(N+1);
    sum[0] = 0;
    rep1(i,N) sum[i] = sum[i-1] + (ll) A[i-1];
    while(Q--){
        ll ans = 0;
        ll X;
        cin >> X;

        ll idx = lower_bound(all(A), X) - A.begin();
        ans += idx*X;
        ans -= sum[idx];
        ans += sum[N] - sum[idx];
        ans -= ((ll) N-idx)*X;
        cout << ans << endl;  
    }
}