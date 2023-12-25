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
    int N;
    cin >> N; // odd 
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    sort(all(a));
    int left = a[0];
    int right = a[0];
    bool ok = true;
    for (int i = 1; i < N; i++){
        if (i % 2 == 1){
            //top
            left = a[N-1];
            right = a[N-2];
        }
    }
}