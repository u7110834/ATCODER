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
    int N;
    cin >> N;
    vector<int> vec(10);
    for (int i = 1;i <=9 ;i++){
        if (N%i==0){vec[i] = N/i;}
        else vec[i] = -1;
    }
    try{
        for (int i = 0; i <= N; i++){ 
        bool can = false;
        for (int j =1; j <= 9; j++){
            if (vec[j] != -1 && i%vec[j] ==0){
                cout << j;
                can  = true;
                break;
            }
        }
        if (!can) cout << "-";
        }
    } catch(runtime_error& e){
        cout << e.what() << endl;
    }
    cout << endl;
}