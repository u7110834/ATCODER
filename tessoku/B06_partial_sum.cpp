#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int N, Q, L[100009], R[100009],sum[100009];
bool A[100009];
int main(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> Q;
    for (int i = 0; i < Q; i++) cin >> L[i] >> R[i];

    memset(sum,0,sizeof(sum));
    for (int i = 1; i <= N; i++){
        sum[i] = sum[i-1] + A[i];
    }
    for (int i = 0; i < Q; i++){
        int win = sum[R[i]] - sum[L[i]-1];
        int loss  = 1+R[i]-L[i] - win;
        if (win > loss) {cout << "win" << endl;}
        else if (win == loss){cout << "draw" << endl;}
        else {cout << "lose" << endl;}
    }

    return 0;
}