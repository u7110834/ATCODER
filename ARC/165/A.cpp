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

long long euclidean_gcd(long long a, long long b){
    if (b == 0) return a;
    else {
        ll mn = min (a,b);
        ll mx = max(a,b);
        return euclidean_gcd(mn,mx % mn);
    }
}

// eg.
// gcd(111,30) -> gcd(30,21) -> gcd(30,9) 
// -> gcd(9,3) -> gcd(3,1) -> gcd(3,0) -> 3

// lcm = ab/gcd

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}


long long gcd_arr(vector<long long> &a){
  int n = a.size();
  for(int i=n-2; i>=0; i--){
    a[i] = euclidean_gcd(a[i], a[i+1]);
  }
  return a.front();
}

long long lcm_arr(vector<long long> &a){
  int n = a.size();
  for(int i=n-2; i>=0; i--){
    a[i] = lcm(a[i], a[i+1]);
  }
  return a.front();
}

// smallest integer greater than or equal to sqrt(a);
long long sqrt_bs(long long a){
    long long hi = a;
    long long lo = 1;
    while (hi - lo > 1){
        long long mid = (hi+lo)/2;
        long long mid_sq = mid*mid;
        if (mid_sq < a){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (lo*lo == a){
        return lo;
    } else if (hi*hi == a){
        return hi;
    } else {
        return hi;
    }
}

int main()
{   
    long long a;
    cin >> a;
    cout << sqrt_bs(a) << endl;
}