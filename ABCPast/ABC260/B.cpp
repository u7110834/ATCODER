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

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,X,Y,Z;
    cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N), sum(N);
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        A[i] = a;
    }
    for (int i = 0; i < N; i++){
        int b; cin >> b;
        B[i] = b;
    }
    for (int i = 0; i < N; i++){
        sum[i] = A[i]+B[i];
    }
    
    vector<int> idx(N);
    iota(all(idx), 0);

    auto compA = [&](int a, int b){
        return greater<int>()(A[a],A[b]);
    };
    stable_sort(all(idx),compA);
    sort(idx.begin()+X,idx.end()); // sort indices in ascending order
    auto compB = [&](int a, int b){
        return greater<int>()(B[a],B[b]);
    };
    stable_sort(idx.begin()+X,idx.end(), compB);
    sort(idx.begin()+X+Y,idx.end());
    auto compSum = [&](int a, int b){
        return greater<int>()(sum[a],sum[b]);
    };
    
    stable_sort(idx.begin()+X+Y,idx.end(),compSum);
    set<int> passed;
    for (int i = 0; i < X+Y+Z; i++){
        passed.insert(idx[i]);
    }
    for (int p : passed){
        cout << p+1 << endl;
    }
}