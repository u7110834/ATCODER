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

// Assume a^p does not overflow
long long power(int a, int p){
    long long ans = 1;
    while(p>0){
        ans *= a;
        p--;
    }
    return ans;
}

int main()
{   
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int K;
    cin >> K;

    long long decimal = 0;
    long long pow  = 1;
    vector<int> ans;


    // to decimal
    rep(i, s.size()){
        int d = s[i] - '0';
        decimal += d*pow;
        pow *= 8;
    }

    if (decimal == 0) {
        cout << 0 << endl;
        return 0;
    }

    while (K--){
        ll dec = decimal;
        // to base 9
        ll p9 = 1;
        while (true){
            if (p9 > dec){
                p9 /= 9;
                break;
            }
            p9 *= 9;
        }
        vector<int> base8vec;
        while (p9 > 0){
            int digit = dec/p9;
            dec -= digit*p9;
            if (digit == 8) digit = 5;
            base8vec.push_back(digit);
            p9 /= 9;
        }
        ans = base8vec;
        reverse(base8vec.begin(),base8vec.end());
        ll p8 = 1;
        ll new_decimal = 0;
        for(int d: base8vec){
            new_decimal += d*p8;
            p8*=8;
        }
        decimal = new_decimal;
    }
    for (int d: ans){
        cout << d;
    }

    cout << endl;
}