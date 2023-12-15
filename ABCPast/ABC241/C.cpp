#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <cctype>
// #include <cstring>
// #include <numeric>      // std::iota
// #include <algorithm>
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

auto putline = [](string s = "========"){
    cout << s << endl;
};

int dx[] = {1,1,1,0};
int dy[] = {0,1,-1,-1};
int main()
{   
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i,N) cin >> s[i];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int di = 0; di < 4; di++){
                int cnt = 0;
                bool ok = true;
                for (int k = 0; k < 6; k++){
                    int newx = i +k*dx[di];
                    int newy = j + k*dy[di];
                    if (newx < 0 || newx >= N || newy < 0 || newy >= N){
                        ok = false;
                        break;
                    }
                    cnt += s[newx][newy] == '#';
                }
                if (ok && cnt >= 4){
                        cout << "Yes" << endl;
                        return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}