#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iterator>
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

// Assume vec is sorted
int BinarySearch_index(vector<int> vec, int key) {
    // key: 検索対象の値
    int left = 0, right = vec.size(), mid;

    while (left < right) {
        mid = (left + right)/2;
        if (vec[mid] == key) {
            return mid;
        } else if (key < vec[mid]) {
            // 半分より下
            right = mid;
        } else if (vec[mid] < key) {
            // 半分より上
            // 必要ないが，分かりやすいように条件を記述してある．
            left = mid + 1;
        }
    }
    // key が配列の中に見つからない場合
    return -1;
}


int main()
{   
    vector<int> v = {2,3,4,5,6,1,3,2,4};
    sort(v.begin(),v.end());
    // std::binary_search() only checks if the key is contained
    // in a given vecotor. returns bool
    if (binary_search(v.begin(),v.end(),3))cout << "found 3" << endl;
    else cout << "could not find 3" << endl;
    // std::lower_bound() 
    // 指定した key 以上の要素の内，
    // 一番左側の要素の位置（最小のインデックス）をイテレータで返します
    // std::upper_bound()
    //指定した key より大きい要素の内，一番左側の要素の位置（
    // 最小のインデックス）をイテレータで返します．
    // returns iterator
    auto position = lower_bound(v.begin(),v.end(),4);
    int ind_lower = distance(v.begin(),position);
    cout << *position << " at lower index " << ind_lower << endl; // 5

    auto position2 = upper_bound(v.begin(),v.end(),4);
    int ind_upper = distance(v.begin(),position2);
    cout << *position2 << " at upper index " << ind_upper << endl; // expected = 7
}