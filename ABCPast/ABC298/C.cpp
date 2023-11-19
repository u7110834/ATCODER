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
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,Q;
    cin >> N >> Q;
    vector<multiset<int>> boxes(N);
    map<int,set<int>> value_to_box;
    while(Q--){
        int n;
        cin >> n;
        if (n==1){
            int i,j;
            cin >> i >> j;
            boxes[j-1].insert(i);
            value_to_box[i].insert(j);
        } else{
            int i;
            cin >> i;
            if (n == 2){
                for (auto it = boxes[i-1].begin(); it != boxes[i-1].end();it++){
                    auto last  = boxes[i-1].end();
                    if (it != prev(last)) cout << *it << " ";
                    else cout << *it << endl;
                }
            } else { // n = 3
                if (value_to_box.find(i) != value_to_box.end()){
                    for (auto it = value_to_box.at(i).begin(); it != value_to_box.at(i).end();it++){
                        auto last  = value_to_box.at(i).end();
                        if (it != prev(last)) cout << *it << " ";
                            else cout << *it << endl; 
                    }
                } 
            }
        }
    }
}