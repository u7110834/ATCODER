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
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    vector<int> C(N);
    vector<set<int>> func(N);
    rep(i,N){
        cin >> P[i];
        int c;
        cin >> c;
        C[i] = c;
        rep(j,c){
            int f;
            cin >> f;
            func[i].insert(f);
        }
    }

    for (int i = 0; i<N;i++){
        for (int j = 0; j < N; j++){
            if(i == j)continue;

            bool compare = true;

            if (P[i] < P[j]) compare = false;

            set<int> iset = func[i];
            set<int> jset = func[j];
            for (int f : iset){
                if (!jset.contains(f)){
                    compare = false;
                    break;
                }
            }

            if (P[i] == P[j] && C[i] == C[j]){
                compare = false;
            }
            if (compare){cout << "Yes" << endl; return 0;}
        }
    } 
    cout << "No" << endl;
}