#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <cctype>
// #include <cstring>
// #include <numeric>      // std::iota
// #include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll infl = 1LL << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    // 1 ++ -> 
    int N, M;
    cin >> N >> M;
    int a1,a2; cin >> a1 >> a2;
    vector<int> a(N-2);
    rep(i,N-2) cin >> a[i];
    sort(all(a));
    // check each contiguous subsequence
    ll rtn = infl;
    for (int i = 0; i < N-1-M; i++){
        // 0 if as >= a1 else abs(as - a1)
        // + 0 if al <= a2 else abs(a largest - a2)
        ll ans = 0;
        if (a[i] >= a1) {
            ans += 0;
        } else {
            ans += a1-a[i];
        }
        if (a[i+M-1] <= a2){
            ans += 0;
        } else {
            ans += a[i+M-1] - a2;
        }
        chmin(rtn,ans);
    }

    cout << rtn << endl;
}