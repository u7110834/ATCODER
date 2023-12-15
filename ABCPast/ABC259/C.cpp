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
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    string s,t;
    cin >> s >> t;

    if (s.size() > t.size()) {
        cout << "No" << endl;
        return 0;
    }
    vector<pair<char,int>> smp, tmp;
    int cnt = 1;
    char c = s[0];
    for (int i = 1; i < s.size(); i++){
        char newc = s[i];
        if (c == newc) cnt++;
        else {
            smp.push_back({c,cnt});
            cnt = 1;
            c = newc;
        }
        if (i == s.size()-1){
            smp.push_back({c,cnt});
        }
    }
    
    cnt = 1;
    c = t[0];

    for (int i = 1; i < t.size(); i++){
        char newc = t[i];
        if (c == newc) cnt++;
        else {
            tmp.push_back({c,cnt});
            cnt = 1;
            c = newc;
        }
        if (i == t.size()-1){
            tmp.push_back({c,cnt});
        }
    }

    if (smp.size() != tmp.size()){
        cout << "No" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < smp.size(); i++){
        if (smp[i].first != tmp[i].first){
            ok = false;
            break;
        }
        if (smp[i].second > tmp[i].second){
            ok = false;
            break;
        }
        if (smp[i].second < tmp[i].second && smp[i].second < 2){
            ok = false;
            break;
        }
    }

    cout << (ok? "Yes" : "No") << endl;

}