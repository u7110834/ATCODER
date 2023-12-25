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

int main()
{   
    int N; cin >> N;
    int M; cin >> M;
    vector<vector<int>> adj(N);
    vector<bool> check(N,0);
    rep(i,M){
        int a,b;cin >> a >> b;
        a--;b--;
        check[a] = true;
        check[b] = false;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok = true;
    for (int i = 0; i < N; i++){
        if (adj[i].size() > 2){
            ok = false; break;
        }
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }
    vector<bool> seen(N,0);
    vector<bool> finished(N,0);

    for (int i = 0; i < N; i++){
        if (!check[i] || seen[i]) continue;
        stack<int> st;
        st.push(i);
        seen[i] = true;
        while(!st.empty()){
            int t = st.top;
            st.push();
            for (int next : adj[t]){
                if (finished[next]) continue;
                if (seen[next]) {
                    cout << "No" << endl;
                    return 0;
                }
                seen[i] = true;
                st.push(next);
            }
            finished[t] = true;
        }
    }

    

    // 1 - 2
    // 2 - 3
    // 3 - 4
    // 4 - 1 
}
