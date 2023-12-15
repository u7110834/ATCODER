#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <cctype>
// #include <cstring>
// #include <numeric>      // std::iota
// #include <algorithm>
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

int main()
{   
    int N;
    cin >> N;
    map<int, int>  l;// y x
    map<int,int> r;
    vector<int> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    string s;
    cin >> s;
    rep(i,N){
        if (s[i] == 'R'){
            if (l.find(y[i]) == l.end()){
                l[y[i]] = x[i];
            } else {
                l[y[i]] = min(l[y[i]],x[i]);
            }
        } else {
            r[y[i]] = max(r[y[i]], x[i]);
        }
    }
    bool ok = false;
    for (auto it : l){
        auto rit = r.find(it.first);
        if (rit != r.end()){
            if (it.second < (*rit).second){
                ok = true;
                break;
            }
        }
    }
    cout << (ok? "Yes": "No") << endl;
}