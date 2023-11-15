#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define lint long long

// D日間にわたってイベント。N人が出席。参加者ⅰはL_iからR_i日目まで出席。
//各日の出席者数を出力せよ。
int main(){
    int N, D;
    cin >> D >> N;

    int L[N],R[N];
    rep(i, N) cin >> L[i] >> R[i];

    //前日比
    int diff[D+1];
    memset(diff, 0,sizeof(diff));

    rep(i,N){
        diff[L[i]]++;
        diff[R[i]]--;
    }
    //前日比の合計が当日の参加者
    int sum = 0;
    for(int i =1 ; i <= N; i++){
        sum += diff[i];
        cout << sum << endl; 
    }
    return 0;
}