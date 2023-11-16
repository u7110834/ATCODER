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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

const int MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main()
{   
    long long a, b, c;
  a = 111111111;
  b = 123456789;
  c = 987654321;
  cout << "Overflow : " << a * b * c % MOD << endl;       // a*b*c がオーバーフローするので間違った答えに
  cout << "Correct : " << a * b % MOD * c % MOD << endl; // a*b で一旦 MOD をとる
  
  //mod of negative int 
  cout << "17 mod 5 : " << 17 %5 << endl;
  cout << "-17 mod 5 : " << -17%5 << endl;
  cout << "correct -17 mod 5 : " << mod(-17,5) << endl;
}