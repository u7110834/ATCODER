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

const ll infl = 1LL << 62;
auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N; cin >> N;
    vector<ll> t(N);
    vector g(N, vector<int>()); 
    for (int i = 0; i < N; i++){
        cin >> t[i];
        int k; cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            a--;
            g[i].push_back(a);
        }
    }
    set<int> s;
    vector<int> seen(N,0);
    seen[N-1] = true;
    stack<int> st;
    st.push(N-1);
    s.insert(N-1);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        for (int next : g[top]){
            if (seen[next]) continue;
            seen[next] = true;
            st.push(next);
            s.insert(next);
        }
    }
    ll ans = 0;
    for (int v : s){
        ans += t[v];
    }
    cout << ans << endl;
}