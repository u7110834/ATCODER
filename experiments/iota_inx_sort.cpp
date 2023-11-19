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
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main()
{   
    int N =3;
    int A[N] = {3,1,2};
    vector<int> idx(3);
    iota(idx.begin(),idx.end(),0); // = {0,1,2}

    auto comp = [&](int i,int j){
        return A[i] < A[j];
    };
    // preserve index order if equal
    stable_sort(idx.begin(),idx.end(),comp);
    for (int i : idx){
        cout << i << " "; // should get 1 2 0
    }
    cout << endl;
    cout << "==============";
    cout << endl;
    stable_sort(idx.rbegin(),idx.rend(),comp);
    for (int i : idx){
        cout << i << " "; // reversed
    }
    cout << endl;
}
