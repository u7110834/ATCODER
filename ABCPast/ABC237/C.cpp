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
    string s;
    cin >> s;
    auto f = s.find_first_not_of('a');
    auto l = s.find_last_not_of('a');
    if (f == s.npos) {
        cout << "Yes" << endl;
        return 0;
    } else if (s.size()-l-1 < f){
        cout << "No" << endl;
        return 0;
    }
    string news = s.substr(f,l-f+1);
    bool ispalind = true;

    for (int i = 0; i < l-f+1; i++){
        if (l-f-i == i){
            break;
        }
        if (news[i] != news[l-f-i]){
            ispalind = false;
            break;
        }
    }
    if (ispalind) cout << "Yes" << endl;
    else cout << "No" << endl;
     
}

bool isPalindrome(string s, int n){
    bool rtn = true;
    for (int i = 0; i < n; i++){
        if (n-1-i == i){
            break;
        }
        if (s[i] == s[n-1-i]){
            rtn = false;
            break;
        }
    }
    
    return rtn;
}