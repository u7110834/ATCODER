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

auto putline = [](string s = "========"){
    cout << s << endl;
};

vector<set<int>> idx(200010);
vector<vector<int>> vidx(200010);

long long f(long long a,long long b){
  return (a*a*a + a*a*b + a*b*b + b*b*b);
}
int main(){
  long long n;
  cin >> n;
  long long x=8e18;
  long long j=1000000;
  for(long long i=0;i<=1000000;i++){
    while(f(i,j)>=n && j>=0){
      x=min(x,f(i,j));
      j--;
    }
  }
  cout << x << endl;
  return 0;
}