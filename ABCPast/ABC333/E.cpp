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

int main()
{   
    int N;
    cin >> N;
    
    vector<int> t(N),x(N);
    rep(i,N) cin >> t[i] >> x[i];
    map<int,int> req; //x and num
    vector<int> ans;
    int mx = 0;
    int cur = 0;
    for (int i = N-1; i>=0; i--){
        if (t[i] == 1){
            if (req[x[i]] > 0){
                req[x[i]]--;
                ans.push_back(1);
                cur--;
            } else ans.push_back(0);// else no
        } else {
            req[x[i]]++;
            cur++;
            chmax(mx,cur);
        }        
    }
    for (auto it : req){
        if (it.second != 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mx << endl;
    
    for (auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << *it << " ";
    }

    cout << endl;


}