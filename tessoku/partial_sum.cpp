#include<iostream>
#include<vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int N, Q;
    cin >> N >> Q;

    int A[N+1];
    A[0] = 0; 
    for(int i = 1; i <= N; i++) {
        int a; cin >> a; 
        A[i] = A[i-1] + a;
    }

    int L[Q],R[Q];
    rep(i, Q) cin >> L[i] >> R[i];

    rep(i,Q){
        cout << A[R[i]] - A[L[i]-1] << endl;
    }
    return 0;
}