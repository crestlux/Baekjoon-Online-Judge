#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s1;
    cin >> s1;
    reverse(s1.begin(), s1.end());
    cout << s1 << "\n";
    return 0;
}