#include <bits/stdc++.h>
#include <iostream>
#include <set>
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

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<char>> v(n);
	vector<bool> used(256);
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') now++;
		else if (s[i] == ')') {
			for (char c : v[now]) used[c] = false;
			v[now].clear();
			now--;
		}
		else {
			if (used[s[i]]) {
				cout << "No\n";
				return 0;
			}
			v[now].push_back(s[i]);
			used[s[i]] = true;
		}
	}
	cout << "Yes\n";
}