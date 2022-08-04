#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        s.erase(s.begin() + n - 1);
        cout << s << "\n";
    }
    return 0;
}