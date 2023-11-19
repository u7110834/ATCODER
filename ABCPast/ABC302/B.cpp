#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main(){
    int n,m,x,y;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    string str;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<8;k++){
                str="";
                for(int t=0;t<5;t++){
                    x=i+t*dx[k],y=j+t*dy[k];
                    if((x<0)||(x>=n)||(y<0)||(y>=m))break;
                    str+=s[x][y];
                }
                if(str=="snuke"){
                    for(int t=0;t<5;t++){
                        x=i+t*dx[k]+1,y=j+t*dy[k]+1;
                        cout<<x<<" "<<y<<endl;
                    }
                    return 0;
                }
            }
        }
    }
	return 0;
}