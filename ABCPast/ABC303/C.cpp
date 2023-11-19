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
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

int main()
{   
    //問題読め
    int N,M,H,K;
    cin >> N >> M >> H >> K;
    string s;
    cin >> s;
    vector<pair<int,int>> coord = {{0,0}};
    set<pair<int,int>> heals;
    
    rep(i,M){
        int x,y;
        cin >> x >> y;
        heals.insert({x,y});
    }

    rep1(i,N){
        char c = s[i-1];
        pair <int,int> prepos = coord[i-1];
        if (c== 'R') coord.push_back(prepos+make_pair(1,0));
        if (c== 'L') coord.push_back(prepos+make_pair(-1,0));
        if (c== 'U') coord.push_back(prepos+make_pair(0,1));
        if (c== 'D') coord.push_back(prepos+make_pair(0,-1));
    }
    bool can = true;
    rep1(i,N){
        H--;
        if (H < 0) {
            can = false;
            break;
        }
        pair<int,int> pos = coord[i];
        //cout << pos.first << " " << pos.second << endl;
        if (heals.contains(pos)){
            //cout << "found" << endl;
            if (H < K){
                H = K;
                heals.erase(pos);
            }
        }
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}