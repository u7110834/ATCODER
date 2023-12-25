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
    int N; cin >> N;
    int M; cin >> M;
    vector<set<int>> g(N),h(N);
    vector<int> idx(N);

    iota(all(idx),0);
    rep(i, M) {
        int a,b; 
        cin >> a >> b;
        a--;b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    rep(i, M) {
        int a,b; 
        cin >> a >> b;
        a--;b--;
        h[a].insert(b);
        h[b].insert(a);
    }

    do {
        vector<int> inv(N);
        for (int i = 0;i < N; i++){
            inv[idx[i]] = i;
        }
        bool ok = true;
        for (int i = 0; i < N; i++){
            for (int v : g[i]){
                if (!h[idx[i]].contains(idx[v])) ok = false;
            }
        }

        for (int i = 0; i < N; i++){
            for (int v : h[i]){
                if (!g[inv[i]].contains(inv[v])) ok = false;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(all(idx)));
    cout << "No" << endl;
}
