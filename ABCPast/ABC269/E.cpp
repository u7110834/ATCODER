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
    int N;
    cin >> N; 
    // find vertical coord A,B
    int hi = N; int lo = 1;
    while (hi - lo > 1){
        int mid = (hi+lo)/2;
        cout << "? " << lo << " " << mid << " " << 1 << " " << N << endl;
        int T;
        cin >> T;
        if (T != mid-lo+1) hi = mid;
        else lo = mid+1;
    }
    // Final Check
    cout << "? " << 1 << " " << lo << " " << 1 << " " << N << endl;
    int T;
    cin >> T;
    int X;
    if (T != lo){
        X = lo;
    } else {
        X = lo+1;
    }



    int hi2 = N; int lo2 = 1;
    while (hi2 - lo2 > 1){
        int mid = (hi2+lo2)/2;
        cout << "? " << 1 << " " << N << " " << lo2 << " " << mid << endl;
        int T;
        cin >> T;
        if (T != mid-lo2+1) hi2 = mid;
        else lo2 = mid+1; // mid+1 !!!!
    }

    // Final Check
    cout << "? " << 1 << " " << N << " " << 1 << " " << lo2 << endl;
    int T2;
    cin >> T2;
    int Y;
    if (T2 != lo2){
        Y = lo2;
    } else {
        Y = lo2+1;
    }
    cout << "! " << X << " " << Y << endl;
}