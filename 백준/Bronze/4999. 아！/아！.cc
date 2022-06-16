#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() >= s2.length()) cout << "go\n";
    else cout << "no\n";
    return 0;
}