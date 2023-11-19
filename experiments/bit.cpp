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
    int a  =27;
    int b = 67;
    cout << a << " : " << bitset<8>(a) << endl; 
    cout << b << " : " << bitset<8>(b) << endl; 

    // binary 
    // 1 if at least one of the two bits is 1
    cout << "a|b : " << (a|b) << " = " << bitset<8>(a|b) << endl;
    // 1 if the two bits are different
    cout << "a^b : " << (a^b) << " = " << bitset<8>(a^b) << endl;
    // 1 if the two bits are the same
    cout << "a&b : " << (a&b) << " = " << bitset<8>(a&b) << endl;
    
    //unitary

    // inverts all the bits
    cout << "~a : " << (~a) << " = " << bitset<8>(~a) << endl; // -a+1;

    // Shift operator
    cout << "1 = 1<<0 : " << (1<<0) << " = " << bitset<8>(1<<0) << endl;
    cout << "2^4  = 1<<4 : " << (1<<4) << " = " << bitset<8>(1<<4) << endl; 
    cout << "1>>4 : " << (1>>4) << " = " << bitset<8>(1>>4) << endl; // remove the first four bits
}