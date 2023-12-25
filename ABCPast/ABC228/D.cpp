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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Pint pair<int,int>

const ll infl = 1LL << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int Q; cin >> Q;
    ll N = 1LL << 20;
    vector<ll> a(N,-1);
    set<ll> alloc; 
    rep(i,N) {
        alloc.insert(i);
    }
    while (Q--){
        int t; cin >> t;
        ll x; cin >> x;
        ll h = x % N;
        if (t == 1){
            auto it = alloc.lower_bound(h);
            if (it == alloc.end()){
                h = 0;
                it = alloc.lower_bound(h);
            }
            a[*it] = x;
            alloc.erase(it);
        } else {
            cout << a[h] << endl;
        }

    }
}