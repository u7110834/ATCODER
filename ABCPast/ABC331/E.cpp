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
    int N,M,L;
    cin >> N >> M >> L;
    vector<int> a(N);
    vector<int> b(M);
    rep(i,N) cin >> a[i];
    rep(i,M) cin >> b[i];
    vector<int> idxA(N),idxB(M);
    iota(all(idxA),0);
    iota(all(idxB),0);
    auto compA = [&](int i,int j){
        if (a[i] != a[j]) return a[i] < a[j];
        else return i < j;
    };
    auto compB = [&](int i,int j){
        if (b[i] != b[j]) return b[i] < b[j];
        else return i < j;
    };
    sort(all(idxA),compA);
    sort(all(idxB),compB);
    sort(all(a));
    sort(all(b));
    vector<int> c(L),d(L);
    map<int,set<int>> mp;
    rep(i,L) {
        int c,d;
        cin >> c >> d;
        c--,d--;
        mp[c].insert(d);
    }
    int ans = 0;
    int jmax = -1;
    for (int i = N-1; i>= 0; i--){
        int m = a[i];
        //for (int an : mp[idxA[i]]) cout << an << endl;
        for (int j = M-1; j> jmax; j--){
            if (mp[idxA[i]].contains(idxB[j])) continue;
            jmax = j;
            int mx = m+b[j];
            chmax(ans, mx);
            break;
        }
    }
    cout << ans << endl;
}
