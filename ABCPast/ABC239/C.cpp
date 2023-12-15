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

int dist_sq(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int dx[] = {2,1,-1,-2};
int dy[] = {2,1,-1,-2};
int main()
{   
   int x1,y1,x2,y2;
   cin >> x1 >> y1 >> x2 >> y2;
   for (int d1 : dx) for (int d2 : dy){
        if (d1*d1+d2*d2 == 5){
            int x = x1 + d1;
            int y = y1 + d2;
            if (dist_sq(x,y,x2,y2) == 5){
                cout << "Yes" << endl;
                return 0;
            }
        }
   }
   cout << "No" << endl;
}