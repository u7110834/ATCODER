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

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Pint(a) pair<int,int>

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    ll r1,c1,r2,c2;
    // r1 - r2 
    cin >> r1 >> c1 >> r2 >> c2;
    // 1 step
    // dist <= 3 or diag
    if (r1 == r2 && c1 == c2){
        cout << 0 << endl;
    } else if (abs(r1-r2) == abs(c1-c2) || abs(r1-r2)+abs(c1-c2) <= 3){
        cout << 1 << endl;
    } else {
        bool ok = false;
        for (int i = -3; i <= 3; i++){
            for (int j = -3; j <= 3; j++){
                ll r = r1+i;
                ll c = c1+j;
                if (abs(r1-r)+abs(c1-c) <= 3){
                    if (abs(r-r2) == abs(c-c2)){
                        ok = true; break;
                    }
                }
            }
        }
        if ((abs(r1-r2) + abs(c1-c2)) % 2 == 0) ok = true;
        if (r1 == r2 && abs(c1-c2) <= 6) ok = true;
        if (c1 == c2 && abs(r1-r2) <= 5) ok = true;
        if (ok){
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
}