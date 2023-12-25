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

const ll infl = 1 << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N,Q; cin >> N >> Q;
    vector<int> left(N,-1), right(N,-1);
    while(Q--){
        int i; cin >> i;
        if (i == 1){
            int x,y; cin >> x >> y;
            x--; y--;
            right[x] = y;
            left[y] = x;

        } else if (i == 2){
            int x,y; cin >> x >> y;
            x--; y--;
            right[x] = -1;
            left[y] = -1;
        } else {
            int x; 
            cin >> x;
            x--;
            deque<int> deq;
            deq.push_back(x+1);
            int now = x;
            while (left[now] != -1){
                now = left[now];
                deq.push_front(now + 1);
            }
            now = x;
            while (right[now] != -1){
                now = right[now];
                deq.push_back(now + 1);
            }
            cout << deq.size() << " ";
            while(!deq.empty()){
                int fr = deq.front();
                deq.pop_front();
                cout << fr << " ";
            }
            cout << endl;
        }
    }
}