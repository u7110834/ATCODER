#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <numeric>      // std::iota
#include <algorithm>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int dx[] = {1, -1,0,0}; 
int dy[] = {0, 0, 1,-1};

// union find
int main()
{   
    int H , W , Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> red(H, vector<bool>(W,0));

    dsu g(H*W);

    while (Q--){
        int i;
        cin >> i;
        if (i == 1){
            int r , c;
            cin >> r >> c;
            r--; c--;
            red[r][c] = true;
            rep(j,4){
                int x = dx[j] + r;
                int y = dy[j] + c;
                if (x < H && x >= 0 && y < W && y >= 0){
                    if (red[x][y]) g.merge(r*W+c, x*W+y);
                }
            }
        } else {
            int ra,ca,rb,cb;
            cin >> ra >> ca >> rb >> cb;
            ra--; ca--;rb--;cb--;
            if (!red[ra][ca] || !red[rb][cb]) {
                cout << "No" << endl;
                continue;
            }
            if (g.same(ra*W+ca,rb*W+cb)) {
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
    }
    
}