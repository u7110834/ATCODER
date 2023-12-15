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

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    multiset<ll> A;
    int Q;
    cin >> Q;
    while (Q--){
        int i; cin >> i;
        ll x; cin >> x;
        if (i == 1){
            A.insert(x);
        } else if (i == 3){
            int k; cin >> k; k--;
            auto it = A.lower_bound(x);
            bool ok = true;
            while(k--){
                if (it == A.end()) {
                    ok = false;
                    break;
                }
                it++;
            }
            ok = it != A.end();
            if (ok) cout << *it << endl;
            else cout << -1 << endl;
        } else {
            int k; cin >> k;
            auto it = A.upper_bound(x);
            bool ok = true;
            while(k--){
                if (it == A.begin()) {
                    ok = false;
                    break;
                }
                it--;
            }
            if (ok) cout << *it << endl;
            else cout << -1 << endl;
        }
    }
}