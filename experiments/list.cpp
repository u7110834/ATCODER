#include <bits/stdc++.h>
#include <utility>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    // find はtime complexity 的に厳しい
    // lower/upper bound を使うべし
    vector<int> a = {1,2,3,4,4,5,6,6};
    sort(a.rbegin(),a.rend());
    auto it =unique(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    // a.end() 以降を消す
    cout << a[1] << endl; 
}