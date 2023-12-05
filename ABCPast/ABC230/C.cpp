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
    ll N,A,B;
    cin >> N >> A >> B;
    ll P,Q,R,S;
    cin >> P >> Q >> R >> S;

    for (ll i = P; i <= Q; i++){
        for (ll j = R; j <= S; j++){
            // check if painted
            ll k = i-A;
            ll k2 = j-B;
            if (abs(k) != abs(k2)){
                // false
                cout << '.';
            } else if (k == k2){
                if (max(1-A,1-B) <= k && k <= max(N-A,N-B)){
                    cout << '#';
                } else cout << '.';
            } else {
                if (max(1-A,B-N) <= k && k <= max(N-A,B-1)){
                    cout << '#'; 
                } else cout << '.';
            }
        }
        cout << endl;
    }
}