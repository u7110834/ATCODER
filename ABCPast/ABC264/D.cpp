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
    string target = "atcoder";
    string s;
    cin >> s;
    string sorted_target = target;
    sort(all(sorted_target));
    map<string,bool> seen;
    map<string,int> dmap;
    do {
        seen[sorted_target] = false;
    } while(next_permutation(all(sorted_target)));

    // BFS
    queue<string> que;
    que.push(s);
    seen[s] = true;
    dmap[s] = 0;
    while(!que.empty()){
        string fr = que.front();
        que.pop();
        if (fr == target){
            break;
        }
        for (int i = 0; i < 6; i++){
            string next_str = fr;
            swap(next_str[i],next_str[i+1]);
            if (seen[next_str]) continue;
            else {
                seen[next_str] = true;
                dmap[next_str] = dmap[fr]+1;
                que.push(next_str);
            }
        }
    }
    cout << dmap[target] << endl;
}