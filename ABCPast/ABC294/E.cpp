#include <bits/stdc++.h>
using namespace std;

// #include <atcoder/all>
// using namespace atcoder;

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Pint pair<int,int>

auto putline = [](string s = "========"){
    cout << s << endl;
};

int main()
{   
    ll L, N1,N2;
    cin >> L >> N1 >> N2;

    vector<pair<ll,ll>> a(N1),b(N2);
    ll sum = 0;
    rep(i,N1) {
        ll x,l;
        cin >> x >> l;
        a[i].first = x;
        a[i].second = l+sum;
        sum = a[i].second;
    }

    sum = 0;
    rep(i,N2) {
        ll x,l;
        cin >> x >> l;
        b[i].first = x;
        b[i].second = l+sum;
        sum = b[i].second;
    }


    ll ans = 0;
    int i2 = 0;

    ll pos = 0;
    for (int i = 0; i < N1;){
        ll x1 = a[i].first;
        ll l1 = a[i].second;

        ll x2 = b[i2].first;
        ll l2 = b[i2].second;
        if (l1 > l2){
            i2++;
            if (x1 == x2){
                ans += l2 - pos;
                //cout << l2 << " " << pos << endl;
            }
            pos = l2;
        } else if (l1 < l2) {
            // l1 < l2
            i++;
            if (x1 == x2){
                ans += l1 - pos;
                //cout << l1 << " " << pos << endl;
            }
            pos = l1;
        } else {
            if (x1 == x2){
                ans += l1-pos;
            }
            i++; i2++;
            pos = l1;
        }
        if (i == N1 && i2 == N2) break;
    }
    cout << ans << endl;
}