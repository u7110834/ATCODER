#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    int N;
    cin >> N;

    map<int, lint> A_diff;
    rep(i,N) cin >> A_diff[i];

    int Q;
    cin >> Q;

    lint sub = 0;
    while (Q--){
        int i;
        cin >> i;
        if (i == 1){
            cin >> sub;
            A_diff.clear();
        } else if (i == 2){
            int ind;
            lint x;
            cin >> ind >> x;
            A_diff[ind-1] += x;

        } else {
            int ind;
            cin >> ind;

            if (A_diff.find(ind-1) == A_diff.end()){
                cout << sub << endl;
            } else cout << sub + A_diff[ind-1] << endl;
        }
    }
}