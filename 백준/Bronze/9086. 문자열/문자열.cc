#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; string s1;
    cin >> T;
    while (T--) {
        cin >> s1;
        cout << *s1.begin() << *(s1.end() - 1) << "\n";
    }
    return 0;
}