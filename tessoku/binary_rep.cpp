#include<iostream>
#include<vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int N;
    cin >> N;
    for (int x = 9; x >= 0; x--){
        int div = 1 << x; // 2^x
        // N/divはNの２進法表記の最初のｘ桁を削って得られる数。
        // e.g. 1111 = 15, 15/2^2 =3 = 11, 15/2 = 7 = 111.
        int digit  = (N/div)%2; 
        cout << digit;
    }
    cout << endl;
    return 0;
}
