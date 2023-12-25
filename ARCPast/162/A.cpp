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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int ans = 0;
        vector<int> a(N);
        rep(i,N) cin >> a[i];
        vector<int> mn(N);
        mn[N-1] = a[N-1];
        for (int i = N-2; i >= 0; i--){
            mn[i] = min(mn[i+1],a[i]);
        }
        for (int i = 0; i < N; i++){
            if (a[i] == mn[i]) ans++;
        }
        cout << ans << endl;
    }

}