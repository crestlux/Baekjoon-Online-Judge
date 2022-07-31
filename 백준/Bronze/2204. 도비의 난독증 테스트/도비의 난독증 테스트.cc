#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        vector<pair<string, string>> v(n);
        for (auto &e1 : v) {
            string s;
            cin >> s;
            e1 = { s, s };
            transform(e1.first.begin(), e1.first.end(), e1.first.begin(), ::tolower);
        }
        cout << min_element(v.begin(), v.end())->second << "\n";
    }
    return 0;
}