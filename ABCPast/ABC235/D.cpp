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

int digits(int n){
    int pow = 1;
    for (int i = 1;; i++){
        pow *= 10;
        if (n < pow){
            return i;
        }
    }
}
int main()
{   
    int a, N;
    cin >> a >> N;
    int mxd = digits(N);
    vector<int> seen(1e6+1,0),depth(1e6+1,0);
    seen[1] = true;
    queue<int> st;
    st.push(1);

    while(!st.empty()){
        int fr = st.front();
        st.pop();
        if (fr == N) {
            cout << depth[fr] << endl;
            return 0;
        } 
        ll amult = (ll) fr*a;
        if (amult < 1e6 && digits(fr*a) <= mxd && !seen[fr*a]){
            st.push(fr*a);
            seen[fr*a] = true;
            depth[fr*a] = depth[fr] + 1;
        }
        if (fr % 10 != 0){
            string s = to_string(fr);
            s = s[s.size()-1] + s.substr(0,s.size()-1);
            int next = stoi(s);
            if (digits(next) > mxd || seen[next]) continue;
            st.push(next);
            seen[next] = true;
            depth[next] = depth[fr] + 1;
        }
    }
    
    cout << -1 << endl;
}