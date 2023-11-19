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
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main()
{   
    int N, M;
    cin >> N >> M;

    int A[M];
    int score[N];
    string sheet[N];

    rep(i,M) cin >> A[i];

    rep(i,N){
        int is = i;
        cin >> sheet[i];

        rep(j,M){
            is +=A[j]*(sheet[i][j] == 'o');
        }

        score[i] = is;

    }

    int mx = *max_element(score,score+N);

    vector<int> idx(M);
    iota(idx.begin(),idx.end(),0);

    auto comp = [&](int i,int j){
        return A[i] < A[j];
    };
    stable_sort(idx.begin(),idx.end(),comp);
    
    rep(i,N){
        int remain = mx - score[i];
        int cnt = 0;
        int j = M-1;
        while (remain > 0){
            if (sheet[i][idx[j]] == 'o'){j--;continue;}
            remain -= A[idx[j]];
            cnt++;
            j--;
        }
        cout << cnt << endl;
    }

}
