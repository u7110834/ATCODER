#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

// include <atcoder/all>
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
    vector<int> v = {1,2,3,4,5};
    int c = 10;

    auto print_all = [=](){
        rep(i,5) cout << v[i] << endl;
    };

    auto print_all_by_reference = [&](){
        rep(i,5) cout << v[i] << endl;
    };

    auto comp1 = [](int a, int b){
        return a < b;
    };

    print_all();

    sort(v.begin(),v.end(),comp1);

    putline();
    print_all();

    auto print2 = [&c](){
        cout << c << endl;
    };

    auto print3 = [c](){
        cout << c << endl;
    };
    c++;
    print2();//11
    print3();//10
}