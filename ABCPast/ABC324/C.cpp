#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <cmath>
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
    int N;
    string T;
    cin >> N >> T;
    vector<int> ans;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        int diff  = str.size()-T.size();
        if (abs(diff) > 1) continue;
        if (diff == 0){
            int cnt = 0;
            for (int j = 0; j < T.size(); j++){
                if (T[j] != str[j]) cnt++;
            }
            if (cnt > 1) continue;
        }
        if (diff == 1) { //str > T
            int cnt = 0;
            string Tcopy = T;
            for (int j = 0; j < str.size(); j++){
                if (Tcopy[j] != str[j]) {
                    cnt++;
                    if (cnt > 1) break;
                    Tcopy.insert(j,1,str[j]);
                    //cout << Tcopy << endl;
                }
            }
            if (cnt > 1) continue;
        }
        if (diff == -1) { //str < T
            int cnt = 0;
            string strcopy = str;
            for (int j = 0; j < T.size(); j++){
                if (T[j] != strcopy[j]) {
                    cnt++;
                    if (cnt > 1) break;
                    strcopy.insert(j,1,T[j]);
                }
            }
            if (cnt > 1) continue;
        }
        ans.push_back(i+1);
    } 

    cout << ans.size() << endl;
    int k = 0;
    for (int an : ans){
        if (k != ans.size()-1) cout << an << " ";
        else cout << an << endl;
        k++;
    }
    //cout << endl;
 }