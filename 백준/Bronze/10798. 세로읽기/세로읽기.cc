#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<string> v(5);
    for (auto &e : v) cin >> e;
    for (int i = 0; i < 15; ++i) {
        for (const auto &e : v) {
            if (e.length() > size_t(i)) cout << e[i];
        }
    }
    return 0;
}