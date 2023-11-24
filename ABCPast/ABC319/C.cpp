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

int main()
{   
    int M;
    cin >> M;
    vector<int> dcnt(10);
    vector<string> s(3);
    rep(i,3){
        string str;
        cin >> str;
        set<int> ds;
        rep(i,M) ds.insert(str[i] - '0');
        s[i] = str;
        for (int i : ds) dcnt[i]++;
    }
    set<char> possible_d;
    rep(i,10) if (dcnt[i] >= 3) possible_d.insert('0'+i);
    if (possible_d.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 3*M+1;
    for (char d : possible_d){
        vector<vector<int>> v(3);
        rep(i,3){
            string st = s[i];
            rep(j,M) {
                if (st[j] == d) v[i].push_back(j); 
            }
        }
        for (int t1 : v[0]) for (int t2 : v[1]) for (int t3 : v[2]){
            set<int> ts = {t1,t2,t3};
            auto it = ts.rbegin();
            rep(i,3-ts.size()) it++;
            int time = (3-ts.size())*M + *it;
            chmin(ans, time);
        } 
        
    }
    cout << ans << endl;
}