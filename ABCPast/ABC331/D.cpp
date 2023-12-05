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
    int N,Q;
    cin >> N >> Q;
    vector<string> P(N);
    rep(i,N) cin >> P[i];
    vector<vector<int>> sum(N+1,vector<int>(N+1,0));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            sum[i][j] = sum[i][j-1];
            if (P[i-1][j-1] == 'B'){
                sum[i][j] +=1;
            }
        }
    }
    for (int j = 1; j <= N; j++){
        for (int i = 1; i <= N; i++){
            sum[i][j] += sum[i-1][j];
        }
    }
    // a >= 1;
    auto find = [&](int a, int b, int c, int d) {
        return (ll) sum[c+1][d+1] - sum[a-1+1][d+1] - sum[c+1][b-1+1] + sum[a-1+1][b-1+1];
    };
    while (Q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a = a % N;
        b = b % N;
        c = c % N;
        d = d % N;
        ll hnum = ((c-c%N) - (a+(N-a%N)))/N;
        ll vnum = ((d-d%N) - (b+(N-b%N)))/N;
        if (hnum == 0 && vnum == 0){
            int ans = 0;
            if (c < a){
                if (d < b){
                    ans += find(a,b,N-1,N-1);
                    ans += find(0,b,c,N-1);
                    ans += find(a,0,N-1,d);
                    ans += find(0,0,c,d);
                } else {
                    ans += find(a,b,N-1,d);
                    ans += find(0,b,c,d);
                }
            } else {
                if (d < b){
                    ans += find(a, b, c, N-1);
                    ans += find(a, 0, c, d);
                } else {
                    ans += find(a,b,c,d);
                }
            }
            cout << ans << endl;
        } else if (hnum != 0 && vnum == 0){
            ll ans = 0;
            if (d < b){
                ans += (ll) hnum*(find(0,b,N-1,N-1) + find(0,0,N-1,d));
            } else {
                ans += (ll) hnum*(find(0,b,N-1,d));
            }
            
            if (c < a){
                if (d < b){
                    ans += find(a,b,N-1,N-1);
                    ans += find(0,b,c,N-1);
                    ans += find(a,0,N-1,d);
                    ans += find(0,0,c,d);
                } else {
                    ans += find(a,b,N-1,d);
                    ans += find(0,b,c,d);
                }
            } else {
                if (d < b){
                    ans += find(a, b, c, N-1);
                    ans += find(a, 0, c, d);
                } else {
                    ans += find(a,b,c,d);
                }
            }
            cout << ans << endl;
        } else if (hnum == 0 && vnum != 0){
            ll ans = 0;
            if (c < a){
                ans += (ll) hnum*(find(a,0,N-1,N-1) + find(0,0,c,N-1));
            } else {
                ans += (ll) hnum*(find(a,0,c,N-1));
            }
            
            if (c < a){
                if (d < b){
                    ans += find(a,b,N-1,N-1);
                    ans += find(0,b,c,N-1);
                    ans += find(a,0,N-1,d);
                    ans += find(0,0,c,d);
                } else {
                    ans += find(a,b,N-1,d);
                    ans += find(0,b,c,d);
                }
            } else {
                if (d < b){
                    ans += find(a, b, c, N-1);
                    ans += find(a, 0, c, d);
                } else {
                    ans += find(a,b,c,d);
                }
            }
            cout << ans << endl;
        } else {
            if (c < a){
                if (d < b){
                    ans += find(a,b,N-1,N-1);
                    ans += find(0,b,c,N-1);
                    ans += find(a,0,N-1,d);
                    ans += find(0,0,c,d);
                } else {
                    ans += find(a,b,N-1,d);
                    ans += find(0,b,c,d);
                }
            } else {
                if (d < b){
                    ans += find(a, b, c, N-1);
                    ans += find(a, 0, c, d);
                } else {
                    ans += find(a,b,c,d);
                }
            }
            cout << ans << endl;
        }
    }
}
