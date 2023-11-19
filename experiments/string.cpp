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
    string s = "012345";
    cout << s.substr(6,1) << endl; // 0
    //indexing
    int k = 3; // remove the kth element
    cout << s.substr(0, k-1) + s.substr(k, s.size()-k) << endl;
    s.erase(s.begin()+k);// remove kth element
    cout << s << endl;
    s.insert(3,"3"); // insert "2" to the 3rd element
    cout << s << endl;
    // or equivalently
    s.insert(0, 4 ,'c');
    cout << s << endl;
}