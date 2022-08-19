#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(3);
    for (auto &e : v) cin >> e;
    ranges::sort(v);
    for (int i = 0; i < 3; ++i) {
        char c;
        cin >> c;
        cout << v[c - 'A'] << " ";
    }
    return 0;
}