#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> cnt(N);
    lint ans = 0;
    for (auto it = A.begin(); it != A.end(); it++){
        int cnt = lower_bound(A.begin(), A.end(), *it+K+1) - it;
        cnt--;
        ans += cnt;
    }
    cout << ans << endl;
}