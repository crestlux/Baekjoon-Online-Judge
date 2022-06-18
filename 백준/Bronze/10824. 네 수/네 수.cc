#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cout << stoll(s1 + s2) + stoll(s3 + s4) << "\n";
    return 0;
}