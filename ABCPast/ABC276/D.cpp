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

int main()
{   
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> p(N,0), q(N,0);
    set<int> type;
    rep(i,N) {
        int a;
        cin >> a;
        while (a % 2==0){
            a /= 2;
            p[i]++;
        }
        while (a % 3 == 0){
            a /= 3;
            q[i]++;
        }
        type.insert(a);
        if (type.size() > 1){
            cout << -1 << endl;
            return 0;
        }
    }

    int min_p = *(min_element(p.begin(),p.end()));
    int min_q = *(min_element(q.begin(),q.end()));
    lint ans = 0;
    rep(i,N){
        ans +=  p[i] - min_p;
        ans +=  q[i] - min_q;
    }
    cout << ans << endl;

}