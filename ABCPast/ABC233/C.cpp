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
    int N; ll X;
    cin >> N >> X;

    vector L(N, vector<ll>());
    rep(i,N){
        int l;
        cin >> l;
        L[i].resize(l);
        rep(j,l){
            ll a;
            cin >> a;
            L[i][j] = a;
        }
    }

    queue<ll> p;
    p.push(1);
    int cnt = 1;
    for (int i = 0; i < N; i++){
        int c = cnt;
        int used = 0;
        while (c--){
            ll fr = p.front();
            p.pop();
            for (int j = 0; j < (int) L[i].size(); j++){
                if (L[i][j] <= X && X % L[i][j] == 0 &&  fr <=  X/L[i][j]) {
                    p.push(fr*L[i][j]); used++;
                }
            }
        }
        cnt = used;
    }
    int ans = 0;
    while(!p.empty()){
        ll fr = p.front();
        p.pop();
        if (fr == X) ans++;
    }                     
    cout << ans << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
}