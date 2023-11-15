#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int N,Q, S[1509][1509], X[1509][1509],A[100009],B[100009],C[100009],D[100009];
int main(){
    constexpr int H =1501;
    constexpr int W= 1501;
    memset(X,0,sizeof(X));
    memset(S,0,sizeof(S));
    cin >> N;
    for (int i = 1; i <= N; i++){
        int x,y;
        cin >> x >> y;
        X[x][y]++;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    // partial sum;
    for (int i = 1; i < H ; i++){
        for (int j = 1; j < W; j++){
            S[i][j] = S[i][j-1] + X[i][j];
        }
    }
    for (int i = 2; i < H ; i++){
        for (int j = 1; j < W; j++){
            S[i][j] += S[i-1][j];
        }
    }
    for (int i = 0 ; i < Q; i++){
        int a = A[i];
        int b = B[i];
        int c = C[i];
        int d = D[i];
        cout << S[c][d] - S[a-1][d] - S[c][b-1] + S[a-1][b-1] << endl;
    }
    return 0;
}