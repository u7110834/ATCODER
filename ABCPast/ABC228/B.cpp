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
#define Pint pair<int,int>

const ll infl = 1 << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,X;
    cin >> N >> X; X--;
    int ans = 1;
    vector<int> a(N);
    rep(i,N) {
        int b;
        cin >> b;
        b--;
        a[i] = b;
    }
    vector<int> seen(N,0);
    seen[X] = true;
    int cur = X;
    while(true){
        if (seen[a[cur]]){
            break;
        }
        ans++;
        cur = a[cur];
        seen[cur] = true;
    }
    cout << ans << endl;
}