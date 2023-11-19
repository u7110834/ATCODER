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
    // Check existence of a closed Hamiltonian path
    // ABC302 C: brute-force using all possible 
    // paths using (sort and) next_permutation.
    // dp
    int n,m;
    cin >> n >> m;
    vector<string> s(n); 
    rep(i,n) cin >> s[i];
    
    vector<int> dp(1<<n,0);

    rep(i,n) dp[1<<i] |= 1 << i; // bitor
    for (int bit : 1 << n){
        
    }
}