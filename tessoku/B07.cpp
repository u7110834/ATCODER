#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int T, N;
    cin >> T >> N;
    
    int L[N], R[N];
    rep(i, N) cin >> L[i] >> R[i];

    int diff[T+1];
    memset(diff, 0, sizeof(diff));

    rep(i, N){
        diff[L[i]]++;
        diff[R[i]]--;
    }
    int ans[T];
    ans[0] = diff[0];
    for (int j =1 ; j < T ; j++){
        ans[j] = ans[j-1] + diff[j];
    }
    for (int j =0 ; j < T ; j++){cout << ans[j] << endl;} 
    return 0;
}