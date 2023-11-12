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
void remove(string &s, bool &can,int &current){
    int N =s.size();
    for (int i = current; i < N-2; i++){
            string sub = s.substr(i,3);
            if(sub == "ABC"){
                string news = s.substr(0, i)+s.substr(i+3, N - i+3);
                s  = news;
                can = true;
                current =  max(i-2,0);
                return;
            }
        }
    can = false;
}

int main()
{   
    string s;
    cin >> s;
    bool can = true;
    int current = 0;
    while (s.size() >= 3 && can){
        can =  false;
        remove(s,can,current);
    }
    cout << s << endl;
}