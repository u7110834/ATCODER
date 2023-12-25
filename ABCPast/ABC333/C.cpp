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

auto putline = [](string s = "========"){
    cout << s << endl;
};

ll repl(int i){
    ll ans = 1;
    for(int j = 1; j < i; j++){
        ans*= 10;
        ans++;
    }
    return ans;
}
int main()
{   
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; ; i++){
        for (int j = 1; j <= i; j++){
            for (int k = 1; k <= j; k++){
                cnt++;
                if (cnt == N){
                    ll ans = repl(i)+repl(j)+repl(k);
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
}