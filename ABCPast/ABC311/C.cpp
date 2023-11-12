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
    vector<int> A(N+1);
    for (int i = 1; i <= N;i++){
        cin >> A[i];
    }
    // 制約下ではどの点から始めても閉回路を見つけられる。
    int v =1;
    vector<bool> seen(N+1); // true if seen;
    while (!seen[v]){
        seen[v] = true;
        v = A[v];
    }
    vector<int> ans = {v};
    int current  = v;
    do{
        current = A[current];
        if(current != v) ans.push_back(current);
    }while (current != v);
    cout << ans.size() << endl;
    for (int a: ans){
        cout << a << " ";
    }
    cout << endl;
}