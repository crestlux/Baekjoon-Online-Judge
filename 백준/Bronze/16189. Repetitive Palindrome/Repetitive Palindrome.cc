#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2; int k;
    cin >> s1 >> k;
    s2 = s1;
    ranges::reverse(s2);
    s1 == s2 ? cout << "YES\n" : cout << "NO\n";
    return 0;
}