#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

//bit search p.45
int main(){
    int N, S;
    cin >> N >> S;

    int A[N];
    rep(i,N) cin >> A[i+1];

    // Bit search (O(2^N * N))
    // e.g. if N = 4 and j = 1101, 
    // choose A_1, A_2 and A_3 and evaluate their sum.
    rep(j,1 << N){
        int sum = 0;
        rep(k, N){
            int div = 1 << k;
            if ((j / div) %2 == 1){
                sum += A[k-1];
            }
        }
        if (sum == S) {
            cout << "Yes" << endl;
            return  0;
        }
    }

    cout << "No" << endl;

    return 0;
}