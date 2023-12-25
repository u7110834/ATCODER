#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Pint pair<int,int>

const ll infl = 1 << 62;
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
    // dsu 
    int N; cin >> N;
    vector<long long> x(N), y(N);
    rep(i,N) cin >> x[i] >> y[i];
    set<pair<long,long>> s;
    for (int i = 0; i < N ; i++){
        for (int j = 0 ; j < N; j++) {
        if (i == j) continue;
        ll xx = x[i] - x[j];
        ll yy = y[i] - y[j];
        if (xx == 0) {
            long long d = 1;
            if (yy < 0) d*=-1;
            s.emplace(0,d); continue;
        }
        if (yy == 0) {
            long long d = 1;
            if (xx < 0) d = -1;
            s.emplace(d,0);
            continue;
        }
        long long m = euclidean_gcd(abs(xx),abs(yy));
        s.emplace(xx/m, yy/m);
        }
    }
    
    cout << s.size() << endl;
}