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
    int N;
    cin >> N;
    int K;
    cin >> K;

    set<int> A;
    rep(i,K) {
        int a;
        cin >> a;
        a--;
        A.insert(a);
    }

    vector<pair<long double ,long double>> co(N);

    rep(i,N) {
        long double x,y;
        cin >> x >> y;
        co[i] = make_pair(x,y);
    }
    long double ans = 0;
    for (int i = 0; i < N; i++){
        long double x = co[i].first;
        long double y = co[i].second;
        if (A.contains(i)){
            continue;
        } else {
            long double dreq = 1e10;
            for (int a : A){
                long double ax = co[a].first;
                long double ay = co[a].second;
                long double d = sqrt((ax-x)*(ax-x) + (ay-y)*(ay-y));
                chmin(dreq,d);
            }
            chmax(ans,dreq);
        }
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}