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
    int N,M;
    cin >> N >> M;
    string S[N];
    rep(i,N) cin >> S[i];
    vector<pair<int,int>> ans;
    for (int  i = 0; i< N-8; i++){
        for (int j = 0; j < M-8; j++){
            bool istak = true;
            for (int k = i; k < i+9; k++){
                for (int l = j; l < j+9; l++){
                    int x = k-i;
                    int y = l-j;
                    if ((x < 3 && y < 3)||(x > 5 && y > 5)){
                        if (S[k][l] != '#'){
                            istak = false;
                        }
                    } else if ((x == 3 && y <= 3)||(x <= 3 && y == 3)||(x == 5 && y >= 5)||(x >=5 && y == 5)){
                        if (S[k][l] != '.') istak = false; 
                    }
                }
            }
            if (istak) {ans.push_back({i,j});}
        }
    }
    for (auto pair : ans){
        cout << pair.first+1 << " " << pair.second+1 << endl;
    }
}