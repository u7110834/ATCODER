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

auto putline = [](string s = "========"){
    cout << s << endl;
};

int dx[] = {1, 0,-1,0};
int dy[] = {0,-1,0,1};
int main()
{   
    int x= 0;
    int y = 0;
    int d = 0;
    int N;
    cin >> N;
    string s;
    cin >> s;
    rep(i,N){
        char c = s[i];
        if (c == 'S'){
            x += dx[d];
            y += dy[d];
        } else {
            d++;
            d = d % 4;
        }
    }
    cout << x << " " << y << endl;
}