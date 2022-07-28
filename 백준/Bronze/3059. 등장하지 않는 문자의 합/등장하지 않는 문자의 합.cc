#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        bitset<26> b; string s; int sum = 0;
        cin >> s;
        for (auto &e : s) b[e - 'A'] = true;
        for (int i = 0; i < 26; ++i) {
            if (!b[i]) sum += i + 'A';
        }
        cout << sum << "\n";
    }
    return 0;
}