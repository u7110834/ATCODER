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

int num_swaps(string s, string t){
    int cycles = 0;
    set<char> seen;
    for (int i = 0; i < 3; i++){
        char c = t[i];
        if (seen.contains(c)) continue;
        char cur = c;
        while (!seen.contains(cur)){
            seen.insert(cur);
            int next_i = s.find(cur);
            cur = t[next_i];
        }
        cycles++;
    }
    return 3-cycles;
}

int main()
{   
    string s;
    string t;
    rep(i,3) {
        char c; cin >> c;
        s += c;
    }

    rep(i,3) {
        char c; cin >> c;
        t += c;
    }
    int m = num_swaps(s,t);
    if (m % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}