#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,K;
    cin >> N >> K;
    vector<pair<int,int>> ab(N);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        ab[i] = {a,b}; 
    }
    sort(ab.begin(),ab.end());
    lint sum = 0; 
    rep(i,N){
        sum += ab[i].second;
    }
    //reverse(ab.begin(),ab.end()); //a decreasing

    if (sum <= K){cout << 1 << endl; return 0;}

    vector<lint> sum_dose(N);
    sum_dose[0] = ab[0].second;
    for (int i = 1; i < N; i++){
        sum_dose[i] =  sum_dose[i-1] + ab[i].second; // increasing
    }

    auto position = lower_bound(sum_dose.begin(),sum_dose.end(),sum-K);
    int ind_lower = distance(sum_dose.begin(),position);
    cout << ab[ind_lower].first+1 << endl;
}