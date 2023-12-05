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
    // deque
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    sort(all(aac));
    deque<int> deq;
    rep(i,N) deq.push_back(a[i]);
    int end = 0;
    while(true){
        int check_cnt = 0;
        int size = (int) deq.size();
        while(check_cnt != size){
            int fr = deq.front();
            if (fr == end+1) {
                deq.pop_front();
                end++;
                check_cnt++;
            } else if (fr <= end){
                deq.pop_front();
                deq.push_back(fr);
                check_cnt++;
            } else break;
        }
        if (deq.size() > 1) {
            deq.pop_back();
            deq.pop_back();
            end++;
        } else {
            break;
        }
    }

    cout << end << endl;
}