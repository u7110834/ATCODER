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

lint nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    lint result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main()
{   
    int A, B;
    lint K;
    cin >> A >> B >> K;
    int len =  A+B;
    int b_rem = B;
    string ans;
    bool done = false;
    for (int i = len; i >=1; i--){
        if (b_rem == 0){
            rep(j, i){ans+='a';}
            done = true;
        } else if (b_rem == i){
            rep(j, i){ans+='b';}
            done = true;
        }
        if (done) break;
        lint choose = nChoosek(i-1,b_rem);
        if (K > choose){
            K -= choose;
            ans += 'b';
            b_rem--;
        } else{
            ans += 'a';
        }
    }
    cout << ans << endl;
}