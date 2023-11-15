#include<iostream>
#include<vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

int main(){
    int B;
    cin >> B;

    int ans = 0;
    int num = 1;

    do {
        ans += (num)*(B % 2);
        num *= 2;
    } while ((B/= 10) > 0);

    cout << ans << endl;
    
    return 0;
}
