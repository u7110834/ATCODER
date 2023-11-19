#include <bits/stdc++.h>
#include <utility>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    // string s ="abc";
    // do cout << s << endl;
    // while (next_permutation(s.begin(),s.end()));

    string s2 ="cab";
    do cout << s2 << endl;
    while (next_permutation(s2.begin(),s2.end()));

    // To permutate over all orders sort the target
    string s3 ="cab";
    sort(s3.begin(),s3.end());
    do cout << s3 << endl;
    while (next_permutation(s3.begin(),s3.end()));
}