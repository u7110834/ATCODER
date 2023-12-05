#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N),B(N),C(N),D(N);
    for (int i =0 ; i < N; i++){
        cin >> A[i];
    } 
    for (int i =0 ; i < N; i++){
        cin >> B[i];
    } 
    for (int i =0 ; i < N; i++){
        cin >> C[i];
    } 
    for (int i =0 ; i < N; i++){
        cin >> D[i];
    } 
    set<int> first, second;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            first.insert(A[i] + B[j]);
            second.insert(C[i] + D[j]);
        }
    }
    bool ok = false;
    for (int sum : first){
        if (second.contains(K-sum)) {
            ok = true;
            break;
        }
    }
    cout << (ok? "Yes" : "No") << endl;
}